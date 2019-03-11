/* 
 * Copyright © 2008-2011 Kristian Høgsberg
 * Copyright © 2010-2011 Intel Corporation
 * 
 * Permission to use, copy, modify, distribute, and sell this
 * software and its documentation for any purpose is hereby granted
 * without fee, provided that the above copyright notice appear in
 * all copies and that both that copyright notice and this permission
 * notice appear in supporting documentation, and that the name of
 * the copyright holders not be used in advertising or publicity
 * pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied
 * warranty.
 * 
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS, IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
 * THIS SOFTWARE.
 */

#ifndef WAYLAND_CLIENT_PROTOCOL_H
#define WAYLAND_CLIENT_PROTOCOL_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include "wayland-util.h"

struct wl_client;
struct wl_resource;

struct wl_display;
struct wl_callback;
struct wl_compositor;
struct wl_shm;
struct wl_buffer;
struct wl_data_offer;
struct wl_data_source;
struct wl_data_device;
struct wl_data_device_manager;
struct wl_shell;
struct wl_shell_surface;
struct wl_surface;
struct wl_input_device;
struct wl_output;

extern const struct wl_interface wl_display_interface;
extern const struct wl_interface wl_callback_interface;
extern const struct wl_interface wl_compositor_interface;
extern const struct wl_interface wl_shm_interface;
extern const struct wl_interface wl_buffer_interface;
extern const struct wl_interface wl_data_offer_interface;
extern const struct wl_interface wl_data_source_interface;
extern const struct wl_interface wl_data_device_interface;
extern const struct wl_interface wl_data_device_manager_interface;
extern const struct wl_interface wl_shell_interface;
extern const struct wl_interface wl_shell_surface_interface;
extern const struct wl_interface wl_surface_interface;
extern const struct wl_interface wl_input_device_interface;
extern const struct wl_interface wl_output_interface;

#ifndef WL_DISPLAY_ERROR_ENUM
#define WL_DISPLAY_ERROR_ENUM
/**
 * wl_display_error - global error values
 * @WL_DISPLAY_ERROR_INVALID_OBJECT: server couldn't find object
 * @WL_DISPLAY_ERROR_INVALID_METHOD: method doesn't exist on the specified interface
 * @WL_DISPLAY_ERROR_NO_MEMORY: server is out of memory
 *
 * These errors are global and can be emitted in response to any server request. */
enum wl_display_error {
	WL_DISPLAY_ERROR_INVALID_OBJECT = 0,
	WL_DISPLAY_ERROR_INVALID_METHOD = 1,
	WL_DISPLAY_ERROR_NO_MEMORY = 2,
};
#endif /* WL_DISPLAY_ERROR_ENUM */

/**
 * wl_display - core global object
 * @error: fatal error event
 * @global: announce global object
 * @global_remove: announce removal of global object
 * @delete_id: acknowledge object id deletion
 *
 * The core global object. This is a special singleton object. It is used for
 * internal wayland protocol features.  */
struct wl_display_listener {
	/**
	 * error - fatal error event
	 * @object_id: (none)
	 * @code: (none)
	 * @message: (none)
	 * The error event is sent out when a fatal (non-recoverable) error has
         * occurred. 
	 */
	void (*error)(void *data,
		      struct wl_display *wl_display,
		      struct wl_object *object_id,
		      uint32_t code,
		      const char *message);
	/**
	 * global - announce global object
	 * @name: (none)
	 * @interface: (none)
	 * @version: (none)
	 * Notify the client of global objects. These are objects that are created
         * by the server. Globals are published on the initial client connection
         * sequence, upon device hotplugs, device disconnects, reconfiguration
         * or other events. A client can 'bind' to a global object by using the
         * bind request. This creates a client side handle that lets the object
         * emit events to the client and lets the client invoke requests on the
         * object. 
	 */
	void (*global)(void *data,
		       struct wl_display *wl_display,
		       uint32_t name,
		       const char *interface,
		       uint32_t version);
	/**
	 * global_remove - announce removal of global object
	 * @name: (none)
	 * Notify the client of removed global objects. 
	 */
	void (*global_remove)(void *data,
			      struct wl_display *wl_display,
			      uint32_t name);
	/**
	 * delete_id - acknowledge object id deletion
	 * @id: (none)
	 * Server has deleted the id and client can now reuse it. 
	 */
	void (*delete_id)(void *data,
			  struct wl_display *wl_display,
			  uint32_t id);
};

static inline int
wl_display_add_listener(struct wl_display *wl_display,
			const struct wl_display_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) wl_display,
				     (void (**)(void)) listener, data);
}

#define WL_DISPLAY_BIND	0
#define WL_DISPLAY_SYNC	1

struct wl_callback_listener {
	/**
	 * done - (none)
	 * @time: (none)
	 */
	void (*done)(void *data,
		     struct wl_callback *wl_callback,
		     uint32_t time);
};

static inline int
wl_callback_add_listener(struct wl_callback *wl_callback,
			 const struct wl_callback_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) wl_callback,
				     (void (**)(void)) listener, data);
}

static inline void
wl_callback_set_user_data(struct wl_callback *wl_callback, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) wl_callback, user_data);
}

static inline void *
wl_callback_get_user_data(struct wl_callback *wl_callback)
{
	return wl_proxy_get_user_data((struct wl_proxy *) wl_callback);
}

static inline void
wl_callback_destroy(struct wl_callback *wl_callback)
{
	wl_proxy_destroy((struct wl_proxy *) wl_callback);
}

#define WL_COMPOSITOR_CREATE_SURFACE	0

static inline void
wl_compositor_set_user_data(struct wl_compositor *wl_compositor, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) wl_compositor, user_data);
}

static inline void *
wl_compositor_get_user_data(struct wl_compositor *wl_compositor)
{
	return wl_proxy_get_user_data((struct wl_proxy *) wl_compositor);
}

static inline void
wl_compositor_destroy(struct wl_compositor *wl_compositor)
{
	wl_proxy_destroy((struct wl_proxy *) wl_compositor);
}

static inline struct wl_surface *
wl_compositor_create_surface(struct wl_compositor *wl_compositor)
{
	struct wl_proxy *id;

	id = wl_proxy_create((struct wl_proxy *) wl_compositor,
			     &wl_surface_interface);
	if (!id)
		return NULL;

	wl_proxy_marshal((struct wl_proxy *) wl_compositor,
			 WL_COMPOSITOR_CREATE_SURFACE, id);

	return (struct wl_surface *) id;
}

#ifndef WL_SHM_ERROR_ENUM
#define WL_SHM_ERROR_ENUM
enum wl_shm_error {
	WL_SHM_ERROR_INVALID_FORMAT = 0,
	WL_SHM_ERROR_INVALID_STRIDE = 1,
	WL_SHM_ERROR_INVALID_FD = 2,
};
#endif /* WL_SHM_ERROR_ENUM */

#ifndef WL_SHM_FORMAT_ENUM
#define WL_SHM_FORMAT_ENUM
enum wl_shm_format {
	WL_SHM_FORMAT_ARGB8888 = 0,
	WL_SHM_FORMAT_XRGB8888 = 1,
};
#endif /* WL_SHM_FORMAT_ENUM */

/**
 * wl_shm - shared memory support
 * @format: (none)
 *
 * Support for shared memory buffers.  */
struct wl_shm_listener {
	/**
	 * format - (none)
	 * @format: (none)
	 */
	void (*format)(void *data,
		       struct wl_shm *wl_shm,
		       uint32_t format);
};

static inline int
wl_shm_add_listener(struct wl_shm *wl_shm,
		    const struct wl_shm_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) wl_shm,
				     (void (**)(void)) listener, data);
}

#define WL_SHM_CREATE_BUFFER	0

static inline void
wl_shm_set_user_data(struct wl_shm *wl_shm, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) wl_shm, user_data);
}

static inline void *
wl_shm_get_user_data(struct wl_shm *wl_shm)
{
	return wl_proxy_get_user_data((struct wl_proxy *) wl_shm);
}

static inline void
wl_shm_destroy(struct wl_shm *wl_shm)
{
	wl_proxy_destroy((struct wl_proxy *) wl_shm);
}

static inline struct wl_buffer *
wl_shm_create_buffer(struct wl_shm *wl_shm, int32_t fd, int32_t width, int32_t height, uint32_t stride, uint32_t format)
{
	struct wl_proxy *id;

	id = wl_proxy_create((struct wl_proxy *) wl_shm,
			     &wl_buffer_interface);
	if (!id)
		return NULL;

	wl_proxy_marshal((struct wl_proxy *) wl_shm,
			 WL_SHM_CREATE_BUFFER, id, fd, width, height, stride, format);

	return (struct wl_buffer *) id;
}

/**
 * wl_buffer - content for a wl_surface
 * @release: compositor releases buffer
 *
 * A buffer provides the content for a wl_surface. Buffers are created through
 * factory interfaces such as wl_drm, wl_shm or similar. It has a width and a
 * height and can be attached to a wl_surface, but the mechanism by which a client
 * provides and updates the contents is defined by the buffer factory interface */
struct wl_buffer_listener {
	/**
	 * release - compositor releases buffer
	 * Sent when an attached buffer is no longer used by the compositor.
	 */
	void (*release)(void *data,
			struct wl_buffer *wl_buffer);
};

static inline int
wl_buffer_add_listener(struct wl_buffer *wl_buffer,
		       const struct wl_buffer_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) wl_buffer,
				     (void (**)(void)) listener, data);
}

#define WL_BUFFER_DAMAGE	0
#define WL_BUFFER_DESTROY	1

static inline void
wl_buffer_set_user_data(struct wl_buffer *wl_buffer, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) wl_buffer, user_data);
}

static inline void *
wl_buffer_get_user_data(struct wl_buffer *wl_buffer)
{
	return wl_proxy_get_user_data((struct wl_proxy *) wl_buffer);
}

static inline void
wl_buffer_damage(struct wl_buffer *wl_buffer, int32_t x, int32_t y, int32_t width, int32_t height)
{
	wl_proxy_marshal((struct wl_proxy *) wl_buffer,
			 WL_BUFFER_DAMAGE, x, y, width, height);
}

static inline void
wl_buffer_destroy(struct wl_buffer *wl_buffer)
{
	wl_proxy_marshal((struct wl_proxy *) wl_buffer,
			 WL_BUFFER_DESTROY);

	wl_proxy_destroy((struct wl_proxy *) wl_buffer);
}

struct wl_data_offer_listener {
	/**
	 * offer - advertise offered mime-type
	 * @type: (none)
	 * Sent immediately after creating the wl_data_offer object. One event
         * per offered mime type. 
	 */
	void (*offer)(void *data,
		      struct wl_data_offer *wl_data_offer,
		      const char *type);
};

static inline int
wl_data_offer_add_listener(struct wl_data_offer *wl_data_offer,
			   const struct wl_data_offer_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) wl_data_offer,
				     (void (**)(void)) listener, data);
}

#define WL_DATA_OFFER_ACCEPT	0
#define WL_DATA_OFFER_RECEIVE	1
#define WL_DATA_OFFER_DESTROY	2

static inline void
wl_data_offer_set_user_data(struct wl_data_offer *wl_data_offer, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) wl_data_offer, user_data);
}

static inline void *
wl_data_offer_get_user_data(struct wl_data_offer *wl_data_offer)
{
	return wl_proxy_get_user_data((struct wl_proxy *) wl_data_offer);
}

static inline void
wl_data_offer_accept(struct wl_data_offer *wl_data_offer, uint32_t time, const char *type)
{
	wl_proxy_marshal((struct wl_proxy *) wl_data_offer,
			 WL_DATA_OFFER_ACCEPT, time, type);
}

static inline void
wl_data_offer_receive(struct wl_data_offer *wl_data_offer, const char *mime_type, int32_t fd)
{
	wl_proxy_marshal((struct wl_proxy *) wl_data_offer,
			 WL_DATA_OFFER_RECEIVE, mime_type, fd);
}

static inline void
wl_data_offer_destroy(struct wl_data_offer *wl_data_offer)
{
	wl_proxy_marshal((struct wl_proxy *) wl_data_offer,
			 WL_DATA_OFFER_DESTROY);

	wl_proxy_destroy((struct wl_proxy *) wl_data_offer);
}

struct wl_data_source_listener {
	/**
	 * target - a target accepts an offered mime-type
	 * @mime_type: (none)
	 * Sent when a target accepts pointer_focus or motion events. If a target
         * does not accept any of the offered types, type is NULL. 
	 */
	void (*target)(void *data,
		       struct wl_data_source *wl_data_source,
		       const char *mime_type);
	/**
	 * send - send the data
	 * @mime_type: (none)
	 * @fd: (none)
	 * Request for data from another client. Send the data as the specified
         * mime-type over the passed fd, then close the fd. 
	 */
	void (*send)(void *data,
		     struct wl_data_source *wl_data_source,
		     const char *mime_type,
		     int32_t fd);
	/**
	 * cancelled - selection was cancelled
	 * Another selection became active. 
	 */
	void (*cancelled)(void *data,
			  struct wl_data_source *wl_data_source);
};

static inline int
wl_data_source_add_listener(struct wl_data_source *wl_data_source,
			    const struct wl_data_source_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) wl_data_source,
				     (void (**)(void)) listener, data);
}

#define WL_DATA_SOURCE_OFFER	0
#define WL_DATA_SOURCE_DESTROY	1

static inline void
wl_data_source_set_user_data(struct wl_data_source *wl_data_source, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) wl_data_source, user_data);
}

static inline void *
wl_data_source_get_user_data(struct wl_data_source *wl_data_source)
{
	return wl_proxy_get_user_data((struct wl_proxy *) wl_data_source);
}

static inline void
wl_data_source_offer(struct wl_data_source *wl_data_source, const char *type)
{
	wl_proxy_marshal((struct wl_proxy *) wl_data_source,
			 WL_DATA_SOURCE_OFFER, type);
}

static inline void
wl_data_source_destroy(struct wl_data_source *wl_data_source)
{
	wl_proxy_marshal((struct wl_proxy *) wl_data_source,
			 WL_DATA_SOURCE_DESTROY);

	wl_proxy_destroy((struct wl_proxy *) wl_data_source);
}

struct wl_data_device_listener {
	/**
	 * data_offer - introduce a new wl_data_offer
	 * @id: (none)
	 * The data_offer event introduces a new wl_data_offer object, which
         * will subsequently be used in either the data_device.enter event (for
         * drag and drop) or the data_device.selection event (for selections).
         * Immediately following the data_device_data_offer event, the new data_offer
         * object will send out data_offer.offer events to describe the mime-types
         * it offers. 
	 */
	void (*data_offer)(void *data,
			   struct wl_data_device *wl_data_device,
			   uint32_t id);
	/**
	 * enter - (none)
	 * @time: (none)
	 * @surface: (none)
	 * @x: (none)
	 * @y: (none)
	 * @id: (none)
	 */
	void (*enter)(void *data,
		      struct wl_data_device *wl_data_device,
		      uint32_t time,
		      struct wl_surface *surface,
		      int32_t x,
		      int32_t y,
		      struct wl_data_offer *id);
	/**
	 * leave - (none)
	 */
	void (*leave)(void *data,
		      struct wl_data_device *wl_data_device);
	/**
	 * motion - (none)
	 * @time: (none)
	 * @x: (none)
	 * @y: (none)
	 */
	void (*motion)(void *data,
		       struct wl_data_device *wl_data_device,
		       uint32_t time,
		       int32_t x,
		       int32_t y);
	/**
	 * drop - (none)
	 */
	void (*drop)(void *data,
		     struct wl_data_device *wl_data_device);
	/**
	 * selection - advertise new selection
	 * @id: (none)
	 * The selection event is sent out to notify the client of a new wl_data_offer
         * for the selection for this device. The data_device.data_offer and
         * the data_offer.offer events are sent out immediately before this event
         * to introduce the data offer object. The selection event is sent to
         * a client immediately before receiving keyboard focus and when a new
         * selection is set while the client has keyboard focus. The data_offer
         * is valid until a new data_offer or NULL is received or until the client
         * loses keyboard focus. 
	 */
	void (*selection)(void *data,
			  struct wl_data_device *wl_data_device,
			  struct wl_data_offer *id);
};

static inline int
wl_data_device_add_listener(struct wl_data_device *wl_data_device,
			    const struct wl_data_device_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) wl_data_device,
				     (void (**)(void)) listener, data);
}

#define WL_DATA_DEVICE_START_DRAG	0
#define WL_DATA_DEVICE_ATTACH	1
#define WL_DATA_DEVICE_SET_SELECTION	2

static inline void
wl_data_device_set_user_data(struct wl_data_device *wl_data_device, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) wl_data_device, user_data);
}

static inline void *
wl_data_device_get_user_data(struct wl_data_device *wl_data_device)
{
	return wl_proxy_get_user_data((struct wl_proxy *) wl_data_device);
}

static inline void
wl_data_device_destroy(struct wl_data_device *wl_data_device)
{
	wl_proxy_destroy((struct wl_proxy *) wl_data_device);
}

static inline void
wl_data_device_start_drag(struct wl_data_device *wl_data_device, struct wl_data_source *source, struct wl_surface *surface, uint32_t time)
{
	wl_proxy_marshal((struct wl_proxy *) wl_data_device,
			 WL_DATA_DEVICE_START_DRAG, source, surface, time);
}

static inline void
wl_data_device_attach(struct wl_data_device *wl_data_device, uint32_t time, struct wl_buffer *buffer, int32_t x, int32_t y)
{
	wl_proxy_marshal((struct wl_proxy *) wl_data_device,
			 WL_DATA_DEVICE_ATTACH, time, buffer, x, y);
}

static inline void
wl_data_device_set_selection(struct wl_data_device *wl_data_device, struct wl_data_source *source, uint32_t time)
{
	wl_proxy_marshal((struct wl_proxy *) wl_data_device,
			 WL_DATA_DEVICE_SET_SELECTION, source, time);
}

#define WL_DATA_DEVICE_MANAGER_CREATE_DATA_SOURCE	0
#define WL_DATA_DEVICE_MANAGER_GET_DATA_DEVICE	1

static inline void
wl_data_device_manager_set_user_data(struct wl_data_device_manager *wl_data_device_manager, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) wl_data_device_manager, user_data);
}

static inline void *
wl_data_device_manager_get_user_data(struct wl_data_device_manager *wl_data_device_manager)
{
	return wl_proxy_get_user_data((struct wl_proxy *) wl_data_device_manager);
}

static inline void
wl_data_device_manager_destroy(struct wl_data_device_manager *wl_data_device_manager)
{
	wl_proxy_destroy((struct wl_proxy *) wl_data_device_manager);
}

static inline struct wl_data_source *
wl_data_device_manager_create_data_source(struct wl_data_device_manager *wl_data_device_manager)
{
	struct wl_proxy *id;

	id = wl_proxy_create((struct wl_proxy *) wl_data_device_manager,
			     &wl_data_source_interface);
	if (!id)
		return NULL;

	wl_proxy_marshal((struct wl_proxy *) wl_data_device_manager,
			 WL_DATA_DEVICE_MANAGER_CREATE_DATA_SOURCE, id);

	return (struct wl_data_source *) id;
}

static inline struct wl_data_device *
wl_data_device_manager_get_data_device(struct wl_data_device_manager *wl_data_device_manager, struct wl_input_device *input_device)
{
	struct wl_proxy *id;

	id = wl_proxy_create((struct wl_proxy *) wl_data_device_manager,
			     &wl_data_device_interface);
	if (!id)
		return NULL;

	wl_proxy_marshal((struct wl_proxy *) wl_data_device_manager,
			 WL_DATA_DEVICE_MANAGER_GET_DATA_DEVICE, id, input_device);

	return (struct wl_data_device *) id;
}

#define WL_SHELL_GET_SHELL_SURFACE	0

static inline void
wl_shell_set_user_data(struct wl_shell *wl_shell, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) wl_shell, user_data);
}

static inline void *
wl_shell_get_user_data(struct wl_shell *wl_shell)
{
	return wl_proxy_get_user_data((struct wl_proxy *) wl_shell);
}

static inline void
wl_shell_destroy(struct wl_shell *wl_shell)
{
	wl_proxy_destroy((struct wl_proxy *) wl_shell);
}

static inline struct wl_shell_surface *
wl_shell_get_shell_surface(struct wl_shell *wl_shell, struct wl_surface *surface)
{
	struct wl_proxy *id;

	id = wl_proxy_create((struct wl_proxy *) wl_shell,
			     &wl_shell_surface_interface);
	if (!id)
		return NULL;

	wl_proxy_marshal((struct wl_proxy *) wl_shell,
			 WL_SHELL_GET_SHELL_SURFACE, id, surface);

	return (struct wl_shell_surface *) id;
}

#ifndef WL_SHELL_SURFACE_RESIZE_ENUM
#define WL_SHELL_SURFACE_RESIZE_ENUM
enum wl_shell_surface_resize {
	WL_SHELL_SURFACE_RESIZE_NONE = 0,
	WL_SHELL_SURFACE_RESIZE_TOP = 1,
	WL_SHELL_SURFACE_RESIZE_BOTTOM = 2,
	WL_SHELL_SURFACE_RESIZE_LEFT = 4,
	WL_SHELL_SURFACE_RESIZE_TOP_LEFT = 5,
	WL_SHELL_SURFACE_RESIZE_BOTTOM_LEFT = 6,
	WL_SHELL_SURFACE_RESIZE_RIGHT = 8,
	WL_SHELL_SURFACE_RESIZE_TOP_RIGHT = 9,
	WL_SHELL_SURFACE_RESIZE_BOTTOM_RIGHT = 10,
};
#endif /* WL_SHELL_SURFACE_RESIZE_ENUM */

/**
 * wl_shell_surface - desktop style meta data interface
 * @configure: suggest resize
 * @popup_done: popup interaction is done
 *
 * An interface implemented by a wl_surface. On server side the object is automatically
 * destroyed when the related wl_surface is destroyed. On client side, wl_shell_surface_destroy()
 * must be called before destroying the wl_surface object.  */
struct wl_shell_surface_listener {
	/**
	 * configure - suggest resize
	 * @time: (none)
	 * @edges: (none)
	 * @width: (none)
	 * @height: (none)
	 * The configure event asks the client to resize its surface. The size
         * is a hint, in the sense that the client is free to ignore it if it
         * doesn't resize, pick a smaller size (to satisfy aspect ration or resize
         * in steps of NxM pixels). The client is free to dismiss all but the
         * last configure event it received. 
	 */
	void (*configure)(void *data,
			  struct wl_shell_surface *wl_shell_surface,
			  uint32_t time,
			  uint32_t edges,
			  int32_t width,
			  int32_t height);
	/**
	 * popup_done - popup interaction is done
	 * The popup_done event is sent out when a popup grab is broken, that
         * is, when the users clicks a surface that doesn't belong to the client
         * owning the popup surface. 
	 */
	void (*popup_done)(void *data,
			   struct wl_shell_surface *wl_shell_surface);
};

static inline int
wl_shell_surface_add_listener(struct wl_shell_surface *wl_shell_surface,
			      const struct wl_shell_surface_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) wl_shell_surface,
				     (void (**)(void)) listener, data);
}

#define WL_SHELL_SURFACE_MOVE	0
#define WL_SHELL_SURFACE_RESIZE	1
#define WL_SHELL_SURFACE_SET_TOPLEVEL	2
#define WL_SHELL_SURFACE_SET_TRANSIENT	3
#define WL_SHELL_SURFACE_SET_FULLSCREEN	4
#define WL_SHELL_SURFACE_SET_POPUP	5

static inline void
wl_shell_surface_set_user_data(struct wl_shell_surface *wl_shell_surface, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) wl_shell_surface, user_data);
}

static inline void *
wl_shell_surface_get_user_data(struct wl_shell_surface *wl_shell_surface)
{
	return wl_proxy_get_user_data((struct wl_proxy *) wl_shell_surface);
}

static inline void
wl_shell_surface_destroy(struct wl_shell_surface *wl_shell_surface)
{
	wl_proxy_destroy((struct wl_proxy *) wl_shell_surface);
}

static inline void
wl_shell_surface_move(struct wl_shell_surface *wl_shell_surface, struct wl_input_device *input_device, uint32_t time)
{
	wl_proxy_marshal((struct wl_proxy *) wl_shell_surface,
			 WL_SHELL_SURFACE_MOVE, input_device, time);
}

static inline void
wl_shell_surface_resize(struct wl_shell_surface *wl_shell_surface, struct wl_input_device *input_device, uint32_t time, uint32_t edges)
{
	wl_proxy_marshal((struct wl_proxy *) wl_shell_surface,
			 WL_SHELL_SURFACE_RESIZE, input_device, time, edges);
}

static inline void
wl_shell_surface_set_toplevel(struct wl_shell_surface *wl_shell_surface)
{
	wl_proxy_marshal((struct wl_proxy *) wl_shell_surface,
			 WL_SHELL_SURFACE_SET_TOPLEVEL);
}

static inline void
wl_shell_surface_set_transient(struct wl_shell_surface *wl_shell_surface, struct wl_shell_surface *parent, int32_t x, int32_t y, uint32_t flags)
{
	wl_proxy_marshal((struct wl_proxy *) wl_shell_surface,
			 WL_SHELL_SURFACE_SET_TRANSIENT, parent, x, y, flags);
}

static inline void
wl_shell_surface_set_fullscreen(struct wl_shell_surface *wl_shell_surface)
{
	wl_proxy_marshal((struct wl_proxy *) wl_shell_surface,
			 WL_SHELL_SURFACE_SET_FULLSCREEN);
}

static inline void
wl_shell_surface_set_popup(struct wl_shell_surface *wl_shell_surface, struct wl_input_device *input_device, uint32_t time, struct wl_shell_surface *parent, int32_t x, int32_t y, uint32_t flags)
{
	wl_proxy_marshal((struct wl_proxy *) wl_shell_surface,
			 WL_SHELL_SURFACE_SET_POPUP, input_device, time, parent, x, y, flags);
}

#define WL_SURFACE_DESTROY	0
#define WL_SURFACE_ATTACH	1
#define WL_SURFACE_DAMAGE	2
#define WL_SURFACE_FRAME	3

static inline void
wl_surface_set_user_data(struct wl_surface *wl_surface, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) wl_surface, user_data);
}

static inline void *
wl_surface_get_user_data(struct wl_surface *wl_surface)
{
	return wl_proxy_get_user_data((struct wl_proxy *) wl_surface);
}

static inline void
wl_surface_destroy(struct wl_surface *wl_surface)
{
	wl_proxy_marshal((struct wl_proxy *) wl_surface,
			 WL_SURFACE_DESTROY);

	wl_proxy_destroy((struct wl_proxy *) wl_surface);
}

static inline void
wl_surface_attach(struct wl_surface *wl_surface, struct wl_buffer *buffer, int32_t x, int32_t y)
{
	wl_proxy_marshal((struct wl_proxy *) wl_surface,
			 WL_SURFACE_ATTACH, buffer, x, y);
}

static inline void
wl_surface_damage(struct wl_surface *wl_surface, int32_t x, int32_t y, int32_t width, int32_t height)
{
	wl_proxy_marshal((struct wl_proxy *) wl_surface,
			 WL_SURFACE_DAMAGE, x, y, width, height);
}

static inline struct wl_callback *
wl_surface_frame(struct wl_surface *wl_surface)
{
	struct wl_proxy *callback;

	callback = wl_proxy_create((struct wl_proxy *) wl_surface,
			     &wl_callback_interface);
	if (!callback)
		return NULL;

	wl_proxy_marshal((struct wl_proxy *) wl_surface,
			 WL_SURFACE_FRAME, callback);

	return (struct wl_callback *) callback;
}

/**
 * wl_input_device - input device group
 * @motion: pointer motion event
 * @button: pointer button event
 * @key: key event
 * @pointer_focus: pointer focus change event
 * @keyboard_focus: (none)
 * @touch_down: (none)
 * @touch_up: (none)
 * @touch_motion: (none)
 * @touch_frame: end of touch frame event
 * @touch_cancel: touch session cancelled
 *
 * A group of keyboards and pointer devices (mice, for example). This object
 * is published as a global during start up, or when such a device is hot plugged.
 * A input_device group typically has a pointer and maintains a keyboard_focus
 * and a pointer_focus.  */
struct wl_input_device_listener {
	/**
	 * motion - pointer motion event
	 * @time: (none)
	 * @x: (none)
	 * @y: (none)
	 * @surface_x: (none)
	 * @surface_y: (none)
	 * Notification of pointer location change. x,y are the absolute location
         * on the screen. surface_[xy] are the location relative to the focused
         * surface. 
	 */
	void (*motion)(void *data,
		       struct wl_input_device *wl_input_device,
		       uint32_t time,
		       int32_t x,
		       int32_t y,
		       int32_t surface_x,
		       int32_t surface_y);
	/**
	 * button - pointer button event
	 * @time: (none)
	 * @button: (none)
	 * @state: (none)
	 * Mouse button click and release notifications. The location of the
         * click is given by the last motion or pointer_focus event. 
	 */
	void (*button)(void *data,
		       struct wl_input_device *wl_input_device,
		       uint32_t time,
		       uint32_t button,
		       uint32_t state);
	/**
	 * key - key event
	 * @time: (none)
	 * @key: (none)
	 * @state: (none)
	 * A key was pressed or released. 
	 */
	void (*key)(void *data,
		    struct wl_input_device *wl_input_device,
		    uint32_t time,
		    uint32_t key,
		    uint32_t state);
	/**
	 * pointer_focus - pointer focus change event
	 * @time: (none)
	 * @surface: (none)
	 * @x: (none)
	 * @y: (none)
	 * @surface_x: (none)
	 * @surface_y: (none)
	 * Notification that this input device's pointer is focused on certain
         * surface. When an input_device enters a surface, the pointer image
         * is undefined and a client should respond to this event by setting
         * an appropriate pointer image. 
	 */
	void (*pointer_focus)(void *data,
			      struct wl_input_device *wl_input_device,
			      uint32_t time,
			      struct wl_surface *surface,
			      int32_t x,
			      int32_t y,
			      int32_t surface_x,
			      int32_t surface_y);
	/**
	 * keyboard_focus - (none)
	 * @time: (none)
	 * @surface: (none)
	 * @keys: (none)
	 */
	void (*keyboard_focus)(void *data,
			       struct wl_input_device *wl_input_device,
			       uint32_t time,
			       struct wl_surface *surface,
			       struct wl_array *keys);
	/**
	 * touch_down - (none)
	 * @time: (none)
	 * @surface: (none)
	 * @id: (none)
	 * @x: (none)
	 * @y: (none)
	 */
	void (*touch_down)(void *data,
			   struct wl_input_device *wl_input_device,
			   uint32_t time,
			   struct wl_surface *surface,
			   int32_t id,
			   int32_t x,
			   int32_t y);
	/**
	 * touch_up - (none)
	 * @time: (none)
	 * @id: (none)
	 */
	void (*touch_up)(void *data,
			 struct wl_input_device *wl_input_device,
			 uint32_t time,
			 int32_t id);
	/**
	 * touch_motion - (none)
	 * @time: (none)
	 * @id: (none)
	 * @x: (none)
	 * @y: (none)
	 */
	void (*touch_motion)(void *data,
			     struct wl_input_device *wl_input_device,
			     uint32_t time,
			     int32_t id,
			     int32_t x,
			     int32_t y);
	/**
	 * touch_frame - end of touch frame event
	 * Indicates the end of a contact point list. 
	 */
	void (*touch_frame)(void *data,
			    struct wl_input_device *wl_input_device);
	/**
	 * touch_cancel - touch session cancelled
	 * Sent if the compositor decides the touch stream is a global gesture.
         * No further events are sent to the clients from that particular gesture.
	 */
	void (*touch_cancel)(void *data,
			     struct wl_input_device *wl_input_device);
};

static inline int
wl_input_device_add_listener(struct wl_input_device *wl_input_device,
			     const struct wl_input_device_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) wl_input_device,
				     (void (**)(void)) listener, data);
}

#define WL_INPUT_DEVICE_ATTACH	0

static inline void
wl_input_device_set_user_data(struct wl_input_device *wl_input_device, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) wl_input_device, user_data);
}

static inline void *
wl_input_device_get_user_data(struct wl_input_device *wl_input_device)
{
	return wl_proxy_get_user_data((struct wl_proxy *) wl_input_device);
}

static inline void
wl_input_device_destroy(struct wl_input_device *wl_input_device)
{
	wl_proxy_destroy((struct wl_proxy *) wl_input_device);
}

static inline void
wl_input_device_attach(struct wl_input_device *wl_input_device, uint32_t time, struct wl_buffer *buffer, int32_t hotspot_x, int32_t hotspot_y)
{
	wl_proxy_marshal((struct wl_proxy *) wl_input_device,
			 WL_INPUT_DEVICE_ATTACH, time, buffer, hotspot_x, hotspot_y);
}

#ifndef WL_OUTPUT_SUBPIXEL_ENUM
#define WL_OUTPUT_SUBPIXEL_ENUM
enum wl_output_subpixel {
	WL_OUTPUT_SUBPIXEL_UNKNOWN = 0,
	WL_OUTPUT_SUBPIXEL_NONE = 1,
	WL_OUTPUT_SUBPIXEL_HORIZONTAL_RGB = 2,
	WL_OUTPUT_SUBPIXEL_HORIZONTAL_BGR = 3,
	WL_OUTPUT_SUBPIXEL_VERTICAL_RGB = 4,
	WL_OUTPUT_SUBPIXEL_VERTICAL_BGR = 5,
};
#endif /* WL_OUTPUT_SUBPIXEL_ENUM */

#ifndef WL_OUTPUT_MODE_ENUM
#define WL_OUTPUT_MODE_ENUM
/**
 * wl_output_mode - values for the flags bitfield in the mode event
 * @WL_OUTPUT_MODE_CURRENT: (null)
 * @WL_OUTPUT_MODE_PREFERRED: (null)
 *
 *  */
enum wl_output_mode {
	WL_OUTPUT_MODE_CURRENT = 0x1,
	WL_OUTPUT_MODE_PREFERRED = 0x2,
};
#endif /* WL_OUTPUT_MODE_ENUM */

/**
 * wl_output - compositor output region
 * @geometry: (none)
 * @mode: (none)
 *
 * An output describes part of the compositor geometry. The compositor work in
 * the 'compositor coordinate system' and an output corresponds to rectangular
 * area in that space that is actually visible. This typically corresponds to
 * a monitor that displays part of the compositor space. This object is published
 * as global during start up, or when a screen is hot plugged.  */
struct wl_output_listener {
	/**
	 * geometry - (none)
	 * @x: (none)
	 * @y: (none)
	 * @physical_width: (none)
	 * @physical_height: (none)
	 * @subpixel: (none)
	 * @make: (none)
	 * @model: (none)
	 */
	void (*geometry)(void *data,
			 struct wl_output *wl_output,
			 int32_t x,
			 int32_t y,
			 int32_t physical_width,
			 int32_t physical_height,
			 int32_t subpixel,
			 const char *make,
			 const char *model);
	/**
	 * mode - (none)
	 * @flags: (none)
	 * @width: (none)
	 * @height: (none)
	 * @refresh: (none)
	 */
	void (*mode)(void *data,
		     struct wl_output *wl_output,
		     uint32_t flags,
		     int32_t width,
		     int32_t height,
		     int32_t refresh);
};

static inline int
wl_output_add_listener(struct wl_output *wl_output,
		       const struct wl_output_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) wl_output,
				     (void (**)(void)) listener, data);
}

static inline void
wl_output_set_user_data(struct wl_output *wl_output, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) wl_output, user_data);
}

static inline void *
wl_output_get_user_data(struct wl_output *wl_output)
{
	return wl_proxy_get_user_data((struct wl_proxy *) wl_output);
}

static inline void
wl_output_destroy(struct wl_output *wl_output)
{
	wl_proxy_destroy((struct wl_proxy *) wl_output);
}

#ifdef  __cplusplus
}
#endif

#endif
