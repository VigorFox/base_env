/*
 * Copyright © 2008 Kristian Høgsberg
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that copyright
 * notice and this permission notice appear in supporting documentation, and
 * that the name of the copyright holders not be used in advertising or
 * publicity pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no representations
 * about the suitability of this software for any purpose.  It is provided "as
 * is" without express or implied warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 */

#ifndef WAYLAND_H
#define WAYLAND_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "wayland-util.h"
#include "wayland-server-protocol.h"

enum {
	WL_EVENT_READABLE = 0x01,
	WL_EVENT_WRITABLE = 0x02
};

struct wl_event_loop;
struct wl_event_source;
typedef int (*wl_event_loop_fd_func_t)(int fd, uint32_t mask, void *data);
typedef int (*wl_event_loop_timer_func_t)(void *data);
typedef int (*wl_event_loop_signal_func_t)(int signal_number, void *data);
typedef void (*wl_event_loop_idle_func_t)(void *data);

struct wl_event_loop *wl_event_loop_create(void);
void wl_event_loop_destroy(struct wl_event_loop *loop);
struct wl_event_source *wl_event_loop_add_fd(struct wl_event_loop *loop,
					     int fd, uint32_t mask,
					     wl_event_loop_fd_func_t func,
					     void *data);
int wl_event_source_fd_update(struct wl_event_source *source, uint32_t mask);
struct wl_event_source *wl_event_loop_add_timer(struct wl_event_loop *loop,
						wl_event_loop_timer_func_t func,
						void *data);
struct wl_event_source *
wl_event_loop_add_signal(struct wl_event_loop *loop,
			int signal_number,
			wl_event_loop_signal_func_t func,
			void *data);

int wl_event_source_timer_update(struct wl_event_source *source,
				 int ms_delay);
int wl_event_source_remove(struct wl_event_source *source);
void wl_event_source_check(struct wl_event_source *source);


int wl_event_loop_dispatch(struct wl_event_loop *loop, int timeout);
struct wl_event_source *wl_event_loop_add_idle(struct wl_event_loop *loop,
					       wl_event_loop_idle_func_t func,
					       void *data);
int wl_event_loop_get_fd(struct wl_event_loop *loop);

struct wl_client;
struct wl_display;
struct wl_input_device;

struct wl_display *wl_display_create(void);
void wl_display_destroy(struct wl_display *display);
struct wl_event_loop *wl_display_get_event_loop(struct wl_display *display);
int wl_display_add_socket(struct wl_display *display, const char *name);
void wl_display_terminate(struct wl_display *display);
void wl_display_run(struct wl_display *display);

void wl_display_add_object(struct wl_display *display,
			   struct wl_object *object);

typedef void (*wl_global_bind_func_t)(struct wl_client *client, void *data,
				      uint32_t version, uint32_t id);

struct wl_global *wl_display_add_global(struct wl_display *display,
					const struct wl_interface *interface,
					void *data,
					wl_global_bind_func_t bind);

void wl_display_remove_global(struct wl_display *display,
			      struct wl_global *global);

struct wl_client *wl_client_create(struct wl_display *display, int fd);
void wl_client_destroy(struct wl_client *client);
void wl_client_flush(struct wl_client *client);

struct wl_resource *
wl_client_add_object(struct wl_client *client,
		     const struct wl_interface *interface,
		     const void *implementation, uint32_t id, void *data);
struct wl_resource *
wl_client_new_object(struct wl_client *client,
		     const struct wl_interface *interface,
		     const void *implementation, void *data);

struct wl_resource {
	struct wl_object object;
	void (*destroy)(struct wl_resource *resource);
	struct wl_list link;
	struct wl_list destroy_listener_list;
	struct wl_client *client;
	void *data;
};

struct wl_shm_callbacks {
	void (*buffer_created)(struct wl_buffer *buffer);

	void (*buffer_damaged)(struct wl_buffer *buffer,
			      int32_t x, int32_t y,
			      int32_t width, int32_t height);

	void (*buffer_destroyed)(struct wl_buffer *buffer);
};

struct wl_buffer {
	struct wl_resource resource;
	int32_t width, height;
	uint32_t busy_count;
	void *user_data;
};

struct wl_listener {
	struct wl_list link;
	void (*func)(struct wl_listener *listener,
		     struct wl_resource *resource, uint32_t time);
};

struct wl_surface {
	struct wl_resource resource;
};

struct wl_grab;
struct wl_grab_interface {
	void (*focus)(struct wl_grab *grab, uint32_t time,
		      struct wl_surface *surface, int32_t x, int32_t y);
	void (*motion)(struct wl_grab *grab,
		       uint32_t time, int32_t x, int32_t y);
	void (*button)(struct wl_grab *grab,
		       uint32_t time, int32_t button, int32_t state);
};

struct wl_grab {
	const struct wl_grab_interface *interface;
	struct wl_input_device *input_device;
	struct wl_surface *focus;
	int32_t x, y;
};

struct wl_data_offer {
	struct wl_resource resource;
	struct wl_data_source *source;
	struct wl_listener source_destroy_listener;
};

struct wl_data_source {
	struct wl_resource resource;
	struct wl_array mime_types;

	const struct wl_data_offer_interface *offer_interface;
	void (*cancel)(struct wl_data_source *source);
};

struct wl_selection_listener {
	void (*func)(struct wl_selection_listener *listener,
		     struct wl_input_device *device);
	struct wl_list link;
};

struct wl_input_device {
	struct wl_list resource_list;
	struct wl_resource *pointer_focus_resource;
	struct wl_surface *pointer_focus;
	struct wl_resource *keyboard_focus_resource;
	struct wl_surface *keyboard_focus;
	struct wl_array keys;
	uint32_t pointer_focus_time;
	uint32_t keyboard_focus_time;
	struct wl_listener pointer_focus_listener;
	struct wl_listener keyboard_focus_listener;

	int32_t x, y;
	struct wl_surface *current;
	int32_t current_x, current_y;

	struct wl_grab *grab;
	struct wl_grab default_grab;
	uint32_t button_count;
	uint32_t grab_time;
	int32_t grab_x, grab_y;
	uint32_t grab_button;
	struct wl_listener grab_listener;

	struct wl_list drag_resource_list;
	struct wl_data_source *drag_data_source;
	struct wl_surface *drag_focus;
	struct wl_resource *drag_focus_resource;
	struct wl_listener drag_focus_listener;
	struct wl_grab drag_grab;

	struct wl_data_source *selection_data_source;
	struct wl_listener selection_data_source_listener;
	struct wl_list selection_listener_list;

};

/*
 * Post an event to the client's object referred to by 'resource'.
 * 'opcode' is the event number generated from the protocol XML
 * description (the event name). The variable arguments are the event
 * parameters, in the order they appear in the protocol XML specification.
 *
 * The variable arguments' types are:
 * - type=uint: 	uint32_t
 * - type=int:		int32_t
 * - type=string:	(const char *) to a nil-terminated string
 * - type=array:	(struct wl_array *)
 * - type=fd:		int, that is an open file descriptor
 * - type=new_id:	(struct wl_object *) or (struct wl_resource *)
 * - type=object:	(struct wl_object *) or (struct wl_resource *)
 */
void wl_resource_post_event(struct wl_resource *resource,
			    uint32_t opcode, ...);
void wl_resource_queue_event(struct wl_resource *resource,
			     uint32_t opcode, ...);

/* msg is a printf format string, variable args are its args. */
void wl_resource_post_error(struct wl_resource *resource,
			    uint32_t code, const char *msg, ...);
void wl_resource_post_no_memory(struct wl_resource *resource);

void
wl_display_post_frame(struct wl_display *display, struct wl_surface *surface,
		      uint32_t msecs);

void
wl_client_add_resource(struct wl_client *client,
		       struct wl_resource *resource);

struct wl_display *
wl_client_get_display(struct wl_client *client);

void
wl_resource_destroy(struct wl_resource *resource, uint32_t time);

void
wl_input_device_init(struct wl_input_device *device);

void
wl_input_device_release(struct wl_input_device *device);

void
wl_input_device_set_pointer_focus(struct wl_input_device *device,
				  struct wl_surface *surface,
				  uint32_t time,
				  int32_t x, int32_t y,
				  int32_t sx, int32_t sy);

void
wl_input_device_set_keyboard_focus(struct wl_input_device *device,
				   struct wl_surface *surface,
				   uint32_t time);
void
wl_data_device_set_keyboard_focus(struct wl_input_device *device);
int
wl_data_device_manager_init(struct wl_display *display);

void
wl_input_device_end_grab(struct wl_input_device *device, uint32_t time);
void
wl_input_device_start_grab(struct wl_input_device *device,
			   struct wl_grab *grab, uint32_t time);

void
wl_input_device_set_selection(struct wl_input_device *device,
			      struct wl_data_source *source,
			      uint32_t time);


struct wl_shm;

void *
wl_shm_buffer_get_data(struct wl_buffer *buffer);

int32_t
wl_shm_buffer_get_stride(struct wl_buffer *buffer);

uint32_t
wl_shm_buffer_get_format(struct wl_buffer *buffer);

struct wl_buffer *
wl_shm_buffer_create(struct wl_shm *shm, int width, int height,
		     int stride, uint32_t visual, void *data);

int
wl_buffer_is_shm(struct wl_buffer *buffer);

struct wl_shm *
wl_shm_init(struct wl_display *display,
	    const struct wl_shm_callbacks *callbacks);

void
wl_shm_finish(struct wl_shm *shm);

#ifdef  __cplusplus
}
#endif

#endif
