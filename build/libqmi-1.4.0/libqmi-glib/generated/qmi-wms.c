
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

#include "qmi-wms.h"
#include "qmi-enum-types.h"
#include "qmi-enum-types-private.h"
#include "qmi-flags64-types.h"
#include "qmi-error-types.h"
#include "qmi-device.h"
#include "qmi-utils.h"

#define QMI_STATUS_SUCCESS 0x0000
#define QMI_STATUS_FAILURE 0x0001


typedef enum {
    QMI_MESSAGE_WMS_RESET = 0x0000,
    QMI_MESSAGE_WMS_SET_EVENT_REPORT = 0x0001,
    QMI_MESSAGE_WMS_RAW_SEND = 0x0020,
    QMI_MESSAGE_WMS_RAW_WRITE = 0x0021,
    QMI_MESSAGE_WMS_RAW_READ = 0x0022,
    QMI_MESSAGE_WMS_MODIFY_TAG = 0x0023,
    QMI_MESSAGE_WMS_DELETE = 0x0024,
    QMI_MESSAGE_WMS_GET_MESSAGE_PROTOCOL = 0x0030,
    QMI_MESSAGE_WMS_LIST_MESSAGES = 0x0031,
    QMI_MESSAGE_WMS_SET_ROUTES = 0x0032,
    QMI_MESSAGE_WMS_GET_ROUTES = 0x0033,
    QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE = 0x0042,
} QmiMessageWms;


typedef enum {
    QMI_INDICATION_WMS_EVENT_REPORT = 0x0001,
} QmiIndicationWms;


/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WMS Reset */


/* --- Input -- */

/* Note: no fields in the Input container */

static QmiMessage *
__qmi_message_wms_reset_request_create (
    guint8 transaction_id,
    guint8 cid,
    gpointer unused,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WMS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WMS_RESET);

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

struct _QmiMessageWmsResetOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;
};

#define QMI_MESSAGE_WMS_RESET_OUTPUT_TLV_RESULT 0x02

/**
 * qmi_message_wms_reset_output_get_result:
 * @self: a QmiMessageWmsResetOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wms_reset_output_get_result (
    QmiMessageWmsResetOutput *self,
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
qmi_message_wms_reset_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsResetOutput"),
                                          (GBoxedCopyFunc) qmi_message_wms_reset_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_reset_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_reset_output_ref:
 * @self: a #QmiMessageWmsResetOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsResetOutput *
qmi_message_wms_reset_output_ref (QmiMessageWmsResetOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_reset_output_unref:
 * @self: a #QmiMessageWmsResetOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_reset_output_unref (QmiMessageWmsResetOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWmsResetOutput, self);
    }
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
                                      QMI_MESSAGE_WMS_RESET_OUTPUT_TLV_RESULT,
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

struct message_reset_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_reset_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_reset_context *ctx)
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
        case QMI_MESSAGE_WMS_RESET_OUTPUT_TLV_RESULT:
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
message_reset_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Reset\" (0x0000)\n",
                            line_prefix);

    {
        struct message_reset_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_reset_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageWmsResetOutput *
__qmi_message_wms_reset_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWmsResetOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WMS_RESET, NULL);

    self = g_slice_new0 (QmiMessageWmsResetOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WMS_RESET_OUTPUT_TLV_RESULT,
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
                qmi_message_wms_reset_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WMS Set Event Report */


/* --- Input -- */

struct _QmiMessageWmsSetEventReportInput {
    volatile gint ref_count;

    /* New MT Message Indicator */
    gboolean arg_new_mt_message_indicator_set;
    guint8 arg_new_mt_message_indicator_report;
};

#define QMI_MESSAGE_WMS_SET_EVENT_REPORT_INPUT_TLV_NEW_MT_MESSAGE_INDICATOR 0x10

/**
 * qmi_message_wms_set_event_report_input_get_new_mt_message_indicator:
 * @self: a #QmiMessageWmsSetEventReportInput.
 * @new_mt_message_indicator_report: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'New MT Message Indicator' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_set_event_report_input_get_new_mt_message_indicator (
    QmiMessageWmsSetEventReportInput *self,
    gboolean *new_mt_message_indicator_report,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_new_mt_message_indicator_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'New MT Message Indicator' was not found in the message");
        return FALSE;
    }

    if (new_mt_message_indicator_report)
        *new_mt_message_indicator_report = (gboolean)(self->arg_new_mt_message_indicator_report);

    return TRUE;
}

/**
 * qmi_message_wms_set_event_report_input_set_new_mt_message_indicator:
 * @self: a #QmiMessageWmsSetEventReportInput.
 * @new_mt_message_indicator_report: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'New MT Message Indicator' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_set_event_report_input_set_new_mt_message_indicator (
    QmiMessageWmsSetEventReportInput *self,
    gboolean new_mt_message_indicator_report,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_new_mt_message_indicator_report = (guint8)(new_mt_message_indicator_report);
    self->arg_new_mt_message_indicator_set = TRUE;

    return TRUE;
}

GType
qmi_message_wms_set_event_report_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsSetEventReportInput"),
                                          (GBoxedCopyFunc) qmi_message_wms_set_event_report_input_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_set_event_report_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_set_event_report_input_ref:
 * @self: a #QmiMessageWmsSetEventReportInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsSetEventReportInput *
qmi_message_wms_set_event_report_input_ref (QmiMessageWmsSetEventReportInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_set_event_report_input_unref:
 * @self: a #QmiMessageWmsSetEventReportInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_set_event_report_input_unref (QmiMessageWmsSetEventReportInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWmsSetEventReportInput, self);
    }
}

/**
 * qmi_message_wms_set_event_report_input_new:
 *
 * Allocates a new #QmiMessageWmsSetEventReportInput.
 *
 * Returns: the newly created #QmiMessageWmsSetEventReportInput. The returned value should be freed with qmi_message_wms_set_event_report_input_unref().
 */
QmiMessageWmsSetEventReportInput *
qmi_message_wms_set_event_report_input_new (void)
{
    QmiMessageWmsSetEventReportInput *self;

    self = g_slice_new0 (QmiMessageWmsSetEventReportInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_wms_set_event_report_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessageWmsSetEventReportInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WMS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WMS_SET_EVENT_REPORT);

    /* All TLVs are optional, we allow NULL input */
    if (!input)
        return self;

    /* Try to add the 'New MT Message Indicator' TLV */
    if (input->arg_new_mt_message_indicator_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_new_mt_message_indicator_report;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_SET_EVENT_REPORT_INPUT_TLV_NEW_MT_MESSAGE_INDICATOR,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the New MT Message Indicator TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    return self;
}

/* --- Output -- */

struct _QmiMessageWmsSetEventReportOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;
};

#define QMI_MESSAGE_WMS_SET_EVENT_REPORT_OUTPUT_TLV_RESULT 0x02

/**
 * qmi_message_wms_set_event_report_output_get_result:
 * @self: a QmiMessageWmsSetEventReportOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wms_set_event_report_output_get_result (
    QmiMessageWmsSetEventReportOutput *self,
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
qmi_message_wms_set_event_report_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsSetEventReportOutput"),
                                          (GBoxedCopyFunc) qmi_message_wms_set_event_report_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_set_event_report_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_set_event_report_output_ref:
 * @self: a #QmiMessageWmsSetEventReportOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsSetEventReportOutput *
qmi_message_wms_set_event_report_output_ref (QmiMessageWmsSetEventReportOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_set_event_report_output_unref:
 * @self: a #QmiMessageWmsSetEventReportOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_set_event_report_output_unref (QmiMessageWmsSetEventReportOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWmsSetEventReportOutput, self);
    }
}

static gboolean
qmi_message_wms_set_event_report_input_new_mt_message_indicator_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'New MT Message Indicator' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'New MT Message Indicator' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_set_event_report_input_new_mt_message_indicator_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_SET_EVENT_REPORT_INPUT_TLV_NEW_MT_MESSAGE_INDICATOR,
                                      &buffer_len);
    if (buffer && qmi_message_wms_set_event_report_input_new_mt_message_indicator_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " report = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

            g_string_append_printf (printable, "%s", tmp ? "yes" : "no");
        }
        g_string_append (printable, "'");
        g_string_append (printable, " ]");

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'New MT Message Indicator' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_set_event_report_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_set_event_report_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_set_event_report_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_WMS_SET_EVENT_REPORT_INPUT_TLV_NEW_MT_MESSAGE_INDICATOR:
            tlv_type_str = "New MT Message Indicator";
            translated_value = qmi_message_wms_set_event_report_input_new_mt_message_indicator_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_WMS_SET_EVENT_REPORT_OUTPUT_TLV_RESULT:
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
message_set_event_report_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Set Event Report\" (0x0001)\n",
                            line_prefix);

    {
        struct message_set_event_report_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_set_event_report_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageWmsSetEventReportOutput *
__qmi_message_wms_set_event_report_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWmsSetEventReportOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WMS_SET_EVENT_REPORT, NULL);

    self = g_slice_new0 (QmiMessageWmsSetEventReportOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WMS_SET_EVENT_REPORT_OUTPUT_TLV_RESULT,
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
                qmi_message_wms_set_event_report_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* INDICATION: Qmi Indication WMS Event Report */


/* --- Output -- */

struct _QmiIndicationWmsEventReportOutput {
    volatile gint ref_count;

    /* SMS on IMS */
    gboolean arg_sms_on_ims_set;
    guint8 arg_sms_on_ims;

    /* SMSC Address */
    gboolean arg_smsc_address_set;
    gchar *arg_smsc_address;

    /* ETWS PLMN Information */
    gboolean arg_etws_plmn_information_set;
    guint16 arg_etws_plmn_information_mcc;
    guint16 arg_etws_plmn_information_mnc;

    /* ETWS Message */
    gboolean arg_etws_message_set;
    guint8 arg_etws_message_notification_type;
    GArray *arg_etws_message_raw_data;

    /* Message Mode */
    gboolean arg_message_mode_set;
    guint8 arg_message_mode;

    /* Transfer Route MT Message */
    gboolean arg_transfer_route_mt_message_set;
    guint8 arg_transfer_route_mt_message_ack_indicator;
    guint32 arg_transfer_route_mt_message_transaction_id;
    guint8 arg_transfer_route_mt_message_format;
    GArray *arg_transfer_route_mt_message_raw_data;

    /* MT Message */
    gboolean arg_mt_message_set;
    guint8 arg_mt_message_storage_type;
    guint32 arg_mt_message_memory_index;
};

#define QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_SMS_ON_IMS 0x16
#define QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_SMSC_ADDRESS 0x15
#define QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_ETWS_PLMN_INFORMATION 0x14
#define QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_ETWS_MESSAGE 0x13
#define QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_MESSAGE_MODE 0x12
#define QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_TRANSFER_ROUTE_MT_MESSAGE 0x11
#define QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_MT_MESSAGE 0x10

/**
 * qmi_indication_wms_event_report_output_get_sms_on_ims:
 * @self: a #QmiIndicationWmsEventReportOutput.
 * @sms_on_ims: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'SMS on IMS' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_indication_wms_event_report_output_get_sms_on_ims (
    QmiIndicationWmsEventReportOutput *self,
    gboolean *sms_on_ims,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_sms_on_ims_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'SMS on IMS' was not found in the message");
        return FALSE;
    }

    if (sms_on_ims)
        *sms_on_ims = (gboolean)(self->arg_sms_on_ims);

    return TRUE;
}

/**
 * qmi_indication_wms_event_report_output_get_smsc_address:
 * @self: a #QmiIndicationWmsEventReportOutput.
 * @smsc_address: a placeholder for the output constant string, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'SMSC Address' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_indication_wms_event_report_output_get_smsc_address (
    QmiIndicationWmsEventReportOutput *self,
    const gchar **smsc_address,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_smsc_address_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'SMSC Address' was not found in the message");
        return FALSE;
    }

    if (smsc_address)
        *smsc_address = self->arg_smsc_address;

    return TRUE;
}

/**
 * qmi_indication_wms_event_report_output_get_etws_plmn_information:
 * @self: a #QmiIndicationWmsEventReportOutput.
 * @etws_plmn_information_mcc: a placeholder for the output #guint16, or %NULL if not required.
 * @etws_plmn_information_mnc: a placeholder for the output #guint16, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'ETWS PLMN Information' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_indication_wms_event_report_output_get_etws_plmn_information (
    QmiIndicationWmsEventReportOutput *self,
    guint16 *etws_plmn_information_mcc,
    guint16 *etws_plmn_information_mnc,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_etws_plmn_information_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'ETWS PLMN Information' was not found in the message");
        return FALSE;
    }

    if (etws_plmn_information_mcc)
        *etws_plmn_information_mcc = self->arg_etws_plmn_information_mcc;
    if (etws_plmn_information_mnc)
        *etws_plmn_information_mnc = self->arg_etws_plmn_information_mnc;

    return TRUE;
}

/**
 * qmi_indication_wms_event_report_output_get_etws_message:
 * @self: a #QmiIndicationWmsEventReportOutput.
 * @etws_message_notification_type: a placeholder for the output #QmiWmsNotificationType, or %NULL if not required.
 * @etws_message_raw_data: a placeholder for the output #GArray of #guint8 elements, or %NULL if not required. Do not free it, it is owned by @self.
 * @error: Return location for error or %NULL.
 *
 * Get the 'ETWS Message' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_indication_wms_event_report_output_get_etws_message (
    QmiIndicationWmsEventReportOutput *self,
    QmiWmsNotificationType *etws_message_notification_type,
    GArray **etws_message_raw_data,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_etws_message_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'ETWS Message' was not found in the message");
        return FALSE;
    }

    if (etws_message_notification_type)
        *etws_message_notification_type = (QmiWmsNotificationType)(self->arg_etws_message_notification_type);
    if (etws_message_raw_data)
        *etws_message_raw_data = self->arg_etws_message_raw_data;

    return TRUE;
}

/**
 * qmi_indication_wms_event_report_output_get_message_mode:
 * @self: a #QmiIndicationWmsEventReportOutput.
 * @message_mode: a placeholder for the output #QmiWmsMessageMode, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Message Mode' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_indication_wms_event_report_output_get_message_mode (
    QmiIndicationWmsEventReportOutput *self,
    QmiWmsMessageMode *message_mode,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_message_mode_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Message Mode' was not found in the message");
        return FALSE;
    }

    if (message_mode)
        *message_mode = (QmiWmsMessageMode)(self->arg_message_mode);

    return TRUE;
}

/**
 * qmi_indication_wms_event_report_output_get_transfer_route_mt_message:
 * @self: a #QmiIndicationWmsEventReportOutput.
 * @transfer_route_mt_message_ack_indicator: a placeholder for the output #QmiWmsAckIndicator, or %NULL if not required.
 * @transfer_route_mt_message_transaction_id: a placeholder for the output #guint32, or %NULL if not required.
 * @transfer_route_mt_message_format: a placeholder for the output #QmiWmsMessageFormat, or %NULL if not required.
 * @transfer_route_mt_message_raw_data: a placeholder for the output #GArray of #guint8 elements, or %NULL if not required. Do not free it, it is owned by @self.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Transfer Route MT Message' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_indication_wms_event_report_output_get_transfer_route_mt_message (
    QmiIndicationWmsEventReportOutput *self,
    QmiWmsAckIndicator *transfer_route_mt_message_ack_indicator,
    guint32 *transfer_route_mt_message_transaction_id,
    QmiWmsMessageFormat *transfer_route_mt_message_format,
    GArray **transfer_route_mt_message_raw_data,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_transfer_route_mt_message_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Transfer Route MT Message' was not found in the message");
        return FALSE;
    }

    if (transfer_route_mt_message_ack_indicator)
        *transfer_route_mt_message_ack_indicator = (QmiWmsAckIndicator)(self->arg_transfer_route_mt_message_ack_indicator);
    if (transfer_route_mt_message_transaction_id)
        *transfer_route_mt_message_transaction_id = self->arg_transfer_route_mt_message_transaction_id;
    if (transfer_route_mt_message_format)
        *transfer_route_mt_message_format = (QmiWmsMessageFormat)(self->arg_transfer_route_mt_message_format);
    if (transfer_route_mt_message_raw_data)
        *transfer_route_mt_message_raw_data = self->arg_transfer_route_mt_message_raw_data;

    return TRUE;
}

/**
 * qmi_indication_wms_event_report_output_get_mt_message:
 * @self: a #QmiIndicationWmsEventReportOutput.
 * @mt_message_storage_type: a placeholder for the output #QmiWmsStorageType, or %NULL if not required.
 * @mt_message_memory_index: a placeholder for the output #guint32, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'MT Message' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_indication_wms_event_report_output_get_mt_message (
    QmiIndicationWmsEventReportOutput *self,
    QmiWmsStorageType *mt_message_storage_type,
    guint32 *mt_message_memory_index,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_mt_message_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'MT Message' was not found in the message");
        return FALSE;
    }

    if (mt_message_storage_type)
        *mt_message_storage_type = (QmiWmsStorageType)(self->arg_mt_message_storage_type);
    if (mt_message_memory_index)
        *mt_message_memory_index = self->arg_mt_message_memory_index;

    return TRUE;
}

GType
qmi_indication_wms_event_report_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiIndicationWmsEventReportOutput"),
                                          (GBoxedCopyFunc) qmi_indication_wms_event_report_output_ref,
                                          (GBoxedFreeFunc) qmi_indication_wms_event_report_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_indication_wms_event_report_output_ref:
 * @self: a #QmiIndicationWmsEventReportOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiIndicationWmsEventReportOutput *
qmi_indication_wms_event_report_output_ref (QmiIndicationWmsEventReportOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_indication_wms_event_report_output_unref:
 * @self: a #QmiIndicationWmsEventReportOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_indication_wms_event_report_output_unref (QmiIndicationWmsEventReportOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_free (self->arg_smsc_address);
        if (self->arg_etws_message_raw_data)
            g_array_unref (self->arg_etws_message_raw_data);
        if (self->arg_transfer_route_mt_message_raw_data)
            g_array_unref (self->arg_transfer_route_mt_message_raw_data);
        g_slice_free (QmiIndicationWmsEventReportOutput, self);
    }
}

static gboolean
qmi_indication_wms_event_report_output_sms_on_ims_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'SMS on IMS' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'SMS on IMS' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_indication_wms_event_report_output_sms_on_ims_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_SMS_ON_IMS,
                                      &buffer_len);
    if (buffer && qmi_indication_wms_event_report_output_sms_on_ims_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

            g_string_append_printf (printable, "%s", tmp ? "yes" : "no");
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'SMS on IMS' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_indication_wms_event_report_output_smsc_address_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += buffer_len;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'SMSC Address' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'SMSC Address' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_indication_wms_event_report_output_smsc_address_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_SMSC_ADDRESS,
                                      &buffer_len);
    if (buffer && qmi_indication_wms_event_report_output_smsc_address_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            gchar *tmp;

            /* Read the string variable from the buffer */
            qmi_utils_read_string_from_buffer (
                &buffer,
                &buffer_len,
                0,
                0,
                &tmp);

            g_string_append_printf (printable, "%s", tmp);
            g_free (tmp);
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'SMSC Address' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_indication_wms_event_report_output_etws_plmn_information_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 2;
    expected_len += 2;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'ETWS PLMN Information' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'ETWS PLMN Information' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_indication_wms_event_report_output_etws_plmn_information_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_ETWS_PLMN_INFORMATION,
                                      &buffer_len);
    if (buffer && qmi_indication_wms_event_report_output_etws_plmn_information_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " mcc = '");

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
        g_string_append (printable, " mnc = '");

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

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'ETWS PLMN Information' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_indication_wms_event_report_output_etws_message_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;
    {
        guint raw_data_i;
        guint16 raw_data_n_items;
        const guint8 *raw_data_aux_buffer = &buffer[expected_len];
        guint16 raw_data_aux_buffer_len = buffer_len - expected_len;

        expected_len += 2;

        /* Read the guint16 variable from the buffer */
        qmi_utils_read_guint16_from_buffer (
            &raw_data_aux_buffer,
            &raw_data_aux_buffer_len,
            QMI_ENDIAN_LITTLE,
            &(raw_data_n_items));
        for (raw_data_i = 0; raw_data_i < raw_data_n_items; raw_data_i++) {

            expected_len += 1;
        }
    }

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'ETWS Message' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'ETWS Message' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_indication_wms_event_report_output_etws_message_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_ETWS_MESSAGE,
                                      &buffer_len);
    if (buffer && qmi_indication_wms_event_report_output_etws_message_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " notification_type = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_NOTIFICATION_TYPE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_notification_type_get_string ((QmiWmsNotificationType)tmp));
#elif defined  __QMI_WMS_NOTIFICATION_TYPE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_notification_type_build_string_from_mask ((QmiWmsNotificationType)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsNotificationType
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " raw_data = '");
        {
            guint raw_data_i;
            guint16 raw_data_n_items;

            /* Read number of items in the array */
            /* Read the guint16 variable from the buffer */
            qmi_utils_read_guint16_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &(raw_data_n_items));

            g_string_append (printable, "{");

            for (raw_data_i = 0; raw_data_i < raw_data_n_items; raw_data_i++) {
                g_string_append_printf (printable, " [%u] = '", raw_data_i);

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);

                    g_string_append_printf (printable, "%u", (guint)tmp);
                }
                g_string_append (printable, " '");
            }

            g_string_append (printable, "}");
        }        g_string_append (printable, "'");
        g_string_append (printable, " ]");

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'ETWS Message' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_indication_wms_event_report_output_message_mode_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Message Mode' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Message Mode' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_indication_wms_event_report_output_message_mode_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_MESSAGE_MODE,
                                      &buffer_len);
    if (buffer && qmi_indication_wms_event_report_output_message_mode_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_MESSAGE_MODE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_message_mode_get_string ((QmiWmsMessageMode)tmp));
#elif defined  __QMI_WMS_MESSAGE_MODE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_message_mode_build_string_from_mask ((QmiWmsMessageMode)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsMessageMode
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Message Mode' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_indication_wms_event_report_output_transfer_route_mt_message_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;
    expected_len += 4;
    expected_len += 1;
    {
        guint raw_data_i;
        guint16 raw_data_n_items;
        const guint8 *raw_data_aux_buffer = &buffer[expected_len];
        guint16 raw_data_aux_buffer_len = buffer_len - expected_len;

        expected_len += 2;

        /* Read the guint16 variable from the buffer */
        qmi_utils_read_guint16_from_buffer (
            &raw_data_aux_buffer,
            &raw_data_aux_buffer_len,
            QMI_ENDIAN_LITTLE,
            &(raw_data_n_items));
        for (raw_data_i = 0; raw_data_i < raw_data_n_items; raw_data_i++) {

            expected_len += 1;
        }
    }

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Transfer Route MT Message' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Transfer Route MT Message' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_indication_wms_event_report_output_transfer_route_mt_message_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_TRANSFER_ROUTE_MT_MESSAGE,
                                      &buffer_len);
    if (buffer && qmi_indication_wms_event_report_output_transfer_route_mt_message_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " ack_indicator = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_ACK_INDICATOR_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_ack_indicator_get_string ((QmiWmsAckIndicator)tmp));
#elif defined  __QMI_WMS_ACK_INDICATOR_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_ack_indicator_build_string_from_mask ((QmiWmsAckIndicator)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsAckIndicator
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " transaction_id = '");

        {
            guint32 tmp;

            /* Read the guint32 variable from the buffer */
            qmi_utils_read_guint32_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &tmp);

            g_string_append_printf (printable, "%" G_GUINT32_FORMAT "", tmp);
        }
        g_string_append (printable, "'");
        g_string_append (printable, " format = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_MESSAGE_FORMAT_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_message_format_get_string ((QmiWmsMessageFormat)tmp));
#elif defined  __QMI_WMS_MESSAGE_FORMAT_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_message_format_build_string_from_mask ((QmiWmsMessageFormat)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsMessageFormat
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " raw_data = '");
        {
            guint raw_data_i;
            guint16 raw_data_n_items;

            /* Read number of items in the array */
            /* Read the guint16 variable from the buffer */
            qmi_utils_read_guint16_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &(raw_data_n_items));

            g_string_append (printable, "{");

            for (raw_data_i = 0; raw_data_i < raw_data_n_items; raw_data_i++) {
                g_string_append_printf (printable, " [%u] = '", raw_data_i);

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);

                    g_string_append_printf (printable, "%u", (guint)tmp);
                }
                g_string_append (printable, " '");
            }

            g_string_append (printable, "}");
        }        g_string_append (printable, "'");
        g_string_append (printable, " ]");

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Transfer Route MT Message' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_indication_wms_event_report_output_mt_message_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;
    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'MT Message' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'MT Message' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_indication_wms_event_report_output_mt_message_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_MT_MESSAGE,
                                      &buffer_len);
    if (buffer && qmi_indication_wms_event_report_output_mt_message_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " storage_type = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_STORAGE_TYPE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_storage_type_get_string ((QmiWmsStorageType)tmp));
#elif defined  __QMI_WMS_STORAGE_TYPE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_storage_type_build_string_from_mask ((QmiWmsStorageType)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsStorageType
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " memory_index = '");

        {
            guint32 tmp;

            /* Read the guint32 variable from the buffer */
            qmi_utils_read_guint32_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &tmp);

            g_string_append_printf (printable, "%" G_GUINT32_FORMAT "", tmp);
        }
        g_string_append (printable, "'");
        g_string_append (printable, " ]");

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'MT Message' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct indication_event_report_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
indication_event_report_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct indication_event_report_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    {
        switch (type) {
        case QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_SMS_ON_IMS:
            tlv_type_str = "SMS on IMS";
            translated_value = qmi_indication_wms_event_report_output_sms_on_ims_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_SMSC_ADDRESS:
            tlv_type_str = "SMSC Address";
            translated_value = qmi_indication_wms_event_report_output_smsc_address_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_ETWS_PLMN_INFORMATION:
            tlv_type_str = "ETWS PLMN Information";
            translated_value = qmi_indication_wms_event_report_output_etws_plmn_information_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_ETWS_MESSAGE:
            tlv_type_str = "ETWS Message";
            translated_value = qmi_indication_wms_event_report_output_etws_message_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_MESSAGE_MODE:
            tlv_type_str = "Message Mode";
            translated_value = qmi_indication_wms_event_report_output_message_mode_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_TRANSFER_ROUTE_MT_MESSAGE:
            tlv_type_str = "Transfer Route MT Message";
            translated_value = qmi_indication_wms_event_report_output_transfer_route_mt_message_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_MT_MESSAGE:
            tlv_type_str = "MT Message";
            translated_value = qmi_indication_wms_event_report_output_mt_message_get_printable (
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
indication_event_report_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Event Report\" (0x0001)\n",
                            line_prefix);

    {
        struct indication_event_report_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)indication_event_report_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiIndicationWmsEventReportOutput *
__qmi_indication_wms_event_report_indication_parse (
    QmiMessage *message,
    GError **error)
{
    QmiIndicationWmsEventReportOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_INDICATION_WMS_EVENT_REPORT, NULL);

    self = g_slice_new0 (QmiIndicationWmsEventReportOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_SMS_ON_IMS,
                                              &buffer_len);
            if (buffer && qmi_indication_wms_event_report_output_sms_on_ims_validate (buffer, buffer_len)) {
                self->arg_sms_on_ims_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_sms_on_ims = (gboolean)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'SMS on IMS' TLV", buffer_len);
                }
            }

        }
    } while (0);

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_SMSC_ADDRESS,
                                              &buffer_len);
            if (buffer && qmi_indication_wms_event_report_output_smsc_address_validate (buffer, buffer_len)) {
                self->arg_smsc_address_set = TRUE;

                /* Read the string variable from the buffer */
                qmi_utils_read_string_from_buffer (
                    &buffer,
                    &buffer_len,
                    0,
                    0,
                    &(self->arg_smsc_address));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'SMSC Address' TLV", buffer_len);
                }
            }

        }
    } while (0);

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_ETWS_PLMN_INFORMATION,
                                              &buffer_len);
            if (buffer && qmi_indication_wms_event_report_output_etws_plmn_information_validate (buffer, buffer_len)) {
                self->arg_etws_plmn_information_set = TRUE;

                /* Read the guint16 variable from the buffer */
                qmi_utils_read_guint16_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_etws_plmn_information_mcc));
                /* Read the guint16 variable from the buffer */
                qmi_utils_read_guint16_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_etws_plmn_information_mnc));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'ETWS PLMN Information' TLV", buffer_len);
                }
            }

        }
    } while (0);

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_ETWS_MESSAGE,
                                              &buffer_len);
            if (buffer && qmi_indication_wms_event_report_output_etws_message_validate (buffer, buffer_len)) {
                self->arg_etws_message_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_etws_message_notification_type = (QmiWmsNotificationType)tmp;
                }
                {
                    guint raw_data_i;
                    guint16 raw_data_n_items;

                    /* Read number of items in the array */
                    /* Read the guint16 variable from the buffer */
                    qmi_utils_read_guint16_from_buffer (
                        &buffer,
                        &buffer_len,
                        QMI_ENDIAN_LITTLE,
                        &(raw_data_n_items));

                    self->arg_etws_message_raw_data = g_array_sized_new (
                        FALSE,
                        FALSE,
                        sizeof (guint8),
                        (guint)raw_data_n_items);

                    for (raw_data_i = 0; raw_data_i < raw_data_n_items; raw_data_i++) {
                        guint8 raw_data_aux;

                        /* Read the guint8 variable from the buffer */
                        qmi_utils_read_guint8_from_buffer (
                            &buffer,
                            &buffer_len,
                            &(raw_data_aux));
                        g_array_insert_val (self->arg_etws_message_raw_data, raw_data_i, raw_data_aux);
                    }
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'ETWS Message' TLV", buffer_len);
                }
            }

        }
    } while (0);

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_MESSAGE_MODE,
                                              &buffer_len);
            if (buffer && qmi_indication_wms_event_report_output_message_mode_validate (buffer, buffer_len)) {
                self->arg_message_mode_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_message_mode = (QmiWmsMessageMode)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Message Mode' TLV", buffer_len);
                }
            }

        }
    } while (0);

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_TRANSFER_ROUTE_MT_MESSAGE,
                                              &buffer_len);
            if (buffer && qmi_indication_wms_event_report_output_transfer_route_mt_message_validate (buffer, buffer_len)) {
                self->arg_transfer_route_mt_message_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_transfer_route_mt_message_ack_indicator = (QmiWmsAckIndicator)tmp;
                }
                /* Read the guint32 variable from the buffer */
                qmi_utils_read_guint32_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_transfer_route_mt_message_transaction_id));
                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_transfer_route_mt_message_format = (QmiWmsMessageFormat)tmp;
                }
                {
                    guint raw_data_i;
                    guint16 raw_data_n_items;

                    /* Read number of items in the array */
                    /* Read the guint16 variable from the buffer */
                    qmi_utils_read_guint16_from_buffer (
                        &buffer,
                        &buffer_len,
                        QMI_ENDIAN_LITTLE,
                        &(raw_data_n_items));

                    self->arg_transfer_route_mt_message_raw_data = g_array_sized_new (
                        FALSE,
                        FALSE,
                        sizeof (guint8),
                        (guint)raw_data_n_items);

                    for (raw_data_i = 0; raw_data_i < raw_data_n_items; raw_data_i++) {
                        guint8 raw_data_aux;

                        /* Read the guint8 variable from the buffer */
                        qmi_utils_read_guint8_from_buffer (
                            &buffer,
                            &buffer_len,
                            &(raw_data_aux));
                        g_array_insert_val (self->arg_transfer_route_mt_message_raw_data, raw_data_i, raw_data_aux);
                    }
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Transfer Route MT Message' TLV", buffer_len);
                }
            }

        }
    } while (0);

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_INDICATION_WMS_EVENT_REPORT_OUTPUT_TLV_MT_MESSAGE,
                                              &buffer_len);
            if (buffer && qmi_indication_wms_event_report_output_mt_message_validate (buffer, buffer_len)) {
                self->arg_mt_message_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_mt_message_storage_type = (QmiWmsStorageType)tmp;
                }
                /* Read the guint32 variable from the buffer */
                qmi_utils_read_guint32_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_mt_message_memory_index));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'MT Message' TLV", buffer_len);
                }
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WMS Raw Send */


/* --- Input -- */

struct _QmiMessageWmsRawSendInput {
    volatile gint ref_count;

    /* SMS on IMS */
    gboolean arg_sms_on_ims_set;
    guint8 arg_sms_on_ims;

    /* GSM WCDMA Link Timer */
    gboolean arg_gsm_wcdma_link_timer_set;
    guint8 arg_gsm_wcdma_link_timer;

    /* CDMA Follow On DC */
    gboolean arg_cdma_follow_on_dc_set;
    guint8 arg_cdma_follow_on_dc_follow;

    /* CDMA Force On DC */
    gboolean arg_cdma_force_on_dc_set;
    guint8 arg_cdma_force_on_dc_force;
    guint8 arg_cdma_force_on_dc_service_option;

    /* Raw Message Data */
    gboolean arg_raw_message_data_set;
    guint8 arg_raw_message_data_format;
    GArray *arg_raw_message_data_raw_data;
};

#define QMI_MESSAGE_WMS_RAW_SEND_INPUT_TLV_SMS_ON_IMS 0x13
#define QMI_MESSAGE_WMS_RAW_SEND_INPUT_TLV_GSM_WCDMA_LINK_TIMER 0x12
#define QMI_MESSAGE_WMS_RAW_SEND_INPUT_TLV_CDMA_FOLLOW_ON_DC 0x11
#define QMI_MESSAGE_WMS_RAW_SEND_INPUT_TLV_CDMA_FORCE_ON_DC 0x10
#define QMI_MESSAGE_WMS_RAW_SEND_INPUT_TLV_RAW_MESSAGE_DATA 0x01

/**
 * qmi_message_wms_raw_send_input_get_sms_on_ims:
 * @self: a #QmiMessageWmsRawSendInput.
 * @sms_on_ims: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'SMS on IMS' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_send_input_get_sms_on_ims (
    QmiMessageWmsRawSendInput *self,
    gboolean *sms_on_ims,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_sms_on_ims_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'SMS on IMS' was not found in the message");
        return FALSE;
    }

    if (sms_on_ims)
        *sms_on_ims = (gboolean)(self->arg_sms_on_ims);

    return TRUE;
}

/**
 * qmi_message_wms_raw_send_input_set_sms_on_ims:
 * @self: a #QmiMessageWmsRawSendInput.
 * @sms_on_ims: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'SMS on IMS' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_send_input_set_sms_on_ims (
    QmiMessageWmsRawSendInput *self,
    gboolean sms_on_ims,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_sms_on_ims = (guint8)(sms_on_ims);
    self->arg_sms_on_ims_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wms_raw_send_input_get_gsm_wcdma_link_timer:
 * @self: a #QmiMessageWmsRawSendInput.
 * @gsm_wcdma_link_timer: a placeholder for the output #guint8, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'GSM WCDMA Link Timer' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_send_input_get_gsm_wcdma_link_timer (
    QmiMessageWmsRawSendInput *self,
    guint8 *gsm_wcdma_link_timer,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_gsm_wcdma_link_timer_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'GSM WCDMA Link Timer' was not found in the message");
        return FALSE;
    }

    if (gsm_wcdma_link_timer)
        *gsm_wcdma_link_timer = self->arg_gsm_wcdma_link_timer;

    return TRUE;
}

/**
 * qmi_message_wms_raw_send_input_set_gsm_wcdma_link_timer:
 * @self: a #QmiMessageWmsRawSendInput.
 * @gsm_wcdma_link_timer: a #guint8.
 * @error: Return location for error or %NULL.
 *
 * Set the 'GSM WCDMA Link Timer' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_send_input_set_gsm_wcdma_link_timer (
    QmiMessageWmsRawSendInput *self,
    guint8 gsm_wcdma_link_timer,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_gsm_wcdma_link_timer = gsm_wcdma_link_timer;
    self->arg_gsm_wcdma_link_timer_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wms_raw_send_input_get_cdma_follow_on_dc:
 * @self: a #QmiMessageWmsRawSendInput.
 * @cdma_follow_on_dc_follow: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'CDMA Follow On DC' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_send_input_get_cdma_follow_on_dc (
    QmiMessageWmsRawSendInput *self,
    gboolean *cdma_follow_on_dc_follow,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_cdma_follow_on_dc_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'CDMA Follow On DC' was not found in the message");
        return FALSE;
    }

    if (cdma_follow_on_dc_follow)
        *cdma_follow_on_dc_follow = (gboolean)(self->arg_cdma_follow_on_dc_follow);

    return TRUE;
}

/**
 * qmi_message_wms_raw_send_input_set_cdma_follow_on_dc:
 * @self: a #QmiMessageWmsRawSendInput.
 * @cdma_follow_on_dc_follow: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'CDMA Follow On DC' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_send_input_set_cdma_follow_on_dc (
    QmiMessageWmsRawSendInput *self,
    gboolean cdma_follow_on_dc_follow,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_cdma_follow_on_dc_follow = (guint8)(cdma_follow_on_dc_follow);
    self->arg_cdma_follow_on_dc_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wms_raw_send_input_get_cdma_force_on_dc:
 * @self: a #QmiMessageWmsRawSendInput.
 * @cdma_force_on_dc_force: a placeholder for the output #gboolean, or %NULL if not required.
 * @cdma_force_on_dc_service_option: a placeholder for the output #QmiWmsCdmaServiceOption, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'CDMA Force On DC' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_send_input_get_cdma_force_on_dc (
    QmiMessageWmsRawSendInput *self,
    gboolean *cdma_force_on_dc_force,
    QmiWmsCdmaServiceOption *cdma_force_on_dc_service_option,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_cdma_force_on_dc_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'CDMA Force On DC' was not found in the message");
        return FALSE;
    }

    if (cdma_force_on_dc_force)
        *cdma_force_on_dc_force = (gboolean)(self->arg_cdma_force_on_dc_force);
    if (cdma_force_on_dc_service_option)
        *cdma_force_on_dc_service_option = (QmiWmsCdmaServiceOption)(self->arg_cdma_force_on_dc_service_option);

    return TRUE;
}

/**
 * qmi_message_wms_raw_send_input_set_cdma_force_on_dc:
 * @self: a #QmiMessageWmsRawSendInput.
 * @cdma_force_on_dc_force: a #gboolean.
 * @cdma_force_on_dc_service_option: a #QmiWmsCdmaServiceOption.
 * @error: Return location for error or %NULL.
 *
 * Set the 'CDMA Force On DC' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_send_input_set_cdma_force_on_dc (
    QmiMessageWmsRawSendInput *self,
    gboolean cdma_force_on_dc_force,
    QmiWmsCdmaServiceOption cdma_force_on_dc_service_option,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_cdma_force_on_dc_force = (guint8)(cdma_force_on_dc_force);
    self->arg_cdma_force_on_dc_service_option = (guint8)(cdma_force_on_dc_service_option);
    self->arg_cdma_force_on_dc_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wms_raw_send_input_get_raw_message_data:
 * @self: a #QmiMessageWmsRawSendInput.
 * @raw_message_data_format: a placeholder for the output #QmiWmsMessageFormat, or %NULL if not required.
 * @raw_message_data_raw_data: a placeholder for the output #GArray of #guint8 elements, or %NULL if not required. Do not free it, it is owned by @self.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Raw Message Data' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_send_input_get_raw_message_data (
    QmiMessageWmsRawSendInput *self,
    QmiWmsMessageFormat *raw_message_data_format,
    GArray **raw_message_data_raw_data,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_raw_message_data_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Raw Message Data' was not found in the message");
        return FALSE;
    }

    if (raw_message_data_format)
        *raw_message_data_format = (QmiWmsMessageFormat)(self->arg_raw_message_data_format);
    if (raw_message_data_raw_data)
        *raw_message_data_raw_data = self->arg_raw_message_data_raw_data;

    return TRUE;
}

/**
 * qmi_message_wms_raw_send_input_set_raw_message_data:
 * @self: a #QmiMessageWmsRawSendInput.
 * @raw_message_data_format: a #QmiWmsMessageFormat.
 * @raw_message_data_raw_data: a #GArray of #guint8 elements. A new reference to @raw_message_data_raw_data will be taken.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Raw Message Data' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_send_input_set_raw_message_data (
    QmiMessageWmsRawSendInput *self,
    QmiWmsMessageFormat raw_message_data_format,
    GArray *raw_message_data_raw_data,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_raw_message_data_format = (guint8)(raw_message_data_format);
    if (self->arg_raw_message_data_raw_data)
        g_array_unref (self->arg_raw_message_data_raw_data);
    self->arg_raw_message_data_raw_data = g_array_ref (raw_message_data_raw_data);
    self->arg_raw_message_data_set = TRUE;

    return TRUE;
}

GType
qmi_message_wms_raw_send_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsRawSendInput"),
                                          (GBoxedCopyFunc) qmi_message_wms_raw_send_input_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_raw_send_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_raw_send_input_ref:
 * @self: a #QmiMessageWmsRawSendInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsRawSendInput *
qmi_message_wms_raw_send_input_ref (QmiMessageWmsRawSendInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_raw_send_input_unref:
 * @self: a #QmiMessageWmsRawSendInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_raw_send_input_unref (QmiMessageWmsRawSendInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        if (self->arg_raw_message_data_raw_data)
            g_array_unref (self->arg_raw_message_data_raw_data);
        g_slice_free (QmiMessageWmsRawSendInput, self);
    }
}

/**
 * qmi_message_wms_raw_send_input_new:
 *
 * Allocates a new #QmiMessageWmsRawSendInput.
 *
 * Returns: the newly created #QmiMessageWmsRawSendInput. The returned value should be freed with qmi_message_wms_raw_send_input_unref().
 */
QmiMessageWmsRawSendInput *
qmi_message_wms_raw_send_input_new (void)
{
    QmiMessageWmsRawSendInput *self;

    self = g_slice_new0 (QmiMessageWmsRawSendInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_wms_raw_send_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessageWmsRawSendInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WMS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WMS_RAW_SEND);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Raw Send' has mandatory TLVs");
        qmi_message_unref (self);
        return NULL;
    }

    /* Try to add the 'SMS on IMS' TLV */
    if (input->arg_sms_on_ims_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_sms_on_ims;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_RAW_SEND_INPUT_TLV_SMS_ON_IMS,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the SMS on IMS TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'GSM WCDMA Link Timer' TLV */
    if (input->arg_gsm_wcdma_link_timer_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        /* Write the guint8 variable to the buffer */
        qmi_utils_write_guint8_to_buffer (
            &buffer_aux,
            &buffer_len,
            &(input->arg_gsm_wcdma_link_timer));

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_RAW_SEND_INPUT_TLV_GSM_WCDMA_LINK_TIMER,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the GSM WCDMA Link Timer TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'CDMA Follow On DC' TLV */
    if (input->arg_cdma_follow_on_dc_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_cdma_follow_on_dc_follow;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_RAW_SEND_INPUT_TLV_CDMA_FOLLOW_ON_DC,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the CDMA Follow On DC TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'CDMA Force On DC' TLV */
    if (input->arg_cdma_force_on_dc_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_cdma_force_on_dc_force;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }
        {
            guint8 tmp;

            tmp = (guint8)input->arg_cdma_force_on_dc_service_option;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_RAW_SEND_INPUT_TLV_CDMA_FORCE_ON_DC,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the CDMA Force On DC TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Raw Message Data' TLV */
    if (input->arg_raw_message_data_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_raw_message_data_format;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }
        {
            guint raw_data_i;
            guint16 raw_data_n_items;

            /* Write the number of items in the array first */
            raw_data_n_items = (guint16) input->arg_raw_message_data_raw_data->len;
            /* Write the guint16 variable to the buffer */
            qmi_utils_write_guint16_to_buffer (
                &buffer_aux,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &(raw_data_n_items));

            for (raw_data_i = 0; raw_data_i < input->arg_raw_message_data_raw_data->len; raw_data_i++) {
                /* Write the guint8 variable to the buffer */
                qmi_utils_write_guint8_to_buffer (
                    &buffer_aux,
                    &buffer_len,
                    &(g_array_index (input->arg_raw_message_data_raw_data, guint8,raw_data_i)));
            }
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_RAW_SEND_INPUT_TLV_RAW_MESSAGE_DATA,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Raw Message Data TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'Raw Message Data' in message 'Raw Send'");
        qmi_message_unref (self);
        return NULL;
    }

    return self;
}

/* --- Output -- */

struct _QmiMessageWmsRawSendOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Message ID */
    gboolean arg_message_id_set;
    guint16 arg_message_id;

    /* CDMA Cause Code */
    gboolean arg_cdma_cause_code_set;
    guint16 arg_cdma_cause_code;

    /* CDMA Error Class */
    gboolean arg_cdma_error_class_set;
    guint8 arg_cdma_error_class;

    /* GSM WCDMA Cause Info */
    gboolean arg_gsm_wcdma_cause_info_set;
    guint16 arg_gsm_wcdma_cause_info_rp_cause;
    guint8 arg_gsm_wcdma_cause_info_tp_cause;

    /* Message Delivery Failure Type */
    gboolean arg_message_delivery_failure_type_set;
    guint8 arg_message_delivery_failure_type;
};

#define QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_MESSAGE_ID 0x01
#define QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_CDMA_CAUSE_CODE 0x10
#define QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_CDMA_ERROR_CLASS 0x11
#define QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_GSM_WCDMA_CAUSE_INFO 0x12
#define QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_MESSAGE_DELIVERY_FAILURE_TYPE 0x13

/**
 * qmi_message_wms_raw_send_output_get_result:
 * @self: a QmiMessageWmsRawSendOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wms_raw_send_output_get_result (
    QmiMessageWmsRawSendOutput *self,
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
 * qmi_message_wms_raw_send_output_get_message_id:
 * @self: a #QmiMessageWmsRawSendOutput.
 * @message_id: a placeholder for the output #guint16, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Message ID' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_send_output_get_message_id (
    QmiMessageWmsRawSendOutput *self,
    guint16 *message_id,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_message_id_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Message ID' was not found in the message");
        return FALSE;
    }

    if (message_id)
        *message_id = self->arg_message_id;

    return TRUE;
}

/**
 * qmi_message_wms_raw_send_output_get_cdma_cause_code:
 * @self: a #QmiMessageWmsRawSendOutput.
 * @cdma_cause_code: a placeholder for the output #QmiWmsCdmaCauseCode, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'CDMA Cause Code' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_send_output_get_cdma_cause_code (
    QmiMessageWmsRawSendOutput *self,
    QmiWmsCdmaCauseCode *cdma_cause_code,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_cdma_cause_code_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'CDMA Cause Code' was not found in the message");
        return FALSE;
    }

    if (cdma_cause_code)
        *cdma_cause_code = (QmiWmsCdmaCauseCode)(self->arg_cdma_cause_code);

    return TRUE;
}

/**
 * qmi_message_wms_raw_send_output_get_cdma_error_class:
 * @self: a #QmiMessageWmsRawSendOutput.
 * @cdma_error_class: a placeholder for the output #QmiWmsCdmaErrorClass, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'CDMA Error Class' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_send_output_get_cdma_error_class (
    QmiMessageWmsRawSendOutput *self,
    QmiWmsCdmaErrorClass *cdma_error_class,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_cdma_error_class_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'CDMA Error Class' was not found in the message");
        return FALSE;
    }

    if (cdma_error_class)
        *cdma_error_class = (QmiWmsCdmaErrorClass)(self->arg_cdma_error_class);

    return TRUE;
}

/**
 * qmi_message_wms_raw_send_output_get_gsm_wcdma_cause_info:
 * @self: a #QmiMessageWmsRawSendOutput.
 * @gsm_wcdma_cause_info_rp_cause: a placeholder for the output #QmiWmsGsmUmtsRpCause, or %NULL if not required.
 * @gsm_wcdma_cause_info_tp_cause: a placeholder for the output #QmiWmsGsmUmtsTpCause, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'GSM WCDMA Cause Info' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_send_output_get_gsm_wcdma_cause_info (
    QmiMessageWmsRawSendOutput *self,
    QmiWmsGsmUmtsRpCause *gsm_wcdma_cause_info_rp_cause,
    QmiWmsGsmUmtsTpCause *gsm_wcdma_cause_info_tp_cause,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_gsm_wcdma_cause_info_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'GSM WCDMA Cause Info' was not found in the message");
        return FALSE;
    }

    if (gsm_wcdma_cause_info_rp_cause)
        *gsm_wcdma_cause_info_rp_cause = (QmiWmsGsmUmtsRpCause)(self->arg_gsm_wcdma_cause_info_rp_cause);
    if (gsm_wcdma_cause_info_tp_cause)
        *gsm_wcdma_cause_info_tp_cause = (QmiWmsGsmUmtsTpCause)(self->arg_gsm_wcdma_cause_info_tp_cause);

    return TRUE;
}

/**
 * qmi_message_wms_raw_send_output_get_message_delivery_failure_type:
 * @self: a #QmiMessageWmsRawSendOutput.
 * @message_delivery_failure_type: a placeholder for the output #QmiWmsMessageDeliveryFailureType, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Message Delivery Failure Type' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_send_output_get_message_delivery_failure_type (
    QmiMessageWmsRawSendOutput *self,
    QmiWmsMessageDeliveryFailureType *message_delivery_failure_type,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_message_delivery_failure_type_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Message Delivery Failure Type' was not found in the message");
        return FALSE;
    }

    if (message_delivery_failure_type)
        *message_delivery_failure_type = (QmiWmsMessageDeliveryFailureType)(self->arg_message_delivery_failure_type);

    return TRUE;
}

GType
qmi_message_wms_raw_send_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsRawSendOutput"),
                                          (GBoxedCopyFunc) qmi_message_wms_raw_send_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_raw_send_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_raw_send_output_ref:
 * @self: a #QmiMessageWmsRawSendOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsRawSendOutput *
qmi_message_wms_raw_send_output_ref (QmiMessageWmsRawSendOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_raw_send_output_unref:
 * @self: a #QmiMessageWmsRawSendOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_raw_send_output_unref (QmiMessageWmsRawSendOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWmsRawSendOutput, self);
    }
}

static gboolean
qmi_message_wms_raw_send_input_sms_on_ims_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'SMS on IMS' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'SMS on IMS' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_raw_send_input_sms_on_ims_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_RAW_SEND_INPUT_TLV_SMS_ON_IMS,
                                      &buffer_len);
    if (buffer && qmi_message_wms_raw_send_input_sms_on_ims_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

            g_string_append_printf (printable, "%s", tmp ? "yes" : "no");
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'SMS on IMS' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_raw_send_input_gsm_wcdma_link_timer_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'GSM WCDMA Link Timer' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'GSM WCDMA Link Timer' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_raw_send_input_gsm_wcdma_link_timer_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_RAW_SEND_INPUT_TLV_GSM_WCDMA_LINK_TIMER,
                                      &buffer_len);
    if (buffer && qmi_message_wms_raw_send_input_gsm_wcdma_link_timer_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'GSM WCDMA Link Timer' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_raw_send_input_cdma_follow_on_dc_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'CDMA Follow On DC' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'CDMA Follow On DC' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_raw_send_input_cdma_follow_on_dc_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_RAW_SEND_INPUT_TLV_CDMA_FOLLOW_ON_DC,
                                      &buffer_len);
    if (buffer && qmi_message_wms_raw_send_input_cdma_follow_on_dc_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " follow = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

            g_string_append_printf (printable, "%s", tmp ? "yes" : "no");
        }
        g_string_append (printable, "'");
        g_string_append (printable, " ]");

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'CDMA Follow On DC' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_raw_send_input_cdma_force_on_dc_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;
    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'CDMA Force On DC' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'CDMA Force On DC' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_raw_send_input_cdma_force_on_dc_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_RAW_SEND_INPUT_TLV_CDMA_FORCE_ON_DC,
                                      &buffer_len);
    if (buffer && qmi_message_wms_raw_send_input_cdma_force_on_dc_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " force = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

            g_string_append_printf (printable, "%s", tmp ? "yes" : "no");
        }
        g_string_append (printable, "'");
        g_string_append (printable, " service_option = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_CDMA_SERVICE_OPTION_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_cdma_service_option_get_string ((QmiWmsCdmaServiceOption)tmp));
#elif defined  __QMI_WMS_CDMA_SERVICE_OPTION_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_cdma_service_option_build_string_from_mask ((QmiWmsCdmaServiceOption)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsCdmaServiceOption
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " ]");

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'CDMA Force On DC' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_raw_send_input_raw_message_data_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;
    {
        guint raw_data_i;
        guint16 raw_data_n_items;
        const guint8 *raw_data_aux_buffer = &buffer[expected_len];
        guint16 raw_data_aux_buffer_len = buffer_len - expected_len;

        expected_len += 2;

        /* Read the guint16 variable from the buffer */
        qmi_utils_read_guint16_from_buffer (
            &raw_data_aux_buffer,
            &raw_data_aux_buffer_len,
            QMI_ENDIAN_LITTLE,
            &(raw_data_n_items));
        for (raw_data_i = 0; raw_data_i < raw_data_n_items; raw_data_i++) {

            expected_len += 1;
        }
    }

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Raw Message Data' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Raw Message Data' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_raw_send_input_raw_message_data_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_RAW_SEND_INPUT_TLV_RAW_MESSAGE_DATA,
                                      &buffer_len);
    if (buffer && qmi_message_wms_raw_send_input_raw_message_data_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " format = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_MESSAGE_FORMAT_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_message_format_get_string ((QmiWmsMessageFormat)tmp));
#elif defined  __QMI_WMS_MESSAGE_FORMAT_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_message_format_build_string_from_mask ((QmiWmsMessageFormat)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsMessageFormat
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " raw_data = '");
        {
            guint raw_data_i;
            guint16 raw_data_n_items;

            /* Read number of items in the array */
            /* Read the guint16 variable from the buffer */
            qmi_utils_read_guint16_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &(raw_data_n_items));

            g_string_append (printable, "{");

            for (raw_data_i = 0; raw_data_i < raw_data_n_items; raw_data_i++) {
                g_string_append_printf (printable, " [%u] = '", raw_data_i);

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);

                    g_string_append_printf (printable, "%u", (guint)tmp);
                }
                g_string_append (printable, " '");
            }

            g_string_append (printable, "}");
        }        g_string_append (printable, "'");
        g_string_append (printable, " ]");

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Raw Message Data' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_raw_send_output_message_id_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 2;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Message ID' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Message ID' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_raw_send_output_message_id_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_MESSAGE_ID,
                                      &buffer_len);
    if (buffer && qmi_message_wms_raw_send_output_message_id_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Message ID' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_raw_send_output_cdma_cause_code_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 2;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'CDMA Cause Code' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'CDMA Cause Code' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_raw_send_output_cdma_cause_code_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_CDMA_CAUSE_CODE,
                                      &buffer_len);
    if (buffer && qmi_message_wms_raw_send_output_cdma_cause_code_validate (buffer, buffer_len)) {
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

#if defined  __QMI_WMS_CDMA_CAUSE_CODE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_cdma_cause_code_get_string ((QmiWmsCdmaCauseCode)tmp));
#elif defined  __QMI_WMS_CDMA_CAUSE_CODE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_cdma_cause_code_build_string_from_mask ((QmiWmsCdmaCauseCode)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsCdmaCauseCode
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'CDMA Cause Code' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_raw_send_output_cdma_error_class_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'CDMA Error Class' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'CDMA Error Class' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_raw_send_output_cdma_error_class_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_CDMA_ERROR_CLASS,
                                      &buffer_len);
    if (buffer && qmi_message_wms_raw_send_output_cdma_error_class_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_CDMA_ERROR_CLASS_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_cdma_error_class_get_string ((QmiWmsCdmaErrorClass)tmp));
#elif defined  __QMI_WMS_CDMA_ERROR_CLASS_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_cdma_error_class_build_string_from_mask ((QmiWmsCdmaErrorClass)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsCdmaErrorClass
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'CDMA Error Class' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_raw_send_output_gsm_wcdma_cause_info_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 2;
    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'GSM WCDMA Cause Info' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'GSM WCDMA Cause Info' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_raw_send_output_gsm_wcdma_cause_info_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_GSM_WCDMA_CAUSE_INFO,
                                      &buffer_len);
    if (buffer && qmi_message_wms_raw_send_output_gsm_wcdma_cause_info_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " rp_cause = '");

        {
            guint16 tmp;

            /* Read the guint16 variable from the buffer */
            qmi_utils_read_guint16_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &tmp);

#if defined  __QMI_WMS_GSM_UMTS_RP_CAUSE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_gsm_umts_rp_cause_get_string ((QmiWmsGsmUmtsRpCause)tmp));
#elif defined  __QMI_WMS_GSM_UMTS_RP_CAUSE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_gsm_umts_rp_cause_build_string_from_mask ((QmiWmsGsmUmtsRpCause)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsGsmUmtsRpCause
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " tp_cause = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_GSM_UMTS_TP_CAUSE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_gsm_umts_tp_cause_get_string ((QmiWmsGsmUmtsTpCause)tmp));
#elif defined  __QMI_WMS_GSM_UMTS_TP_CAUSE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_gsm_umts_tp_cause_build_string_from_mask ((QmiWmsGsmUmtsTpCause)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsGsmUmtsTpCause
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " ]");

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'GSM WCDMA Cause Info' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_raw_send_output_message_delivery_failure_type_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Message Delivery Failure Type' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Message Delivery Failure Type' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_raw_send_output_message_delivery_failure_type_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_MESSAGE_DELIVERY_FAILURE_TYPE,
                                      &buffer_len);
    if (buffer && qmi_message_wms_raw_send_output_message_delivery_failure_type_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_MESSAGE_DELIVERY_FAILURE_TYPE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_message_delivery_failure_type_get_string ((QmiWmsMessageDeliveryFailureType)tmp));
#elif defined  __QMI_WMS_MESSAGE_DELIVERY_FAILURE_TYPE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_message_delivery_failure_type_build_string_from_mask ((QmiWmsMessageDeliveryFailureType)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsMessageDeliveryFailureType
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Message Delivery Failure Type' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_raw_send_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_raw_send_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_raw_send_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_WMS_RAW_SEND_INPUT_TLV_SMS_ON_IMS:
            tlv_type_str = "SMS on IMS";
            translated_value = qmi_message_wms_raw_send_input_sms_on_ims_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_RAW_SEND_INPUT_TLV_GSM_WCDMA_LINK_TIMER:
            tlv_type_str = "GSM WCDMA Link Timer";
            translated_value = qmi_message_wms_raw_send_input_gsm_wcdma_link_timer_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_RAW_SEND_INPUT_TLV_CDMA_FOLLOW_ON_DC:
            tlv_type_str = "CDMA Follow On DC";
            translated_value = qmi_message_wms_raw_send_input_cdma_follow_on_dc_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_RAW_SEND_INPUT_TLV_CDMA_FORCE_ON_DC:
            tlv_type_str = "CDMA Force On DC";
            translated_value = qmi_message_wms_raw_send_input_cdma_force_on_dc_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_RAW_SEND_INPUT_TLV_RAW_MESSAGE_DATA:
            tlv_type_str = "Raw Message Data";
            translated_value = qmi_message_wms_raw_send_input_raw_message_data_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_MESSAGE_ID:
            tlv_type_str = "Message ID";
            translated_value = qmi_message_wms_raw_send_output_message_id_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_CDMA_CAUSE_CODE:
            tlv_type_str = "CDMA Cause Code";
            translated_value = qmi_message_wms_raw_send_output_cdma_cause_code_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_CDMA_ERROR_CLASS:
            tlv_type_str = "CDMA Error Class";
            translated_value = qmi_message_wms_raw_send_output_cdma_error_class_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_GSM_WCDMA_CAUSE_INFO:
            tlv_type_str = "GSM WCDMA Cause Info";
            translated_value = qmi_message_wms_raw_send_output_gsm_wcdma_cause_info_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_MESSAGE_DELIVERY_FAILURE_TYPE:
            tlv_type_str = "Message Delivery Failure Type";
            translated_value = qmi_message_wms_raw_send_output_message_delivery_failure_type_get_printable (
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
message_raw_send_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Raw Send\" (0x0020)\n",
                            line_prefix);

    {
        struct message_raw_send_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_raw_send_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageWmsRawSendOutput *
__qmi_message_wms_raw_send_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWmsRawSendOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WMS_RAW_SEND, NULL);

    self = g_slice_new0 (QmiMessageWmsRawSendOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_RESULT,
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
                qmi_message_wms_raw_send_output_unref (self);
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
                                              QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_MESSAGE_ID,
                                              &buffer_len);
            if (buffer && qmi_message_wms_raw_send_output_message_id_validate (buffer, buffer_len)) {
                self->arg_message_id_set = TRUE;

                /* Read the guint16 variable from the buffer */
                qmi_utils_read_guint16_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_message_id));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Message ID' TLV", buffer_len);
                }
            }

        }
    } while (0);

    do {
        /* Prerequisite.... */
        if (!(self->arg_result.error_status != QMI_STATUS_SUCCESS))
            break;
        /* Prerequisite.... */
        if (!(self->arg_result.error_code == QMI_PROTOCOL_ERROR_WMS_CAUSE_CODE))
            break;

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_CDMA_CAUSE_CODE,
                                              &buffer_len);
            if (buffer && qmi_message_wms_raw_send_output_cdma_cause_code_validate (buffer, buffer_len)) {
                self->arg_cdma_cause_code_set = TRUE;

                {
                    guint16 tmp;

                    /* Read the guint16 variable from the buffer */
                    qmi_utils_read_guint16_from_buffer (
                        &buffer,
                        &buffer_len,
                        QMI_ENDIAN_LITTLE,
                        &tmp);
                    self->arg_cdma_cause_code = (QmiWmsCdmaCauseCode)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'CDMA Cause Code' TLV", buffer_len);
                }
            }

        }
    } while (0);

    do {
        /* Prerequisite.... */
        if (!(self->arg_result.error_status != QMI_STATUS_SUCCESS))
            break;
        /* Prerequisite.... */
        if (!(self->arg_result.error_code == QMI_PROTOCOL_ERROR_WMS_CAUSE_CODE))
            break;

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_CDMA_ERROR_CLASS,
                                              &buffer_len);
            if (buffer && qmi_message_wms_raw_send_output_cdma_error_class_validate (buffer, buffer_len)) {
                self->arg_cdma_error_class_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_cdma_error_class = (QmiWmsCdmaErrorClass)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'CDMA Error Class' TLV", buffer_len);
                }
            }

        }
    } while (0);

    do {
        /* Prerequisite.... */
        if (!(self->arg_result.error_status != QMI_STATUS_SUCCESS))
            break;
        /* Prerequisite.... */
        if (!(self->arg_result.error_code == QMI_PROTOCOL_ERROR_WMS_CAUSE_CODE))
            break;

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_GSM_WCDMA_CAUSE_INFO,
                                              &buffer_len);
            if (buffer && qmi_message_wms_raw_send_output_gsm_wcdma_cause_info_validate (buffer, buffer_len)) {
                self->arg_gsm_wcdma_cause_info_set = TRUE;

                {
                    guint16 tmp;

                    /* Read the guint16 variable from the buffer */
                    qmi_utils_read_guint16_from_buffer (
                        &buffer,
                        &buffer_len,
                        QMI_ENDIAN_LITTLE,
                        &tmp);
                    self->arg_gsm_wcdma_cause_info_rp_cause = (QmiWmsGsmUmtsRpCause)tmp;
                }
                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_gsm_wcdma_cause_info_tp_cause = (QmiWmsGsmUmtsTpCause)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'GSM WCDMA Cause Info' TLV", buffer_len);
                }
            }

        }
    } while (0);

    do {
        /* Prerequisite.... */
        if (!(self->arg_result.error_status != QMI_STATUS_SUCCESS))
            break;
        /* Prerequisite.... */
        if (!(self->arg_result.error_code == QMI_PROTOCOL_ERROR_WMS_CAUSE_CODE))
            break;

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WMS_RAW_SEND_OUTPUT_TLV_MESSAGE_DELIVERY_FAILURE_TYPE,
                                              &buffer_len);
            if (buffer && qmi_message_wms_raw_send_output_message_delivery_failure_type_validate (buffer, buffer_len)) {
                self->arg_message_delivery_failure_type_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_message_delivery_failure_type = (QmiWmsMessageDeliveryFailureType)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Message Delivery Failure Type' TLV", buffer_len);
                }
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WMS Raw Write */


/* --- Input -- */

struct _QmiMessageWmsRawWriteInput {
    volatile gint ref_count;

    /* Raw Message Data */
    gboolean arg_raw_message_data_set;
    guint8 arg_raw_message_data_storage_type;
    guint8 arg_raw_message_data_format;
    GArray *arg_raw_message_data_raw_data;
};

#define QMI_MESSAGE_WMS_RAW_WRITE_INPUT_TLV_RAW_MESSAGE_DATA 0x01

/**
 * qmi_message_wms_raw_write_input_get_raw_message_data:
 * @self: a #QmiMessageWmsRawWriteInput.
 * @raw_message_data_storage_type: a placeholder for the output #QmiWmsStorageType, or %NULL if not required.
 * @raw_message_data_format: a placeholder for the output #QmiWmsMessageFormat, or %NULL if not required.
 * @raw_message_data_raw_data: a placeholder for the output #GArray of #guint8 elements, or %NULL if not required. Do not free it, it is owned by @self.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Raw Message Data' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_write_input_get_raw_message_data (
    QmiMessageWmsRawWriteInput *self,
    QmiWmsStorageType *raw_message_data_storage_type,
    QmiWmsMessageFormat *raw_message_data_format,
    GArray **raw_message_data_raw_data,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_raw_message_data_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Raw Message Data' was not found in the message");
        return FALSE;
    }

    if (raw_message_data_storage_type)
        *raw_message_data_storage_type = (QmiWmsStorageType)(self->arg_raw_message_data_storage_type);
    if (raw_message_data_format)
        *raw_message_data_format = (QmiWmsMessageFormat)(self->arg_raw_message_data_format);
    if (raw_message_data_raw_data)
        *raw_message_data_raw_data = self->arg_raw_message_data_raw_data;

    return TRUE;
}

/**
 * qmi_message_wms_raw_write_input_set_raw_message_data:
 * @self: a #QmiMessageWmsRawWriteInput.
 * @raw_message_data_storage_type: a #QmiWmsStorageType.
 * @raw_message_data_format: a #QmiWmsMessageFormat.
 * @raw_message_data_raw_data: a #GArray of #guint8 elements. A new reference to @raw_message_data_raw_data will be taken.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Raw Message Data' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_write_input_set_raw_message_data (
    QmiMessageWmsRawWriteInput *self,
    QmiWmsStorageType raw_message_data_storage_type,
    QmiWmsMessageFormat raw_message_data_format,
    GArray *raw_message_data_raw_data,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_raw_message_data_storage_type = (guint8)(raw_message_data_storage_type);
    self->arg_raw_message_data_format = (guint8)(raw_message_data_format);
    if (self->arg_raw_message_data_raw_data)
        g_array_unref (self->arg_raw_message_data_raw_data);
    self->arg_raw_message_data_raw_data = g_array_ref (raw_message_data_raw_data);
    self->arg_raw_message_data_set = TRUE;

    return TRUE;
}

GType
qmi_message_wms_raw_write_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsRawWriteInput"),
                                          (GBoxedCopyFunc) qmi_message_wms_raw_write_input_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_raw_write_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_raw_write_input_ref:
 * @self: a #QmiMessageWmsRawWriteInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsRawWriteInput *
qmi_message_wms_raw_write_input_ref (QmiMessageWmsRawWriteInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_raw_write_input_unref:
 * @self: a #QmiMessageWmsRawWriteInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_raw_write_input_unref (QmiMessageWmsRawWriteInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        if (self->arg_raw_message_data_raw_data)
            g_array_unref (self->arg_raw_message_data_raw_data);
        g_slice_free (QmiMessageWmsRawWriteInput, self);
    }
}

/**
 * qmi_message_wms_raw_write_input_new:
 *
 * Allocates a new #QmiMessageWmsRawWriteInput.
 *
 * Returns: the newly created #QmiMessageWmsRawWriteInput. The returned value should be freed with qmi_message_wms_raw_write_input_unref().
 */
QmiMessageWmsRawWriteInput *
qmi_message_wms_raw_write_input_new (void)
{
    QmiMessageWmsRawWriteInput *self;

    self = g_slice_new0 (QmiMessageWmsRawWriteInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_wms_raw_write_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessageWmsRawWriteInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WMS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WMS_RAW_WRITE);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Raw Write' has mandatory TLVs");
        qmi_message_unref (self);
        return NULL;
    }

    /* Try to add the 'Raw Message Data' TLV */
    if (input->arg_raw_message_data_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_raw_message_data_storage_type;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }
        {
            guint8 tmp;

            tmp = (guint8)input->arg_raw_message_data_format;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }
        {
            guint raw_data_i;
            guint16 raw_data_n_items;

            /* Write the number of items in the array first */
            raw_data_n_items = (guint16) input->arg_raw_message_data_raw_data->len;
            /* Write the guint16 variable to the buffer */
            qmi_utils_write_guint16_to_buffer (
                &buffer_aux,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &(raw_data_n_items));

            for (raw_data_i = 0; raw_data_i < input->arg_raw_message_data_raw_data->len; raw_data_i++) {
                /* Write the guint8 variable to the buffer */
                qmi_utils_write_guint8_to_buffer (
                    &buffer_aux,
                    &buffer_len,
                    &(g_array_index (input->arg_raw_message_data_raw_data, guint8,raw_data_i)));
            }
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_RAW_WRITE_INPUT_TLV_RAW_MESSAGE_DATA,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Raw Message Data TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'Raw Message Data' in message 'Raw Write'");
        qmi_message_unref (self);
        return NULL;
    }

    return self;
}

/* --- Output -- */

struct _QmiMessageWmsRawWriteOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Memory Index */
    gboolean arg_memory_index_set;
    guint32 arg_memory_index;
};

#define QMI_MESSAGE_WMS_RAW_WRITE_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_WMS_RAW_WRITE_OUTPUT_TLV_MEMORY_INDEX 0x01

/**
 * qmi_message_wms_raw_write_output_get_result:
 * @self: a QmiMessageWmsRawWriteOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wms_raw_write_output_get_result (
    QmiMessageWmsRawWriteOutput *self,
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
 * qmi_message_wms_raw_write_output_get_memory_index:
 * @self: a #QmiMessageWmsRawWriteOutput.
 * @memory_index: a placeholder for the output #guint32, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Memory Index' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_write_output_get_memory_index (
    QmiMessageWmsRawWriteOutput *self,
    guint32 *memory_index,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_memory_index_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Memory Index' was not found in the message");
        return FALSE;
    }

    if (memory_index)
        *memory_index = self->arg_memory_index;

    return TRUE;
}

GType
qmi_message_wms_raw_write_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsRawWriteOutput"),
                                          (GBoxedCopyFunc) qmi_message_wms_raw_write_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_raw_write_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_raw_write_output_ref:
 * @self: a #QmiMessageWmsRawWriteOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsRawWriteOutput *
qmi_message_wms_raw_write_output_ref (QmiMessageWmsRawWriteOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_raw_write_output_unref:
 * @self: a #QmiMessageWmsRawWriteOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_raw_write_output_unref (QmiMessageWmsRawWriteOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWmsRawWriteOutput, self);
    }
}

static gboolean
qmi_message_wms_raw_write_input_raw_message_data_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;
    expected_len += 1;
    {
        guint raw_data_i;
        guint16 raw_data_n_items;
        const guint8 *raw_data_aux_buffer = &buffer[expected_len];
        guint16 raw_data_aux_buffer_len = buffer_len - expected_len;

        expected_len += 2;

        /* Read the guint16 variable from the buffer */
        qmi_utils_read_guint16_from_buffer (
            &raw_data_aux_buffer,
            &raw_data_aux_buffer_len,
            QMI_ENDIAN_LITTLE,
            &(raw_data_n_items));
        for (raw_data_i = 0; raw_data_i < raw_data_n_items; raw_data_i++) {

            expected_len += 1;
        }
    }

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Raw Message Data' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Raw Message Data' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_raw_write_input_raw_message_data_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_RAW_WRITE_INPUT_TLV_RAW_MESSAGE_DATA,
                                      &buffer_len);
    if (buffer && qmi_message_wms_raw_write_input_raw_message_data_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " storage_type = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_STORAGE_TYPE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_storage_type_get_string ((QmiWmsStorageType)tmp));
#elif defined  __QMI_WMS_STORAGE_TYPE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_storage_type_build_string_from_mask ((QmiWmsStorageType)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsStorageType
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " format = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_MESSAGE_FORMAT_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_message_format_get_string ((QmiWmsMessageFormat)tmp));
#elif defined  __QMI_WMS_MESSAGE_FORMAT_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_message_format_build_string_from_mask ((QmiWmsMessageFormat)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsMessageFormat
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " raw_data = '");
        {
            guint raw_data_i;
            guint16 raw_data_n_items;

            /* Read number of items in the array */
            /* Read the guint16 variable from the buffer */
            qmi_utils_read_guint16_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &(raw_data_n_items));

            g_string_append (printable, "{");

            for (raw_data_i = 0; raw_data_i < raw_data_n_items; raw_data_i++) {
                g_string_append_printf (printable, " [%u] = '", raw_data_i);

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);

                    g_string_append_printf (printable, "%u", (guint)tmp);
                }
                g_string_append (printable, " '");
            }

            g_string_append (printable, "}");
        }        g_string_append (printable, "'");
        g_string_append (printable, " ]");

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Raw Message Data' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_raw_write_output_memory_index_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Memory Index' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Memory Index' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_raw_write_output_memory_index_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_RAW_WRITE_OUTPUT_TLV_MEMORY_INDEX,
                                      &buffer_len);
    if (buffer && qmi_message_wms_raw_write_output_memory_index_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint32 tmp;

            /* Read the guint32 variable from the buffer */
            qmi_utils_read_guint32_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &tmp);

            g_string_append_printf (printable, "%" G_GUINT32_FORMAT "", tmp);
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Memory Index' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_raw_write_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_raw_write_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_raw_write_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_WMS_RAW_WRITE_INPUT_TLV_RAW_MESSAGE_DATA:
            tlv_type_str = "Raw Message Data";
            translated_value = qmi_message_wms_raw_write_input_raw_message_data_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_WMS_RAW_WRITE_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_RAW_WRITE_OUTPUT_TLV_MEMORY_INDEX:
            tlv_type_str = "Memory Index";
            translated_value = qmi_message_wms_raw_write_output_memory_index_get_printable (
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
message_raw_write_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Raw Write\" (0x0021)\n",
                            line_prefix);

    {
        struct message_raw_write_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_raw_write_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageWmsRawWriteOutput *
__qmi_message_wms_raw_write_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWmsRawWriteOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WMS_RAW_WRITE, NULL);

    self = g_slice_new0 (QmiMessageWmsRawWriteOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WMS_RAW_WRITE_OUTPUT_TLV_RESULT,
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
                qmi_message_wms_raw_write_output_unref (self);
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
                                              QMI_MESSAGE_WMS_RAW_WRITE_OUTPUT_TLV_MEMORY_INDEX,
                                              &buffer_len);
            if (buffer && qmi_message_wms_raw_write_output_memory_index_validate (buffer, buffer_len)) {
                self->arg_memory_index_set = TRUE;

                /* Read the guint32 variable from the buffer */
                qmi_utils_read_guint32_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_memory_index));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Memory Index' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the Memory Index TLV: Not found");
                qmi_message_wms_raw_write_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WMS Raw Read */


/* --- Input -- */

struct _QmiMessageWmsRawReadInput {
    volatile gint ref_count;

    /* SMS on IMS */
    gboolean arg_sms_on_ims_set;
    guint8 arg_sms_on_ims;

    /* Message Mode */
    gboolean arg_message_mode_set;
    guint8 arg_message_mode;

    /* Message Memory Storage ID */
    gboolean arg_message_memory_storage_id_set;
    guint8 arg_message_memory_storage_id_storage_type;
    guint32 arg_message_memory_storage_id_memory_index;
};

#define QMI_MESSAGE_WMS_RAW_READ_INPUT_TLV_SMS_ON_IMS 0x11
#define QMI_MESSAGE_WMS_RAW_READ_INPUT_TLV_MESSAGE_MODE 0x10
#define QMI_MESSAGE_WMS_RAW_READ_INPUT_TLV_MESSAGE_MEMORY_STORAGE_ID 0x01

/**
 * qmi_message_wms_raw_read_input_get_sms_on_ims:
 * @self: a #QmiMessageWmsRawReadInput.
 * @sms_on_ims: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'SMS on IMS' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_read_input_get_sms_on_ims (
    QmiMessageWmsRawReadInput *self,
    gboolean *sms_on_ims,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_sms_on_ims_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'SMS on IMS' was not found in the message");
        return FALSE;
    }

    if (sms_on_ims)
        *sms_on_ims = (gboolean)(self->arg_sms_on_ims);

    return TRUE;
}

/**
 * qmi_message_wms_raw_read_input_set_sms_on_ims:
 * @self: a #QmiMessageWmsRawReadInput.
 * @sms_on_ims: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'SMS on IMS' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_read_input_set_sms_on_ims (
    QmiMessageWmsRawReadInput *self,
    gboolean sms_on_ims,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_sms_on_ims = (guint8)(sms_on_ims);
    self->arg_sms_on_ims_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wms_raw_read_input_get_message_mode:
 * @self: a #QmiMessageWmsRawReadInput.
 * @message_mode: a placeholder for the output #QmiWmsMessageMode, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Message Mode' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_read_input_get_message_mode (
    QmiMessageWmsRawReadInput *self,
    QmiWmsMessageMode *message_mode,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_message_mode_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Message Mode' was not found in the message");
        return FALSE;
    }

    if (message_mode)
        *message_mode = (QmiWmsMessageMode)(self->arg_message_mode);

    return TRUE;
}

/**
 * qmi_message_wms_raw_read_input_set_message_mode:
 * @self: a #QmiMessageWmsRawReadInput.
 * @message_mode: a #QmiWmsMessageMode.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Message Mode' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_read_input_set_message_mode (
    QmiMessageWmsRawReadInput *self,
    QmiWmsMessageMode message_mode,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_message_mode = (guint8)(message_mode);
    self->arg_message_mode_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wms_raw_read_input_get_message_memory_storage_id:
 * @self: a #QmiMessageWmsRawReadInput.
 * @message_memory_storage_id_storage_type: a placeholder for the output #QmiWmsStorageType, or %NULL if not required.
 * @message_memory_storage_id_memory_index: a placeholder for the output #guint32, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Message Memory Storage ID' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_read_input_get_message_memory_storage_id (
    QmiMessageWmsRawReadInput *self,
    QmiWmsStorageType *message_memory_storage_id_storage_type,
    guint32 *message_memory_storage_id_memory_index,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_message_memory_storage_id_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Message Memory Storage ID' was not found in the message");
        return FALSE;
    }

    if (message_memory_storage_id_storage_type)
        *message_memory_storage_id_storage_type = (QmiWmsStorageType)(self->arg_message_memory_storage_id_storage_type);
    if (message_memory_storage_id_memory_index)
        *message_memory_storage_id_memory_index = self->arg_message_memory_storage_id_memory_index;

    return TRUE;
}

/**
 * qmi_message_wms_raw_read_input_set_message_memory_storage_id:
 * @self: a #QmiMessageWmsRawReadInput.
 * @message_memory_storage_id_storage_type: a #QmiWmsStorageType.
 * @message_memory_storage_id_memory_index: a #guint32.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Message Memory Storage ID' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_read_input_set_message_memory_storage_id (
    QmiMessageWmsRawReadInput *self,
    QmiWmsStorageType message_memory_storage_id_storage_type,
    guint32 message_memory_storage_id_memory_index,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_message_memory_storage_id_storage_type = (guint8)(message_memory_storage_id_storage_type);
    self->arg_message_memory_storage_id_memory_index = message_memory_storage_id_memory_index;
    self->arg_message_memory_storage_id_set = TRUE;

    return TRUE;
}

GType
qmi_message_wms_raw_read_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsRawReadInput"),
                                          (GBoxedCopyFunc) qmi_message_wms_raw_read_input_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_raw_read_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_raw_read_input_ref:
 * @self: a #QmiMessageWmsRawReadInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsRawReadInput *
qmi_message_wms_raw_read_input_ref (QmiMessageWmsRawReadInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_raw_read_input_unref:
 * @self: a #QmiMessageWmsRawReadInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_raw_read_input_unref (QmiMessageWmsRawReadInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWmsRawReadInput, self);
    }
}

/**
 * qmi_message_wms_raw_read_input_new:
 *
 * Allocates a new #QmiMessageWmsRawReadInput.
 *
 * Returns: the newly created #QmiMessageWmsRawReadInput. The returned value should be freed with qmi_message_wms_raw_read_input_unref().
 */
QmiMessageWmsRawReadInput *
qmi_message_wms_raw_read_input_new (void)
{
    QmiMessageWmsRawReadInput *self;

    self = g_slice_new0 (QmiMessageWmsRawReadInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_wms_raw_read_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessageWmsRawReadInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WMS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WMS_RAW_READ);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Raw Read' has mandatory TLVs");
        qmi_message_unref (self);
        return NULL;
    }

    /* Try to add the 'SMS on IMS' TLV */
    if (input->arg_sms_on_ims_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_sms_on_ims;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_RAW_READ_INPUT_TLV_SMS_ON_IMS,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the SMS on IMS TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Message Mode' TLV */
    if (input->arg_message_mode_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_message_mode;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_RAW_READ_INPUT_TLV_MESSAGE_MODE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Message Mode TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Message Memory Storage ID' TLV */
    if (input->arg_message_memory_storage_id_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_message_memory_storage_id_storage_type;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }
        /* Write the guint32 variable to the buffer */
        qmi_utils_write_guint32_to_buffer (
            &buffer_aux,
            &buffer_len,
            QMI_ENDIAN_LITTLE,
            &(input->arg_message_memory_storage_id_memory_index));

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_RAW_READ_INPUT_TLV_MESSAGE_MEMORY_STORAGE_ID,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Message Memory Storage ID TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'Message Memory Storage ID' in message 'Raw Read'");
        qmi_message_unref (self);
        return NULL;
    }

    return self;
}

/* --- Output -- */

struct _QmiMessageWmsRawReadOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Raw Message Data */
    gboolean arg_raw_message_data_set;
    guint8 arg_raw_message_data_message_tag;
    guint8 arg_raw_message_data_format;
    GArray *arg_raw_message_data_raw_data;
};

#define QMI_MESSAGE_WMS_RAW_READ_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_WMS_RAW_READ_OUTPUT_TLV_RAW_MESSAGE_DATA 0x01

/**
 * qmi_message_wms_raw_read_output_get_result:
 * @self: a QmiMessageWmsRawReadOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wms_raw_read_output_get_result (
    QmiMessageWmsRawReadOutput *self,
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
 * qmi_message_wms_raw_read_output_get_raw_message_data:
 * @self: a #QmiMessageWmsRawReadOutput.
 * @raw_message_data_message_tag: a placeholder for the output #QmiWmsMessageTagType, or %NULL if not required.
 * @raw_message_data_format: a placeholder for the output #QmiWmsMessageFormat, or %NULL if not required.
 * @raw_message_data_raw_data: a placeholder for the output #GArray of #guint8 elements, or %NULL if not required. Do not free it, it is owned by @self.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Raw Message Data' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_raw_read_output_get_raw_message_data (
    QmiMessageWmsRawReadOutput *self,
    QmiWmsMessageTagType *raw_message_data_message_tag,
    QmiWmsMessageFormat *raw_message_data_format,
    GArray **raw_message_data_raw_data,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_raw_message_data_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Raw Message Data' was not found in the message");
        return FALSE;
    }

    if (raw_message_data_message_tag)
        *raw_message_data_message_tag = (QmiWmsMessageTagType)(self->arg_raw_message_data_message_tag);
    if (raw_message_data_format)
        *raw_message_data_format = (QmiWmsMessageFormat)(self->arg_raw_message_data_format);
    if (raw_message_data_raw_data)
        *raw_message_data_raw_data = self->arg_raw_message_data_raw_data;

    return TRUE;
}

GType
qmi_message_wms_raw_read_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsRawReadOutput"),
                                          (GBoxedCopyFunc) qmi_message_wms_raw_read_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_raw_read_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_raw_read_output_ref:
 * @self: a #QmiMessageWmsRawReadOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsRawReadOutput *
qmi_message_wms_raw_read_output_ref (QmiMessageWmsRawReadOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_raw_read_output_unref:
 * @self: a #QmiMessageWmsRawReadOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_raw_read_output_unref (QmiMessageWmsRawReadOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        if (self->arg_raw_message_data_raw_data)
            g_array_unref (self->arg_raw_message_data_raw_data);
        g_slice_free (QmiMessageWmsRawReadOutput, self);
    }
}

static gboolean
qmi_message_wms_raw_read_input_sms_on_ims_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'SMS on IMS' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'SMS on IMS' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_raw_read_input_sms_on_ims_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_RAW_READ_INPUT_TLV_SMS_ON_IMS,
                                      &buffer_len);
    if (buffer && qmi_message_wms_raw_read_input_sms_on_ims_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

            g_string_append_printf (printable, "%s", tmp ? "yes" : "no");
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'SMS on IMS' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_raw_read_input_message_mode_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Message Mode' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Message Mode' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_raw_read_input_message_mode_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_RAW_READ_INPUT_TLV_MESSAGE_MODE,
                                      &buffer_len);
    if (buffer && qmi_message_wms_raw_read_input_message_mode_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_MESSAGE_MODE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_message_mode_get_string ((QmiWmsMessageMode)tmp));
#elif defined  __QMI_WMS_MESSAGE_MODE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_message_mode_build_string_from_mask ((QmiWmsMessageMode)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsMessageMode
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Message Mode' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_raw_read_input_message_memory_storage_id_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;
    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Message Memory Storage ID' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Message Memory Storage ID' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_raw_read_input_message_memory_storage_id_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_RAW_READ_INPUT_TLV_MESSAGE_MEMORY_STORAGE_ID,
                                      &buffer_len);
    if (buffer && qmi_message_wms_raw_read_input_message_memory_storage_id_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " storage_type = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_STORAGE_TYPE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_storage_type_get_string ((QmiWmsStorageType)tmp));
#elif defined  __QMI_WMS_STORAGE_TYPE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_storage_type_build_string_from_mask ((QmiWmsStorageType)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsStorageType
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " memory_index = '");

        {
            guint32 tmp;

            /* Read the guint32 variable from the buffer */
            qmi_utils_read_guint32_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &tmp);

            g_string_append_printf (printable, "%" G_GUINT32_FORMAT "", tmp);
        }
        g_string_append (printable, "'");
        g_string_append (printable, " ]");

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Message Memory Storage ID' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_raw_read_output_raw_message_data_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;
    expected_len += 1;
    {
        guint raw_data_i;
        guint16 raw_data_n_items;
        const guint8 *raw_data_aux_buffer = &buffer[expected_len];
        guint16 raw_data_aux_buffer_len = buffer_len - expected_len;

        expected_len += 2;

        /* Read the guint16 variable from the buffer */
        qmi_utils_read_guint16_from_buffer (
            &raw_data_aux_buffer,
            &raw_data_aux_buffer_len,
            QMI_ENDIAN_LITTLE,
            &(raw_data_n_items));
        for (raw_data_i = 0; raw_data_i < raw_data_n_items; raw_data_i++) {

            expected_len += 1;
        }
    }

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Raw Message Data' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Raw Message Data' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_raw_read_output_raw_message_data_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_RAW_READ_OUTPUT_TLV_RAW_MESSAGE_DATA,
                                      &buffer_len);
    if (buffer && qmi_message_wms_raw_read_output_raw_message_data_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " message_tag = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_MESSAGE_TAG_TYPE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_message_tag_type_get_string ((QmiWmsMessageTagType)tmp));
#elif defined  __QMI_WMS_MESSAGE_TAG_TYPE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_message_tag_type_build_string_from_mask ((QmiWmsMessageTagType)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsMessageTagType
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " format = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_MESSAGE_FORMAT_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_message_format_get_string ((QmiWmsMessageFormat)tmp));
#elif defined  __QMI_WMS_MESSAGE_FORMAT_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_message_format_build_string_from_mask ((QmiWmsMessageFormat)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsMessageFormat
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " raw_data = '");
        {
            guint raw_data_i;
            guint16 raw_data_n_items;

            /* Read number of items in the array */
            /* Read the guint16 variable from the buffer */
            qmi_utils_read_guint16_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &(raw_data_n_items));

            g_string_append (printable, "{");

            for (raw_data_i = 0; raw_data_i < raw_data_n_items; raw_data_i++) {
                g_string_append_printf (printable, " [%u] = '", raw_data_i);

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);

                    g_string_append_printf (printable, "%u", (guint)tmp);
                }
                g_string_append (printable, " '");
            }

            g_string_append (printable, "}");
        }        g_string_append (printable, "'");
        g_string_append (printable, " ]");

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Raw Message Data' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_raw_read_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_raw_read_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_raw_read_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_WMS_RAW_READ_INPUT_TLV_SMS_ON_IMS:
            tlv_type_str = "SMS on IMS";
            translated_value = qmi_message_wms_raw_read_input_sms_on_ims_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_RAW_READ_INPUT_TLV_MESSAGE_MODE:
            tlv_type_str = "Message Mode";
            translated_value = qmi_message_wms_raw_read_input_message_mode_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_RAW_READ_INPUT_TLV_MESSAGE_MEMORY_STORAGE_ID:
            tlv_type_str = "Message Memory Storage ID";
            translated_value = qmi_message_wms_raw_read_input_message_memory_storage_id_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_WMS_RAW_READ_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_RAW_READ_OUTPUT_TLV_RAW_MESSAGE_DATA:
            tlv_type_str = "Raw Message Data";
            translated_value = qmi_message_wms_raw_read_output_raw_message_data_get_printable (
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
message_raw_read_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Raw Read\" (0x0022)\n",
                            line_prefix);

    {
        struct message_raw_read_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_raw_read_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageWmsRawReadOutput *
__qmi_message_wms_raw_read_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWmsRawReadOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WMS_RAW_READ, NULL);

    self = g_slice_new0 (QmiMessageWmsRawReadOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WMS_RAW_READ_OUTPUT_TLV_RESULT,
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
                qmi_message_wms_raw_read_output_unref (self);
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
                                              QMI_MESSAGE_WMS_RAW_READ_OUTPUT_TLV_RAW_MESSAGE_DATA,
                                              &buffer_len);
            if (buffer && qmi_message_wms_raw_read_output_raw_message_data_validate (buffer, buffer_len)) {
                self->arg_raw_message_data_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_raw_message_data_message_tag = (QmiWmsMessageTagType)tmp;
                }
                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_raw_message_data_format = (QmiWmsMessageFormat)tmp;
                }
                {
                    guint raw_data_i;
                    guint16 raw_data_n_items;

                    /* Read number of items in the array */
                    /* Read the guint16 variable from the buffer */
                    qmi_utils_read_guint16_from_buffer (
                        &buffer,
                        &buffer_len,
                        QMI_ENDIAN_LITTLE,
                        &(raw_data_n_items));

                    self->arg_raw_message_data_raw_data = g_array_sized_new (
                        FALSE,
                        FALSE,
                        sizeof (guint8),
                        (guint)raw_data_n_items);

                    for (raw_data_i = 0; raw_data_i < raw_data_n_items; raw_data_i++) {
                        guint8 raw_data_aux;

                        /* Read the guint8 variable from the buffer */
                        qmi_utils_read_guint8_from_buffer (
                            &buffer,
                            &buffer_len,
                            &(raw_data_aux));
                        g_array_insert_val (self->arg_raw_message_data_raw_data, raw_data_i, raw_data_aux);
                    }
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Raw Message Data' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the Raw Message Data TLV: Not found");
                qmi_message_wms_raw_read_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WMS Modify Tag */


/* --- Input -- */

struct _QmiMessageWmsModifyTagInput {
    volatile gint ref_count;

    /* Message Mode */
    gboolean arg_message_mode_set;
    guint8 arg_message_mode;

    /* Message Tag */
    gboolean arg_message_tag_set;
    guint8 arg_message_tag_storage_type;
    guint32 arg_message_tag_memory_index;
    guint8 arg_message_tag_message_tag;
};

#define QMI_MESSAGE_WMS_MODIFY_TAG_INPUT_TLV_MESSAGE_MODE 0x10
#define QMI_MESSAGE_WMS_MODIFY_TAG_INPUT_TLV_MESSAGE_TAG 0x01

/**
 * qmi_message_wms_modify_tag_input_get_message_mode:
 * @self: a #QmiMessageWmsModifyTagInput.
 * @message_mode: a placeholder for the output #QmiWmsMessageMode, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Message Mode' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_modify_tag_input_get_message_mode (
    QmiMessageWmsModifyTagInput *self,
    QmiWmsMessageMode *message_mode,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_message_mode_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Message Mode' was not found in the message");
        return FALSE;
    }

    if (message_mode)
        *message_mode = (QmiWmsMessageMode)(self->arg_message_mode);

    return TRUE;
}

/**
 * qmi_message_wms_modify_tag_input_set_message_mode:
 * @self: a #QmiMessageWmsModifyTagInput.
 * @message_mode: a #QmiWmsMessageMode.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Message Mode' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_modify_tag_input_set_message_mode (
    QmiMessageWmsModifyTagInput *self,
    QmiWmsMessageMode message_mode,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_message_mode = (guint8)(message_mode);
    self->arg_message_mode_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wms_modify_tag_input_get_message_tag:
 * @self: a #QmiMessageWmsModifyTagInput.
 * @message_tag_storage_type: a placeholder for the output #QmiWmsStorageType, or %NULL if not required.
 * @message_tag_memory_index: a placeholder for the output #guint32, or %NULL if not required.
 * @message_tag_message_tag: a placeholder for the output #QmiWmsMessageTagType, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Message Tag' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_modify_tag_input_get_message_tag (
    QmiMessageWmsModifyTagInput *self,
    QmiWmsStorageType *message_tag_storage_type,
    guint32 *message_tag_memory_index,
    QmiWmsMessageTagType *message_tag_message_tag,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_message_tag_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Message Tag' was not found in the message");
        return FALSE;
    }

    if (message_tag_storage_type)
        *message_tag_storage_type = (QmiWmsStorageType)(self->arg_message_tag_storage_type);
    if (message_tag_memory_index)
        *message_tag_memory_index = self->arg_message_tag_memory_index;
    if (message_tag_message_tag)
        *message_tag_message_tag = (QmiWmsMessageTagType)(self->arg_message_tag_message_tag);

    return TRUE;
}

/**
 * qmi_message_wms_modify_tag_input_set_message_tag:
 * @self: a #QmiMessageWmsModifyTagInput.
 * @message_tag_storage_type: a #QmiWmsStorageType.
 * @message_tag_memory_index: a #guint32.
 * @message_tag_message_tag: a #QmiWmsMessageTagType.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Message Tag' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_modify_tag_input_set_message_tag (
    QmiMessageWmsModifyTagInput *self,
    QmiWmsStorageType message_tag_storage_type,
    guint32 message_tag_memory_index,
    QmiWmsMessageTagType message_tag_message_tag,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_message_tag_storage_type = (guint8)(message_tag_storage_type);
    self->arg_message_tag_memory_index = message_tag_memory_index;
    self->arg_message_tag_message_tag = (guint8)(message_tag_message_tag);
    self->arg_message_tag_set = TRUE;

    return TRUE;
}

GType
qmi_message_wms_modify_tag_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsModifyTagInput"),
                                          (GBoxedCopyFunc) qmi_message_wms_modify_tag_input_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_modify_tag_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_modify_tag_input_ref:
 * @self: a #QmiMessageWmsModifyTagInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsModifyTagInput *
qmi_message_wms_modify_tag_input_ref (QmiMessageWmsModifyTagInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_modify_tag_input_unref:
 * @self: a #QmiMessageWmsModifyTagInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_modify_tag_input_unref (QmiMessageWmsModifyTagInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWmsModifyTagInput, self);
    }
}

/**
 * qmi_message_wms_modify_tag_input_new:
 *
 * Allocates a new #QmiMessageWmsModifyTagInput.
 *
 * Returns: the newly created #QmiMessageWmsModifyTagInput. The returned value should be freed with qmi_message_wms_modify_tag_input_unref().
 */
QmiMessageWmsModifyTagInput *
qmi_message_wms_modify_tag_input_new (void)
{
    QmiMessageWmsModifyTagInput *self;

    self = g_slice_new0 (QmiMessageWmsModifyTagInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_wms_modify_tag_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessageWmsModifyTagInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WMS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WMS_MODIFY_TAG);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Modify Tag' has mandatory TLVs");
        qmi_message_unref (self);
        return NULL;
    }

    /* Try to add the 'Message Mode' TLV */
    if (input->arg_message_mode_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_message_mode;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_MODIFY_TAG_INPUT_TLV_MESSAGE_MODE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Message Mode TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Message Tag' TLV */
    if (input->arg_message_tag_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_message_tag_storage_type;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }
        /* Write the guint32 variable to the buffer */
        qmi_utils_write_guint32_to_buffer (
            &buffer_aux,
            &buffer_len,
            QMI_ENDIAN_LITTLE,
            &(input->arg_message_tag_memory_index));
        {
            guint8 tmp;

            tmp = (guint8)input->arg_message_tag_message_tag;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_MODIFY_TAG_INPUT_TLV_MESSAGE_TAG,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Message Tag TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'Message Tag' in message 'Modify Tag'");
        qmi_message_unref (self);
        return NULL;
    }

    return self;
}

/* --- Output -- */

struct _QmiMessageWmsModifyTagOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;
};

#define QMI_MESSAGE_WMS_MODIFY_TAG_OUTPUT_TLV_RESULT 0x02

/**
 * qmi_message_wms_modify_tag_output_get_result:
 * @self: a QmiMessageWmsModifyTagOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wms_modify_tag_output_get_result (
    QmiMessageWmsModifyTagOutput *self,
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
qmi_message_wms_modify_tag_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsModifyTagOutput"),
                                          (GBoxedCopyFunc) qmi_message_wms_modify_tag_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_modify_tag_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_modify_tag_output_ref:
 * @self: a #QmiMessageWmsModifyTagOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsModifyTagOutput *
qmi_message_wms_modify_tag_output_ref (QmiMessageWmsModifyTagOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_modify_tag_output_unref:
 * @self: a #QmiMessageWmsModifyTagOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_modify_tag_output_unref (QmiMessageWmsModifyTagOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWmsModifyTagOutput, self);
    }
}

static gboolean
qmi_message_wms_modify_tag_input_message_mode_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Message Mode' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Message Mode' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_modify_tag_input_message_mode_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_MODIFY_TAG_INPUT_TLV_MESSAGE_MODE,
                                      &buffer_len);
    if (buffer && qmi_message_wms_modify_tag_input_message_mode_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_MESSAGE_MODE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_message_mode_get_string ((QmiWmsMessageMode)tmp));
#elif defined  __QMI_WMS_MESSAGE_MODE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_message_mode_build_string_from_mask ((QmiWmsMessageMode)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsMessageMode
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Message Mode' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_modify_tag_input_message_tag_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;
    expected_len += 4;
    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Message Tag' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Message Tag' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_modify_tag_input_message_tag_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_MODIFY_TAG_INPUT_TLV_MESSAGE_TAG,
                                      &buffer_len);
    if (buffer && qmi_message_wms_modify_tag_input_message_tag_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " storage_type = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_STORAGE_TYPE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_storage_type_get_string ((QmiWmsStorageType)tmp));
#elif defined  __QMI_WMS_STORAGE_TYPE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_storage_type_build_string_from_mask ((QmiWmsStorageType)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsStorageType
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " memory_index = '");

        {
            guint32 tmp;

            /* Read the guint32 variable from the buffer */
            qmi_utils_read_guint32_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &tmp);

            g_string_append_printf (printable, "%" G_GUINT32_FORMAT "", tmp);
        }
        g_string_append (printable, "'");
        g_string_append (printable, " message_tag = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_MESSAGE_TAG_TYPE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_message_tag_type_get_string ((QmiWmsMessageTagType)tmp));
#elif defined  __QMI_WMS_MESSAGE_TAG_TYPE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_message_tag_type_build_string_from_mask ((QmiWmsMessageTagType)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsMessageTagType
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " ]");

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Message Tag' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_modify_tag_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_modify_tag_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_modify_tag_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_WMS_MODIFY_TAG_INPUT_TLV_MESSAGE_MODE:
            tlv_type_str = "Message Mode";
            translated_value = qmi_message_wms_modify_tag_input_message_mode_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_MODIFY_TAG_INPUT_TLV_MESSAGE_TAG:
            tlv_type_str = "Message Tag";
            translated_value = qmi_message_wms_modify_tag_input_message_tag_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_WMS_MODIFY_TAG_OUTPUT_TLV_RESULT:
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
message_modify_tag_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Modify Tag\" (0x0023)\n",
                            line_prefix);

    {
        struct message_modify_tag_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_modify_tag_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageWmsModifyTagOutput *
__qmi_message_wms_modify_tag_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWmsModifyTagOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WMS_MODIFY_TAG, NULL);

    self = g_slice_new0 (QmiMessageWmsModifyTagOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WMS_MODIFY_TAG_OUTPUT_TLV_RESULT,
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
                qmi_message_wms_modify_tag_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WMS Delete */


/* --- Input -- */

struct _QmiMessageWmsDeleteInput {
    volatile gint ref_count;

    /* Message Mode */
    gboolean arg_message_mode_set;
    guint8 arg_message_mode;

    /* Message Tag */
    gboolean arg_message_tag_set;
    guint8 arg_message_tag;

    /* Memory Index */
    gboolean arg_memory_index_set;
    guint32 arg_memory_index;

    /* Memory Storage */
    gboolean arg_memory_storage_set;
    guint8 arg_memory_storage;
};

#define QMI_MESSAGE_WMS_DELETE_INPUT_TLV_MESSAGE_MODE 0x12
#define QMI_MESSAGE_WMS_DELETE_INPUT_TLV_MESSAGE_TAG 0x11
#define QMI_MESSAGE_WMS_DELETE_INPUT_TLV_MEMORY_INDEX 0x10
#define QMI_MESSAGE_WMS_DELETE_INPUT_TLV_MEMORY_STORAGE 0x01

/**
 * qmi_message_wms_delete_input_get_message_mode:
 * @self: a #QmiMessageWmsDeleteInput.
 * @message_mode: a placeholder for the output #QmiWmsMessageMode, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Message Mode' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_delete_input_get_message_mode (
    QmiMessageWmsDeleteInput *self,
    QmiWmsMessageMode *message_mode,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_message_mode_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Message Mode' was not found in the message");
        return FALSE;
    }

    if (message_mode)
        *message_mode = (QmiWmsMessageMode)(self->arg_message_mode);

    return TRUE;
}

/**
 * qmi_message_wms_delete_input_set_message_mode:
 * @self: a #QmiMessageWmsDeleteInput.
 * @message_mode: a #QmiWmsMessageMode.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Message Mode' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_delete_input_set_message_mode (
    QmiMessageWmsDeleteInput *self,
    QmiWmsMessageMode message_mode,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_message_mode = (guint8)(message_mode);
    self->arg_message_mode_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wms_delete_input_get_message_tag:
 * @self: a #QmiMessageWmsDeleteInput.
 * @message_tag: a placeholder for the output #QmiWmsMessageTagType, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Message Tag' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_delete_input_get_message_tag (
    QmiMessageWmsDeleteInput *self,
    QmiWmsMessageTagType *message_tag,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_message_tag_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Message Tag' was not found in the message");
        return FALSE;
    }

    if (message_tag)
        *message_tag = (QmiWmsMessageTagType)(self->arg_message_tag);

    return TRUE;
}

/**
 * qmi_message_wms_delete_input_set_message_tag:
 * @self: a #QmiMessageWmsDeleteInput.
 * @message_tag: a #QmiWmsMessageTagType.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Message Tag' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_delete_input_set_message_tag (
    QmiMessageWmsDeleteInput *self,
    QmiWmsMessageTagType message_tag,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_message_tag = (guint8)(message_tag);
    self->arg_message_tag_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wms_delete_input_get_memory_index:
 * @self: a #QmiMessageWmsDeleteInput.
 * @memory_index: a placeholder for the output #guint32, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Memory Index' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_delete_input_get_memory_index (
    QmiMessageWmsDeleteInput *self,
    guint32 *memory_index,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_memory_index_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Memory Index' was not found in the message");
        return FALSE;
    }

    if (memory_index)
        *memory_index = self->arg_memory_index;

    return TRUE;
}

/**
 * qmi_message_wms_delete_input_set_memory_index:
 * @self: a #QmiMessageWmsDeleteInput.
 * @memory_index: a #guint32.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Memory Index' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_delete_input_set_memory_index (
    QmiMessageWmsDeleteInput *self,
    guint32 memory_index,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_memory_index = memory_index;
    self->arg_memory_index_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wms_delete_input_get_memory_storage:
 * @self: a #QmiMessageWmsDeleteInput.
 * @memory_storage: a placeholder for the output #QmiWmsStorageType, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Memory Storage' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_delete_input_get_memory_storage (
    QmiMessageWmsDeleteInput *self,
    QmiWmsStorageType *memory_storage,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_memory_storage_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Memory Storage' was not found in the message");
        return FALSE;
    }

    if (memory_storage)
        *memory_storage = (QmiWmsStorageType)(self->arg_memory_storage);

    return TRUE;
}

/**
 * qmi_message_wms_delete_input_set_memory_storage:
 * @self: a #QmiMessageWmsDeleteInput.
 * @memory_storage: a #QmiWmsStorageType.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Memory Storage' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_delete_input_set_memory_storage (
    QmiMessageWmsDeleteInput *self,
    QmiWmsStorageType memory_storage,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_memory_storage = (guint8)(memory_storage);
    self->arg_memory_storage_set = TRUE;

    return TRUE;
}

GType
qmi_message_wms_delete_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsDeleteInput"),
                                          (GBoxedCopyFunc) qmi_message_wms_delete_input_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_delete_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_delete_input_ref:
 * @self: a #QmiMessageWmsDeleteInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsDeleteInput *
qmi_message_wms_delete_input_ref (QmiMessageWmsDeleteInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_delete_input_unref:
 * @self: a #QmiMessageWmsDeleteInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_delete_input_unref (QmiMessageWmsDeleteInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWmsDeleteInput, self);
    }
}

/**
 * qmi_message_wms_delete_input_new:
 *
 * Allocates a new #QmiMessageWmsDeleteInput.
 *
 * Returns: the newly created #QmiMessageWmsDeleteInput. The returned value should be freed with qmi_message_wms_delete_input_unref().
 */
QmiMessageWmsDeleteInput *
qmi_message_wms_delete_input_new (void)
{
    QmiMessageWmsDeleteInput *self;

    self = g_slice_new0 (QmiMessageWmsDeleteInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_wms_delete_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessageWmsDeleteInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WMS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WMS_DELETE);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Delete' has mandatory TLVs");
        qmi_message_unref (self);
        return NULL;
    }

    /* Try to add the 'Message Mode' TLV */
    if (input->arg_message_mode_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_message_mode;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_DELETE_INPUT_TLV_MESSAGE_MODE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Message Mode TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Message Tag' TLV */
    if (input->arg_message_tag_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_message_tag;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_DELETE_INPUT_TLV_MESSAGE_TAG,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Message Tag TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Memory Index' TLV */
    if (input->arg_memory_index_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        /* Write the guint32 variable to the buffer */
        qmi_utils_write_guint32_to_buffer (
            &buffer_aux,
            &buffer_len,
            QMI_ENDIAN_LITTLE,
            &(input->arg_memory_index));

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_DELETE_INPUT_TLV_MEMORY_INDEX,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Memory Index TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Memory Storage' TLV */
    if (input->arg_memory_storage_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_memory_storage;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_DELETE_INPUT_TLV_MEMORY_STORAGE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Memory Storage TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'Memory Storage' in message 'Delete'");
        qmi_message_unref (self);
        return NULL;
    }

    return self;
}

/* --- Output -- */

struct _QmiMessageWmsDeleteOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;
};

#define QMI_MESSAGE_WMS_DELETE_OUTPUT_TLV_RESULT 0x02

/**
 * qmi_message_wms_delete_output_get_result:
 * @self: a QmiMessageWmsDeleteOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wms_delete_output_get_result (
    QmiMessageWmsDeleteOutput *self,
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
qmi_message_wms_delete_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsDeleteOutput"),
                                          (GBoxedCopyFunc) qmi_message_wms_delete_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_delete_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_delete_output_ref:
 * @self: a #QmiMessageWmsDeleteOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsDeleteOutput *
qmi_message_wms_delete_output_ref (QmiMessageWmsDeleteOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_delete_output_unref:
 * @self: a #QmiMessageWmsDeleteOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_delete_output_unref (QmiMessageWmsDeleteOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWmsDeleteOutput, self);
    }
}

static gboolean
qmi_message_wms_delete_input_message_mode_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Message Mode' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Message Mode' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_delete_input_message_mode_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_DELETE_INPUT_TLV_MESSAGE_MODE,
                                      &buffer_len);
    if (buffer && qmi_message_wms_delete_input_message_mode_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_MESSAGE_MODE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_message_mode_get_string ((QmiWmsMessageMode)tmp));
#elif defined  __QMI_WMS_MESSAGE_MODE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_message_mode_build_string_from_mask ((QmiWmsMessageMode)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsMessageMode
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Message Mode' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_delete_input_message_tag_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Message Tag' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Message Tag' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_delete_input_message_tag_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_DELETE_INPUT_TLV_MESSAGE_TAG,
                                      &buffer_len);
    if (buffer && qmi_message_wms_delete_input_message_tag_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_MESSAGE_TAG_TYPE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_message_tag_type_get_string ((QmiWmsMessageTagType)tmp));
#elif defined  __QMI_WMS_MESSAGE_TAG_TYPE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_message_tag_type_build_string_from_mask ((QmiWmsMessageTagType)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsMessageTagType
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Message Tag' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_delete_input_memory_index_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Memory Index' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Memory Index' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_delete_input_memory_index_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_DELETE_INPUT_TLV_MEMORY_INDEX,
                                      &buffer_len);
    if (buffer && qmi_message_wms_delete_input_memory_index_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint32 tmp;

            /* Read the guint32 variable from the buffer */
            qmi_utils_read_guint32_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &tmp);

            g_string_append_printf (printable, "%" G_GUINT32_FORMAT "", tmp);
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Memory Index' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_delete_input_memory_storage_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Memory Storage' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Memory Storage' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_delete_input_memory_storage_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_DELETE_INPUT_TLV_MEMORY_STORAGE,
                                      &buffer_len);
    if (buffer && qmi_message_wms_delete_input_memory_storage_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_STORAGE_TYPE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_storage_type_get_string ((QmiWmsStorageType)tmp));
#elif defined  __QMI_WMS_STORAGE_TYPE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_storage_type_build_string_from_mask ((QmiWmsStorageType)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsStorageType
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Memory Storage' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_delete_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_delete_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_delete_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_WMS_DELETE_INPUT_TLV_MESSAGE_MODE:
            tlv_type_str = "Message Mode";
            translated_value = qmi_message_wms_delete_input_message_mode_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_DELETE_INPUT_TLV_MESSAGE_TAG:
            tlv_type_str = "Message Tag";
            translated_value = qmi_message_wms_delete_input_message_tag_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_DELETE_INPUT_TLV_MEMORY_INDEX:
            tlv_type_str = "Memory Index";
            translated_value = qmi_message_wms_delete_input_memory_index_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_DELETE_INPUT_TLV_MEMORY_STORAGE:
            tlv_type_str = "Memory Storage";
            translated_value = qmi_message_wms_delete_input_memory_storage_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_WMS_DELETE_OUTPUT_TLV_RESULT:
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
message_delete_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Delete\" (0x0024)\n",
                            line_prefix);

    {
        struct message_delete_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_delete_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageWmsDeleteOutput *
__qmi_message_wms_delete_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWmsDeleteOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WMS_DELETE, NULL);

    self = g_slice_new0 (QmiMessageWmsDeleteOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WMS_DELETE_OUTPUT_TLV_RESULT,
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
                qmi_message_wms_delete_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WMS Get Message Protocol */


/* --- Input -- */

/* Note: no fields in the Input container */

static QmiMessage *
__qmi_message_wms_get_message_protocol_request_create (
    guint8 transaction_id,
    guint8 cid,
    gpointer unused,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WMS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WMS_GET_MESSAGE_PROTOCOL);

    return self;
}

/* --- Output -- */

struct _QmiMessageWmsGetMessageProtocolOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Message Protocol */
    gboolean arg_message_protocol_set;
    guint8 arg_message_protocol;
};

#define QMI_MESSAGE_WMS_GET_MESSAGE_PROTOCOL_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_WMS_GET_MESSAGE_PROTOCOL_OUTPUT_TLV_MESSAGE_PROTOCOL 0x01

/**
 * qmi_message_wms_get_message_protocol_output_get_result:
 * @self: a QmiMessageWmsGetMessageProtocolOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wms_get_message_protocol_output_get_result (
    QmiMessageWmsGetMessageProtocolOutput *self,
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
 * qmi_message_wms_get_message_protocol_output_get_message_protocol:
 * @self: a #QmiMessageWmsGetMessageProtocolOutput.
 * @message_protocol: a placeholder for the output #QmiWmsMessageProtocol, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Message Protocol' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_get_message_protocol_output_get_message_protocol (
    QmiMessageWmsGetMessageProtocolOutput *self,
    QmiWmsMessageProtocol *message_protocol,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_message_protocol_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Message Protocol' was not found in the message");
        return FALSE;
    }

    if (message_protocol)
        *message_protocol = (QmiWmsMessageProtocol)(self->arg_message_protocol);

    return TRUE;
}

GType
qmi_message_wms_get_message_protocol_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsGetMessageProtocolOutput"),
                                          (GBoxedCopyFunc) qmi_message_wms_get_message_protocol_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_get_message_protocol_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_get_message_protocol_output_ref:
 * @self: a #QmiMessageWmsGetMessageProtocolOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsGetMessageProtocolOutput *
qmi_message_wms_get_message_protocol_output_ref (QmiMessageWmsGetMessageProtocolOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_get_message_protocol_output_unref:
 * @self: a #QmiMessageWmsGetMessageProtocolOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_get_message_protocol_output_unref (QmiMessageWmsGetMessageProtocolOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWmsGetMessageProtocolOutput, self);
    }
}

static gboolean
qmi_message_wms_get_message_protocol_output_message_protocol_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Message Protocol' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Message Protocol' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_get_message_protocol_output_message_protocol_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_GET_MESSAGE_PROTOCOL_OUTPUT_TLV_MESSAGE_PROTOCOL,
                                      &buffer_len);
    if (buffer && qmi_message_wms_get_message_protocol_output_message_protocol_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_MESSAGE_PROTOCOL_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_message_protocol_get_string ((QmiWmsMessageProtocol)tmp));
#elif defined  __QMI_WMS_MESSAGE_PROTOCOL_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_message_protocol_build_string_from_mask ((QmiWmsMessageProtocol)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsMessageProtocol
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Message Protocol' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_get_message_protocol_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_get_message_protocol_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_get_message_protocol_context *ctx)
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
        case QMI_MESSAGE_WMS_GET_MESSAGE_PROTOCOL_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_GET_MESSAGE_PROTOCOL_OUTPUT_TLV_MESSAGE_PROTOCOL:
            tlv_type_str = "Message Protocol";
            translated_value = qmi_message_wms_get_message_protocol_output_message_protocol_get_printable (
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
message_get_message_protocol_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Get Message Protocol\" (0x0030)\n",
                            line_prefix);

    {
        struct message_get_message_protocol_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_get_message_protocol_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageWmsGetMessageProtocolOutput *
__qmi_message_wms_get_message_protocol_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWmsGetMessageProtocolOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WMS_GET_MESSAGE_PROTOCOL, NULL);

    self = g_slice_new0 (QmiMessageWmsGetMessageProtocolOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WMS_GET_MESSAGE_PROTOCOL_OUTPUT_TLV_RESULT,
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
                qmi_message_wms_get_message_protocol_output_unref (self);
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
                                              QMI_MESSAGE_WMS_GET_MESSAGE_PROTOCOL_OUTPUT_TLV_MESSAGE_PROTOCOL,
                                              &buffer_len);
            if (buffer && qmi_message_wms_get_message_protocol_output_message_protocol_validate (buffer, buffer_len)) {
                self->arg_message_protocol_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_message_protocol = (QmiWmsMessageProtocol)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Message Protocol' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the Message Protocol TLV: Not found");
                qmi_message_wms_get_message_protocol_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WMS List Messages */


/* --- Input -- */

struct _QmiMessageWmsListMessagesInput {
    volatile gint ref_count;

    /* Message Mode */
    gboolean arg_message_mode_set;
    guint8 arg_message_mode;

    /* Message Tag */
    gboolean arg_message_tag_set;
    guint8 arg_message_tag;

    /* Storage Type */
    gboolean arg_storage_type_set;
    guint8 arg_storage_type;
};

#define QMI_MESSAGE_WMS_LIST_MESSAGES_INPUT_TLV_MESSAGE_MODE 0x12
#define QMI_MESSAGE_WMS_LIST_MESSAGES_INPUT_TLV_MESSAGE_TAG 0x11
#define QMI_MESSAGE_WMS_LIST_MESSAGES_INPUT_TLV_STORAGE_TYPE 0x01

/**
 * qmi_message_wms_list_messages_input_get_message_mode:
 * @self: a #QmiMessageWmsListMessagesInput.
 * @message_mode: a placeholder for the output #QmiWmsMessageMode, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Message Mode' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_list_messages_input_get_message_mode (
    QmiMessageWmsListMessagesInput *self,
    QmiWmsMessageMode *message_mode,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_message_mode_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Message Mode' was not found in the message");
        return FALSE;
    }

    if (message_mode)
        *message_mode = (QmiWmsMessageMode)(self->arg_message_mode);

    return TRUE;
}

/**
 * qmi_message_wms_list_messages_input_set_message_mode:
 * @self: a #QmiMessageWmsListMessagesInput.
 * @message_mode: a #QmiWmsMessageMode.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Message Mode' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_list_messages_input_set_message_mode (
    QmiMessageWmsListMessagesInput *self,
    QmiWmsMessageMode message_mode,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_message_mode = (guint8)(message_mode);
    self->arg_message_mode_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wms_list_messages_input_get_message_tag:
 * @self: a #QmiMessageWmsListMessagesInput.
 * @message_tag: a placeholder for the output #QmiWmsMessageTagType, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Message Tag' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_list_messages_input_get_message_tag (
    QmiMessageWmsListMessagesInput *self,
    QmiWmsMessageTagType *message_tag,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_message_tag_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Message Tag' was not found in the message");
        return FALSE;
    }

    if (message_tag)
        *message_tag = (QmiWmsMessageTagType)(self->arg_message_tag);

    return TRUE;
}

/**
 * qmi_message_wms_list_messages_input_set_message_tag:
 * @self: a #QmiMessageWmsListMessagesInput.
 * @message_tag: a #QmiWmsMessageTagType.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Message Tag' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_list_messages_input_set_message_tag (
    QmiMessageWmsListMessagesInput *self,
    QmiWmsMessageTagType message_tag,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_message_tag = (guint8)(message_tag);
    self->arg_message_tag_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wms_list_messages_input_get_storage_type:
 * @self: a #QmiMessageWmsListMessagesInput.
 * @storage_type: a placeholder for the output #QmiWmsStorageType, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Storage Type' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_list_messages_input_get_storage_type (
    QmiMessageWmsListMessagesInput *self,
    QmiWmsStorageType *storage_type,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_storage_type_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Storage Type' was not found in the message");
        return FALSE;
    }

    if (storage_type)
        *storage_type = (QmiWmsStorageType)(self->arg_storage_type);

    return TRUE;
}

/**
 * qmi_message_wms_list_messages_input_set_storage_type:
 * @self: a #QmiMessageWmsListMessagesInput.
 * @storage_type: a #QmiWmsStorageType.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Storage Type' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_list_messages_input_set_storage_type (
    QmiMessageWmsListMessagesInput *self,
    QmiWmsStorageType storage_type,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_storage_type = (guint8)(storage_type);
    self->arg_storage_type_set = TRUE;

    return TRUE;
}

GType
qmi_message_wms_list_messages_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsListMessagesInput"),
                                          (GBoxedCopyFunc) qmi_message_wms_list_messages_input_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_list_messages_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_list_messages_input_ref:
 * @self: a #QmiMessageWmsListMessagesInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsListMessagesInput *
qmi_message_wms_list_messages_input_ref (QmiMessageWmsListMessagesInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_list_messages_input_unref:
 * @self: a #QmiMessageWmsListMessagesInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_list_messages_input_unref (QmiMessageWmsListMessagesInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWmsListMessagesInput, self);
    }
}

/**
 * qmi_message_wms_list_messages_input_new:
 *
 * Allocates a new #QmiMessageWmsListMessagesInput.
 *
 * Returns: the newly created #QmiMessageWmsListMessagesInput. The returned value should be freed with qmi_message_wms_list_messages_input_unref().
 */
QmiMessageWmsListMessagesInput *
qmi_message_wms_list_messages_input_new (void)
{
    QmiMessageWmsListMessagesInput *self;

    self = g_slice_new0 (QmiMessageWmsListMessagesInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_wms_list_messages_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessageWmsListMessagesInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WMS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WMS_LIST_MESSAGES);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'List Messages' has mandatory TLVs");
        qmi_message_unref (self);
        return NULL;
    }

    /* Try to add the 'Message Mode' TLV */
    if (input->arg_message_mode_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_message_mode;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_LIST_MESSAGES_INPUT_TLV_MESSAGE_MODE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Message Mode TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Message Tag' TLV */
    if (input->arg_message_tag_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_message_tag;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_LIST_MESSAGES_INPUT_TLV_MESSAGE_TAG,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Message Tag TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Storage Type' TLV */
    if (input->arg_storage_type_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_storage_type;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_LIST_MESSAGES_INPUT_TLV_STORAGE_TYPE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Storage Type TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'Storage Type' in message 'List Messages'");
        qmi_message_unref (self);
        return NULL;
    }

    return self;
}

/* --- Output -- */

struct _QmiMessageWmsListMessagesOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Message List */
    gboolean arg_message_list_set;
    GArray *arg_message_list;
};

#define QMI_MESSAGE_WMS_LIST_MESSAGES_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_WMS_LIST_MESSAGES_OUTPUT_TLV_MESSAGE_LIST 0x01

/**
 * qmi_message_wms_list_messages_output_get_result:
 * @self: a QmiMessageWmsListMessagesOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wms_list_messages_output_get_result (
    QmiMessageWmsListMessagesOutput *self,
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
 * qmi_message_wms_list_messages_output_get_message_list:
 * @self: a #QmiMessageWmsListMessagesOutput.
 * @message_list: a placeholder for the output #GArray of #QmiMessageWmsListMessagesOutputMessageListElement elements, or %NULL if not required. Do not free it, it is owned by @self.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Message List' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_list_messages_output_get_message_list (
    QmiMessageWmsListMessagesOutput *self,
    GArray **message_list,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_message_list_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Message List' was not found in the message");
        return FALSE;
    }

    if (message_list)
        *message_list = self->arg_message_list;

    return TRUE;
}

GType
qmi_message_wms_list_messages_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsListMessagesOutput"),
                                          (GBoxedCopyFunc) qmi_message_wms_list_messages_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_list_messages_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_list_messages_output_ref:
 * @self: a #QmiMessageWmsListMessagesOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsListMessagesOutput *
qmi_message_wms_list_messages_output_ref (QmiMessageWmsListMessagesOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_list_messages_output_unref:
 * @self: a #QmiMessageWmsListMessagesOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_list_messages_output_unref (QmiMessageWmsListMessagesOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        if (self->arg_message_list)
            g_array_unref (self->arg_message_list);
        g_slice_free (QmiMessageWmsListMessagesOutput, self);
    }
}

static gboolean
qmi_message_wms_list_messages_input_message_mode_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Message Mode' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Message Mode' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_list_messages_input_message_mode_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_LIST_MESSAGES_INPUT_TLV_MESSAGE_MODE,
                                      &buffer_len);
    if (buffer && qmi_message_wms_list_messages_input_message_mode_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_MESSAGE_MODE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_message_mode_get_string ((QmiWmsMessageMode)tmp));
#elif defined  __QMI_WMS_MESSAGE_MODE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_message_mode_build_string_from_mask ((QmiWmsMessageMode)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsMessageMode
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Message Mode' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_list_messages_input_message_tag_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Message Tag' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Message Tag' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_list_messages_input_message_tag_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_LIST_MESSAGES_INPUT_TLV_MESSAGE_TAG,
                                      &buffer_len);
    if (buffer && qmi_message_wms_list_messages_input_message_tag_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_MESSAGE_TAG_TYPE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_message_tag_type_get_string ((QmiWmsMessageTagType)tmp));
#elif defined  __QMI_WMS_MESSAGE_TAG_TYPE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_message_tag_type_build_string_from_mask ((QmiWmsMessageTagType)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsMessageTagType
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Message Tag' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_list_messages_input_storage_type_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Storage Type' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Storage Type' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_list_messages_input_storage_type_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_LIST_MESSAGES_INPUT_TLV_STORAGE_TYPE,
                                      &buffer_len);
    if (buffer && qmi_message_wms_list_messages_input_storage_type_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_STORAGE_TYPE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_storage_type_get_string ((QmiWmsStorageType)tmp));
#elif defined  __QMI_WMS_STORAGE_TYPE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_storage_type_build_string_from_mask ((QmiWmsStorageType)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsStorageType
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Storage Type' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_list_messages_output_message_list_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    {
        guint message_list_i;
        guint32 message_list_n_items;
        const guint8 *message_list_aux_buffer = &buffer[expected_len];
        guint16 message_list_aux_buffer_len = buffer_len - expected_len;

        expected_len += 4;

        /* Read the guint32 variable from the buffer */
        qmi_utils_read_guint32_from_buffer (
            &message_list_aux_buffer,
            &message_list_aux_buffer_len,
            QMI_ENDIAN_LITTLE,
            &(message_list_n_items));
        for (message_list_i = 0; message_list_i < message_list_n_items; message_list_i++) {

            expected_len += 4;
            expected_len += 1;
        }
    }

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Message List' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Message List' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_list_messages_output_message_list_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_LIST_MESSAGES_OUTPUT_TLV_MESSAGE_LIST,
                                      &buffer_len);
    if (buffer && qmi_message_wms_list_messages_output_message_list_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        {
            guint message_list_i;
            guint32 message_list_n_items;

            /* Read number of items in the array */
            /* Read the guint32 variable from the buffer */
            qmi_utils_read_guint32_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &(message_list_n_items));

            g_string_append (printable, "{");

            for (message_list_i = 0; message_list_i < message_list_n_items; message_list_i++) {
                g_string_append_printf (printable, " [%u] = '", message_list_i);
                g_string_append (printable, "[");
                g_string_append (printable, " memory_index = '");

                {
                    guint32 tmp;

                    /* Read the guint32 variable from the buffer */
                    qmi_utils_read_guint32_from_buffer (
                        &buffer,
                        &buffer_len,
                        QMI_ENDIAN_LITTLE,
                        &tmp);

                    g_string_append_printf (printable, "%" G_GUINT32_FORMAT "", tmp);
                }
                g_string_append (printable, "'");
                g_string_append (printable, " message_tag = '");

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);

#if defined  __QMI_WMS_MESSAGE_TAG_TYPE_IS_ENUM__
                    g_string_append_printf (printable, "%s", qmi_wms_message_tag_type_get_string ((QmiWmsMessageTagType)tmp));
#elif defined  __QMI_WMS_MESSAGE_TAG_TYPE_IS_FLAGS__
                    {
                        gchar *flags_str;

                        flags_str = qmi_wms_message_tag_type_build_string_from_mask ((QmiWmsMessageTagType)tmp);
                        g_string_append_printf (printable, "%s", flags_str);
                        g_free (flags_str);
                    }
#else
# error unexpected public format: QmiWmsMessageTagType
#endif
                }
                g_string_append (printable, "'");
                g_string_append (printable, " ]");
                g_string_append (printable, " '");
            }

            g_string_append (printable, "}");
        }
        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Message List' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_list_messages_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_list_messages_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_list_messages_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_WMS_LIST_MESSAGES_INPUT_TLV_MESSAGE_MODE:
            tlv_type_str = "Message Mode";
            translated_value = qmi_message_wms_list_messages_input_message_mode_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_LIST_MESSAGES_INPUT_TLV_MESSAGE_TAG:
            tlv_type_str = "Message Tag";
            translated_value = qmi_message_wms_list_messages_input_message_tag_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_LIST_MESSAGES_INPUT_TLV_STORAGE_TYPE:
            tlv_type_str = "Storage Type";
            translated_value = qmi_message_wms_list_messages_input_storage_type_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_WMS_LIST_MESSAGES_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_LIST_MESSAGES_OUTPUT_TLV_MESSAGE_LIST:
            tlv_type_str = "Message List";
            translated_value = qmi_message_wms_list_messages_output_message_list_get_printable (
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
message_list_messages_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"List Messages\" (0x0031)\n",
                            line_prefix);

    {
        struct message_list_messages_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_list_messages_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageWmsListMessagesOutput *
__qmi_message_wms_list_messages_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWmsListMessagesOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WMS_LIST_MESSAGES, NULL);

    self = g_slice_new0 (QmiMessageWmsListMessagesOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WMS_LIST_MESSAGES_OUTPUT_TLV_RESULT,
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
                qmi_message_wms_list_messages_output_unref (self);
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
                                              QMI_MESSAGE_WMS_LIST_MESSAGES_OUTPUT_TLV_MESSAGE_LIST,
                                              &buffer_len);
            if (buffer && qmi_message_wms_list_messages_output_message_list_validate (buffer, buffer_len)) {
                self->arg_message_list_set = TRUE;

                {
                    guint message_list_i;
                    guint32 message_list_n_items;

                    /* Read number of items in the array */
                    /* Read the guint32 variable from the buffer */
                    qmi_utils_read_guint32_from_buffer (
                        &buffer,
                        &buffer_len,
                        QMI_ENDIAN_LITTLE,
                        &(message_list_n_items));

                    self->arg_message_list = g_array_sized_new (
                        FALSE,
                        FALSE,
                        sizeof (QmiMessageWmsListMessagesOutputMessageListElement),
                        (guint)message_list_n_items);

                    for (message_list_i = 0; message_list_i < message_list_n_items; message_list_i++) {
                        QmiMessageWmsListMessagesOutputMessageListElement message_list_aux;

                        /* Read the guint32 variable from the buffer */
                        qmi_utils_read_guint32_from_buffer (
                            &buffer,
                            &buffer_len,
                            QMI_ENDIAN_LITTLE,
                            &(message_list_aux.memory_index));
                        {
                            guint8 tmp;

                            /* Read the guint8 variable from the buffer */
                            qmi_utils_read_guint8_from_buffer (
                                &buffer,
                                &buffer_len,
                                &tmp);
                            message_list_aux.message_tag = (QmiWmsMessageTagType)tmp;
                        }
                        g_array_insert_val (self->arg_message_list, message_list_i, message_list_aux);
                    }
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Message List' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the Message List TLV: Not found");
                qmi_message_wms_list_messages_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WMS Set Routes */


/* --- Input -- */

struct _QmiMessageWmsSetRoutesInput {
    volatile gint ref_count;

    /* Transfer Status Report */
    gboolean arg_transfer_status_report_set;
    guint8 arg_transfer_status_report;

    /* Route List */
    gboolean arg_route_list_set;
    GArray *arg_route_list;
};

#define QMI_MESSAGE_WMS_SET_ROUTES_INPUT_TLV_TRANSFER_STATUS_REPORT 0x10
#define QMI_MESSAGE_WMS_SET_ROUTES_INPUT_TLV_ROUTE_LIST 0x01

/**
 * qmi_message_wms_set_routes_input_get_transfer_status_report:
 * @self: a #QmiMessageWmsSetRoutesInput.
 * @transfer_status_report: a placeholder for the output #QmiWmsTransferIndication, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Transfer Status Report' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_set_routes_input_get_transfer_status_report (
    QmiMessageWmsSetRoutesInput *self,
    QmiWmsTransferIndication *transfer_status_report,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_transfer_status_report_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Transfer Status Report' was not found in the message");
        return FALSE;
    }

    if (transfer_status_report)
        *transfer_status_report = (QmiWmsTransferIndication)(self->arg_transfer_status_report);

    return TRUE;
}

/**
 * qmi_message_wms_set_routes_input_set_transfer_status_report:
 * @self: a #QmiMessageWmsSetRoutesInput.
 * @transfer_status_report: a #QmiWmsTransferIndication.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Transfer Status Report' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_set_routes_input_set_transfer_status_report (
    QmiMessageWmsSetRoutesInput *self,
    QmiWmsTransferIndication transfer_status_report,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_transfer_status_report = (guint8)(transfer_status_report);
    self->arg_transfer_status_report_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wms_set_routes_input_get_route_list:
 * @self: a #QmiMessageWmsSetRoutesInput.
 * @route_list: a placeholder for the output #GArray of #QmiMessageWmsSetRoutesInputRouteListElement elements, or %NULL if not required. Do not free it, it is owned by @self.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Route List' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_set_routes_input_get_route_list (
    QmiMessageWmsSetRoutesInput *self,
    GArray **route_list,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_route_list_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Route List' was not found in the message");
        return FALSE;
    }

    if (route_list)
        *route_list = self->arg_route_list;

    return TRUE;
}

/**
 * qmi_message_wms_set_routes_input_set_route_list:
 * @self: a #QmiMessageWmsSetRoutesInput.
 * @route_list: a #GArray of #QmiMessageWmsSetRoutesInputRouteListElement elements. A new reference to @route_list will be taken.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Route List' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_set_routes_input_set_route_list (
    QmiMessageWmsSetRoutesInput *self,
    GArray *route_list,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (self->arg_route_list)
        g_array_unref (self->arg_route_list);
    self->arg_route_list = g_array_ref (route_list);
    self->arg_route_list_set = TRUE;

    return TRUE;
}

GType
qmi_message_wms_set_routes_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsSetRoutesInput"),
                                          (GBoxedCopyFunc) qmi_message_wms_set_routes_input_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_set_routes_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_set_routes_input_ref:
 * @self: a #QmiMessageWmsSetRoutesInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsSetRoutesInput *
qmi_message_wms_set_routes_input_ref (QmiMessageWmsSetRoutesInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_set_routes_input_unref:
 * @self: a #QmiMessageWmsSetRoutesInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_set_routes_input_unref (QmiMessageWmsSetRoutesInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        if (self->arg_route_list)
            g_array_unref (self->arg_route_list);
        g_slice_free (QmiMessageWmsSetRoutesInput, self);
    }
}

/**
 * qmi_message_wms_set_routes_input_new:
 *
 * Allocates a new #QmiMessageWmsSetRoutesInput.
 *
 * Returns: the newly created #QmiMessageWmsSetRoutesInput. The returned value should be freed with qmi_message_wms_set_routes_input_unref().
 */
QmiMessageWmsSetRoutesInput *
qmi_message_wms_set_routes_input_new (void)
{
    QmiMessageWmsSetRoutesInput *self;

    self = g_slice_new0 (QmiMessageWmsSetRoutesInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_wms_set_routes_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessageWmsSetRoutesInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WMS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WMS_SET_ROUTES);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Set Routes' has mandatory TLVs");
        qmi_message_unref (self);
        return NULL;
    }

    /* Try to add the 'Transfer Status Report' TLV */
    if (input->arg_transfer_status_report_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_transfer_status_report;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_SET_ROUTES_INPUT_TLV_TRANSFER_STATUS_REPORT,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Transfer Status Report TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Route List' TLV */
    if (input->arg_route_list_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint route_list_i;
            guint16 route_list_n_items;

            /* Write the number of items in the array first */
            route_list_n_items = (guint16) input->arg_route_list->len;
            /* Write the guint16 variable to the buffer */
            qmi_utils_write_guint16_to_buffer (
                &buffer_aux,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &(route_list_n_items));

            for (route_list_i = 0; route_list_i < input->arg_route_list->len; route_list_i++) {
                {
                    guint8 tmp;

                    tmp = (guint8)g_array_index (input->arg_route_list, QmiMessageWmsSetRoutesInputRouteListElement,route_list_i).message_type;
                    /* Write the guint8 variable to the buffer */
                    qmi_utils_write_guint8_to_buffer (
                        &buffer_aux,
                        &buffer_len,
                        &tmp);
                }
                {
                    guint8 tmp;

                    tmp = (guint8)g_array_index (input->arg_route_list, QmiMessageWmsSetRoutesInputRouteListElement,route_list_i).message_class;
                    /* Write the guint8 variable to the buffer */
                    qmi_utils_write_guint8_to_buffer (
                        &buffer_aux,
                        &buffer_len,
                        &tmp);
                }
                {
                    guint8 tmp;

                    tmp = (guint8)g_array_index (input->arg_route_list, QmiMessageWmsSetRoutesInputRouteListElement,route_list_i).storage;
                    /* Write the guint8 variable to the buffer */
                    qmi_utils_write_guint8_to_buffer (
                        &buffer_aux,
                        &buffer_len,
                        &tmp);
                }
                {
                    guint8 tmp;

                    tmp = (guint8)g_array_index (input->arg_route_list, QmiMessageWmsSetRoutesInputRouteListElement,route_list_i).receipt_action;
                    /* Write the guint8 variable to the buffer */
                    qmi_utils_write_guint8_to_buffer (
                        &buffer_aux,
                        &buffer_len,
                        &tmp);
                }
            }
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_SET_ROUTES_INPUT_TLV_ROUTE_LIST,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Route List TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'Route List' in message 'Set Routes'");
        qmi_message_unref (self);
        return NULL;
    }

    return self;
}

/* --- Output -- */

struct _QmiMessageWmsSetRoutesOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;
};

#define QMI_MESSAGE_WMS_SET_ROUTES_OUTPUT_TLV_RESULT 0x02

/**
 * qmi_message_wms_set_routes_output_get_result:
 * @self: a QmiMessageWmsSetRoutesOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wms_set_routes_output_get_result (
    QmiMessageWmsSetRoutesOutput *self,
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
qmi_message_wms_set_routes_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsSetRoutesOutput"),
                                          (GBoxedCopyFunc) qmi_message_wms_set_routes_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_set_routes_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_set_routes_output_ref:
 * @self: a #QmiMessageWmsSetRoutesOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsSetRoutesOutput *
qmi_message_wms_set_routes_output_ref (QmiMessageWmsSetRoutesOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_set_routes_output_unref:
 * @self: a #QmiMessageWmsSetRoutesOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_set_routes_output_unref (QmiMessageWmsSetRoutesOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWmsSetRoutesOutput, self);
    }
}

static gboolean
qmi_message_wms_set_routes_input_transfer_status_report_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Transfer Status Report' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Transfer Status Report' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_set_routes_input_transfer_status_report_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_SET_ROUTES_INPUT_TLV_TRANSFER_STATUS_REPORT,
                                      &buffer_len);
    if (buffer && qmi_message_wms_set_routes_input_transfer_status_report_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_TRANSFER_INDICATION_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_transfer_indication_get_string ((QmiWmsTransferIndication)tmp));
#elif defined  __QMI_WMS_TRANSFER_INDICATION_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_transfer_indication_build_string_from_mask ((QmiWmsTransferIndication)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsTransferIndication
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Transfer Status Report' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_set_routes_input_route_list_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    {
        guint route_list_i;
        guint16 route_list_n_items;
        const guint8 *route_list_aux_buffer = &buffer[expected_len];
        guint16 route_list_aux_buffer_len = buffer_len - expected_len;

        expected_len += 2;

        /* Read the guint16 variable from the buffer */
        qmi_utils_read_guint16_from_buffer (
            &route_list_aux_buffer,
            &route_list_aux_buffer_len,
            QMI_ENDIAN_LITTLE,
            &(route_list_n_items));
        for (route_list_i = 0; route_list_i < route_list_n_items; route_list_i++) {

            expected_len += 1;
            expected_len += 1;
            expected_len += 1;
            expected_len += 1;
        }
    }

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Route List' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Route List' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_set_routes_input_route_list_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_SET_ROUTES_INPUT_TLV_ROUTE_LIST,
                                      &buffer_len);
    if (buffer && qmi_message_wms_set_routes_input_route_list_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        {
            guint route_list_i;
            guint16 route_list_n_items;

            /* Read number of items in the array */
            /* Read the guint16 variable from the buffer */
            qmi_utils_read_guint16_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &(route_list_n_items));

            g_string_append (printable, "{");

            for (route_list_i = 0; route_list_i < route_list_n_items; route_list_i++) {
                g_string_append_printf (printable, " [%u] = '", route_list_i);
                g_string_append (printable, "[");
                g_string_append (printable, " message_type = '");

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);

#if defined  __QMI_WMS_MESSAGE_TYPE_IS_ENUM__
                    g_string_append_printf (printable, "%s", qmi_wms_message_type_get_string ((QmiWmsMessageType)tmp));
#elif defined  __QMI_WMS_MESSAGE_TYPE_IS_FLAGS__
                    {
                        gchar *flags_str;

                        flags_str = qmi_wms_message_type_build_string_from_mask ((QmiWmsMessageType)tmp);
                        g_string_append_printf (printable, "%s", flags_str);
                        g_free (flags_str);
                    }
#else
# error unexpected public format: QmiWmsMessageType
#endif
                }
                g_string_append (printable, "'");
                g_string_append (printable, " message_class = '");

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);

#if defined  __QMI_WMS_MESSAGE_CLASS_IS_ENUM__
                    g_string_append_printf (printable, "%s", qmi_wms_message_class_get_string ((QmiWmsMessageClass)tmp));
#elif defined  __QMI_WMS_MESSAGE_CLASS_IS_FLAGS__
                    {
                        gchar *flags_str;

                        flags_str = qmi_wms_message_class_build_string_from_mask ((QmiWmsMessageClass)tmp);
                        g_string_append_printf (printable, "%s", flags_str);
                        g_free (flags_str);
                    }
#else
# error unexpected public format: QmiWmsMessageClass
#endif
                }
                g_string_append (printable, "'");
                g_string_append (printable, " storage = '");

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);

#if defined  __QMI_WMS_STORAGE_TYPE_IS_ENUM__
                    g_string_append_printf (printable, "%s", qmi_wms_storage_type_get_string ((QmiWmsStorageType)tmp));
#elif defined  __QMI_WMS_STORAGE_TYPE_IS_FLAGS__
                    {
                        gchar *flags_str;

                        flags_str = qmi_wms_storage_type_build_string_from_mask ((QmiWmsStorageType)tmp);
                        g_string_append_printf (printable, "%s", flags_str);
                        g_free (flags_str);
                    }
#else
# error unexpected public format: QmiWmsStorageType
#endif
                }
                g_string_append (printable, "'");
                g_string_append (printable, " receipt_action = '");

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);

#if defined  __QMI_WMS_RECEIPT_ACTION_IS_ENUM__
                    g_string_append_printf (printable, "%s", qmi_wms_receipt_action_get_string ((QmiWmsReceiptAction)tmp));
#elif defined  __QMI_WMS_RECEIPT_ACTION_IS_FLAGS__
                    {
                        gchar *flags_str;

                        flags_str = qmi_wms_receipt_action_build_string_from_mask ((QmiWmsReceiptAction)tmp);
                        g_string_append_printf (printable, "%s", flags_str);
                        g_free (flags_str);
                    }
#else
# error unexpected public format: QmiWmsReceiptAction
#endif
                }
                g_string_append (printable, "'");
                g_string_append (printable, " ]");
                g_string_append (printable, " '");
            }

            g_string_append (printable, "}");
        }
        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Route List' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_set_routes_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_set_routes_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_set_routes_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_WMS_SET_ROUTES_INPUT_TLV_TRANSFER_STATUS_REPORT:
            tlv_type_str = "Transfer Status Report";
            translated_value = qmi_message_wms_set_routes_input_transfer_status_report_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_SET_ROUTES_INPUT_TLV_ROUTE_LIST:
            tlv_type_str = "Route List";
            translated_value = qmi_message_wms_set_routes_input_route_list_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_WMS_SET_ROUTES_OUTPUT_TLV_RESULT:
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
message_set_routes_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Set Routes\" (0x0032)\n",
                            line_prefix);

    {
        struct message_set_routes_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_set_routes_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageWmsSetRoutesOutput *
__qmi_message_wms_set_routes_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWmsSetRoutesOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WMS_SET_ROUTES, NULL);

    self = g_slice_new0 (QmiMessageWmsSetRoutesOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WMS_SET_ROUTES_OUTPUT_TLV_RESULT,
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
                qmi_message_wms_set_routes_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WMS Get Routes */


/* --- Input -- */

/* Note: no fields in the Input container */

static QmiMessage *
__qmi_message_wms_get_routes_request_create (
    guint8 transaction_id,
    guint8 cid,
    gpointer unused,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WMS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WMS_GET_ROUTES);

    return self;
}

/* --- Output -- */

struct _QmiMessageWmsGetRoutesOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Route List */
    gboolean arg_route_list_set;
    GArray *arg_route_list;

    /* Transfer Status Report */
    gboolean arg_transfer_status_report_set;
    guint8 arg_transfer_status_report;
};

#define QMI_MESSAGE_WMS_GET_ROUTES_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_WMS_GET_ROUTES_OUTPUT_TLV_ROUTE_LIST 0x01
#define QMI_MESSAGE_WMS_GET_ROUTES_OUTPUT_TLV_TRANSFER_STATUS_REPORT 0x10

/**
 * qmi_message_wms_get_routes_output_get_result:
 * @self: a QmiMessageWmsGetRoutesOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wms_get_routes_output_get_result (
    QmiMessageWmsGetRoutesOutput *self,
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
 * qmi_message_wms_get_routes_output_get_route_list:
 * @self: a #QmiMessageWmsGetRoutesOutput.
 * @route_list: a placeholder for the output #GArray of #QmiMessageWmsGetRoutesOutputRouteListElement elements, or %NULL if not required. Do not free it, it is owned by @self.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Route List' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_get_routes_output_get_route_list (
    QmiMessageWmsGetRoutesOutput *self,
    GArray **route_list,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_route_list_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Route List' was not found in the message");
        return FALSE;
    }

    if (route_list)
        *route_list = self->arg_route_list;

    return TRUE;
}

/**
 * qmi_message_wms_get_routes_output_get_transfer_status_report:
 * @self: a #QmiMessageWmsGetRoutesOutput.
 * @transfer_status_report: a placeholder for the output #QmiWmsTransferIndication, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Transfer Status Report' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_get_routes_output_get_transfer_status_report (
    QmiMessageWmsGetRoutesOutput *self,
    QmiWmsTransferIndication *transfer_status_report,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_transfer_status_report_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Transfer Status Report' was not found in the message");
        return FALSE;
    }

    if (transfer_status_report)
        *transfer_status_report = (QmiWmsTransferIndication)(self->arg_transfer_status_report);

    return TRUE;
}

GType
qmi_message_wms_get_routes_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsGetRoutesOutput"),
                                          (GBoxedCopyFunc) qmi_message_wms_get_routes_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_get_routes_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_get_routes_output_ref:
 * @self: a #QmiMessageWmsGetRoutesOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsGetRoutesOutput *
qmi_message_wms_get_routes_output_ref (QmiMessageWmsGetRoutesOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_get_routes_output_unref:
 * @self: a #QmiMessageWmsGetRoutesOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_get_routes_output_unref (QmiMessageWmsGetRoutesOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        if (self->arg_route_list)
            g_array_unref (self->arg_route_list);
        g_slice_free (QmiMessageWmsGetRoutesOutput, self);
    }
}

static gboolean
qmi_message_wms_get_routes_output_route_list_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    {
        guint route_list_i;
        guint16 route_list_n_items;
        const guint8 *route_list_aux_buffer = &buffer[expected_len];
        guint16 route_list_aux_buffer_len = buffer_len - expected_len;

        expected_len += 2;

        /* Read the guint16 variable from the buffer */
        qmi_utils_read_guint16_from_buffer (
            &route_list_aux_buffer,
            &route_list_aux_buffer_len,
            QMI_ENDIAN_LITTLE,
            &(route_list_n_items));
        for (route_list_i = 0; route_list_i < route_list_n_items; route_list_i++) {

            expected_len += 1;
            expected_len += 1;
            expected_len += 1;
            expected_len += 1;
        }
    }

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Route List' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Route List' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_get_routes_output_route_list_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_GET_ROUTES_OUTPUT_TLV_ROUTE_LIST,
                                      &buffer_len);
    if (buffer && qmi_message_wms_get_routes_output_route_list_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        {
            guint route_list_i;
            guint16 route_list_n_items;

            /* Read number of items in the array */
            /* Read the guint16 variable from the buffer */
            qmi_utils_read_guint16_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &(route_list_n_items));

            g_string_append (printable, "{");

            for (route_list_i = 0; route_list_i < route_list_n_items; route_list_i++) {
                g_string_append_printf (printable, " [%u] = '", route_list_i);
                g_string_append (printable, "[");
                g_string_append (printable, " message_type = '");

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);

#if defined  __QMI_WMS_MESSAGE_TYPE_IS_ENUM__
                    g_string_append_printf (printable, "%s", qmi_wms_message_type_get_string ((QmiWmsMessageType)tmp));
#elif defined  __QMI_WMS_MESSAGE_TYPE_IS_FLAGS__
                    {
                        gchar *flags_str;

                        flags_str = qmi_wms_message_type_build_string_from_mask ((QmiWmsMessageType)tmp);
                        g_string_append_printf (printable, "%s", flags_str);
                        g_free (flags_str);
                    }
#else
# error unexpected public format: QmiWmsMessageType
#endif
                }
                g_string_append (printable, "'");
                g_string_append (printable, " message_class = '");

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);

#if defined  __QMI_WMS_MESSAGE_CLASS_IS_ENUM__
                    g_string_append_printf (printable, "%s", qmi_wms_message_class_get_string ((QmiWmsMessageClass)tmp));
#elif defined  __QMI_WMS_MESSAGE_CLASS_IS_FLAGS__
                    {
                        gchar *flags_str;

                        flags_str = qmi_wms_message_class_build_string_from_mask ((QmiWmsMessageClass)tmp);
                        g_string_append_printf (printable, "%s", flags_str);
                        g_free (flags_str);
                    }
#else
# error unexpected public format: QmiWmsMessageClass
#endif
                }
                g_string_append (printable, "'");
                g_string_append (printable, " storage = '");

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);

#if defined  __QMI_WMS_STORAGE_TYPE_IS_ENUM__
                    g_string_append_printf (printable, "%s", qmi_wms_storage_type_get_string ((QmiWmsStorageType)tmp));
#elif defined  __QMI_WMS_STORAGE_TYPE_IS_FLAGS__
                    {
                        gchar *flags_str;

                        flags_str = qmi_wms_storage_type_build_string_from_mask ((QmiWmsStorageType)tmp);
                        g_string_append_printf (printable, "%s", flags_str);
                        g_free (flags_str);
                    }
#else
# error unexpected public format: QmiWmsStorageType
#endif
                }
                g_string_append (printable, "'");
                g_string_append (printable, " receipt_action = '");

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);

#if defined  __QMI_WMS_RECEIPT_ACTION_IS_ENUM__
                    g_string_append_printf (printable, "%s", qmi_wms_receipt_action_get_string ((QmiWmsReceiptAction)tmp));
#elif defined  __QMI_WMS_RECEIPT_ACTION_IS_FLAGS__
                    {
                        gchar *flags_str;

                        flags_str = qmi_wms_receipt_action_build_string_from_mask ((QmiWmsReceiptAction)tmp);
                        g_string_append_printf (printable, "%s", flags_str);
                        g_free (flags_str);
                    }
#else
# error unexpected public format: QmiWmsReceiptAction
#endif
                }
                g_string_append (printable, "'");
                g_string_append (printable, " ]");
                g_string_append (printable, " '");
            }

            g_string_append (printable, "}");
        }
        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Route List' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_get_routes_output_transfer_status_report_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Transfer Status Report' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Transfer Status Report' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_get_routes_output_transfer_status_report_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_GET_ROUTES_OUTPUT_TLV_TRANSFER_STATUS_REPORT,
                                      &buffer_len);
    if (buffer && qmi_message_wms_get_routes_output_transfer_status_report_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_TRANSFER_INDICATION_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_transfer_indication_get_string ((QmiWmsTransferIndication)tmp));
#elif defined  __QMI_WMS_TRANSFER_INDICATION_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_transfer_indication_build_string_from_mask ((QmiWmsTransferIndication)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsTransferIndication
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Transfer Status Report' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_get_routes_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_get_routes_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_get_routes_context *ctx)
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
        case QMI_MESSAGE_WMS_GET_ROUTES_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_GET_ROUTES_OUTPUT_TLV_ROUTE_LIST:
            tlv_type_str = "Route List";
            translated_value = qmi_message_wms_get_routes_output_route_list_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_GET_ROUTES_OUTPUT_TLV_TRANSFER_STATUS_REPORT:
            tlv_type_str = "Transfer Status Report";
            translated_value = qmi_message_wms_get_routes_output_transfer_status_report_get_printable (
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
message_get_routes_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Get Routes\" (0x0033)\n",
                            line_prefix);

    {
        struct message_get_routes_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_get_routes_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageWmsGetRoutesOutput *
__qmi_message_wms_get_routes_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWmsGetRoutesOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WMS_GET_ROUTES, NULL);

    self = g_slice_new0 (QmiMessageWmsGetRoutesOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WMS_GET_ROUTES_OUTPUT_TLV_RESULT,
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
                qmi_message_wms_get_routes_output_unref (self);
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
                                              QMI_MESSAGE_WMS_GET_ROUTES_OUTPUT_TLV_ROUTE_LIST,
                                              &buffer_len);
            if (buffer && qmi_message_wms_get_routes_output_route_list_validate (buffer, buffer_len)) {
                self->arg_route_list_set = TRUE;

                {
                    guint route_list_i;
                    guint16 route_list_n_items;

                    /* Read number of items in the array */
                    /* Read the guint16 variable from the buffer */
                    qmi_utils_read_guint16_from_buffer (
                        &buffer,
                        &buffer_len,
                        QMI_ENDIAN_LITTLE,
                        &(route_list_n_items));

                    self->arg_route_list = g_array_sized_new (
                        FALSE,
                        FALSE,
                        sizeof (QmiMessageWmsGetRoutesOutputRouteListElement),
                        (guint)route_list_n_items);

                    for (route_list_i = 0; route_list_i < route_list_n_items; route_list_i++) {
                        QmiMessageWmsGetRoutesOutputRouteListElement route_list_aux;

                        {
                            guint8 tmp;

                            /* Read the guint8 variable from the buffer */
                            qmi_utils_read_guint8_from_buffer (
                                &buffer,
                                &buffer_len,
                                &tmp);
                            route_list_aux.message_type = (QmiWmsMessageType)tmp;
                        }
                        {
                            guint8 tmp;

                            /* Read the guint8 variable from the buffer */
                            qmi_utils_read_guint8_from_buffer (
                                &buffer,
                                &buffer_len,
                                &tmp);
                            route_list_aux.message_class = (QmiWmsMessageClass)tmp;
                        }
                        {
                            guint8 tmp;

                            /* Read the guint8 variable from the buffer */
                            qmi_utils_read_guint8_from_buffer (
                                &buffer,
                                &buffer_len,
                                &tmp);
                            route_list_aux.storage = (QmiWmsStorageType)tmp;
                        }
                        {
                            guint8 tmp;

                            /* Read the guint8 variable from the buffer */
                            qmi_utils_read_guint8_from_buffer (
                                &buffer,
                                &buffer_len,
                                &tmp);
                            route_list_aux.receipt_action = (QmiWmsReceiptAction)tmp;
                        }
                        g_array_insert_val (self->arg_route_list, route_list_i, route_list_aux);
                    }
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Route List' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the Route List TLV: Not found");
                qmi_message_wms_get_routes_output_unref (self);
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
                                              QMI_MESSAGE_WMS_GET_ROUTES_OUTPUT_TLV_TRANSFER_STATUS_REPORT,
                                              &buffer_len);
            if (buffer && qmi_message_wms_get_routes_output_transfer_status_report_validate (buffer, buffer_len)) {
                self->arg_transfer_status_report_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_transfer_status_report = (QmiWmsTransferIndication)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Transfer Status Report' TLV", buffer_len);
                }
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WMS Send From Memory Storage */


/* --- Input -- */

struct _QmiMessageWmsSendFromMemoryStorageInput {
    volatile gint ref_count;

    /* SMS on IMS */
    gboolean arg_sms_on_ims_set;
    guint8 arg_sms_on_ims;

    /* Information */
    gboolean arg_information_set;
    guint8 arg_information_storage_type;
    guint32 arg_information_memory_index;
    guint8 arg_information_message_mode;
};

#define QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_INPUT_TLV_SMS_ON_IMS 0x10
#define QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_INPUT_TLV_INFORMATION 0x01

/**
 * qmi_message_wms_send_from_memory_storage_input_get_sms_on_ims:
 * @self: a #QmiMessageWmsSendFromMemoryStorageInput.
 * @sms_on_ims: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'SMS on IMS' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_send_from_memory_storage_input_get_sms_on_ims (
    QmiMessageWmsSendFromMemoryStorageInput *self,
    gboolean *sms_on_ims,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_sms_on_ims_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'SMS on IMS' was not found in the message");
        return FALSE;
    }

    if (sms_on_ims)
        *sms_on_ims = (gboolean)(self->arg_sms_on_ims);

    return TRUE;
}

/**
 * qmi_message_wms_send_from_memory_storage_input_set_sms_on_ims:
 * @self: a #QmiMessageWmsSendFromMemoryStorageInput.
 * @sms_on_ims: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'SMS on IMS' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_send_from_memory_storage_input_set_sms_on_ims (
    QmiMessageWmsSendFromMemoryStorageInput *self,
    gboolean sms_on_ims,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_sms_on_ims = (guint8)(sms_on_ims);
    self->arg_sms_on_ims_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wms_send_from_memory_storage_input_get_information:
 * @self: a #QmiMessageWmsSendFromMemoryStorageInput.
 * @information_storage_type: a placeholder for the output #QmiWmsStorageType, or %NULL if not required.
 * @information_memory_index: a placeholder for the output #guint32, or %NULL if not required.
 * @information_message_mode: a placeholder for the output #QmiWmsMessageMode, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Information' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_send_from_memory_storage_input_get_information (
    QmiMessageWmsSendFromMemoryStorageInput *self,
    QmiWmsStorageType *information_storage_type,
    guint32 *information_memory_index,
    QmiWmsMessageMode *information_message_mode,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_information_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Information' was not found in the message");
        return FALSE;
    }

    if (information_storage_type)
        *information_storage_type = (QmiWmsStorageType)(self->arg_information_storage_type);
    if (information_memory_index)
        *information_memory_index = self->arg_information_memory_index;
    if (information_message_mode)
        *information_message_mode = (QmiWmsMessageMode)(self->arg_information_message_mode);

    return TRUE;
}

/**
 * qmi_message_wms_send_from_memory_storage_input_set_information:
 * @self: a #QmiMessageWmsSendFromMemoryStorageInput.
 * @information_storage_type: a #QmiWmsStorageType.
 * @information_memory_index: a #guint32.
 * @information_message_mode: a #QmiWmsMessageMode.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Information' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wms_send_from_memory_storage_input_set_information (
    QmiMessageWmsSendFromMemoryStorageInput *self,
    QmiWmsStorageType information_storage_type,
    guint32 information_memory_index,
    QmiWmsMessageMode information_message_mode,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_information_storage_type = (guint8)(information_storage_type);
    self->arg_information_memory_index = information_memory_index;
    self->arg_information_message_mode = (guint8)(information_message_mode);
    self->arg_information_set = TRUE;

    return TRUE;
}

GType
qmi_message_wms_send_from_memory_storage_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsSendFromMemoryStorageInput"),
                                          (GBoxedCopyFunc) qmi_message_wms_send_from_memory_storage_input_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_send_from_memory_storage_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_send_from_memory_storage_input_ref:
 * @self: a #QmiMessageWmsSendFromMemoryStorageInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsSendFromMemoryStorageInput *
qmi_message_wms_send_from_memory_storage_input_ref (QmiMessageWmsSendFromMemoryStorageInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_send_from_memory_storage_input_unref:
 * @self: a #QmiMessageWmsSendFromMemoryStorageInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_send_from_memory_storage_input_unref (QmiMessageWmsSendFromMemoryStorageInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWmsSendFromMemoryStorageInput, self);
    }
}

/**
 * qmi_message_wms_send_from_memory_storage_input_new:
 *
 * Allocates a new #QmiMessageWmsSendFromMemoryStorageInput.
 *
 * Returns: the newly created #QmiMessageWmsSendFromMemoryStorageInput. The returned value should be freed with qmi_message_wms_send_from_memory_storage_input_unref().
 */
QmiMessageWmsSendFromMemoryStorageInput *
qmi_message_wms_send_from_memory_storage_input_new (void)
{
    QmiMessageWmsSendFromMemoryStorageInput *self;

    self = g_slice_new0 (QmiMessageWmsSendFromMemoryStorageInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_wms_send_from_memory_storage_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessageWmsSendFromMemoryStorageInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WMS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Send From Memory Storage' has mandatory TLVs");
        qmi_message_unref (self);
        return NULL;
    }

    /* Try to add the 'SMS on IMS' TLV */
    if (input->arg_sms_on_ims_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_sms_on_ims;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_INPUT_TLV_SMS_ON_IMS,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the SMS on IMS TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Information' TLV */
    if (input->arg_information_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_information_storage_type;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }
        /* Write the guint32 variable to the buffer */
        qmi_utils_write_guint32_to_buffer (
            &buffer_aux,
            &buffer_len,
            QMI_ENDIAN_LITTLE,
            &(input->arg_information_memory_index));
        {
            guint8 tmp;

            tmp = (guint8)input->arg_information_message_mode;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_INPUT_TLV_INFORMATION,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Information TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'Information' in message 'Send From Memory Storage'");
        qmi_message_unref (self);
        return NULL;
    }

    return self;
}

/* --- Output -- */

struct _QmiMessageWmsSendFromMemoryStorageOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Message ID */
    gboolean arg_message_id_set;
    guint16 arg_message_id;

    /* CDMA Cause Code */
    gboolean arg_cdma_cause_code_set;
    guint16 arg_cdma_cause_code;

    /* CDMA Error Class */
    gboolean arg_cdma_error_class_set;
    guint8 arg_cdma_error_class;

    /* GSM WCDMA Cause Info */
    gboolean arg_gsm_wcdma_cause_info_set;
    guint16 arg_gsm_wcdma_cause_info_rp_cause;
    guint8 arg_gsm_wcdma_cause_info_tp_cause;

    /* Message Delivery Failure Type */
    gboolean arg_message_delivery_failure_type_set;
    guint8 arg_message_delivery_failure_type;
};

#define QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_MESSAGE_ID 0x10
#define QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_CDMA_CAUSE_CODE 0x11
#define QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_CDMA_ERROR_CLASS 0x12
#define QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_GSM_WCDMA_CAUSE_INFO 0x13
#define QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_MESSAGE_DELIVERY_FAILURE_TYPE 0x14

/**
 * qmi_message_wms_send_from_memory_storage_output_get_result:
 * @self: a QmiMessageWmsSendFromMemoryStorageOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wms_send_from_memory_storage_output_get_result (
    QmiMessageWmsSendFromMemoryStorageOutput *self,
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
 * qmi_message_wms_send_from_memory_storage_output_get_message_id:
 * @self: a #QmiMessageWmsSendFromMemoryStorageOutput.
 * @message_id: a placeholder for the output #guint16, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Message ID' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_send_from_memory_storage_output_get_message_id (
    QmiMessageWmsSendFromMemoryStorageOutput *self,
    guint16 *message_id,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_message_id_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Message ID' was not found in the message");
        return FALSE;
    }

    if (message_id)
        *message_id = self->arg_message_id;

    return TRUE;
}

/**
 * qmi_message_wms_send_from_memory_storage_output_get_cdma_cause_code:
 * @self: a #QmiMessageWmsSendFromMemoryStorageOutput.
 * @cdma_cause_code: a placeholder for the output #QmiWmsCdmaCauseCode, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'CDMA Cause Code' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_send_from_memory_storage_output_get_cdma_cause_code (
    QmiMessageWmsSendFromMemoryStorageOutput *self,
    QmiWmsCdmaCauseCode *cdma_cause_code,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_cdma_cause_code_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'CDMA Cause Code' was not found in the message");
        return FALSE;
    }

    if (cdma_cause_code)
        *cdma_cause_code = (QmiWmsCdmaCauseCode)(self->arg_cdma_cause_code);

    return TRUE;
}

/**
 * qmi_message_wms_send_from_memory_storage_output_get_cdma_error_class:
 * @self: a #QmiMessageWmsSendFromMemoryStorageOutput.
 * @cdma_error_class: a placeholder for the output #QmiWmsCdmaErrorClass, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'CDMA Error Class' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_send_from_memory_storage_output_get_cdma_error_class (
    QmiMessageWmsSendFromMemoryStorageOutput *self,
    QmiWmsCdmaErrorClass *cdma_error_class,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_cdma_error_class_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'CDMA Error Class' was not found in the message");
        return FALSE;
    }

    if (cdma_error_class)
        *cdma_error_class = (QmiWmsCdmaErrorClass)(self->arg_cdma_error_class);

    return TRUE;
}

/**
 * qmi_message_wms_send_from_memory_storage_output_get_gsm_wcdma_cause_info:
 * @self: a #QmiMessageWmsSendFromMemoryStorageOutput.
 * @gsm_wcdma_cause_info_rp_cause: a placeholder for the output #QmiWmsGsmUmtsRpCause, or %NULL if not required.
 * @gsm_wcdma_cause_info_tp_cause: a placeholder for the output #QmiWmsGsmUmtsTpCause, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'GSM WCDMA Cause Info' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_send_from_memory_storage_output_get_gsm_wcdma_cause_info (
    QmiMessageWmsSendFromMemoryStorageOutput *self,
    QmiWmsGsmUmtsRpCause *gsm_wcdma_cause_info_rp_cause,
    QmiWmsGsmUmtsTpCause *gsm_wcdma_cause_info_tp_cause,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_gsm_wcdma_cause_info_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'GSM WCDMA Cause Info' was not found in the message");
        return FALSE;
    }

    if (gsm_wcdma_cause_info_rp_cause)
        *gsm_wcdma_cause_info_rp_cause = (QmiWmsGsmUmtsRpCause)(self->arg_gsm_wcdma_cause_info_rp_cause);
    if (gsm_wcdma_cause_info_tp_cause)
        *gsm_wcdma_cause_info_tp_cause = (QmiWmsGsmUmtsTpCause)(self->arg_gsm_wcdma_cause_info_tp_cause);

    return TRUE;
}

/**
 * qmi_message_wms_send_from_memory_storage_output_get_message_delivery_failure_type:
 * @self: a #QmiMessageWmsSendFromMemoryStorageOutput.
 * @message_delivery_failure_type: a placeholder for the output #QmiWmsMessageDeliveryFailureType, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Message Delivery Failure Type' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wms_send_from_memory_storage_output_get_message_delivery_failure_type (
    QmiMessageWmsSendFromMemoryStorageOutput *self,
    QmiWmsMessageDeliveryFailureType *message_delivery_failure_type,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_message_delivery_failure_type_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Message Delivery Failure Type' was not found in the message");
        return FALSE;
    }

    if (message_delivery_failure_type)
        *message_delivery_failure_type = (QmiWmsMessageDeliveryFailureType)(self->arg_message_delivery_failure_type);

    return TRUE;
}

GType
qmi_message_wms_send_from_memory_storage_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWmsSendFromMemoryStorageOutput"),
                                          (GBoxedCopyFunc) qmi_message_wms_send_from_memory_storage_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wms_send_from_memory_storage_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wms_send_from_memory_storage_output_ref:
 * @self: a #QmiMessageWmsSendFromMemoryStorageOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWmsSendFromMemoryStorageOutput *
qmi_message_wms_send_from_memory_storage_output_ref (QmiMessageWmsSendFromMemoryStorageOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wms_send_from_memory_storage_output_unref:
 * @self: a #QmiMessageWmsSendFromMemoryStorageOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wms_send_from_memory_storage_output_unref (QmiMessageWmsSendFromMemoryStorageOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWmsSendFromMemoryStorageOutput, self);
    }
}

static gboolean
qmi_message_wms_send_from_memory_storage_input_sms_on_ims_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'SMS on IMS' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'SMS on IMS' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_send_from_memory_storage_input_sms_on_ims_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_INPUT_TLV_SMS_ON_IMS,
                                      &buffer_len);
    if (buffer && qmi_message_wms_send_from_memory_storage_input_sms_on_ims_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

            g_string_append_printf (printable, "%s", tmp ? "yes" : "no");
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'SMS on IMS' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_send_from_memory_storage_input_information_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;
    expected_len += 4;
    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Information' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Information' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_send_from_memory_storage_input_information_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_INPUT_TLV_INFORMATION,
                                      &buffer_len);
    if (buffer && qmi_message_wms_send_from_memory_storage_input_information_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " storage_type = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_STORAGE_TYPE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_storage_type_get_string ((QmiWmsStorageType)tmp));
#elif defined  __QMI_WMS_STORAGE_TYPE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_storage_type_build_string_from_mask ((QmiWmsStorageType)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsStorageType
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " memory_index = '");

        {
            guint32 tmp;

            /* Read the guint32 variable from the buffer */
            qmi_utils_read_guint32_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &tmp);

            g_string_append_printf (printable, "%" G_GUINT32_FORMAT "", tmp);
        }
        g_string_append (printable, "'");
        g_string_append (printable, " message_mode = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_MESSAGE_MODE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_message_mode_get_string ((QmiWmsMessageMode)tmp));
#elif defined  __QMI_WMS_MESSAGE_MODE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_message_mode_build_string_from_mask ((QmiWmsMessageMode)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsMessageMode
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " ]");

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Information' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_send_from_memory_storage_output_message_id_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 2;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Message ID' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Message ID' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_send_from_memory_storage_output_message_id_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_MESSAGE_ID,
                                      &buffer_len);
    if (buffer && qmi_message_wms_send_from_memory_storage_output_message_id_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Message ID' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_send_from_memory_storage_output_cdma_cause_code_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 2;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'CDMA Cause Code' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'CDMA Cause Code' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_send_from_memory_storage_output_cdma_cause_code_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_CDMA_CAUSE_CODE,
                                      &buffer_len);
    if (buffer && qmi_message_wms_send_from_memory_storage_output_cdma_cause_code_validate (buffer, buffer_len)) {
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

#if defined  __QMI_WMS_CDMA_CAUSE_CODE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_cdma_cause_code_get_string ((QmiWmsCdmaCauseCode)tmp));
#elif defined  __QMI_WMS_CDMA_CAUSE_CODE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_cdma_cause_code_build_string_from_mask ((QmiWmsCdmaCauseCode)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsCdmaCauseCode
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'CDMA Cause Code' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_send_from_memory_storage_output_cdma_error_class_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'CDMA Error Class' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'CDMA Error Class' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_send_from_memory_storage_output_cdma_error_class_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_CDMA_ERROR_CLASS,
                                      &buffer_len);
    if (buffer && qmi_message_wms_send_from_memory_storage_output_cdma_error_class_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_CDMA_ERROR_CLASS_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_cdma_error_class_get_string ((QmiWmsCdmaErrorClass)tmp));
#elif defined  __QMI_WMS_CDMA_ERROR_CLASS_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_cdma_error_class_build_string_from_mask ((QmiWmsCdmaErrorClass)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsCdmaErrorClass
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'CDMA Error Class' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_send_from_memory_storage_output_gsm_wcdma_cause_info_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 2;
    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'GSM WCDMA Cause Info' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'GSM WCDMA Cause Info' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_send_from_memory_storage_output_gsm_wcdma_cause_info_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_GSM_WCDMA_CAUSE_INFO,
                                      &buffer_len);
    if (buffer && qmi_message_wms_send_from_memory_storage_output_gsm_wcdma_cause_info_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " rp_cause = '");

        {
            guint16 tmp;

            /* Read the guint16 variable from the buffer */
            qmi_utils_read_guint16_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &tmp);

#if defined  __QMI_WMS_GSM_UMTS_RP_CAUSE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_gsm_umts_rp_cause_get_string ((QmiWmsGsmUmtsRpCause)tmp));
#elif defined  __QMI_WMS_GSM_UMTS_RP_CAUSE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_gsm_umts_rp_cause_build_string_from_mask ((QmiWmsGsmUmtsRpCause)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsGsmUmtsRpCause
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " tp_cause = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_GSM_UMTS_TP_CAUSE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_gsm_umts_tp_cause_get_string ((QmiWmsGsmUmtsTpCause)tmp));
#elif defined  __QMI_WMS_GSM_UMTS_TP_CAUSE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_gsm_umts_tp_cause_build_string_from_mask ((QmiWmsGsmUmtsTpCause)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsGsmUmtsTpCause
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " ]");

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'GSM WCDMA Cause Info' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wms_send_from_memory_storage_output_message_delivery_failure_type_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Message Delivery Failure Type' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Message Delivery Failure Type' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wms_send_from_memory_storage_output_message_delivery_failure_type_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_MESSAGE_DELIVERY_FAILURE_TYPE,
                                      &buffer_len);
    if (buffer && qmi_message_wms_send_from_memory_storage_output_message_delivery_failure_type_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WMS_MESSAGE_DELIVERY_FAILURE_TYPE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wms_message_delivery_failure_type_get_string ((QmiWmsMessageDeliveryFailureType)tmp));
#elif defined  __QMI_WMS_MESSAGE_DELIVERY_FAILURE_TYPE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wms_message_delivery_failure_type_build_string_from_mask ((QmiWmsMessageDeliveryFailureType)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWmsMessageDeliveryFailureType
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Message Delivery Failure Type' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_send_from_memory_storage_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_send_from_memory_storage_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_send_from_memory_storage_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_INPUT_TLV_SMS_ON_IMS:
            tlv_type_str = "SMS on IMS";
            translated_value = qmi_message_wms_send_from_memory_storage_input_sms_on_ims_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_INPUT_TLV_INFORMATION:
            tlv_type_str = "Information";
            translated_value = qmi_message_wms_send_from_memory_storage_input_information_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_MESSAGE_ID:
            tlv_type_str = "Message ID";
            translated_value = qmi_message_wms_send_from_memory_storage_output_message_id_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_CDMA_CAUSE_CODE:
            tlv_type_str = "CDMA Cause Code";
            translated_value = qmi_message_wms_send_from_memory_storage_output_cdma_cause_code_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_CDMA_ERROR_CLASS:
            tlv_type_str = "CDMA Error Class";
            translated_value = qmi_message_wms_send_from_memory_storage_output_cdma_error_class_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_GSM_WCDMA_CAUSE_INFO:
            tlv_type_str = "GSM WCDMA Cause Info";
            translated_value = qmi_message_wms_send_from_memory_storage_output_gsm_wcdma_cause_info_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_MESSAGE_DELIVERY_FAILURE_TYPE:
            tlv_type_str = "Message Delivery Failure Type";
            translated_value = qmi_message_wms_send_from_memory_storage_output_message_delivery_failure_type_get_printable (
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
message_send_from_memory_storage_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Send From Memory Storage\" (0x0042)\n",
                            line_prefix);

    {
        struct message_send_from_memory_storage_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_send_from_memory_storage_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageWmsSendFromMemoryStorageOutput *
__qmi_message_wms_send_from_memory_storage_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWmsSendFromMemoryStorageOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE, NULL);

    self = g_slice_new0 (QmiMessageWmsSendFromMemoryStorageOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_RESULT,
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
                qmi_message_wms_send_from_memory_storage_output_unref (self);
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
                                              QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_MESSAGE_ID,
                                              &buffer_len);
            if (buffer && qmi_message_wms_send_from_memory_storage_output_message_id_validate (buffer, buffer_len)) {
                self->arg_message_id_set = TRUE;

                /* Read the guint16 variable from the buffer */
                qmi_utils_read_guint16_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_message_id));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Message ID' TLV", buffer_len);
                }
            }

        }
    } while (0);

    do {
        /* Prerequisite.... */
        if (!(self->arg_result.error_status != QMI_STATUS_SUCCESS))
            break;
        /* Prerequisite.... */
        if (!(self->arg_result.error_code == QMI_PROTOCOL_ERROR_WMS_CAUSE_CODE))
            break;

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_CDMA_CAUSE_CODE,
                                              &buffer_len);
            if (buffer && qmi_message_wms_send_from_memory_storage_output_cdma_cause_code_validate (buffer, buffer_len)) {
                self->arg_cdma_cause_code_set = TRUE;

                {
                    guint16 tmp;

                    /* Read the guint16 variable from the buffer */
                    qmi_utils_read_guint16_from_buffer (
                        &buffer,
                        &buffer_len,
                        QMI_ENDIAN_LITTLE,
                        &tmp);
                    self->arg_cdma_cause_code = (QmiWmsCdmaCauseCode)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'CDMA Cause Code' TLV", buffer_len);
                }
            }

        }
    } while (0);

    do {
        /* Prerequisite.... */
        if (!(self->arg_result.error_status != QMI_STATUS_SUCCESS))
            break;
        /* Prerequisite.... */
        if (!(self->arg_result.error_code == QMI_PROTOCOL_ERROR_WMS_CAUSE_CODE))
            break;

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_CDMA_ERROR_CLASS,
                                              &buffer_len);
            if (buffer && qmi_message_wms_send_from_memory_storage_output_cdma_error_class_validate (buffer, buffer_len)) {
                self->arg_cdma_error_class_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_cdma_error_class = (QmiWmsCdmaErrorClass)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'CDMA Error Class' TLV", buffer_len);
                }
            }

        }
    } while (0);

    do {
        /* Prerequisite.... */
        if (!(self->arg_result.error_status != QMI_STATUS_SUCCESS))
            break;
        /* Prerequisite.... */
        if (!(self->arg_result.error_code == QMI_PROTOCOL_ERROR_WMS_CAUSE_CODE))
            break;

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_GSM_WCDMA_CAUSE_INFO,
                                              &buffer_len);
            if (buffer && qmi_message_wms_send_from_memory_storage_output_gsm_wcdma_cause_info_validate (buffer, buffer_len)) {
                self->arg_gsm_wcdma_cause_info_set = TRUE;

                {
                    guint16 tmp;

                    /* Read the guint16 variable from the buffer */
                    qmi_utils_read_guint16_from_buffer (
                        &buffer,
                        &buffer_len,
                        QMI_ENDIAN_LITTLE,
                        &tmp);
                    self->arg_gsm_wcdma_cause_info_rp_cause = (QmiWmsGsmUmtsRpCause)tmp;
                }
                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_gsm_wcdma_cause_info_tp_cause = (QmiWmsGsmUmtsTpCause)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'GSM WCDMA Cause Info' TLV", buffer_len);
                }
            }

        }
    } while (0);

    do {
        /* Prerequisite.... */
        if (!(self->arg_result.error_status != QMI_STATUS_SUCCESS))
            break;
        /* Prerequisite.... */
        if (!(self->arg_result.error_code == QMI_PROTOCOL_ERROR_WMS_CAUSE_CODE))
            break;

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE_OUTPUT_TLV_MESSAGE_DELIVERY_FAILURE_TYPE,
                                              &buffer_len);
            if (buffer && qmi_message_wms_send_from_memory_storage_output_message_delivery_failure_type_validate (buffer, buffer_len)) {
                self->arg_message_delivery_failure_type_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_message_delivery_failure_type = (QmiWmsMessageDeliveryFailureType)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Message Delivery Failure Type' TLV", buffer_len);
                }
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* Service-specific printable: WMS */


gchar *
__qmi_message_wms_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    if (qmi_message_is_indication (self)) {
        switch (qmi_message_get_message_id (self)) {
        case QMI_INDICATION_WMS_EVENT_REPORT:
            return indication_event_report_get_printable (self, line_prefix);
         default:
             return NULL;
        }
    } else {
        switch (qmi_message_get_message_id (self)) {
        case QMI_MESSAGE_WMS_RESET:
            return message_reset_get_printable (self, line_prefix);
        case QMI_MESSAGE_WMS_SET_EVENT_REPORT:
            return message_set_event_report_get_printable (self, line_prefix);
        case QMI_MESSAGE_WMS_RAW_SEND:
            return message_raw_send_get_printable (self, line_prefix);
        case QMI_MESSAGE_WMS_RAW_WRITE:
            return message_raw_write_get_printable (self, line_prefix);
        case QMI_MESSAGE_WMS_RAW_READ:
            return message_raw_read_get_printable (self, line_prefix);
        case QMI_MESSAGE_WMS_MODIFY_TAG:
            return message_modify_tag_get_printable (self, line_prefix);
        case QMI_MESSAGE_WMS_DELETE:
            return message_delete_get_printable (self, line_prefix);
        case QMI_MESSAGE_WMS_GET_MESSAGE_PROTOCOL:
            return message_get_message_protocol_get_printable (self, line_prefix);
        case QMI_MESSAGE_WMS_LIST_MESSAGES:
            return message_list_messages_get_printable (self, line_prefix);
        case QMI_MESSAGE_WMS_SET_ROUTES:
            return message_set_routes_get_printable (self, line_prefix);
        case QMI_MESSAGE_WMS_GET_ROUTES:
            return message_get_routes_get_printable (self, line_prefix);
        case QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE:
            return message_send_from_memory_storage_get_printable (self, line_prefix);
         default:
             return NULL;
        }
    }
}

gboolean
__qmi_message_wms_get_version_introduced (
    QmiMessage *self,
    guint *major,
    guint *minor)
{
    switch (qmi_message_get_message_id (self)) {
    case QMI_MESSAGE_WMS_RESET:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_WMS_SET_EVENT_REPORT:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_WMS_RAW_SEND:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_WMS_RAW_WRITE:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_WMS_RAW_READ:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_WMS_MODIFY_TAG:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_WMS_DELETE:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_WMS_GET_MESSAGE_PROTOCOL:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_WMS_LIST_MESSAGES:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_WMS_SET_ROUTES:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_WMS_GET_ROUTES:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_WMS_SEND_FROM_MEMORY_STORAGE:
        *major = 1;
        *minor = 2;
        return TRUE;
    default:
        return FALSE;
    }
}

/*****************************************************************************/
/* CLIENT: QMI Client WMS */


/**
 * SECTION: qmi-client-wms
 * @title: QmiClientWms
 * @short_description: #QmiClient for the WMS service.
 *
 * #QmiClient which handles operations in the WMS service.
 */

G_DEFINE_TYPE (QmiClientWms, qmi_client_wms, QMI_TYPE_CLIENT);

enum {
    SIGNAL_EVENT_REPORT,
    SIGNAL_LAST
};

static guint signals[SIGNAL_LAST] = { 0 };

static void
process_indication (QmiClient *self,
                    QmiMessage *message)
{
    switch (qmi_message_get_message_id (message)) {
        case QMI_INDICATION_WMS_EVENT_REPORT: {
            QmiIndicationWmsEventReportOutput *output;
            GError *error = NULL;

            /* Parse indication */
            output = __qmi_indication_wms_event_report_indication_parse (message, &error);
            if (!output) {
                g_warning ("Couldn't parse 'Event Report' indication: %s",
                           error ? error->message : "Unknown error");
                if (error)
                    g_error_free (error);
            } else {
                g_signal_emit (self, signals[SIGNAL_EVENT_REPORT], 0, output);
                qmi_indication_wms_event_report_output_unref (output);
            }
            break;
        }
        default:
            break;
    }
}

static void
qmi_client_wms_init (QmiClientWms *self)
{
}

static void
qmi_client_wms_class_init (QmiClientWmsClass *klass)
{
    QmiClientClass *client_class = QMI_CLIENT_CLASS (klass);

    client_class->process_indication = process_indication;

    /**
     * QmiClientWms::event-report:
     * @object: A #QmiClientWms.
     * @output: A #QmiIndicationWmsEventReportOutput.
     *
     * The ::event-report signal gets emitted when a '<link linkend="libqmi-glib-WMS-Event-Report.top_of_page">Event Report</link>' indication is received.
     */
    signals[SIGNAL_EVENT_REPORT] =
        g_signal_new ("event-report",
                      G_OBJECT_CLASS_TYPE (G_OBJECT_CLASS (klass)),
                      G_SIGNAL_RUN_LAST,
                      0,
                      NULL,
                      NULL,
                      NULL,
                      G_TYPE_NONE,
                      1,
                      QMI_TYPE_INDICATION_WMS_EVENT_REPORT_OUTPUT);
}


/**
 * qmi_client_wms_reset_finish:
 * @self: a #QmiClientWms.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_wms_reset().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_wms_reset().
 *
 * Returns: a #QmiMessageWmsResetOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_wms_reset_output_unref().
 */
QmiMessageWmsResetOutput *
qmi_client_wms_reset_finish (
    QmiClientWms *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_wms_reset_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
reset_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWmsResetOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_wms_reset_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_wms_reset_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_wms_reset:
 * @self: a #QmiClientWms.
 * @unused: %NULL. This message doesn't have any input bundle.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Reset request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_wms_reset_finish() to get the result of the operation.
 */
void
qmi_client_wms_reset (
    QmiClientWms *self,
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
                                        qmi_client_wms_reset);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_wms_reset_request_create (
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
                        (GAsyncReadyCallback)reset_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_wms_set_event_report_finish:
 * @self: a #QmiClientWms.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_wms_set_event_report().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_wms_set_event_report().
 *
 * Returns: a #QmiMessageWmsSetEventReportOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_wms_set_event_report_output_unref().
 */
QmiMessageWmsSetEventReportOutput *
qmi_client_wms_set_event_report_finish (
    QmiClientWms *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_wms_set_event_report_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
set_event_report_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWmsSetEventReportOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_wms_set_event_report_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_wms_set_event_report_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_wms_set_event_report:
 * @self: a #QmiClientWms.
 * @input: a #QmiMessageWmsSetEventReportInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Set Event Report request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_wms_set_event_report_finish() to get the result of the operation.
 */
void
qmi_client_wms_set_event_report (
    QmiClientWms *self,
    QmiMessageWmsSetEventReportInput *input,
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
                                        qmi_client_wms_set_event_report);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_wms_set_event_report_request_create (
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
                        (GAsyncReadyCallback)set_event_report_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_wms_raw_send_finish:
 * @self: a #QmiClientWms.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_wms_raw_send().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_wms_raw_send().
 *
 * Returns: a #QmiMessageWmsRawSendOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_wms_raw_send_output_unref().
 */
QmiMessageWmsRawSendOutput *
qmi_client_wms_raw_send_finish (
    QmiClientWms *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_wms_raw_send_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
raw_send_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWmsRawSendOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_wms_raw_send_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_wms_raw_send_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_wms_raw_send:
 * @self: a #QmiClientWms.
 * @input: a #QmiMessageWmsRawSendInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Raw Send request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_wms_raw_send_finish() to get the result of the operation.
 */
void
qmi_client_wms_raw_send (
    QmiClientWms *self,
    QmiMessageWmsRawSendInput *input,
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
                                        qmi_client_wms_raw_send);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_wms_raw_send_request_create (
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
                        (GAsyncReadyCallback)raw_send_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_wms_raw_write_finish:
 * @self: a #QmiClientWms.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_wms_raw_write().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_wms_raw_write().
 *
 * Returns: a #QmiMessageWmsRawWriteOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_wms_raw_write_output_unref().
 */
QmiMessageWmsRawWriteOutput *
qmi_client_wms_raw_write_finish (
    QmiClientWms *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_wms_raw_write_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
raw_write_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWmsRawWriteOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_wms_raw_write_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_wms_raw_write_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_wms_raw_write:
 * @self: a #QmiClientWms.
 * @input: a #QmiMessageWmsRawWriteInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Raw Write request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_wms_raw_write_finish() to get the result of the operation.
 */
void
qmi_client_wms_raw_write (
    QmiClientWms *self,
    QmiMessageWmsRawWriteInput *input,
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
                                        qmi_client_wms_raw_write);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_wms_raw_write_request_create (
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
                        (GAsyncReadyCallback)raw_write_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_wms_raw_read_finish:
 * @self: a #QmiClientWms.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_wms_raw_read().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_wms_raw_read().
 *
 * Returns: a #QmiMessageWmsRawReadOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_wms_raw_read_output_unref().
 */
QmiMessageWmsRawReadOutput *
qmi_client_wms_raw_read_finish (
    QmiClientWms *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_wms_raw_read_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
raw_read_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWmsRawReadOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_wms_raw_read_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_wms_raw_read_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_wms_raw_read:
 * @self: a #QmiClientWms.
 * @input: a #QmiMessageWmsRawReadInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Raw Read request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_wms_raw_read_finish() to get the result of the operation.
 */
void
qmi_client_wms_raw_read (
    QmiClientWms *self,
    QmiMessageWmsRawReadInput *input,
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
                                        qmi_client_wms_raw_read);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_wms_raw_read_request_create (
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
                        (GAsyncReadyCallback)raw_read_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_wms_modify_tag_finish:
 * @self: a #QmiClientWms.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_wms_modify_tag().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_wms_modify_tag().
 *
 * Returns: a #QmiMessageWmsModifyTagOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_wms_modify_tag_output_unref().
 */
QmiMessageWmsModifyTagOutput *
qmi_client_wms_modify_tag_finish (
    QmiClientWms *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_wms_modify_tag_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
modify_tag_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWmsModifyTagOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_wms_modify_tag_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_wms_modify_tag_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_wms_modify_tag:
 * @self: a #QmiClientWms.
 * @input: a #QmiMessageWmsModifyTagInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Modify Tag request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_wms_modify_tag_finish() to get the result of the operation.
 */
void
qmi_client_wms_modify_tag (
    QmiClientWms *self,
    QmiMessageWmsModifyTagInput *input,
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
                                        qmi_client_wms_modify_tag);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_wms_modify_tag_request_create (
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
                        (GAsyncReadyCallback)modify_tag_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_wms_delete_finish:
 * @self: a #QmiClientWms.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_wms_delete().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_wms_delete().
 *
 * Returns: a #QmiMessageWmsDeleteOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_wms_delete_output_unref().
 */
QmiMessageWmsDeleteOutput *
qmi_client_wms_delete_finish (
    QmiClientWms *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_wms_delete_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
delete_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWmsDeleteOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_wms_delete_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_wms_delete_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_wms_delete:
 * @self: a #QmiClientWms.
 * @input: a #QmiMessageWmsDeleteInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Delete request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_wms_delete_finish() to get the result of the operation.
 */
void
qmi_client_wms_delete (
    QmiClientWms *self,
    QmiMessageWmsDeleteInput *input,
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
                                        qmi_client_wms_delete);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_wms_delete_request_create (
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
                        (GAsyncReadyCallback)delete_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_wms_get_message_protocol_finish:
 * @self: a #QmiClientWms.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_wms_get_message_protocol().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_wms_get_message_protocol().
 *
 * Returns: a #QmiMessageWmsGetMessageProtocolOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_wms_get_message_protocol_output_unref().
 */
QmiMessageWmsGetMessageProtocolOutput *
qmi_client_wms_get_message_protocol_finish (
    QmiClientWms *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_wms_get_message_protocol_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
get_message_protocol_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWmsGetMessageProtocolOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_wms_get_message_protocol_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_wms_get_message_protocol_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_wms_get_message_protocol:
 * @self: a #QmiClientWms.
 * @unused: %NULL. This message doesn't have any input bundle.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Get Message Protocol request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_wms_get_message_protocol_finish() to get the result of the operation.
 */
void
qmi_client_wms_get_message_protocol (
    QmiClientWms *self,
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
                                        qmi_client_wms_get_message_protocol);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_wms_get_message_protocol_request_create (
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
                        (GAsyncReadyCallback)get_message_protocol_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_wms_list_messages_finish:
 * @self: a #QmiClientWms.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_wms_list_messages().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_wms_list_messages().
 *
 * Returns: a #QmiMessageWmsListMessagesOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_wms_list_messages_output_unref().
 */
QmiMessageWmsListMessagesOutput *
qmi_client_wms_list_messages_finish (
    QmiClientWms *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_wms_list_messages_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
list_messages_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWmsListMessagesOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_wms_list_messages_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_wms_list_messages_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_wms_list_messages:
 * @self: a #QmiClientWms.
 * @input: a #QmiMessageWmsListMessagesInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a List Messages request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_wms_list_messages_finish() to get the result of the operation.
 */
void
qmi_client_wms_list_messages (
    QmiClientWms *self,
    QmiMessageWmsListMessagesInput *input,
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
                                        qmi_client_wms_list_messages);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_wms_list_messages_request_create (
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
                        (GAsyncReadyCallback)list_messages_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_wms_set_routes_finish:
 * @self: a #QmiClientWms.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_wms_set_routes().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_wms_set_routes().
 *
 * Returns: a #QmiMessageWmsSetRoutesOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_wms_set_routes_output_unref().
 */
QmiMessageWmsSetRoutesOutput *
qmi_client_wms_set_routes_finish (
    QmiClientWms *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_wms_set_routes_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
set_routes_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWmsSetRoutesOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_wms_set_routes_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_wms_set_routes_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_wms_set_routes:
 * @self: a #QmiClientWms.
 * @input: a #QmiMessageWmsSetRoutesInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Set Routes request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_wms_set_routes_finish() to get the result of the operation.
 */
void
qmi_client_wms_set_routes (
    QmiClientWms *self,
    QmiMessageWmsSetRoutesInput *input,
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
                                        qmi_client_wms_set_routes);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_wms_set_routes_request_create (
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
                        (GAsyncReadyCallback)set_routes_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_wms_get_routes_finish:
 * @self: a #QmiClientWms.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_wms_get_routes().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_wms_get_routes().
 *
 * Returns: a #QmiMessageWmsGetRoutesOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_wms_get_routes_output_unref().
 */
QmiMessageWmsGetRoutesOutput *
qmi_client_wms_get_routes_finish (
    QmiClientWms *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_wms_get_routes_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
get_routes_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWmsGetRoutesOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_wms_get_routes_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_wms_get_routes_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_wms_get_routes:
 * @self: a #QmiClientWms.
 * @unused: %NULL. This message doesn't have any input bundle.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Get Routes request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_wms_get_routes_finish() to get the result of the operation.
 */
void
qmi_client_wms_get_routes (
    QmiClientWms *self,
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
                                        qmi_client_wms_get_routes);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_wms_get_routes_request_create (
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
                        (GAsyncReadyCallback)get_routes_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_wms_send_from_memory_storage_finish:
 * @self: a #QmiClientWms.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_wms_send_from_memory_storage().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_wms_send_from_memory_storage().
 *
 * Returns: a #QmiMessageWmsSendFromMemoryStorageOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_wms_send_from_memory_storage_output_unref().
 */
QmiMessageWmsSendFromMemoryStorageOutput *
qmi_client_wms_send_from_memory_storage_finish (
    QmiClientWms *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_wms_send_from_memory_storage_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
send_from_memory_storage_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWmsSendFromMemoryStorageOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_wms_send_from_memory_storage_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_wms_send_from_memory_storage_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_wms_send_from_memory_storage:
 * @self: a #QmiClientWms.
 * @input: a #QmiMessageWmsSendFromMemoryStorageInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Send From Memory Storage request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_wms_send_from_memory_storage_finish() to get the result of the operation.
 */
void
qmi_client_wms_send_from_memory_storage (
    QmiClientWms *self,
    QmiMessageWmsSendFromMemoryStorageInput *input,
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
                                        qmi_client_wms_send_from_memory_storage);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_wms_send_from_memory_storage_request_create (
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
                        (GAsyncReadyCallback)send_from_memory_storage_ready,
                        result);
    qmi_message_unref (request);
}

