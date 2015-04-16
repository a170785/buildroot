
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

#include "qmi-pds.h"
#include "qmi-enum-types.h"
#include "qmi-enum-types-private.h"
#include "qmi-flags64-types.h"
#include "qmi-error-types.h"
#include "qmi-device.h"
#include "qmi-utils.h"

#define QMI_STATUS_SUCCESS 0x0000
#define QMI_STATUS_FAILURE 0x0001


typedef enum {
    QMI_MESSAGE_PDS_RESET = 0x0000,
    QMI_MESSAGE_PDS_SET_EVENT_REPORT = 0x0001,
    QMI_MESSAGE_PDS_GET_GPS_SERVICE_STATE = 0x0020,
    QMI_MESSAGE_PDS_SET_GPS_SERVICE_STATE = 0x0021,
    QMI_MESSAGE_PDS_GET_AUTO_TRACKING_STATE = 0x0030,
    QMI_MESSAGE_PDS_SET_AUTO_TRACKING_STATE = 0x0031,
} QmiMessagePds;


typedef enum {
    QMI_INDICATION_PDS_EVENT_REPORT = 0x0001,
} QmiIndicationPds;


/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message PDS Reset */


/* --- Input -- */

/* Note: no fields in the Input container */

static QmiMessage *
__qmi_message_pds_reset_request_create (
    guint8 transaction_id,
    guint8 cid,
    gpointer unused,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_PDS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_PDS_RESET);

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

struct _QmiMessagePdsResetOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;
};

#define QMI_MESSAGE_PDS_RESET_OUTPUT_TLV_RESULT 0x02

/**
 * qmi_message_pds_reset_output_get_result:
 * @self: a QmiMessagePdsResetOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_pds_reset_output_get_result (
    QmiMessagePdsResetOutput *self,
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
qmi_message_pds_reset_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessagePdsResetOutput"),
                                          (GBoxedCopyFunc) qmi_message_pds_reset_output_ref,
                                          (GBoxedFreeFunc) qmi_message_pds_reset_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_pds_reset_output_ref:
 * @self: a #QmiMessagePdsResetOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessagePdsResetOutput *
qmi_message_pds_reset_output_ref (QmiMessagePdsResetOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_pds_reset_output_unref:
 * @self: a #QmiMessagePdsResetOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_pds_reset_output_unref (QmiMessagePdsResetOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessagePdsResetOutput, self);
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
                                      QMI_MESSAGE_PDS_RESET_OUTPUT_TLV_RESULT,
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
        case QMI_MESSAGE_PDS_RESET_OUTPUT_TLV_RESULT:
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

static QmiMessagePdsResetOutput *
__qmi_message_pds_reset_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessagePdsResetOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_PDS_RESET, NULL);

    self = g_slice_new0 (QmiMessagePdsResetOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_PDS_RESET_OUTPUT_TLV_RESULT,
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
                qmi_message_pds_reset_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message PDS Set Event Report */


/* --- Input -- */

struct _QmiMessagePdsSetEventReportInput {
    volatile gint ref_count;

    /* Extended External XTRA Data Request Reporting */
    gboolean arg_extended_external_xtra_data_request_reporting_set;
    guint8 arg_extended_external_xtra_data_request_reporting;

    /* NMEA Debug Strings Reporting */
    gboolean arg_nmea_debug_strings_reporting_set;
    guint8 arg_nmea_debug_strings_reporting;

    /* Heading Uncertainty Reporting */
    gboolean arg_heading_uncertainty_reporting_set;
    guint8 arg_heading_uncertainty_reporting;

    /* Time Source Information Reporting */
    gboolean arg_time_source_information_reporting_set;
    guint8 arg_time_source_information_reporting;

    /* Sensor Data Usage Indicator Reporting */
    gboolean arg_sensor_data_usage_indicator_reporting_set;
    guint8 arg_sensor_data_usage_indicator_reporting;

    /* Position Reliability Indicator Reporting */
    gboolean arg_position_reliability_indicator_reporting_set;
    guint8 arg_position_reliability_indicator_reporting;

    /* Time Sync Request Reporting */
    gboolean arg_time_sync_request_reporting_set;
    guint8 arg_time_sync_request_reporting;

    /* Gyro Data Streaming Ready Reporting */
    gboolean arg_gyro_data_streaming_ready_reporting_set;
    guint8 arg_gyro_data_streaming_ready_reporting;

    /* Accelerometer Data Streaming Ready Reporting */
    gboolean arg_accelerometer_data_streaming_ready_reporting_set;
    guint8 arg_accelerometer_data_streaming_ready_reporting;

    /* PDS Comm Event Reporting */
    gboolean arg_pds_comm_event_reporting_set;
    guint8 arg_pds_comm_event_reporting;

    /* UMTS CP Network Initiated Prompt Reporting */
    gboolean arg_umts_cp_network_initiated_prompt_reporting_set;
    guint8 arg_umts_cp_network_initiated_prompt_reporting;

    /* SUPL Network Initiated Prompt Reporting */
    gboolean arg_supl_network_initiated_prompt_reporting_set;
    guint8 arg_supl_network_initiated_prompt_reporting;

    /* VX Network Initiated Request Reporting */
    gboolean arg_vx_network_initiated_request_reporting_set;
    guint8 arg_vx_network_initiated_request_reporting;

    /* Satellite Information Reporting */
    gboolean arg_satellite_information_reporting_set;
    guint8 arg_satellite_information_reporting;

    /* External WIFI Position Request Reporting */
    gboolean arg_external_wifi_position_request_reporting_set;
    guint8 arg_external_wifi_position_request_reporting;

    /* External Time Injection Request Reporting */
    gboolean arg_external_time_injection_request_reporting_set;
    guint8 arg_external_time_injection_request_reporting;

    /* External XTRA Data Request Reporting */
    gboolean arg_external_xtra_data_request_reporting_set;
    guint8 arg_external_xtra_data_request_reporting;

    /* Parsed Position Reporting */
    gboolean arg_parsed_position_reporting_set;
    guint8 arg_parsed_position_reporting;

    /* Extended NMEA Position Reporting */
    gboolean arg_extended_nmea_position_reporting_set;
    guint8 arg_extended_nmea_position_reporting;

    /* NMEA Position Reporting */
    gboolean arg_nmea_position_reporting_set;
    guint8 arg_nmea_position_reporting;
};

#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_EXTENDED_EXTERNAL_XTRA_DATA_REQUEST_REPORTING 0x23
#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_NMEA_DEBUG_STRINGS_REPORTING 0x22
#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_HEADING_UNCERTAINTY_REPORTING 0x21
#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_TIME_SOURCE_INFORMATION_REPORTING 0x20
#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_SENSOR_DATA_USAGE_INDICATOR_REPORTING 0x1F
#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_POSITION_RELIABILITY_INDICATOR_REPORTING 0x1E
#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_TIME_SYNC_REQUEST_REPORTING 0x1D
#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_GYRO_DATA_STREAMING_READY_REPORTING 0x1C
#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_ACCELEROMETER_DATA_STREAMING_READY_REPORTING 0x1B
#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_PDS_COMM_EVENT_REPORTING 0x1A
#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_UMTS_CP_NETWORK_INITIATED_PROMPT_REPORTING 0x19
#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_SUPL_NETWORK_INITIATED_PROMPT_REPORTING 0x18
#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_VX_NETWORK_INITIATED_REQUEST_REPORTING 0x17
#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_SATELLITE_INFORMATION_REPORTING 0x16
#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_EXTERNAL_WIFI_POSITION_REQUEST_REPORTING 0x15
#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_EXTERNAL_TIME_INJECTION_REQUEST_REPORTING 0x14
#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_EXTERNAL_XTRA_DATA_REQUEST_REPORTING 0x13
#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_PARSED_POSITION_REPORTING 0x12
#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_EXTENDED_NMEA_POSITION_REPORTING 0x11
#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_NMEA_POSITION_REPORTING 0x10

/**
 * qmi_message_pds_set_event_report_input_get_extended_external_xtra_data_request_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @extended_external_xtra_data_request_reporting: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Extended External XTRA Data Request Reporting' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_get_extended_external_xtra_data_request_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean *extended_external_xtra_data_request_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_extended_external_xtra_data_request_reporting_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Extended External XTRA Data Request Reporting' was not found in the message");
        return FALSE;
    }

    if (extended_external_xtra_data_request_reporting)
        *extended_external_xtra_data_request_reporting = (gboolean)(self->arg_extended_external_xtra_data_request_reporting);

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_set_extended_external_xtra_data_request_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @extended_external_xtra_data_request_reporting: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Extended External XTRA Data Request Reporting' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_set_extended_external_xtra_data_request_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean extended_external_xtra_data_request_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_extended_external_xtra_data_request_reporting = (guint8)(extended_external_xtra_data_request_reporting);
    self->arg_extended_external_xtra_data_request_reporting_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_get_nmea_debug_strings_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @nmea_debug_strings_reporting: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'NMEA Debug Strings Reporting' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_get_nmea_debug_strings_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean *nmea_debug_strings_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_nmea_debug_strings_reporting_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'NMEA Debug Strings Reporting' was not found in the message");
        return FALSE;
    }

    if (nmea_debug_strings_reporting)
        *nmea_debug_strings_reporting = (gboolean)(self->arg_nmea_debug_strings_reporting);

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_set_nmea_debug_strings_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @nmea_debug_strings_reporting: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'NMEA Debug Strings Reporting' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_set_nmea_debug_strings_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean nmea_debug_strings_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_nmea_debug_strings_reporting = (guint8)(nmea_debug_strings_reporting);
    self->arg_nmea_debug_strings_reporting_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_get_heading_uncertainty_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @heading_uncertainty_reporting: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Heading Uncertainty Reporting' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_get_heading_uncertainty_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean *heading_uncertainty_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_heading_uncertainty_reporting_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Heading Uncertainty Reporting' was not found in the message");
        return FALSE;
    }

    if (heading_uncertainty_reporting)
        *heading_uncertainty_reporting = (gboolean)(self->arg_heading_uncertainty_reporting);

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_set_heading_uncertainty_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @heading_uncertainty_reporting: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Heading Uncertainty Reporting' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_set_heading_uncertainty_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean heading_uncertainty_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_heading_uncertainty_reporting = (guint8)(heading_uncertainty_reporting);
    self->arg_heading_uncertainty_reporting_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_get_time_source_information_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @time_source_information_reporting: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Time Source Information Reporting' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_get_time_source_information_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean *time_source_information_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_time_source_information_reporting_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Time Source Information Reporting' was not found in the message");
        return FALSE;
    }

    if (time_source_information_reporting)
        *time_source_information_reporting = (gboolean)(self->arg_time_source_information_reporting);

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_set_time_source_information_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @time_source_information_reporting: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Time Source Information Reporting' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_set_time_source_information_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean time_source_information_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_time_source_information_reporting = (guint8)(time_source_information_reporting);
    self->arg_time_source_information_reporting_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_get_sensor_data_usage_indicator_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @sensor_data_usage_indicator_reporting: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Sensor Data Usage Indicator Reporting' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_get_sensor_data_usage_indicator_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean *sensor_data_usage_indicator_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_sensor_data_usage_indicator_reporting_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Sensor Data Usage Indicator Reporting' was not found in the message");
        return FALSE;
    }

    if (sensor_data_usage_indicator_reporting)
        *sensor_data_usage_indicator_reporting = (gboolean)(self->arg_sensor_data_usage_indicator_reporting);

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_set_sensor_data_usage_indicator_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @sensor_data_usage_indicator_reporting: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Sensor Data Usage Indicator Reporting' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_set_sensor_data_usage_indicator_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean sensor_data_usage_indicator_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_sensor_data_usage_indicator_reporting = (guint8)(sensor_data_usage_indicator_reporting);
    self->arg_sensor_data_usage_indicator_reporting_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_get_position_reliability_indicator_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @position_reliability_indicator_reporting: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Position Reliability Indicator Reporting' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_get_position_reliability_indicator_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean *position_reliability_indicator_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_position_reliability_indicator_reporting_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Position Reliability Indicator Reporting' was not found in the message");
        return FALSE;
    }

    if (position_reliability_indicator_reporting)
        *position_reliability_indicator_reporting = (gboolean)(self->arg_position_reliability_indicator_reporting);

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_set_position_reliability_indicator_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @position_reliability_indicator_reporting: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Position Reliability Indicator Reporting' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_set_position_reliability_indicator_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean position_reliability_indicator_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_position_reliability_indicator_reporting = (guint8)(position_reliability_indicator_reporting);
    self->arg_position_reliability_indicator_reporting_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_get_time_sync_request_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @time_sync_request_reporting: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Time Sync Request Reporting' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_get_time_sync_request_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean *time_sync_request_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_time_sync_request_reporting_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Time Sync Request Reporting' was not found in the message");
        return FALSE;
    }

    if (time_sync_request_reporting)
        *time_sync_request_reporting = (gboolean)(self->arg_time_sync_request_reporting);

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_set_time_sync_request_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @time_sync_request_reporting: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Time Sync Request Reporting' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_set_time_sync_request_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean time_sync_request_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_time_sync_request_reporting = (guint8)(time_sync_request_reporting);
    self->arg_time_sync_request_reporting_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_get_gyro_data_streaming_ready_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @gyro_data_streaming_ready_reporting: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Gyro Data Streaming Ready Reporting' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_get_gyro_data_streaming_ready_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean *gyro_data_streaming_ready_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_gyro_data_streaming_ready_reporting_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Gyro Data Streaming Ready Reporting' was not found in the message");
        return FALSE;
    }

    if (gyro_data_streaming_ready_reporting)
        *gyro_data_streaming_ready_reporting = (gboolean)(self->arg_gyro_data_streaming_ready_reporting);

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_set_gyro_data_streaming_ready_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @gyro_data_streaming_ready_reporting: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Gyro Data Streaming Ready Reporting' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_set_gyro_data_streaming_ready_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean gyro_data_streaming_ready_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_gyro_data_streaming_ready_reporting = (guint8)(gyro_data_streaming_ready_reporting);
    self->arg_gyro_data_streaming_ready_reporting_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_get_accelerometer_data_streaming_ready_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @accelerometer_data_streaming_ready_reporting: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Accelerometer Data Streaming Ready Reporting' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_get_accelerometer_data_streaming_ready_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean *accelerometer_data_streaming_ready_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_accelerometer_data_streaming_ready_reporting_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Accelerometer Data Streaming Ready Reporting' was not found in the message");
        return FALSE;
    }

    if (accelerometer_data_streaming_ready_reporting)
        *accelerometer_data_streaming_ready_reporting = (gboolean)(self->arg_accelerometer_data_streaming_ready_reporting);

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_set_accelerometer_data_streaming_ready_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @accelerometer_data_streaming_ready_reporting: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Accelerometer Data Streaming Ready Reporting' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_set_accelerometer_data_streaming_ready_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean accelerometer_data_streaming_ready_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_accelerometer_data_streaming_ready_reporting = (guint8)(accelerometer_data_streaming_ready_reporting);
    self->arg_accelerometer_data_streaming_ready_reporting_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_get_pds_comm_event_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @pds_comm_event_reporting: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'PDS Comm Event Reporting' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_get_pds_comm_event_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean *pds_comm_event_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_pds_comm_event_reporting_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'PDS Comm Event Reporting' was not found in the message");
        return FALSE;
    }

    if (pds_comm_event_reporting)
        *pds_comm_event_reporting = (gboolean)(self->arg_pds_comm_event_reporting);

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_set_pds_comm_event_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @pds_comm_event_reporting: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'PDS Comm Event Reporting' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_set_pds_comm_event_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean pds_comm_event_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_pds_comm_event_reporting = (guint8)(pds_comm_event_reporting);
    self->arg_pds_comm_event_reporting_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_get_umts_cp_network_initiated_prompt_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @umts_cp_network_initiated_prompt_reporting: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'UMTS CP Network Initiated Prompt Reporting' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_get_umts_cp_network_initiated_prompt_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean *umts_cp_network_initiated_prompt_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_umts_cp_network_initiated_prompt_reporting_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'UMTS CP Network Initiated Prompt Reporting' was not found in the message");
        return FALSE;
    }

    if (umts_cp_network_initiated_prompt_reporting)
        *umts_cp_network_initiated_prompt_reporting = (gboolean)(self->arg_umts_cp_network_initiated_prompt_reporting);

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_set_umts_cp_network_initiated_prompt_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @umts_cp_network_initiated_prompt_reporting: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'UMTS CP Network Initiated Prompt Reporting' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_set_umts_cp_network_initiated_prompt_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean umts_cp_network_initiated_prompt_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_umts_cp_network_initiated_prompt_reporting = (guint8)(umts_cp_network_initiated_prompt_reporting);
    self->arg_umts_cp_network_initiated_prompt_reporting_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_get_supl_network_initiated_prompt_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @supl_network_initiated_prompt_reporting: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'SUPL Network Initiated Prompt Reporting' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_get_supl_network_initiated_prompt_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean *supl_network_initiated_prompt_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_supl_network_initiated_prompt_reporting_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'SUPL Network Initiated Prompt Reporting' was not found in the message");
        return FALSE;
    }

    if (supl_network_initiated_prompt_reporting)
        *supl_network_initiated_prompt_reporting = (gboolean)(self->arg_supl_network_initiated_prompt_reporting);

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_set_supl_network_initiated_prompt_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @supl_network_initiated_prompt_reporting: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'SUPL Network Initiated Prompt Reporting' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_set_supl_network_initiated_prompt_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean supl_network_initiated_prompt_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_supl_network_initiated_prompt_reporting = (guint8)(supl_network_initiated_prompt_reporting);
    self->arg_supl_network_initiated_prompt_reporting_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_get_vx_network_initiated_request_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @vx_network_initiated_request_reporting: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'VX Network Initiated Request Reporting' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_get_vx_network_initiated_request_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean *vx_network_initiated_request_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_vx_network_initiated_request_reporting_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'VX Network Initiated Request Reporting' was not found in the message");
        return FALSE;
    }

    if (vx_network_initiated_request_reporting)
        *vx_network_initiated_request_reporting = (gboolean)(self->arg_vx_network_initiated_request_reporting);

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_set_vx_network_initiated_request_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @vx_network_initiated_request_reporting: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'VX Network Initiated Request Reporting' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_set_vx_network_initiated_request_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean vx_network_initiated_request_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_vx_network_initiated_request_reporting = (guint8)(vx_network_initiated_request_reporting);
    self->arg_vx_network_initiated_request_reporting_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_get_satellite_information_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @satellite_information_reporting: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Satellite Information Reporting' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_get_satellite_information_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean *satellite_information_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_satellite_information_reporting_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Satellite Information Reporting' was not found in the message");
        return FALSE;
    }

    if (satellite_information_reporting)
        *satellite_information_reporting = (gboolean)(self->arg_satellite_information_reporting);

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_set_satellite_information_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @satellite_information_reporting: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Satellite Information Reporting' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_set_satellite_information_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean satellite_information_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_satellite_information_reporting = (guint8)(satellite_information_reporting);
    self->arg_satellite_information_reporting_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_get_external_wifi_position_request_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @external_wifi_position_request_reporting: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'External WIFI Position Request Reporting' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_get_external_wifi_position_request_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean *external_wifi_position_request_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_external_wifi_position_request_reporting_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'External WIFI Position Request Reporting' was not found in the message");
        return FALSE;
    }

    if (external_wifi_position_request_reporting)
        *external_wifi_position_request_reporting = (gboolean)(self->arg_external_wifi_position_request_reporting);

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_set_external_wifi_position_request_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @external_wifi_position_request_reporting: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'External WIFI Position Request Reporting' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_set_external_wifi_position_request_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean external_wifi_position_request_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_external_wifi_position_request_reporting = (guint8)(external_wifi_position_request_reporting);
    self->arg_external_wifi_position_request_reporting_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_get_external_time_injection_request_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @external_time_injection_request_reporting: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'External Time Injection Request Reporting' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_get_external_time_injection_request_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean *external_time_injection_request_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_external_time_injection_request_reporting_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'External Time Injection Request Reporting' was not found in the message");
        return FALSE;
    }

    if (external_time_injection_request_reporting)
        *external_time_injection_request_reporting = (gboolean)(self->arg_external_time_injection_request_reporting);

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_set_external_time_injection_request_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @external_time_injection_request_reporting: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'External Time Injection Request Reporting' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_set_external_time_injection_request_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean external_time_injection_request_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_external_time_injection_request_reporting = (guint8)(external_time_injection_request_reporting);
    self->arg_external_time_injection_request_reporting_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_get_external_xtra_data_request_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @external_xtra_data_request_reporting: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'External XTRA Data Request Reporting' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_get_external_xtra_data_request_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean *external_xtra_data_request_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_external_xtra_data_request_reporting_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'External XTRA Data Request Reporting' was not found in the message");
        return FALSE;
    }

    if (external_xtra_data_request_reporting)
        *external_xtra_data_request_reporting = (gboolean)(self->arg_external_xtra_data_request_reporting);

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_set_external_xtra_data_request_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @external_xtra_data_request_reporting: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'External XTRA Data Request Reporting' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_set_external_xtra_data_request_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean external_xtra_data_request_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_external_xtra_data_request_reporting = (guint8)(external_xtra_data_request_reporting);
    self->arg_external_xtra_data_request_reporting_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_get_parsed_position_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @parsed_position_reporting: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Parsed Position Reporting' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_get_parsed_position_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean *parsed_position_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_parsed_position_reporting_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Parsed Position Reporting' was not found in the message");
        return FALSE;
    }

    if (parsed_position_reporting)
        *parsed_position_reporting = (gboolean)(self->arg_parsed_position_reporting);

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_set_parsed_position_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @parsed_position_reporting: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Parsed Position Reporting' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_set_parsed_position_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean parsed_position_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_parsed_position_reporting = (guint8)(parsed_position_reporting);
    self->arg_parsed_position_reporting_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_get_extended_nmea_position_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @extended_nmea_position_reporting: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Extended NMEA Position Reporting' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_get_extended_nmea_position_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean *extended_nmea_position_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_extended_nmea_position_reporting_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Extended NMEA Position Reporting' was not found in the message");
        return FALSE;
    }

    if (extended_nmea_position_reporting)
        *extended_nmea_position_reporting = (gboolean)(self->arg_extended_nmea_position_reporting);

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_set_extended_nmea_position_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @extended_nmea_position_reporting: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Extended NMEA Position Reporting' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_set_extended_nmea_position_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean extended_nmea_position_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_extended_nmea_position_reporting = (guint8)(extended_nmea_position_reporting);
    self->arg_extended_nmea_position_reporting_set = TRUE;

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_get_nmea_position_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @nmea_position_reporting: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'NMEA Position Reporting' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_get_nmea_position_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean *nmea_position_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_nmea_position_reporting_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'NMEA Position Reporting' was not found in the message");
        return FALSE;
    }

    if (nmea_position_reporting)
        *nmea_position_reporting = (gboolean)(self->arg_nmea_position_reporting);

    return TRUE;
}

/**
 * qmi_message_pds_set_event_report_input_set_nmea_position_reporting:
 * @self: a #QmiMessagePdsSetEventReportInput.
 * @nmea_position_reporting: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'NMEA Position Reporting' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_event_report_input_set_nmea_position_reporting (
    QmiMessagePdsSetEventReportInput *self,
    gboolean nmea_position_reporting,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_nmea_position_reporting = (guint8)(nmea_position_reporting);
    self->arg_nmea_position_reporting_set = TRUE;

    return TRUE;
}

GType
qmi_message_pds_set_event_report_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessagePdsSetEventReportInput"),
                                          (GBoxedCopyFunc) qmi_message_pds_set_event_report_input_ref,
                                          (GBoxedFreeFunc) qmi_message_pds_set_event_report_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_pds_set_event_report_input_ref:
 * @self: a #QmiMessagePdsSetEventReportInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessagePdsSetEventReportInput *
qmi_message_pds_set_event_report_input_ref (QmiMessagePdsSetEventReportInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_pds_set_event_report_input_unref:
 * @self: a #QmiMessagePdsSetEventReportInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_pds_set_event_report_input_unref (QmiMessagePdsSetEventReportInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessagePdsSetEventReportInput, self);
    }
}

/**
 * qmi_message_pds_set_event_report_input_new:
 *
 * Allocates a new #QmiMessagePdsSetEventReportInput.
 *
 * Returns: the newly created #QmiMessagePdsSetEventReportInput. The returned value should be freed with qmi_message_pds_set_event_report_input_unref().
 */
QmiMessagePdsSetEventReportInput *
qmi_message_pds_set_event_report_input_new (void)
{
    QmiMessagePdsSetEventReportInput *self;

    self = g_slice_new0 (QmiMessagePdsSetEventReportInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_pds_set_event_report_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessagePdsSetEventReportInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_PDS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_PDS_SET_EVENT_REPORT);

    /* All TLVs are optional, we allow NULL input */
    if (!input)
        return self;

    /* Try to add the 'Extended External XTRA Data Request Reporting' TLV */
    if (input->arg_extended_external_xtra_data_request_reporting_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_extended_external_xtra_data_request_reporting;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_EXTENDED_EXTERNAL_XTRA_DATA_REQUEST_REPORTING,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Extended External XTRA Data Request Reporting TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'NMEA Debug Strings Reporting' TLV */
    if (input->arg_nmea_debug_strings_reporting_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_nmea_debug_strings_reporting;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_NMEA_DEBUG_STRINGS_REPORTING,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the NMEA Debug Strings Reporting TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Heading Uncertainty Reporting' TLV */
    if (input->arg_heading_uncertainty_reporting_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_heading_uncertainty_reporting;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_HEADING_UNCERTAINTY_REPORTING,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Heading Uncertainty Reporting TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Time Source Information Reporting' TLV */
    if (input->arg_time_source_information_reporting_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_time_source_information_reporting;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_TIME_SOURCE_INFORMATION_REPORTING,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Time Source Information Reporting TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Sensor Data Usage Indicator Reporting' TLV */
    if (input->arg_sensor_data_usage_indicator_reporting_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_sensor_data_usage_indicator_reporting;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_SENSOR_DATA_USAGE_INDICATOR_REPORTING,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Sensor Data Usage Indicator Reporting TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Position Reliability Indicator Reporting' TLV */
    if (input->arg_position_reliability_indicator_reporting_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_position_reliability_indicator_reporting;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_POSITION_RELIABILITY_INDICATOR_REPORTING,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Position Reliability Indicator Reporting TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Time Sync Request Reporting' TLV */
    if (input->arg_time_sync_request_reporting_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_time_sync_request_reporting;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_TIME_SYNC_REQUEST_REPORTING,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Time Sync Request Reporting TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Gyro Data Streaming Ready Reporting' TLV */
    if (input->arg_gyro_data_streaming_ready_reporting_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_gyro_data_streaming_ready_reporting;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_GYRO_DATA_STREAMING_READY_REPORTING,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Gyro Data Streaming Ready Reporting TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Accelerometer Data Streaming Ready Reporting' TLV */
    if (input->arg_accelerometer_data_streaming_ready_reporting_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_accelerometer_data_streaming_ready_reporting;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_ACCELEROMETER_DATA_STREAMING_READY_REPORTING,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Accelerometer Data Streaming Ready Reporting TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'PDS Comm Event Reporting' TLV */
    if (input->arg_pds_comm_event_reporting_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_pds_comm_event_reporting;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_PDS_COMM_EVENT_REPORTING,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the PDS Comm Event Reporting TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'UMTS CP Network Initiated Prompt Reporting' TLV */
    if (input->arg_umts_cp_network_initiated_prompt_reporting_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_umts_cp_network_initiated_prompt_reporting;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_UMTS_CP_NETWORK_INITIATED_PROMPT_REPORTING,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the UMTS CP Network Initiated Prompt Reporting TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'SUPL Network Initiated Prompt Reporting' TLV */
    if (input->arg_supl_network_initiated_prompt_reporting_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_supl_network_initiated_prompt_reporting;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_SUPL_NETWORK_INITIATED_PROMPT_REPORTING,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the SUPL Network Initiated Prompt Reporting TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'VX Network Initiated Request Reporting' TLV */
    if (input->arg_vx_network_initiated_request_reporting_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_vx_network_initiated_request_reporting;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_VX_NETWORK_INITIATED_REQUEST_REPORTING,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the VX Network Initiated Request Reporting TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Satellite Information Reporting' TLV */
    if (input->arg_satellite_information_reporting_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_satellite_information_reporting;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_SATELLITE_INFORMATION_REPORTING,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Satellite Information Reporting TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'External WIFI Position Request Reporting' TLV */
    if (input->arg_external_wifi_position_request_reporting_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_external_wifi_position_request_reporting;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_EXTERNAL_WIFI_POSITION_REQUEST_REPORTING,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the External WIFI Position Request Reporting TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'External Time Injection Request Reporting' TLV */
    if (input->arg_external_time_injection_request_reporting_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_external_time_injection_request_reporting;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_EXTERNAL_TIME_INJECTION_REQUEST_REPORTING,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the External Time Injection Request Reporting TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'External XTRA Data Request Reporting' TLV */
    if (input->arg_external_xtra_data_request_reporting_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_external_xtra_data_request_reporting;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_EXTERNAL_XTRA_DATA_REQUEST_REPORTING,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the External XTRA Data Request Reporting TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Parsed Position Reporting' TLV */
    if (input->arg_parsed_position_reporting_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_parsed_position_reporting;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_PARSED_POSITION_REPORTING,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Parsed Position Reporting TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'Extended NMEA Position Reporting' TLV */
    if (input->arg_extended_nmea_position_reporting_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_extended_nmea_position_reporting;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_EXTENDED_NMEA_POSITION_REPORTING,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the Extended NMEA Position Reporting TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    /* Try to add the 'NMEA Position Reporting' TLV */
    if (input->arg_nmea_position_reporting_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_nmea_position_reporting;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_NMEA_POSITION_REPORTING,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the NMEA Position Reporting TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    }

    return self;
}

/* --- Output -- */

struct _QmiMessagePdsSetEventReportOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;
};

#define QMI_MESSAGE_PDS_SET_EVENT_REPORT_OUTPUT_TLV_RESULT 0x02

/**
 * qmi_message_pds_set_event_report_output_get_result:
 * @self: a QmiMessagePdsSetEventReportOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_pds_set_event_report_output_get_result (
    QmiMessagePdsSetEventReportOutput *self,
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
qmi_message_pds_set_event_report_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessagePdsSetEventReportOutput"),
                                          (GBoxedCopyFunc) qmi_message_pds_set_event_report_output_ref,
                                          (GBoxedFreeFunc) qmi_message_pds_set_event_report_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_pds_set_event_report_output_ref:
 * @self: a #QmiMessagePdsSetEventReportOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessagePdsSetEventReportOutput *
qmi_message_pds_set_event_report_output_ref (QmiMessagePdsSetEventReportOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_pds_set_event_report_output_unref:
 * @self: a #QmiMessagePdsSetEventReportOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_pds_set_event_report_output_unref (QmiMessagePdsSetEventReportOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessagePdsSetEventReportOutput, self);
    }
}

static gboolean
qmi_message_pds_set_event_report_input_extended_external_xtra_data_request_reporting_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Extended External XTRA Data Request Reporting' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Extended External XTRA Data Request Reporting' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_event_report_input_extended_external_xtra_data_request_reporting_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_EXTENDED_EXTERNAL_XTRA_DATA_REQUEST_REPORTING,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_event_report_input_extended_external_xtra_data_request_reporting_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Extended External XTRA Data Request Reporting' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_pds_set_event_report_input_nmea_debug_strings_reporting_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'NMEA Debug Strings Reporting' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'NMEA Debug Strings Reporting' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_event_report_input_nmea_debug_strings_reporting_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_NMEA_DEBUG_STRINGS_REPORTING,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_event_report_input_nmea_debug_strings_reporting_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'NMEA Debug Strings Reporting' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_pds_set_event_report_input_heading_uncertainty_reporting_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Heading Uncertainty Reporting' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Heading Uncertainty Reporting' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_event_report_input_heading_uncertainty_reporting_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_HEADING_UNCERTAINTY_REPORTING,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_event_report_input_heading_uncertainty_reporting_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Heading Uncertainty Reporting' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_pds_set_event_report_input_time_source_information_reporting_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Time Source Information Reporting' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Time Source Information Reporting' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_event_report_input_time_source_information_reporting_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_TIME_SOURCE_INFORMATION_REPORTING,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_event_report_input_time_source_information_reporting_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Time Source Information Reporting' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_pds_set_event_report_input_sensor_data_usage_indicator_reporting_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Sensor Data Usage Indicator Reporting' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Sensor Data Usage Indicator Reporting' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_event_report_input_sensor_data_usage_indicator_reporting_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_SENSOR_DATA_USAGE_INDICATOR_REPORTING,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_event_report_input_sensor_data_usage_indicator_reporting_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Sensor Data Usage Indicator Reporting' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_pds_set_event_report_input_position_reliability_indicator_reporting_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Position Reliability Indicator Reporting' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Position Reliability Indicator Reporting' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_event_report_input_position_reliability_indicator_reporting_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_POSITION_RELIABILITY_INDICATOR_REPORTING,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_event_report_input_position_reliability_indicator_reporting_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Position Reliability Indicator Reporting' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_pds_set_event_report_input_time_sync_request_reporting_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Time Sync Request Reporting' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Time Sync Request Reporting' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_event_report_input_time_sync_request_reporting_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_TIME_SYNC_REQUEST_REPORTING,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_event_report_input_time_sync_request_reporting_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Time Sync Request Reporting' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_pds_set_event_report_input_gyro_data_streaming_ready_reporting_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Gyro Data Streaming Ready Reporting' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Gyro Data Streaming Ready Reporting' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_event_report_input_gyro_data_streaming_ready_reporting_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_GYRO_DATA_STREAMING_READY_REPORTING,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_event_report_input_gyro_data_streaming_ready_reporting_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Gyro Data Streaming Ready Reporting' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_pds_set_event_report_input_accelerometer_data_streaming_ready_reporting_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Accelerometer Data Streaming Ready Reporting' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Accelerometer Data Streaming Ready Reporting' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_event_report_input_accelerometer_data_streaming_ready_reporting_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_ACCELEROMETER_DATA_STREAMING_READY_REPORTING,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_event_report_input_accelerometer_data_streaming_ready_reporting_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Accelerometer Data Streaming Ready Reporting' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_pds_set_event_report_input_pds_comm_event_reporting_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'PDS Comm Event Reporting' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'PDS Comm Event Reporting' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_event_report_input_pds_comm_event_reporting_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_PDS_COMM_EVENT_REPORTING,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_event_report_input_pds_comm_event_reporting_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'PDS Comm Event Reporting' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_pds_set_event_report_input_umts_cp_network_initiated_prompt_reporting_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'UMTS CP Network Initiated Prompt Reporting' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'UMTS CP Network Initiated Prompt Reporting' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_event_report_input_umts_cp_network_initiated_prompt_reporting_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_UMTS_CP_NETWORK_INITIATED_PROMPT_REPORTING,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_event_report_input_umts_cp_network_initiated_prompt_reporting_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'UMTS CP Network Initiated Prompt Reporting' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_pds_set_event_report_input_supl_network_initiated_prompt_reporting_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'SUPL Network Initiated Prompt Reporting' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'SUPL Network Initiated Prompt Reporting' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_event_report_input_supl_network_initiated_prompt_reporting_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_SUPL_NETWORK_INITIATED_PROMPT_REPORTING,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_event_report_input_supl_network_initiated_prompt_reporting_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'SUPL Network Initiated Prompt Reporting' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_pds_set_event_report_input_vx_network_initiated_request_reporting_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'VX Network Initiated Request Reporting' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'VX Network Initiated Request Reporting' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_event_report_input_vx_network_initiated_request_reporting_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_VX_NETWORK_INITIATED_REQUEST_REPORTING,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_event_report_input_vx_network_initiated_request_reporting_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'VX Network Initiated Request Reporting' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_pds_set_event_report_input_satellite_information_reporting_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Satellite Information Reporting' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Satellite Information Reporting' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_event_report_input_satellite_information_reporting_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_SATELLITE_INFORMATION_REPORTING,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_event_report_input_satellite_information_reporting_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Satellite Information Reporting' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_pds_set_event_report_input_external_wifi_position_request_reporting_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'External WIFI Position Request Reporting' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'External WIFI Position Request Reporting' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_event_report_input_external_wifi_position_request_reporting_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_EXTERNAL_WIFI_POSITION_REQUEST_REPORTING,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_event_report_input_external_wifi_position_request_reporting_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'External WIFI Position Request Reporting' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_pds_set_event_report_input_external_time_injection_request_reporting_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'External Time Injection Request Reporting' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'External Time Injection Request Reporting' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_event_report_input_external_time_injection_request_reporting_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_EXTERNAL_TIME_INJECTION_REQUEST_REPORTING,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_event_report_input_external_time_injection_request_reporting_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'External Time Injection Request Reporting' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_pds_set_event_report_input_external_xtra_data_request_reporting_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'External XTRA Data Request Reporting' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'External XTRA Data Request Reporting' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_event_report_input_external_xtra_data_request_reporting_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_EXTERNAL_XTRA_DATA_REQUEST_REPORTING,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_event_report_input_external_xtra_data_request_reporting_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'External XTRA Data Request Reporting' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_pds_set_event_report_input_parsed_position_reporting_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Parsed Position Reporting' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Parsed Position Reporting' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_event_report_input_parsed_position_reporting_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_PARSED_POSITION_REPORTING,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_event_report_input_parsed_position_reporting_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Parsed Position Reporting' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_pds_set_event_report_input_extended_nmea_position_reporting_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Extended NMEA Position Reporting' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Extended NMEA Position Reporting' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_event_report_input_extended_nmea_position_reporting_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_EXTENDED_NMEA_POSITION_REPORTING,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_event_report_input_extended_nmea_position_reporting_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'Extended NMEA Position Reporting' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_message_pds_set_event_report_input_nmea_position_reporting_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'NMEA Position Reporting' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'NMEA Position Reporting' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_event_report_input_nmea_position_reporting_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_NMEA_POSITION_REPORTING,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_event_report_input_nmea_position_reporting_validate (buffer, buffer_len)) {
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
            g_warning ("Left '%u' bytes unread when getting the 'NMEA Position Reporting' TLV as printable", buffer_len);
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
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_EXTENDED_EXTERNAL_XTRA_DATA_REQUEST_REPORTING:
            tlv_type_str = "Extended External XTRA Data Request Reporting";
            translated_value = qmi_message_pds_set_event_report_input_extended_external_xtra_data_request_reporting_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_NMEA_DEBUG_STRINGS_REPORTING:
            tlv_type_str = "NMEA Debug Strings Reporting";
            translated_value = qmi_message_pds_set_event_report_input_nmea_debug_strings_reporting_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_HEADING_UNCERTAINTY_REPORTING:
            tlv_type_str = "Heading Uncertainty Reporting";
            translated_value = qmi_message_pds_set_event_report_input_heading_uncertainty_reporting_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_TIME_SOURCE_INFORMATION_REPORTING:
            tlv_type_str = "Time Source Information Reporting";
            translated_value = qmi_message_pds_set_event_report_input_time_source_information_reporting_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_SENSOR_DATA_USAGE_INDICATOR_REPORTING:
            tlv_type_str = "Sensor Data Usage Indicator Reporting";
            translated_value = qmi_message_pds_set_event_report_input_sensor_data_usage_indicator_reporting_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_POSITION_RELIABILITY_INDICATOR_REPORTING:
            tlv_type_str = "Position Reliability Indicator Reporting";
            translated_value = qmi_message_pds_set_event_report_input_position_reliability_indicator_reporting_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_TIME_SYNC_REQUEST_REPORTING:
            tlv_type_str = "Time Sync Request Reporting";
            translated_value = qmi_message_pds_set_event_report_input_time_sync_request_reporting_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_GYRO_DATA_STREAMING_READY_REPORTING:
            tlv_type_str = "Gyro Data Streaming Ready Reporting";
            translated_value = qmi_message_pds_set_event_report_input_gyro_data_streaming_ready_reporting_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_ACCELEROMETER_DATA_STREAMING_READY_REPORTING:
            tlv_type_str = "Accelerometer Data Streaming Ready Reporting";
            translated_value = qmi_message_pds_set_event_report_input_accelerometer_data_streaming_ready_reporting_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_PDS_COMM_EVENT_REPORTING:
            tlv_type_str = "PDS Comm Event Reporting";
            translated_value = qmi_message_pds_set_event_report_input_pds_comm_event_reporting_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_UMTS_CP_NETWORK_INITIATED_PROMPT_REPORTING:
            tlv_type_str = "UMTS CP Network Initiated Prompt Reporting";
            translated_value = qmi_message_pds_set_event_report_input_umts_cp_network_initiated_prompt_reporting_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_SUPL_NETWORK_INITIATED_PROMPT_REPORTING:
            tlv_type_str = "SUPL Network Initiated Prompt Reporting";
            translated_value = qmi_message_pds_set_event_report_input_supl_network_initiated_prompt_reporting_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_VX_NETWORK_INITIATED_REQUEST_REPORTING:
            tlv_type_str = "VX Network Initiated Request Reporting";
            translated_value = qmi_message_pds_set_event_report_input_vx_network_initiated_request_reporting_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_SATELLITE_INFORMATION_REPORTING:
            tlv_type_str = "Satellite Information Reporting";
            translated_value = qmi_message_pds_set_event_report_input_satellite_information_reporting_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_EXTERNAL_WIFI_POSITION_REQUEST_REPORTING:
            tlv_type_str = "External WIFI Position Request Reporting";
            translated_value = qmi_message_pds_set_event_report_input_external_wifi_position_request_reporting_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_EXTERNAL_TIME_INJECTION_REQUEST_REPORTING:
            tlv_type_str = "External Time Injection Request Reporting";
            translated_value = qmi_message_pds_set_event_report_input_external_time_injection_request_reporting_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_EXTERNAL_XTRA_DATA_REQUEST_REPORTING:
            tlv_type_str = "External XTRA Data Request Reporting";
            translated_value = qmi_message_pds_set_event_report_input_external_xtra_data_request_reporting_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_PARSED_POSITION_REPORTING:
            tlv_type_str = "Parsed Position Reporting";
            translated_value = qmi_message_pds_set_event_report_input_parsed_position_reporting_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_EXTENDED_NMEA_POSITION_REPORTING:
            tlv_type_str = "Extended NMEA Position Reporting";
            translated_value = qmi_message_pds_set_event_report_input_extended_nmea_position_reporting_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_INPUT_TLV_NMEA_POSITION_REPORTING:
            tlv_type_str = "NMEA Position Reporting";
            translated_value = qmi_message_pds_set_event_report_input_nmea_position_reporting_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT_OUTPUT_TLV_RESULT:
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

static QmiMessagePdsSetEventReportOutput *
__qmi_message_pds_set_event_report_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessagePdsSetEventReportOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_PDS_SET_EVENT_REPORT, NULL);

    self = g_slice_new0 (QmiMessagePdsSetEventReportOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_PDS_SET_EVENT_REPORT_OUTPUT_TLV_RESULT,
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
                qmi_message_pds_set_event_report_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* INDICATION: Qmi Indication PDS Event Report */


/* --- Output -- */

struct _QmiIndicationPdsEventReportOutput {
    volatile gint ref_count;

    /* Position Session Status */
    gboolean arg_position_session_status_set;
    guint8 arg_position_session_status;

    /* Extended NMEA Position */
    gboolean arg_extended_nmea_position_set;
    gint8 arg_extended_nmea_position_operation_mode;
    gchar *arg_extended_nmea_position_nmea;

    /* NMEA Position */
    gboolean arg_nmea_position_set;
    gchar *arg_nmea_position;
};

#define QMI_INDICATION_PDS_EVENT_REPORT_OUTPUT_TLV_POSITION_SESSION_STATUS 0x12
#define QMI_INDICATION_PDS_EVENT_REPORT_OUTPUT_TLV_EXTENDED_NMEA_POSITION 0x11
#define QMI_INDICATION_PDS_EVENT_REPORT_OUTPUT_TLV_NMEA_POSITION 0x10

/**
 * qmi_indication_pds_event_report_output_get_position_session_status:
 * @self: a #QmiIndicationPdsEventReportOutput.
 * @position_session_status: a placeholder for the output #QmiPdsPositionSessionStatus, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Position Session Status' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_indication_pds_event_report_output_get_position_session_status (
    QmiIndicationPdsEventReportOutput *self,
    QmiPdsPositionSessionStatus *position_session_status,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_position_session_status_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Position Session Status' was not found in the message");
        return FALSE;
    }

    if (position_session_status)
        *position_session_status = (QmiPdsPositionSessionStatus)(self->arg_position_session_status);

    return TRUE;
}

/**
 * qmi_indication_pds_event_report_output_get_extended_nmea_position:
 * @self: a #QmiIndicationPdsEventReportOutput.
 * @extended_nmea_position_operation_mode: a placeholder for the output #QmiPdsOperationMode, or %NULL if not required.
 * @extended_nmea_position_nmea: a placeholder for the output constant string, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Extended NMEA Position' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_indication_pds_event_report_output_get_extended_nmea_position (
    QmiIndicationPdsEventReportOutput *self,
    QmiPdsOperationMode *extended_nmea_position_operation_mode,
    const gchar **extended_nmea_position_nmea,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_extended_nmea_position_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Extended NMEA Position' was not found in the message");
        return FALSE;
    }

    if (extended_nmea_position_operation_mode)
        *extended_nmea_position_operation_mode = (QmiPdsOperationMode)(self->arg_extended_nmea_position_operation_mode);
    if (extended_nmea_position_nmea)
        *extended_nmea_position_nmea = self->arg_extended_nmea_position_nmea;

    return TRUE;
}

/**
 * qmi_indication_pds_event_report_output_get_nmea_position:
 * @self: a #QmiIndicationPdsEventReportOutput.
 * @nmea_position: a placeholder for the output constant string, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'NMEA Position' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_indication_pds_event_report_output_get_nmea_position (
    QmiIndicationPdsEventReportOutput *self,
    const gchar **nmea_position,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_nmea_position_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'NMEA Position' was not found in the message");
        return FALSE;
    }

    if (nmea_position)
        *nmea_position = self->arg_nmea_position;

    return TRUE;
}

GType
qmi_indication_pds_event_report_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiIndicationPdsEventReportOutput"),
                                          (GBoxedCopyFunc) qmi_indication_pds_event_report_output_ref,
                                          (GBoxedFreeFunc) qmi_indication_pds_event_report_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_indication_pds_event_report_output_ref:
 * @self: a #QmiIndicationPdsEventReportOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiIndicationPdsEventReportOutput *
qmi_indication_pds_event_report_output_ref (QmiIndicationPdsEventReportOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_indication_pds_event_report_output_unref:
 * @self: a #QmiIndicationPdsEventReportOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_indication_pds_event_report_output_unref (QmiIndicationPdsEventReportOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_free (self->arg_extended_nmea_position_nmea);
        g_free (self->arg_nmea_position);
        g_slice_free (QmiIndicationPdsEventReportOutput, self);
    }
}

static gboolean
qmi_indication_pds_event_report_output_position_session_status_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Position Session Status' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Position Session Status' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_indication_pds_event_report_output_position_session_status_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_INDICATION_PDS_EVENT_REPORT_OUTPUT_TLV_POSITION_SESSION_STATUS,
                                      &buffer_len);
    if (buffer && qmi_indication_pds_event_report_output_position_session_status_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_PDS_POSITION_SESSION_STATUS_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_pds_position_session_status_get_string ((QmiPdsPositionSessionStatus)tmp));
#elif defined  __QMI_PDS_POSITION_SESSION_STATUS_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_pds_position_session_status_build_string_from_mask ((QmiPdsPositionSessionStatus)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiPdsPositionSessionStatus
#endif
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Position Session Status' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_indication_pds_event_report_output_extended_nmea_position_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;
    {
        guint16 size16;
        const guint8 *aux_buffer = &buffer[expected_len];
        guint16 aux_buffer_len = buffer_len - expected_len;

        qmi_utils_read_guint16_from_buffer (&aux_buffer, &aux_buffer_len, QMI_ENDIAN_LITTLE, &size16);
        expected_len += (2 + size16);
    }

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'Extended NMEA Position' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'Extended NMEA Position' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_indication_pds_event_report_output_extended_nmea_position_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_INDICATION_PDS_EVENT_REPORT_OUTPUT_TLV_EXTENDED_NMEA_POSITION,
                                      &buffer_len);
    if (buffer && qmi_indication_pds_event_report_output_extended_nmea_position_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " operation_mode = '");

        {
            gint8 tmp;

            /* Read the gint8 variable from the buffer */
            qmi_utils_read_gint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_PDS_OPERATION_MODE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_pds_operation_mode_get_string ((QmiPdsOperationMode)tmp));
#elif defined  __QMI_PDS_OPERATION_MODE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_pds_operation_mode_build_string_from_mask ((QmiPdsOperationMode)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiPdsOperationMode
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " nmea = '");

        {
            gchar *tmp;

            /* Read the string variable from the buffer */
            qmi_utils_read_string_from_buffer (
                &buffer,
                &buffer_len,
                16,
                200,
                &tmp);

            g_string_append_printf (printable, "%s", tmp);
            g_free (tmp);
        }
        g_string_append (printable, "'");
        g_string_append (printable, " ]");

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'Extended NMEA Position' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

static gboolean
qmi_indication_pds_event_report_output_nmea_position_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += buffer_len;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'NMEA Position' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'NMEA Position' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_indication_pds_event_report_output_nmea_position_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_INDICATION_PDS_EVENT_REPORT_OUTPUT_TLV_NMEA_POSITION,
                                      &buffer_len);
    if (buffer && qmi_indication_pds_event_report_output_nmea_position_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");

        {
            gchar *tmp;

            /* Read the string variable from the buffer */
            qmi_utils_read_string_from_buffer (
                &buffer,
                &buffer_len,
                0,
                200,
                &tmp);

            g_string_append_printf (printable, "%s", tmp);
            g_free (tmp);
        }

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'NMEA Position' TLV as printable", buffer_len);
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
        case QMI_INDICATION_PDS_EVENT_REPORT_OUTPUT_TLV_POSITION_SESSION_STATUS:
            tlv_type_str = "Position Session Status";
            translated_value = qmi_indication_pds_event_report_output_position_session_status_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_INDICATION_PDS_EVENT_REPORT_OUTPUT_TLV_EXTENDED_NMEA_POSITION:
            tlv_type_str = "Extended NMEA Position";
            translated_value = qmi_indication_pds_event_report_output_extended_nmea_position_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_INDICATION_PDS_EVENT_REPORT_OUTPUT_TLV_NMEA_POSITION:
            tlv_type_str = "NMEA Position";
            translated_value = qmi_indication_pds_event_report_output_nmea_position_get_printable (
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

static QmiIndicationPdsEventReportOutput *
__qmi_indication_pds_event_report_indication_parse (
    QmiMessage *message,
    GError **error)
{
    QmiIndicationPdsEventReportOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_INDICATION_PDS_EVENT_REPORT, NULL);

    self = g_slice_new0 (QmiIndicationPdsEventReportOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_INDICATION_PDS_EVENT_REPORT_OUTPUT_TLV_POSITION_SESSION_STATUS,
                                              &buffer_len);
            if (buffer && qmi_indication_pds_event_report_output_position_session_status_validate (buffer, buffer_len)) {
                self->arg_position_session_status_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_position_session_status = (QmiPdsPositionSessionStatus)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Position Session Status' TLV", buffer_len);
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
                                              QMI_INDICATION_PDS_EVENT_REPORT_OUTPUT_TLV_EXTENDED_NMEA_POSITION,
                                              &buffer_len);
            if (buffer && qmi_indication_pds_event_report_output_extended_nmea_position_validate (buffer, buffer_len)) {
                self->arg_extended_nmea_position_set = TRUE;

                {
                    gint8 tmp;

                    /* Read the gint8 variable from the buffer */
                    qmi_utils_read_gint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_extended_nmea_position_operation_mode = (QmiPdsOperationMode)tmp;
                }
                /* Read the string variable from the buffer */
                qmi_utils_read_string_from_buffer (
                    &buffer,
                    &buffer_len,
                    16,
                    200,
                    &(self->arg_extended_nmea_position_nmea));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'Extended NMEA Position' TLV", buffer_len);
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
                                              QMI_INDICATION_PDS_EVENT_REPORT_OUTPUT_TLV_NMEA_POSITION,
                                              &buffer_len);
            if (buffer && qmi_indication_pds_event_report_output_nmea_position_validate (buffer, buffer_len)) {
                self->arg_nmea_position_set = TRUE;

                /* Read the string variable from the buffer */
                qmi_utils_read_string_from_buffer (
                    &buffer,
                    &buffer_len,
                    0,
                    200,
                    &(self->arg_nmea_position));

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'NMEA Position' TLV", buffer_len);
                }
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message PDS Get GPS Service State */


/* --- Input -- */

/* Note: no fields in the Input container */

static QmiMessage *
__qmi_message_pds_get_gps_service_state_request_create (
    guint8 transaction_id,
    guint8 cid,
    gpointer unused,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_PDS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_PDS_GET_GPS_SERVICE_STATE);

    return self;
}

/* --- Output -- */

struct _QmiMessagePdsGetGpsServiceStateOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* State */
    gboolean arg_state_set;
    guint8 arg_state_gps_service_state;
    guint8 arg_state_tracking_session_state;
};

#define QMI_MESSAGE_PDS_GET_GPS_SERVICE_STATE_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_PDS_GET_GPS_SERVICE_STATE_OUTPUT_TLV_STATE 0x01

/**
 * qmi_message_pds_get_gps_service_state_output_get_result:
 * @self: a QmiMessagePdsGetGpsServiceStateOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_pds_get_gps_service_state_output_get_result (
    QmiMessagePdsGetGpsServiceStateOutput *self,
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
 * qmi_message_pds_get_gps_service_state_output_get_state:
 * @self: a #QmiMessagePdsGetGpsServiceStateOutput.
 * @state_gps_service_state: a placeholder for the output #gboolean, or %NULL if not required.
 * @state_tracking_session_state: a placeholder for the output #QmiPdsTrackingSessionState, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'State' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_get_gps_service_state_output_get_state (
    QmiMessagePdsGetGpsServiceStateOutput *self,
    gboolean *state_gps_service_state,
    QmiPdsTrackingSessionState *state_tracking_session_state,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_state_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'State' was not found in the message");
        return FALSE;
    }

    if (state_gps_service_state)
        *state_gps_service_state = (gboolean)(self->arg_state_gps_service_state);
    if (state_tracking_session_state)
        *state_tracking_session_state = (QmiPdsTrackingSessionState)(self->arg_state_tracking_session_state);

    return TRUE;
}

GType
qmi_message_pds_get_gps_service_state_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessagePdsGetGpsServiceStateOutput"),
                                          (GBoxedCopyFunc) qmi_message_pds_get_gps_service_state_output_ref,
                                          (GBoxedFreeFunc) qmi_message_pds_get_gps_service_state_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_pds_get_gps_service_state_output_ref:
 * @self: a #QmiMessagePdsGetGpsServiceStateOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessagePdsGetGpsServiceStateOutput *
qmi_message_pds_get_gps_service_state_output_ref (QmiMessagePdsGetGpsServiceStateOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_pds_get_gps_service_state_output_unref:
 * @self: a #QmiMessagePdsGetGpsServiceStateOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_pds_get_gps_service_state_output_unref (QmiMessagePdsGetGpsServiceStateOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessagePdsGetGpsServiceStateOutput, self);
    }
}

static gboolean
qmi_message_pds_get_gps_service_state_output_state_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;
    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'State' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'State' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_get_gps_service_state_output_state_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_GET_GPS_SERVICE_STATE_OUTPUT_TLV_STATE,
                                      &buffer_len);
    if (buffer && qmi_message_pds_get_gps_service_state_output_state_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " gps_service_state = '");

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
        g_string_append (printable, " tracking_session_state = '");

        {
            guint8 tmp;

            /* Read the guint8 variable from the buffer */
            qmi_utils_read_guint8_from_buffer (
                &buffer,
                &buffer_len,
                &tmp);

#if defined  __QMI_PDS_TRACKING_SESSION_STATE_IS_ENUM__
            g_string_append_printf (printable, "%s", qmi_pds_tracking_session_state_get_string ((QmiPdsTrackingSessionState)tmp));
#elif defined  __QMI_PDS_TRACKING_SESSION_STATE_IS_FLAGS__
            {
                gchar *flags_str;

                flags_str = qmi_pds_tracking_session_state_build_string_from_mask ((QmiPdsTrackingSessionState)tmp);
                g_string_append_printf (printable, "%s", flags_str);
                g_free (flags_str);
            }
#else
# error unexpected public format: QmiPdsTrackingSessionState
#endif
        }
        g_string_append (printable, "'");
        g_string_append (printable, " ]");

        /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
        if (buffer_len > 0) {
            g_warning ("Left '%u' bytes unread when getting the 'State' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_get_gps_service_state_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_get_gps_service_state_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_get_gps_service_state_context *ctx)
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
        case QMI_MESSAGE_PDS_GET_GPS_SERVICE_STATE_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_GET_GPS_SERVICE_STATE_OUTPUT_TLV_STATE:
            tlv_type_str = "State";
            translated_value = qmi_message_pds_get_gps_service_state_output_state_get_printable (
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
message_get_gps_service_state_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Get GPS Service State\" (0x0020)\n",
                            line_prefix);

    {
        struct message_get_gps_service_state_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_get_gps_service_state_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessagePdsGetGpsServiceStateOutput *
__qmi_message_pds_get_gps_service_state_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessagePdsGetGpsServiceStateOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_PDS_GET_GPS_SERVICE_STATE, NULL);

    self = g_slice_new0 (QmiMessagePdsGetGpsServiceStateOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_PDS_GET_GPS_SERVICE_STATE_OUTPUT_TLV_RESULT,
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
                qmi_message_pds_get_gps_service_state_output_unref (self);
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
                                              QMI_MESSAGE_PDS_GET_GPS_SERVICE_STATE_OUTPUT_TLV_STATE,
                                              &buffer_len);
            if (buffer && qmi_message_pds_get_gps_service_state_output_state_validate (buffer, buffer_len)) {
                self->arg_state_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_state_gps_service_state = (gboolean)tmp;
                }
                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_state_tracking_session_state = (QmiPdsTrackingSessionState)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'State' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the State TLV: Not found");
                qmi_message_pds_get_gps_service_state_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message PDS Set GPS Service State */


/* --- Input -- */

struct _QmiMessagePdsSetGpsServiceStateInput {
    volatile gint ref_count;

    /* State */
    gboolean arg_state_set;
    guint8 arg_state_gps_service_state;
};

#define QMI_MESSAGE_PDS_SET_GPS_SERVICE_STATE_INPUT_TLV_STATE 0x01

/**
 * qmi_message_pds_set_gps_service_state_input_get_state:
 * @self: a #QmiMessagePdsSetGpsServiceStateInput.
 * @state_gps_service_state: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'State' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_gps_service_state_input_get_state (
    QmiMessagePdsSetGpsServiceStateInput *self,
    gboolean *state_gps_service_state,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_state_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'State' was not found in the message");
        return FALSE;
    }

    if (state_gps_service_state)
        *state_gps_service_state = (gboolean)(self->arg_state_gps_service_state);

    return TRUE;
}

/**
 * qmi_message_pds_set_gps_service_state_input_set_state:
 * @self: a #QmiMessagePdsSetGpsServiceStateInput.
 * @state_gps_service_state: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'State' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_gps_service_state_input_set_state (
    QmiMessagePdsSetGpsServiceStateInput *self,
    gboolean state_gps_service_state,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_state_gps_service_state = (guint8)(state_gps_service_state);
    self->arg_state_set = TRUE;

    return TRUE;
}

GType
qmi_message_pds_set_gps_service_state_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessagePdsSetGpsServiceStateInput"),
                                          (GBoxedCopyFunc) qmi_message_pds_set_gps_service_state_input_ref,
                                          (GBoxedFreeFunc) qmi_message_pds_set_gps_service_state_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_pds_set_gps_service_state_input_ref:
 * @self: a #QmiMessagePdsSetGpsServiceStateInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessagePdsSetGpsServiceStateInput *
qmi_message_pds_set_gps_service_state_input_ref (QmiMessagePdsSetGpsServiceStateInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_pds_set_gps_service_state_input_unref:
 * @self: a #QmiMessagePdsSetGpsServiceStateInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_pds_set_gps_service_state_input_unref (QmiMessagePdsSetGpsServiceStateInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessagePdsSetGpsServiceStateInput, self);
    }
}

/**
 * qmi_message_pds_set_gps_service_state_input_new:
 *
 * Allocates a new #QmiMessagePdsSetGpsServiceStateInput.
 *
 * Returns: the newly created #QmiMessagePdsSetGpsServiceStateInput. The returned value should be freed with qmi_message_pds_set_gps_service_state_input_unref().
 */
QmiMessagePdsSetGpsServiceStateInput *
qmi_message_pds_set_gps_service_state_input_new (void)
{
    QmiMessagePdsSetGpsServiceStateInput *self;

    self = g_slice_new0 (QmiMessagePdsSetGpsServiceStateInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_pds_set_gps_service_state_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessagePdsSetGpsServiceStateInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_PDS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_PDS_SET_GPS_SERVICE_STATE);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Set GPS Service State' has mandatory TLVs");
        qmi_message_unref (self);
        return NULL;
    }

    /* Try to add the 'State' TLV */
    if (input->arg_state_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_state_gps_service_state;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_GPS_SERVICE_STATE_INPUT_TLV_STATE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the State TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'State' in message 'Set GPS Service State'");
        qmi_message_unref (self);
        return NULL;
    }

    return self;
}

/* --- Output -- */

struct _QmiMessagePdsSetGpsServiceStateOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;
};

#define QMI_MESSAGE_PDS_SET_GPS_SERVICE_STATE_OUTPUT_TLV_RESULT 0x02

/**
 * qmi_message_pds_set_gps_service_state_output_get_result:
 * @self: a QmiMessagePdsSetGpsServiceStateOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_pds_set_gps_service_state_output_get_result (
    QmiMessagePdsSetGpsServiceStateOutput *self,
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
qmi_message_pds_set_gps_service_state_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessagePdsSetGpsServiceStateOutput"),
                                          (GBoxedCopyFunc) qmi_message_pds_set_gps_service_state_output_ref,
                                          (GBoxedFreeFunc) qmi_message_pds_set_gps_service_state_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_pds_set_gps_service_state_output_ref:
 * @self: a #QmiMessagePdsSetGpsServiceStateOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessagePdsSetGpsServiceStateOutput *
qmi_message_pds_set_gps_service_state_output_ref (QmiMessagePdsSetGpsServiceStateOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_pds_set_gps_service_state_output_unref:
 * @self: a #QmiMessagePdsSetGpsServiceStateOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_pds_set_gps_service_state_output_unref (QmiMessagePdsSetGpsServiceStateOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessagePdsSetGpsServiceStateOutput, self);
    }
}

static gboolean
qmi_message_pds_set_gps_service_state_input_state_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'State' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'State' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_gps_service_state_input_state_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_GPS_SERVICE_STATE_INPUT_TLV_STATE,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_gps_service_state_input_state_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " gps_service_state = '");

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
            g_warning ("Left '%u' bytes unread when getting the 'State' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_set_gps_service_state_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_set_gps_service_state_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_set_gps_service_state_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_PDS_SET_GPS_SERVICE_STATE_INPUT_TLV_STATE:
            tlv_type_str = "State";
            translated_value = qmi_message_pds_set_gps_service_state_input_state_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_PDS_SET_GPS_SERVICE_STATE_OUTPUT_TLV_RESULT:
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
message_set_gps_service_state_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Set GPS Service State\" (0x0021)\n",
                            line_prefix);

    {
        struct message_set_gps_service_state_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_set_gps_service_state_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessagePdsSetGpsServiceStateOutput *
__qmi_message_pds_set_gps_service_state_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessagePdsSetGpsServiceStateOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_PDS_SET_GPS_SERVICE_STATE, NULL);

    self = g_slice_new0 (QmiMessagePdsSetGpsServiceStateOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_PDS_SET_GPS_SERVICE_STATE_OUTPUT_TLV_RESULT,
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
                qmi_message_pds_set_gps_service_state_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message PDS Get Auto Tracking State */


/* --- Input -- */

/* Note: no fields in the Input container */

static QmiMessage *
__qmi_message_pds_get_auto_tracking_state_request_create (
    guint8 transaction_id,
    guint8 cid,
    gpointer unused,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_PDS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_PDS_GET_AUTO_TRACKING_STATE);

    return self;
}

/* --- Output -- */

struct _QmiMessagePdsGetAutoTrackingStateOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* State */
    gboolean arg_state_set;
    guint8 arg_state_auto_tracking_state;
};

#define QMI_MESSAGE_PDS_GET_AUTO_TRACKING_STATE_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_PDS_GET_AUTO_TRACKING_STATE_OUTPUT_TLV_STATE 0x01

/**
 * qmi_message_pds_get_auto_tracking_state_output_get_result:
 * @self: a QmiMessagePdsGetAutoTrackingStateOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_pds_get_auto_tracking_state_output_get_result (
    QmiMessagePdsGetAutoTrackingStateOutput *self,
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
 * qmi_message_pds_get_auto_tracking_state_output_get_state:
 * @self: a #QmiMessagePdsGetAutoTrackingStateOutput.
 * @state_auto_tracking_state: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'State' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_get_auto_tracking_state_output_get_state (
    QmiMessagePdsGetAutoTrackingStateOutput *self,
    gboolean *state_auto_tracking_state,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_state_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'State' was not found in the message");
        return FALSE;
    }

    if (state_auto_tracking_state)
        *state_auto_tracking_state = (gboolean)(self->arg_state_auto_tracking_state);

    return TRUE;
}

GType
qmi_message_pds_get_auto_tracking_state_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessagePdsGetAutoTrackingStateOutput"),
                                          (GBoxedCopyFunc) qmi_message_pds_get_auto_tracking_state_output_ref,
                                          (GBoxedFreeFunc) qmi_message_pds_get_auto_tracking_state_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_pds_get_auto_tracking_state_output_ref:
 * @self: a #QmiMessagePdsGetAutoTrackingStateOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessagePdsGetAutoTrackingStateOutput *
qmi_message_pds_get_auto_tracking_state_output_ref (QmiMessagePdsGetAutoTrackingStateOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_pds_get_auto_tracking_state_output_unref:
 * @self: a #QmiMessagePdsGetAutoTrackingStateOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_pds_get_auto_tracking_state_output_unref (QmiMessagePdsGetAutoTrackingStateOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessagePdsGetAutoTrackingStateOutput, self);
    }
}

static gboolean
qmi_message_pds_get_auto_tracking_state_output_state_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'State' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'State' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_get_auto_tracking_state_output_state_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_GET_AUTO_TRACKING_STATE_OUTPUT_TLV_STATE,
                                      &buffer_len);
    if (buffer && qmi_message_pds_get_auto_tracking_state_output_state_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " auto_tracking_state = '");

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
            g_warning ("Left '%u' bytes unread when getting the 'State' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_get_auto_tracking_state_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_get_auto_tracking_state_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_get_auto_tracking_state_context *ctx)
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
        case QMI_MESSAGE_PDS_GET_AUTO_TRACKING_STATE_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PDS_GET_AUTO_TRACKING_STATE_OUTPUT_TLV_STATE:
            tlv_type_str = "State";
            translated_value = qmi_message_pds_get_auto_tracking_state_output_state_get_printable (
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
message_get_auto_tracking_state_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Get Auto Tracking State\" (0x0030)\n",
                            line_prefix);

    {
        struct message_get_auto_tracking_state_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_get_auto_tracking_state_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessagePdsGetAutoTrackingStateOutput *
__qmi_message_pds_get_auto_tracking_state_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessagePdsGetAutoTrackingStateOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_PDS_GET_AUTO_TRACKING_STATE, NULL);

    self = g_slice_new0 (QmiMessagePdsGetAutoTrackingStateOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_PDS_GET_AUTO_TRACKING_STATE_OUTPUT_TLV_RESULT,
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
                qmi_message_pds_get_auto_tracking_state_output_unref (self);
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
                                              QMI_MESSAGE_PDS_GET_AUTO_TRACKING_STATE_OUTPUT_TLV_STATE,
                                              &buffer_len);
            if (buffer && qmi_message_pds_get_auto_tracking_state_output_state_validate (buffer, buffer_len)) {
                self->arg_state_set = TRUE;

                {
                    guint8 tmp;

                    /* Read the guint8 variable from the buffer */
                    qmi_utils_read_guint8_from_buffer (
                        &buffer,
                        &buffer_len,
                        &tmp);
                    self->arg_state_auto_tracking_state = (gboolean)tmp;
                }

                /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
                if (buffer_len > 0) {
                    g_warning ("Left '%u' bytes unread when getting the 'State' TLV", buffer_len);
                }
            } else {
                g_set_error (error,
                             QMI_CORE_ERROR,
                             QMI_CORE_ERROR_TLV_NOT_FOUND,
                             "Couldn't get the State TLV: Not found");
                qmi_message_pds_get_auto_tracking_state_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message PDS Set Auto Tracking State */


/* --- Input -- */

struct _QmiMessagePdsSetAutoTrackingStateInput {
    volatile gint ref_count;

    /* State */
    gboolean arg_state_set;
    guint8 arg_state_auto_tracking_state;
};

#define QMI_MESSAGE_PDS_SET_AUTO_TRACKING_STATE_INPUT_TLV_STATE 0x01

/**
 * qmi_message_pds_set_auto_tracking_state_input_get_state:
 * @self: a #QmiMessagePdsSetAutoTrackingStateInput.
 * @state_auto_tracking_state: a placeholder for the output #gboolean, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'State' field from @self.
 *
 * Returns: %TRUE if the field is found, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_auto_tracking_state_input_get_state (
    QmiMessagePdsSetAutoTrackingStateInput *self,
    gboolean *state_auto_tracking_state,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_state_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'State' was not found in the message");
        return FALSE;
    }

    if (state_auto_tracking_state)
        *state_auto_tracking_state = (gboolean)(self->arg_state_auto_tracking_state);

    return TRUE;
}

/**
 * qmi_message_pds_set_auto_tracking_state_input_set_state:
 * @self: a #QmiMessagePdsSetAutoTrackingStateInput.
 * @state_auto_tracking_state: a #gboolean.
 * @error: Return location for error or %NULL.
 *
 * Set the 'State' field in the message.
 *
 * Returns: %TRUE if @value was successfully set, %FALSE otherwise.
 */
gboolean
qmi_message_pds_set_auto_tracking_state_input_set_state (
    QmiMessagePdsSetAutoTrackingStateInput *self,
    gboolean state_auto_tracking_state,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_state_auto_tracking_state = (guint8)(state_auto_tracking_state);
    self->arg_state_set = TRUE;

    return TRUE;
}

GType
qmi_message_pds_set_auto_tracking_state_input_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessagePdsSetAutoTrackingStateInput"),
                                          (GBoxedCopyFunc) qmi_message_pds_set_auto_tracking_state_input_ref,
                                          (GBoxedFreeFunc) qmi_message_pds_set_auto_tracking_state_input_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_pds_set_auto_tracking_state_input_ref:
 * @self: a #QmiMessagePdsSetAutoTrackingStateInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessagePdsSetAutoTrackingStateInput *
qmi_message_pds_set_auto_tracking_state_input_ref (QmiMessagePdsSetAutoTrackingStateInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_pds_set_auto_tracking_state_input_unref:
 * @self: a #QmiMessagePdsSetAutoTrackingStateInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_pds_set_auto_tracking_state_input_unref (QmiMessagePdsSetAutoTrackingStateInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessagePdsSetAutoTrackingStateInput, self);
    }
}

/**
 * qmi_message_pds_set_auto_tracking_state_input_new:
 *
 * Allocates a new #QmiMessagePdsSetAutoTrackingStateInput.
 *
 * Returns: the newly created #QmiMessagePdsSetAutoTrackingStateInput. The returned value should be freed with qmi_message_pds_set_auto_tracking_state_input_unref().
 */
QmiMessagePdsSetAutoTrackingStateInput *
qmi_message_pds_set_auto_tracking_state_input_new (void)
{
    QmiMessagePdsSetAutoTrackingStateInput *self;

    self = g_slice_new0 (QmiMessagePdsSetAutoTrackingStateInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_pds_set_auto_tracking_state_request_create (
    guint8 transaction_id,
    guint8 cid,
    QmiMessagePdsSetAutoTrackingStateInput *input,
    GError **error)
{
    QmiMessage *self;

    self = qmi_message_new (QMI_SERVICE_PDS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_PDS_SET_AUTO_TRACKING_STATE);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Set Auto Tracking State' has mandatory TLVs");
        qmi_message_unref (self);
        return NULL;
    }

    /* Try to add the 'State' TLV */
    if (input->arg_state_set) {
        guint8 buffer[1024];
        guint16 buffer_len = 1024;
        guint8 *buffer_aux = buffer;

        {
            guint8 tmp;

            tmp = (guint8)input->arg_state_auto_tracking_state;
            /* Write the guint8 variable to the buffer */
            qmi_utils_write_guint8_to_buffer (
                &buffer_aux,
                &buffer_len,
                &tmp);
        }

        if (!qmi_message_add_raw_tlv (self,
                                      (guint8)QMI_MESSAGE_PDS_SET_AUTO_TRACKING_STATE_INPUT_TLV_STATE,
                                      buffer,
                                      (1024 - buffer_len),
                                      error)) {
            g_prefix_error (error, "Couldn't set the State TLV: ");
            qmi_message_unref (self);
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'State' in message 'Set Auto Tracking State'");
        qmi_message_unref (self);
        return NULL;
    }

    return self;
}

/* --- Output -- */

struct _QmiMessagePdsSetAutoTrackingStateOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;
};

#define QMI_MESSAGE_PDS_SET_AUTO_TRACKING_STATE_OUTPUT_TLV_RESULT 0x02

/**
 * qmi_message_pds_set_auto_tracking_state_output_get_result:
 * @self: a QmiMessagePdsSetAutoTrackingStateOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 */
gboolean
qmi_message_pds_set_auto_tracking_state_output_get_result (
    QmiMessagePdsSetAutoTrackingStateOutput *self,
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
qmi_message_pds_set_auto_tracking_state_output_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessagePdsSetAutoTrackingStateOutput"),
                                          (GBoxedCopyFunc) qmi_message_pds_set_auto_tracking_state_output_ref,
                                          (GBoxedFreeFunc) qmi_message_pds_set_auto_tracking_state_output_unref);

        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/**
 * qmi_message_pds_set_auto_tracking_state_output_ref:
 * @self: a #QmiMessagePdsSetAutoTrackingStateOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 */
QmiMessagePdsSetAutoTrackingStateOutput *
qmi_message_pds_set_auto_tracking_state_output_ref (QmiMessagePdsSetAutoTrackingStateOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

/**
 * qmi_message_pds_set_auto_tracking_state_output_unref:
 * @self: a #QmiMessagePdsSetAutoTrackingStateOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 */
void
qmi_message_pds_set_auto_tracking_state_output_unref (QmiMessagePdsSetAutoTrackingStateOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessagePdsSetAutoTrackingStateOutput, self);
    }
}

static gboolean
qmi_message_pds_set_auto_tracking_state_input_state_validate (
    const guint8 *buffer,
    guint16 buffer_len)
{
    guint expected_len = 0;

    expected_len += 1;

    if (buffer_len < expected_len) {
        g_warning ("Cannot read the 'State' TLV: expected '%u' bytes, but only got '%u' bytes",
                   expected_len, buffer_len);
        return FALSE;
    }

    if (buffer_len > expected_len) {
        g_debug ("Reading the 'State' TLV: expected '%u' bytes, but got '%u' bytes",
                 expected_len, buffer_len);
        return TRUE;
    }

    return TRUE;
}


static gchar *
qmi_message_pds_set_auto_tracking_state_input_state_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    const guint8 *buffer;
    guint16 buffer_len;

    buffer = qmi_message_get_raw_tlv (message,
                                      QMI_MESSAGE_PDS_SET_AUTO_TRACKING_STATE_INPUT_TLV_STATE,
                                      &buffer_len);
    if (buffer && qmi_message_pds_set_auto_tracking_state_input_state_validate (buffer, buffer_len)) {
        GString *printable;

        printable = g_string_new ("");
        g_string_append (printable, "[");
        g_string_append (printable, " auto_tracking_state = '");

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
            g_warning ("Left '%u' bytes unread when getting the 'State' TLV as printable", buffer_len);
        }

        return g_string_free (printable, FALSE);
    }

    return NULL;
}

struct message_set_auto_tracking_state_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_set_auto_tracking_state_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_set_auto_tracking_state_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    gchar *translated_value;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_PDS_SET_AUTO_TRACKING_STATE_INPUT_TLV_STATE:
            tlv_type_str = "State";
            translated_value = qmi_message_pds_set_auto_tracking_state_input_state_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_PDS_SET_AUTO_TRACKING_STATE_OUTPUT_TLV_RESULT:
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
message_set_auto_tracking_state_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Set Auto Tracking State\" (0x0031)\n",
                            line_prefix);

    {
        struct message_set_auto_tracking_state_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_set_auto_tracking_state_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessagePdsSetAutoTrackingStateOutput *
__qmi_message_pds_set_auto_tracking_state_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessagePdsSetAutoTrackingStateOutput *self;

    g_return_val_if_fail (qmi_message_get_message_id (message) == QMI_MESSAGE_PDS_SET_AUTO_TRACKING_STATE, NULL);

    self = g_slice_new0 (QmiMessagePdsSetAutoTrackingStateOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            const guint8 *buffer;
            guint16 buffer_len;

            buffer = qmi_message_get_raw_tlv (message,
                                              QMI_MESSAGE_PDS_SET_AUTO_TRACKING_STATE_OUTPUT_TLV_RESULT,
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
                qmi_message_pds_set_auto_tracking_state_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* Service-specific printable: PDS */


gchar *
__qmi_message_pds_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    if (qmi_message_is_indication (self)) {
        switch (qmi_message_get_message_id (self)) {
        case QMI_INDICATION_PDS_EVENT_REPORT:
            return indication_event_report_get_printable (self, line_prefix);
         default:
             return NULL;
        }
    } else {
        switch (qmi_message_get_message_id (self)) {
        case QMI_MESSAGE_PDS_RESET:
            return message_reset_get_printable (self, line_prefix);
        case QMI_MESSAGE_PDS_SET_EVENT_REPORT:
            return message_set_event_report_get_printable (self, line_prefix);
        case QMI_MESSAGE_PDS_GET_GPS_SERVICE_STATE:
            return message_get_gps_service_state_get_printable (self, line_prefix);
        case QMI_MESSAGE_PDS_SET_GPS_SERVICE_STATE:
            return message_set_gps_service_state_get_printable (self, line_prefix);
        case QMI_MESSAGE_PDS_GET_AUTO_TRACKING_STATE:
            return message_get_auto_tracking_state_get_printable (self, line_prefix);
        case QMI_MESSAGE_PDS_SET_AUTO_TRACKING_STATE:
            return message_set_auto_tracking_state_get_printable (self, line_prefix);
         default:
             return NULL;
        }
    }
}

gboolean
__qmi_message_pds_get_version_introduced (
    QmiMessage *self,
    guint *major,
    guint *minor)
{
    switch (qmi_message_get_message_id (self)) {
    case QMI_MESSAGE_PDS_RESET:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_PDS_SET_EVENT_REPORT:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_PDS_GET_GPS_SERVICE_STATE:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_PDS_SET_GPS_SERVICE_STATE:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_PDS_GET_AUTO_TRACKING_STATE:
        *major = 1;
        *minor = 0;
        return TRUE;
    case QMI_MESSAGE_PDS_SET_AUTO_TRACKING_STATE:
        *major = 1;
        *minor = 0;
        return TRUE;
    default:
        return FALSE;
    }
}

/*****************************************************************************/
/* CLIENT: QMI Client PDS */


/**
 * SECTION: qmi-client-pds
 * @title: QmiClientPds
 * @short_description: #QmiClient for the PDS service.
 *
 * #QmiClient which handles operations in the PDS service.
 */

G_DEFINE_TYPE (QmiClientPds, qmi_client_pds, QMI_TYPE_CLIENT);

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
        case QMI_INDICATION_PDS_EVENT_REPORT: {
            QmiIndicationPdsEventReportOutput *output;
            GError *error = NULL;

            /* Parse indication */
            output = __qmi_indication_pds_event_report_indication_parse (message, &error);
            if (!output) {
                g_warning ("Couldn't parse 'Event Report' indication: %s",
                           error ? error->message : "Unknown error");
                if (error)
                    g_error_free (error);
            } else {
                g_signal_emit (self, signals[SIGNAL_EVENT_REPORT], 0, output);
                qmi_indication_pds_event_report_output_unref (output);
            }
            break;
        }
        default:
            break;
    }
}

static void
qmi_client_pds_init (QmiClientPds *self)
{
}

static void
qmi_client_pds_class_init (QmiClientPdsClass *klass)
{
    QmiClientClass *client_class = QMI_CLIENT_CLASS (klass);

    client_class->process_indication = process_indication;

    /**
     * QmiClientPds::event-report:
     * @object: A #QmiClientPds.
     * @output: A #QmiIndicationPdsEventReportOutput.
     *
     * The ::event-report signal gets emitted when a '<link linkend="libqmi-glib-PDS-Event-Report.top_of_page">Event Report</link>' indication is received.
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
                      QMI_TYPE_INDICATION_PDS_EVENT_REPORT_OUTPUT);
}


/**
 * qmi_client_pds_reset_finish:
 * @self: a #QmiClientPds.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_pds_reset().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_pds_reset().
 *
 * Returns: a #QmiMessagePdsResetOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_pds_reset_output_unref().
 */
QmiMessagePdsResetOutput *
qmi_client_pds_reset_finish (
    QmiClientPds *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_pds_reset_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
reset_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessagePdsResetOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_pds_reset_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_pds_reset_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_pds_reset:
 * @self: a #QmiClientPds.
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
 * You can then call qmi_client_pds_reset_finish() to get the result of the operation.
 */
void
qmi_client_pds_reset (
    QmiClientPds *self,
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
                                        qmi_client_pds_reset);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_pds_reset_request_create (
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
 * qmi_client_pds_set_event_report_finish:
 * @self: a #QmiClientPds.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_pds_set_event_report().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_pds_set_event_report().
 *
 * Returns: a #QmiMessagePdsSetEventReportOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_pds_set_event_report_output_unref().
 */
QmiMessagePdsSetEventReportOutput *
qmi_client_pds_set_event_report_finish (
    QmiClientPds *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_pds_set_event_report_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
set_event_report_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessagePdsSetEventReportOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_pds_set_event_report_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_pds_set_event_report_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_pds_set_event_report:
 * @self: a #QmiClientPds.
 * @input: a #QmiMessagePdsSetEventReportInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Set Event Report request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_pds_set_event_report_finish() to get the result of the operation.
 */
void
qmi_client_pds_set_event_report (
    QmiClientPds *self,
    QmiMessagePdsSetEventReportInput *input,
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
                                        qmi_client_pds_set_event_report);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_pds_set_event_report_request_create (
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
 * qmi_client_pds_get_gps_service_state_finish:
 * @self: a #QmiClientPds.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_pds_get_gps_service_state().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_pds_get_gps_service_state().
 *
 * Returns: a #QmiMessagePdsGetGpsServiceStateOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_pds_get_gps_service_state_output_unref().
 */
QmiMessagePdsGetGpsServiceStateOutput *
qmi_client_pds_get_gps_service_state_finish (
    QmiClientPds *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_pds_get_gps_service_state_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
get_gps_service_state_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessagePdsGetGpsServiceStateOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_pds_get_gps_service_state_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_pds_get_gps_service_state_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_pds_get_gps_service_state:
 * @self: a #QmiClientPds.
 * @unused: %NULL. This message doesn't have any input bundle.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Get GPS Service State request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_pds_get_gps_service_state_finish() to get the result of the operation.
 */
void
qmi_client_pds_get_gps_service_state (
    QmiClientPds *self,
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
                                        qmi_client_pds_get_gps_service_state);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_pds_get_gps_service_state_request_create (
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
                        (GAsyncReadyCallback)get_gps_service_state_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_pds_set_gps_service_state_finish:
 * @self: a #QmiClientPds.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_pds_set_gps_service_state().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_pds_set_gps_service_state().
 *
 * Returns: a #QmiMessagePdsSetGpsServiceStateOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_pds_set_gps_service_state_output_unref().
 */
QmiMessagePdsSetGpsServiceStateOutput *
qmi_client_pds_set_gps_service_state_finish (
    QmiClientPds *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_pds_set_gps_service_state_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
set_gps_service_state_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessagePdsSetGpsServiceStateOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_pds_set_gps_service_state_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_pds_set_gps_service_state_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_pds_set_gps_service_state:
 * @self: a #QmiClientPds.
 * @input: a #QmiMessagePdsSetGpsServiceStateInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Set GPS Service State request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_pds_set_gps_service_state_finish() to get the result of the operation.
 */
void
qmi_client_pds_set_gps_service_state (
    QmiClientPds *self,
    QmiMessagePdsSetGpsServiceStateInput *input,
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
                                        qmi_client_pds_set_gps_service_state);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_pds_set_gps_service_state_request_create (
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
                        (GAsyncReadyCallback)set_gps_service_state_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_pds_get_auto_tracking_state_finish:
 * @self: a #QmiClientPds.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_pds_get_auto_tracking_state().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_pds_get_auto_tracking_state().
 *
 * Returns: a #QmiMessagePdsGetAutoTrackingStateOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_pds_get_auto_tracking_state_output_unref().
 */
QmiMessagePdsGetAutoTrackingStateOutput *
qmi_client_pds_get_auto_tracking_state_finish (
    QmiClientPds *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_pds_get_auto_tracking_state_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
get_auto_tracking_state_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessagePdsGetAutoTrackingStateOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_pds_get_auto_tracking_state_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_pds_get_auto_tracking_state_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_pds_get_auto_tracking_state:
 * @self: a #QmiClientPds.
 * @unused: %NULL. This message doesn't have any input bundle.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Get Auto Tracking State request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_pds_get_auto_tracking_state_finish() to get the result of the operation.
 */
void
qmi_client_pds_get_auto_tracking_state (
    QmiClientPds *self,
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
                                        qmi_client_pds_get_auto_tracking_state);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_pds_get_auto_tracking_state_request_create (
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
                        (GAsyncReadyCallback)get_auto_tracking_state_ready,
                        result);
    qmi_message_unref (request);
}


/**
 * qmi_client_pds_set_auto_tracking_state_finish:
 * @self: a #QmiClientPds.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_pds_set_auto_tracking_state().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_pds_set_auto_tracking_state().
 *
 * Returns: a #QmiMessagePdsSetAutoTrackingStateOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_pds_set_auto_tracking_state_output_unref().
 */
QmiMessagePdsSetAutoTrackingStateOutput *
qmi_client_pds_set_auto_tracking_state_finish (
    QmiClientPds *self,
    GAsyncResult *res,
    GError **error)
{
   if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (res), error))
       return NULL;

   return qmi_message_pds_set_auto_tracking_state_output_ref (g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (res)));
}

static void
set_auto_tracking_state_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GSimpleAsyncResult *simple)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessagePdsSetAutoTrackingStateOutput *output;

    reply = qmi_device_command_finish (device, res, &error);
    if (!reply) {
        g_simple_async_result_take_error (simple, error);
        g_simple_async_result_complete (simple);
        g_object_unref (simple);
        return;
    }

    /* Parse reply */
    output = __qmi_message_pds_set_auto_tracking_state_response_parse (reply, &error);
    if (!output)
        g_simple_async_result_take_error (simple, error);
    else
        g_simple_async_result_set_op_res_gpointer (simple,
                                                   output,
                                                   (GDestroyNotify)qmi_message_pds_set_auto_tracking_state_output_unref);
    g_simple_async_result_complete (simple);
    g_object_unref (simple);
    qmi_message_unref (reply);
}

/**
 * qmi_client_pds_set_auto_tracking_state:
 * @self: a #QmiClientPds.
 * @input: a #QmiMessagePdsSetAutoTrackingStateInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Set Auto Tracking State request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_pds_set_auto_tracking_state_finish() to get the result of the operation.
 */
void
qmi_client_pds_set_auto_tracking_state (
    QmiClientPds *self,
    QmiMessagePdsSetAutoTrackingStateInput *input,
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
                                        qmi_client_pds_set_auto_tracking_state);

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_pds_set_auto_tracking_state_request_create (
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
                        (GAsyncReadyCallback)set_auto_tracking_state_ready,
                        result);
    qmi_message_unref (request);
}

