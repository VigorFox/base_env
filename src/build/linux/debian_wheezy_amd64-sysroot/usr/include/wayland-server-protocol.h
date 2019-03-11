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

#ifndef WAYLAND_SERVER_PROTOCOL_H
#define WAYLAND_SERVER_PROTOCOL_H

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
 * @bind: bind an object to the display
 * @sync: asynchronous roundtrip
 *
 * The core global object. This is a special singleton object. It is used for
 * internal wayland protocol features.  */
struct wl_display_interface {
	/**
	 * bind - bind an object to the display
	 * @name: unique number id for object
	 * @interface: (none)
	 * @version: (none)
	 * @id: (none)
	 * Binds a new, client created object to the server using @name as the
         * identifier. 
	 */
	void (*bind)(struct wl_client *client,
		     struct wl_resource *resource,
		     uint32_t name,
		     const char *interface,
		     uint32_t version,
		     uint32_t id);
	/**
	 * sync - asynchronous roundtrip
	 * @callback: (none)
	 * The sync request asks the server to invoke the 'done' request on the
         * provided wl_callback object. Since requests are handled in-order,
         * this can be used as a barrier to ensure all previous requests have
         * been handled. 
	 */
	void (*sync)(struct wl_client *client,
		     struct wl_resource *resource,
		     uint32_t callback);
};

#define WL_DISPLAY_ERROR	0
#define WL_DISPLAY_GLOBAL	1
#define WL_DISPLAY_GLOBAL_REMOVE	2
#define WL_DISPLAY_DELETE_ID	3

#define WL_CALLBACK_DONE	0

/**
 * wl_compositor - the compositor singleton
 * @create_surface: create new surface
 *
 * A compositor. This object is a singleton global. The compositor is in charge
 * of combining the contents of multiple surfaces into one displayable output. */
struct wl_compositor_interface {
	/**
	 * create_surface - create new surface
	 * @id: (none)
	 * Ask the compositor to create a new surface. 
	 */
	void (*create_surface)(struct wl_client *client,
			       struct wl_resource *resource,
			       uint32_t id);
};

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
 * @create_buffer: create a wl_buffer
 *
 * Support for shared memory buffers.  */
struct wl_shm_interface {
	/**
	 * create_buffer - create a wl_buffer
	 * @id: (none)
	 * @fd: (none)
	 * @width: (none)
	 * @height: (none)
	 * @stride: (none)
	 * @format: (none)
	 * Transfer a shm buffer to the server. The allocated buffer would include
         * at least stride * height bytes starting at the beginning of fd. The
         * file descriptor is transferred over the socket using AF_UNIX magical
         * features. width, height, stride and format describe the respective
         * properties of the pixel data contained in the buffer. 
	 */
	void (*create_buffer)(struct wl_client *client,
			      struct wl_resource *resource,
			      uint32_t id,
			      int32_t fd,
			      int32_t width,
			      int32_t height,
			      uint32_t stride,
			      uint32_t format);
};

#define WL_SHM_FORMAT	0

/**
 * wl_buffer - content for a wl_surface
 * @damage: mark part of the buffer damaged
 * @destroy: destroy a buffer
 *
 * A buffer provides the content for a wl_surface. Buffers are created through
 * factory interfaces such as wl_drm, wl_shm or similar. It has a width and a
 * height and can be attached to a wl_surface, but the mechanism by which a client
 * provides and updates the contents is defined by the buffer factory interface */
struct wl_buffer_interface {
	/**
	 * damage - mark part of the buffer damaged
	 * @x: (none)
	 * @y: (none)
	 * @width: (none)
	 * @height: (none)
	 * Notify the server that the specified area of the buffers contents
         * have changed. To describe a more complicated area of damage, break
         * down the region into rectangles and use this request several times.
	 */
	void (*damage)(struct wl_client *client,
		       struct wl_resource *resource,
		       int32_t x,
		       int32_t y,
		       int32_t width,
		       int32_t height);
	/**
	 * destroy - destroy a buffer
	 * Destroy a buffer. This will invalidate the object id. 
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
};

#define WL_BUFFER_RELEASE	0

struct wl_data_offer_interface {
	/**
	 * accept - accept one of the offered mime-types
	 * @time: (none)
	 * @type: (none)
	 * Indicate that the client can accept the given mime-type, or NULL for
         * not accepted. Use for feedback during drag and drop. 
	 */
	void (*accept)(struct wl_client *client,
		       struct wl_resource *resource,
		       uint32_t time,
		       const char *type);
	/**
	 * receive - (none)
	 * @mime_type: (none)
	 * @fd: (none)
	 */
	void (*receive)(struct wl_client *client,
			struct wl_resource *resource,
			const char *mime_type,
			int32_t fd);
	/**
	 * destroy - (none)
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
};

#define WL_DATA_OFFER_OFFER	0

struct wl_data_source_interface {
	/**
	 * offer - add an offered mime type
	 * @type: (none)
	 * This request adds a mime-type to the set of mime-types advertised
         * to targets. Can be called several times to offer multiple types. 
	 */
	void (*offer)(struct wl_client *client,
		      struct wl_resource *resource,
		      const char *type);
	/**
	 * destroy - destroy the data source
	 * Destroy the data source. 
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
};

#define WL_DATA_SOURCE_TARGET	0
#define WL_DATA_SOURCE_SEND	1
#define WL_DATA_SOURCE_CANCELLED	2

struct wl_data_device_interface {
	/**
	 * start_drag - (none)
	 * @source: (none)
	 * @surface: (none)
	 * @time: (none)
	 */
	void (*start_drag)(struct wl_client *client,
			   struct wl_resource *resource,
			   struct wl_resource *source,
			   struct wl_resource *surface,
			   uint32_t time);
	/**
	 * attach - (none)
	 * @time: (none)
	 * @buffer: (none)
	 * @x: (none)
	 * @y: (none)
	 */
	void (*attach)(struct wl_client *client,
		       struct wl_resource *resource,
		       uint32_t time,
		       struct wl_resource *buffer,
		       int32_t x,
		       int32_t y);
	/**
	 * set_selection - (none)
	 * @source: (none)
	 * @time: (none)
	 */
	void (*set_selection)(struct wl_client *client,
			      struct wl_resource *resource,
			      struct wl_resource *source,
			      uint32_t time);
};

#define WL_DATA_DEVICE_DATA_OFFER	0
#define WL_DATA_DEVICE_ENTER	1
#define WL_DATA_DEVICE_LEAVE	2
#define WL_DATA_DEVICE_MOTION	3
#define WL_DATA_DEVICE_DROP	4
#define WL_DATA_DEVICE_SELECTION	5

struct wl_data_device_manager_interface {
	/**
	 * create_data_source - (none)
	 * @id: (none)
	 */
	void (*create_data_source)(struct wl_client *client,
				   struct wl_resource *resource,
				   uint32_t id);
	/**
	 * get_data_device - (none)
	 * @id: (none)
	 * @input_device: (none)
	 */
	void (*get_data_device)(struct wl_client *client,
				struct wl_resource *resource,
				uint32_t id,
				struct wl_resource *input_device);
};

struct wl_shell_interface {
	/**
	 * get_shell_surface - (none)
	 * @id: (none)
	 * @surface: (none)
	 */
	void (*get_shell_surface)(struct wl_client *client,
				  struct wl_resource *resource,
				  uint32_t id,
				  struct wl_resource *surface);
};

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
 * @move: (none)
 * @resize: (none)
 * @set_toplevel: make the surface a top level surface
 * @set_transient: make the surface a transient surface
 * @set_fullscreen: make the surface a fullscreen surface
 * @set_popup: make the surface a popup surface
 *
 * An interface implemented by a wl_surface. On server side the object is automatically
 * destroyed when the related wl_surface is destroyed. On client side, wl_shell_surface_destroy()
 * must be called before destroying the wl_surface object.  */
struct wl_shell_surface_interface {
	/**
	 * move - (none)
	 * @input_device: (none)
	 * @time: (none)
	 */
	void (*move)(struct wl_client *client,
		     struct wl_resource *resource,
		     struct wl_resource *input_device,
		     uint32_t time);
	/**
	 * resize - (none)
	 * @input_device: (none)
	 * @time: (none)
	 * @edges: (none)
	 */
	void (*resize)(struct wl_client *client,
		       struct wl_resource *resource,
		       struct wl_resource *input_device,
		       uint32_t time,
		       uint32_t edges);
	/**
	 * set_toplevel - make the surface a top level surface
	 * Make the surface a toplevel window. 
	 */
	void (*set_toplevel)(struct wl_client *client,
			     struct wl_resource *resource);
	/**
	 * set_transient - make the surface a transient surface
	 * @parent: (none)
	 * @x: (none)
	 * @y: (none)
	 * @flags: (none)
	 * Map the surface relative to an existing surface. The x and y arguments
         * specify the locations of the upper left corner of the surface relative
         * to the upper left corner of the parent surface. The flags argument
         * controls overflow/clipping behaviour when the surface would intersect
         * a screen edge, panel or such. And possibly whether the offset only
         * determines the initial position or if the surface is locked to that
         * relative position during moves. 
	 */
	void (*set_transient)(struct wl_client *client,
			      struct wl_resource *resource,
			      struct wl_resource *parent,
			      int32_t x,
			      int32_t y,
			      uint32_t flags);
	/**
	 * set_fullscreen - make the surface a fullscreen surface
	 * Map the surface as a fullscreen surface. There are a number of options
         * here: on which output? if the surface size doesn't match the output
         * size, do we scale, change resolution, or add black borders? is that
         * something the client controls? what about transient surfaces, do they
         * float on top of the fullscreen? what if there's already a fullscreen
         * surface on the output, maybe you can only go fullscreen if you're
         * active? 
	 */
	void (*set_fullscreen)(struct wl_client *client,
			       struct wl_resource *resource);
	/**
	 * set_popup - make the surface a popup surface
	 * @input_device: (none)
	 * @time: (none)
	 * @parent: (none)
	 * @x: (none)
	 * @y: (none)
	 * @flags: (none)
	 * Popup surfaces. Will switch an implicit grab into owner-events mode,
         * and grab will continue after the implicit grab ends (button released).
         * Once the implicit grab is over, the popup grab continues until the
         * window is destroyed or a mouse button is pressed in any other clients
         * window. A click in any of the clients surfaces is reported as normal,
         * however, clicks in other clients surfaces will be discarded and trigger
         * the callback. TODO: Grab keyboard too, maybe just terminate on any
         * click inside or outside the surface? 
	 */
	void (*set_popup)(struct wl_client *client,
			  struct wl_resource *resource,
			  struct wl_resource *input_device,
			  uint32_t time,
			  struct wl_resource *parent,
			  int32_t x,
			  int32_t y,
			  uint32_t flags);
};

#define WL_SHELL_SURFACE_CONFIGURE	0
#define WL_SHELL_SURFACE_POPUP_DONE	1

/**
 * wl_surface - an onscreen surface
 * @destroy: delete surface
 * @attach: set the surface contents
 * @damage: mark part of the surface damaged
 * @frame: request repaint feedback
 *
 * A surface. This is an image that is displayed on the screen. It has a location,
 * size and pixel contents.  */
struct wl_surface_interface {
	/**
	 * destroy - delete surface
	 * Deletes the surface and invalidates its object id. 
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
	/**
	 * attach - set the surface contents
	 * @buffer: (none)
	 * @x: (none)
	 * @y: (none)
	 * Copy the contents of a buffer into this surface. The x and y arguments
         * specify the location of the new buffers upper left corner, relative
         * to the old buffers upper left corner. 
	 */
	void (*attach)(struct wl_client *client,
		       struct wl_resource *resource,
		       struct wl_resource *buffer,
		       int32_t x,
		       int32_t y);
	/**
	 * damage - mark part of the surface damaged
	 * @x: (none)
	 * @y: (none)
	 * @width: (none)
	 * @height: (none)
	 * After attaching a new buffer, this request is used to describe the
         * regions where the new buffer is different from the previous buffer
         * and needs to be repainted. Coordinates are relative to the new buffer.
	 */
	void (*damage)(struct wl_client *client,
		       struct wl_resource *resource,
		       int32_t x,
		       int32_t y,
		       int32_t width,
		       int32_t height);
	/**
	 * frame - request repaint feedback
	 * @callback: (none)
	 * Request notification when the next frame is displayed. Useful for
         * throttling redrawing operations, and driving animations. The notification
         * will only be posted for one frame unless requested again. 
	 */
	void (*frame)(struct wl_client *client,
		      struct wl_resource *resource,
		      uint32_t callback);
};

/**
 * wl_input_device - input device group
 * @attach: set the pointer image
 *
 * A group of keyboards and pointer devices (mice, for example). This object
 * is published as a global during start up, or when such a device is hot plugged.
 * A input_device group typically has a pointer and maintains a keyboard_focus
 * and a pointer_focus.  */
struct wl_input_device_interface {
	/**
	 * attach - set the pointer image
	 * @time: (none)
	 * @buffer: (none)
	 * @hotspot_x: (none)
	 * @hotspot_y: (none)
	 * Set the pointer's image. This request only takes effect if the pointer
         * focus for this device is one of the requesting clients surfaces. 
	 */
	void (*attach)(struct wl_client *client,
		       struct wl_resource *resource,
		       uint32_t time,
		       struct wl_resource *buffer,
		       int32_t hotspot_x,
		       int32_t hotspot_y);
};

#define WL_INPUT_DEVICE_MOTION	0
#define WL_INPUT_DEVICE_BUTTON	1
#define WL_INPUT_DEVICE_KEY	2
#define WL_INPUT_DEVICE_POINTER_FOCUS	3
#define WL_INPUT_DEVICE_KEYBOARD_FOCUS	4
#define WL_INPUT_DEVICE_TOUCH_DOWN	5
#define WL_INPUT_DEVICE_TOUCH_UP	6
#define WL_INPUT_DEVICE_TOUCH_MOTION	7
#define WL_INPUT_DEVICE_TOUCH_FRAME	8
#define WL_INPUT_DEVICE_TOUCH_CANCEL	9

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

#define WL_OUTPUT_GEOMETRY	0
#define WL_OUTPUT_MODE	1

#ifdef  __cplusplus
}
#endif

#endif
