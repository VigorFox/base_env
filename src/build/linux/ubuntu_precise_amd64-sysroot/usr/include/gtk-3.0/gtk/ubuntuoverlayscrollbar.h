/*
 * Copyright (C) 2011 Canonical, Ltd.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Authors: Andrea Cimitan <andrea.cimitan@canonical.com>
 */

#if defined(GTK_DISABLE_SINGLE_INCLUDES) && !defined (__GTK_H_INSIDE__) && !defined (GTK_COMPILATION)
#error "Only <gtk/gtk.h> can be included directly."
#endif

#ifndef __UBUNTU_OVERLAY_SCROLLBAR_H__
#define __UBUNTU_OVERLAY_SCROLLBAR_H__

#include <gtk/gtkwidget.h>

G_BEGIN_DECLS

gboolean   ubuntu_overlay_scrollbar_get_enabled (void);

void       ubuntu_overlay_scrollbar_set_enabled (gboolean enabled);

void       _ubuntu_overlay_scrollbar_init       (void);

GtkWidget* _ubuntu_overlay_scrollbar_new        (GtkOrientation orientation,
                                                                 GtkAdjustment* adjustment);

G_END_DECLS

#endif /* __UBUNTU_OVERLAY_SCROLLBAR_H__ */
