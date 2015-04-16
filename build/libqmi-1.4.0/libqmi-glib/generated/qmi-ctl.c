
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


#include <string.h>

#include "qmi-ctl.h"
#include "qmi-enum-types.h"
#include "qmi-enum-types-private.h"
#include "qmi-flags64-types.h"
#include "qmi-error-types.h"
#include "qmi-device.h"
#include "qmi-utils.h"

#define QMI_STATUS_SUCCESS 0x0000
#define QMI_STATUS_FAILURE 0x0001


typedef enum {
    QMI_MESSAGE_CTL_SET_INSTANCE_ID = 0x0020,
    QMI_MESSAGE_CTL_GET_VERSION_INFO = 0x0021,
    QMI_MESSAGE_CTL_ALLOCATE_CID = 0x0022,
    QMI_MESSAGE_CTL_RELEASE_CID = 0x0023,
    QMI_MESSAGE_CTL_SET_DATA_FORMAT = 0x0026,
    QMI_MESSAGE_CTL_SYNC = 0x0027,
} QmiMessageCtl;


typedef enum {
    QMI_INDICATION_CTL_SYNC = 0x0027,
} QmiIndicationCtl;


/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message CTL Set Instance ID */


/* --- Input -- */

struct _QmiMessageCtlSetInstanceIdInput {
    volatile gint ref_count;

    /* ID */
    gboolean arg_id_set;
    guint8 arg_id;
};

#define QMI_MESSAGE_CTL_SET_INSTANCE_ID_INPUT_TLV_ID 0x01

/**
 * qmi_message_ctl_set_instance_id_input_get_id:
 * @self: a #QmiMessageCtlSetInstanceIdInput.
 * @id: a placeholder for the output #guint8, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'ID' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_ctl_set_instance_id_input_get_id (
    QmiMessageCtlSetInstanceIdInput *self,
    guint8 *id,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_id_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'ID' was not found in the message");
        return FALSE;
    }

    if (id)
        *id = self->arg_id;

    return TRUE;
}

/**
 * qmi_message_ctl_set_instance_id_input_set_id:
 * @self: a #QmiMessageCtlSetInstanceIdInput.
 * @id: a #guint8.
 * @error: Return location for error or %NULL.
 *
 * Set the 'ID' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_ctl_set_instance_id_input_set_id (
    QmiMessageCtlSetInstanceIdInput *self,
    guint8 id,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_id = id;
    self->arg_id_set = TRUE;

    return TRUE;
}

GType
qmi_message_ctl_set_instance_id_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageCtlSetInstanceIdInput"),
                                          (GBoxedCopyFunc) qmi_message_ctl_set_instance_id_input_ref,
                                          (GBoxedFreeFunc) qmi_message_ctl_set_instance_id_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_ctl_set_instance_id_input_ref:
 * @self: a #QmiMessageCtlSetInstanceIdInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageCtlSetInstanceIdInput *
qmi_message_ctl_set_instance_id_input_ref (QmiMessageCtlSetInstanceIdInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_ctl_set_instance_id_input_unref:
 * @self: a #QmiMessageCtlSetInstanceIdInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_ctl_set_instance_id_input_unref (QmiMessageCtlSetInstanceIdInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageCtlSetInstanceIdInput, self);
    }
}

/**
 * qmi_message_ctl_set_instance_id_input_new:
 *
 * Allocates a new #QmiMessageCtlSetInstanceIdInput.
 *
 * Returns: the newly created #QmiMessageCtlSetInstanceIdInput. The returned value should be freed with qmi_message_ctl_set_instance_id_input_unref().
 */
QmiMessageCtlSetInstanceIdInput *
qmi_message_ctl_set_instance_id_input_new (void)
{
    QmiMessageCtlSetInstanceIdInput *self;

    self = g_slice_new0 (QmiMessageCtlSetInstanceIdInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_ctl_set_instance_id_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessageCtlSetInstanceIdInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_CTL,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_CTL_SET_INSTANCE_ID);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Set Instance ID' has mandatory TLVs");
        qmi_message_unref (self);
        return NULL;
    }

    /* Try to add the 'ID' TLV */
    if (input->arg_id_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        /* Write the guint8 variable to the buffer */
        qmi_utils_write_guint8_to_buffer (
            &buffer_aux,
            &buffer_len,
            &(input->arg_id));

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_CTL_SET_INSTANCE_ID_INPUT_TLV_ID,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the ID TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'ID' in message 'Set Instance ID'");
        qmi_message_unref (self);
        return NULL;
    }

    return self;
}

/* --- Output -- */

/**
 * QmiMessageResult:
 * @error_status: a #guint16.
 * @error_code: a #guint16.
 *
 * A QmiMessageResult struct.
 */
typedef struct _QmiMessageResult {
    guint16 error_status;
    guint16 error_code;
} QmiMessageResult;

struct _QmiMessageCtlSetInstanceIdOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Link ID */
    gboolean arg_link_id_set;
    guint16 arg_link_id;
};

#define QMI_MESSAGE_CTL_SET_INSTANCE_ID_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_CTL_SET_INSTANCE_ID_OUTPUT_TLV_LINK_ID 0x01

/**
 * qmi_message_ctl_set_instance_id_output_get_result:
 * @self: a QmiMessageCtlSetInstanceIdOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_ctl_set_instance_id_output_get_result (
    QmiMessageCtlSetInstanceIdOutput *self,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    /* We should always have a result set in the response message */
    if (!self->arg_result_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_MESSAGE,
                     "No 'Result' field given in the message");
        return FALSE;
    }

    if (self->arg_result.error_status == QMI_STATUS_SUCCESS) {
        /* Operation succeeded */
        return TRUE;
    }

    /* Report a QMI protocol error */
    g_set_error (error,
                 QMI_PROTOCOL_ERROR,
                 (QmiProtocolError) self->arg_result.error_code,
                 "QMI protocol error (%u): '%s'",
                 self->arg_result.error_code,
                 qmi_protocol_error_get_string ((QmiProtocolError) self->arg_result.error_code));
    return FALSE;
}

/**
 * qmi_message_ctl_set_instance_id_output_get_link_id:
 * @self: a #QmiMessageCtlSetInstanceIdOutput.
 * @link_id: a placeholder for the output #guint16, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Link ID' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_ctl_set_instance_id_output_get_link_id (
    QmiMessageCtlSetInstanceIdOutput *self,
    guint16 *link_id,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_link_id_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Link ID' was not found in the message");
        return FALSE;
    }

    if (link_id)
        *link_id = self->arg_link_id;

    return TRUE;
}

GType
qmi_message_ctl_set_instance_id_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageCtlSetInstanceIdOutput"),
                                          (GBoxedCopyFunc) qmi_message_ctl_set_instance_id_output_ref,
                                          (GBoxedFreeFunc) qmi_message_ctl_set_instance_id_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_ctl_set_instance_id_output_ref:
 * @self: a #QmiMessageCtlSetInstanceIdOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageCtlSetInstanceIdOutput *
qmi_message_ctl_set_instance_id_output_ref (QmiMessageCtlSetInstanceIdOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_ctl_set_instance_id_output_unref:
 * @self: a #QmiMessageCtlSetInstanceIdOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_ctl_set_instance_id_output_unref (QmiMessageCtlSetInstanceIdOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageCtlSetInstanceIdOutput, self);
    }
}

static gboolean
qmi_message_ctl_set_instance_id_input_id_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'ID' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'ID' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_ctl_set_instance_id_input_id_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_CTL_SET_INSTANCE_ID_INPUT_TLV_ID,
                                      &buffer_len);
    if (buffer && qmi_message_ctl_set_instance_id_input_id_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

            g_string_append_printf (printable, "%u", (guint)tmp);
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'ID' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_result_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    static const guint expected_len = 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Result' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    return TRUE;
}

static gchar *
qmi_message_result_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (self,
                                      QMI_MESSAGE_CTL_SET_INSTANCE_ID_OUTPUT_TLV_RESULT,
                                      &buffer_len);
    if (buffer) {
        GString *printable;
        guint16 error_status;
        guint16 error_code;

        printable = g_string_new ("");
        qmi_utils_read_guint16_from_buffer (
            &buffer,
            &buffer_len,
            QMI_ENDIAN_LITTLE,
            &error_status);
        qmi_utils_read_guint16_from_buffer (
            &buffer,
            &buffer_len,
            QMI_ENDIAN_LITTLE,
            &error_code);

        g_warn_if_fail (buffer_len == 0);

        if (error_status == QMI_STATUS_SUCCESS)
            g_string_append (printable, "SUCCESS");
        else
            g_string_append_printf (printable,
                                    "FAILURE: %s",
                                    qmi_protocol_error_get_string ((QmiProtocolError) error_code));

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_ctl_set_instance_id_output_link_id_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 2;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Link ID' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Link ID' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_ctl_set_instance_id_output_link_id_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_CTL_SET_INSTANCE_ID_OUTPUT_TLV_LINK_ID,
                                      &buffer_len);
    if (buffer && qmi_message_ctl_set_instance_id_output_link_id_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint16 tmp;

            /* Read the guint16 variable from the buffer */
            qmi_utils_read_guint16_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &tmp);

            g_string_append_printf (printable, "%" G_GUINT16_FORMAT "", tmp);
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Link ID' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_set_instance_id_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_set_instance_id_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_set_instance_id_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_CTL_SET_INSTANCE_ID_INPUT_TLV_ID:
            tlv_type_str = "ID";
            translated_value = qmi_message_ctl_set_instance_id_input_id_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_CTL_SET_INSTANCE_ID_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_CTL_SET_INSTANCE_ID_OUTPUT_TLV_LINK_ID:
            tlv_type_str = "Link ID";
            translated_value = qmi_message_ctl_set_instance_id_output_link_id_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    }

    if (!tlv_type_str) {
        gchar *value_str = NULL;

        value_str = qmi_message_get_tlv_printable (ctx->self,
                                                   ctx->line_prefix,
                                                   type,
                                                   value,
                                                   length);
        g_string_append (ctx->printable, value_str);
        g_free (value_str);
    } else {
        gchar *value_hex;

        value_hex = __qmi_utils_str_hex (value, length, ':');
        g_string_append_printf (ctx->printable,
                                "%sTLV:\n"
                                "%s  type       = \"%s\" (0x%02x)\n"
                                "%s  length     = %" G_GSIZE_FORMAT "\n"
                                "%s  value      = %s\n"
                                "%s  translated = %s\n",
                                ctx->line_prefix,
                                ctx->line_prefix, tlv_type_str, type,
                                ctx->line_prefix, length,
                                ctx->line_prefix, value_hex,
                                ctx->line_prefix, translated_value ? translated_value : "");
        g_free (value_hex);
        g_free (translated_value);
    }
}

static gchar *
message_set_instance_id_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Set Instance ID\" (0x0020)\n",
                            line_prefix);

    {
        struct message_set_instance_id_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_set_instance_id_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageCtlSetInstanceIdOutput *
__qmi_message_ctl_set_instance_id_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageCtlSetInstanceIdOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_CTL_SET_INSTANCE_ID, NULL);

    self = g_slice_new0 (QmiMessageCtlSetInstanceIdOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_CTL_SET_INSTANCE_ID_OUTPUT_TLV_RESULT,
                                              &buffer_len);
            if (buffer && qmi_message_result_validate (buffer, buffer_len)) {
                self->arg_result_set = TRUE;

                /* Read the guint16 variable from the buffer */
                qmi_utils_read_guint16_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_result.error_status));
                /* Read the guint16 variable from the buffer */
                qmi_utils_read_guint16_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_result.error_code));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Result' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the Result TLV: Not found");
                qmi_message_ctl_set_instance_id_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    do {
        /* Prerequisite.... */
        if (!(self->arg_result.error_status == QMI_STATUS_SUCCESS))
            break;

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_CTL_SET_INSTANCE_ID_OUTPUT_TLV_LINK_ID,
                                              &buffer_len);
            if (buffer && qmi_message_ctl_set_instance_id_output_link_id_validate (buffer, buffer_len)) {
                self->arg_link_id_set = TRUE;

                /* Read the guint16 variable from the buffer */
                qmi_utils_read_guint16_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_link_id));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Link ID' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the Link ID TLV: Not found");
                qmi_message_ctl_set_instance_id_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message CTL Get Version Info */


/* --- Input -- */

/* Note: no fields in the Input container */

static QmiMessage *
__qmi_message_ctl_get_version_info_request_create (
    guint8 transaction_id,
    guint8 cid,
    gpointer unused,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_CTL,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_CTL_GET_VERSION_INFO);

    return self;
}

/* --- Output -- */

struct _QmiMessageCtlGetVersionInfoOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Service list */
    gboolean arg_service_list_set;
    GArray *arg_service_list;
};

#define QMI_MESSAGE_CTL_GET_VERSION_INFO_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_CTL_GET_VERSION_INFO_OUTPUT_TLV_SERVICE_LIST 0x01

/**
 * qmi_message_ctl_get_version_info_output_get_result:
 * @self: a QmiMessageCtlGetVersionInfoOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_ctl_get_version_info_output_get_result (
    QmiMessageCtlGetVersionInfoOutput *self,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    /* We should always have a result set in the response message */
    if (!self->arg_result_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_MESSAGE,
                     "No 'Result' field given in the message");
        return FALSE;
    }

    if (self->arg_result.error_status == QMI_STATUS_SUCCESS) {
        /* Operation succeeded */
        return TRUE;
    }

    /* Report a QMI protocol error */
    g_set_error (error,
                 QMI_PROTOCOL_ERROR,
                 (QmiProtocolError) self->arg_result.error_code,
                 "QMI protocol error (%u): '%s'",
                 self->arg_result.error_code,
                 qmi_protocol_error_get_string ((QmiProtocolError) self->arg_result.error_code));
    return FALSE;
}

/**
 * qmi_message_ctl_get_version_info_output_get_service_list:
 * @self: a #QmiMessageCtlGetVersionInfoOutput.
 * @service_list: a placeholder for the output #GArray of #QmiMessageCtlGetVersionInfoOutputServiceListService elements, or %NULL if not required. Do not free it, it is owned by @self.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Service list' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_ctl_get_version_info_output_get_service_list (
    QmiMessageCtlGetVersionInfoOutput *self,
    GArray **service_list,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_service_list_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Service list' was not found in the message");
        return FALSE;
    }

    if (service_list)
        *service_list = self->arg_service_list;

    return TRUE;
}

GType
qmi_message_ctl_get_version_info_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageCtlGetVersionInfoOutput"),
                                          (GBoxedCopyFunc) qmi_message_ctl_get_version_info_output_ref,
                                          (GBoxedFreeFunc) qmi_message_ctl_get_version_info_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_ctl_get_version_info_output_ref:
 * @self: a #QmiMessageCtlGetVersionInfoOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageCtlGetVersionInfoOutput *
qmi_message_ctl_get_version_info_output_ref (QmiMessageCtlGetVersionInfoOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_ctl_get_version_info_output_unref:
 * @self: a #QmiMessageCtlGetVersionInfoOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_ctl_get_version_info_output_unref (QmiMessageCtlGetVersionInfoOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        if (self->arg_service_list)
            g_array_unref (self->arg_service_list);
        g_slice_free (QmiMessageCtlGetVersionInfoOutput, self);
    }
}

static gboolean
qmi_message_ctl_get_version_info_output_service_list_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    {
        guint service_list_i;
        guint8 service_list_n_items;
        const guint8 *service_list_aux_buffer = &buffer[expected_len];
        guint16 service_list_aux_buffer_len = buffer_len - expected_len;

        expected_len += 1;

        /* Read the guint8 variable from the buffer */
        qmi_utils_read_guint8_from_buffer (
            &service_list_aux_buffer,
            &service_list_aux_buffer_len,
            &(service_list_n_items));
        for (service_list_i = 0; service_list_i < service_list_n_items; service_list_i++) {

            expected_len += 1;
            expected_len += 2;
            expected_len += 2;
        }
    }

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Service list' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Service list' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_ctl_get_version_info_output_service_list_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_CTL_GET_VERSION_INFO_OUTPUT_TLV_SERVICE_LIST,
                                      &buffer_len);
    if (buffer && qmi_message_ctl_get_version_info_output_service_list_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        {
            guint service_list_i;
            guint8 service_list_n_items;

            /* Read number of items in the array */
            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &(service_list_n_items));

            g_string_append (printable, "{");

            for (service_list_i = 0; service_list_i < service_list_n_items; service_list_i++) {
                g_string_append_printf (printable, " [%u] = '", service_list_i);
                g_string_append (printable, "[");
                g_string_append (printable, " service = '");

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);

#if defined  __QMI_SERVICE_IS_ENUM__
                    g_string_append_printf (printable, "%s", qmi_service_get_string ((QmiService)tmp));
#elif defined  __QMI_SERVICE_IS_FLAGS__
                    {
                        gchar *flags_str;

                        flags_str = qmi_service_build_string_from_mask ((QmiService)tmp);
                        g_string_append_printf (printable, "%s", flags_str);
                        g_free (flags_str);
                    }
#else
# error unexpected public format: QmiService
#endif
                }
                g_string_append (printable, "'");
                g_string_append (printable, " major_version = '");

                {
                    guint16 tmp;

                    /* Read the guint16 variable from the buffer */
                    qmi_utils_read_guint16_from_buffer (
                        &buffer,
                        &buffer_len,
                        QMI_ENDIAN_LITTLE,
                        &tmp);

                    g_string_append_printf (printable, "%" G_GUINT16_FORMAT "", tmp);
                }
                g_string_append (printable, "'");
                g_string_append (printable, " minor_version = '");

                {
                    guint16 tmp;

                    /* Read the guint16 variable from the buffer */
                    qmi_utils_read_guint16_from_buffer (
                        &buffer,
                        &buffer_len,
                        QMI_ENDIAN_LITTLE,
                        &tmp);

                    g_string_append_printf (printable, "%" G_GUINT16_FORMAT "", tmp);
                }
                g_string_append (printable, "'");
                g_string_append (printable, " ]");
                g_string_append (printable, " '");
            }

            g_string_append (printable, "}");
        }
        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Service list' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_get_version_info_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_get_version_info_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_get_version_info_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_CTL_GET_VERSION_INFO_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_CTL_GET_VERSION_INFO_OUTPUT_TLV_SERVICE_LIST:
            tlv_type_str = "Service list";
            translated_value = qmi_message_ctl_get_version_info_output_service_list_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    }

    if (!tlv_type_str) {
        gchar *value_str = NULL;

        value_str = qmi_message_get_tlv_printable (ctx->self,
                                                   ctx->line_prefix,
                                                   type,
                                                   value,
                                                   length);
        g_string_append (ctx->printable, value_str);
        g_free (value_str);
    } else {
        gchar *value_hex;

        value_hex = __qmi_utils_str_hex (value, length, ':');
        g_string_append_printf (ctx->printable,
                                "%sTLV:\n"
                                "%s  type       = \"%s\" (0x%02x)\n"
                                "%s  length     = %" G_GSIZE_FORMAT "\n"
                                "%s  value      = %s\n"
                                "%s  translated = %s\n",
                                ctx->line_prefix,
                                ctx->line_prefix, tlv_type_str, type,
                                ctx->line_prefix, length,
                                ctx->line_prefix, value_hex,
                                ctx->line_prefix, translated_value ? translated_value : "");
        g_free (value_hex);
        g_free (translated_value);
    }
}

static gchar *
message_get_version_info_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Get Version Info\" (0x0021)\n",
                            line_prefix);

    {
        struct message_get_version_info_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_get_version_info_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageCtlGetVersionInfoOutput *
__qmi_message_ctl_get_version_info_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageCtlGetVersionInfoOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_CTL_GET_VERSION_INFO, NULL);

    self = g_slice_new0 (QmiMessageCtlGetVersionInfoOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_CTL_GET_VERSION_INFO_OUTPUT_TLV_RESULT,
                                              &buffer_len);
            if (buffer && qmi_message_result_validate (buffer, buffer_len)) {
                self->arg_result_set = TRUE;

                /* Read the guint16 variable from the buffer */
                qmi_utils_read_guint16_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_result.error_status));
                /* Read the guint16 variable from the buffer */
                qmi_utils_read_guint16_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_result.error_code));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Result' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the Result TLV: Not found");
                qmi_message_ctl_get_version_info_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    do {
        /* Prerequisite.... */
        if (!(self->arg_result.error_status == QMI_STATUS_SUCCESS))
            break;

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_CTL_GET_VERSION_INFO_OUTPUT_TLV_SERVICE_LIST,
                                              &buffer_len);
            if (buffer && qmi_message_ctl_get_version_info_output_service_list_validate (buffer, buffer_len)) {
                self->arg_service_list_set = TRUE;

                {
                    guint service_list_i;
                    guint8 service_list_n_items;

                    /* Read number of items in the array */
                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &(service_list_n_items));

                    self->arg_service_list = g_array_sized_new (
                        FALSE,
                        FALSE,
                        sizeof (QmiMessageCtlGetVersionInfoOutputServiceListService),
                        (guint)service_list_n_items);

                    for (service_list_i = 0; service_list_i < service_list_n_items; service_list_i++) {
                        QmiMessageCtlGetVersionInfoOutputServiceListService service_list_aux;

                        {
                            guint8 tmp;

                            /* Read the guint8 variable from the buffer */
                            qmi_utils_read_guint8_from_buffer (
                                &buffer,
                                &buffer_len,
                                &tmp);
                            service_list_aux.service = (QmiService)tmp;
                        }
                        /* Read the guint16 variable from the buffer */
                        qmi_utils_read_guint16_from_buffer (
                            &buffer,
                            &buffer_len,
                            QMI_ENDIAN_LITTLE,
                            &(service_list_aux.major_version));
                        /* Read the guint16 variable from the buffer */
                        qmi_utils_read_guint16_from_buffer (
                            &buffer,
                            &buffer_len,
                            QMI_ENDIAN_LITTLE,
                            &(service_list_aux.minor_version));
                        g_array_insert_val (self->arg_service_list, service_list_i, service_list_aux);
                    }
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Service list' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the Service list TLV: Not found");
                qmi_message_ctl_get_version_info_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message CTL Allocate CID */


/* --- Input -- */

struct _QmiMessageCtlAllocateCidInput {
    volatile gint ref_count;

    /* Service */
    gboolean arg_service_set;
    guint8 arg_service;
};

#define QMI_MESSAGE_CTL_ALLOCATE_CID_INPUT_TLV_SERVICE 0x01

/**
 * qmi_message_ctl_allocate_cid_input_get_service:
 * @self: a #QmiMessageCtlAllocateCidInput.
 * @service: a placeholder for the output #QmiService, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Service' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_ctl_allocate_cid_input_get_service (
    QmiMessageCtlAllocateCidInput *self,
    QmiService *service,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_service_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Service' was not found in the message");
        return FALSE;
    }

    if (service)
        *service = (QmiService)(self->arg_service);

    return TRUE;
}

/**
 * qmi_message_ctl_allocate_cid_input_set_service:
 * @self: a #QmiMessageCtlAllocateCidInput.
 * @service: a #QmiService.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Service' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_ctl_allocate_cid_input_set_service (
    QmiMessageCtlAllocateCidInput *self,
    QmiService service,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_service = (guint8)(service);
    self->arg_service_set = TRUE;

    return TRUE;
}

GType
qmi_message_ctl_allocate_cid_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageCtlAllocateCidInput"),
                                          (GBoxedCopyFunc) qmi_message_ctl_allocate_cid_input_ref,
                                          (GBoxedFreeFunc) qmi_message_ctl_allocate_cid_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_ctl_allocate_cid_input_ref:
 * @self: a #QmiMessageCtlAllocateCidInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageCtlAllocateCidInput *
qmi_message_ctl_allocate_cid_input_ref (QmiMessageCtlAllocateCidInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_ctl_allocate_cid_input_unref:
 * @self: a #QmiMessageCtlAllocateCidInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_ctl_allocate_cid_input_unref (QmiMessageCtlAllocateCidInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageCtlAllocateCidInput, self);
    }
}

/**
 * qmi_message_ctl_allocate_cid_input_new:
 *
 * Allocates a new #QmiMessageCtlAllocateCidInput.
 *
 * Returns: the newly created #QmiMessageCtlAllocateCidInput. The returned value should be freed with qmi_message_ctl_allocate_cid_input_unref().
 */
QmiMessageCtlAllocateCidInput *
qmi_message_ctl_allocate_cid_input_new (void)
{
    QmiMessageCtlAllocateCidInput *self;

    self = g_slice_new0 (QmiMessageCtlAllocateCidInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_ctl_allocate_cid_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessageCtlAllocateCidInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_CTL,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_CTL_ALLOCATE_CID);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Allocate CID' has mandatory TLVs");
        qmi_message_unref (self);
        return NULL;
    }

    /* Try to add the 'Service' TLV */
    if (input->arg_service_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_service;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_CTL_ALLOCATE_CID_INPUT_TLV_SERVICE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Service TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'Service' in message 'Allocate CID'");
        qmi_message_unref (self);
        return NULL;
    }

    return self;
}

/* --- Output -- */

struct _QmiMessageCtlAllocateCidOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Allocation Info */
    gboolean arg_allocation_info_set;
    guint8 arg_allocation_info_service;
    guint8 arg_allocation_info_cid;
};

#define QMI_MESSAGE_CTL_ALLOCATE_CID_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_CTL_ALLOCATE_CID_OUTPUT_TLV_ALLOCATION_INFO 0x01

/**
 * qmi_message_ctl_allocate_cid_output_get_result:
 * @self: a QmiMessageCtlAllocateCidOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_ctl_allocate_cid_output_get_result (
    QmiMessageCtlAllocateCidOutput *self,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    /* We should always have a result set in the response message */
    if (!self->arg_result_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_MESSAGE,
                     "No 'Result' field given in the message");
        return FALSE;
    }

    if (self->arg_result.error_status == QMI_STATUS_SUCCESS) {
        /* Operation succeeded */
        return TRUE;
    }

    /* Report a QMI protocol error */
    g_set_error (error,
                 QMI_PROTOCOL_ERROR,
                 (QmiProtocolError) self->arg_result.error_code,
                 "QMI protocol error (%u): '%s'",
                 self->arg_result.error_code,
                 qmi_protocol_error_get_string ((QmiProtocolError) self->arg_result.error_code));
    return FALSE;
}

/**
 * qmi_message_ctl_allocate_cid_output_get_allocation_info:
 * @self: a #QmiMessageCtlAllocateCidOutput.
 * @allocation_info_service: a placeholder for the output #QmiService, or %NULL if not required.
 * @allocation_info_cid: a placeholder for the output #guint8, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Allocation Info' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_ctl_allocate_cid_output_get_allocation_info (
    QmiMessageCtlAllocateCidOutput *self,
    QmiService *allocation_info_service,
    guint8 *allocation_info_cid,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_allocation_info_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Allocation Info' was not found in the message");
        return FALSE;
    }

    if (allocation_info_service)
        *allocation_info_service = (QmiService)(self->arg_allocation_info_service);
    if (allocation_info_cid)
        *allocation_info_cid = self->arg_allocation_info_cid;

    return TRUE;
}

GType
qmi_message_ctl_allocate_cid_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageCtlAllocateCidOutput"),
                                          (GBoxedCopyFunc) qmi_message_ctl_allocate_cid_output_ref,
                                          (GBoxedFreeFunc) qmi_message_ctl_allocate_cid_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_ctl_allocate_cid_output_ref:
 * @self: a #QmiMessageCtlAllocateCidOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageCtlAllocateCidOutput *
qmi_message_ctl_allocate_cid_output_ref (QmiMessageCtlAllocateCidOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_ctl_allocate_cid_output_unref:
 * @self: a #QmiMessageCtlAllocateCidOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_ctl_allocate_cid_output_unref (QmiMessageCtlAllocateCidOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageCtlAllocateCidOutput, self);
    }
}

static gboolean
qmi_message_ctl_allocate_cid_input_service_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Service' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Service' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_ctl_allocate_cid_input_service_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_CTL_ALLOCATE_CID_INPUT_TLV_SERVICE,
                                      &buffer_len);
    if (buffer && qmi_message_ctl_allocate_cid_input_service_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_SERVICE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_service_get_string ((QmiService)tmp));
#elif defined  __QMI_SERVICE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_service_build_string_from_mask ((QmiService)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiService
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Service' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_ctl_allocate_cid_output_allocation_info_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;
    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Allocation Info' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Allocation Info' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_ctl_allocate_cid_output_allocation_info_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_CTL_ALLOCATE_CID_OUTPUT_TLV_ALLOCATION_INFO,
                                      &buffer_len);
    if (buffer && qmi_message_ctl_allocate_cid_output_allocation_info_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " service = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_SERVICE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_service_get_string ((QmiService)tmp));
#elif defined  __QMI_SERVICE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_service_build_string_from_mask ((QmiService)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiService
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " cid = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

            g_string_append_printf (printable, "%u", (guint)tmp);
        }
        g_string_append (printable, "'");
        g_string_append (printable, " ]");

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Allocation Info' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_allocate_cid_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_allocate_cid_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_allocate_cid_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_CTL_ALLOCATE_CID_INPUT_TLV_SERVICE:
            tlv_type_str = "Service";
            translated_value = qmi_message_ctl_allocate_cid_input_service_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_CTL_ALLOCATE_CID_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_CTL_ALLOCATE_CID_OUTPUT_TLV_ALLOCATION_INFO:
            tlv_type_str = "Allocation Info";
            translated_value = qmi_message_ctl_allocate_cid_output_allocation_info_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    }

    if (!tlv_type_str) {
        gchar *value_str = NULL;

        value_str = qmi_message_get_tlv_printable (ctx->self,
                                                   ctx->line_prefix,
                                                   type,
                                                   value,
                                                   length);
        g_string_append (ctx->printable, value_str);
        g_free (value_str);
    } else {
        gchar *value_hex;

        value_hex = __qmi_utils_str_hex (value, length, ':');
        g_string_append_printf (ctx->printable,
                                "%sTLV:\n"
                                "%s  type       = \"%s\" (0x%02x)\n"
                                "%s  length     = %" G_GSIZE_FORMAT "\n"
                                "%s  value      = %s\n"
                                "%s  translated = %s\n",
                                ctx->line_prefix,
                                ctx->line_prefix, tlv_type_str, type,
                                ctx->line_prefix, length,
                                ctx->line_prefix, value_hex,
                                ctx->line_prefix, translated_value ? translated_value : "");
        g_free (value_hex);
        g_free (translated_value);
    }
}

static gchar *
message_allocate_cid_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Allocate CID\" (0x0022)\n",
                            line_prefix);

    {
        struct message_allocate_cid_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_allocate_cid_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageCtlAllocateCidOutput *
__qmi_message_ctl_allocate_cid_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageCtlAllocateCidOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_CTL_ALLOCATE_CID, NULL);

    self = g_slice_new0 (QmiMessageCtlAllocateCidOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_CTL_ALLOCATE_CID_OUTPUT_TLV_RESULT,
                                              &buffer_len);
            if (buffer && qmi_message_result_validate (buffer, buffer_len)) {
                self->arg_result_set = TRUE;

                /* Read the guint16 variable from the buffer */
                qmi_utils_read_guint16_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_result.error_status));
                /* Read the guint16 variable from the buffer */
                qmi_utils_read_guint16_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_result.error_code));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Result' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the Result TLV: Not found");
                qmi_message_ctl_allocate_cid_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    do {
        /* Prerequisite.... */
        if (!(self->arg_result.error_status == QMI_STATUS_SUCCESS))
            break;

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_CTL_ALLOCATE_CID_OUTPUT_TLV_ALLOCATION_INFO,
                                              &buffer_len);
            if (buffer && qmi_message_ctl_allocate_cid_output_allocation_info_validate (buffer, buffer_len)) {
                self->arg_allocation_info_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_allocation_info_service = (QmiService)tmp;
                }
                /* Read the guint8 variable from the buffer */
                qmi_utils_read_guint8_from_buffer (
                    &buffer,
                    &buffer_len,
                    &(self->arg_allocation_info_cid));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Allocation Info' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the Allocation Info TLV: Not found");
                qmi_message_ctl_allocate_cid_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message CTL Release CID */


/* --- Input -- */

struct _QmiMessageCtlReleaseCidInput {
    volatile gint ref_count;

    /* Release Info */
    gboolean arg_release_info_set;
    guint8 arg_release_info_service;
    guint8 arg_release_info_cid;
};

#define QMI_MESSAGE_CTL_RELEASE_CID_INPUT_TLV_RELEASE_INFO 0x01

/**
 * qmi_message_ctl_release_cid_input_get_release_info:
 * @self: a #QmiMessageCtlReleaseCidInput.
 * @release_info_service: a placeholder for the output #QmiService, or %NULL if not required.
 * @release_info_cid: a placeholder for the output #guint8, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Release Info' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_ctl_release_cid_input_get_release_info (
    QmiMessageCtlReleaseCidInput *self,
    QmiService *release_info_service,
    guint8 *release_info_cid,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_release_info_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Release Info' was not found in the message");
        return FALSE;
    }

    if (release_info_service)
        *release_info_service = (QmiService)(self->arg_release_info_service);
    if (release_info_cid)
        *release_info_cid = self->arg_release_info_cid;

    return TRUE;
}

/**
 * qmi_message_ctl_release_cid_input_set_release_info:
 * @self: a #QmiMessageCtlReleaseCidInput.
 * @release_info_service: a #QmiService.
 * @release_info_cid: a #guint8.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Release Info' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_ctl_release_cid_input_set_release_info (
    QmiMessageCtlReleaseCidInput *self,
    QmiService release_info_service,
    guint8 release_info_cid,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_release_info_service = (guint8)(release_info_service);
    self->arg_release_info_cid = release_info_cid;
    self->arg_release_info_set = TRUE;

    return TRUE;
}

GType
qmi_message_ctl_release_cid_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageCtlReleaseCidInput"),
                                          (GBoxedCopyFunc) qmi_message_ctl_release_cid_input_ref,
                                          (GBoxedFreeFunc) qmi_message_ctl_release_cid_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_ctl_release_cid_input_ref:
 * @self: a #QmiMessageCtlReleaseCidInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageCtlReleaseCidInput *
qmi_message_ctl_release_cid_input_ref (QmiMessageCtlReleaseCidInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_ctl_release_cid_input_unref:
 * @self: a #QmiMessageCtlReleaseCidInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_ctl_release_cid_input_unref (QmiMessageCtlReleaseCidInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageCtlReleaseCidInput, self);
    }
}

/**
 * qmi_message_ctl_release_cid_input_new:
 *
 * Allocates a new #QmiMessageCtlReleaseCidInput.
 *
 * Returns: the newly created #QmiMessageCtlReleaseCidInput. The returned value should be freed with qmi_message_ctl_release_cid_input_unref().
 */
QmiMessageCtlReleaseCidInput *
qmi_message_ctl_release_cid_input_new (void)
{
    QmiMessageCtlReleaseCidInput *self;

    self = g_slice_new0 (QmiMessageCtlReleaseCidInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_ctl_release_cid_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessageCtlReleaseCidInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_CTL,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_CTL_RELEASE_CID);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Release CID' has mandatory TLVs");
        qmi_message_unref (self);
        return NULL;
    }

    /* Try to add the 'Release Info' TLV */
    if (input->arg_release_info_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_release_info_service;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }
        /* Write the guint8 variable to the buffer */
        qmi_utils_write_guint8_to_buffer (
            &buffer_aux,
            &buffer_len,
            &(input->arg_release_info_cid));

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_CTL_RELEASE_CID_INPUT_TLV_RELEASE_INFO,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Release Info TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'Release Info' in message 'Release CID'");
        qmi_message_unref (self);
        return NULL;
    }

    return self;
}

/* --- Output -- */

struct _QmiMessageCtlReleaseCidOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Release Info */
    gboolean arg_release_info_set;
    guint8 arg_release_info_service;
    guint8 arg_release_info_cid;
};

#define QMI_MESSAGE_CTL_RELEASE_CID_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_CTL_RELEASE_CID_OUTPUT_TLV_RELEASE_INFO 0x01

/**
 * qmi_message_ctl_release_cid_output_get_result:
 * @self: a QmiMessageCtlReleaseCidOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_ctl_release_cid_output_get_result (
    QmiMessageCtlReleaseCidOutput *self,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    /* We should always have a result set in the response message */
    if (!self->arg_result_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_MESSAGE,
                     "No 'Result' field given in the message");
        return FALSE;
    }

    if (self->arg_result.error_status == QMI_STATUS_SUCCESS) {
        /* Operation succeeded */
        return TRUE;
    }

    /* Report a QMI protocol error */
    g_set_error (error,
                 QMI_PROTOCOL_ERROR,
                 (QmiProtocolError) self->arg_result.error_code,
                 "QMI protocol error (%u): '%s'",
                 self->arg_result.error_code,
                 qmi_protocol_error_get_string ((QmiProtocolError) self->arg_result.error_code));
    return FALSE;
}

/**
 * qmi_message_ctl_release_cid_output_get_release_info:
 * @self: a #QmiMessageCtlReleaseCidOutput.
 * @release_info_service: a placeholder for the output #QmiService, or %NULL if not required.
 * @release_info_cid: a placeholder for the output #guint8, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Release Info' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_ctl_release_cid_output_get_release_info (
    QmiMessageCtlReleaseCidOutput *self,
    QmiService *release_info_service,
    guint8 *release_info_cid,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_release_info_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Release Info' was not found in the message");
        return FALSE;
    }

    if (release_info_service)
        *release_info_service = (QmiService)(self->arg_release_info_service);
    if (release_info_cid)
        *release_info_cid = self->arg_release_info_cid;

    return TRUE;
}

GType
qmi_message_ctl_release_cid_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageCtlReleaseCidOutput"),
                                          (GBoxedCopyFunc) qmi_message_ctl_release_cid_output_ref,
                                          (GBoxedFreeFunc) qmi_message_ctl_release_cid_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_ctl_release_cid_output_ref:
 * @self: a #QmiMessageCtlReleaseCidOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageCtlReleaseCidOutput *
qmi_message_ctl_release_cid_output_ref (QmiMessageCtlReleaseCidOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_ctl_release_cid_output_unref:
 * @self: a #QmiMessageCtlReleaseCidOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_ctl_release_cid_output_unref (QmiMessageCtlReleaseCidOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageCtlReleaseCidOutput, self);
    }
}

static gboolean
qmi_message_ctl_release_cid_input_release_info_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;
    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Release Info' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Release Info' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_ctl_release_cid_input_release_info_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_CTL_RELEASE_CID_INPUT_TLV_RELEASE_INFO,
                                      &buffer_len);
    if (buffer && qmi_message_ctl_release_cid_input_release_info_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " service = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_SERVICE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_service_get_string ((QmiService)tmp));
#elif defined  __QMI_SERVICE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_service_build_string_from_mask ((QmiService)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiService
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " cid = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

            g_string_append_printf (printable, "%u", (guint)tmp);
        }
        g_string_append (printable, "'");
        g_string_append (printable, " ]");

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Release Info' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_ctl_release_cid_output_release_info_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;
    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Release Info' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Release Info' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_ctl_release_cid_output_release_info_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_CTL_RELEASE_CID_OUTPUT_TLV_RELEASE_INFO,
                                      &buffer_len);
    if (buffer && qmi_message_ctl_release_cid_output_release_info_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " service = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_SERVICE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_service_get_string ((QmiService)tmp));
#elif defined  __QMI_SERVICE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_service_build_string_from_mask ((QmiService)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiService
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " cid = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

            g_string_append_printf (printable, "%u", (guint)tmp);
        }
        g_string_append (printable, "'");
        g_string_append (printable, " ]");

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Release Info' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_release_cid_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_release_cid_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_release_cid_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_CTL_RELEASE_CID_INPUT_TLV_RELEASE_INFO:
            tlv_type_str = "Release Info";
            translated_value = qmi_message_ctl_release_cid_input_release_info_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_CTL_RELEASE_CID_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_CTL_RELEASE_CID_OUTPUT_TLV_RELEASE_INFO:
            tlv_type_str = "Release Info";
            translated_value = qmi_message_ctl_release_cid_output_release_info_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    }

    if (!tlv_type_str) {
        gchar *value_str = NULL;

        value_str = qmi_message_get_tlv_printable (ctx->self,
                                                   ctx->line_prefix,
                                                   type,
                                                   value,
                                                   length);
        g_string_append (ctx->printable, value_str);
        g_free (value_str);
    } else {
        gchar *value_hex;

        value_hex = __qmi_utils_str_hex (value, length, ':');
        g_string_append_printf (ctx->printable,
                                "%sTLV:\n"
                                "%s  type       = \"%s\" (0x%02x)\n"
                                "%s  length     = %" G_GSIZE_FORMAT "\n"
                                "%s  value      = %s\n"
                                "%s  translated = %s\n",
                                ctx->line_prefix,
                                ctx->line_prefix, tlv_type_str, type,
                                ctx->line_prefix, length,
                                ctx->line_prefix, value_hex,
                                ctx->line_prefix, translated_value ? translated_value : "");
        g_free (value_hex);
        g_free (translated_value);
    }
}

static gchar *
message_release_cid_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Release CID\" (0x0023)\n",
                            line_prefix);

    {
        struct message_release_cid_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_release_cid_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageCtlReleaseCidOutput *
__qmi_message_ctl_release_cid_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageCtlReleaseCidOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_CTL_RELEASE_CID, NULL);

    self = g_slice_new0 (QmiMessageCtlReleaseCidOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_CTL_RELEASE_CID_OUTPUT_TLV_RESULT,
                                              &buffer_len);
            if (buffer && qmi_message_result_validate (buffer, buffer_len)) {
                self->arg_result_set = TRUE;

                /* Read the guint16 variable from the buffer */
                qmi_utils_read_guint16_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_result.error_status));
                /* Read the guint16 variable from the buffer */
                qmi_utils_read_guint16_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_result.error_code));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Result' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the Result TLV: Not found");
                qmi_message_ctl_release_cid_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    do {
        /* Prerequisite.... */
        if (!(self->arg_result.error_status == QMI_STATUS_SUCCESS))
            break;

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_CTL_RELEASE_CID_OUTPUT_TLV_RELEASE_INFO,
                                              &buffer_len);
            if (buffer && qmi_message_ctl_release_cid_output_release_info_validate (buffer, buffer_len)) {
                self->arg_release_info_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_release_info_service = (QmiService)tmp;
                }
                /* Read the guint8 variable from the buffer */
                qmi_utils_read_guint8_from_buffer (
                    &buffer,
                    &buffer_len,
                    &(self->arg_release_info_cid));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Release Info' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the Release Info TLV: Not found");
                qmi_message_ctl_release_cid_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message CTL Set Data Format */


/* --- Input -- */

struct _QmiMessageCtlSetDataFormatInput {
    volatile gint ref_count;

    /* Protocol */
    gboolean arg_protocol_set;
    guint16 arg_protocol;

    /* Format */
    gboolean arg_format_set;
    guint8 arg_format;
};

#define QMI_MESSAGE_CTL_SET_DATA_FORMAT_INPUT_TLV_PROTOCOL 0x10
#define QMI_MESSAGE_CTL_SET_DATA_FORMAT_INPUT_TLV_FORMAT 0x01

/**
 * qmi_message_ctl_set_data_format_input_get_protocol:
 * @self: a #QmiMessageCtlSetDataFormatInput.
 * @protocol: a placeholder for the output #QmiCtlDataLinkProtocol, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Protocol' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_ctl_set_data_format_input_get_protocol (
    QmiMessageCtlSetDataFormatInput *self,
    QmiCtlDataLinkProtocol *protocol,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_protocol_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Protocol' was not found in the message");
        return FALSE;
    }

    if (protocol)
        *protocol = (QmiCtlDataLinkProtocol)(self->arg_protocol);

    return TRUE;
}

/**
 * qmi_message_ctl_set_data_format_input_set_protocol:
 * @self: a #QmiMessageCtlSetDataFormatInput.
 * @protocol: a #QmiCtlDataLinkProtocol.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Protocol' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_ctl_set_data_format_input_set_protocol (
    QmiMessageCtlSetDataFormatInput *self,
    QmiCtlDataLinkProtocol protocol,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_protocol = (guint16)(protocol);
    self->arg_protocol_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_ctl_set_data_format_input_get_format:
 * @self: a #QmiMessageCtlSetDataFormatInput.
 * @format: a placeholder for the output #QmiCtlDataFormat, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Format' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_ctl_set_data_format_input_get_format (
    QmiMessageCtlSetDataFormatInput *self,
    QmiCtlDataFormat *format,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_format_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Format' was not found in the message");
        return FALSE;
    }

    if (format)
        *format = (QmiCtlDataFormat)(self->arg_format);

    return TRUE;
}

/**
 * qmi_message_ctl_set_data_format_input_set_format:
 * @self: a #QmiMessageCtlSetDataFormatInput.
 * @format: a #QmiCtlDataFormat.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Format' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_ctl_set_data_format_input_set_format (
    QmiMessageCtlSetDataFormatInput *self,
    QmiCtlDataFormat format,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_format = (guint8)(format);
    self->arg_format_set = TRUE;

    return TRUE;
}

GType
qmi_message_ctl_set_data_format_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageCtlSetDataFormatInput"),
                                          (GBoxedCopyFunc) qmi_message_ctl_set_data_format_input_ref,
                                          (GBoxedFreeFunc) qmi_message_ctl_set_data_format_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_ctl_set_data_format_input_ref:
 * @self: a #QmiMessageCtlSetDataFormatInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageCtlSetDataFormatInput *
qmi_message_ctl_set_data_format_input_ref (QmiMessageCtlSetDataFormatInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_ctl_set_data_format_input_unref:
 * @self: a #QmiMessageCtlSetDataFormatInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_ctl_set_data_format_input_unref (QmiMessageCtlSetDataFormatInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageCtlSetDataFormatInput, self);
    }
}

/**
 * qmi_message_ctl_set_data_format_input_new:
 *
 * Allocates a new #QmiMessageCtlSetDataFormatInput.
 *
 * Returns: the newly created #QmiMessageCtlSetDataFormatInput. The returned value should be freed with qmi_message_ctl_set_data_format_input_unref().
 */
QmiMessageCtlSetDataFormatInput *
qmi_message_ctl_set_data_format_input_new (void)
{
    QmiMessageCtlSetDataFormatInput *self;

    self = g_slice_new0 (QmiMessageCtlSetDataFormatInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_ctl_set_data_format_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessageCtlSetDataFormatInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_CTL,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_CTL_SET_DATA_FORMAT);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Set Data Format' has mandatory TLVs");
        qmi_message_unref (self);
        return NULL;
    }

    /* Try to add the 'Protocol' TLV */
    if (input->arg_protocol_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint16 tmp;

            tmp = (guint16)input->arg_protocol;
            /* Write the guint16 variable to the buffer */
            qmi_utils_write_guint16_to_buffer (
                &buffer_aux,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_CTL_SET_DATA_FORMAT_INPUT_TLV_PROTOCOL,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Protocol TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'Protocol' in message 'Set Data Format'");
        qmi_message_unref (self);
        return NULL;
    }

    /* Try to add the 'Format' TLV */
    if (input->arg_format_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_format;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_CTL_SET_DATA_FORMAT_INPUT_TLV_FORMAT,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Format TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'Format' in message 'Set Data Format'");
        qmi_message_unref (self);
        return NULL;
    }

    return self;
}

/* --- Output -- */

struct _QmiMessageCtlSetDataFormatOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Protocol */
    gboolean arg_protocol_set;
    guint16 arg_protocol;
};

#define QMI_MESSAGE_CTL_SET_DATA_FORMAT_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_CTL_SET_DATA_FORMAT_OUTPUT_TLV_PROTOCOL 0x10

/**
 * qmi_message_ctl_set_data_format_output_get_result:
 * @self: a QmiMessageCtlSetDataFormatOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_ctl_set_data_format_output_get_result (
    QmiMessageCtlSetDataFormatOutput *self,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    /* We should always have a result set in the response message */
    if (!self->arg_result_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_MESSAGE,
                     "No 'Result' field given in the message");
        return FALSE;
    }

    if (self->arg_result.error_status == QMI_STATUS_SUCCESS) {
        /* Operation succeeded */
        return TRUE;
    }

    /* Report a QMI protocol error */
    g_set_error (error,
                 QMI_PROTOCOL_ERROR,
                 (QmiProtocolError) self->arg_result.error_code,
                 "QMI protocol error (%u): '%s'",
                 self->arg_result.error_code,
                 qmi_protocol_error_get_string ((QmiProtocolError) self->arg_result.error_code));
    return FALSE;
}

/**
 * qmi_message_ctl_set_data_format_output_get_protocol:
 * @self: a #QmiMessageCtlSetDataFormatOutput.
 * @protocol: a placeholder for the output #QmiCtlDataLinkProtocol, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Protocol' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_ctl_set_data_format_output_get_protocol (
    QmiMessageCtlSetDataFormatOutput *self,
    QmiCtlDataLinkProtocol *protocol,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_protocol_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Protocol' was not found in the message");
        return FALSE;
    }

    if (protocol)
        *protocol = (QmiCtlDataLinkProtocol)(self->arg_protocol);

    return TRUE;
}

GType
qmi_message_ctl_set_data_format_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageCtlSetDataFormatOutput"),
                                          (GBoxedCopyFunc) qmi_message_ctl_set_data_format_output_ref,
                                          (GBoxedFreeFunc) qmi_message_ctl_set_data_format_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_ctl_set_data_format_output_ref:
 * @self: a #QmiMessageCtlSetDataFormatOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageCtlSetDataFormatOutput *
qmi_message_ctl_set_data_format_output_ref (QmiMessageCtlSetDataFormatOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_ctl_set_data_format_output_unref:
 * @self: a #QmiMessageCtlSetDataFormatOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_ctl_set_data_format_output_unref (QmiMessageCtlSetDataFormatOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageCtlSetDataFormatOutput, self);
    }
}

static gboolean
qmi_message_ctl_set_data_format_input_protocol_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 2;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Protocol' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Protocol' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_ctl_set_data_format_input_protocol_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_CTL_SET_DATA_FORMAT_INPUT_TLV_PROTOCOL,
                                      &buffer_len);
    if (buffer && qmi_message_ctl_set_data_format_input_protocol_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint16 tmp;

            /* Read the guint16 variable from the buffer */
            qmi_utils_read_guint16_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &tmp);

#if defined  __QMI_CTL_DATA_LINK_PROTOCOL_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_ctl_data_link_protocol_get_string ((QmiCtlDataLinkProtocol)tmp));
#elif defined  __QMI_CTL_DATA_LINK_PROTOCOL_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_ctl_data_link_protocol_build_string_from_mask ((QmiCtlDataLinkProtocol)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiCtlDataLinkProtocol
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Protocol' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_ctl_set_data_format_input_format_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Format' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Format' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_ctl_set_data_format_input_format_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_CTL_SET_DATA_FORMAT_INPUT_TLV_FORMAT,
                                      &buffer_len);
    if (buffer && qmi_message_ctl_set_data_format_input_format_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_CTL_DATA_FORMAT_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_ctl_data_format_get_string ((QmiCtlDataFormat)tmp));
#elif defined  __QMI_CTL_DATA_FORMAT_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_ctl_data_format_build_string_from_mask ((QmiCtlDataFormat)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiCtlDataFormat
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Format' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_ctl_set_data_format_output_protocol_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 2;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Protocol' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Protocol' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_ctl_set_data_format_output_protocol_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_CTL_SET_DATA_FORMAT_OUTPUT_TLV_PROTOCOL,
                                      &buffer_len);
    if (buffer && qmi_message_ctl_set_data_format_output_protocol_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint16 tmp;

            /* Read the guint16 variable from the buffer */
            qmi_utils_read_guint16_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &tmp);

#if defined  __QMI_CTL_DATA_LINK_PROTOCOL_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_ctl_data_link_protocol_get_string ((QmiCtlDataLinkProtocol)tmp));
#elif defined  __QMI_CTL_DATA_LINK_PROTOCOL_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_ctl_data_link_protocol_build_string_from_mask ((QmiCtlDataLinkProtocol)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiCtlDataLinkProtocol
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Protocol' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_set_data_format_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_set_data_format_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_set_data_format_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_CTL_SET_DATA_FORMAT_INPUT_TLV_PROTOCOL:
            tlv_type_str = "Protocol";
            translated_value = qmi_message_ctl_set_data_format_input_protocol_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_CTL_SET_DATA_FORMAT_INPUT_TLV_FORMAT:
            tlv_type_str = "Format";
            translated_value = qmi_message_ctl_set_data_format_input_format_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_CTL_SET_DATA_FORMAT_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_CTL_SET_DATA_FORMAT_OUTPUT_TLV_PROTOCOL:
            tlv_type_str = "Protocol";
            translated_value = qmi_message_ctl_set_data_format_output_protocol_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    }

    if (!tlv_type_str) {
        gchar *value_str = NULL;

        value_str = qmi_message_get_tlv_printable (ctx->self,
                                                   ctx->line_prefix,
                                                   type,
                                                   value,
                                                   length);
        g_string_append (ctx->printable, value_str);
        g_free (value_str);
    } else {
        gchar *value_hex;

        value_hex = __qmi_utils_str_hex (value, length, ':');
        g_string_append_printf (ctx->printable,
                                "%sTLV:\n"
                                "%s  type       = \"%s\" (0x%02x)\n"
                                "%s  length     = %" G_GSIZE_FORMAT "\n"
                                "%s  value      = %s\n"
                                "%s  translated = %s\n",
                                ctx->line_prefix,
                                ctx->line_prefix, tlv_type_str, type,
                                ctx->line_prefix, length,
                                ctx->line_prefix, value_hex,
                                ctx->line_prefix, translated_value ? translated_value : "");
        g_free (value_hex);
        g_free (translated_value);
    }
}

static gchar *
message_set_data_format_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Set Data Format\" (0x0026)\n",
                            line_prefix);

    {
        struct message_set_data_format_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_set_data_format_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageCtlSetDataFormatOutput *
__qmi_message_ctl_set_data_format_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageCtlSetDataFormatOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_CTL_SET_DATA_FORMAT, NULL);

    self = g_slice_new0 (QmiMessageCtlSetDataFormatOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_CTL_SET_DATA_FORMAT_OUTPUT_TLV_RESULT,
                                              &buffer_len);
            if (buffer && qmi_message_result_validate (buffer, buffer_len)) {
                self->arg_result_set = TRUE;

                /* Read the guint16 variable from the buffer */
                qmi_utils_read_guint16_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_result.error_status));
                /* Read the guint16 variable from the buffer */
                qmi_utils_read_guint16_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_result.error_code));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Result' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the Result TLV: Not found");
                qmi_message_ctl_set_data_format_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_CTL_SET_DATA_FORMAT_OUTPUT_TLV_PROTOCOL,
                                              &buffer_len);
            if (buffer && qmi_message_ctl_set_data_format_output_protocol_validate (buffer, buffer_len)) {
                self->arg_protocol_set = TRUE;

                {
                    guint16 tmp;

                    /* Read the guint16 variable from the buffer */
                    qmi_utils_read_guint16_from_buffer (
                        &buffer,
                        &buffer_len,
                        QMI_ENDIAN_LITTLE,
                        &tmp);
                    self->arg_protocol = (QmiCtlDataLinkProtocol)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Protocol' TLV", buffer_len);
                }
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message CTL Sync */


/* --- Input -- */

/* Note: no fields in the Input container */

static QmiMessage *
__qmi_message_ctl_sync_request_create (
    guint8 transaction_id,
    guint8 cid,
    gpointer unused,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_CTL,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_CTL_SYNC);

    return self;
}

/* --- Output -- */

struct _QmiMessageCtlSyncOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;
};

#define QMI_MESSAGE_CTL_SYNC_OUTPUT_TLV_RESULT 0x02

/**
 * qmi_message_ctl_sync_output_get_result:
 * @self: a QmiMessageCtlSyncOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_ctl_sync_output_get_result (
    QmiMessageCtlSyncOutput *self,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    /* We should always have a result set in the response message */
    if (!self->arg_result_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_MESSAGE,
                     "No 'Result' field given in the message");
        return FALSE;
    }

    if (self->arg_result.error_status == QMI_STATUS_SUCCESS) {
        /* Operation succeeded */
        return TRUE;
    }

    /* Report a QMI protocol error */
    g_set_error (error,
                 QMI_PROTOCOL_ERROR,
                 (QmiProtocolError) self->arg_result.error_code,
                 "QMI protocol error (%u): '%s'",
                 self->arg_result.error_code,
                 qmi_protocol_error_get_string ((QmiProtocolError) self->arg_result.error_code));
    return FALSE;
}

GType
qmi_message_ctl_sync_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageCtlSyncOutput"),
                                          (GBoxedCopyFunc) qmi_message_ctl_sync_output_ref,
                                          (GBoxedFreeFunc) qmi_message_ctl_sync_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_ctl_sync_output_ref:
 * @self: a #QmiMessageCtlSyncOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageCtlSyncOutput *
qmi_message_ctl_sync_output_ref (QmiMessageCtlSyncOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_ctl_sync_output_unref:
 * @self: a #QmiMessageCtlSyncOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_ctl_sync_output_unref (QmiMessageCtlSyncOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageCtlSyncOutput, self);
    }
}

struct message_sync_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_sync_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_sync_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_CTL_SYNC_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    }

    if (!tlv_type_str) {
        gchar *value_str = NULL;

        value_str = qmi_message_get_tlv_printable (ctx->self,
                                                   ctx->line_prefix,
                                                   type,
                                                   value,
                                                   length);
        g_string_append (ctx->printable, value_str);
        g_free (value_str);
    } else {
        gchar *value_hex;

        value_hex = __qmi_utils_str_hex (value, length, ':');
        g_string_append_printf (ctx->printable,
                                "%sTLV:\n"
                                "%s  type       = \"%s\" (0x%02x)\n"
                                "%s  length     = %" G_GSIZE_FORMAT "\n"
                                "%s  value      = %s\n"
                                "%s  translated = %s\n",
                                ctx->line_prefix,
                                ctx->line_prefix, tlv_type_str, type,
                                ctx->line_prefix, length,
                                ctx->line_prefix, value_hex,
                                ctx->line_prefix, translated_value ? translated_value : "");
        g_free (value_hex);
        g_free (translated_value);
    }
}

static gchar *
message_sync_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Sync\" (0x0027)\n",
                            line_prefix);

    {
        struct message_sync_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_sync_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageCtlSyncOutput *
__qmi_message_ctl_sync_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageCtlSyncOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_CTL_SYNC, NULL);

    self = g_slice_new0 (QmiMessageCtlSyncOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_CTL_SYNC_OUTPUT_TLV_RESULT,
                                              &buffer_len);
            if (buffer && qmi_message_result_validate (buffer, buffer_len)) {
                self->arg_result_set = TRUE;

                /* Read the guint16 variable from the buffer */
                qmi_utils_read_guint16_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_result.error_status));
                /* Read the guint16 variable from the buffer */
                qmi_utils_read_guint16_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_result.error_code));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Result' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the Result TLV: Not found");
                qmi_message_ctl_sync_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* INDICATION: Qmi Indication CTL Sync */


/* --- Output -- */

/* Note: no fields in the Output container */

static gchar *
indication_sync_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Sync\" (0x0027)\n",
                            line_prefix);

    return g_string_free (printable, FALSE);
}

/*****************************************************************************/
/* Service-specific printable: CTL */


gchar *
__qmi_message_ctl_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    if (qmi_message_is_indication (self)) {
        switch (qmi_message_get_message_id (self)) {
        case QMI_INDICATION_CTL_SYNC:
            return indication_sync_get_printable (self, line_prefix);
         default:
             return NULL;
        }
    } else {
        switch (qmi_message_get_message_id (self)) {
        case QMI_MESSAGE_CTL_SET_INSTANCE_ID:
            return message_set_instance_id_get_printable (self, line_prefix);
        case QMI_MESSAGE_CTL_GET_VERSION_INFO:
            return message_get_version_info_get_printable (self, line_prefix);
        case QMI_MESSAGE_CTL_ALLOCATE_CID:
            return message_allocate_cid_get_printable (self, line_prefix);
        case QMI_MESSAGE_CTL_RELEASE_CID:
            return message_release_cid_get_printable (self, line_prefix);
        case QMI_MESSAGE_CTL_SET_DATA_FORMAT:
            return message_set_data_format_get_printable (self, line_prefix);
        case QMI_MESSAGE_CTL_SYNC:
            return message_sync_get_printable (self, line_prefix);
         default:
             return NULL;
        }
    }
}

gboolean
__qmi_message_ctl_get_version_introduced (
    QmiMessage *self,
    guint *major,
    guint *minor)
{
    switch (qmi_message_get_message_id (self)) {
    default:
        return FALSE;
    }
}

/*****************************************************************************/
/* CLIENT: QMI Client CTL */

G_DEFINE_TYPE (QmiClientCtl, qmi_client_ctl, QMI_TYPE_CLIENT);

enum {
    SIGNAL_SYNC,
    SIGNAL_LAST
};

static guint signals[SIGNAL_LAST] = { 0 };

static void
process_indication (QmiClient *self,
                    QmiMessage *message)
{
    switch (qmi_message_get_message_id (message)) {
        case QMI_INDICATION_CTL_SYNC: {
            g_signal_emit (self, signals[SIGNAL_SYNC], 0, NULL);
            break;
        }
        default:
            break;
    }
}

static void
qmi_client_ctl_init (QmiClientCtl *self)
{
}

static void
qmi_client_ctl_class_init (QmiClientCtlClass *klass)
{
    QmiClientClass *client_class = QMI_CLIENT_CLASS (klass);

    client_class->process_indication = process_indication;

    /**
     * QmiClientCtl::sync:
     * @object: A #QmiClientCtl.
     *
     * The ::sync signal gets emitted when a 'Sync' indication is received.
     */
    signals[SIGNAL_SYNC] =
        g_signal_new ("sync",
                      G_OBJECT_CLASS_TYPE (G_OBJECT_CLASS (klass)),
                      G_SIGNAL_RUN_LAST,
                      0,
                      NULL,
                      NULL,
                      NULL,
                      G_TYPE_NONE,
                      0);
}


/**
 * qmi_client_ctl_set_instance_id_finish:
 * @self: a #QmiClientCtl.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_ctl_set_instance_id().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_ctl_set_instance_id().
 *
 * Returns: a #QmiMessageCtlSetInstanceIdOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_ctl_set_instance_id_output_unref().
 */
QmiMessageCtlSetInstanceIdOutput *
qmi_client_ctl_set_instance_id_finish (
    QmiClientCtl *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_ctl_set_instance_id_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
set_instance_id_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageCtlSetInstanceIdOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_ctl_set_instance_id_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_ctl_set_instance_id_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_ctl_set_instance_id:
 * @self: a #QmiClientCtl.
 * @input: a #QmiMessageCtlSetInstanceIdInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Set Instance ID request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_ctl_set_instance_id_finish() to get the result of the operation.
 */
void
qmi_client_ctl_set_instance_id (
    QmiClientCtl *self,
    QmiMessageCtlSetInstanceIdInput *input,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data)
{
    GSimpleAsyncResult *result;
    QmiMessage *request;
    GError *error = NULL;
    guint16 transaction_id;

    result = g_simple_async_result_new (G_OBJECT (self),
                                        callback,
                                        user_data,
                                        qmi_client_ctl_set_instance_id);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_ctl_set_instance_id_request_create (
                  transaction_id,
                  qmi_client_get_cid (QMI_CLIENT (self)),
                  input,
                  &error);
    if (!request) {
        g_prefix_error (&error, "Couldn't create request message: ");
        g_simple_async_result_take_error (result, error);
        g_simple_async_result_complete_in_idle (result);
        g_object_unref (result);
        return;
    }

    qmi_device_command (QMI_DEVICE (qmi_client_peek_device (QMI_CLIENT (self))),
                        request,
                        timeout,
                        cancellable,
                        (GAsyncReadyCallback)set_instance_id_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_ctl_get_version_info_finish:
 * @self: a #QmiClientCtl.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_ctl_get_version_info().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_ctl_get_version_info().
 *
 * Returns: a #QmiMessageCtlGetVersionInfoOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_ctl_get_version_info_output_unref().
 */
QmiMessageCtlGetVersionInfoOutput *
qmi_client_ctl_get_version_info_finish (
    QmiClientCtl *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_ctl_get_version_info_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
get_version_info_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageCtlGetVersionInfoOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_ctl_get_version_info_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_ctl_get_version_info_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_ctl_get_version_info:
 * @self: a #QmiClientCtl.
 * @unused: %NULL. This message doesn't have any input bundle.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Get Version Info request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_ctl_get_version_info_finish() to get the result of the operation.
 */
void
qmi_client_ctl_get_version_info (
    QmiClientCtl *self,
    gpointer unused,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data)
{
    GSimpleAsyncResult *result;
    QmiMessage *request;
    GError *error = NULL;
    guint16 transaction_id;

    result = g_simple_async_result_new (G_OBJECT (self),
                                        callback,
                                        user_data,
                                        qmi_client_ctl_get_version_info);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_ctl_get_version_info_request_create (
                  transaction_id,
                  qmi_client_get_cid (QMI_CLIENT (self)),
                  NULL,
                  &error);
    if (!request) {
        g_prefix_error (&error, "Couldn't create request message: ");
        g_simple_async_result_take_error (result, error);
        g_simple_async_result_complete_in_idle (result);
        g_object_unref (result);
        return;
    }

    qmi_device_command (QMI_DEVICE (qmi_client_peek_device (QMI_CLIENT (self))),
                        request,
                        timeout,
                        cancellable,
                        (GAsyncReadyCallback)get_version_info_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_ctl_allocate_cid_finish:
 * @self: a #QmiClientCtl.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_ctl_allocate_cid().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_ctl_allocate_cid().
 *
 * Returns: a #QmiMessageCtlAllocateCidOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_ctl_allocate_cid_output_unref().
 */
QmiMessageCtlAllocateCidOutput *
qmi_client_ctl_allocate_cid_finish (
    QmiClientCtl *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_ctl_allocate_cid_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
allocate_cid_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageCtlAllocateCidOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_ctl_allocate_cid_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_ctl_allocate_cid_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_ctl_allocate_cid:
 * @self: a #QmiClientCtl.
 * @input: a #QmiMessageCtlAllocateCidInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Allocate CID request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_ctl_allocate_cid_finish() to get the result of the operation.
 */
void
qmi_client_ctl_allocate_cid (
    QmiClientCtl *self,
    QmiMessageCtlAllocateCidInput *input,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data)
{
    GSimpleAsyncResult *result;
    QmiMessage *request;
    GError *error = NULL;
    guint16 transaction_id;

    result = g_simple_async_result_new (G_OBJECT (self),
                                        callback,
                                        user_data,
                                        qmi_client_ctl_allocate_cid);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_ctl_allocate_cid_request_create (
                  transaction_id,
                  qmi_client_get_cid (QMI_CLIENT (self)),
                  input,
                  &error);
    if (!request) {
        g_prefix_error (&error, "Couldn't create request message: ");
        g_simple_async_result_take_error (result, error);
        g_simple_async_result_complete_in_idle (result);
        g_object_unref (result);
        return;
    }

    qmi_device_command (QMI_DEVICE (qmi_client_peek_device (QMI_CLIENT (self))),
                        request,
                        timeout,
                        cancellable,
                        (GAsyncReadyCallback)allocate_cid_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_ctl_release_cid_finish:
 * @self: a #QmiClientCtl.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_ctl_release_cid().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_ctl_release_cid().
 *
 * Returns: a #QmiMessageCtlReleaseCidOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_ctl_release_cid_output_unref().
 */
QmiMessageCtlReleaseCidOutput *
qmi_client_ctl_release_cid_finish (
    QmiClientCtl *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_ctl_release_cid_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
release_cid_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageCtlReleaseCidOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_ctl_release_cid_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_ctl_release_cid_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_ctl_release_cid:
 * @self: a #QmiClientCtl.
 * @input: a #QmiMessageCtlReleaseCidInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Release CID request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_ctl_release_cid_finish() to get the result of the operation.
 */
void
qmi_client_ctl_release_cid (
    QmiClientCtl *self,
    QmiMessageCtlReleaseCidInput *input,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data)
{
    GSimpleAsyncResult *result;
    QmiMessage *request;
    GError *error = NULL;
    guint16 transaction_id;

    result = g_simple_async_result_new (G_OBJECT (self),
                                        callback,
                                        user_data,
                                        qmi_client_ctl_release_cid);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_ctl_release_cid_request_create (
                  transaction_id,
                  qmi_client_get_cid (QMI_CLIENT (self)),
                  input,
                  &error);
    if (!request) {
        g_prefix_error (&error, "Couldn't create request message: ");
        g_simple_async_result_take_error (result, error);
        g_simple_async_result_complete_in_idle (result);
        g_object_unref (result);
        return;
    }

    qmi_device_command (QMI_DEVICE (qmi_client_peek_device (QMI_CLIENT (self))),
                        request,
                        timeout,
                        cancellable,
                        (GAsyncReadyCallback)release_cid_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_ctl_set_data_format_finish:
 * @self: a #QmiClientCtl.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_ctl_set_data_format().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_ctl_set_data_format().
 *
 * Returns: a #QmiMessageCtlSetDataFormatOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_ctl_set_data_format_output_unref().
 */
QmiMessageCtlSetDataFormatOutput *
qmi_client_ctl_set_data_format_finish (
    QmiClientCtl *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_ctl_set_data_format_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
set_data_format_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageCtlSetDataFormatOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_ctl_set_data_format_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_ctl_set_data_format_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_ctl_set_data_format:
 * @self: a #QmiClientCtl.
 * @input: a #QmiMessageCtlSetDataFormatInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Set Data Format request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_ctl_set_data_format_finish() to get the result of the operation.
 */
void
qmi_client_ctl_set_data_format (
    QmiClientCtl *self,
    QmiMessageCtlSetDataFormatInput *input,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data)
{
    GSimpleAsyncResult *result;
    QmiMessage *request;
    GError *error = NULL;
    guint16 transaction_id;

    result = g_simple_async_result_new (G_OBJECT (self),
                                        callback,
                                        user_data,
                                        qmi_client_ctl_set_data_format);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_ctl_set_data_format_request_create (
                  transaction_id,
                  qmi_client_get_cid (QMI_CLIENT (self)),
                  input,
                  &error);
    if (!request) {
        g_prefix_error (&error, "Couldn't create request message: ");
        g_simple_async_result_take_error (result, error);
        g_simple_async_result_complete_in_idle (result);
        g_object_unref (result);
        return;
    }

    qmi_device_command (QMI_DEVICE (qmi_client_peek_device (QMI_CLIENT (self))),
                        request,
                        timeout,
                        cancellable,
                        (GAsyncReadyCallback)set_data_format_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_ctl_sync_finish:
 * @self: a #QmiClientCtl.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_ctl_sync().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_ctl_sync().
 *
 * Returns: a #QmiMessageCtlSyncOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_ctl_sync_output_unref().
 */
QmiMessageCtlSyncOutput *
qmi_client_ctl_sync_finish (
    QmiClientCtl *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_ctl_sync_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
sync_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageCtlSyncOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_ctl_sync_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_ctl_sync_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_ctl_sync:
 * @self: a #QmiClientCtl.
 * @unused: %NULL. This message doesn't have any input bundle.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Sync request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_ctl_sync_finish() to get the result of the operation.
 */
void
qmi_client_ctl_sync (
    QmiClientCtl *self,
    gpointer unused,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data)
{
    GSimpleAsyncResult *result;
    QmiMessage *request;
    GError *error = NULL;
    guint16 transaction_id;

    result = g_simple_async_result_new (G_OBJECT (self),
                                        callback,
                                        user_data,
                                        qmi_client_ctl_sync);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_ctl_sync_request_create (
                  transaction_id,
                  qmi_client_get_cid (QMI_CLIENT (self)),
                  NULL,
                  &error);
    if (!request) {
        g_prefix_error (&error, "Couldn't create request message: ");
        g_simple_async_result_take_error (result, error);
        g_simple_async_result_complete_in_idle (result);
        g_object_unref (result);
        return;
    }

    qmi_device_command (QMI_DEVICE (qmi_client_peek_device (QMI_CLIENT (self))),
                        request,
                        timeout,
                        cancellable,
                        (GAsyncReadyCallback)sync_ready,
                        result);
    qmi_message_unref (request);
}

