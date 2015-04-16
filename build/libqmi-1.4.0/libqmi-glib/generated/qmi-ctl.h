
/* GENERATED CODE... DO NOT EDIT */

/*
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
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 * Copyright (C) 2012 Lanedo GmbH
 */


#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>

#include "qmi-enums.h"
#include "qmi-enums-private.h"
#include "qmi-message.h"
#include "qmi-client.h"

#ifndef __LIBQMI_GLIB_QMI_CTL__
#define __LIBQMI_GLIB_QMI_CTL__

G_BEGIN_DECLS


/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message CTL Set Instance ID */


/* --- Input -- */

/**
 * QmiMessageCtlSetInstanceIdInput:
 *
 * The #QmiMessageCtlSetInstanceIdInput structure contains private data and should only be accessed
 * using the provided API.
 */
typedef struct _QmiMessageCtlSetInstanceIdInput QmiMessageCtlSetInstanceIdInput;
GType qmi_message_ctl_set_instance_id_input_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_SET_INSTANCE_ID_INPUT (qmi_message_ctl_set_instance_id_input_get_type ())

gboolean qmi_message_ctl_set_instance_id_input_get_id (
    QmiMessageCtlSetInstanceIdInput *self,
    guint8 *id,
    GError **error);

gboolean qmi_message_ctl_set_instance_id_input_set_id (
    QmiMessageCtlSetInstanceIdInput *self,
    guint8 id,
    GError **error);

QmiMessageCtlSetInstanceIdInput *qmi_message_ctl_set_instance_id_input_ref (QmiMessageCtlSetInstanceIdInput *self);
void qmi_message_ctl_set_instance_id_input_unref (QmiMessageCtlSetInstanceIdInput *self);
QmiMessageCtlSetInstanceIdInput *qmi_message_ctl_set_instance_id_input_new (void);

/* --- Output -- */

/**
 * QmiMessageCtlSetInstanceIdOutput:
 *
 * The #QmiMessageCtlSetInstanceIdOutput structure contains private data and should only be accessed
 * using the provided API.
 */
typedef struct _QmiMessageCtlSetInstanceIdOutput QmiMessageCtlSetInstanceIdOutput;
GType qmi_message_ctl_set_instance_id_output_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_SET_INSTANCE_ID_OUTPUT (qmi_message_ctl_set_instance_id_output_get_type ())

gboolean qmi_message_ctl_set_instance_id_output_get_result (
    QmiMessageCtlSetInstanceIdOutput *self,
    GError **error);

gboolean qmi_message_ctl_set_instance_id_output_get_link_id (
    QmiMessageCtlSetInstanceIdOutput *self,
    guint16 *link_id,
    GError **error);

QmiMessageCtlSetInstanceIdOutput *qmi_message_ctl_set_instance_id_output_ref (QmiMessageCtlSetInstanceIdOutput *self);
void qmi_message_ctl_set_instance_id_output_unref (QmiMessageCtlSetInstanceIdOutput *self);

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message CTL Get Version Info */


/* --- Input -- */

/* Note: no fields in the Input container */

/* --- Output -- */

/**
 * QmiMessageCtlGetVersionInfoOutputServiceListService:
 * @service: a #QmiService.
 * @major_version: a #guint16.
 * @minor_version: a #guint16.
 *
 * A QmiMessageCtlGetVersionInfoOutputServiceListService struct.
 */
typedef struct _QmiMessageCtlGetVersionInfoOutputServiceListService {
    QmiService service;
    guint16 major_version;
    guint16 minor_version;
} QmiMessageCtlGetVersionInfoOutputServiceListService;

/**
 * QmiMessageCtlGetVersionInfoOutput:
 *
 * The #QmiMessageCtlGetVersionInfoOutput structure contains private data and should only be accessed
 * using the provided API.
 */
typedef struct _QmiMessageCtlGetVersionInfoOutput QmiMessageCtlGetVersionInfoOutput;
GType qmi_message_ctl_get_version_info_output_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_GET_VERSION_INFO_OUTPUT (qmi_message_ctl_get_version_info_output_get_type ())

gboolean qmi_message_ctl_get_version_info_output_get_result (
    QmiMessageCtlGetVersionInfoOutput *self,
    GError **error);

gboolean qmi_message_ctl_get_version_info_output_get_service_list (
    QmiMessageCtlGetVersionInfoOutput *self,
    GArray **service_list,
    GError **error);

QmiMessageCtlGetVersionInfoOutput *qmi_message_ctl_get_version_info_output_ref (QmiMessageCtlGetVersionInfoOutput *self);
void qmi_message_ctl_get_version_info_output_unref (QmiMessageCtlGetVersionInfoOutput *self);

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message CTL Allocate CID */


/* --- Input -- */

/**
 * QmiMessageCtlAllocateCidInput:
 *
 * The #QmiMessageCtlAllocateCidInput structure contains private data and should only be accessed
 * using the provided API.
 */
typedef struct _QmiMessageCtlAllocateCidInput QmiMessageCtlAllocateCidInput;
GType qmi_message_ctl_allocate_cid_input_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_ALLOCATE_CID_INPUT (qmi_message_ctl_allocate_cid_input_get_type ())

gboolean qmi_message_ctl_allocate_cid_input_get_service (
    QmiMessageCtlAllocateCidInput *self,
    QmiService *service,
    GError **error);

gboolean qmi_message_ctl_allocate_cid_input_set_service (
    QmiMessageCtlAllocateCidInput *self,
    QmiService service,
    GError **error);

QmiMessageCtlAllocateCidInput *qmi_message_ctl_allocate_cid_input_ref (QmiMessageCtlAllocateCidInput *self);
void qmi_message_ctl_allocate_cid_input_unref (QmiMessageCtlAllocateCidInput *self);
QmiMessageCtlAllocateCidInput *qmi_message_ctl_allocate_cid_input_new (void);

/* --- Output -- */

/**
 * QmiMessageCtlAllocateCidOutput:
 *
 * The #QmiMessageCtlAllocateCidOutput structure contains private data and should only be accessed
 * using the provided API.
 */
typedef struct _QmiMessageCtlAllocateCidOutput QmiMessageCtlAllocateCidOutput;
GType qmi_message_ctl_allocate_cid_output_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_ALLOCATE_CID_OUTPUT (qmi_message_ctl_allocate_cid_output_get_type ())

gboolean qmi_message_ctl_allocate_cid_output_get_result (
    QmiMessageCtlAllocateCidOutput *self,
    GError **error);

gboolean qmi_message_ctl_allocate_cid_output_get_allocation_info (
    QmiMessageCtlAllocateCidOutput *self,
    QmiService *allocation_info_service,
    guint8 *allocation_info_cid,
    GError **error);

QmiMessageCtlAllocateCidOutput *qmi_message_ctl_allocate_cid_output_ref (QmiMessageCtlAllocateCidOutput *self);
void qmi_message_ctl_allocate_cid_output_unref (QmiMessageCtlAllocateCidOutput *self);

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message CTL Release CID */


/* --- Input -- */

/**
 * QmiMessageCtlReleaseCidInput:
 *
 * The #QmiMessageCtlReleaseCidInput structure contains private data and should only be accessed
 * using the provided API.
 */
typedef struct _QmiMessageCtlReleaseCidInput QmiMessageCtlReleaseCidInput;
GType qmi_message_ctl_release_cid_input_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_RELEASE_CID_INPUT (qmi_message_ctl_release_cid_input_get_type ())

gboolean qmi_message_ctl_release_cid_input_get_release_info (
    QmiMessageCtlReleaseCidInput *self,
    QmiService *release_info_service,
    guint8 *release_info_cid,
    GError **error);

gboolean qmi_message_ctl_release_cid_input_set_release_info (
    QmiMessageCtlReleaseCidInput *self,
    QmiService release_info_service,
    guint8 release_info_cid,
    GError **error);

QmiMessageCtlReleaseCidInput *qmi_message_ctl_release_cid_input_ref (QmiMessageCtlReleaseCidInput *self);
void qmi_message_ctl_release_cid_input_unref (QmiMessageCtlReleaseCidInput *self);
QmiMessageCtlReleaseCidInput *qmi_message_ctl_release_cid_input_new (void);

/* --- Output -- */

/**
 * QmiMessageCtlReleaseCidOutput:
 *
 * The #QmiMessageCtlReleaseCidOutput structure contains private data and should only be accessed
 * using the provided API.
 */
typedef struct _QmiMessageCtlReleaseCidOutput QmiMessageCtlReleaseCidOutput;
GType qmi_message_ctl_release_cid_output_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_RELEASE_CID_OUTPUT (qmi_message_ctl_release_cid_output_get_type ())

gboolean qmi_message_ctl_release_cid_output_get_result (
    QmiMessageCtlReleaseCidOutput *self,
    GError **error);

gboolean qmi_message_ctl_release_cid_output_get_release_info (
    QmiMessageCtlReleaseCidOutput *self,
    QmiService *release_info_service,
    guint8 *release_info_cid,
    GError **error);

QmiMessageCtlReleaseCidOutput *qmi_message_ctl_release_cid_output_ref (QmiMessageCtlReleaseCidOutput *self);
void qmi_message_ctl_release_cid_output_unref (QmiMessageCtlReleaseCidOutput *self);

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message CTL Set Data Format */


/* --- Input -- */

/**
 * QmiMessageCtlSetDataFormatInput:
 *
 * The #QmiMessageCtlSetDataFormatInput structure contains private data and should only be accessed
 * using the provided API.
 */
typedef struct _QmiMessageCtlSetDataFormatInput QmiMessageCtlSetDataFormatInput;
GType qmi_message_ctl_set_data_format_input_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_SET_DATA_FORMAT_INPUT (qmi_message_ctl_set_data_format_input_get_type ())

gboolean qmi_message_ctl_set_data_format_input_get_protocol (
    QmiMessageCtlSetDataFormatInput *self,
    QmiCtlDataLinkProtocol *protocol,
    GError **error);

gboolean qmi_message_ctl_set_data_format_input_set_protocol (
    QmiMessageCtlSetDataFormatInput *self,
    QmiCtlDataLinkProtocol protocol,
    GError **error);

gboolean qmi_message_ctl_set_data_format_input_get_format (
    QmiMessageCtlSetDataFormatInput *self,
    QmiCtlDataFormat *format,
    GError **error);

gboolean qmi_message_ctl_set_data_format_input_set_format (
    QmiMessageCtlSetDataFormatInput *self,
    QmiCtlDataFormat format,
    GError **error);

QmiMessageCtlSetDataFormatInput *qmi_message_ctl_set_data_format_input_ref (QmiMessageCtlSetDataFormatInput *self);
void qmi_message_ctl_set_data_format_input_unref (QmiMessageCtlSetDataFormatInput *self);
QmiMessageCtlSetDataFormatInput *qmi_message_ctl_set_data_format_input_new (void);

/* --- Output -- */

/**
 * QmiMessageCtlSetDataFormatOutput:
 *
 * The #QmiMessageCtlSetDataFormatOutput structure contains private data and should only be accessed
 * using the provided API.
 */
typedef struct _QmiMessageCtlSetDataFormatOutput QmiMessageCtlSetDataFormatOutput;
GType qmi_message_ctl_set_data_format_output_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_SET_DATA_FORMAT_OUTPUT (qmi_message_ctl_set_data_format_output_get_type ())

gboolean qmi_message_ctl_set_data_format_output_get_result (
    QmiMessageCtlSetDataFormatOutput *self,
    GError **error);

gboolean qmi_message_ctl_set_data_format_output_get_protocol (
    QmiMessageCtlSetDataFormatOutput *self,
    QmiCtlDataLinkProtocol *protocol,
    GError **error);

QmiMessageCtlSetDataFormatOutput *qmi_message_ctl_set_data_format_output_ref (QmiMessageCtlSetDataFormatOutput *self);
void qmi_message_ctl_set_data_format_output_unref (QmiMessageCtlSetDataFormatOutput *self);

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message CTL Sync */


/* --- Input -- */

/* Note: no fields in the Input container */

/* --- Output -- */

/**
 * QmiMessageCtlSyncOutput:
 *
 * The #QmiMessageCtlSyncOutput structure contains private data and should only be accessed
 * using the provided API.
 */
typedef struct _QmiMessageCtlSyncOutput QmiMessageCtlSyncOutput;
GType qmi_message_ctl_sync_output_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_SYNC_OUTPUT (qmi_message_ctl_sync_output_get_type ())

gboolean qmi_message_ctl_sync_output_get_result (
    QmiMessageCtlSyncOutput *self,
    GError **error);

QmiMessageCtlSyncOutput *qmi_message_ctl_sync_output_ref (QmiMessageCtlSyncOutput *self);
void qmi_message_ctl_sync_output_unref (QmiMessageCtlSyncOutput *self);

/*****************************************************************************/
/* INDICATION: Qmi Indication CTL Sync */


/* --- Output -- */

/* Note: no fields in the Output container */

/*****************************************************************************/
/* Service-specific printable: CTL */


#if defined (LIBQMI_GLIB_COMPILATION)

G_GNUC_INTERNAL
gchar *__qmi_message_ctl_get_printable (
    QmiMessage *self,
    const gchar *line_prefix);

#endif


#if defined (LIBQMI_GLIB_COMPILATION)

G_GNUC_INTERNAL
gboolean __qmi_message_ctl_get_version_introduced (
    QmiMessage *self,
    guint *major,
    guint *minor);

#endif


/*****************************************************************************/
/* CLIENT: QMI Client CTL */

#define QMI_TYPE_CLIENT_CTL            (qmi_client_ctl_get_type ())
#define QMI_CLIENT_CTL(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), QMI_TYPE_CLIENT_CTL, QmiClientCtl))
#define QMI_CLIENT_CTL_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  QMI_TYPE_CLIENT_CTL, QmiClientCtlClass))
#define QMI_IS_CLIENT_CTL(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), QMI_TYPE_CLIENT_CTL))
#define QMI_IS_CLIENT_CTL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  QMI_TYPE_CLIENT_CTL))
#define QMI_CLIENT_CTL_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  QMI_TYPE_CLIENT_CTL, QmiClientCtlClass))

typedef struct _QmiClientCtl QmiClientCtl;
typedef struct _QmiClientCtlClass QmiClientCtlClass;

/**
 * QmiClientCtl:
 *
 * The #QmiClientCtl structure contains private data and should only be accessed
 * using the provided API.
 */
struct _QmiClientCtl {
    /*< private >*/
    QmiClient parent;
    gpointer priv_unused;
};

struct _QmiClientCtlClass {
    /*< private >*/
    QmiClientClass parent;
};

GType qmi_client_ctl_get_type (void);


void qmi_client_ctl_set_instance_id (
    QmiClientCtl *self,
    QmiMessageCtlSetInstanceIdInput *input,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);
QmiMessageCtlSetInstanceIdOutput *qmi_client_ctl_set_instance_id_finish (
    QmiClientCtl *self,
    GAsyncResult *res,
    GError **error);

void qmi_client_ctl_get_version_info (
    QmiClientCtl *self,
    gpointer unused,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);
QmiMessageCtlGetVersionInfoOutput *qmi_client_ctl_get_version_info_finish (
    QmiClientCtl *self,
    GAsyncResult *res,
    GError **error);

void qmi_client_ctl_allocate_cid (
    QmiClientCtl *self,
    QmiMessageCtlAllocateCidInput *input,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);
QmiMessageCtlAllocateCidOutput *qmi_client_ctl_allocate_cid_finish (
    QmiClientCtl *self,
    GAsyncResult *res,
    GError **error);

void qmi_client_ctl_release_cid (
    QmiClientCtl *self,
    QmiMessageCtlReleaseCidInput *input,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);
QmiMessageCtlReleaseCidOutput *qmi_client_ctl_release_cid_finish (
    QmiClientCtl *self,
    GAsyncResult *res,
    GError **error);

void qmi_client_ctl_set_data_format (
    QmiClientCtl *self,
    QmiMessageCtlSetDataFormatInput *input,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);
QmiMessageCtlSetDataFormatOutput *qmi_client_ctl_set_data_format_finish (
    QmiClientCtl *self,
    GAsyncResult *res,
    GError **error);

void qmi_client_ctl_sync (
    QmiClientCtl *self,
    gpointer unused,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);
QmiMessageCtlSyncOutput *qmi_client_ctl_sync_finish (
    QmiClientCtl *self,
    GAsyncResult *res,
    GError **error);

G_END_DECLS

#endif /* __LIBQMI_GLIB_QMI_CTL__ */
