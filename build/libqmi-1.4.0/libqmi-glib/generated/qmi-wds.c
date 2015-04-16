
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

#include "qmi-wds.h"
#include "qmi-enum-types.h"
#include "qmi-enum-types-private.h"
#include "qmi-flags64-types.h"
#include "qmi-error-types.h"
#include "qmi-device.h"
#include "qmi-utils.h"

#define QMI_STATUS_SUCCESS 0x0000
#define QMI_STATUS_FAILURE 0x0001


typedef enum {
    QMI_MESSAGE_WDS_RESET = 0x0000,
    QMI_MESSAGE_WDS_ABORT = 0x0002,
    QMI_MESSAGE_WDS_START_NETWORK = 0x0020,
    QMI_MESSAGE_WDS_STOP_NETWORK = 0x0021,
    QMI_MESSAGE_WDS_GET_PACKET_SERVICE_STATUS = 0x0022,
    QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS = 0x002D,
    QMI_MESSAGE_WDS_GET_DATA_BEARER_TECHNOLOGY = 0x0037,
    QMI_MESSAGE_WDS_GET_CURRENT_DATA_BEARER_TECHNOLOGY = 0x0044,
    QMI_MESSAGE_WDS_SET_IP_FAMILY = 0x004D,
} QmiMessageWds;


/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WDS Reset */


/* --- Input -- */

/* Note: no fields in the Input container */

static QmiMessage *
__qmi_message_wds_reset_request_create (
    guint8 transaction_id,
    guint8 cid,
    gpointer unused,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WDS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WDS_RESET);

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

struct _QmiMessageWdsResetOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;
};

#define QMI_MESSAGE_WDS_RESET_OUTPUT_TLV_RESULT 0x02

/**
 * qmi_message_wds_reset_output_get_result:
 * @self: a QmiMessageWdsResetOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wds_reset_output_get_result (
    QmiMessageWdsResetOutput *self,
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
qmi_message_wds_reset_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWdsResetOutput"),
                                          (GBoxedCopyFunc) qmi_message_wds_reset_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wds_reset_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wds_reset_output_ref:
 * @self: a #QmiMessageWdsResetOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWdsResetOutput *
qmi_message_wds_reset_output_ref (QmiMessageWdsResetOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wds_reset_output_unref:
 * @self: a #QmiMessageWdsResetOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wds_reset_output_unref (QmiMessageWdsResetOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWdsResetOutput, self);
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
                                      QMI_MESSAGE_WDS_RESET_OUTPUT_TLV_RESULT,
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
        case QMI_MESSAGE_WDS_RESET_OUTPUT_TLV_RESULT:
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

static QmiMessageWdsResetOutput *
__qmi_message_wds_reset_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWdsResetOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WDS_RESET, NULL);

    self = g_slice_new0 (QmiMessageWdsResetOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WDS_RESET_OUTPUT_TLV_RESULT,
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
                qmi_message_wds_reset_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WDS Abort */


/* --- Input -- */

/**
 * QmiMessageWdsAbortInput:
 *
 * The #QmiMessageWdsAbortInput structure contains private data and should only be accessed
 * using the provided API.
 */
typedef struct _QmiMessageWdsAbortInput QmiMessageWdsAbortInput;
static GType qmi_message_wds_abort_input_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_WDS_ABORT_INPUT (qmi_message_wds_abort_input_get_type ())

struct _QmiMessageWdsAbortInput {
    volatile gint ref_count;

    /* Transaction ID */
    gboolean arg_transaction_id_set;
    guint16 arg_transaction_id;
};

#define QMI_MESSAGE_WDS_ABORT_INPUT_TLV_TRANSACTION_ID 0x01

static gboolean qmi_message_wds_abort_input_get_transaction_id (
    QmiMessageWdsAbortInput *self,
    guint16 *transaction_id,
    GError **error);

/**
 * qmi_message_wds_abort_input_get_transaction_id:
 * @self: a #QmiMessageWdsAbortInput.
 * @transaction_id: a placeholder for the output #guint16, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Transaction ID' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
static gboolean
qmi_message_wds_abort_input_get_transaction_id (
    QmiMessageWdsAbortInput *self,
    guint16 *transaction_id,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_transaction_id_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Transaction ID' was not found in the message");
        return FALSE;
    }

    if (transaction_id)
        *transaction_id = self->arg_transaction_id;

    return TRUE;
}

static gboolean qmi_message_wds_abort_input_set_transaction_id (
    QmiMessageWdsAbortInput *self,
    guint16 transaction_id,
    GError **error);

/**
 * qmi_message_wds_abort_input_set_transaction_id:
 * @self: a #QmiMessageWdsAbortInput.
 * @transaction_id: a #guint16.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Transaction ID' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
static gboolean
qmi_message_wds_abort_input_set_transaction_id (
    QmiMessageWdsAbortInput *self,
    guint16 transaction_id,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_transaction_id = transaction_id;
    self->arg_transaction_id_set = TRUE;

    return TRUE;
}

static QmiMessageWdsAbortInput *qmi_message_wds_abort_input_ref (QmiMessageWdsAbortInput *self);
static void qmi_message_wds_abort_input_unref (QmiMessageWdsAbortInput *self);
static QmiMessageWdsAbortInput *qmi_message_wds_abort_input_new (void);

static GType
qmi_message_wds_abort_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWdsAbortInput"),
                                          (GBoxedCopyFunc) qmi_message_wds_abort_input_ref,
                                          (GBoxedFreeFunc) qmi_message_wds_abort_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wds_abort_input_ref:
 * @self: a #QmiMessageWdsAbortInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
static QmiMessageWdsAbortInput *
qmi_message_wds_abort_input_ref (QmiMessageWdsAbortInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wds_abort_input_unref:
 * @self: a #QmiMessageWdsAbortInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
static void
qmi_message_wds_abort_input_unref (QmiMessageWdsAbortInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWdsAbortInput, self);
    }
}

/**
 * qmi_message_wds_abort_input_new:
 *
 * Allocates a new #QmiMessageWdsAbortInput.
 *
 * Returns: the newly created #QmiMessageWdsAbortInput. The returned value should be freed with qmi_message_wds_abort_input_unref().
 */
static QmiMessageWdsAbortInput *
qmi_message_wds_abort_input_new (void)
{
    QmiMessageWdsAbortInput *self;

    self = g_slice_new0 (QmiMessageWdsAbortInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_wds_abort_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessageWdsAbortInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WDS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WDS_ABORT);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Abort' has mandatory TLVs");
        qmi_message_unref (self);
        return NULL;
    }

    /* Try to add the 'Transaction ID' TLV */
    if (input->arg_transaction_id_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        /* Write the guint16 variable to the buffer */
        qmi_utils_write_guint16_to_buffer (
            &buffer_aux,
            &buffer_len,
            QMI_ENDIAN_LITTLE,
            &(input->arg_transaction_id));

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_ABORT_INPUT_TLV_TRANSACTION_ID,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Transaction ID TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'Transaction ID' in message 'Abort'");
        qmi_message_unref (self);
        return NULL;
    }

    return self;
}

/* --- Output -- */

/**
 * QmiMessageWdsAbortOutput:
 *
 * The #QmiMessageWdsAbortOutput structure contains private data and should only be accessed
 * using the provided API.
 */
typedef struct _QmiMessageWdsAbortOutput QmiMessageWdsAbortOutput;
static GType qmi_message_wds_abort_output_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_WDS_ABORT_OUTPUT (qmi_message_wds_abort_output_get_type ())

struct _QmiMessageWdsAbortOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;
};

#define QMI_MESSAGE_WDS_ABORT_OUTPUT_TLV_RESULT 0x02

gboolean qmi_message_wds_abort_output_get_result (
    QmiMessageWdsAbortOutput *self,
    GError **error);

/**
 * qmi_message_wds_abort_output_get_result:
 * @self: a QmiMessageWdsAbortOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wds_abort_output_get_result (
    QmiMessageWdsAbortOutput *self,
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

static QmiMessageWdsAbortOutput *qmi_message_wds_abort_output_ref (QmiMessageWdsAbortOutput *self);
static void qmi_message_wds_abort_output_unref (QmiMessageWdsAbortOutput *self);

static GType
qmi_message_wds_abort_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWdsAbortOutput"),
                                          (GBoxedCopyFunc) qmi_message_wds_abort_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wds_abort_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wds_abort_output_ref:
 * @self: a #QmiMessageWdsAbortOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
static QmiMessageWdsAbortOutput *
qmi_message_wds_abort_output_ref (QmiMessageWdsAbortOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wds_abort_output_unref:
 * @self: a #QmiMessageWdsAbortOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
static void
qmi_message_wds_abort_output_unref (QmiMessageWdsAbortOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWdsAbortOutput, self);
    }
}

static gboolean
qmi_message_wds_abort_input_transaction_id_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 2;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Transaction ID' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Transaction ID' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_abort_input_transaction_id_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_ABORT_INPUT_TLV_TRANSACTION_ID,
                                      &buffer_len);
    if (buffer && qmi_message_wds_abort_input_transaction_id_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Transaction ID' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_abort_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_abort_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_abort_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_WDS_ABORT_INPUT_TLV_TRANSACTION_ID:
            tlv_type_str = "Transaction ID";
            translated_value = qmi_message_wds_abort_input_transaction_id_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_WDS_ABORT_OUTPUT_TLV_RESULT:
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
message_abort_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Abort\" (0x0002)\n",
                            line_prefix);

    {
        struct message_abort_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_abort_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageWdsAbortOutput *
__qmi_message_wds_abort_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWdsAbortOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WDS_ABORT, NULL);

    self = g_slice_new0 (QmiMessageWdsAbortOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WDS_ABORT_OUTPUT_TLV_RESULT,
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
                qmi_message_wds_abort_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WDS Start Network */


/* --- Input -- */

struct _QmiMessageWdsStartNetworkInput {
    volatile gint ref_count;

    /* Call Type */
    gboolean arg_call_type_set;
    guint8 arg_call_type;

    /* Extended Technology Preference */
    gboolean arg_extended_technology_preference_set;
    guint16 arg_extended_technology_preference;

    /* Enable Autoconnect */
    gboolean arg_enable_autoconnect_set;
    guint8 arg_enable_autoconnect;

    /* Profile Index 3GPP2 */
    gboolean arg_profile_index_3gpp2_set;
    guint8 arg_profile_index_3gpp2;

    /* Profile Index 3GPP */
    gboolean arg_profile_index_3gpp_set;
    guint8 arg_profile_index_3gpp;

    /* Technology Preference */
    gboolean arg_technology_preference_set;
    guint8 arg_technology_preference;

    /* IP Family Preference */
    gboolean arg_ip_family_preference_set;
    guint8 arg_ip_family_preference;

    /* Password */
    gboolean arg_password_set;
    gchar *arg_password;

    /* Username */
    gboolean arg_username_set;
    gchar *arg_username;

    /* Authentication Preference */
    gboolean arg_authentication_preference_set;
    guint8 arg_authentication_preference;

    /* IPv4 Address Preference */
    gboolean arg_ipv4_address_preference_set;
    guint32 arg_ipv4_address_preference;

    /* APN */
    gboolean arg_apn_set;
    gchar *arg_apn;

    /* Secondary NBNS Address Preference */
    gboolean arg_secondary_nbns_address_preference_set;
    guint32 arg_secondary_nbns_address_preference;

    /* Primary NBNS Address Preference */
    gboolean arg_primary_nbns_address_preference_set;
    guint32 arg_primary_nbns_address_preference;

    /* Secondary DNS Address Preference */
    gboolean arg_secondary_dns_address_preference_set;
    guint32 arg_secondary_dns_address_preference;

    /* Primary DNS Address Preference */
    gboolean arg_primary_dns_address_preference_set;
    guint32 arg_primary_dns_address_preference;
};

#define QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_CALL_TYPE 0x35
#define QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_EXTENDED_TECHNOLOGY_PREFERENCE 0x34
#define QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_ENABLE_AUTOCONNECT 0x33
#define QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_PROFILE_INDEX_3GPP2 0x32
#define QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_PROFILE_INDEX_3GPP 0x31
#define QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_TECHNOLOGY_PREFERENCE 0x30
#define QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_IP_FAMILY_PREFERENCE 0x19
#define QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_PASSWORD 0x18
#define QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_USERNAME 0x17
#define QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_AUTHENTICATION_PREFERENCE 0x16
#define QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_IPV4_ADDRESS_PREFERENCE 0x15
#define QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_APN 0x14
#define QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_SECONDARY_NBNS_ADDRESS_PREFERENCE 0x13
#define QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_PRIMARY_NBNS_ADDRESS_PREFERENCE 0x12
#define QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_SECONDARY_DNS_ADDRESS_PREFERENCE 0x11
#define QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_PRIMARY_DNS_ADDRESS_PREFERENCE 0x10

/**
 * qmi_message_wds_start_network_input_get_call_type:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @call_type: a placeholder for the output #QmiWdsCallType, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Call Type' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_get_call_type (
    QmiMessageWdsStartNetworkInput *self,
    QmiWdsCallType *call_type,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_call_type_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Call Type' was not found in the message");
        return FALSE;
    }

    if (call_type)
        *call_type = (QmiWdsCallType)(self->arg_call_type);

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_set_call_type:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @call_type: a #QmiWdsCallType.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Call Type' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_set_call_type (
    QmiMessageWdsStartNetworkInput *self,
    QmiWdsCallType call_type,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_call_type = (guint8)(call_type);
    self->arg_call_type_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_get_extended_technology_preference:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @extended_technology_preference: a placeholder for the output #QmiWdsExtendedTechnologyPreference, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Extended Technology Preference' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_get_extended_technology_preference (
    QmiMessageWdsStartNetworkInput *self,
    QmiWdsExtendedTechnologyPreference *extended_technology_preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_extended_technology_preference_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Extended Technology Preference' was not found in the message");
        return FALSE;
    }

    if (extended_technology_preference)
        *extended_technology_preference = (QmiWdsExtendedTechnologyPreference)(self->arg_extended_technology_preference);

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_set_extended_technology_preference:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @extended_technology_preference: a #QmiWdsExtendedTechnologyPreference.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Extended Technology Preference' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_set_extended_technology_preference (
    QmiMessageWdsStartNetworkInput *self,
    QmiWdsExtendedTechnologyPreference extended_technology_preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_extended_technology_preference = (guint16)(extended_technology_preference);
    self->arg_extended_technology_preference_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_get_enable_autoconnect:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @enable_autoconnect: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Enable Autoconnect' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_get_enable_autoconnect (
    QmiMessageWdsStartNetworkInput *self,
    gboolean *enable_autoconnect,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_enable_autoconnect_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Enable Autoconnect' was not found in the message");
        return FALSE;
    }

    if (enable_autoconnect)
        *enable_autoconnect = (gboolean)(self->arg_enable_autoconnect);

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_set_enable_autoconnect:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @enable_autoconnect: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Enable Autoconnect' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_set_enable_autoconnect (
    QmiMessageWdsStartNetworkInput *self,
    gboolean enable_autoconnect,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_enable_autoconnect = (guint8)(enable_autoconnect);
    self->arg_enable_autoconnect_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_get_profile_index_3gpp2:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @profile_index_3gpp2: a placeholder for the output #guint8, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Profile Index 3GPP2' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_get_profile_index_3gpp2 (
    QmiMessageWdsStartNetworkInput *self,
    guint8 *profile_index_3gpp2,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_profile_index_3gpp2_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Profile Index 3GPP2' was not found in the message");
        return FALSE;
    }

    if (profile_index_3gpp2)
        *profile_index_3gpp2 = self->arg_profile_index_3gpp2;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_set_profile_index_3gpp2:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @profile_index_3gpp2: a #guint8.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Profile Index 3GPP2' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_set_profile_index_3gpp2 (
    QmiMessageWdsStartNetworkInput *self,
    guint8 profile_index_3gpp2,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_profile_index_3gpp2 = profile_index_3gpp2;
    self->arg_profile_index_3gpp2_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_get_profile_index_3gpp:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @profile_index_3gpp: a placeholder for the output #guint8, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Profile Index 3GPP' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_get_profile_index_3gpp (
    QmiMessageWdsStartNetworkInput *self,
    guint8 *profile_index_3gpp,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_profile_index_3gpp_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Profile Index 3GPP' was not found in the message");
        return FALSE;
    }

    if (profile_index_3gpp)
        *profile_index_3gpp = self->arg_profile_index_3gpp;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_set_profile_index_3gpp:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @profile_index_3gpp: a #guint8.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Profile Index 3GPP' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_set_profile_index_3gpp (
    QmiMessageWdsStartNetworkInput *self,
    guint8 profile_index_3gpp,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_profile_index_3gpp = profile_index_3gpp;
    self->arg_profile_index_3gpp_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_get_technology_preference:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @technology_preference: a placeholder for the output #QmiWdsTechnologyPreference, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Technology Preference' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_get_technology_preference (
    QmiMessageWdsStartNetworkInput *self,
    QmiWdsTechnologyPreference *technology_preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_technology_preference_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Technology Preference' was not found in the message");
        return FALSE;
    }

    if (technology_preference)
        *technology_preference = (QmiWdsTechnologyPreference)(self->arg_technology_preference);

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_set_technology_preference:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @technology_preference: a #QmiWdsTechnologyPreference.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Technology Preference' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_set_technology_preference (
    QmiMessageWdsStartNetworkInput *self,
    QmiWdsTechnologyPreference technology_preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_technology_preference = (guint8)(technology_preference);
    self->arg_technology_preference_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_get_ip_family_preference:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @ip_family_preference: a placeholder for the output #QmiWdsIpFamily, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'IP Family Preference' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_get_ip_family_preference (
    QmiMessageWdsStartNetworkInput *self,
    QmiWdsIpFamily *ip_family_preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_ip_family_preference_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'IP Family Preference' was not found in the message");
        return FALSE;
    }

    if (ip_family_preference)
        *ip_family_preference = (QmiWdsIpFamily)(self->arg_ip_family_preference);

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_set_ip_family_preference:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @ip_family_preference: a #QmiWdsIpFamily.
 * @error: Return location for error or %NULL.
 *
 * Set the 'IP Family Preference' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_set_ip_family_preference (
    QmiMessageWdsStartNetworkInput *self,
    QmiWdsIpFamily ip_family_preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_ip_family_preference = (guint8)(ip_family_preference);
    self->arg_ip_family_preference_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_get_password:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @password: a placeholder for the output constant string, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Password' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_get_password (
    QmiMessageWdsStartNetworkInput *self,
    const gchar **password,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_password_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Password' was not found in the message");
        return FALSE;
    }

    if (password)
        *password = self->arg_password;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_set_password:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @password: a constant string.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Password' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_set_password (
    QmiMessageWdsStartNetworkInput *self,
    const gchar *password,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    g_free (self->arg_password);
    self->arg_password = g_strdup (password ? password : "");
    self->arg_password_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_get_username:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @username: a placeholder for the output constant string, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Username' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_get_username (
    QmiMessageWdsStartNetworkInput *self,
    const gchar **username,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_username_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Username' was not found in the message");
        return FALSE;
    }

    if (username)
        *username = self->arg_username;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_set_username:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @username: a constant string.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Username' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_set_username (
    QmiMessageWdsStartNetworkInput *self,
    const gchar *username,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    g_free (self->arg_username);
    self->arg_username = g_strdup (username ? username : "");
    self->arg_username_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_get_authentication_preference:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @authentication_preference: a placeholder for the output #QmiWdsAuthentication, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Authentication Preference' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_get_authentication_preference (
    QmiMessageWdsStartNetworkInput *self,
    QmiWdsAuthentication *authentication_preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_authentication_preference_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Authentication Preference' was not found in the message");
        return FALSE;
    }

    if (authentication_preference)
        *authentication_preference = (QmiWdsAuthentication)(self->arg_authentication_preference);

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_set_authentication_preference:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @authentication_preference: a #QmiWdsAuthentication.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Authentication Preference' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_set_authentication_preference (
    QmiMessageWdsStartNetworkInput *self,
    QmiWdsAuthentication authentication_preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_authentication_preference = (guint8)(authentication_preference);
    self->arg_authentication_preference_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_get_ipv4_address_preference:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @ipv4_address_preference: a placeholder for the output #guint32, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'IPv4 Address Preference' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_get_ipv4_address_preference (
    QmiMessageWdsStartNetworkInput *self,
    guint32 *ipv4_address_preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_ipv4_address_preference_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'IPv4 Address Preference' was not found in the message");
        return FALSE;
    }

    if (ipv4_address_preference)
        *ipv4_address_preference = self->arg_ipv4_address_preference;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_set_ipv4_address_preference:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @ipv4_address_preference: a #guint32.
 * @error: Return location for error or %NULL.
 *
 * Set the 'IPv4 Address Preference' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_set_ipv4_address_preference (
    QmiMessageWdsStartNetworkInput *self,
    guint32 ipv4_address_preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_ipv4_address_preference = ipv4_address_preference;
    self->arg_ipv4_address_preference_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_get_apn:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @apn: a placeholder for the output constant string, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'APN' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_get_apn (
    QmiMessageWdsStartNetworkInput *self,
    const gchar **apn,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_apn_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'APN' was not found in the message");
        return FALSE;
    }

    if (apn)
        *apn = self->arg_apn;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_set_apn:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @apn: a constant string.
 * @error: Return location for error or %NULL.
 *
 * Set the 'APN' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_set_apn (
    QmiMessageWdsStartNetworkInput *self,
    const gchar *apn,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    g_free (self->arg_apn);
    self->arg_apn = g_strdup (apn ? apn : "");
    self->arg_apn_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_get_secondary_nbns_address_preference:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @secondary_nbns_address_preference: a placeholder for the output #guint32, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Secondary NBNS Address Preference' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_get_secondary_nbns_address_preference (
    QmiMessageWdsStartNetworkInput *self,
    guint32 *secondary_nbns_address_preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_secondary_nbns_address_preference_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Secondary NBNS Address Preference' was not found in the message");
        return FALSE;
    }

    if (secondary_nbns_address_preference)
        *secondary_nbns_address_preference = self->arg_secondary_nbns_address_preference;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_set_secondary_nbns_address_preference:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @secondary_nbns_address_preference: a #guint32.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Secondary NBNS Address Preference' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_set_secondary_nbns_address_preference (
    QmiMessageWdsStartNetworkInput *self,
    guint32 secondary_nbns_address_preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_secondary_nbns_address_preference = secondary_nbns_address_preference;
    self->arg_secondary_nbns_address_preference_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_get_primary_nbns_address_preference:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @primary_nbns_address_preference: a placeholder for the output #guint32, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Primary NBNS Address Preference' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_get_primary_nbns_address_preference (
    QmiMessageWdsStartNetworkInput *self,
    guint32 *primary_nbns_address_preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_primary_nbns_address_preference_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Primary NBNS Address Preference' was not found in the message");
        return FALSE;
    }

    if (primary_nbns_address_preference)
        *primary_nbns_address_preference = self->arg_primary_nbns_address_preference;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_set_primary_nbns_address_preference:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @primary_nbns_address_preference: a #guint32.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Primary NBNS Address Preference' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_set_primary_nbns_address_preference (
    QmiMessageWdsStartNetworkInput *self,
    guint32 primary_nbns_address_preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_primary_nbns_address_preference = primary_nbns_address_preference;
    self->arg_primary_nbns_address_preference_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_get_secondary_dns_address_preference:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @secondary_dns_address_preference: a placeholder for the output #guint32, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Secondary DNS Address Preference' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_get_secondary_dns_address_preference (
    QmiMessageWdsStartNetworkInput *self,
    guint32 *secondary_dns_address_preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_secondary_dns_address_preference_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Secondary DNS Address Preference' was not found in the message");
        return FALSE;
    }

    if (secondary_dns_address_preference)
        *secondary_dns_address_preference = self->arg_secondary_dns_address_preference;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_set_secondary_dns_address_preference:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @secondary_dns_address_preference: a #guint32.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Secondary DNS Address Preference' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_set_secondary_dns_address_preference (
    QmiMessageWdsStartNetworkInput *self,
    guint32 secondary_dns_address_preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_secondary_dns_address_preference = secondary_dns_address_preference;
    self->arg_secondary_dns_address_preference_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_get_primary_dns_address_preference:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @primary_dns_address_preference: a placeholder for the output #guint32, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Primary DNS Address Preference' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_get_primary_dns_address_preference (
    QmiMessageWdsStartNetworkInput *self,
    guint32 *primary_dns_address_preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_primary_dns_address_preference_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Primary DNS Address Preference' was not found in the message");
        return FALSE;
    }

    if (primary_dns_address_preference)
        *primary_dns_address_preference = self->arg_primary_dns_address_preference;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_input_set_primary_dns_address_preference:
 * @self: a #QmiMessageWdsStartNetworkInput.
 * @primary_dns_address_preference: a #guint32.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Primary DNS Address Preference' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_input_set_primary_dns_address_preference (
    QmiMessageWdsStartNetworkInput *self,
    guint32 primary_dns_address_preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_primary_dns_address_preference = primary_dns_address_preference;
    self->arg_primary_dns_address_preference_set = TRUE;

    return TRUE;
}

GType
qmi_message_wds_start_network_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWdsStartNetworkInput"),
                                          (GBoxedCopyFunc) qmi_message_wds_start_network_input_ref,
                                          (GBoxedFreeFunc) qmi_message_wds_start_network_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wds_start_network_input_ref:
 * @self: a #QmiMessageWdsStartNetworkInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWdsStartNetworkInput *
qmi_message_wds_start_network_input_ref (QmiMessageWdsStartNetworkInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wds_start_network_input_unref:
 * @self: a #QmiMessageWdsStartNetworkInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wds_start_network_input_unref (QmiMessageWdsStartNetworkInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_free (self->arg_password);
        g_free (self->arg_username);
        g_free (self->arg_apn);
        g_slice_free (QmiMessageWdsStartNetworkInput, self);
    }
}

/**
 * qmi_message_wds_start_network_input_new:
 *
 * Allocates a new #QmiMessageWdsStartNetworkInput.
 *
 * Returns: the newly created #QmiMessageWdsStartNetworkInput. The returned value should be freed with qmi_message_wds_start_network_input_unref().
 */
QmiMessageWdsStartNetworkInput *
qmi_message_wds_start_network_input_new (void)
{
    QmiMessageWdsStartNetworkInput *self;

    self = g_slice_new0 (QmiMessageWdsStartNetworkInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_wds_start_network_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessageWdsStartNetworkInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WDS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WDS_START_NETWORK);

    /* All TLVs are optional, we allow NULL input */
    if (!input)
        return self;

    /* Try to add the 'Call Type' TLV */
    if (input->arg_call_type_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_call_type;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_CALL_TYPE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Call Type TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Extended Technology Preference' TLV */
    if (input->arg_extended_technology_preference_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint16 tmp;

            tmp = (guint16)input->arg_extended_technology_preference;
            /* Write the guint16 variable to the buffer */
            qmi_utils_write_guint16_to_buffer (
                &buffer_aux,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_EXTENDED_TECHNOLOGY_PREFERENCE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Extended Technology Preference TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Enable Autoconnect' TLV */
    if (input->arg_enable_autoconnect_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_enable_autoconnect;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_ENABLE_AUTOCONNECT,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Enable Autoconnect TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Profile Index 3GPP2' TLV */
    if (input->arg_profile_index_3gpp2_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        /* Write the guint8 variable to the buffer */
        qmi_utils_write_guint8_to_buffer (
            &buffer_aux,
            &buffer_len,
            &(input->arg_profile_index_3gpp2));

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_PROFILE_INDEX_3GPP2,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Profile Index 3GPP2 TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Profile Index 3GPP' TLV */
    if (input->arg_profile_index_3gpp_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        /* Write the guint8 variable to the buffer */
        qmi_utils_write_guint8_to_buffer (
            &buffer_aux,
            &buffer_len,
            &(input->arg_profile_index_3gpp));

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_PROFILE_INDEX_3GPP,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Profile Index 3GPP TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Technology Preference' TLV */
    if (input->arg_technology_preference_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_technology_preference;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_TECHNOLOGY_PREFERENCE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Technology Preference TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'IP Family Preference' TLV */
    if (input->arg_ip_family_preference_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_ip_family_preference;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_IP_FAMILY_PREFERENCE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the IP Family Preference TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Password' TLV */
    if (input->arg_password_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        /* Write the string variable to the buffer */
        qmi_utils_write_string_to_buffer (
            &buffer_aux,
            &buffer_len,
            0,
            input->arg_password);

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_PASSWORD,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Password TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Username' TLV */
    if (input->arg_username_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        /* Write the string variable to the buffer */
        qmi_utils_write_string_to_buffer (
            &buffer_aux,
            &buffer_len,
            0,
            input->arg_username);

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_USERNAME,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Username TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Authentication Preference' TLV */
    if (input->arg_authentication_preference_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_authentication_preference;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_AUTHENTICATION_PREFERENCE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Authentication Preference TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'IPv4 Address Preference' TLV */
    if (input->arg_ipv4_address_preference_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        /* Write the guint32 variable to the buffer */
        qmi_utils_write_guint32_to_buffer (
            &buffer_aux,
            &buffer_len,
            QMI_ENDIAN_LITTLE,
            &(input->arg_ipv4_address_preference));

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_IPV4_ADDRESS_PREFERENCE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the IPv4 Address Preference TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'APN' TLV */
    if (input->arg_apn_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        /* Write the string variable to the buffer */
        qmi_utils_write_string_to_buffer (
            &buffer_aux,
            &buffer_len,
            0,
            input->arg_apn);

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_APN,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the APN TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Secondary NBNS Address Preference' TLV */
    if (input->arg_secondary_nbns_address_preference_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        /* Write the guint32 variable to the buffer */
        qmi_utils_write_guint32_to_buffer (
            &buffer_aux,
            &buffer_len,
            QMI_ENDIAN_LITTLE,
            &(input->arg_secondary_nbns_address_preference));

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_SECONDARY_NBNS_ADDRESS_PREFERENCE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Secondary NBNS Address Preference TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Primary NBNS Address Preference' TLV */
    if (input->arg_primary_nbns_address_preference_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        /* Write the guint32 variable to the buffer */
        qmi_utils_write_guint32_to_buffer (
            &buffer_aux,
            &buffer_len,
            QMI_ENDIAN_LITTLE,
            &(input->arg_primary_nbns_address_preference));

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_PRIMARY_NBNS_ADDRESS_PREFERENCE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Primary NBNS Address Preference TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Secondary DNS Address Preference' TLV */
    if (input->arg_secondary_dns_address_preference_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        /* Write the guint32 variable to the buffer */
        qmi_utils_write_guint32_to_buffer (
            &buffer_aux,
            &buffer_len,
            QMI_ENDIAN_LITTLE,
            &(input->arg_secondary_dns_address_preference));

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_SECONDARY_DNS_ADDRESS_PREFERENCE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Secondary DNS Address Preference TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Primary DNS Address Preference' TLV */
    if (input->arg_primary_dns_address_preference_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        /* Write the guint32 variable to the buffer */
        qmi_utils_write_guint32_to_buffer (
            &buffer_aux,
            &buffer_len,
            QMI_ENDIAN_LITTLE,
            &(input->arg_primary_dns_address_preference));

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_PRIMARY_DNS_ADDRESS_PREFERENCE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Primary DNS Address Preference TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    return self;
}

/* --- Output -- */

struct _QmiMessageWdsStartNetworkOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Packet Data Handle */
    gboolean arg_packet_data_handle_set;
    guint32 arg_packet_data_handle;

    /* Call End Reason */
    gboolean arg_call_end_reason_set;
    guint16 arg_call_end_reason;

    /* Verbose Call End Reason */
    gboolean arg_verbose_call_end_reason_set;
    guint16 arg_verbose_call_end_reason_type;
    gint16 arg_verbose_call_end_reason_reason;
};

#define QMI_MESSAGE_WDS_START_NETWORK_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_WDS_START_NETWORK_OUTPUT_TLV_PACKET_DATA_HANDLE 0x01
#define QMI_MESSAGE_WDS_START_NETWORK_OUTPUT_TLV_CALL_END_REASON 0x10
#define QMI_MESSAGE_WDS_START_NETWORK_OUTPUT_TLV_VERBOSE_CALL_END_REASON 0x11

/**
 * qmi_message_wds_start_network_output_get_result:
 * @self: a QmiMessageWdsStartNetworkOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wds_start_network_output_get_result (
    QmiMessageWdsStartNetworkOutput *self,
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
 * qmi_message_wds_start_network_output_get_packet_data_handle:
 * @self: a #QmiMessageWdsStartNetworkOutput.
 * @packet_data_handle: a placeholder for the output #guint32, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Packet Data Handle' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_output_get_packet_data_handle (
    QmiMessageWdsStartNetworkOutput *self,
    guint32 *packet_data_handle,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_packet_data_handle_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Packet Data Handle' was not found in the message");
        return FALSE;
    }

    if (packet_data_handle)
        *packet_data_handle = self->arg_packet_data_handle;

    return TRUE;
}

/**
 * qmi_message_wds_start_network_output_get_call_end_reason:
 * @self: a #QmiMessageWdsStartNetworkOutput.
 * @call_end_reason: a placeholder for the output #QmiWdsCallEndReason, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Call End Reason' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_output_get_call_end_reason (
    QmiMessageWdsStartNetworkOutput *self,
    QmiWdsCallEndReason *call_end_reason,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_call_end_reason_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Call End Reason' was not found in the message");
        return FALSE;
    }

    if (call_end_reason)
        *call_end_reason = (QmiWdsCallEndReason)(self->arg_call_end_reason);

    return TRUE;
}

/**
 * qmi_message_wds_start_network_output_get_verbose_call_end_reason:
 * @self: a #QmiMessageWdsStartNetworkOutput.
 * @verbose_call_end_reason_type: a placeholder for the output #QmiWdsVerboseCallEndReasonType, or %NULL if not required.
 * @verbose_call_end_reason_reason: a placeholder for the output #gint16, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Verbose Call End Reason' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_start_network_output_get_verbose_call_end_reason (
    QmiMessageWdsStartNetworkOutput *self,
    QmiWdsVerboseCallEndReasonType *verbose_call_end_reason_type,
    gint16 *verbose_call_end_reason_reason,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_verbose_call_end_reason_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Verbose Call End Reason' was not found in the message");
        return FALSE;
    }

    if (verbose_call_end_reason_type)
        *verbose_call_end_reason_type = (QmiWdsVerboseCallEndReasonType)(self->arg_verbose_call_end_reason_type);
    if (verbose_call_end_reason_reason)
        *verbose_call_end_reason_reason = self->arg_verbose_call_end_reason_reason;

    return TRUE;
}

GType
qmi_message_wds_start_network_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWdsStartNetworkOutput"),
                                          (GBoxedCopyFunc) qmi_message_wds_start_network_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wds_start_network_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wds_start_network_output_ref:
 * @self: a #QmiMessageWdsStartNetworkOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWdsStartNetworkOutput *
qmi_message_wds_start_network_output_ref (QmiMessageWdsStartNetworkOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wds_start_network_output_unref:
 * @self: a #QmiMessageWdsStartNetworkOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wds_start_network_output_unref (QmiMessageWdsStartNetworkOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWdsStartNetworkOutput, self);
    }
}

static gboolean
qmi_message_wds_start_network_input_call_type_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Call Type' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Call Type' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_start_network_input_call_type_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_CALL_TYPE,
                                      &buffer_len);
    if (buffer && qmi_message_wds_start_network_input_call_type_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WDS_CALL_TYPE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wds_call_type_get_string ((QmiWdsCallType)tmp));
#elif defined  __QMI_WDS_CALL_TYPE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wds_call_type_build_string_from_mask ((QmiWdsCallType)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWdsCallType
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Call Type' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_start_network_input_extended_technology_preference_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 2;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Extended Technology Preference' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Extended Technology Preference' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_start_network_input_extended_technology_preference_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_EXTENDED_TECHNOLOGY_PREFERENCE,
                                      &buffer_len);
    if (buffer && qmi_message_wds_start_network_input_extended_technology_preference_validate (buffer, buffer_len)) {
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

#if defined  __QMI_WDS_EXTENDED_TECHNOLOGY_PREFERENCE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wds_extended_technology_preference_get_string ((QmiWdsExtendedTechnologyPreference)tmp));
#elif defined  __QMI_WDS_EXTENDED_TECHNOLOGY_PREFERENCE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wds_extended_technology_preference_build_string_from_mask ((QmiWdsExtendedTechnologyPreference)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWdsExtendedTechnologyPreference
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Extended Technology Preference' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_start_network_input_enable_autoconnect_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Enable Autoconnect' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Enable Autoconnect' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_start_network_input_enable_autoconnect_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_ENABLE_AUTOCONNECT,
                                      &buffer_len);
    if (buffer && qmi_message_wds_start_network_input_enable_autoconnect_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Enable Autoconnect' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_start_network_input_profile_index_3gpp2_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Profile Index 3GPP2' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Profile Index 3GPP2' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_start_network_input_profile_index_3gpp2_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_PROFILE_INDEX_3GPP2,
                                      &buffer_len);
    if (buffer && qmi_message_wds_start_network_input_profile_index_3gpp2_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Profile Index 3GPP2' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_start_network_input_profile_index_3gpp_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Profile Index 3GPP' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Profile Index 3GPP' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_start_network_input_profile_index_3gpp_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_PROFILE_INDEX_3GPP,
                                      &buffer_len);
    if (buffer && qmi_message_wds_start_network_input_profile_index_3gpp_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Profile Index 3GPP' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_start_network_input_technology_preference_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Technology Preference' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Technology Preference' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_start_network_input_technology_preference_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_TECHNOLOGY_PREFERENCE,
                                      &buffer_len);
    if (buffer && qmi_message_wds_start_network_input_technology_preference_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WDS_TECHNOLOGY_PREFERENCE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wds_technology_preference_get_string ((QmiWdsTechnologyPreference)tmp));
#elif defined  __QMI_WDS_TECHNOLOGY_PREFERENCE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wds_technology_preference_build_string_from_mask ((QmiWdsTechnologyPreference)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWdsTechnologyPreference
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Technology Preference' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_start_network_input_ip_family_preference_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'IP Family Preference' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'IP Family Preference' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_start_network_input_ip_family_preference_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_IP_FAMILY_PREFERENCE,
                                      &buffer_len);
    if (buffer && qmi_message_wds_start_network_input_ip_family_preference_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WDS_IP_FAMILY_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wds_ip_family_get_string ((QmiWdsIpFamily)tmp));
#elif defined  __QMI_WDS_IP_FAMILY_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wds_ip_family_build_string_from_mask ((QmiWdsIpFamily)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWdsIpFamily
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'IP Family Preference' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_start_network_input_password_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += buffer_len;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Password' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Password' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_start_network_input_password_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_PASSWORD,
                                      &buffer_len);
    if (buffer && qmi_message_wds_start_network_input_password_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Password' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_start_network_input_username_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += buffer_len;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Username' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Username' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_start_network_input_username_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_USERNAME,
                                      &buffer_len);
    if (buffer && qmi_message_wds_start_network_input_username_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Username' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_start_network_input_authentication_preference_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Authentication Preference' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Authentication Preference' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_start_network_input_authentication_preference_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_AUTHENTICATION_PREFERENCE,
                                      &buffer_len);
    if (buffer && qmi_message_wds_start_network_input_authentication_preference_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WDS_AUTHENTICATION_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wds_authentication_get_string ((QmiWdsAuthentication)tmp));
#elif defined  __QMI_WDS_AUTHENTICATION_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wds_authentication_build_string_from_mask ((QmiWdsAuthentication)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWdsAuthentication
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Authentication Preference' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_start_network_input_ipv4_address_preference_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'IPv4 Address Preference' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'IPv4 Address Preference' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_start_network_input_ipv4_address_preference_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_IPV4_ADDRESS_PREFERENCE,
                                      &buffer_len);
    if (buffer && qmi_message_wds_start_network_input_ipv4_address_preference_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'IPv4 Address Preference' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_start_network_input_apn_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += buffer_len;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'APN' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'APN' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_start_network_input_apn_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_APN,
                                      &buffer_len);
    if (buffer && qmi_message_wds_start_network_input_apn_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'APN' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_start_network_input_secondary_nbns_address_preference_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Secondary NBNS Address Preference' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Secondary NBNS Address Preference' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_start_network_input_secondary_nbns_address_preference_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_SECONDARY_NBNS_ADDRESS_PREFERENCE,
                                      &buffer_len);
    if (buffer && qmi_message_wds_start_network_input_secondary_nbns_address_preference_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Secondary NBNS Address Preference' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_start_network_input_primary_nbns_address_preference_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Primary NBNS Address Preference' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Primary NBNS Address Preference' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_start_network_input_primary_nbns_address_preference_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_PRIMARY_NBNS_ADDRESS_PREFERENCE,
                                      &buffer_len);
    if (buffer && qmi_message_wds_start_network_input_primary_nbns_address_preference_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Primary NBNS Address Preference' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_start_network_input_secondary_dns_address_preference_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Secondary DNS Address Preference' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Secondary DNS Address Preference' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_start_network_input_secondary_dns_address_preference_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_SECONDARY_DNS_ADDRESS_PREFERENCE,
                                      &buffer_len);
    if (buffer && qmi_message_wds_start_network_input_secondary_dns_address_preference_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Secondary DNS Address Preference' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_start_network_input_primary_dns_address_preference_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Primary DNS Address Preference' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Primary DNS Address Preference' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_start_network_input_primary_dns_address_preference_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_PRIMARY_DNS_ADDRESS_PREFERENCE,
                                      &buffer_len);
    if (buffer && qmi_message_wds_start_network_input_primary_dns_address_preference_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Primary DNS Address Preference' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_start_network_output_packet_data_handle_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Packet Data Handle' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Packet Data Handle' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_start_network_output_packet_data_handle_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_START_NETWORK_OUTPUT_TLV_PACKET_DATA_HANDLE,
                                      &buffer_len);
    if (buffer && qmi_message_wds_start_network_output_packet_data_handle_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Packet Data Handle' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_start_network_output_call_end_reason_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 2;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Call End Reason' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Call End Reason' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_start_network_output_call_end_reason_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_START_NETWORK_OUTPUT_TLV_CALL_END_REASON,
                                      &buffer_len);
    if (buffer && qmi_message_wds_start_network_output_call_end_reason_validate (buffer, buffer_len)) {
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

#if defined  __QMI_WDS_CALL_END_REASON_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wds_call_end_reason_get_string ((QmiWdsCallEndReason)tmp));
#elif defined  __QMI_WDS_CALL_END_REASON_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wds_call_end_reason_build_string_from_mask ((QmiWdsCallEndReason)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWdsCallEndReason
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Call End Reason' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_start_network_output_verbose_call_end_reason_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 2;
    expected_len += 2;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Verbose Call End Reason' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Verbose Call End Reason' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_start_network_output_verbose_call_end_reason_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_START_NETWORK_OUTPUT_TLV_VERBOSE_CALL_END_REASON,
                                      &buffer_len);
    if (buffer && qmi_message_wds_start_network_output_verbose_call_end_reason_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " type = '");

        {
            guint16 tmp;

            /* Read the guint16 variable from the buffer */
            qmi_utils_read_guint16_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &tmp);

#if defined  __QMI_WDS_VERBOSE_CALL_END_REASON_TYPE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wds_verbose_call_end_reason_type_get_string ((QmiWdsVerboseCallEndReasonType)tmp));
#elif defined  __QMI_WDS_VERBOSE_CALL_END_REASON_TYPE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wds_verbose_call_end_reason_type_build_string_from_mask ((QmiWdsVerboseCallEndReasonType)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWdsVerboseCallEndReasonType
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " reason = '");

        {
            gint16 tmp;

            /* Read the gint16 variable from the buffer */
            qmi_utils_read_gint16_from_buffer (
                &buffer,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &tmp);

            g_string_append_printf (printable, "%" G_GINT16_FORMAT "", tmp);
        }
        g_string_append (printable, "'");
        g_string_append (printable, " ]");

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Verbose Call End Reason' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_start_network_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_start_network_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_start_network_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_CALL_TYPE:
            tlv_type_str = "Call Type";
            translated_value = qmi_message_wds_start_network_input_call_type_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_EXTENDED_TECHNOLOGY_PREFERENCE:
            tlv_type_str = "Extended Technology Preference";
            translated_value = qmi_message_wds_start_network_input_extended_technology_preference_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_ENABLE_AUTOCONNECT:
            tlv_type_str = "Enable Autoconnect";
            translated_value = qmi_message_wds_start_network_input_enable_autoconnect_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_PROFILE_INDEX_3GPP2:
            tlv_type_str = "Profile Index 3GPP2";
            translated_value = qmi_message_wds_start_network_input_profile_index_3gpp2_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_PROFILE_INDEX_3GPP:
            tlv_type_str = "Profile Index 3GPP";
            translated_value = qmi_message_wds_start_network_input_profile_index_3gpp_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_TECHNOLOGY_PREFERENCE:
            tlv_type_str = "Technology Preference";
            translated_value = qmi_message_wds_start_network_input_technology_preference_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_IP_FAMILY_PREFERENCE:
            tlv_type_str = "IP Family Preference";
            translated_value = qmi_message_wds_start_network_input_ip_family_preference_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_PASSWORD:
            tlv_type_str = "Password";
            translated_value = qmi_message_wds_start_network_input_password_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_USERNAME:
            tlv_type_str = "Username";
            translated_value = qmi_message_wds_start_network_input_username_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_AUTHENTICATION_PREFERENCE:
            tlv_type_str = "Authentication Preference";
            translated_value = qmi_message_wds_start_network_input_authentication_preference_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_IPV4_ADDRESS_PREFERENCE:
            tlv_type_str = "IPv4 Address Preference";
            translated_value = qmi_message_wds_start_network_input_ipv4_address_preference_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_APN:
            tlv_type_str = "APN";
            translated_value = qmi_message_wds_start_network_input_apn_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_SECONDARY_NBNS_ADDRESS_PREFERENCE:
            tlv_type_str = "Secondary NBNS Address Preference";
            translated_value = qmi_message_wds_start_network_input_secondary_nbns_address_preference_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_PRIMARY_NBNS_ADDRESS_PREFERENCE:
            tlv_type_str = "Primary NBNS Address Preference";
            translated_value = qmi_message_wds_start_network_input_primary_nbns_address_preference_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_SECONDARY_DNS_ADDRESS_PREFERENCE:
            tlv_type_str = "Secondary DNS Address Preference";
            translated_value = qmi_message_wds_start_network_input_secondary_dns_address_preference_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_START_NETWORK_INPUT_TLV_PRIMARY_DNS_ADDRESS_PREFERENCE:
            tlv_type_str = "Primary DNS Address Preference";
            translated_value = qmi_message_wds_start_network_input_primary_dns_address_preference_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_WDS_START_NETWORK_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_START_NETWORK_OUTPUT_TLV_PACKET_DATA_HANDLE:
            tlv_type_str = "Packet Data Handle";
            translated_value = qmi_message_wds_start_network_output_packet_data_handle_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_START_NETWORK_OUTPUT_TLV_CALL_END_REASON:
            tlv_type_str = "Call End Reason";
            translated_value = qmi_message_wds_start_network_output_call_end_reason_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_START_NETWORK_OUTPUT_TLV_VERBOSE_CALL_END_REASON:
            tlv_type_str = "Verbose Call End Reason";
            translated_value = qmi_message_wds_start_network_output_verbose_call_end_reason_get_printable (
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
message_start_network_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Start Network\" (0x0020)\n",
                            line_prefix);

    {
        struct message_start_network_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_start_network_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageWdsStartNetworkOutput *
__qmi_message_wds_start_network_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWdsStartNetworkOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WDS_START_NETWORK, NULL);

    self = g_slice_new0 (QmiMessageWdsStartNetworkOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WDS_START_NETWORK_OUTPUT_TLV_RESULT,
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
                qmi_message_wds_start_network_output_unref (self);
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
                                              QMI_MESSAGE_WDS_START_NETWORK_OUTPUT_TLV_PACKET_DATA_HANDLE,
                                              &buffer_len);
            if (buffer && qmi_message_wds_start_network_output_packet_data_handle_validate (buffer, buffer_len)) {
                self->arg_packet_data_handle_set = TRUE;

                /* Read the guint32 variable from the buffer */
                qmi_utils_read_guint32_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_packet_data_handle));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Packet Data Handle' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the Packet Data Handle TLV: Not found");
                qmi_message_wds_start_network_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    do {
        /* Prerequisite.... */
        if (!(self->arg_result.error_status != QMI_STATUS_SUCCESS))
            break;
        /* Prerequisite.... */
        if (!(self->arg_result.error_code == QMI_PROTOCOL_ERROR_CALL_FAILED))
            break;

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WDS_START_NETWORK_OUTPUT_TLV_CALL_END_REASON,
                                              &buffer_len);
            if (buffer && qmi_message_wds_start_network_output_call_end_reason_validate (buffer, buffer_len)) {
                self->arg_call_end_reason_set = TRUE;

                {
                    guint16 tmp;

                    /* Read the guint16 variable from the buffer */
                    qmi_utils_read_guint16_from_buffer (
                        &buffer,
                        &buffer_len,
                        QMI_ENDIAN_LITTLE,
                        &tmp);
                    self->arg_call_end_reason = (QmiWdsCallEndReason)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Call End Reason' TLV", buffer_len);
                }
            }

        }
    } while (0);

    do {
        /* Prerequisite.... */
        if (!(self->arg_result.error_status != QMI_STATUS_SUCCESS))
            break;
        /* Prerequisite.... */
        if (!(self->arg_result.error_code == QMI_PROTOCOL_ERROR_CALL_FAILED))
            break;

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WDS_START_NETWORK_OUTPUT_TLV_VERBOSE_CALL_END_REASON,
                                              &buffer_len);
            if (buffer && qmi_message_wds_start_network_output_verbose_call_end_reason_validate (buffer, buffer_len)) {
                self->arg_verbose_call_end_reason_set = TRUE;

                {
                    guint16 tmp;

                    /* Read the guint16 variable from the buffer */
                    qmi_utils_read_guint16_from_buffer (
                        &buffer,
                        &buffer_len,
                        QMI_ENDIAN_LITTLE,
                        &tmp);
                    self->arg_verbose_call_end_reason_type = (QmiWdsVerboseCallEndReasonType)tmp;
                }
                /* Read the gint16 variable from the buffer */
                qmi_utils_read_gint16_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_verbose_call_end_reason_reason));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Verbose Call End Reason' TLV", buffer_len);
                }
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WDS Stop Network */


/* --- Input -- */

struct _QmiMessageWdsStopNetworkInput {
    volatile gint ref_count;

    /* Disable Autoconnect */
    gboolean arg_disable_autoconnect_set;
    guint8 arg_disable_autoconnect;

    /* Packet Data Handle */
    gboolean arg_packet_data_handle_set;
    guint32 arg_packet_data_handle;
};

#define QMI_MESSAGE_WDS_STOP_NETWORK_INPUT_TLV_DISABLE_AUTOCONNECT 0x10
#define QMI_MESSAGE_WDS_STOP_NETWORK_INPUT_TLV_PACKET_DATA_HANDLE 0x01

/**
 * qmi_message_wds_stop_network_input_get_disable_autoconnect:
 * @self: a #QmiMessageWdsStopNetworkInput.
 * @disable_autoconnect: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Disable Autoconnect' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_stop_network_input_get_disable_autoconnect (
    QmiMessageWdsStopNetworkInput *self,
    gboolean *disable_autoconnect,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_disable_autoconnect_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Disable Autoconnect' was not found in the message");
        return FALSE;
    }

    if (disable_autoconnect)
        *disable_autoconnect = (gboolean)(self->arg_disable_autoconnect);

    return TRUE;
}

/**
 * qmi_message_wds_stop_network_input_set_disable_autoconnect:
 * @self: a #QmiMessageWdsStopNetworkInput.
 * @disable_autoconnect: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Disable Autoconnect' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wds_stop_network_input_set_disable_autoconnect (
    QmiMessageWdsStopNetworkInput *self,
    gboolean disable_autoconnect,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_disable_autoconnect = (guint8)(disable_autoconnect);
    self->arg_disable_autoconnect_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_wds_stop_network_input_get_packet_data_handle:
 * @self: a #QmiMessageWdsStopNetworkInput.
 * @packet_data_handle: a placeholder for the output #guint32, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Packet Data Handle' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_stop_network_input_get_packet_data_handle (
    QmiMessageWdsStopNetworkInput *self,
    guint32 *packet_data_handle,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_packet_data_handle_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Packet Data Handle' was not found in the message");
        return FALSE;
    }

    if (packet_data_handle)
        *packet_data_handle = self->arg_packet_data_handle;

    return TRUE;
}

/**
 * qmi_message_wds_stop_network_input_set_packet_data_handle:
 * @self: a #QmiMessageWdsStopNetworkInput.
 * @packet_data_handle: a #guint32.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Packet Data Handle' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wds_stop_network_input_set_packet_data_handle (
    QmiMessageWdsStopNetworkInput *self,
    guint32 packet_data_handle,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_packet_data_handle = packet_data_handle;
    self->arg_packet_data_handle_set = TRUE;

    return TRUE;
}

GType
qmi_message_wds_stop_network_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWdsStopNetworkInput"),
                                          (GBoxedCopyFunc) qmi_message_wds_stop_network_input_ref,
                                          (GBoxedFreeFunc) qmi_message_wds_stop_network_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wds_stop_network_input_ref:
 * @self: a #QmiMessageWdsStopNetworkInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWdsStopNetworkInput *
qmi_message_wds_stop_network_input_ref (QmiMessageWdsStopNetworkInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wds_stop_network_input_unref:
 * @self: a #QmiMessageWdsStopNetworkInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wds_stop_network_input_unref (QmiMessageWdsStopNetworkInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWdsStopNetworkInput, self);
    }
}

/**
 * qmi_message_wds_stop_network_input_new:
 *
 * Allocates a new #QmiMessageWdsStopNetworkInput.
 *
 * Returns: the newly created #QmiMessageWdsStopNetworkInput. The returned value should be freed with qmi_message_wds_stop_network_input_unref().
 */
QmiMessageWdsStopNetworkInput *
qmi_message_wds_stop_network_input_new (void)
{
    QmiMessageWdsStopNetworkInput *self;

    self = g_slice_new0 (QmiMessageWdsStopNetworkInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_wds_stop_network_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessageWdsStopNetworkInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WDS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WDS_STOP_NETWORK);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Stop Network' has mandatory TLVs");
        qmi_message_unref (self);
        return NULL;
    }

    /* Try to add the 'Disable Autoconnect' TLV */
    if (input->arg_disable_autoconnect_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_disable_autoconnect;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_STOP_NETWORK_INPUT_TLV_DISABLE_AUTOCONNECT,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Disable Autoconnect TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Packet Data Handle' TLV */
    if (input->arg_packet_data_handle_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        /* Write the guint32 variable to the buffer */
        qmi_utils_write_guint32_to_buffer (
            &buffer_aux,
            &buffer_len,
            QMI_ENDIAN_LITTLE,
            &(input->arg_packet_data_handle));

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_STOP_NETWORK_INPUT_TLV_PACKET_DATA_HANDLE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Packet Data Handle TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'Packet Data Handle' in message 'Stop Network'");
        qmi_message_unref (self);
        return NULL;
    }

    return self;
}

/* --- Output -- */

struct _QmiMessageWdsStopNetworkOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;
};

#define QMI_MESSAGE_WDS_STOP_NETWORK_OUTPUT_TLV_RESULT 0x02

/**
 * qmi_message_wds_stop_network_output_get_result:
 * @self: a QmiMessageWdsStopNetworkOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wds_stop_network_output_get_result (
    QmiMessageWdsStopNetworkOutput *self,
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
qmi_message_wds_stop_network_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWdsStopNetworkOutput"),
                                          (GBoxedCopyFunc) qmi_message_wds_stop_network_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wds_stop_network_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wds_stop_network_output_ref:
 * @self: a #QmiMessageWdsStopNetworkOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWdsStopNetworkOutput *
qmi_message_wds_stop_network_output_ref (QmiMessageWdsStopNetworkOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wds_stop_network_output_unref:
 * @self: a #QmiMessageWdsStopNetworkOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wds_stop_network_output_unref (QmiMessageWdsStopNetworkOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWdsStopNetworkOutput, self);
    }
}

static gboolean
qmi_message_wds_stop_network_input_disable_autoconnect_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Disable Autoconnect' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Disable Autoconnect' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_stop_network_input_disable_autoconnect_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_STOP_NETWORK_INPUT_TLV_DISABLE_AUTOCONNECT,
                                      &buffer_len);
    if (buffer && qmi_message_wds_stop_network_input_disable_autoconnect_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Disable Autoconnect' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_stop_network_input_packet_data_handle_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Packet Data Handle' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Packet Data Handle' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_stop_network_input_packet_data_handle_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_STOP_NETWORK_INPUT_TLV_PACKET_DATA_HANDLE,
                                      &buffer_len);
    if (buffer && qmi_message_wds_stop_network_input_packet_data_handle_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Packet Data Handle' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_stop_network_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_stop_network_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_stop_network_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_WDS_STOP_NETWORK_INPUT_TLV_DISABLE_AUTOCONNECT:
            tlv_type_str = "Disable Autoconnect";
            translated_value = qmi_message_wds_stop_network_input_disable_autoconnect_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_STOP_NETWORK_INPUT_TLV_PACKET_DATA_HANDLE:
            tlv_type_str = "Packet Data Handle";
            translated_value = qmi_message_wds_stop_network_input_packet_data_handle_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_WDS_STOP_NETWORK_OUTPUT_TLV_RESULT:
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
message_stop_network_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Stop Network\" (0x0021)\n",
                            line_prefix);

    {
        struct message_stop_network_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_stop_network_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageWdsStopNetworkOutput *
__qmi_message_wds_stop_network_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWdsStopNetworkOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WDS_STOP_NETWORK, NULL);

    self = g_slice_new0 (QmiMessageWdsStopNetworkOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WDS_STOP_NETWORK_OUTPUT_TLV_RESULT,
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
                qmi_message_wds_stop_network_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WDS Get Packet Service Status */


/* --- Input -- */

/* Note: no fields in the Input container */

static QmiMessage *
__qmi_message_wds_get_packet_service_status_request_create (
    guint8 transaction_id,
    guint8 cid,
    gpointer unused,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WDS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WDS_GET_PACKET_SERVICE_STATUS);

    return self;
}

/* --- Output -- */

struct _QmiMessageWdsGetPacketServiceStatusOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Connection Status */
    gboolean arg_connection_status_set;
    guint8 arg_connection_status;
};

#define QMI_MESSAGE_WDS_GET_PACKET_SERVICE_STATUS_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_WDS_GET_PACKET_SERVICE_STATUS_OUTPUT_TLV_CONNECTION_STATUS 0x01

/**
 * qmi_message_wds_get_packet_service_status_output_get_result:
 * @self: a QmiMessageWdsGetPacketServiceStatusOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wds_get_packet_service_status_output_get_result (
    QmiMessageWdsGetPacketServiceStatusOutput *self,
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
 * qmi_message_wds_get_packet_service_status_output_get_connection_status:
 * @self: a #QmiMessageWdsGetPacketServiceStatusOutput.
 * @connection_status: a placeholder for the output #QmiWdsConnectionStatus, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Connection Status' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_packet_service_status_output_get_connection_status (
    QmiMessageWdsGetPacketServiceStatusOutput *self,
    QmiWdsConnectionStatus *connection_status,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_connection_status_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Connection Status' was not found in the message");
        return FALSE;
    }

    if (connection_status)
        *connection_status = (QmiWdsConnectionStatus)(self->arg_connection_status);

    return TRUE;
}

GType
qmi_message_wds_get_packet_service_status_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWdsGetPacketServiceStatusOutput"),
                                          (GBoxedCopyFunc) qmi_message_wds_get_packet_service_status_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wds_get_packet_service_status_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wds_get_packet_service_status_output_ref:
 * @self: a #QmiMessageWdsGetPacketServiceStatusOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWdsGetPacketServiceStatusOutput *
qmi_message_wds_get_packet_service_status_output_ref (QmiMessageWdsGetPacketServiceStatusOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wds_get_packet_service_status_output_unref:
 * @self: a #QmiMessageWdsGetPacketServiceStatusOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wds_get_packet_service_status_output_unref (QmiMessageWdsGetPacketServiceStatusOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWdsGetPacketServiceStatusOutput, self);
    }
}

static gboolean
qmi_message_wds_get_packet_service_status_output_connection_status_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Connection Status' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Connection Status' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_packet_service_status_output_connection_status_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_PACKET_SERVICE_STATUS_OUTPUT_TLV_CONNECTION_STATUS,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_packet_service_status_output_connection_status_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WDS_CONNECTION_STATUS_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wds_connection_status_get_string ((QmiWdsConnectionStatus)tmp));
#elif defined  __QMI_WDS_CONNECTION_STATUS_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wds_connection_status_build_string_from_mask ((QmiWdsConnectionStatus)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWdsConnectionStatus
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Connection Status' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_get_packet_service_status_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_get_packet_service_status_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_get_packet_service_status_context *ctx)
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
        case QMI_MESSAGE_WDS_GET_PACKET_SERVICE_STATUS_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_PACKET_SERVICE_STATUS_OUTPUT_TLV_CONNECTION_STATUS:
            tlv_type_str = "Connection Status";
            translated_value = qmi_message_wds_get_packet_service_status_output_connection_status_get_printable (
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
message_get_packet_service_status_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Get Packet Service Status\" (0x0022)\n",
                            line_prefix);

    {
        struct message_get_packet_service_status_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_get_packet_service_status_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageWdsGetPacketServiceStatusOutput *
__qmi_message_wds_get_packet_service_status_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWdsGetPacketServiceStatusOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WDS_GET_PACKET_SERVICE_STATUS, NULL);

    self = g_slice_new0 (QmiMessageWdsGetPacketServiceStatusOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WDS_GET_PACKET_SERVICE_STATUS_OUTPUT_TLV_RESULT,
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
                qmi_message_wds_get_packet_service_status_output_unref (self);
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
                                              QMI_MESSAGE_WDS_GET_PACKET_SERVICE_STATUS_OUTPUT_TLV_CONNECTION_STATUS,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_packet_service_status_output_connection_status_validate (buffer, buffer_len)) {
                self->arg_connection_status_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_connection_status = (QmiWdsConnectionStatus)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Connection Status' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the Connection Status TLV: Not found");
                qmi_message_wds_get_packet_service_status_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WDS Get Current Settings */


/* --- Input -- */

struct _QmiMessageWdsGetCurrentSettingsInput {
    volatile gint ref_count;

    /* Requested Settings */
    gboolean arg_requested_settings_set;
    guint32 arg_requested_settings;
};

#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_INPUT_TLV_REQUESTED_SETTINGS 0x10

/**
 * qmi_message_wds_get_current_settings_input_get_requested_settings:
 * @self: a #QmiMessageWdsGetCurrentSettingsInput.
 * @requested_settings: a placeholder for the output #QmiWdsGetCurrentSettingsRequestedSettings, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Requested Settings' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_input_get_requested_settings (
    QmiMessageWdsGetCurrentSettingsInput *self,
    QmiWdsGetCurrentSettingsRequestedSettings *requested_settings,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_requested_settings_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Requested Settings' was not found in the message");
        return FALSE;
    }

    if (requested_settings)
        *requested_settings = (QmiWdsGetCurrentSettingsRequestedSettings)(self->arg_requested_settings);

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_input_set_requested_settings:
 * @self: a #QmiMessageWdsGetCurrentSettingsInput.
 * @requested_settings: a #QmiWdsGetCurrentSettingsRequestedSettings.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Requested Settings' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_input_set_requested_settings (
    QmiMessageWdsGetCurrentSettingsInput *self,
    QmiWdsGetCurrentSettingsRequestedSettings requested_settings,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_requested_settings = (guint32)(requested_settings);
    self->arg_requested_settings_set = TRUE;

    return TRUE;
}

GType
qmi_message_wds_get_current_settings_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWdsGetCurrentSettingsInput"),
                                          (GBoxedCopyFunc) qmi_message_wds_get_current_settings_input_ref,
                                          (GBoxedFreeFunc) qmi_message_wds_get_current_settings_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wds_get_current_settings_input_ref:
 * @self: a #QmiMessageWdsGetCurrentSettingsInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWdsGetCurrentSettingsInput *
qmi_message_wds_get_current_settings_input_ref (QmiMessageWdsGetCurrentSettingsInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wds_get_current_settings_input_unref:
 * @self: a #QmiMessageWdsGetCurrentSettingsInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wds_get_current_settings_input_unref (QmiMessageWdsGetCurrentSettingsInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWdsGetCurrentSettingsInput, self);
    }
}

/**
 * qmi_message_wds_get_current_settings_input_new:
 *
 * Allocates a new #QmiMessageWdsGetCurrentSettingsInput.
 *
 * Returns: the newly created #QmiMessageWdsGetCurrentSettingsInput. The returned value should be freed with qmi_message_wds_get_current_settings_input_unref().
 */
QmiMessageWdsGetCurrentSettingsInput *
qmi_message_wds_get_current_settings_input_new (void)
{
    QmiMessageWdsGetCurrentSettingsInput *self;

    self = g_slice_new0 (QmiMessageWdsGetCurrentSettingsInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_wds_get_current_settings_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessageWdsGetCurrentSettingsInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WDS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Get Current Settings' has mandatory TLVs");
        qmi_message_unref (self);
        return NULL;
    }

    /* Try to add the 'Requested Settings' TLV */
    if (input->arg_requested_settings_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint32 tmp;

            tmp = (guint32)input->arg_requested_settings;
            /* Write the guint32 variable to the buffer */
            qmi_utils_write_guint32_to_buffer (
                &buffer_aux,
                &buffer_len,
                QMI_ENDIAN_LITTLE,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_INPUT_TLV_REQUESTED_SETTINGS,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Requested Settings TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'Requested Settings' in message 'Get Current Settings'");
        qmi_message_unref (self);
        return NULL;
    }

    return self;
}

/* --- Output -- */

static void
pcscf_domain_name_list_gchar_pointer_clear (gchar * *p)
{
    g_free ((*p));
}

static void
domain_name_list_gchar_pointer_clear (gchar * *p)
{
    g_free ((*p));
}

struct _QmiMessageWdsGetCurrentSettingsOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Profile Name */
    gboolean arg_profile_name_set;
    gchar *arg_profile_name;

    /* PDP Type */
    gboolean arg_pdp_type_set;
    guint8 arg_pdp_type;

    /* APN Name */
    gboolean arg_apn_name_set;
    gchar *arg_apn_name;

    /* Primary IPv4 DNS Address */
    gboolean arg_primary_ipv4_dns_address_set;
    guint32 arg_primary_ipv4_dns_address;

    /* Secondary IPv4 DNS Address */
    gboolean arg_secondary_ipv4_dns_address_set;
    guint32 arg_secondary_ipv4_dns_address;

    /* GPRS Granted QoS */
    gboolean arg_gprs_granted_qos_set;
    guint32 arg_gprs_granted_qos_precedence_class;
    guint32 arg_gprs_granted_qos_delay_class;
    guint32 arg_gprs_granted_qos_reliability_class;
    guint32 arg_gprs_granted_qos_peak_throughput_class;
    guint32 arg_gprs_granted_qos_mean_throughput_class;

    /* Username */
    gboolean arg_username_set;
    gchar *arg_username;

    /* Authentication */
    gboolean arg_authentication_set;
    guint8 arg_authentication;

    /* IPv4 Address */
    gboolean arg_ipv4_address_set;
    guint32 arg_ipv4_address;

    /* Profile ID */
    gboolean arg_profile_id_set;
    guint8 arg_profile_id_profile_type;
    guint8 arg_profile_id_profile_index;

    /* IPv4 Gateway Address */
    gboolean arg_ipv4_gateway_address_set;
    guint32 arg_ipv4_gateway_address;

    /* IPv4 Gateway Subnet Mask */
    gboolean arg_ipv4_gateway_subnet_mask_set;
    guint32 arg_ipv4_gateway_subnet_mask;

    /* PCSCF Address Using PCO */
    gboolean arg_pcscf_address_using_pco_set;
    guint8 arg_pcscf_address_using_pco;

    /* PCSCF Server Address List */
    gboolean arg_pcscf_server_address_list_set;
    GArray *arg_pcscf_server_address_list;

    /* PCSCF Domain Name List */
    gboolean arg_pcscf_domain_name_list_set;
    GArray *arg_pcscf_domain_name_list;

    /* IPv6 Address */
    gboolean arg_ipv6_address_set;
    GArray *arg_ipv6_address_address;
    guint8 arg_ipv6_address_prefix_length;

    /* IPv6 Gateway Address */
    gboolean arg_ipv6_gateway_address_set;
    GArray *arg_ipv6_gateway_address_address;
    guint8 arg_ipv6_gateway_address_prefix_length;

    /* IPv6 Primary DNS Address */
    gboolean arg_ipv6_primary_dns_address_set;
    GArray *arg_ipv6_primary_dns_address;

    /* IPv6 Secondary DNS Address */
    gboolean arg_ipv6_secondary_dns_address_set;
    GArray *arg_ipv6_secondary_dns_address;

    /* MTU */
    gboolean arg_mtu_set;
    guint32 arg_mtu;

    /* Domain Name List */
    gboolean arg_domain_name_list_set;
    GArray *arg_domain_name_list;

    /* IP Family */
    gboolean arg_ip_family_set;
    guint8 arg_ip_family;

    /* IMCN Flag */
    gboolean arg_imcn_flag_set;
    gint8 arg_imcn_flag;

    /* Extended Technology Preference */
    gboolean arg_extended_technology_preference_set;
    guint16 arg_extended_technology_preference;
};

#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PROFILE_NAME 0x10
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PDP_TYPE 0x11
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_APN_NAME 0x14
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PRIMARY_IPV4_DNS_ADDRESS 0x15
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_SECONDARY_IPV4_DNS_ADDRESS 0x16
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_GPRS_GRANTED_QOS 0x19
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_USERNAME 0x1B
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_AUTHENTICATION 0x1D
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV4_ADDRESS 0x1E
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PROFILE_ID 0x1F
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV4_GATEWAY_ADDRESS 0x20
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV4_GATEWAY_SUBNET_MASK 0x21
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PCSCF_ADDRESS_USING_PCO 0x22
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PCSCF_SERVER_ADDRESS_LIST 0x23
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PCSCF_DOMAIN_NAME_LIST 0x24
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV6_ADDRESS 0x25
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV6_GATEWAY_ADDRESS 0x26
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV6_PRIMARY_DNS_ADDRESS 0x27
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV6_SECONDARY_DNS_ADDRESS 0x28
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_MTU 0x29
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_DOMAIN_NAME_LIST 0x2A
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IP_FAMILY 0x2B
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IMCN_FLAG 0x2C
#define QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_EXTENDED_TECHNOLOGY_PREFERENCE 0x2D

/**
 * qmi_message_wds_get_current_settings_output_get_result:
 * @self: a QmiMessageWdsGetCurrentSettingsOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_result (
    QmiMessageWdsGetCurrentSettingsOutput *self,
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
 * qmi_message_wds_get_current_settings_output_get_profile_name:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @profile_name: a placeholder for the output constant string, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Profile Name' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_profile_name (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    const gchar **profile_name,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_profile_name_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Profile Name' was not found in the message");
        return FALSE;
    }

    if (profile_name)
        *profile_name = self->arg_profile_name;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_pdp_type:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @pdp_type: a placeholder for the output #QmiWdsPdpType, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'PDP Type' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_pdp_type (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    QmiWdsPdpType *pdp_type,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_pdp_type_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'PDP Type' was not found in the message");
        return FALSE;
    }

    if (pdp_type)
        *pdp_type = (QmiWdsPdpType)(self->arg_pdp_type);

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_apn_name:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @apn_name: a placeholder for the output constant string, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'APN Name' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_apn_name (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    const gchar **apn_name,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_apn_name_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'APN Name' was not found in the message");
        return FALSE;
    }

    if (apn_name)
        *apn_name = self->arg_apn_name;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_primary_ipv4_dns_address:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @primary_ipv4_dns_address: a placeholder for the output #guint32, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Primary IPv4 DNS Address' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_primary_ipv4_dns_address (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    guint32 *primary_ipv4_dns_address,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_primary_ipv4_dns_address_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Primary IPv4 DNS Address' was not found in the message");
        return FALSE;
    }

    if (primary_ipv4_dns_address)
        *primary_ipv4_dns_address = self->arg_primary_ipv4_dns_address;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_secondary_ipv4_dns_address:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @secondary_ipv4_dns_address: a placeholder for the output #guint32, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Secondary IPv4 DNS Address' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_secondary_ipv4_dns_address (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    guint32 *secondary_ipv4_dns_address,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_secondary_ipv4_dns_address_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Secondary IPv4 DNS Address' was not found in the message");
        return FALSE;
    }

    if (secondary_ipv4_dns_address)
        *secondary_ipv4_dns_address = self->arg_secondary_ipv4_dns_address;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_gprs_granted_qos:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @gprs_granted_qos_precedence_class: a placeholder for the output #guint32, or %NULL if not required.
 * @gprs_granted_qos_delay_class: a placeholder for the output #guint32, or %NULL if not required.
 * @gprs_granted_qos_reliability_class: a placeholder for the output #guint32, or %NULL if not required.
 * @gprs_granted_qos_peak_throughput_class: a placeholder for the output #guint32, or %NULL if not required.
 * @gprs_granted_qos_mean_throughput_class: a placeholder for the output #guint32, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'GPRS Granted QoS' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_gprs_granted_qos (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    guint32 *gprs_granted_qos_precedence_class,
    guint32 *gprs_granted_qos_delay_class,
    guint32 *gprs_granted_qos_reliability_class,
    guint32 *gprs_granted_qos_peak_throughput_class,
    guint32 *gprs_granted_qos_mean_throughput_class,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_gprs_granted_qos_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'GPRS Granted QoS' was not found in the message");
        return FALSE;
    }

    if (gprs_granted_qos_precedence_class)
        *gprs_granted_qos_precedence_class = self->arg_gprs_granted_qos_precedence_class;
    if (gprs_granted_qos_delay_class)
        *gprs_granted_qos_delay_class = self->arg_gprs_granted_qos_delay_class;
    if (gprs_granted_qos_reliability_class)
        *gprs_granted_qos_reliability_class = self->arg_gprs_granted_qos_reliability_class;
    if (gprs_granted_qos_peak_throughput_class)
        *gprs_granted_qos_peak_throughput_class = self->arg_gprs_granted_qos_peak_throughput_class;
    if (gprs_granted_qos_mean_throughput_class)
        *gprs_granted_qos_mean_throughput_class = self->arg_gprs_granted_qos_mean_throughput_class;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_username:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @username: a placeholder for the output constant string, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Username' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_username (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    const gchar **username,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_username_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Username' was not found in the message");
        return FALSE;
    }

    if (username)
        *username = self->arg_username;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_authentication:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @authentication: a placeholder for the output #QmiWdsAuthentication, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Authentication' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_authentication (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    QmiWdsAuthentication *authentication,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_authentication_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Authentication' was not found in the message");
        return FALSE;
    }

    if (authentication)
        *authentication = (QmiWdsAuthentication)(self->arg_authentication);

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_ipv4_address:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @ipv4_address: a placeholder for the output #guint32, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'IPv4 Address' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_ipv4_address (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    guint32 *ipv4_address,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_ipv4_address_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'IPv4 Address' was not found in the message");
        return FALSE;
    }

    if (ipv4_address)
        *ipv4_address = self->arg_ipv4_address;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_profile_id:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @profile_id_profile_type: a placeholder for the output #QmiWdsProfileType, or %NULL if not required.
 * @profile_id_profile_index: a placeholder for the output #guint8, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Profile ID' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_profile_id (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    QmiWdsProfileType *profile_id_profile_type,
    guint8 *profile_id_profile_index,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_profile_id_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Profile ID' was not found in the message");
        return FALSE;
    }

    if (profile_id_profile_type)
        *profile_id_profile_type = (QmiWdsProfileType)(self->arg_profile_id_profile_type);
    if (profile_id_profile_index)
        *profile_id_profile_index = self->arg_profile_id_profile_index;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_ipv4_gateway_address:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @ipv4_gateway_address: a placeholder for the output #guint32, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'IPv4 Gateway Address' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_ipv4_gateway_address (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    guint32 *ipv4_gateway_address,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_ipv4_gateway_address_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'IPv4 Gateway Address' was not found in the message");
        return FALSE;
    }

    if (ipv4_gateway_address)
        *ipv4_gateway_address = self->arg_ipv4_gateway_address;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_ipv4_gateway_subnet_mask:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @ipv4_gateway_subnet_mask: a placeholder for the output #guint32, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'IPv4 Gateway Subnet Mask' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_ipv4_gateway_subnet_mask (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    guint32 *ipv4_gateway_subnet_mask,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_ipv4_gateway_subnet_mask_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'IPv4 Gateway Subnet Mask' was not found in the message");
        return FALSE;
    }

    if (ipv4_gateway_subnet_mask)
        *ipv4_gateway_subnet_mask = self->arg_ipv4_gateway_subnet_mask;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_pcscf_address_using_pco:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @pcscf_address_using_pco: a placeholder for the output #guint8, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'PCSCF Address Using PCO' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_pcscf_address_using_pco (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    guint8 *pcscf_address_using_pco,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_pcscf_address_using_pco_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'PCSCF Address Using PCO' was not found in the message");
        return FALSE;
    }

    if (pcscf_address_using_pco)
        *pcscf_address_using_pco = self->arg_pcscf_address_using_pco;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_pcscf_server_address_list:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @pcscf_server_address_list: a placeholder for the output #GArray of #guint32 elements, or %NULL if not required. Do not free it, it is owned by @self.
 * @error: Return location for error or %NULL.
 *
 * Get the 'PCSCF Server Address List' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_pcscf_server_address_list (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    GArray **pcscf_server_address_list,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_pcscf_server_address_list_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'PCSCF Server Address List' was not found in the message");
        return FALSE;
    }

    if (pcscf_server_address_list)
        *pcscf_server_address_list = self->arg_pcscf_server_address_list;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_pcscf_domain_name_list:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @pcscf_domain_name_list: a placeholder for the output #GArray of #gchar * elements, or %NULL if not required. Do not free it, it is owned by @self.
 * @error: Return location for error or %NULL.
 *
 * Get the 'PCSCF Domain Name List' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_pcscf_domain_name_list (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    GArray **pcscf_domain_name_list,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_pcscf_domain_name_list_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'PCSCF Domain Name List' was not found in the message");
        return FALSE;
    }

    if (pcscf_domain_name_list)
        *pcscf_domain_name_list = self->arg_pcscf_domain_name_list;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_ipv6_address:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @ipv6_address_address: a placeholder for the output #GArray of #guint16 elements, or %NULL if not required. Do not free it, it is owned by @self.
 * @ipv6_address_prefix_length: a placeholder for the output #guint8, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'IPv6 Address' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_ipv6_address (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    GArray **ipv6_address_address,
    guint8 *ipv6_address_prefix_length,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_ipv6_address_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'IPv6 Address' was not found in the message");
        return FALSE;
    }

    if (ipv6_address_address)
        *ipv6_address_address = self->arg_ipv6_address_address;
    if (ipv6_address_prefix_length)
        *ipv6_address_prefix_length = self->arg_ipv6_address_prefix_length;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_ipv6_gateway_address:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @ipv6_gateway_address_address: a placeholder for the output #GArray of #guint16 elements, or %NULL if not required. Do not free it, it is owned by @self.
 * @ipv6_gateway_address_prefix_length: a placeholder for the output #guint8, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'IPv6 Gateway Address' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_ipv6_gateway_address (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    GArray **ipv6_gateway_address_address,
    guint8 *ipv6_gateway_address_prefix_length,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_ipv6_gateway_address_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'IPv6 Gateway Address' was not found in the message");
        return FALSE;
    }

    if (ipv6_gateway_address_address)
        *ipv6_gateway_address_address = self->arg_ipv6_gateway_address_address;
    if (ipv6_gateway_address_prefix_length)
        *ipv6_gateway_address_prefix_length = self->arg_ipv6_gateway_address_prefix_length;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_ipv6_primary_dns_address:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @ipv6_primary_dns_address: a placeholder for the output #GArray of #guint16 elements, or %NULL if not required. Do not free it, it is owned by @self.
 * @error: Return location for error or %NULL.
 *
 * Get the 'IPv6 Primary DNS Address' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_ipv6_primary_dns_address (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    GArray **ipv6_primary_dns_address,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_ipv6_primary_dns_address_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'IPv6 Primary DNS Address' was not found in the message");
        return FALSE;
    }

    if (ipv6_primary_dns_address)
        *ipv6_primary_dns_address = self->arg_ipv6_primary_dns_address;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_ipv6_secondary_dns_address:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @ipv6_secondary_dns_address: a placeholder for the output #GArray of #guint16 elements, or %NULL if not required. Do not free it, it is owned by @self.
 * @error: Return location for error or %NULL.
 *
 * Get the 'IPv6 Secondary DNS Address' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_ipv6_secondary_dns_address (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    GArray **ipv6_secondary_dns_address,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_ipv6_secondary_dns_address_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'IPv6 Secondary DNS Address' was not found in the message");
        return FALSE;
    }

    if (ipv6_secondary_dns_address)
        *ipv6_secondary_dns_address = self->arg_ipv6_secondary_dns_address;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_mtu:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @mtu: a placeholder for the output #guint32, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'MTU' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_mtu (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    guint32 *mtu,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_mtu_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'MTU' was not found in the message");
        return FALSE;
    }

    if (mtu)
        *mtu = self->arg_mtu;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_domain_name_list:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @domain_name_list: a placeholder for the output #GArray of #gchar * elements, or %NULL if not required. Do not free it, it is owned by @self.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Domain Name List' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_domain_name_list (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    GArray **domain_name_list,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_domain_name_list_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Domain Name List' was not found in the message");
        return FALSE;
    }

    if (domain_name_list)
        *domain_name_list = self->arg_domain_name_list;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_ip_family:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @ip_family: a placeholder for the output #QmiWdsIpFamily, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'IP Family' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_ip_family (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    QmiWdsIpFamily *ip_family,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_ip_family_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'IP Family' was not found in the message");
        return FALSE;
    }

    if (ip_family)
        *ip_family = (QmiWdsIpFamily)(self->arg_ip_family);

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_imcn_flag:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @imcn_flag: a placeholder for the output #gint8, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'IMCN Flag' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_imcn_flag (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    gint8 *imcn_flag,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_imcn_flag_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'IMCN Flag' was not found in the message");
        return FALSE;
    }

    if (imcn_flag)
        *imcn_flag = self->arg_imcn_flag;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_settings_output_get_extended_technology_preference:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 * @extended_technology_preference: a placeholder for the output #QmiWdsExtendedTechnologyPreference, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Extended Technology Preference' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_settings_output_get_extended_technology_preference (
    QmiMessageWdsGetCurrentSettingsOutput *self,
    QmiWdsExtendedTechnologyPreference *extended_technology_preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_extended_technology_preference_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Extended Technology Preference' was not found in the message");
        return FALSE;
    }

    if (extended_technology_preference)
        *extended_technology_preference = (QmiWdsExtendedTechnologyPreference)(self->arg_extended_technology_preference);

    return TRUE;
}

GType
qmi_message_wds_get_current_settings_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWdsGetCurrentSettingsOutput"),
                                          (GBoxedCopyFunc) qmi_message_wds_get_current_settings_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wds_get_current_settings_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wds_get_current_settings_output_ref:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWdsGetCurrentSettingsOutput *
qmi_message_wds_get_current_settings_output_ref (QmiMessageWdsGetCurrentSettingsOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wds_get_current_settings_output_unref:
 * @self: a #QmiMessageWdsGetCurrentSettingsOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wds_get_current_settings_output_unref (QmiMessageWdsGetCurrentSettingsOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_free (self->arg_profile_name);
        g_free (self->arg_apn_name);
        g_free (self->arg_username);
        if (self->arg_pcscf_server_address_list)
            g_array_unref (self->arg_pcscf_server_address_list);
        if (self->arg_pcscf_domain_name_list)
            g_array_unref (self->arg_pcscf_domain_name_list);
        if (self->arg_ipv6_address_address)
            g_array_unref (self->arg_ipv6_address_address);
        if (self->arg_ipv6_gateway_address_address)
            g_array_unref (self->arg_ipv6_gateway_address_address);
        if (self->arg_ipv6_primary_dns_address)
            g_array_unref (self->arg_ipv6_primary_dns_address);
        if (self->arg_ipv6_secondary_dns_address)
            g_array_unref (self->arg_ipv6_secondary_dns_address);
        if (self->arg_domain_name_list)
            g_array_unref (self->arg_domain_name_list);
        g_slice_free (QmiMessageWdsGetCurrentSettingsOutput, self);
    }
}

static gboolean
qmi_message_wds_get_current_settings_input_requested_settings_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Requested Settings' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Requested Settings' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_input_requested_settings_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_INPUT_TLV_REQUESTED_SETTINGS,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_input_requested_settings_validate (buffer, buffer_len)) {
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

#if defined  __QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wds_get_current_settings_requested_settings_get_string ((QmiWdsGetCurrentSettingsRequestedSettings)tmp));
#elif defined  __QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wds_get_current_settings_requested_settings_build_string_from_mask ((QmiWdsGetCurrentSettingsRequestedSettings)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWdsGetCurrentSettingsRequestedSettings
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Requested Settings' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_profile_name_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += buffer_len;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Profile Name' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Profile Name' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_profile_name_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PROFILE_NAME,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_profile_name_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Profile Name' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_pdp_type_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'PDP Type' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'PDP Type' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_pdp_type_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PDP_TYPE,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_pdp_type_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WDS_PDP_TYPE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wds_pdp_type_get_string ((QmiWdsPdpType)tmp));
#elif defined  __QMI_WDS_PDP_TYPE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wds_pdp_type_build_string_from_mask ((QmiWdsPdpType)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWdsPdpType
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'PDP Type' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_apn_name_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += buffer_len;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'APN Name' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'APN Name' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_apn_name_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_APN_NAME,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_apn_name_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'APN Name' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_primary_ipv4_dns_address_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Primary IPv4 DNS Address' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Primary IPv4 DNS Address' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_primary_ipv4_dns_address_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PRIMARY_IPV4_DNS_ADDRESS,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_primary_ipv4_dns_address_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Primary IPv4 DNS Address' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_secondary_ipv4_dns_address_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Secondary IPv4 DNS Address' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Secondary IPv4 DNS Address' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_secondary_ipv4_dns_address_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_SECONDARY_IPV4_DNS_ADDRESS,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_secondary_ipv4_dns_address_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Secondary IPv4 DNS Address' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_gprs_granted_qos_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 4;
    expected_len += 4;
    expected_len += 4;
    expected_len += 4;
    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'GPRS Granted QoS' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'GPRS Granted QoS' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_gprs_granted_qos_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_GPRS_GRANTED_QOS,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_gprs_granted_qos_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " precedence_class = '");

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
        g_string_append (printable, " delay_class = '");

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
        g_string_append (printable, " reliability_class = '");

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
        g_string_append (printable, " peak_throughput_class = '");

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
        g_string_append (printable, " mean_throughput_class = '");

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
            g_warning ("Left '%u' bytes unread when getting the 'GPRS Granted QoS' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_username_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += buffer_len;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Username' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Username' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_username_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_USERNAME,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_username_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Username' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_authentication_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Authentication' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Authentication' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_authentication_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_AUTHENTICATION,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_authentication_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WDS_AUTHENTICATION_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wds_authentication_get_string ((QmiWdsAuthentication)tmp));
#elif defined  __QMI_WDS_AUTHENTICATION_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wds_authentication_build_string_from_mask ((QmiWdsAuthentication)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWdsAuthentication
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Authentication' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_ipv4_address_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'IPv4 Address' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'IPv4 Address' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_ipv4_address_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV4_ADDRESS,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_ipv4_address_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'IPv4 Address' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_profile_id_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;
    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Profile ID' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Profile ID' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_profile_id_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PROFILE_ID,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_profile_id_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " profile_type = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WDS_PROFILE_TYPE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wds_profile_type_get_string ((QmiWdsProfileType)tmp));
#elif defined  __QMI_WDS_PROFILE_TYPE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wds_profile_type_build_string_from_mask ((QmiWdsProfileType)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWdsProfileType
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " profile_index = '");

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
            g_warning ("Left '%u' bytes unread when getting the 'Profile ID' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_ipv4_gateway_address_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'IPv4 Gateway Address' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'IPv4 Gateway Address' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_ipv4_gateway_address_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV4_GATEWAY_ADDRESS,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_ipv4_gateway_address_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'IPv4 Gateway Address' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_ipv4_gateway_subnet_mask_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'IPv4 Gateway Subnet Mask' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'IPv4 Gateway Subnet Mask' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_ipv4_gateway_subnet_mask_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV4_GATEWAY_SUBNET_MASK,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_ipv4_gateway_subnet_mask_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'IPv4 Gateway Subnet Mask' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_pcscf_address_using_pco_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'PCSCF Address Using PCO' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'PCSCF Address Using PCO' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_pcscf_address_using_pco_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PCSCF_ADDRESS_USING_PCO,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_pcscf_address_using_pco_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'PCSCF Address Using PCO' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_pcscf_server_address_list_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    {
        guint pcscf_server_address_list_i;
        guint8 pcscf_server_address_list_n_items;
        const guint8 *pcscf_server_address_list_aux_buffer = &buffer[expected_len];
        guint16 pcscf_server_address_list_aux_buffer_len = buffer_len - expected_len;

        expected_len += 1;

        /* Read the guint8 variable from the buffer */
        qmi_utils_read_guint8_from_buffer (
            &pcscf_server_address_list_aux_buffer,
            &pcscf_server_address_list_aux_buffer_len,
            &(pcscf_server_address_list_n_items));
        for (pcscf_server_address_list_i = 0; pcscf_server_address_list_i < pcscf_server_address_list_n_items; pcscf_server_address_list_i++) {

            expected_len += 4;
        }
    }

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'PCSCF Server Address List' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'PCSCF Server Address List' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_pcscf_server_address_list_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PCSCF_SERVER_ADDRESS_LIST,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_pcscf_server_address_list_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        {
            guint pcscf_server_address_list_i;
            guint8 pcscf_server_address_list_n_items;

            /* Read number of items in the array */
            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &(pcscf_server_address_list_n_items));

            g_string_append (printable, "{");

            for (pcscf_server_address_list_i = 0; pcscf_server_address_list_i < pcscf_server_address_list_n_items; pcscf_server_address_list_i++) {
                g_string_append_printf (printable, " [%u] = '", pcscf_server_address_list_i);

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
                g_string_append (printable, " '");
            }

            g_string_append (printable, "}");
        }
        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'PCSCF Server Address List' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_pcscf_domain_name_list_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    {
        guint pcscf_domain_name_list_i;
        guint8 pcscf_domain_name_list_n_items;
        const guint8 *pcscf_domain_name_list_aux_buffer = &buffer[expected_len];
        guint16 pcscf_domain_name_list_aux_buffer_len = buffer_len - expected_len;

        expected_len += 1;

        /* Read the guint8 variable from the buffer */
        qmi_utils_read_guint8_from_buffer (
            &pcscf_domain_name_list_aux_buffer,
            &pcscf_domain_name_list_aux_buffer_len,
            &(pcscf_domain_name_list_n_items));
        for (pcscf_domain_name_list_i = 0; pcscf_domain_name_list_i < pcscf_domain_name_list_n_items; pcscf_domain_name_list_i++) {

            {
                guint16 size16;
                const guint8 *aux_buffer = &buffer[expected_len];
                guint16 aux_buffer_len = buffer_len - expected_len;

                qmi_utils_read_guint16_from_buffer (&aux_buffer, &aux_buffer_len, QMI_ENDIAN_LITTLE, &size16);
                expected_len += (2 + size16);
            }
        }
    }

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'PCSCF Domain Name List' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'PCSCF Domain Name List' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_pcscf_domain_name_list_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PCSCF_DOMAIN_NAME_LIST,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_pcscf_domain_name_list_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        {
            guint pcscf_domain_name_list_i;
            guint8 pcscf_domain_name_list_n_items;

            /* Read number of items in the array */
            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &(pcscf_domain_name_list_n_items));

            g_string_append (printable, "{");

            for (pcscf_domain_name_list_i = 0; pcscf_domain_name_list_i < pcscf_domain_name_list_n_items; pcscf_domain_name_list_i++) {
                g_string_append_printf (printable, " [%u] = '", pcscf_domain_name_list_i);

                {
                    gchar *tmp;

                    /* Read the string variable from the buffer */
                    qmi_utils_read_string_from_buffer (
                        &buffer,
                        &buffer_len,
                        16,
                        0,
                        &tmp);

                    g_string_append_printf (printable, "%s", tmp);
                    g_free (tmp);
                }
                g_string_append (printable, " '");
            }

            g_string_append (printable, "}");
        }
        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'PCSCF Domain Name List' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_ipv6_address_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    {
        guint address_i;
        guint16 address_n_items = 8;

        for (address_i = 0; address_i < address_n_items; address_i++) {

            expected_len += 2;
        }
    }
    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'IPv6 Address' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'IPv6 Address' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_ipv6_address_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV6_ADDRESS,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_ipv6_address_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " address = '");
        {
            guint address_i;
            guint16 address_n_items = 8;


            g_string_append (printable, "{");

            for (address_i = 0; address_i < address_n_items; address_i++) {
                g_string_append_printf (printable, " [%u] = '", address_i);

                {
                    guint16 tmp;

                    /* Read the guint16 variable from the buffer */
                    qmi_utils_read_guint16_from_buffer (
                        &buffer,
                        &buffer_len,
                        QMI_ENDIAN_BIG,
                        &tmp);

                    g_string_append_printf (printable, "%" G_GUINT16_FORMAT "", tmp);
                }
                g_string_append (printable, " '");
            }

            g_string_append (printable, "}");
        }        g_string_append (printable, "'");
        g_string_append (printable, " prefix_length = '");

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
            g_warning ("Left '%u' bytes unread when getting the 'IPv6 Address' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_ipv6_gateway_address_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    {
        guint address_i;
        guint16 address_n_items = 8;

        for (address_i = 0; address_i < address_n_items; address_i++) {

            expected_len += 2;
        }
    }
    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'IPv6 Gateway Address' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'IPv6 Gateway Address' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_ipv6_gateway_address_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV6_GATEWAY_ADDRESS,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_ipv6_gateway_address_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " address = '");
        {
            guint address_i;
            guint16 address_n_items = 8;


            g_string_append (printable, "{");

            for (address_i = 0; address_i < address_n_items; address_i++) {
                g_string_append_printf (printable, " [%u] = '", address_i);

                {
                    guint16 tmp;

                    /* Read the guint16 variable from the buffer */
                    qmi_utils_read_guint16_from_buffer (
                        &buffer,
                        &buffer_len,
                        QMI_ENDIAN_BIG,
                        &tmp);

                    g_string_append_printf (printable, "%" G_GUINT16_FORMAT "", tmp);
                }
                g_string_append (printable, " '");
            }

            g_string_append (printable, "}");
        }        g_string_append (printable, "'");
        g_string_append (printable, " prefix_length = '");

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
            g_warning ("Left '%u' bytes unread when getting the 'IPv6 Gateway Address' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_ipv6_primary_dns_address_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    {
        guint ipv6_primary_dns_address_i;
        guint16 ipv6_primary_dns_address_n_items = 8;

        for (ipv6_primary_dns_address_i = 0; ipv6_primary_dns_address_i < ipv6_primary_dns_address_n_items; ipv6_primary_dns_address_i++) {

            expected_len += 2;
        }
    }

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'IPv6 Primary DNS Address' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'IPv6 Primary DNS Address' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_ipv6_primary_dns_address_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV6_PRIMARY_DNS_ADDRESS,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_ipv6_primary_dns_address_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        {
            guint ipv6_primary_dns_address_i;
            guint16 ipv6_primary_dns_address_n_items = 8;


            g_string_append (printable, "{");

            for (ipv6_primary_dns_address_i = 0; ipv6_primary_dns_address_i < ipv6_primary_dns_address_n_items; ipv6_primary_dns_address_i++) {
                g_string_append_printf (printable, " [%u] = '", ipv6_primary_dns_address_i);

                {
                    guint16 tmp;

                    /* Read the guint16 variable from the buffer */
                    qmi_utils_read_guint16_from_buffer (
                        &buffer,
                        &buffer_len,
                        QMI_ENDIAN_BIG,
                        &tmp);

                    g_string_append_printf (printable, "%" G_GUINT16_FORMAT "", tmp);
                }
                g_string_append (printable, " '");
            }

            g_string_append (printable, "}");
        }
        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'IPv6 Primary DNS Address' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_ipv6_secondary_dns_address_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    {
        guint ipv6_secondary_dns_address_i;
        guint16 ipv6_secondary_dns_address_n_items = 8;

        for (ipv6_secondary_dns_address_i = 0; ipv6_secondary_dns_address_i < ipv6_secondary_dns_address_n_items; ipv6_secondary_dns_address_i++) {

            expected_len += 2;
        }
    }

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'IPv6 Secondary DNS Address' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'IPv6 Secondary DNS Address' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_ipv6_secondary_dns_address_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV6_SECONDARY_DNS_ADDRESS,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_ipv6_secondary_dns_address_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        {
            guint ipv6_secondary_dns_address_i;
            guint16 ipv6_secondary_dns_address_n_items = 8;


            g_string_append (printable, "{");

            for (ipv6_secondary_dns_address_i = 0; ipv6_secondary_dns_address_i < ipv6_secondary_dns_address_n_items; ipv6_secondary_dns_address_i++) {
                g_string_append_printf (printable, " [%u] = '", ipv6_secondary_dns_address_i);

                {
                    guint16 tmp;

                    /* Read the guint16 variable from the buffer */
                    qmi_utils_read_guint16_from_buffer (
                        &buffer,
                        &buffer_len,
                        QMI_ENDIAN_BIG,
                        &tmp);

                    g_string_append_printf (printable, "%" G_GUINT16_FORMAT "", tmp);
                }
                g_string_append (printable, " '");
            }

            g_string_append (printable, "}");
        }
        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'IPv6 Secondary DNS Address' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_mtu_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'MTU' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'MTU' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_mtu_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_MTU,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_mtu_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'MTU' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_domain_name_list_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    {
        guint domain_name_list_i;
        guint8 domain_name_list_n_items;
        const guint8 *domain_name_list_aux_buffer = &buffer[expected_len];
        guint16 domain_name_list_aux_buffer_len = buffer_len - expected_len;

        expected_len += 1;

        /* Read the guint8 variable from the buffer */
        qmi_utils_read_guint8_from_buffer (
            &domain_name_list_aux_buffer,
            &domain_name_list_aux_buffer_len,
            &(domain_name_list_n_items));
        for (domain_name_list_i = 0; domain_name_list_i < domain_name_list_n_items; domain_name_list_i++) {

            {
                guint16 size16;
                const guint8 *aux_buffer = &buffer[expected_len];
                guint16 aux_buffer_len = buffer_len - expected_len;

                qmi_utils_read_guint16_from_buffer (&aux_buffer, &aux_buffer_len, QMI_ENDIAN_LITTLE, &size16);
                expected_len += (2 + size16);
            }
        }
    }

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Domain Name List' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Domain Name List' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_domain_name_list_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_DOMAIN_NAME_LIST,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_domain_name_list_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        {
            guint domain_name_list_i;
            guint8 domain_name_list_n_items;

            /* Read number of items in the array */
            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &(domain_name_list_n_items));

            g_string_append (printable, "{");

            for (domain_name_list_i = 0; domain_name_list_i < domain_name_list_n_items; domain_name_list_i++) {
                g_string_append_printf (printable, " [%u] = '", domain_name_list_i);

                {
                    gchar *tmp;

                    /* Read the string variable from the buffer */
                    qmi_utils_read_string_from_buffer (
                        &buffer,
                        &buffer_len,
                        16,
                        0,
                        &tmp);

                    g_string_append_printf (printable, "%s", tmp);
                    g_free (tmp);
                }
                g_string_append (printable, " '");
            }

            g_string_append (printable, "}");
        }
        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Domain Name List' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_ip_family_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'IP Family' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'IP Family' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_ip_family_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IP_FAMILY,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_ip_family_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WDS_IP_FAMILY_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wds_ip_family_get_string ((QmiWdsIpFamily)tmp));
#elif defined  __QMI_WDS_IP_FAMILY_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wds_ip_family_build_string_from_mask ((QmiWdsIpFamily)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWdsIpFamily
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'IP Family' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_imcn_flag_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'IMCN Flag' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'IMCN Flag' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_imcn_flag_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IMCN_FLAG,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_imcn_flag_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            gint8 tmp;

            /* Read the gint8 variable from the buffer */
            qmi_utils_read_gint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

            g_string_append_printf (printable, "%d", (gint)tmp);
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'IMCN Flag' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_settings_output_extended_technology_preference_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 2;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Extended Technology Preference' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Extended Technology Preference' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_settings_output_extended_technology_preference_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_EXTENDED_TECHNOLOGY_PREFERENCE,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_settings_output_extended_technology_preference_validate (buffer, buffer_len)) {
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

#if defined  __QMI_WDS_EXTENDED_TECHNOLOGY_PREFERENCE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wds_extended_technology_preference_get_string ((QmiWdsExtendedTechnologyPreference)tmp));
#elif defined  __QMI_WDS_EXTENDED_TECHNOLOGY_PREFERENCE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wds_extended_technology_preference_build_string_from_mask ((QmiWdsExtendedTechnologyPreference)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWdsExtendedTechnologyPreference
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Extended Technology Preference' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_get_current_settings_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_get_current_settings_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_get_current_settings_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_INPUT_TLV_REQUESTED_SETTINGS:
            tlv_type_str = "Requested Settings";
            translated_value = qmi_message_wds_get_current_settings_input_requested_settings_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PROFILE_NAME:
            tlv_type_str = "Profile Name";
            translated_value = qmi_message_wds_get_current_settings_output_profile_name_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PDP_TYPE:
            tlv_type_str = "PDP Type";
            translated_value = qmi_message_wds_get_current_settings_output_pdp_type_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_APN_NAME:
            tlv_type_str = "APN Name";
            translated_value = qmi_message_wds_get_current_settings_output_apn_name_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PRIMARY_IPV4_DNS_ADDRESS:
            tlv_type_str = "Primary IPv4 DNS Address";
            translated_value = qmi_message_wds_get_current_settings_output_primary_ipv4_dns_address_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_SECONDARY_IPV4_DNS_ADDRESS:
            tlv_type_str = "Secondary IPv4 DNS Address";
            translated_value = qmi_message_wds_get_current_settings_output_secondary_ipv4_dns_address_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_GPRS_GRANTED_QOS:
            tlv_type_str = "GPRS Granted QoS";
            translated_value = qmi_message_wds_get_current_settings_output_gprs_granted_qos_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_USERNAME:
            tlv_type_str = "Username";
            translated_value = qmi_message_wds_get_current_settings_output_username_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_AUTHENTICATION:
            tlv_type_str = "Authentication";
            translated_value = qmi_message_wds_get_current_settings_output_authentication_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV4_ADDRESS:
            tlv_type_str = "IPv4 Address";
            translated_value = qmi_message_wds_get_current_settings_output_ipv4_address_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PROFILE_ID:
            tlv_type_str = "Profile ID";
            translated_value = qmi_message_wds_get_current_settings_output_profile_id_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV4_GATEWAY_ADDRESS:
            tlv_type_str = "IPv4 Gateway Address";
            translated_value = qmi_message_wds_get_current_settings_output_ipv4_gateway_address_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV4_GATEWAY_SUBNET_MASK:
            tlv_type_str = "IPv4 Gateway Subnet Mask";
            translated_value = qmi_message_wds_get_current_settings_output_ipv4_gateway_subnet_mask_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PCSCF_ADDRESS_USING_PCO:
            tlv_type_str = "PCSCF Address Using PCO";
            translated_value = qmi_message_wds_get_current_settings_output_pcscf_address_using_pco_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PCSCF_SERVER_ADDRESS_LIST:
            tlv_type_str = "PCSCF Server Address List";
            translated_value = qmi_message_wds_get_current_settings_output_pcscf_server_address_list_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PCSCF_DOMAIN_NAME_LIST:
            tlv_type_str = "PCSCF Domain Name List";
            translated_value = qmi_message_wds_get_current_settings_output_pcscf_domain_name_list_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV6_ADDRESS:
            tlv_type_str = "IPv6 Address";
            translated_value = qmi_message_wds_get_current_settings_output_ipv6_address_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV6_GATEWAY_ADDRESS:
            tlv_type_str = "IPv6 Gateway Address";
            translated_value = qmi_message_wds_get_current_settings_output_ipv6_gateway_address_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV6_PRIMARY_DNS_ADDRESS:
            tlv_type_str = "IPv6 Primary DNS Address";
            translated_value = qmi_message_wds_get_current_settings_output_ipv6_primary_dns_address_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV6_SECONDARY_DNS_ADDRESS:
            tlv_type_str = "IPv6 Secondary DNS Address";
            translated_value = qmi_message_wds_get_current_settings_output_ipv6_secondary_dns_address_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_MTU:
            tlv_type_str = "MTU";
            translated_value = qmi_message_wds_get_current_settings_output_mtu_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_DOMAIN_NAME_LIST:
            tlv_type_str = "Domain Name List";
            translated_value = qmi_message_wds_get_current_settings_output_domain_name_list_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IP_FAMILY:
            tlv_type_str = "IP Family";
            translated_value = qmi_message_wds_get_current_settings_output_ip_family_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IMCN_FLAG:
            tlv_type_str = "IMCN Flag";
            translated_value = qmi_message_wds_get_current_settings_output_imcn_flag_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_EXTENDED_TECHNOLOGY_PREFERENCE:
            tlv_type_str = "Extended Technology Preference";
            translated_value = qmi_message_wds_get_current_settings_output_extended_technology_preference_get_printable (
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
message_get_current_settings_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Get Current Settings\" (0x002D)\n",
                            line_prefix);

    {
        struct message_get_current_settings_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_get_current_settings_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageWdsGetCurrentSettingsOutput *
__qmi_message_wds_get_current_settings_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWdsGetCurrentSettingsOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS, NULL);

    self = g_slice_new0 (QmiMessageWdsGetCurrentSettingsOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_RESULT,
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
                qmi_message_wds_get_current_settings_output_unref (self);
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PROFILE_NAME,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_profile_name_validate (buffer, buffer_len)) {
                self->arg_profile_name_set = TRUE;

                /* Read the string variable from the buffer */
                qmi_utils_read_string_from_buffer (
                    &buffer,
                    &buffer_len,
                    0,
                    0,
                    &(self->arg_profile_name));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Profile Name' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PDP_TYPE,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_pdp_type_validate (buffer, buffer_len)) {
                self->arg_pdp_type_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_pdp_type = (QmiWdsPdpType)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'PDP Type' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_APN_NAME,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_apn_name_validate (buffer, buffer_len)) {
                self->arg_apn_name_set = TRUE;

                /* Read the string variable from the buffer */
                qmi_utils_read_string_from_buffer (
                    &buffer,
                    &buffer_len,
                    0,
                    0,
                    &(self->arg_apn_name));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'APN Name' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PRIMARY_IPV4_DNS_ADDRESS,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_primary_ipv4_dns_address_validate (buffer, buffer_len)) {
                self->arg_primary_ipv4_dns_address_set = TRUE;

                /* Read the guint32 variable from the buffer */
                qmi_utils_read_guint32_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_primary_ipv4_dns_address));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Primary IPv4 DNS Address' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_SECONDARY_IPV4_DNS_ADDRESS,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_secondary_ipv4_dns_address_validate (buffer, buffer_len)) {
                self->arg_secondary_ipv4_dns_address_set = TRUE;

                /* Read the guint32 variable from the buffer */
                qmi_utils_read_guint32_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_secondary_ipv4_dns_address));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Secondary IPv4 DNS Address' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_GPRS_GRANTED_QOS,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_gprs_granted_qos_validate (buffer, buffer_len)) {
                self->arg_gprs_granted_qos_set = TRUE;

                /* Read the guint32 variable from the buffer */
                qmi_utils_read_guint32_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_gprs_granted_qos_precedence_class));
                /* Read the guint32 variable from the buffer */
                qmi_utils_read_guint32_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_gprs_granted_qos_delay_class));
                /* Read the guint32 variable from the buffer */
                qmi_utils_read_guint32_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_gprs_granted_qos_reliability_class));
                /* Read the guint32 variable from the buffer */
                qmi_utils_read_guint32_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_gprs_granted_qos_peak_throughput_class));
                /* Read the guint32 variable from the buffer */
                qmi_utils_read_guint32_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_gprs_granted_qos_mean_throughput_class));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'GPRS Granted QoS' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_USERNAME,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_username_validate (buffer, buffer_len)) {
                self->arg_username_set = TRUE;

                /* Read the string variable from the buffer */
                qmi_utils_read_string_from_buffer (
                    &buffer,
                    &buffer_len,
                    0,
                    0,
                    &(self->arg_username));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Username' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_AUTHENTICATION,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_authentication_validate (buffer, buffer_len)) {
                self->arg_authentication_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_authentication = (QmiWdsAuthentication)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Authentication' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV4_ADDRESS,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_ipv4_address_validate (buffer, buffer_len)) {
                self->arg_ipv4_address_set = TRUE;

                /* Read the guint32 variable from the buffer */
                qmi_utils_read_guint32_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_ipv4_address));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'IPv4 Address' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PROFILE_ID,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_profile_id_validate (buffer, buffer_len)) {
                self->arg_profile_id_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_profile_id_profile_type = (QmiWdsProfileType)tmp;
                }
                /* Read the guint8 variable from the buffer */
                qmi_utils_read_guint8_from_buffer (
                    &buffer,
                    &buffer_len,
                    &(self->arg_profile_id_profile_index));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Profile ID' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV4_GATEWAY_ADDRESS,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_ipv4_gateway_address_validate (buffer, buffer_len)) {
                self->arg_ipv4_gateway_address_set = TRUE;

                /* Read the guint32 variable from the buffer */
                qmi_utils_read_guint32_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_ipv4_gateway_address));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'IPv4 Gateway Address' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV4_GATEWAY_SUBNET_MASK,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_ipv4_gateway_subnet_mask_validate (buffer, buffer_len)) {
                self->arg_ipv4_gateway_subnet_mask_set = TRUE;

                /* Read the guint32 variable from the buffer */
                qmi_utils_read_guint32_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_ipv4_gateway_subnet_mask));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'IPv4 Gateway Subnet Mask' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PCSCF_ADDRESS_USING_PCO,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_pcscf_address_using_pco_validate (buffer, buffer_len)) {
                self->arg_pcscf_address_using_pco_set = TRUE;

                /* Read the guint8 variable from the buffer */
                qmi_utils_read_guint8_from_buffer (
                    &buffer,
                    &buffer_len,
                    &(self->arg_pcscf_address_using_pco));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'PCSCF Address Using PCO' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PCSCF_SERVER_ADDRESS_LIST,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_pcscf_server_address_list_validate (buffer, buffer_len)) {
                self->arg_pcscf_server_address_list_set = TRUE;

                {
                    guint pcscf_server_address_list_i;
                    guint8 pcscf_server_address_list_n_items;

                    /* Read number of items in the array */
                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &(pcscf_server_address_list_n_items));

                    self->arg_pcscf_server_address_list = g_array_sized_new (
                        FALSE,
                        FALSE,
                        sizeof (guint32),
                        (guint)pcscf_server_address_list_n_items);

                    for (pcscf_server_address_list_i = 0; pcscf_server_address_list_i < pcscf_server_address_list_n_items; pcscf_server_address_list_i++) {
                        guint32 pcscf_server_address_list_aux;

                        /* Read the guint32 variable from the buffer */
                        qmi_utils_read_guint32_from_buffer (
                            &buffer,
                            &buffer_len,
                            QMI_ENDIAN_LITTLE,
                            &(pcscf_server_address_list_aux));
                        g_array_insert_val (self->arg_pcscf_server_address_list, pcscf_server_address_list_i, pcscf_server_address_list_aux);
                    }
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'PCSCF Server Address List' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_PCSCF_DOMAIN_NAME_LIST,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_pcscf_domain_name_list_validate (buffer, buffer_len)) {
                self->arg_pcscf_domain_name_list_set = TRUE;

                {
                    guint pcscf_domain_name_list_i;
                    guint8 pcscf_domain_name_list_n_items;

                    /* Read number of items in the array */
                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &(pcscf_domain_name_list_n_items));

                    self->arg_pcscf_domain_name_list = g_array_sized_new (
                        FALSE,
                        FALSE,
                        sizeof (gchar *),
                        (guint)pcscf_domain_name_list_n_items);

                    g_array_set_clear_func (self->arg_pcscf_domain_name_list,
                                            (GDestroyNotify)pcscf_domain_name_list_gchar_pointer_clear);

                    for (pcscf_domain_name_list_i = 0; pcscf_domain_name_list_i < pcscf_domain_name_list_n_items; pcscf_domain_name_list_i++) {
                        gchar * pcscf_domain_name_list_aux;

                        /* Read the string variable from the buffer */
                        qmi_utils_read_string_from_buffer (
                            &buffer,
                            &buffer_len,
                            16,
                            0,
                            &(pcscf_domain_name_list_aux));
                        g_array_insert_val (self->arg_pcscf_domain_name_list, pcscf_domain_name_list_i, pcscf_domain_name_list_aux);
                    }
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'PCSCF Domain Name List' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV6_ADDRESS,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_ipv6_address_validate (buffer, buffer_len)) {
                self->arg_ipv6_address_set = TRUE;

                {
                    guint address_i;
                    guint16 address_n_items = 8;


                    self->arg_ipv6_address_address = g_array_sized_new (
                        FALSE,
                        FALSE,
                        sizeof (guint16),
                        (guint)address_n_items);

                    for (address_i = 0; address_i < address_n_items; address_i++) {
                        guint16 address_aux;

                        /* Read the guint16 variable from the buffer */
                        qmi_utils_read_guint16_from_buffer (
                            &buffer,
                            &buffer_len,
                            QMI_ENDIAN_BIG,
                            &(address_aux));
                        g_array_insert_val (self->arg_ipv6_address_address, address_i, address_aux);
                    }
                }
                /* Read the guint8 variable from the buffer */
                qmi_utils_read_guint8_from_buffer (
                    &buffer,
                    &buffer_len,
                    &(self->arg_ipv6_address_prefix_length));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'IPv6 Address' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV6_GATEWAY_ADDRESS,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_ipv6_gateway_address_validate (buffer, buffer_len)) {
                self->arg_ipv6_gateway_address_set = TRUE;

                {
                    guint address_i;
                    guint16 address_n_items = 8;


                    self->arg_ipv6_gateway_address_address = g_array_sized_new (
                        FALSE,
                        FALSE,
                        sizeof (guint16),
                        (guint)address_n_items);

                    for (address_i = 0; address_i < address_n_items; address_i++) {
                        guint16 address_aux;

                        /* Read the guint16 variable from the buffer */
                        qmi_utils_read_guint16_from_buffer (
                            &buffer,
                            &buffer_len,
                            QMI_ENDIAN_BIG,
                            &(address_aux));
                        g_array_insert_val (self->arg_ipv6_gateway_address_address, address_i, address_aux);
                    }
                }
                /* Read the guint8 variable from the buffer */
                qmi_utils_read_guint8_from_buffer (
                    &buffer,
                    &buffer_len,
                    &(self->arg_ipv6_gateway_address_prefix_length));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'IPv6 Gateway Address' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV6_PRIMARY_DNS_ADDRESS,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_ipv6_primary_dns_address_validate (buffer, buffer_len)) {
                self->arg_ipv6_primary_dns_address_set = TRUE;

                {
                    guint ipv6_primary_dns_address_i;
                    guint16 ipv6_primary_dns_address_n_items = 8;


                    self->arg_ipv6_primary_dns_address = g_array_sized_new (
                        FALSE,
                        FALSE,
                        sizeof (guint16),
                        (guint)ipv6_primary_dns_address_n_items);

                    for (ipv6_primary_dns_address_i = 0; ipv6_primary_dns_address_i < ipv6_primary_dns_address_n_items; ipv6_primary_dns_address_i++) {
                        guint16 ipv6_primary_dns_address_aux;

                        /* Read the guint16 variable from the buffer */
                        qmi_utils_read_guint16_from_buffer (
                            &buffer,
                            &buffer_len,
                            QMI_ENDIAN_BIG,
                            &(ipv6_primary_dns_address_aux));
                        g_array_insert_val (self->arg_ipv6_primary_dns_address, ipv6_primary_dns_address_i, ipv6_primary_dns_address_aux);
                    }
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'IPv6 Primary DNS Address' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IPV6_SECONDARY_DNS_ADDRESS,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_ipv6_secondary_dns_address_validate (buffer, buffer_len)) {
                self->arg_ipv6_secondary_dns_address_set = TRUE;

                {
                    guint ipv6_secondary_dns_address_i;
                    guint16 ipv6_secondary_dns_address_n_items = 8;


                    self->arg_ipv6_secondary_dns_address = g_array_sized_new (
                        FALSE,
                        FALSE,
                        sizeof (guint16),
                        (guint)ipv6_secondary_dns_address_n_items);

                    for (ipv6_secondary_dns_address_i = 0; ipv6_secondary_dns_address_i < ipv6_secondary_dns_address_n_items; ipv6_secondary_dns_address_i++) {
                        guint16 ipv6_secondary_dns_address_aux;

                        /* Read the guint16 variable from the buffer */
                        qmi_utils_read_guint16_from_buffer (
                            &buffer,
                            &buffer_len,
                            QMI_ENDIAN_BIG,
                            &(ipv6_secondary_dns_address_aux));
                        g_array_insert_val (self->arg_ipv6_secondary_dns_address, ipv6_secondary_dns_address_i, ipv6_secondary_dns_address_aux);
                    }
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'IPv6 Secondary DNS Address' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_MTU,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_mtu_validate (buffer, buffer_len)) {
                self->arg_mtu_set = TRUE;

                /* Read the guint32 variable from the buffer */
                qmi_utils_read_guint32_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_mtu));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'MTU' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_DOMAIN_NAME_LIST,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_domain_name_list_validate (buffer, buffer_len)) {
                self->arg_domain_name_list_set = TRUE;

                {
                    guint domain_name_list_i;
                    guint8 domain_name_list_n_items;

                    /* Read number of items in the array */
                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &(domain_name_list_n_items));

                    self->arg_domain_name_list = g_array_sized_new (
                        FALSE,
                        FALSE,
                        sizeof (gchar *),
                        (guint)domain_name_list_n_items);

                    g_array_set_clear_func (self->arg_domain_name_list,
                                            (GDestroyNotify)domain_name_list_gchar_pointer_clear);

                    for (domain_name_list_i = 0; domain_name_list_i < domain_name_list_n_items; domain_name_list_i++) {
                        gchar * domain_name_list_aux;

                        /* Read the string variable from the buffer */
                        qmi_utils_read_string_from_buffer (
                            &buffer,
                            &buffer_len,
                            16,
                            0,
                            &(domain_name_list_aux));
                        g_array_insert_val (self->arg_domain_name_list, domain_name_list_i, domain_name_list_aux);
                    }
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Domain Name List' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IP_FAMILY,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_ip_family_validate (buffer, buffer_len)) {
                self->arg_ip_family_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_ip_family = (QmiWdsIpFamily)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'IP Family' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_IMCN_FLAG,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_imcn_flag_validate (buffer, buffer_len)) {
                self->arg_imcn_flag_set = TRUE;

                /* Read the gint8 variable from the buffer */
                qmi_utils_read_gint8_from_buffer (
                    &buffer,
                    &buffer_len,
                    &(self->arg_imcn_flag));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'IMCN Flag' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS_OUTPUT_TLV_EXTENDED_TECHNOLOGY_PREFERENCE,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_settings_output_extended_technology_preference_validate (buffer, buffer_len)) {
                self->arg_extended_technology_preference_set = TRUE;

                {
                    guint16 tmp;

                    /* Read the guint16 variable from the buffer */
                    qmi_utils_read_guint16_from_buffer (
                        &buffer,
                        &buffer_len,
                        QMI_ENDIAN_LITTLE,
                        &tmp);
                    self->arg_extended_technology_preference = (QmiWdsExtendedTechnologyPreference)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Extended Technology Preference' TLV", buffer_len);
                }
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WDS Get Data Bearer Technology */


/* --- Input -- */

/* Note: no fields in the Input container */

static QmiMessage *
__qmi_message_wds_get_data_bearer_technology_request_create (
    guint8 transaction_id,
    guint8 cid,
    gpointer unused,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WDS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WDS_GET_DATA_BEARER_TECHNOLOGY);

    return self;
}

/* --- Output -- */

struct _QmiMessageWdsGetDataBearerTechnologyOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Current */
    gboolean arg_current_set;
    gint8 arg_current;

    /* Last */
    gboolean arg_last_set;
    gint8 arg_last;
};

#define QMI_MESSAGE_WDS_GET_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_WDS_GET_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_CURRENT 0x01
#define QMI_MESSAGE_WDS_GET_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_LAST 0x10

/**
 * qmi_message_wds_get_data_bearer_technology_output_get_result:
 * @self: a QmiMessageWdsGetDataBearerTechnologyOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wds_get_data_bearer_technology_output_get_result (
    QmiMessageWdsGetDataBearerTechnologyOutput *self,
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
 * qmi_message_wds_get_data_bearer_technology_output_get_current:
 * @self: a #QmiMessageWdsGetDataBearerTechnologyOutput.
 * @current: a placeholder for the output #QmiWdsDataBearerTechnology, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Current' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_data_bearer_technology_output_get_current (
    QmiMessageWdsGetDataBearerTechnologyOutput *self,
    QmiWdsDataBearerTechnology *current,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_current_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Current' was not found in the message");
        return FALSE;
    }

    if (current)
        *current = (QmiWdsDataBearerTechnology)(self->arg_current);

    return TRUE;
}

/**
 * qmi_message_wds_get_data_bearer_technology_output_get_last:
 * @self: a #QmiMessageWdsGetDataBearerTechnologyOutput.
 * @last: a placeholder for the output #QmiWdsDataBearerTechnology, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Last' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_data_bearer_technology_output_get_last (
    QmiMessageWdsGetDataBearerTechnologyOutput *self,
    QmiWdsDataBearerTechnology *last,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_last_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Last' was not found in the message");
        return FALSE;
    }

    if (last)
        *last = (QmiWdsDataBearerTechnology)(self->arg_last);

    return TRUE;
}

GType
qmi_message_wds_get_data_bearer_technology_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWdsGetDataBearerTechnologyOutput"),
                                          (GBoxedCopyFunc) qmi_message_wds_get_data_bearer_technology_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wds_get_data_bearer_technology_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wds_get_data_bearer_technology_output_ref:
 * @self: a #QmiMessageWdsGetDataBearerTechnologyOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWdsGetDataBearerTechnologyOutput *
qmi_message_wds_get_data_bearer_technology_output_ref (QmiMessageWdsGetDataBearerTechnologyOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wds_get_data_bearer_technology_output_unref:
 * @self: a #QmiMessageWdsGetDataBearerTechnologyOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wds_get_data_bearer_technology_output_unref (QmiMessageWdsGetDataBearerTechnologyOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWdsGetDataBearerTechnologyOutput, self);
    }
}

static gboolean
qmi_message_wds_get_data_bearer_technology_output_current_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Current' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Current' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_data_bearer_technology_output_current_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_CURRENT,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_data_bearer_technology_output_current_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            gint8 tmp;

            /* Read the gint8 variable from the buffer */
            qmi_utils_read_gint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WDS_DATA_BEARER_TECHNOLOGY_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wds_data_bearer_technology_get_string ((QmiWdsDataBearerTechnology)tmp));
#elif defined  __QMI_WDS_DATA_BEARER_TECHNOLOGY_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wds_data_bearer_technology_build_string_from_mask ((QmiWdsDataBearerTechnology)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWdsDataBearerTechnology
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Current' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_data_bearer_technology_output_last_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Last' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Last' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_data_bearer_technology_output_last_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_LAST,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_data_bearer_technology_output_last_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            gint8 tmp;

            /* Read the gint8 variable from the buffer */
            qmi_utils_read_gint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WDS_DATA_BEARER_TECHNOLOGY_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wds_data_bearer_technology_get_string ((QmiWdsDataBearerTechnology)tmp));
#elif defined  __QMI_WDS_DATA_BEARER_TECHNOLOGY_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wds_data_bearer_technology_build_string_from_mask ((QmiWdsDataBearerTechnology)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWdsDataBearerTechnology
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Last' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_get_data_bearer_technology_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_get_data_bearer_technology_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_get_data_bearer_technology_context *ctx)
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
        case QMI_MESSAGE_WDS_GET_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_CURRENT:
            tlv_type_str = "Current";
            translated_value = qmi_message_wds_get_data_bearer_technology_output_current_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_LAST:
            tlv_type_str = "Last";
            translated_value = qmi_message_wds_get_data_bearer_technology_output_last_get_printable (
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
message_get_data_bearer_technology_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Get Data Bearer Technology\" (0x0037)\n",
                            line_prefix);

    {
        struct message_get_data_bearer_technology_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_get_data_bearer_technology_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageWdsGetDataBearerTechnologyOutput *
__qmi_message_wds_get_data_bearer_technology_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWdsGetDataBearerTechnologyOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WDS_GET_DATA_BEARER_TECHNOLOGY, NULL);

    self = g_slice_new0 (QmiMessageWdsGetDataBearerTechnologyOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WDS_GET_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_RESULT,
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
                qmi_message_wds_get_data_bearer_technology_output_unref (self);
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
                                              QMI_MESSAGE_WDS_GET_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_CURRENT,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_data_bearer_technology_output_current_validate (buffer, buffer_len)) {
                self->arg_current_set = TRUE;

                {
                    gint8 tmp;

                    /* Read the gint8 variable from the buffer */
                    qmi_utils_read_gint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_current = (QmiWdsDataBearerTechnology)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Current' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the Current TLV: Not found");
                qmi_message_wds_get_data_bearer_technology_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    do {
        /* Prerequisite.... */
        if (!(self->arg_result.error_status != QMI_STATUS_SUCCESS))
            break;
        /* Prerequisite.... */
        if (!(self->arg_result.error_code == QMI_PROTOCOL_ERROR_OUT_OF_CALL))
            break;

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WDS_GET_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_LAST,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_data_bearer_technology_output_last_validate (buffer, buffer_len)) {
                self->arg_last_set = TRUE;

                {
                    gint8 tmp;

                    /* Read the gint8 variable from the buffer */
                    qmi_utils_read_gint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_last = (QmiWdsDataBearerTechnology)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Last' TLV", buffer_len);
                }
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WDS Get Current Data Bearer Technology */


/* --- Input -- */

/* Note: no fields in the Input container */

static QmiMessage *
__qmi_message_wds_get_current_data_bearer_technology_request_create (
    guint8 transaction_id,
    guint8 cid,
    gpointer unused,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WDS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WDS_GET_CURRENT_DATA_BEARER_TECHNOLOGY);

    return self;
}

/* --- Output -- */

struct _QmiMessageWdsGetCurrentDataBearerTechnologyOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Last */
    gboolean arg_last_set;
    guint8 arg_last_network_type;
    guint32 arg_last_rat_mask;
    guint32 arg_last_so_mask;

    /* Current */
    gboolean arg_current_set;
    guint8 arg_current_network_type;
    guint32 arg_current_rat_mask;
    guint32 arg_current_so_mask;
};

#define QMI_MESSAGE_WDS_GET_CURRENT_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_WDS_GET_CURRENT_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_LAST 0x10
#define QMI_MESSAGE_WDS_GET_CURRENT_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_CURRENT 0x01

/**
 * qmi_message_wds_get_current_data_bearer_technology_output_get_result:
 * @self: a QmiMessageWdsGetCurrentDataBearerTechnologyOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wds_get_current_data_bearer_technology_output_get_result (
    QmiMessageWdsGetCurrentDataBearerTechnologyOutput *self,
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
 * qmi_message_wds_get_current_data_bearer_technology_output_get_last:
 * @self: a #QmiMessageWdsGetCurrentDataBearerTechnologyOutput.
 * @last_network_type: a placeholder for the output #QmiWdsNetworkType, or %NULL if not required.
 * @last_rat_mask: a placeholder for the output #guint32, or %NULL if not required.
 * @last_so_mask: a placeholder for the output #guint32, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Last' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_data_bearer_technology_output_get_last (
    QmiMessageWdsGetCurrentDataBearerTechnologyOutput *self,
    QmiWdsNetworkType *last_network_type,
    guint32 *last_rat_mask,
    guint32 *last_so_mask,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_last_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Last' was not found in the message");
        return FALSE;
    }

    if (last_network_type)
        *last_network_type = (QmiWdsNetworkType)(self->arg_last_network_type);
    if (last_rat_mask)
        *last_rat_mask = self->arg_last_rat_mask;
    if (last_so_mask)
        *last_so_mask = self->arg_last_so_mask;

    return TRUE;
}

/**
 * qmi_message_wds_get_current_data_bearer_technology_output_get_current:
 * @self: a #QmiMessageWdsGetCurrentDataBearerTechnologyOutput.
 * @current_network_type: a placeholder for the output #QmiWdsNetworkType, or %NULL if not required.
 * @current_rat_mask: a placeholder for the output #guint32, or %NULL if not required.
 * @current_so_mask: a placeholder for the output #guint32, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Current' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_get_current_data_bearer_technology_output_get_current (
    QmiMessageWdsGetCurrentDataBearerTechnologyOutput *self,
    QmiWdsNetworkType *current_network_type,
    guint32 *current_rat_mask,
    guint32 *current_so_mask,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_current_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Current' was not found in the message");
        return FALSE;
    }

    if (current_network_type)
        *current_network_type = (QmiWdsNetworkType)(self->arg_current_network_type);
    if (current_rat_mask)
        *current_rat_mask = self->arg_current_rat_mask;
    if (current_so_mask)
        *current_so_mask = self->arg_current_so_mask;

    return TRUE;
}

GType
qmi_message_wds_get_current_data_bearer_technology_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWdsGetCurrentDataBearerTechnologyOutput"),
                                          (GBoxedCopyFunc) qmi_message_wds_get_current_data_bearer_technology_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wds_get_current_data_bearer_technology_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wds_get_current_data_bearer_technology_output_ref:
 * @self: a #QmiMessageWdsGetCurrentDataBearerTechnologyOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWdsGetCurrentDataBearerTechnologyOutput *
qmi_message_wds_get_current_data_bearer_technology_output_ref (QmiMessageWdsGetCurrentDataBearerTechnologyOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wds_get_current_data_bearer_technology_output_unref:
 * @self: a #QmiMessageWdsGetCurrentDataBearerTechnologyOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wds_get_current_data_bearer_technology_output_unref (QmiMessageWdsGetCurrentDataBearerTechnologyOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWdsGetCurrentDataBearerTechnologyOutput, self);
    }
}

static gboolean
qmi_message_wds_get_current_data_bearer_technology_output_last_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;
    expected_len += 4;
    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Last' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Last' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_data_bearer_technology_output_last_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_LAST,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_data_bearer_technology_output_last_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " network_type = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WDS_NETWORK_TYPE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wds_network_type_get_string ((QmiWdsNetworkType)tmp));
#elif defined  __QMI_WDS_NETWORK_TYPE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wds_network_type_build_string_from_mask ((QmiWdsNetworkType)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWdsNetworkType
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " rat_mask = '");

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
        g_string_append (printable, " so_mask = '");

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
            g_warning ("Left '%u' bytes unread when getting the 'Last' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_wds_get_current_data_bearer_technology_output_current_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;
    expected_len += 4;
    expected_len += 4;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Current' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Current' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_get_current_data_bearer_technology_output_current_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_GET_CURRENT_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_CURRENT,
                                      &buffer_len);
    if (buffer && qmi_message_wds_get_current_data_bearer_technology_output_current_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " network_type = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WDS_NETWORK_TYPE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wds_network_type_get_string ((QmiWdsNetworkType)tmp));
#elif defined  __QMI_WDS_NETWORK_TYPE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wds_network_type_build_string_from_mask ((QmiWdsNetworkType)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWdsNetworkType
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " rat_mask = '");

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
        g_string_append (printable, " so_mask = '");

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
            g_warning ("Left '%u' bytes unread when getting the 'Current' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_get_current_data_bearer_technology_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_get_current_data_bearer_technology_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_get_current_data_bearer_technology_context *ctx)
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
        case QMI_MESSAGE_WDS_GET_CURRENT_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_LAST:
            tlv_type_str = "Last";
            translated_value = qmi_message_wds_get_current_data_bearer_technology_output_last_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_WDS_GET_CURRENT_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_CURRENT:
            tlv_type_str = "Current";
            translated_value = qmi_message_wds_get_current_data_bearer_technology_output_current_get_printable (
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
message_get_current_data_bearer_technology_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Get Current Data Bearer Technology\" (0x0044)\n",
                            line_prefix);

    {
        struct message_get_current_data_bearer_technology_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_get_current_data_bearer_technology_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageWdsGetCurrentDataBearerTechnologyOutput *
__qmi_message_wds_get_current_data_bearer_technology_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWdsGetCurrentDataBearerTechnologyOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WDS_GET_CURRENT_DATA_BEARER_TECHNOLOGY, NULL);

    self = g_slice_new0 (QmiMessageWdsGetCurrentDataBearerTechnologyOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WDS_GET_CURRENT_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_RESULT,
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
                qmi_message_wds_get_current_data_bearer_technology_output_unref (self);
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_LAST,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_data_bearer_technology_output_last_validate (buffer, buffer_len)) {
                self->arg_last_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_last_network_type = (QmiWdsNetworkType)tmp;
                }
                /* Read the guint32 variable from the buffer */
                qmi_utils_read_guint32_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_last_rat_mask));
                /* Read the guint32 variable from the buffer */
                qmi_utils_read_guint32_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_last_so_mask));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Last' TLV", buffer_len);
                }
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
                                              QMI_MESSAGE_WDS_GET_CURRENT_DATA_BEARER_TECHNOLOGY_OUTPUT_TLV_CURRENT,
                                              &buffer_len);
            if (buffer && qmi_message_wds_get_current_data_bearer_technology_output_current_validate (buffer, buffer_len)) {
                self->arg_current_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_current_network_type = (QmiWdsNetworkType)tmp;
                }
                /* Read the guint32 variable from the buffer */
                qmi_utils_read_guint32_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_current_rat_mask));
                /* Read the guint32 variable from the buffer */
                qmi_utils_read_guint32_from_buffer (
                    &buffer,
                    &buffer_len,
                    QMI_ENDIAN_LITTLE,
                    &(self->arg_current_so_mask));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Current' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the Current TLV: Not found");
                qmi_message_wds_get_current_data_bearer_technology_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message WDS Set IP Family */


/* --- Input -- */

struct _QmiMessageWdsSetIpFamilyInput {
    volatile gint ref_count;

    /* Preference */
    gboolean arg_preference_set;
    guint8 arg_preference;
};

#define QMI_MESSAGE_WDS_SET_IP_FAMILY_INPUT_TLV_PREFERENCE 0x01

/**
 * qmi_message_wds_set_ip_family_input_get_preference:
 * @self: a #QmiMessageWdsSetIpFamilyInput.
 * @preference: a placeholder for the output #QmiWdsIpFamily, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Preference' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_wds_set_ip_family_input_get_preference (
    QmiMessageWdsSetIpFamilyInput *self,
    QmiWdsIpFamily *preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_preference_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Preference' was not found in the message");
        return FALSE;
    }

    if (preference)
        *preference = (QmiWdsIpFamily)(self->arg_preference);

    return TRUE;
}

/**
 * qmi_message_wds_set_ip_family_input_set_preference:
 * @self: a #QmiMessageWdsSetIpFamilyInput.
 * @preference: a #QmiWdsIpFamily.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Preference' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_wds_set_ip_family_input_set_preference (
    QmiMessageWdsSetIpFamilyInput *self,
    QmiWdsIpFamily preference,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_preference = (guint8)(preference);
    self->arg_preference_set = TRUE;

    return TRUE;
}

GType
qmi_message_wds_set_ip_family_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWdsSetIpFamilyInput"),
                                          (GBoxedCopyFunc) qmi_message_wds_set_ip_family_input_ref,
                                          (GBoxedFreeFunc) qmi_message_wds_set_ip_family_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wds_set_ip_family_input_ref:
 * @self: a #QmiMessageWdsSetIpFamilyInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWdsSetIpFamilyInput *
qmi_message_wds_set_ip_family_input_ref (QmiMessageWdsSetIpFamilyInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wds_set_ip_family_input_unref:
 * @self: a #QmiMessageWdsSetIpFamilyInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wds_set_ip_family_input_unref (QmiMessageWdsSetIpFamilyInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWdsSetIpFamilyInput, self);
    }
}

/**
 * qmi_message_wds_set_ip_family_input_new:
 *
 * Allocates a new #QmiMessageWdsSetIpFamilyInput.
 *
 * Returns: the newly created #QmiMessageWdsSetIpFamilyInput. The returned value should be freed with qmi_message_wds_set_ip_family_input_unref().
 */
QmiMessageWdsSetIpFamilyInput *
qmi_message_wds_set_ip_family_input_new (void)
{
    QmiMessageWdsSetIpFamilyInput *self;

    self = g_slice_new0 (QmiMessageWdsSetIpFamilyInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_wds_set_ip_family_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessageWdsSetIpFamilyInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_WDS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_WDS_SET_IP_FAMILY);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Set IP Family' has mandatory TLVs");
        qmi_message_unref (self);
        return NULL;
    }

    /* Try to add the 'Preference' TLV */
    if (input->arg_preference_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_preference;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_WDS_SET_IP_FAMILY_INPUT_TLV_PREFERENCE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Preference TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'Preference' in message 'Set IP Family'");
        qmi_message_unref (self);
        return NULL;
    }

    return self;
}

/* --- Output -- */

struct _QmiMessageWdsSetIpFamilyOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;
};

#define QMI_MESSAGE_WDS_SET_IP_FAMILY_OUTPUT_TLV_RESULT 0x02

/**
 * qmi_message_wds_set_ip_family_output_get_result:
 * @self: a QmiMessageWdsSetIpFamilyOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_wds_set_ip_family_output_get_result (
    QmiMessageWdsSetIpFamilyOutput *self,
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
qmi_message_wds_set_ip_family_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageWdsSetIpFamilyOutput"),
                                          (GBoxedCopyFunc) qmi_message_wds_set_ip_family_output_ref,
                                          (GBoxedFreeFunc) qmi_message_wds_set_ip_family_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_wds_set_ip_family_output_ref:
 * @self: a #QmiMessageWdsSetIpFamilyOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessageWdsSetIpFamilyOutput *
qmi_message_wds_set_ip_family_output_ref (QmiMessageWdsSetIpFamilyOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_wds_set_ip_family_output_unref:
 * @self: a #QmiMessageWdsSetIpFamilyOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_wds_set_ip_family_output_unref (QmiMessageWdsSetIpFamilyOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageWdsSetIpFamilyOutput, self);
    }
}

static gboolean
qmi_message_wds_set_ip_family_input_preference_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Preference' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Preference' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_wds_set_ip_family_input_preference_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_WDS_SET_IP_FAMILY_INPUT_TLV_PREFERENCE,
                                      &buffer_len);
    if (buffer && qmi_message_wds_set_ip_family_input_preference_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_WDS_IP_FAMILY_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_wds_ip_family_get_string ((QmiWdsIpFamily)tmp));
#elif defined  __QMI_WDS_IP_FAMILY_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_wds_ip_family_build_string_from_mask ((QmiWdsIpFamily)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiWdsIpFamily
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Preference' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_set_ip_family_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_set_ip_family_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_set_ip_family_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_WDS_SET_IP_FAMILY_INPUT_TLV_PREFERENCE:
            tlv_type_str = "Preference";
            translated_value = qmi_message_wds_set_ip_family_input_preference_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_WDS_SET_IP_FAMILY_OUTPUT_TLV_RESULT:
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
message_set_ip_family_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Set IP Family\" (0x004D)\n",
                            line_prefix);

    {
        struct message_set_ip_family_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_set_ip_family_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageWdsSetIpFamilyOutput *
__qmi_message_wds_set_ip_family_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageWdsSetIpFamilyOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_WDS_SET_IP_FAMILY, NULL);

    self = g_slice_new0 (QmiMessageWdsSetIpFamilyOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_WDS_SET_IP_FAMILY_OUTPUT_TLV_RESULT,
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
                qmi_message_wds_set_ip_family_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* Service-specific printable: WDS */


gchar *
__qmi_message_wds_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    if (qmi_message_is_indication (self)) {
        switch (qmi_message_get_message_id (self)) {
         default:
             return NULL;
        }
    } else {
        switch (qmi_message_get_message_id (self)) {
        case QMI_MESSAGE_WDS_RESET:
            return message_reset_get_printable (self, line_prefix);
        case QMI_MESSAGE_WDS_ABORT:
            return message_abort_get_printable (self, line_prefix);
        case QMI_MESSAGE_WDS_START_NETWORK:
            return message_start_network_get_printable (self, line_prefix);
        case QMI_MESSAGE_WDS_STOP_NETWORK:
            return message_stop_network_get_printable (self, line_prefix);
        case QMI_MESSAGE_WDS_GET_PACKET_SERVICE_STATUS:
            return message_get_packet_service_status_get_printable (self, line_prefix);
        case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS:
            return message_get_current_settings_get_printable (self, line_prefix);
        case QMI_MESSAGE_WDS_GET_DATA_BEARER_TECHNOLOGY:
            return message_get_data_bearer_technology_get_printable (self, line_prefix);
        case QMI_MESSAGE_WDS_GET_CURRENT_DATA_BEARER_TECHNOLOGY:
            return message_get_current_data_bearer_technology_get_printable (self, line_prefix);
        case QMI_MESSAGE_WDS_SET_IP_FAMILY:
            return message_set_ip_family_get_printable (self, line_prefix);
         default:
             return NULL;
        }
    }
}

gboolean
__qmi_message_wds_get_version_introduced (
    QmiMessage *self,
    guint *major,
    guint *minor)
{
    switch (qmi_message_get_message_id (self)) {
    case QMI_MESSAGE_WDS_RESET:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_WDS_ABORT:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_WDS_START_NETWORK:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_WDS_STOP_NETWORK:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_WDS_GET_PACKET_SERVICE_STATUS:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_WDS_GET_CURRENT_SETTINGS:
        *major = 1;
        *minor = 2;
        return TRUE;
    case QMI_MESSAGE_WDS_GET_DATA_BEARER_TECHNOLOGY:
        *major = 1;
        *minor = 12;
        return TRUE;
    case QMI_MESSAGE_WDS_GET_CURRENT_DATA_BEARER_TECHNOLOGY:
        *major = 1;
        *minor = 4;
        return TRUE;
    case QMI_MESSAGE_WDS_SET_IP_FAMILY:
        *major = 1;
        *minor = 9;
        return TRUE;
    default:
        return FALSE;
    }
}

/*****************************************************************************/
/* CLIENT: QMI Client WDS */


/**
 * SECTION: qmi-client-wds
 * @title: QmiClientWds
 * @short_description: #QmiClient for the WDS service.
 *
 * #QmiClient which handles operations in the WDS service.
 */

G_DEFINE_TYPE (QmiClientWds, qmi_client_wds, QMI_TYPE_CLIENT);

static void
process_indication (QmiClient *self,
                    QmiMessage *message)
{
    switch (qmi_message_get_message_id (message)) {
        default:
            break;
    }
}

static void
qmi_client_wds_init (QmiClientWds *self)
{
}

static void
qmi_client_wds_class_init (QmiClientWdsClass *klass)
{
    QmiClientClass *client_class = QMI_CLIENT_CLASS (klass);

    client_class->process_indication = process_indication;
}


/**
 * qmi_client_wds_reset_finish:
 * @self: a #QmiClientWds.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_wds_reset().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_wds_reset().
 *
 * Returns: a #QmiMessageWdsResetOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_wds_reset_output_unref().
 */
QmiMessageWdsResetOutput *
qmi_client_wds_reset_finish (
    QmiClientWds *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_wds_reset_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
reset_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWdsResetOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_wds_reset_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_wds_reset_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_wds_reset:
 * @self: a #QmiClientWds.
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
 * You can then call qmi_client_wds_reset_finish() to get the result of the operation.
 */
void
qmi_client_wds_reset (
    QmiClientWds *self,
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
                                        qmi_client_wds_reset);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_wds_reset_request_create (
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
 * qmi_client_wds_start_network_finish:
 * @self: a #QmiClientWds.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_wds_start_network().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_wds_start_network().
 *
 * Returns: a #QmiMessageWdsStartNetworkOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_wds_start_network_output_unref().
 */
QmiMessageWdsStartNetworkOutput *
qmi_client_wds_start_network_finish (
    QmiClientWds *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_wds_start_network_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
start_network_abort_ready (
    QmiDevice *device,
    GAsyncResult *res)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWdsAbortOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (reply) {
        output = __qmi_message_wds_abort_response_parse (reply, &error);
        if (output)
            qmi_message_wds_abort_output_unref (output);
        qmi_message_unref (reply);
    }

    if (error) {
        g_debug ("Operation to abort 'Start Network' failed: %s", error->message);
        g_error_free (error);
    }
}

static void
start_network_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWdsStartNetworkOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        if (g_error_matches (error, QMI_CORE_ERROR, QMI_CORE_ERROR_TIMEOUT) ||
            g_error_matches (error, QMI_PROTOCOL_ERROR, QMI_PROTOCOL_ERROR_ABORTED)) {
                QmiMessage *abort;
                GObject *self;
                guint16 transaction_id;
                QmiMessageWdsAbortInput *input;

                self = g_async_result_get_source_object (G_ASYNC_RESULT (simple));
                g_assert (self != NULL);

                transaction_id = (guint16) GPOINTER_TO_UINT (g_object_get_data (G_OBJECT (simple),
                                                                                "transaction-id"));
                g_assert (transaction_id != 0);

                input = qmi_message_wds_abort_input_new ();
                qmi_message_wds_abort_input_set_transaction_id (
                    input,
                    transaction_id,
                    NULL);
                abort = __qmi_message_wds_abort_request_create (
                            qmi_client_get_next_transaction_id (QMI_CLIENT (self)),
                            qmi_client_get_cid (QMI_CLIENT (self)),
                            input,
                            NULL);
                g_assert (abort != NULL);
                qmi_device_command (device,
                                    abort,
                                    30,
                                    NULL,
                                    (GAsyncReadyCallback)start_network_abort_ready,
                                    NULL);
                qmi_message_wds_abort_input_unref (input);
                qmi_message_unref (abort);
                g_object_unref (self);
            }

        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_wds_start_network_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_wds_start_network_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_wds_start_network:
 * @self: a #QmiClientWds.
 * @input: a #QmiMessageWdsStartNetworkInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Start Network request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_wds_start_network_finish() to get the result of the operation.
 */
void
qmi_client_wds_start_network (
    QmiClientWds *self,
    QmiMessageWdsStartNetworkInput *input,
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
                                        qmi_client_wds_start_network);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_wds_start_network_request_create (
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

    g_object_set_data (G_OBJECT (result),
                       "transaction-id",
                       GUINT_TO_POINTER (transaction_id));

    qmi_device_command (QMI_DEVICE (qmi_client_peek_device (QMI_CLIENT (self))),
                        request,
                        timeout,
                        cancellable,
                        (GAsyncReadyCallback)start_network_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_wds_stop_network_finish:
 * @self: a #QmiClientWds.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_wds_stop_network().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_wds_stop_network().
 *
 * Returns: a #QmiMessageWdsStopNetworkOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_wds_stop_network_output_unref().
 */
QmiMessageWdsStopNetworkOutput *
qmi_client_wds_stop_network_finish (
    QmiClientWds *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_wds_stop_network_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
stop_network_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWdsStopNetworkOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_wds_stop_network_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_wds_stop_network_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_wds_stop_network:
 * @self: a #QmiClientWds.
 * @input: a #QmiMessageWdsStopNetworkInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Stop Network request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_wds_stop_network_finish() to get the result of the operation.
 */
void
qmi_client_wds_stop_network (
    QmiClientWds *self,
    QmiMessageWdsStopNetworkInput *input,
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
                                        qmi_client_wds_stop_network);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_wds_stop_network_request_create (
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
                        (GAsyncReadyCallback)stop_network_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_wds_get_packet_service_status_finish:
 * @self: a #QmiClientWds.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_wds_get_packet_service_status().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_wds_get_packet_service_status().
 *
 * Returns: a #QmiMessageWdsGetPacketServiceStatusOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_wds_get_packet_service_status_output_unref().
 */
QmiMessageWdsGetPacketServiceStatusOutput *
qmi_client_wds_get_packet_service_status_finish (
    QmiClientWds *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_wds_get_packet_service_status_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
get_packet_service_status_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWdsGetPacketServiceStatusOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_wds_get_packet_service_status_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_wds_get_packet_service_status_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_wds_get_packet_service_status:
 * @self: a #QmiClientWds.
 * @unused: %NULL. This message doesn't have any input bundle.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Get Packet Service Status request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_wds_get_packet_service_status_finish() to get the result of the operation.
 */
void
qmi_client_wds_get_packet_service_status (
    QmiClientWds *self,
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
                                        qmi_client_wds_get_packet_service_status);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_wds_get_packet_service_status_request_create (
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
                        (GAsyncReadyCallback)get_packet_service_status_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_wds_get_current_settings_finish:
 * @self: a #QmiClientWds.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_wds_get_current_settings().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_wds_get_current_settings().
 *
 * Returns: a #QmiMessageWdsGetCurrentSettingsOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_wds_get_current_settings_output_unref().
 */
QmiMessageWdsGetCurrentSettingsOutput *
qmi_client_wds_get_current_settings_finish (
    QmiClientWds *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_wds_get_current_settings_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
get_current_settings_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWdsGetCurrentSettingsOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_wds_get_current_settings_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_wds_get_current_settings_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_wds_get_current_settings:
 * @self: a #QmiClientWds.
 * @input: a #QmiMessageWdsGetCurrentSettingsInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Get Current Settings request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_wds_get_current_settings_finish() to get the result of the operation.
 */
void
qmi_client_wds_get_current_settings (
    QmiClientWds *self,
    QmiMessageWdsGetCurrentSettingsInput *input,
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
                                        qmi_client_wds_get_current_settings);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_wds_get_current_settings_request_create (
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
                        (GAsyncReadyCallback)get_current_settings_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_wds_get_data_bearer_technology_finish:
 * @self: a #QmiClientWds.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_wds_get_data_bearer_technology().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_wds_get_data_bearer_technology().
 *
 * Returns: a #QmiMessageWdsGetDataBearerTechnologyOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_wds_get_data_bearer_technology_output_unref().
 */
QmiMessageWdsGetDataBearerTechnologyOutput *
qmi_client_wds_get_data_bearer_technology_finish (
    QmiClientWds *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_wds_get_data_bearer_technology_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
get_data_bearer_technology_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWdsGetDataBearerTechnologyOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_wds_get_data_bearer_technology_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_wds_get_data_bearer_technology_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_wds_get_data_bearer_technology:
 * @self: a #QmiClientWds.
 * @unused: %NULL. This message doesn't have any input bundle.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Get Data Bearer Technology request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_wds_get_data_bearer_technology_finish() to get the result of the operation.
 */
void
qmi_client_wds_get_data_bearer_technology (
    QmiClientWds *self,
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
                                        qmi_client_wds_get_data_bearer_technology);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_wds_get_data_bearer_technology_request_create (
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
                        (GAsyncReadyCallback)get_data_bearer_technology_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_wds_get_current_data_bearer_technology_finish:
 * @self: a #QmiClientWds.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_wds_get_current_data_bearer_technology().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_wds_get_current_data_bearer_technology().
 *
 * Returns: a #QmiMessageWdsGetCurrentDataBearerTechnologyOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_wds_get_current_data_bearer_technology_output_unref().
 */
QmiMessageWdsGetCurrentDataBearerTechnologyOutput *
qmi_client_wds_get_current_data_bearer_technology_finish (
    QmiClientWds *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_wds_get_current_data_bearer_technology_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
get_current_data_bearer_technology_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWdsGetCurrentDataBearerTechnologyOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_wds_get_current_data_bearer_technology_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_wds_get_current_data_bearer_technology_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_wds_get_current_data_bearer_technology:
 * @self: a #QmiClientWds.
 * @unused: %NULL. This message doesn't have any input bundle.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Get Current Data Bearer Technology request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_wds_get_current_data_bearer_technology_finish() to get the result of the operation.
 */
void
qmi_client_wds_get_current_data_bearer_technology (
    QmiClientWds *self,
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
                                        qmi_client_wds_get_current_data_bearer_technology);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_wds_get_current_data_bearer_technology_request_create (
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
                        (GAsyncReadyCallback)get_current_data_bearer_technology_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_wds_set_ip_family_finish:
 * @self: a #QmiClientWds.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_wds_set_ip_family().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_wds_set_ip_family().
 *
 * Returns: a #QmiMessageWdsSetIpFamilyOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_wds_set_ip_family_output_unref().
 */
QmiMessageWdsSetIpFamilyOutput *
qmi_client_wds_set_ip_family_finish (
    QmiClientWds *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_wds_set_ip_family_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
set_ip_family_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageWdsSetIpFamilyOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_wds_set_ip_family_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_wds_set_ip_family_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_wds_set_ip_family:
 * @self: a #QmiClientWds.
 * @input: a #QmiMessageWdsSetIpFamilyInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Set IP Family request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_wds_set_ip_family_finish() to get the result of the operation.
 */
void
qmi_client_wds_set_ip_family (
    QmiClientWds *self,
    QmiMessageWdsSetIpFamilyInput *input,
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
                                        qmi_client_wds_set_ip_family);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_wds_set_ip_family_request_create (
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
                        (GAsyncReadyCallback)set_ip_family_ready,
                        result);
    qmi_message_unref (request);
}

