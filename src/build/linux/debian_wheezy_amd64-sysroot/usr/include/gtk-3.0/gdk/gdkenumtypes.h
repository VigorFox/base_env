
/* Generated data (by glib-mkenums) */

#if !defined (__GDK_H_INSIDE__) && !defined (GDK_COMPILATION)
#error "Only <gdk/gdk.h> can be included directly."
#endif

#ifndef __GDK_ENUM_TYPES_H__
#define __GDK_ENUM_TYPES_H__

#include <glib-object.h>

G_BEGIN_DECLS

/* enumerations from "gdkcursor.h" */
GType gdk_cursor_type_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_CURSOR_TYPE (gdk_cursor_type_get_type ())

/* enumerations from "gdkdevice.h" */
GType gdk_input_source_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_INPUT_SOURCE (gdk_input_source_get_type ())
GType gdk_input_mode_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_INPUT_MODE (gdk_input_mode_get_type ())
GType gdk_axis_use_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_AXIS_USE (gdk_axis_use_get_type ())
GType gdk_device_type_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_DEVICE_TYPE (gdk_device_type_get_type ())

/* enumerations from "gdkdnd.h" */
GType gdk_drag_action_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_DRAG_ACTION (gdk_drag_action_get_type ())
GType gdk_drag_protocol_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_DRAG_PROTOCOL (gdk_drag_protocol_get_type ())

/* enumerations from "gdkevents.h" */
GType gdk_filter_return_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_FILTER_RETURN (gdk_filter_return_get_type ())
GType gdk_event_type_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_EVENT_TYPE (gdk_event_type_get_type ())
GType gdk_visibility_state_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_VISIBILITY_STATE (gdk_visibility_state_get_type ())
GType gdk_scroll_direction_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_SCROLL_DIRECTION (gdk_scroll_direction_get_type ())
GType gdk_notify_type_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_NOTIFY_TYPE (gdk_notify_type_get_type ())
GType gdk_crossing_mode_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_CROSSING_MODE (gdk_crossing_mode_get_type ())
GType gdk_property_state_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_PROPERTY_STATE (gdk_property_state_get_type ())
GType gdk_window_state_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_WINDOW_STATE (gdk_window_state_get_type ())
GType gdk_setting_action_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_SETTING_ACTION (gdk_setting_action_get_type ())
GType gdk_owner_change_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_OWNER_CHANGE (gdk_owner_change_get_type ())

/* enumerations from "gdkproperty.h" */
GType gdk_prop_mode_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_PROP_MODE (gdk_prop_mode_get_type ())

/* enumerations from "gdktypes.h" */
GType gdk_byte_order_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_BYTE_ORDER (gdk_byte_order_get_type ())
GType gdk_modifier_type_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_MODIFIER_TYPE (gdk_modifier_type_get_type ())
GType gdk_modifier_intent_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_MODIFIER_INTENT (gdk_modifier_intent_get_type ())
GType gdk_status_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_STATUS (gdk_status_get_type ())
GType gdk_grab_status_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_GRAB_STATUS (gdk_grab_status_get_type ())
GType gdk_grab_ownership_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_GRAB_OWNERSHIP (gdk_grab_ownership_get_type ())
GType gdk_event_mask_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_EVENT_MASK (gdk_event_mask_get_type ())

/* enumerations from "gdkvisual.h" */
GType gdk_visual_type_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_VISUAL_TYPE (gdk_visual_type_get_type ())

/* enumerations from "gdkwindow.h" */
GType gdk_window_window_class_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_WINDOW_WINDOW_CLASS (gdk_window_window_class_get_type ())
GType gdk_window_type_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_WINDOW_TYPE (gdk_window_type_get_type ())
GType gdk_window_attributes_type_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_WINDOW_ATTRIBUTES_TYPE (gdk_window_attributes_type_get_type ())
GType gdk_window_hints_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_WINDOW_HINTS (gdk_window_hints_get_type ())
GType gdk_window_type_hint_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_WINDOW_TYPE_HINT (gdk_window_type_hint_get_type ())
GType gdk_wm_decoration_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_WM_DECORATION (gdk_wm_decoration_get_type ())
GType gdk_wm_function_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_WM_FUNCTION (gdk_wm_function_get_type ())
GType gdk_gravity_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_GRAVITY (gdk_gravity_get_type ())
GType gdk_window_edge_get_type (void) G_GNUC_CONST;
#define GDK_TYPE_WINDOW_EDGE (gdk_window_edge_get_type ())
G_END_DECLS

#endif /* __GDK_ENUM_TYPES_H__ */

/* Generated data ends here */

