
/* Generated data (by glib-mkenums) */

#ifndef __LIBQMI_GLIB_ENUM_TYPES_PRIVATE_H__
#define __LIBQMI_GLIB_ENUM_TYPES_PRIVATE_H__
#include "qmi-enums-private.h"

#include <glib-object.h>

G_BEGIN_DECLS

/* enumerations from "../../libqmi-glib/qmi-enums-private.h" */
GType qmi_ctl_data_format_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_CTL_DATA_FORMAT (qmi_ctl_data_format_get_type ())

/* Define type-specific symbols */
#define __QMI_CTL_DATA_FORMAT_IS_ENUM__

#if defined __QMI_CTL_DATA_FORMAT_IS_ENUM__
const gchar *qmi_ctl_data_format_get_string (QmiCtlDataFormat val);
#endif

#if defined __QMI_CTL_DATA_FORMAT_IS_FLAGS__
gchar *qmi_ctl_data_format_build_string_from_mask (QmiCtlDataFormat mask);
#endif

GType qmi_ctl_data_link_protocol_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_CTL_DATA_LINK_PROTOCOL (qmi_ctl_data_link_protocol_get_type ())

/* Define type-specific symbols */
#define __QMI_CTL_DATA_LINK_PROTOCOL_IS_ENUM__

#if defined __QMI_CTL_DATA_LINK_PROTOCOL_IS_ENUM__
const gchar *qmi_ctl_data_link_protocol_get_string (QmiCtlDataLinkProtocol val);
#endif

#if defined __QMI_CTL_DATA_LINK_PROTOCOL_IS_FLAGS__
gchar *qmi_ctl_data_link_protocol_build_string_from_mask (QmiCtlDataLinkProtocol mask);
#endif

GType qmi_ctl_flag_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_CTL_FLAG (qmi_ctl_flag_get_type ())

/* Define type-specific symbols */
#define __QMI_CTL_FLAG_IS_FLAGS__

#if defined __QMI_CTL_FLAG_IS_ENUM__
const gchar *qmi_ctl_flag_get_string (QmiCtlFlag val);
#endif

#if defined __QMI_CTL_FLAG_IS_FLAGS__
gchar *qmi_ctl_flag_build_string_from_mask (QmiCtlFlag mask);
#endif

GType qmi_service_flag_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_SERVICE_FLAG (qmi_service_flag_get_type ())

/* Define type-specific symbols */
#define __QMI_SERVICE_FLAG_IS_FLAGS__

#if defined __QMI_SERVICE_FLAG_IS_ENUM__
const gchar *qmi_service_flag_get_string (QmiServiceFlag val);
#endif

#if defined __QMI_SERVICE_FLAG_IS_FLAGS__
gchar *qmi_service_flag_build_string_from_mask (QmiServiceFlag mask);
#endif

G_END_DECLS

#endif /* __LIBQMI_GLIB_ENUM_TYPES_PRIVATE_H__ */

/* Generated data ends here */

