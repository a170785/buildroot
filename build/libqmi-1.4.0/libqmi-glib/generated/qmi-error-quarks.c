
/* Generated data (by glib-mkenums) */

#include "qmi-errors.h"
#include "qmi-error-types.h"

#include <gio/gio.h>

/* enumerations from "../../libqmi-glib/qmi-errors.h" */

#define ERROR_PREFIX QMI_CORE_ERROR_DBUS_PREFIX
static const GDBusErrorEntry qmi_core_error_entries[] = {
    { QMI_CORE_ERROR_FAILED, ERROR_PREFIX ".Failed" },
    { QMI_CORE_ERROR_WRONG_STATE, ERROR_PREFIX ".WrongState" },
    { QMI_CORE_ERROR_TIMEOUT, ERROR_PREFIX ".Timeout" },
    { QMI_CORE_ERROR_INVALID_ARGS, ERROR_PREFIX ".InvalidArgs" },
    { QMI_CORE_ERROR_INVALID_MESSAGE, ERROR_PREFIX ".InvalidMessage" },
    { QMI_CORE_ERROR_TLV_NOT_FOUND, ERROR_PREFIX ".TlvNotFound" },
    { QMI_CORE_ERROR_TLV_TOO_LONG, ERROR_PREFIX ".TlvTooLong" },
    { QMI_CORE_ERROR_UNSUPPORTED, ERROR_PREFIX ".Unsupported" },
};
#undef ERROR_PREFIX

GQuark
qmi_core_error_quark (void)
{
    static volatile gsize quark_volatile = 0;

    if (!quark_volatile)
        g_dbus_error_register_error_domain ("qmi_core_error_quark",
                                            &quark_volatile,
                                            qmi_core_error_entries,
                                            G_N_ELEMENTS (qmi_core_error_entries));

    return (GQuark) quark_volatile;
}


#define ERROR_PREFIX QMI_PROTOCOL_ERROR_DBUS_PREFIX
static const GDBusErrorEntry qmi_protocol_error_entries[] = {
    { QMI_PROTOCOL_ERROR_NONE, ERROR_PREFIX ".None" },
    { QMI_PROTOCOL_ERROR_MALFORMED_MESSAGE, ERROR_PREFIX ".MalformedMessage" },
    { QMI_PROTOCOL_ERROR_NO_MEMORY, ERROR_PREFIX ".NoMemory" },
    { QMI_PROTOCOL_ERROR_INTERNAL, ERROR_PREFIX ".Internal" },
    { QMI_PROTOCOL_ERROR_ABORTED, ERROR_PREFIX ".Aborted" },
    { QMI_PROTOCOL_ERROR_CLIENT_IDS_EXHAUSTED, ERROR_PREFIX ".ClientIdsExhausted" },
    { QMI_PROTOCOL_ERROR_UNABORTABLE_TRANSACTION, ERROR_PREFIX ".UnabortableTransaction" },
    { QMI_PROTOCOL_ERROR_INVALID_CLIENT_ID, ERROR_PREFIX ".InvalidClientId" },
    { QMI_PROTOCOL_ERROR_NO_THRESHOLDS_PROVIDED, ERROR_PREFIX ".NoThresholdsProvided" },
    { QMI_PROTOCOL_ERROR_INVALID_HANDLE, ERROR_PREFIX ".InvalidHandle" },
    { QMI_PROTOCOL_ERROR_INVALID_PROFILE, ERROR_PREFIX ".InvalidProfile" },
    { QMI_PROTOCOL_ERROR_INVALID_PIN_ID, ERROR_PREFIX ".InvalidPinId" },
    { QMI_PROTOCOL_ERROR_INCORRECT_PIN, ERROR_PREFIX ".IncorrectPin" },
    { QMI_PROTOCOL_ERROR_NO_NETWORK_FOUND, ERROR_PREFIX ".NoNetworkFound" },
    { QMI_PROTOCOL_ERROR_CALL_FAILED, ERROR_PREFIX ".CallFailed" },
    { QMI_PROTOCOL_ERROR_OUT_OF_CALL, ERROR_PREFIX ".OutOfCall" },
    { QMI_PROTOCOL_ERROR_NOT_PROVISIONED, ERROR_PREFIX ".NotProvisioned" },
    { QMI_PROTOCOL_ERROR_MISSING_ARGUMENT, ERROR_PREFIX ".MissingArgument" },
    { QMI_PROTOCOL_ERROR_ARGUMENT_TOO_LONG, ERROR_PREFIX ".ArgumentTooLong" },
    { QMI_PROTOCOL_ERROR_INVALID_TRANSACTION_ID, ERROR_PREFIX ".InvalidTransactionId" },
    { QMI_PROTOCOL_ERROR_DEVICE_IN_USE, ERROR_PREFIX ".DeviceInUse" },
    { QMI_PROTOCOL_ERROR_NETWORK_UNSUPPORTED, ERROR_PREFIX ".NetworkUnsupported" },
    { QMI_PROTOCOL_ERROR_DEVICE_UNSUPPORTED, ERROR_PREFIX ".DeviceUnsupported" },
    { QMI_PROTOCOL_ERROR_NO_EFFECT, ERROR_PREFIX ".NoEffect" },
    { QMI_PROTOCOL_ERROR_NO_FREE_PROFILE, ERROR_PREFIX ".NoFreeProfile" },
    { QMI_PROTOCOL_ERROR_INVALID_PDP_TYPE, ERROR_PREFIX ".InvalidPdpType" },
    { QMI_PROTOCOL_ERROR_INVALID_TECHNOLOGY_PREFERENCE, ERROR_PREFIX ".InvalidTechnologyPreference" },
    { QMI_PROTOCOL_ERROR_INVALID_PROFILE_TYPE, ERROR_PREFIX ".InvalidProfileType" },
    { QMI_PROTOCOL_ERROR_INVALID_SERVICE_TYPE, ERROR_PREFIX ".InvalidServiceType" },
    { QMI_PROTOCOL_ERROR_INVALID_REGISTER_ACTION, ERROR_PREFIX ".InvalidRegisterAction" },
    { QMI_PROTOCOL_ERROR_INVALID_PS_ATTACH_ACTION, ERROR_PREFIX ".InvalidPsAttachAction" },
    { QMI_PROTOCOL_ERROR_AUTHENTICATION_FAILED, ERROR_PREFIX ".AuthenticationFailed" },
    { QMI_PROTOCOL_ERROR_PIN_BLOCKED, ERROR_PREFIX ".PinBlocked" },
    { QMI_PROTOCOL_ERROR_PIN_ALWAYS_BLOCKED, ERROR_PREFIX ".PinAlwaysBlocked" },
    { QMI_PROTOCOL_ERROR_UIM_UNINITIALIZED, ERROR_PREFIX ".UimUninitialized" },
    { QMI_PROTOCOL_ERROR_MAXIMUM_QOS_REQUESTS_IN_USE, ERROR_PREFIX ".MaximumQosRequestsInUse" },
    { QMI_PROTOCOL_ERROR_INCORRECT_FLOW_FILTER, ERROR_PREFIX ".IncorrectFlowFilter" },
    { QMI_PROTOCOL_ERROR_NETWORK_QOS_UNAWARE, ERROR_PREFIX ". NetworkQosUnaware" },
    { QMI_PROTOCOL_ERROR_INVALID_QOS_ID, ERROR_PREFIX ".InvalidQosId" },
    { QMI_PROTOCOL_ERROR_QOS_UNAVAILABLE, ERROR_PREFIX ".QosUnavailable" },
    { QMI_PROTOCOL_ERROR_FLOW_SUSPENDED, ERROR_PREFIX ".FlowSuspended" },
    { QMI_PROTOCOL_ERROR_GENERAL_ERROR, ERROR_PREFIX ".GeneralError" },
    { QMI_PROTOCOL_ERROR_UNKNOWN_ERROR, ERROR_PREFIX ".UnknownError" },
    { QMI_PROTOCOL_ERROR_INVALID_ARGUMENT, ERROR_PREFIX ".InvalidArgument" },
    { QMI_PROTOCOL_ERROR_INVALID_INDEX, ERROR_PREFIX ".InvalidIndex" },
    { QMI_PROTOCOL_ERROR_NO_ENTRY, ERROR_PREFIX ".NoEntry" },
    { QMI_PROTOCOL_ERROR_DEVICE_STORAGE_FULL, ERROR_PREFIX ".DeviceStorageFull" },
    { QMI_PROTOCOL_ERROR_DEVICE_NOT_READY, ERROR_PREFIX ".DeviceNotReady" },
    { QMI_PROTOCOL_ERROR_NETWORK_NOT_READY, ERROR_PREFIX ".NetworkNotReady" },
    { QMI_PROTOCOL_ERROR_WMS_CAUSE_CODE, ERROR_PREFIX ".Wms.CauseCode" },
    { QMI_PROTOCOL_ERROR_WMS_MESSAGE_NOT_SENT, ERROR_PREFIX ".Wms.MessageNotSent" },
    { QMI_PROTOCOL_ERROR_WMS_MESSAGE_DELIVERY_FAILURE, ERROR_PREFIX ".Wms.MessageDeliveryFailure" },
    { QMI_PROTOCOL_ERROR_WMS_INVALID_MESSAGE_ID, ERROR_PREFIX ".Wms.InvalidMessageId" },
    { QMI_PROTOCOL_ERROR_WMS_ENCODING, ERROR_PREFIX ".Wms.Encoding" },
    { QMI_PROTOCOL_ERROR_AUTHENTICATION_LOCK, ERROR_PREFIX ".AuthenticationLock" },
    { QMI_PROTOCOL_ERROR_INVALID_TRANSITION, ERROR_PREFIX ".InvalidTransaction" },
    { QMI_PROTOCOL_ERROR_SESSION_INACTIVE, ERROR_PREFIX ".SessionInactive" },
    { QMI_PROTOCOL_ERROR_SESSION_INVALID, ERROR_PREFIX ".SessionInvalid" },
    { QMI_PROTOCOL_ERROR_SESSION_OWNERSHIP, ERROR_PREFIX ".SessionOwnership" },
    { QMI_PROTOCOL_ERROR_INSUFFICIENT_RESOURCES, ERROR_PREFIX ".InsufficientResources" },
    { QMI_PROTOCOL_ERROR_DISABLED, ERROR_PREFIX ".Disabled" },
    { QMI_PROTOCOL_ERROR_INVALID_OPERATION, ERROR_PREFIX ".InvalidOperation" },
    { QMI_PROTOCOL_ERROR_INVALID_QMI_COMMAND, ERROR_PREFIX ".InvalidQmiCommand" },
    { QMI_PROTOCOL_ERROR_WMS_T_PDU_TYPE, ERROR_PREFIX ".Wms.TPduType" },
    { QMI_PROTOCOL_ERROR_WMS_SMSC_ADDRESS, ERROR_PREFIX ".Wms.SmscAddress" },
    { QMI_PROTOCOL_ERROR_INFORMATION_UNAVAILABLE, ERROR_PREFIX ".InformationUnavailable" },
    { QMI_PROTOCOL_ERROR_SEGMENT_TOO_LONG, ERROR_PREFIX ".SegmentTooLong" },
    { QMI_PROTOCOL_ERROR_SEGMENT_ORDER, ERROR_PREFIX ".SegmentOrder" },
    { QMI_PROTOCOL_ERROR_BUNDLING_NOT_SUPPORTED, ERROR_PREFIX ".BundlingNotSupported" },
    { QMI_PROTOCOL_ERROR_SIM_FILE_NOT_FOUND, ERROR_PREFIX ".SimFileNotFound" },
    { QMI_PROTOCOL_ERROR_ACCESS_DENIED, ERROR_PREFIX ".AccessDenied" },
    { QMI_PROTOCOL_ERROR_HARDWARE_RESTRICTED, ERROR_PREFIX ".HardwareRestricted" },
    { QMI_PROTOCOL_ERROR_CAT_EVENT_REGISTRATION_FAILED, ERROR_PREFIX ".Cat.EventRegistrationFailed" },
    { QMI_PROTOCOL_ERROR_CAT_INVALID_TERMINAL_RESPONSE, ERROR_PREFIX ".Cat.InvalidTerminalResponse" },
    { QMI_PROTOCOL_ERROR_CAT_INVALID_ENVELOPE_COMMAND, ERROR_PREFIX ".Cat.InvalidEnvelopeCommand" },
    { QMI_PROTOCOL_ERROR_CAT_ENVELOPE_COMMAND_BUSY, ERROR_PREFIX ".Cat.EnvelopCommandBusy" },
    { QMI_PROTOCOL_ERROR_CAT_ENVELOPE_COMMAND_FAILED, ERROR_PREFIX ".Cat.EnvelopeCommandFailed" },
};
#undef ERROR_PREFIX

GQuark
qmi_protocol_error_quark (void)
{
    static volatile gsize quark_volatile = 0;

    if (!quark_volatile)
        g_dbus_error_register_error_domain ("qmi_protocol_error_quark",
                                            &quark_volatile,
                                            qmi_protocol_error_entries,
                                            G_N_ELEMENTS (qmi_protocol_error_entries));

    return (GQuark) quark_volatile;
}


/* Generated data ends here */

