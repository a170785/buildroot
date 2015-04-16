
/* Generated data (by glib-mkenums) */

#include "qmi-enum-types.h"

/* enumerations from "../../libqmi-glib/qmi-enums.h" */
static const GEnumValue qmi_service_values[] = {
    { QMI_SERVICE_UNKNOWN, "QMI_SERVICE_UNKNOWN", "unknown" },
    { QMI_SERVICE_CTL, "QMI_SERVICE_CTL", "ctl" },
    { QMI_SERVICE_WDS, "QMI_SERVICE_WDS", "wds" },
    { QMI_SERVICE_DMS, "QMI_SERVICE_DMS", "dms" },
    { QMI_SERVICE_NAS, "QMI_SERVICE_NAS", "nas" },
    { QMI_SERVICE_QOS, "QMI_SERVICE_QOS", "qos" },
    { QMI_SERVICE_WMS, "QMI_SERVICE_WMS", "wms" },
    { QMI_SERVICE_PDS, "QMI_SERVICE_PDS", "pds" },
    { QMI_SERVICE_AUTH, "QMI_SERVICE_AUTH", "auth" },
    { QMI_SERVICE_AT, "QMI_SERVICE_AT", "at" },
    { QMI_SERVICE_VOICE, "QMI_SERVICE_VOICE", "voice" },
    { QMI_SERVICE_CAT2, "QMI_SERVICE_CAT2", "cat2" },
    { QMI_SERVICE_UIM, "QMI_SERVICE_UIM", "uim" },
    { QMI_SERVICE_PBM, "QMI_SERVICE_PBM", "pbm" },
    { QMI_SERVICE_LOC, "QMI_SERVICE_LOC", "loc" },
    { QMI_SERVICE_SAR, "QMI_SERVICE_SAR", "sar" },
    { QMI_SERVICE_RMTFS, "QMI_SERVICE_RMTFS", "rmtfs" },
    { QMI_SERVICE_CAT, "QMI_SERVICE_CAT", "cat" },
    { QMI_SERVICE_RMS, "QMI_SERVICE_RMS", "rms" },
    { QMI_SERVICE_OMA, "QMI_SERVICE_OMA", "oma" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_service_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiService"),
                                      qmi_service_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_SERVICE_IS_ENUM__
/**
 * qmi_service_get_string:
 * @val: a QmiService.
 *
 * Gets the nickname string for the #QmiService specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_service_get_string (QmiService val)
{
    guint i;

    for (i = 0; qmi_service_values[i].value_nick; i++) {
        if (val == qmi_service_values[i].value)
            return qmi_service_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_SERVICE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_SERVICE_IS_FLAGS__
/**
 * qmi_service_build_string_from_mask:
 * @mask: bitmask of QmiService values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiService in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_service_build_string_from_mask (QmiService mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_service_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_service_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_service_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_service_values[i].value) {
            guint c;
            gulong number = qmi_service_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_service_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_SERVICE_IS_FLAGS__ */

/* enumerations from "../../libqmi-glib/qmi-enums-wds.h" */
static const GEnumValue qmi_wds_ip_family_values[] = {
    { QMI_WDS_IP_FAMILY_IPV4, "QMI_WDS_IP_FAMILY_IPV4", "ipv4" },
    { QMI_WDS_IP_FAMILY_IPV6, "QMI_WDS_IP_FAMILY_IPV6", "ipv6" },
    { QMI_WDS_IP_FAMILY_UNSPECIFIED, "QMI_WDS_IP_FAMILY_UNSPECIFIED", "unspecified" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_ip_family_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWdsIpFamily"),
                                      qmi_wds_ip_family_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_IP_FAMILY_IS_ENUM__
/**
 * qmi_wds_ip_family_get_string:
 * @val: a QmiWdsIpFamily.
 *
 * Gets the nickname string for the #QmiWdsIpFamily specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_ip_family_get_string (QmiWdsIpFamily val)
{
    guint i;

    for (i = 0; qmi_wds_ip_family_values[i].value_nick; i++) {
        if (val == qmi_wds_ip_family_values[i].value)
            return qmi_wds_ip_family_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_IP_FAMILY_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_IP_FAMILY_IS_FLAGS__
/**
 * qmi_wds_ip_family_build_string_from_mask:
 * @mask: bitmask of QmiWdsIpFamily values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsIpFamily in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_ip_family_build_string_from_mask (QmiWdsIpFamily mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_ip_family_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_ip_family_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_ip_family_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_ip_family_values[i].value) {
            guint c;
            gulong number = qmi_wds_ip_family_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_ip_family_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_IP_FAMILY_IS_FLAGS__ */

static const GFlagsValue qmi_wds_technology_preference_values[] = {
    { QMI_WDS_TECHNOLOGY_PREFERENCE_ALLOW_3GPP, "QMI_WDS_TECHNOLOGY_PREFERENCE_ALLOW_3GPP", "3gpp" },
    { QMI_WDS_TECHNOLOGY_PREFERENCE_ALLOW_3GPP2, "QMI_WDS_TECHNOLOGY_PREFERENCE_ALLOW_3GPP2", "3gpp2" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_technology_preference_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("QmiWdsTechnologyPreference"),
                                      qmi_wds_technology_preference_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_TECHNOLOGY_PREFERENCE_IS_ENUM__
/**
 * qmi_wds_technology_preference_get_string:
 * @val: a QmiWdsTechnologyPreference.
 *
 * Gets the nickname string for the #QmiWdsTechnologyPreference specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_technology_preference_get_string (QmiWdsTechnologyPreference val)
{
    guint i;

    for (i = 0; qmi_wds_technology_preference_values[i].value_nick; i++) {
        if (val == qmi_wds_technology_preference_values[i].value)
            return qmi_wds_technology_preference_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_TECHNOLOGY_PREFERENCE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_TECHNOLOGY_PREFERENCE_IS_FLAGS__
/**
 * qmi_wds_technology_preference_build_string_from_mask:
 * @mask: bitmask of QmiWdsTechnologyPreference values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsTechnologyPreference in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_technology_preference_build_string_from_mask (QmiWdsTechnologyPreference mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_technology_preference_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_technology_preference_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_technology_preference_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_technology_preference_values[i].value) {
            guint c;
            gulong number = qmi_wds_technology_preference_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_technology_preference_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_TECHNOLOGY_PREFERENCE_IS_FLAGS__ */

static const GEnumValue qmi_wds_extended_technology_preference_values[] = {
    { QMI_WDS_EXTENDED_TECHNOLOGY_PREFERENCE_CDMA, "QMI_WDS_EXTENDED_TECHNOLOGY_PREFERENCE_CDMA", "cdma" },
    { QMI_WDS_EXTENDED_TECHNOLOGY_PREFERENCE_UMTS, "QMI_WDS_EXTENDED_TECHNOLOGY_PREFERENCE_UMTS", "umts" },
    { QMI_WDS_EXTENDED_TECHNOLOGY_PREFERENCE_EPC, "QMI_WDS_EXTENDED_TECHNOLOGY_PREFERENCE_EPC", "epc" },
    { QMI_WDS_EXTENDED_TECHNOLOGY_PREFERENCE_EMBMS, "QMI_WDS_EXTENDED_TECHNOLOGY_PREFERENCE_EMBMS", "embms" },
    { QMI_WDS_EXTENDED_TECHNOLOGY_PREFERENCE_MODEM_LINK_LOCAL, "QMI_WDS_EXTENDED_TECHNOLOGY_PREFERENCE_MODEM_LINK_LOCAL", "modem-link-local" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_extended_technology_preference_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWdsExtendedTechnologyPreference"),
                                      qmi_wds_extended_technology_preference_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_EXTENDED_TECHNOLOGY_PREFERENCE_IS_ENUM__
/**
 * qmi_wds_extended_technology_preference_get_string:
 * @val: a QmiWdsExtendedTechnologyPreference.
 *
 * Gets the nickname string for the #QmiWdsExtendedTechnologyPreference specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_extended_technology_preference_get_string (QmiWdsExtendedTechnologyPreference val)
{
    guint i;

    for (i = 0; qmi_wds_extended_technology_preference_values[i].value_nick; i++) {
        if (val == qmi_wds_extended_technology_preference_values[i].value)
            return qmi_wds_extended_technology_preference_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_EXTENDED_TECHNOLOGY_PREFERENCE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_EXTENDED_TECHNOLOGY_PREFERENCE_IS_FLAGS__
/**
 * qmi_wds_extended_technology_preference_build_string_from_mask:
 * @mask: bitmask of QmiWdsExtendedTechnologyPreference values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsExtendedTechnologyPreference in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_extended_technology_preference_build_string_from_mask (QmiWdsExtendedTechnologyPreference mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_extended_technology_preference_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_extended_technology_preference_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_extended_technology_preference_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_extended_technology_preference_values[i].value) {
            guint c;
            gulong number = qmi_wds_extended_technology_preference_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_extended_technology_preference_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_EXTENDED_TECHNOLOGY_PREFERENCE_IS_FLAGS__ */

static const GEnumValue qmi_wds_call_type_values[] = {
    { QMI_WDS_CALL_TYPE_LAPTOP, "QMI_WDS_CALL_TYPE_LAPTOP", "laptop" },
    { QMI_WDS_CALL_TYPE_EMBEDDED, "QMI_WDS_CALL_TYPE_EMBEDDED", "embedded" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_call_type_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWdsCallType"),
                                      qmi_wds_call_type_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_CALL_TYPE_IS_ENUM__
/**
 * qmi_wds_call_type_get_string:
 * @val: a QmiWdsCallType.
 *
 * Gets the nickname string for the #QmiWdsCallType specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_call_type_get_string (QmiWdsCallType val)
{
    guint i;

    for (i = 0; qmi_wds_call_type_values[i].value_nick; i++) {
        if (val == qmi_wds_call_type_values[i].value)
            return qmi_wds_call_type_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_CALL_TYPE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_CALL_TYPE_IS_FLAGS__
/**
 * qmi_wds_call_type_build_string_from_mask:
 * @mask: bitmask of QmiWdsCallType values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsCallType in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_call_type_build_string_from_mask (QmiWdsCallType mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_call_type_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_call_type_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_call_type_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_call_type_values[i].value) {
            guint c;
            gulong number = qmi_wds_call_type_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_call_type_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_CALL_TYPE_IS_FLAGS__ */

static const GEnumValue qmi_wds_call_end_reason_values[] = {
    { QMI_WDS_CALL_END_REASON_GENERIC_UNSPECIFIED, "QMI_WDS_CALL_END_REASON_GENERIC_UNSPECIFIED", "generic-unspecified" },
    { QMI_WDS_CALL_END_REASON_GENERIC_CLIENT_END, "QMI_WDS_CALL_END_REASON_GENERIC_CLIENT_END", "generic-client-end" },
    { QMI_WDS_CALL_END_REASON_GENERIC_NO_SERVICE, "QMI_WDS_CALL_END_REASON_GENERIC_NO_SERVICE", "generic-no-service" },
    { QMI_WDS_CALL_END_REASON_GENERIC_FADE, "QMI_WDS_CALL_END_REASON_GENERIC_FADE", "generic-fade" },
    { QMI_WDS_CALL_END_REASON_GENERIC_RELEASE_NORMAL, "QMI_WDS_CALL_END_REASON_GENERIC_RELEASE_NORMAL", "generic-release-normal" },
    { QMI_WDS_CALL_END_REASON_GENERIC_ACCESS_ATTEMPT_IN_PROGRESS, "QMI_WDS_CALL_END_REASON_GENERIC_ACCESS_ATTEMPT_IN_PROGRESS", "generic-access-attempt-in-progress" },
    { QMI_WDS_CALL_END_REASON_GENERIC_ACCESS_FAILURE, "QMI_WDS_CALL_END_REASON_GENERIC_ACCESS_FAILURE", "generic-access-failure" },
    { QMI_WDS_CALL_END_REASON_GENERIC_REDIRECTION_OR_HANDOFF, "QMI_WDS_CALL_END_REASON_GENERIC_REDIRECTION_OR_HANDOFF", "generic-redirection-or-handoff" },
    { QMI_WDS_CALL_END_REASON_GENERIC_CLOSE_IN_PROGRESS, "QMI_WDS_CALL_END_REASON_GENERIC_CLOSE_IN_PROGRESS", "generic-close-in-progress" },
    { QMI_WDS_CALL_END_REASON_GENERIC_AUTHENTICATION_FAILED, "QMI_WDS_CALL_END_REASON_GENERIC_AUTHENTICATION_FAILED", "generic-authentication-failed" },
    { QMI_WDS_CALL_END_REASON_GENERIC_INTERNAL_ERROR, "QMI_WDS_CALL_END_REASON_GENERIC_INTERNAL_ERROR", "generic-internal-error" },
    { QMI_WDS_CALL_END_REASON_CDMA_LOCK, "QMI_WDS_CALL_END_REASON_CDMA_LOCK", "cdma-lock" },
    { QMI_WDS_CALL_END_REASON_CDMA_INTERCEPT, "QMI_WDS_CALL_END_REASON_CDMA_INTERCEPT", "cdma-intercept" },
    { QMI_WDS_CALL_END_REASON_CDMA_REORDER, "QMI_WDS_CALL_END_REASON_CDMA_REORDER", "cdma-reorder" },
    { QMI_WDS_CALL_END_REASON_CDMA_RELEASE_SO_REJECT, "QMI_WDS_CALL_END_REASON_CDMA_RELEASE_SO_REJECT", "cdma-release-so-reject" },
    { QMI_WDS_CALL_END_REASON_CDMA_INCOMING_CALL, "QMI_WDS_CALL_END_REASON_CDMA_INCOMING_CALL", "cdma-incoming-call" },
    { QMI_WDS_CALL_END_REASON_CDMA_ALERT_STOP, "QMI_WDS_CALL_END_REASON_CDMA_ALERT_STOP", "cdma-alert-stop" },
    { QMI_WDS_CALL_END_REASON_CDMA_ACTIVATION, "QMI_WDS_CALL_END_REASON_CDMA_ACTIVATION", "cdma-activation" },
    { QMI_WDS_CALL_END_REASON_CDMA_MAX_ACCESS_PROBES, "QMI_WDS_CALL_END_REASON_CDMA_MAX_ACCESS_PROBES", "cdma-max-access-probes" },
    { QMI_WDS_CALL_END_REASON_CDMA_CCS_NOT_SUPPORTED_BY_BS, "QMI_WDS_CALL_END_REASON_CDMA_CCS_NOT_SUPPORTED_BY_BS", "cdma-ccs-not-supported-by-bs" },
    { QMI_WDS_CALL_END_REASON_CDMA_NO_RESPONSE_FROM_BS, "QMI_WDS_CALL_END_REASON_CDMA_NO_RESPONSE_FROM_BS", "cdma-no-response-from-bs" },
    { QMI_WDS_CALL_END_REASON_CDMA_REJECTED_BY_BS, "QMI_WDS_CALL_END_REASON_CDMA_REJECTED_BY_BS", "cdma-rejected-by-bs" },
    { QMI_WDS_CALL_END_REASON_CDMA_INCOMPATIBLE, "QMI_WDS_CALL_END_REASON_CDMA_INCOMPATIBLE", "cdma-incompatible" },
    { QMI_WDS_CALL_END_REASON_CDMA_ALREADY_IN_TC, "QMI_WDS_CALL_END_REASON_CDMA_ALREADY_IN_TC", "cdma-already-in-tc" },
    { QMI_WDS_CALL_END_REASON_CDMA_USER_CALL_ORIGINATED_DURING_GPS, "QMI_WDS_CALL_END_REASON_CDMA_USER_CALL_ORIGINATED_DURING_GPS", "cdma-user-call-originated-during-gps" },
    { QMI_WDS_CALL_END_REASON_CDMA_USER_CALL_ORIGINATED_DURING_SMS, "QMI_WDS_CALL_END_REASON_CDMA_USER_CALL_ORIGINATED_DURING_SMS", "cdma-user-call-originated-during-sms" },
    { QMI_WDS_CALL_END_REASON_CDMA_NO_SERVICE, "QMI_WDS_CALL_END_REASON_CDMA_NO_SERVICE", "cdma-no-service" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_CONFERENCE_FAILED, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_CONFERENCE_FAILED", "gsm-wcdma-conference-failed" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_INCOMING_REJECTED, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_INCOMING_REJECTED", "gsm-wcdma-incoming-rejected" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_NO_SERVICE, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_NO_SERVICE", "gsm-wcdma-no-service" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_NETWORK_END, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_NETWORK_END", "gsm-wcdma-network-end" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_LLC_SNDCP_FAILURE, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_LLC_SNDCP_FAILURE", "gsm-wcdma-llc-sndcp-failure" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_INSUFFICIENT_RESOURCES, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_INSUFFICIENT_RESOURCES", "gsm-wcdma-insufficient-resources" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_OPTION_TEMPORARILY_OUT_OF_ORDER, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_OPTION_TEMPORARILY_OUT_OF_ORDER", "gsm-wcdma-option-temporarily-out-of-order" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_NSAPI_ALREADY_USED, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_NSAPI_ALREADY_USED", "gsm-wcdma-nsapi-already-used" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_REGULAR_DEACTIVATION, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_REGULAR_DEACTIVATION", "gsm-wcdma-regular-deactivation" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_NETWORK_FAILURE, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_NETWORK_FAILURE", "gsm-wcdma-network-failure" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_REATTACH_REQUIRED, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_REATTACH_REQUIRED", "gsm-wcdma-reattach-required" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_PROTOCOL_ERROR, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_PROTOCOL_ERROR", "gsm-wcdma-protocol-error" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_OPERATOR_DETERMINED_BARRING, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_OPERATOR_DETERMINED_BARRING", "gsm-wcdma-operator-determined-barring" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_UNKNOWN_APN, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_UNKNOWN_APN", "gsm-wcdma-unknown-apn" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_UNKNOWN_PDP, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_UNKNOWN_PDP", "gsm-wcdma-unknown-pdp" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_GGSN_REJECT, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_GGSN_REJECT", "gsm-wcdma-ggsn-reject" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_ACTIVATION_REJECT, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_ACTIVATION_REJECT", "gsm-wcdma-activation-reject" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_OPTION_NOT_SUPPORTED, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_OPTION_NOT_SUPPORTED", "gsm-wcdma-option-not-supported" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_OPTION_UNSUBSCRIBED, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_OPTION_UNSUBSCRIBED", "gsm-wcdma-option-unsubscribed" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_QOS_NOT_ACCEPTED, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_QOS_NOT_ACCEPTED", "gsm-wcdma-qos-not-accepted" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_TFT_SEMANTIC_ERROR, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_TFT_SEMANTIC_ERROR", "gsm-wcdma-tft-semantic-error" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_TFT_SYNTAX_ERROR, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_TFT_SYNTAX_ERROR", "gsm-wcdma-tft-syntax-error" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_UNKNOWN_PDP_CONTEXT, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_UNKNOWN_PDP_CONTEXT", "gsm-wcdma-unknown-pdp-context" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_FILTER_SEMANTIC_ERROR, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_FILTER_SEMANTIC_ERROR", "gsm-wcdma-filter-semantic-error" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_FILTER_SYNTAX_ERROR, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_FILTER_SYNTAX_ERROR", "gsm-wcdma-filter-syntax-error" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_PDP_WITHOUT_ACTIVE_TFT, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_PDP_WITHOUT_ACTIVE_TFT", "gsm-wcdma-pdp-without-active-tft" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_INVALID_TRANSACTION_ID, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_INVALID_TRANSACTION_ID", "gsm-wcdma-invalid-transaction-id" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_MESSAGE_INCORRECT_SEMANTIC, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_MESSAGE_INCORRECT_SEMANTIC", "gsm-wcdma-message-incorrect-semantic" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_INVALID_MANDATORY_INFO, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_INVALID_MANDATORY_INFO", "gsm-wcdma-invalid-mandatory-info" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_MESSAGE_TYPE_UNSUPPORTED, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_MESSAGE_TYPE_UNSUPPORTED", "gsm-wcdma-message-type-unsupported" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_MESSAGE_TYPE_NONCOMPATIBLE_STATE, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_MESSAGE_TYPE_NONCOMPATIBLE_STATE", "gsm-wcdma-message-type-noncompatible-state" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_UNKNOWN_INFO_ELEMENT, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_UNKNOWN_INFO_ELEMENT", "gsm-wcdma-unknown-info-element" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_CONDITIONAL_IE_ERROR, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_CONDITIONAL_IE_ERROR", "gsm-wcdma-conditional-ie-error" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_MESSAGE_AND_PROTOCOL_STATE_UNCOMPATIBLE, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_MESSAGE_AND_PROTOCOL_STATE_UNCOMPATIBLE", "gsm-wcdma-message-and-protocol-state-uncompatible" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_APN_TYPE_CONFLICT, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_APN_TYPE_CONFLICT", "gsm-wcdma-apn-type-conflict" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_NO_GPRS_CONTEXT, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_NO_GPRS_CONTEXT", "gsm-wcdma-no-gprs-context" },
    { QMI_WDS_CALL_END_REASON_GSM_WCDMA_FEATURE_NOT_SUPPORTED, "QMI_WDS_CALL_END_REASON_GSM_WCDMA_FEATURE_NOT_SUPPORTED", "gsm-wcdma-feature-not-supported" },
    { QMI_WDS_CALL_END_REASON_EVDO_CONNECTION_DENY_GENERAL_OR_BUSY, "QMI_WDS_CALL_END_REASON_EVDO_CONNECTION_DENY_GENERAL_OR_BUSY", "evdo-connection-deny-general-or-busy" },
    { QMI_WDS_CALL_END_REASON_EVDO_CONNECTION_DENY_BILLING_OR_AUTHENTICATION_FAILURE, "QMI_WDS_CALL_END_REASON_EVDO_CONNECTION_DENY_BILLING_OR_AUTHENTICATION_FAILURE", "evdo-connection-deny-billing-or-authentication-failure" },
    { QMI_WDS_CALL_END_REASON_EVDO_HDR_CHANGE, "QMI_WDS_CALL_END_REASON_EVDO_HDR_CHANGE", "evdo-hdr-change" },
    { QMI_WDS_CALL_END_REASON_EVDO_HDR_EXIT, "QMI_WDS_CALL_END_REASON_EVDO_HDR_EXIT", "evdo-hdr-exit" },
    { QMI_WDS_CALL_END_REASON_EVDO_HDR_NO_SESSION, "QMI_WDS_CALL_END_REASON_EVDO_HDR_NO_SESSION", "evdo-hdr-no-session" },
    { QMI_WDS_CALL_END_REASON_EVDO_HDR_ORIGINATION_DURING_GPS_FIX, "QMI_WDS_CALL_END_REASON_EVDO_HDR_ORIGINATION_DURING_GPS_FIX", "evdo-hdr-origination-during-gps-fix" },
    { QMI_WDS_CALL_END_REASON_EVDO_HDR_CONNECTION_SETUP_TIMEOUT, "QMI_WDS_CALL_END_REASON_EVDO_HDR_CONNECTION_SETUP_TIMEOUT", "evdo-hdr-connection-setup-timeout" },
    { QMI_WDS_CALL_END_REASON_EVDO_HDR_RELEASED_BY_CM, "QMI_WDS_CALL_END_REASON_EVDO_HDR_RELEASED_BY_CM", "evdo-hdr-released-by-cm" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_call_end_reason_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWdsCallEndReason"),
                                      qmi_wds_call_end_reason_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_CALL_END_REASON_IS_ENUM__
/**
 * qmi_wds_call_end_reason_get_string:
 * @val: a QmiWdsCallEndReason.
 *
 * Gets the nickname string for the #QmiWdsCallEndReason specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_call_end_reason_get_string (QmiWdsCallEndReason val)
{
    guint i;

    for (i = 0; qmi_wds_call_end_reason_values[i].value_nick; i++) {
        if (val == qmi_wds_call_end_reason_values[i].value)
            return qmi_wds_call_end_reason_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_CALL_END_REASON_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_CALL_END_REASON_IS_FLAGS__
/**
 * qmi_wds_call_end_reason_build_string_from_mask:
 * @mask: bitmask of QmiWdsCallEndReason values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsCallEndReason in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_call_end_reason_build_string_from_mask (QmiWdsCallEndReason mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_call_end_reason_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_call_end_reason_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_call_end_reason_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_call_end_reason_values[i].value) {
            guint c;
            gulong number = qmi_wds_call_end_reason_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_call_end_reason_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_CALL_END_REASON_IS_FLAGS__ */

static const GEnumValue qmi_wds_verbose_call_end_reason_type_values[] = {
    { QMI_WDS_VERBOSE_CALL_END_REASON_TYPE_MIP, "QMI_WDS_VERBOSE_CALL_END_REASON_TYPE_MIP", "mip" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_TYPE_INTERNAL, "QMI_WDS_VERBOSE_CALL_END_REASON_TYPE_INTERNAL", "internal" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_TYPE_CM, "QMI_WDS_VERBOSE_CALL_END_REASON_TYPE_CM", "cm" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_TYPE_3GPP, "QMI_WDS_VERBOSE_CALL_END_REASON_TYPE_3GPP", "3gpp" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_TYPE_PPP, "QMI_WDS_VERBOSE_CALL_END_REASON_TYPE_PPP", "ppp" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_TYPE_EHRPD, "QMI_WDS_VERBOSE_CALL_END_REASON_TYPE_EHRPD", "ehrpd" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_TYPE_IPV6, "QMI_WDS_VERBOSE_CALL_END_REASON_TYPE_IPV6", "ipv6" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_verbose_call_end_reason_type_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWdsVerboseCallEndReasonType"),
                                      qmi_wds_verbose_call_end_reason_type_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_VERBOSE_CALL_END_REASON_TYPE_IS_ENUM__
/**
 * qmi_wds_verbose_call_end_reason_type_get_string:
 * @val: a QmiWdsVerboseCallEndReasonType.
 *
 * Gets the nickname string for the #QmiWdsVerboseCallEndReasonType specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_verbose_call_end_reason_type_get_string (QmiWdsVerboseCallEndReasonType val)
{
    guint i;

    for (i = 0; qmi_wds_verbose_call_end_reason_type_values[i].value_nick; i++) {
        if (val == qmi_wds_verbose_call_end_reason_type_values[i].value)
            return qmi_wds_verbose_call_end_reason_type_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_VERBOSE_CALL_END_REASON_TYPE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_VERBOSE_CALL_END_REASON_TYPE_IS_FLAGS__
/**
 * qmi_wds_verbose_call_end_reason_type_build_string_from_mask:
 * @mask: bitmask of QmiWdsVerboseCallEndReasonType values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsVerboseCallEndReasonType in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_verbose_call_end_reason_type_build_string_from_mask (QmiWdsVerboseCallEndReasonType mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_verbose_call_end_reason_type_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_verbose_call_end_reason_type_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_verbose_call_end_reason_type_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_verbose_call_end_reason_type_values[i].value) {
            guint c;
            gulong number = qmi_wds_verbose_call_end_reason_type_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_verbose_call_end_reason_type_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_VERBOSE_CALL_END_REASON_TYPE_IS_FLAGS__ */

static const GEnumValue qmi_wds_verbose_call_end_reason_mip_values[] = {
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_ERROR_REASON_UNKNOWN, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_ERROR_REASON_UNKNOWN", "error-reason-unknown" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_REASON_UNSPECIFIED, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_REASON_UNSPECIFIED", "fa-error-reason-unspecified" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_ADMINISTRATIVELY_PROHIBITED, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_ADMINISTRATIVELY_PROHIBITED", "fa-error-administratively-prohibited" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_INSUFFICIENT_RESOURCES, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_INSUFFICIENT_RESOURCES", "fa-error-insufficient-resources" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_MOBILE_NODE_AUTHENTICATION_FAILURE, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_MOBILE_NODE_AUTHENTICATION_FAILURE", "fa-error-mobile-node-authentication-failure" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_HA_AUTHENTICATION_FAILURE, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_HA_AUTHENTICATION_FAILURE", "fa-error-ha-authentication-failure" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_REQUESTED_LIFETIME_TOO_LONG, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_REQUESTED_LIFETIME_TOO_LONG", "fa-error-requested-lifetime-too-long" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_MALFORMED_REQUEST, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_MALFORMED_REQUEST", "fa-error-malformed-request" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_MALFORMED_REPLY, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_MALFORMED_REPLY", "fa-error-malformed-reply" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_ENCAPSULATION_UNAVAILABLE, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_ENCAPSULATION_UNAVAILABLE", "fa-error-encapsulation-unavailable" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_VJHC_UNAVAILABLE, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_VJHC_UNAVAILABLE", "fa-error-vjhc-unavailable" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_REVERSE_TUNNEL_UNAVAILABLE, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_REVERSE_TUNNEL_UNAVAILABLE", "fa-error-reverse-tunnel-unavailable" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_REVERSE_TUNNEL_MANDATORY_AND_T_BIT_NOT_SET, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_REVERSE_TUNNEL_MANDATORY_AND_T_BIT_NOT_SET", "fa-error-reverse-tunnel-mandatory-and-t-bit-not-set" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_DELIVERY_STYLE_NOT_SUPPORTED, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_DELIVERY_STYLE_NOT_SUPPORTED", "fa-error-delivery-style-not-supported" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_MISSING_NAI, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_MISSING_NAI", "fa-error-missing-nai" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_MISSING_HA, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_MISSING_HA", "fa-error-missing-ha" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_MISSING_HOME_ADDRESS, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_MISSING_HOME_ADDRESS", "fa-error-missing-home-address" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_UNKNOWN_CHALLENGE, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_UNKNOWN_CHALLENGE", "fa-error-unknown-challenge" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_MISSING_CHALLENGE, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_MISSING_CHALLENGE", "fa-error-missing-challenge" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_STALE_CHALLENGE, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_FA_ERROR_STALE_CHALLENGE", "fa-error-stale-challenge" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_REASON_UNSPECIFIED, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_REASON_UNSPECIFIED", "ha-error-reason-unspecified" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_ADMINISTRATIVELY_PROHIBITED, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_ADMINISTRATIVELY_PROHIBITED", "ha-error-administratively-prohibited" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_INSUFFICIENT_RESOURCES, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_INSUFFICIENT_RESOURCES", "ha-error-insufficient-resources" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_MOBILE_NODE_AUTHENTICATION_FAILURE, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_MOBILE_NODE_AUTHENTICATION_FAILURE", "ha-error-mobile-node-authentication-failure" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_FA_AUTHENTICATION_FAILURE, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_FA_AUTHENTICATION_FAILURE", "ha-error-fa-authentication-failure" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_REGISTRATION_ID_MISMATCH, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_REGISTRATION_ID_MISMATCH", "ha-error-registration-id-mismatch" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_MALFORMED_REQUEST, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_MALFORMED_REQUEST", "ha-error-malformed-request" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_UNKNOWN_HA_ADDRESS, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_UNKNOWN_HA_ADDRESS", "ha-error-unknown-ha-address" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_REVERSE_TUNNEL_UNAVAILABLE, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_REVERSE_TUNNEL_UNAVAILABLE", "ha-error-reverse-tunnel-unavailable" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_REVERSE_TUNNEL_MANDATORY_AND_T_BIT_NOT_SET, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_REVERSE_TUNNEL_MANDATORY_AND_T_BIT_NOT_SET", "ha-error-reverse-tunnel-mandatory-and-t-bit-not-set" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_ENCAPSULATION_UNAVAILABLE, "QMI_WDS_VERBOSE_CALL_END_REASON_MIP_HA_ERROR_ENCAPSULATION_UNAVAILABLE", "ha-error-encapsulation-unavailable" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_verbose_call_end_reason_mip_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWdsVerboseCallEndReasonMip"),
                                      qmi_wds_verbose_call_end_reason_mip_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_VERBOSE_CALL_END_REASON_MIP_IS_ENUM__
/**
 * qmi_wds_verbose_call_end_reason_mip_get_string:
 * @val: a QmiWdsVerboseCallEndReasonMip.
 *
 * Gets the nickname string for the #QmiWdsVerboseCallEndReasonMip specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_verbose_call_end_reason_mip_get_string (QmiWdsVerboseCallEndReasonMip val)
{
    guint i;

    for (i = 0; qmi_wds_verbose_call_end_reason_mip_values[i].value_nick; i++) {
        if (val == qmi_wds_verbose_call_end_reason_mip_values[i].value)
            return qmi_wds_verbose_call_end_reason_mip_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_VERBOSE_CALL_END_REASON_MIP_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_VERBOSE_CALL_END_REASON_MIP_IS_FLAGS__
/**
 * qmi_wds_verbose_call_end_reason_mip_build_string_from_mask:
 * @mask: bitmask of QmiWdsVerboseCallEndReasonMip values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsVerboseCallEndReasonMip in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_verbose_call_end_reason_mip_build_string_from_mask (QmiWdsVerboseCallEndReasonMip mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_verbose_call_end_reason_mip_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_verbose_call_end_reason_mip_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_verbose_call_end_reason_mip_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_verbose_call_end_reason_mip_values[i].value) {
            guint c;
            gulong number = qmi_wds_verbose_call_end_reason_mip_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_verbose_call_end_reason_mip_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_VERBOSE_CALL_END_REASON_MIP_IS_FLAGS__ */

static const GEnumValue qmi_wds_verbose_call_end_reason_internal_values[] = {
    { QMI_WDS_VERBOSE_CALL_END_REASON_INTERNAL_ERROR, "QMI_WDS_VERBOSE_CALL_END_REASON_INTERNAL_ERROR", "error" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_INTERNAL_CALL_ENDED, "QMI_WDS_VERBOSE_CALL_END_REASON_INTERNAL_CALL_ENDED", "call-ended" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_INTERNAL_UNKNOWN_INTERNAL_CAUSE, "QMI_WDS_VERBOSE_CALL_END_REASON_INTERNAL_UNKNOWN_INTERNAL_CAUSE", "unknown-internal-cause" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_INTERNAL_UNKNOWN_CAUSE, "QMI_WDS_VERBOSE_CALL_END_REASON_INTERNAL_UNKNOWN_CAUSE", "unknown-cause" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_INTERNAL_CLOSE_IN_PROGRESS, "QMI_WDS_VERBOSE_CALL_END_REASON_INTERNAL_CLOSE_IN_PROGRESS", "close-in-progress" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_INTERNAL_NETWORK_INITIATED_TERMINATION, "QMI_WDS_VERBOSE_CALL_END_REASON_INTERNAL_NETWORK_INITIATED_TERMINATION", "network-initiated-termination" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_INTERNAL_APP_PREEMPTED, "QMI_WDS_VERBOSE_CALL_END_REASON_INTERNAL_APP_PREEMPTED", "app-preempted" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_verbose_call_end_reason_internal_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWdsVerboseCallEndReasonInternal"),
                                      qmi_wds_verbose_call_end_reason_internal_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_VERBOSE_CALL_END_REASON_INTERNAL_IS_ENUM__
/**
 * qmi_wds_verbose_call_end_reason_internal_get_string:
 * @val: a QmiWdsVerboseCallEndReasonInternal.
 *
 * Gets the nickname string for the #QmiWdsVerboseCallEndReasonInternal specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_verbose_call_end_reason_internal_get_string (QmiWdsVerboseCallEndReasonInternal val)
{
    guint i;

    for (i = 0; qmi_wds_verbose_call_end_reason_internal_values[i].value_nick; i++) {
        if (val == qmi_wds_verbose_call_end_reason_internal_values[i].value)
            return qmi_wds_verbose_call_end_reason_internal_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_VERBOSE_CALL_END_REASON_INTERNAL_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_VERBOSE_CALL_END_REASON_INTERNAL_IS_FLAGS__
/**
 * qmi_wds_verbose_call_end_reason_internal_build_string_from_mask:
 * @mask: bitmask of QmiWdsVerboseCallEndReasonInternal values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsVerboseCallEndReasonInternal in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_verbose_call_end_reason_internal_build_string_from_mask (QmiWdsVerboseCallEndReasonInternal mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_verbose_call_end_reason_internal_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_verbose_call_end_reason_internal_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_verbose_call_end_reason_internal_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_verbose_call_end_reason_internal_values[i].value) {
            guint c;
            gulong number = qmi_wds_verbose_call_end_reason_internal_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_verbose_call_end_reason_internal_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_VERBOSE_CALL_END_REASON_INTERNAL_IS_FLAGS__ */

static const GEnumValue qmi_wds_verbose_call_end_reason_cm_values[] = {
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_CDMA_LOCK, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_CDMA_LOCK", "cdma-lock" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_INTERCEPT, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_INTERCEPT", "intercept" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_REORDER, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_REORDER", "reorder" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_RELEASE_SO_REJECT, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_RELEASE_SO_REJECT", "release-so-reject" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_INCOMING_CALL, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_INCOMING_CALL", "incoming-call" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_ALERT_STOP, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_ALERT_STOP", "alert-stop" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_ACTIVATION, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_ACTIVATION", "activation" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_MAX_ACCESS_PROBES, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_MAX_ACCESS_PROBES", "max-access-probes" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_CCS_NOT_SUPPORTED_BY_BS, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_CCS_NOT_SUPPORTED_BY_BS", "ccs-not-supported-by-bs" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_NO_RESPONSE_FROM_BS, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_NO_RESPONSE_FROM_BS", "no-response-from-bs" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_REJECTED_BY_BS, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_REJECTED_BY_BS", "rejected-by-bs" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_INCOMPATIBLE, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_INCOMPATIBLE", "incompatible" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_ALREADY_IN_TC, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_ALREADY_IN_TC", "already-in-tc" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_USER_CALL_ORIGINATED_DURING_GPS, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_USER_CALL_ORIGINATED_DURING_GPS", "user-call-originated-during-gps" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_USER_CALL_ORIGINATED_DURING_SMS, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_USER_CALL_ORIGINATED_DURING_SMS", "user-call-originated-during-sms" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_NO_CDMA_SERVICE, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_NO_CDMA_SERVICE", "no-cdma-service" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_RETRY_ORDER, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_RETRY_ORDER", "retry-order" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_CONFIGURATION_FAILED, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_CONFIGURATION_FAILED", "configuration-failed" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_INCOMING_REJECTED, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_INCOMING_REJECTED", "incoming-rejected" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_NO_GATEWAY_SERVICE, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_NO_GATEWAY_SERVICE", "no-gateway-service" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_NO_GPRS_CONTEXT, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_NO_GPRS_CONTEXT", "no-gprs-context" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_ILLEGAL_MS, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_ILLEGAL_MS", "illegal-ms" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_ILLEGAL_ME, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_ILLEGAL_ME", "illegal-me" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_GPRS_AND_NON_GPRS_SERVICES_NOT_ALLOWED, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_GPRS_AND_NON_GPRS_SERVICES_NOT_ALLOWED", "gprs-and-non-gprs-services-not-allowed" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_GPRS_SERVICES_NOT_ALLOWED, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_GPRS_SERVICES_NOT_ALLOWED", "gprs-services-not-allowed" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_MS_IDENTITY_NOT_DERIVED_BY_THE_NETWORK, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_MS_IDENTITY_NOT_DERIVED_BY_THE_NETWORK", "ms-identity-not-derived-by-the-network" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_IMPLICITLY_DETACHED, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_IMPLICITLY_DETACHED", "implicitly-detached" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_PLMN_NOT_ALLOWED, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_PLMN_NOT_ALLOWED", "plmn-not-allowed" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_LA_NOT_ALLOWED, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_LA_NOT_ALLOWED", "la-not-allowed" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_GPRS_SERVICES_NOT_ALLOWED_IN_PLMN, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_GPRS_SERVICES_NOT_ALLOWED_IN_PLMN", "gprs-services-not-allowed-in-plmn" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_PDP_DUPLICATE, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_PDP_DUPLICATE", "pdp-duplicate" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_UE_RAT_CHANGE, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_UE_RAT_CHANGE", "ue-rat-change" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_CONGESTION, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_CONGESTION", "congestion" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_NO_PDP_CONTEXT_ACTIVATED, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_NO_PDP_CONTEXT_ACTIVATED", "no-pdp-context-activated" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_ACCESS_CLASS_DSAC_REJECTION, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_ACCESS_CLASS_DSAC_REJECTION", "access-class-dsac-rejection" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_CONNECTION_DENY_GENERAL_OR_BUSY, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_CONNECTION_DENY_GENERAL_OR_BUSY", "connection-deny-general-or-busy" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_CONNECTION_DENY_BILLING_OR_AUTHENTICATION_FAILURE, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_CONNECTION_DENY_BILLING_OR_AUTHENTICATION_FAILURE", "connection-deny-billing-or-authentication-failure" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_HDR_CHANGE, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_HDR_CHANGE", "hdr-change" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_HDR_EXIT, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_HDR_EXIT", "hdr-exit" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_HDR_NO_SESSION, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_HDR_NO_SESSION", "hdr-no-session" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_HDR_ORIGINATION_DURING_GPS_FIX, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_HDR_ORIGINATION_DURING_GPS_FIX", "hdr-origination-during-gps-fix" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_HDR_CONNECTION_SETUP_TIMEOUT, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_HDR_CONNECTION_SETUP_TIMEOUT", "hdr-connection-setup-timeout" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_HDR_RELEASED_BY_CM, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_HDR_RELEASED_BY_CM", "hdr-released-by-cm" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_NO_HYBRID_HDR_SERVICE, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_NO_HYBRID_HDR_SERVICE", "no-hybrid-hdr-service" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_CLIENT_END, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_CLIENT_END", "client-end" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_NO_SERVICE, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_NO_SERVICE", "no-service" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_FADE, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_FADE", "fade" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_RELEASE_NORMAL, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_RELEASE_NORMAL", "release-normal" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_ACCESS_ATTEMPT_IN_PROGRESS, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_ACCESS_ATTEMPT_IN_PROGRESS", "access-attempt-in-progress" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_ACCESS_FAILURE, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_ACCESS_FAILURE", "access-failure" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_CM_REDIRECTION_OR_HANDOFF, "QMI_WDS_VERBOSE_CALL_END_REASON_CM_REDIRECTION_OR_HANDOFF", "redirection-or-handoff" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_verbose_call_end_reason_cm_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWdsVerboseCallEndReasonCm"),
                                      qmi_wds_verbose_call_end_reason_cm_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_VERBOSE_CALL_END_REASON_CM_IS_ENUM__
/**
 * qmi_wds_verbose_call_end_reason_cm_get_string:
 * @val: a QmiWdsVerboseCallEndReasonCm.
 *
 * Gets the nickname string for the #QmiWdsVerboseCallEndReasonCm specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_verbose_call_end_reason_cm_get_string (QmiWdsVerboseCallEndReasonCm val)
{
    guint i;

    for (i = 0; qmi_wds_verbose_call_end_reason_cm_values[i].value_nick; i++) {
        if (val == qmi_wds_verbose_call_end_reason_cm_values[i].value)
            return qmi_wds_verbose_call_end_reason_cm_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_VERBOSE_CALL_END_REASON_CM_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_VERBOSE_CALL_END_REASON_CM_IS_FLAGS__
/**
 * qmi_wds_verbose_call_end_reason_cm_build_string_from_mask:
 * @mask: bitmask of QmiWdsVerboseCallEndReasonCm values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsVerboseCallEndReasonCm in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_verbose_call_end_reason_cm_build_string_from_mask (QmiWdsVerboseCallEndReasonCm mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_verbose_call_end_reason_cm_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_verbose_call_end_reason_cm_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_verbose_call_end_reason_cm_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_verbose_call_end_reason_cm_values[i].value) {
            guint c;
            gulong number = qmi_wds_verbose_call_end_reason_cm_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_verbose_call_end_reason_cm_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_VERBOSE_CALL_END_REASON_CM_IS_FLAGS__ */

static const GEnumValue qmi_wds_verbose_call_end_reason_3gpp_values[] = {
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_OPERATOR_DETERMINED_BARRING, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_OPERATOR_DETERMINED_BARRING", "operator-determined-barring" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_LLC_SNDCP_FAILURE, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_LLC_SNDCP_FAILURE", "llc-sndcp-failure" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_INSUFFICIENT_RESOURCES, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_INSUFFICIENT_RESOURCES", "insufficient-resources" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_UNKNOWN_APN, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_UNKNOWN_APN", "unknown-apn" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_UNKNOWN_PDP, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_UNKNOWN_PDP", "unknown-pdp" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_AUTHENTICATION_FAILED, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_AUTHENTICATION_FAILED", "authentication-failed" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_GGSN_REJECT, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_GGSN_REJECT", "ggsn-reject" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_ACTIVATION_REJECT, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_ACTIVATION_REJECT", "activation-reject" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_OPTION_NOT_SUPPORTED, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_OPTION_NOT_SUPPORTED", "option-not-supported" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_OPTION_UNSUBSCRIBED, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_OPTION_UNSUBSCRIBED", "option-unsubscribed" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_OPTION_TEMPORARILY_OUT_OF_ORDER, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_OPTION_TEMPORARILY_OUT_OF_ORDER", "option-temporarily-out-of-order" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_NSAPI_ALREADY_USED, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_NSAPI_ALREADY_USED", "nsapi-already-used" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_REGULAR_DEACTIVATION, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_REGULAR_DEACTIVATION", "regular-deactivation" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_QOS_NOT_ACCEPTED, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_QOS_NOT_ACCEPTED", "qos-not-accepted" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_NETWORK_FAILURE, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_NETWORK_FAILURE", "network-failure" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_REATTACH_REQUIRED, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_REATTACH_REQUIRED", "reattach-required" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_FEATURE_NOT_SUPPORTED, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_FEATURE_NOT_SUPPORTED", "feature-not-supported" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_TFT_SEMANTIC_ERROR, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_TFT_SEMANTIC_ERROR", "tft-semantic-error" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_TFT_SYNTAX_ERROR, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_TFT_SYNTAX_ERROR", "tft-syntax-error" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_UNKNOWN_PDP_CONTEXT, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_UNKNOWN_PDP_CONTEXT", "unknown-pdp-context" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_FILTER_SEMANTIC_ERROR, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_FILTER_SEMANTIC_ERROR", "filter-semantic-error" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_FILTER_SYNTAX_ERROR, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_FILTER_SYNTAX_ERROR", "filter-syntax-error" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_PDP_WITHOUT_ACTIVE_TFT, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_PDP_WITHOUT_ACTIVE_TFT", "pdp-without-active-tft" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_IPV4_ONLY_ALLOWED, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_IPV4_ONLY_ALLOWED", "ipv4-only-allowed" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_IPV6_ONLY_ALLOWED, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_IPV6_ONLY_ALLOWED", "ipv6-only-allowed" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_SINGLE_ADDRESS_BEARER_ONLY, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_SINGLE_ADDRESS_BEARER_ONLY", "single-address-bearer-only" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_ESM_INFO_NOT_RECEIVED, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_ESM_INFO_NOT_RECEIVED", "esm-info-not-received" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_PDN_CONNECTION_DOES_NOT_EXIST, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_PDN_CONNECTION_DOES_NOT_EXIST", "pdn-connection-does-not-exist" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_MULTIPLE_CONNECTION_TO_SAME_PDN_NOT_ALLOWED, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_MULTIPLE_CONNECTION_TO_SAME_PDN_NOT_ALLOWED", "multiple-connection-to-same-pdn-not-allowed" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_INVALID_TRANSACTION_ID, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_INVALID_TRANSACTION_ID", "invalid-transaction-id" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_MESSAGE_INCORRECT_SEMANTIC, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_MESSAGE_INCORRECT_SEMANTIC", "message-incorrect-semantic" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_INVALID_MANDATORY_INFO, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_INVALID_MANDATORY_INFO", "invalid-mandatory-info" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_MESSAGE_TYPE_UNSUPPORTED, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_MESSAGE_TYPE_UNSUPPORTED", "message-type-unsupported" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_MESSAGE_TYPE_NONCOMPATIBLE_STATE, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_MESSAGE_TYPE_NONCOMPATIBLE_STATE", "message-type-noncompatible-state" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_UNKNOWN_INFO_ELEMENT, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_UNKNOWN_INFO_ELEMENT", "unknown-info-element" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_CONDITIONAL_IE_ERROR, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_CONDITIONAL_IE_ERROR", "conditional-ie-error" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_MESSAGE_AND_PROTOCOL_STATE_UNCOMPATIBLE, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_MESSAGE_AND_PROTOCOL_STATE_UNCOMPATIBLE", "message-and-protocol-state-uncompatible" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_PROTOCOL_ERROR, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_PROTOCOL_ERROR", "protocol-error" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_APN_TYPE_CONFLICT, "QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_APN_TYPE_CONFLICT", "apn-type-conflict" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_verbose_call_end_reason_3gpp_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWdsVerboseCallEndReason3gpp"),
                                      qmi_wds_verbose_call_end_reason_3gpp_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_IS_ENUM__
/**
 * qmi_wds_verbose_call_end_reason_3gpp_get_string:
 * @val: a QmiWdsVerboseCallEndReason3gpp.
 *
 * Gets the nickname string for the #QmiWdsVerboseCallEndReason3gpp specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_verbose_call_end_reason_3gpp_get_string (QmiWdsVerboseCallEndReason3gpp val)
{
    guint i;

    for (i = 0; qmi_wds_verbose_call_end_reason_3gpp_values[i].value_nick; i++) {
        if (val == qmi_wds_verbose_call_end_reason_3gpp_values[i].value)
            return qmi_wds_verbose_call_end_reason_3gpp_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_IS_FLAGS__
/**
 * qmi_wds_verbose_call_end_reason_3gpp_build_string_from_mask:
 * @mask: bitmask of QmiWdsVerboseCallEndReason3gpp values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsVerboseCallEndReason3gpp in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_verbose_call_end_reason_3gpp_build_string_from_mask (QmiWdsVerboseCallEndReason3gpp mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_verbose_call_end_reason_3gpp_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_verbose_call_end_reason_3gpp_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_verbose_call_end_reason_3gpp_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_verbose_call_end_reason_3gpp_values[i].value) {
            guint c;
            gulong number = qmi_wds_verbose_call_end_reason_3gpp_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_verbose_call_end_reason_3gpp_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_VERBOSE_CALL_END_REASON_3GPP_IS_FLAGS__ */

static const GEnumValue qmi_wds_verbose_call_end_reason_ppp_values[] = {
    { QMI_WDS_VERBOSE_CALL_END_REASON_PPP_UNKNOWN, "QMI_WDS_VERBOSE_CALL_END_REASON_PPP_UNKNOWN", "unknown" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_PPP_TIMEOUT, "QMI_WDS_VERBOSE_CALL_END_REASON_PPP_TIMEOUT", "timeout" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_PPP_AUTHENTICATION_FAILURE, "QMI_WDS_VERBOSE_CALL_END_REASON_PPP_AUTHENTICATION_FAILURE", "authentication-failure" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_PPP_OPTION_MISMATCH, "QMI_WDS_VERBOSE_CALL_END_REASON_PPP_OPTION_MISMATCH", "option-mismatch" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_PPP_PAP_FAILURE, "QMI_WDS_VERBOSE_CALL_END_REASON_PPP_PAP_FAILURE", "pap-failure" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_PPP_CHAP_FAILURE, "QMI_WDS_VERBOSE_CALL_END_REASON_PPP_CHAP_FAILURE", "chap-failure" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_verbose_call_end_reason_ppp_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWdsVerboseCallEndReasonPpp"),
                                      qmi_wds_verbose_call_end_reason_ppp_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_VERBOSE_CALL_END_REASON_PPP_IS_ENUM__
/**
 * qmi_wds_verbose_call_end_reason_ppp_get_string:
 * @val: a QmiWdsVerboseCallEndReasonPpp.
 *
 * Gets the nickname string for the #QmiWdsVerboseCallEndReasonPpp specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_verbose_call_end_reason_ppp_get_string (QmiWdsVerboseCallEndReasonPpp val)
{
    guint i;

    for (i = 0; qmi_wds_verbose_call_end_reason_ppp_values[i].value_nick; i++) {
        if (val == qmi_wds_verbose_call_end_reason_ppp_values[i].value)
            return qmi_wds_verbose_call_end_reason_ppp_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_VERBOSE_CALL_END_REASON_PPP_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_VERBOSE_CALL_END_REASON_PPP_IS_FLAGS__
/**
 * qmi_wds_verbose_call_end_reason_ppp_build_string_from_mask:
 * @mask: bitmask of QmiWdsVerboseCallEndReasonPpp values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsVerboseCallEndReasonPpp in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_verbose_call_end_reason_ppp_build_string_from_mask (QmiWdsVerboseCallEndReasonPpp mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_verbose_call_end_reason_ppp_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_verbose_call_end_reason_ppp_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_verbose_call_end_reason_ppp_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_verbose_call_end_reason_ppp_values[i].value) {
            guint c;
            gulong number = qmi_wds_verbose_call_end_reason_ppp_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_verbose_call_end_reason_ppp_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_VERBOSE_CALL_END_REASON_PPP_IS_FLAGS__ */

static const GEnumValue qmi_wds_verbose_call_end_reason_ehrpd_values[] = {
    { QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_SUBSCRIPTION_LIMITED_TO_IPV4, "QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_SUBSCRIPTION_LIMITED_TO_IPV4", "subscription-limited-to-ipv4" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_SUBSCRIPTION_LIMITED_TO_IPV6, "QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_SUBSCRIPTION_LIMITED_TO_IPV6", "subscription-limited-to-ipv6" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_TIMEOUT, "QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_TIMEOUT", "vsncp-timeout" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_FAILURE, "QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_FAILURE", "vsncp-failure" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_GENERAL_ERROR, "QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_GENERAL_ERROR", "vsncp-3gpp2-general-error" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_UNAUTHENTICATED_APN, "QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_UNAUTHENTICATED_APN", "vsncp-3gpp2-unauthenticated-apn" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_PDN_LIMIT_EXCEEDED, "QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_PDN_LIMIT_EXCEEDED", "vsncp-3gpp2-pdn-limit-exceeded" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_NO_PDN_GATEWAY, "QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_NO_PDN_GATEWAY", "vsncp-3gpp2-no-pdn-gateway" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_PDN_GATEWAY_UNREACHABLE, "QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_PDN_GATEWAY_UNREACHABLE", "vsncp-3gpp2-pdn-gateway-unreachable" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_PDN_GATEWAY_REJECTED, "QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_PDN_GATEWAY_REJECTED", "vsncp-3gpp2-pdn-gateway-rejected" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_INSUFFICIENT_PARAMETERS, "QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_INSUFFICIENT_PARAMETERS", "vsncp-3gpp2-insufficient-parameters" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_RESOURCE_UNAVAILABLE, "QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_RESOURCE_UNAVAILABLE", "vsncp-3gpp2-resource-unavailable" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_ADMINISTRATIVELY_PROHIBITED, "QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_ADMINISTRATIVELY_PROHIBITED", "vsncp-3gpp2-administratively-prohibited" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_PDN_ID_IN_USE, "QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_PDN_ID_IN_USE", "vsncp-3gpp2-pdn-id-in-use" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_SUBSCRIPTION_LIMITATION, "QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_SUBSCRIPTION_LIMITATION", "vsncp-3gpp2-subscription-limitation" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_PDN_EXISTS_FOR_THIS_APN, "QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_VSNCP_3GPP2_PDN_EXISTS_FOR_THIS_APN", "vsncp-3gpp2-pdn-exists-for-this-apn" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_verbose_call_end_reason_ehrpd_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWdsVerboseCallEndReasonEhrpd"),
                                      qmi_wds_verbose_call_end_reason_ehrpd_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_IS_ENUM__
/**
 * qmi_wds_verbose_call_end_reason_ehrpd_get_string:
 * @val: a QmiWdsVerboseCallEndReasonEhrpd.
 *
 * Gets the nickname string for the #QmiWdsVerboseCallEndReasonEhrpd specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_verbose_call_end_reason_ehrpd_get_string (QmiWdsVerboseCallEndReasonEhrpd val)
{
    guint i;

    for (i = 0; qmi_wds_verbose_call_end_reason_ehrpd_values[i].value_nick; i++) {
        if (val == qmi_wds_verbose_call_end_reason_ehrpd_values[i].value)
            return qmi_wds_verbose_call_end_reason_ehrpd_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_IS_FLAGS__
/**
 * qmi_wds_verbose_call_end_reason_ehrpd_build_string_from_mask:
 * @mask: bitmask of QmiWdsVerboseCallEndReasonEhrpd values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsVerboseCallEndReasonEhrpd in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_verbose_call_end_reason_ehrpd_build_string_from_mask (QmiWdsVerboseCallEndReasonEhrpd mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_verbose_call_end_reason_ehrpd_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_verbose_call_end_reason_ehrpd_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_verbose_call_end_reason_ehrpd_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_verbose_call_end_reason_ehrpd_values[i].value) {
            guint c;
            gulong number = qmi_wds_verbose_call_end_reason_ehrpd_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_verbose_call_end_reason_ehrpd_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_VERBOSE_CALL_END_REASON_EHRPD_IS_FLAGS__ */

static const GEnumValue qmi_wds_verbose_call_end_reason_ipv6_values[] = {
    { QMI_WDS_VERBOSE_CALL_END_REASON_IPV6_PREFIX_UNAVAILABLE, "QMI_WDS_VERBOSE_CALL_END_REASON_IPV6_PREFIX_UNAVAILABLE", "prefix-unavailable" },
    { QMI_WDS_VERBOSE_CALL_END_REASON_IPV6_HRPD_IPV6_DISABLED, "QMI_WDS_VERBOSE_CALL_END_REASON_IPV6_HRPD_IPV6_DISABLED", "hrpd-ipv6-disabled" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_verbose_call_end_reason_ipv6_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWdsVerboseCallEndReasonIpv6"),
                                      qmi_wds_verbose_call_end_reason_ipv6_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_VERBOSE_CALL_END_REASON_IPV6_IS_ENUM__
/**
 * qmi_wds_verbose_call_end_reason_ipv6_get_string:
 * @val: a QmiWdsVerboseCallEndReasonIpv6.
 *
 * Gets the nickname string for the #QmiWdsVerboseCallEndReasonIpv6 specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_verbose_call_end_reason_ipv6_get_string (QmiWdsVerboseCallEndReasonIpv6 val)
{
    guint i;

    for (i = 0; qmi_wds_verbose_call_end_reason_ipv6_values[i].value_nick; i++) {
        if (val == qmi_wds_verbose_call_end_reason_ipv6_values[i].value)
            return qmi_wds_verbose_call_end_reason_ipv6_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_VERBOSE_CALL_END_REASON_IPV6_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_VERBOSE_CALL_END_REASON_IPV6_IS_FLAGS__
/**
 * qmi_wds_verbose_call_end_reason_ipv6_build_string_from_mask:
 * @mask: bitmask of QmiWdsVerboseCallEndReasonIpv6 values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsVerboseCallEndReasonIpv6 in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_verbose_call_end_reason_ipv6_build_string_from_mask (QmiWdsVerboseCallEndReasonIpv6 mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_verbose_call_end_reason_ipv6_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_verbose_call_end_reason_ipv6_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_verbose_call_end_reason_ipv6_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_verbose_call_end_reason_ipv6_values[i].value) {
            guint c;
            gulong number = qmi_wds_verbose_call_end_reason_ipv6_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_verbose_call_end_reason_ipv6_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_VERBOSE_CALL_END_REASON_IPV6_IS_FLAGS__ */

static const GEnumValue qmi_wds_connection_status_values[] = {
    { QMI_WDS_CONNECTION_STATUS_UNKNOWN, "QMI_WDS_CONNECTION_STATUS_UNKNOWN", "unknown" },
    { QMI_WDS_CONNECTION_STATUS_DISCONNECTED, "QMI_WDS_CONNECTION_STATUS_DISCONNECTED", "disconnected" },
    { QMI_WDS_CONNECTION_STATUS_CONNECTED, "QMI_WDS_CONNECTION_STATUS_CONNECTED", "connected" },
    { QMI_WDS_CONNECTION_STATUS_SUSPENDED, "QMI_WDS_CONNECTION_STATUS_SUSPENDED", "suspended" },
    { QMI_WDS_CONNECTION_STATUS_AUTHENTICATING, "QMI_WDS_CONNECTION_STATUS_AUTHENTICATING", "authenticating" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_connection_status_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWdsConnectionStatus"),
                                      qmi_wds_connection_status_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_CONNECTION_STATUS_IS_ENUM__
/**
 * qmi_wds_connection_status_get_string:
 * @val: a QmiWdsConnectionStatus.
 *
 * Gets the nickname string for the #QmiWdsConnectionStatus specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_connection_status_get_string (QmiWdsConnectionStatus val)
{
    guint i;

    for (i = 0; qmi_wds_connection_status_values[i].value_nick; i++) {
        if (val == qmi_wds_connection_status_values[i].value)
            return qmi_wds_connection_status_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_CONNECTION_STATUS_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_CONNECTION_STATUS_IS_FLAGS__
/**
 * qmi_wds_connection_status_build_string_from_mask:
 * @mask: bitmask of QmiWdsConnectionStatus values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsConnectionStatus in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_connection_status_build_string_from_mask (QmiWdsConnectionStatus mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_connection_status_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_connection_status_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_connection_status_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_connection_status_values[i].value) {
            guint c;
            gulong number = qmi_wds_connection_status_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_connection_status_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_CONNECTION_STATUS_IS_FLAGS__ */

static const GEnumValue qmi_wds_data_bearer_technology_values[] = {
    { QMI_WDS_DATA_BEARER_TECHNOLOGY_UNKNOWN, "QMI_WDS_DATA_BEARER_TECHNOLOGY_UNKNOWN", "unknown" },
    { QMI_WDS_DATA_BEARER_TECHNOLOGY_CDMA20001X, "QMI_WDS_DATA_BEARER_TECHNOLOGY_CDMA20001X", "cdma20001x" },
    { QMI_WDS_DATA_BEARER_TECHNOLOGY_1xEVDO, "QMI_WDS_DATA_BEARER_TECHNOLOGY_1xEVDO", "1xevdo" },
    { QMI_WDS_DATA_BEARER_TECHNOLOGY_GSM, "QMI_WDS_DATA_BEARER_TECHNOLOGY_GSM", "gsm" },
    { QMI_WDS_DATA_BEARER_TECHNOLOGY_UMTS, "QMI_WDS_DATA_BEARER_TECHNOLOGY_UMTS", "umts" },
    { QMI_WDS_DATA_BEARER_TECHNOLOGY_1xEVDO_REVA, "QMI_WDS_DATA_BEARER_TECHNOLOGY_1xEVDO_REVA", "1xevdo-reva" },
    { QMI_WDS_DATA_BEARER_TECHNOLOGY_EDGE, "QMI_WDS_DATA_BEARER_TECHNOLOGY_EDGE", "edge" },
    { QMI_WDS_DATA_BEARER_TECHNOLOGY_HSDPA, "QMI_WDS_DATA_BEARER_TECHNOLOGY_HSDPA", "hsdpa" },
    { QMI_WDS_DATA_BEARER_TECHNOLOGY_HSUPA, "QMI_WDS_DATA_BEARER_TECHNOLOGY_HSUPA", "hsupa" },
    { QMI_WDS_DATA_BEARER_TECHNOLOGY_HSDPA_HSUPDA, "QMI_WDS_DATA_BEARER_TECHNOLOGY_HSDPA_HSUPDA", "hsdpa-hsupda" },
    { QMI_WDS_DATA_BEARER_TECHNOLOGY_LTE, "QMI_WDS_DATA_BEARER_TECHNOLOGY_LTE", "lte" },
    { QMI_WDS_DATA_BEARER_TECHNOLOGY_EHRPD, "QMI_WDS_DATA_BEARER_TECHNOLOGY_EHRPD", "ehrpd" },
    { QMI_WDS_DATA_BEARER_TECHNOLOGY_HSDPAPLUS, "QMI_WDS_DATA_BEARER_TECHNOLOGY_HSDPAPLUS", "hsdpaplus" },
    { QMI_WDS_DATA_BEARER_TECHNOLOGY_HSDPAPLUS_HSUPA, "QMI_WDS_DATA_BEARER_TECHNOLOGY_HSDPAPLUS_HSUPA", "hsdpaplus-hsupa" },
    { QMI_WDS_DATA_BEARER_TECHNOLOGY_DCHSDPAPLUS, "QMI_WDS_DATA_BEARER_TECHNOLOGY_DCHSDPAPLUS", "dchsdpaplus" },
    { QMI_WDS_DATA_BEARER_TECHNOLOGY_DCHSDPAPLUS_HSUPA, "QMI_WDS_DATA_BEARER_TECHNOLOGY_DCHSDPAPLUS_HSUPA", "dchsdpaplus-hsupa" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_data_bearer_technology_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWdsDataBearerTechnology"),
                                      qmi_wds_data_bearer_technology_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_DATA_BEARER_TECHNOLOGY_IS_ENUM__
/**
 * qmi_wds_data_bearer_technology_get_string:
 * @val: a QmiWdsDataBearerTechnology.
 *
 * Gets the nickname string for the #QmiWdsDataBearerTechnology specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_data_bearer_technology_get_string (QmiWdsDataBearerTechnology val)
{
    guint i;

    for (i = 0; qmi_wds_data_bearer_technology_values[i].value_nick; i++) {
        if (val == qmi_wds_data_bearer_technology_values[i].value)
            return qmi_wds_data_bearer_technology_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_DATA_BEARER_TECHNOLOGY_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_DATA_BEARER_TECHNOLOGY_IS_FLAGS__
/**
 * qmi_wds_data_bearer_technology_build_string_from_mask:
 * @mask: bitmask of QmiWdsDataBearerTechnology values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsDataBearerTechnology in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_data_bearer_technology_build_string_from_mask (QmiWdsDataBearerTechnology mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_data_bearer_technology_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_data_bearer_technology_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_data_bearer_technology_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_data_bearer_technology_values[i].value) {
            guint c;
            gulong number = qmi_wds_data_bearer_technology_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_data_bearer_technology_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_DATA_BEARER_TECHNOLOGY_IS_FLAGS__ */

static const GEnumValue qmi_wds_network_type_values[] = {
    { QMI_WDS_NETWORK_TYPE_UNKNOWN, "QMI_WDS_NETWORK_TYPE_UNKNOWN", "unknown" },
    { QMI_WDS_NETWORK_TYPE_3GPP2, "QMI_WDS_NETWORK_TYPE_3GPP2", "3gpp2" },
    { QMI_WDS_NETWORK_TYPE_3GPP, "QMI_WDS_NETWORK_TYPE_3GPP", "3gpp" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_network_type_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWdsNetworkType"),
                                      qmi_wds_network_type_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_NETWORK_TYPE_IS_ENUM__
/**
 * qmi_wds_network_type_get_string:
 * @val: a QmiWdsNetworkType.
 *
 * Gets the nickname string for the #QmiWdsNetworkType specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_network_type_get_string (QmiWdsNetworkType val)
{
    guint i;

    for (i = 0; qmi_wds_network_type_values[i].value_nick; i++) {
        if (val == qmi_wds_network_type_values[i].value)
            return qmi_wds_network_type_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_NETWORK_TYPE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_NETWORK_TYPE_IS_FLAGS__
/**
 * qmi_wds_network_type_build_string_from_mask:
 * @mask: bitmask of QmiWdsNetworkType values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsNetworkType in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_network_type_build_string_from_mask (QmiWdsNetworkType mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_network_type_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_network_type_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_network_type_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_network_type_values[i].value) {
            guint c;
            gulong number = qmi_wds_network_type_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_network_type_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_NETWORK_TYPE_IS_FLAGS__ */

static const GFlagsValue qmi_wds_rat_3gpp2_values[] = {
    { QMI_WDS_RAT_3GPP2_NONE, "QMI_WDS_RAT_3GPP2_NONE", "none" },
    { QMI_WDS_RAT_3GPP2_CDMA1X, "QMI_WDS_RAT_3GPP2_CDMA1X", "cdma1x" },
    { QMI_WDS_RAT_3GPP2_EVDO_REV0, "QMI_WDS_RAT_3GPP2_EVDO_REV0", "evdo-rev0" },
    { QMI_WDS_RAT_3GPP2_EVDO_REVA, "QMI_WDS_RAT_3GPP2_EVDO_REVA", "evdo-reva" },
    { QMI_WDS_RAT_3GPP2_EVDO_REVB, "QMI_WDS_RAT_3GPP2_EVDO_REVB", "evdo-revb" },
    { QMI_WDS_RAT_3GPP2_NULL_BEARER, "QMI_WDS_RAT_3GPP2_NULL_BEARER", "null-bearer" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_rat_3gpp2_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("QmiWdsRat3gpp2"),
                                      qmi_wds_rat_3gpp2_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_RAT_3GPP2_IS_ENUM__
/**
 * qmi_wds_rat_3gpp2_get_string:
 * @val: a QmiWdsRat3gpp2.
 *
 * Gets the nickname string for the #QmiWdsRat3gpp2 specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_rat_3gpp2_get_string (QmiWdsRat3gpp2 val)
{
    guint i;

    for (i = 0; qmi_wds_rat_3gpp2_values[i].value_nick; i++) {
        if (val == qmi_wds_rat_3gpp2_values[i].value)
            return qmi_wds_rat_3gpp2_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_RAT_3GPP2_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_RAT_3GPP2_IS_FLAGS__
/**
 * qmi_wds_rat_3gpp2_build_string_from_mask:
 * @mask: bitmask of QmiWdsRat3gpp2 values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsRat3gpp2 in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_rat_3gpp2_build_string_from_mask (QmiWdsRat3gpp2 mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_rat_3gpp2_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_rat_3gpp2_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_rat_3gpp2_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_rat_3gpp2_values[i].value) {
            guint c;
            gulong number = qmi_wds_rat_3gpp2_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_rat_3gpp2_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_RAT_3GPP2_IS_FLAGS__ */

static const GFlagsValue qmi_wds_rat_3gpp_values[] = {
    { QMI_WDS_RAT_3GPP_NONE, "QMI_WDS_RAT_3GPP_NONE", "none" },
    { QMI_WDS_RAT_3GPP_WCDMA, "QMI_WDS_RAT_3GPP_WCDMA", "wcdma" },
    { QMI_WDS_RAT_3GPP_GPRS, "QMI_WDS_RAT_3GPP_GPRS", "gprs" },
    { QMI_WDS_RAT_3GPP_HSDPA, "QMI_WDS_RAT_3GPP_HSDPA", "hsdpa" },
    { QMI_WDS_RAT_3GPP_HSUPA, "QMI_WDS_RAT_3GPP_HSUPA", "hsupa" },
    { QMI_WDS_RAT_3GPP_EDGE, "QMI_WDS_RAT_3GPP_EDGE", "edge" },
    { QMI_WDS_RAT_3GPP_LTE, "QMI_WDS_RAT_3GPP_LTE", "lte" },
    { QMI_WDS_RAT_3GPP_HSDPAPLUS, "QMI_WDS_RAT_3GPP_HSDPAPLUS", "hsdpaplus" },
    { QMI_WDS_RAT_3GPP_DCHSDPAPLUS, "QMI_WDS_RAT_3GPP_DCHSDPAPLUS", "dchsdpaplus" },
    { QMI_WDS_RAT_3GPP_NULL_BEARER, "QMI_WDS_RAT_3GPP_NULL_BEARER", "null-bearer" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_rat_3gpp_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("QmiWdsRat3gpp"),
                                      qmi_wds_rat_3gpp_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_RAT_3GPP_IS_ENUM__
/**
 * qmi_wds_rat_3gpp_get_string:
 * @val: a QmiWdsRat3gpp.
 *
 * Gets the nickname string for the #QmiWdsRat3gpp specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_rat_3gpp_get_string (QmiWdsRat3gpp val)
{
    guint i;

    for (i = 0; qmi_wds_rat_3gpp_values[i].value_nick; i++) {
        if (val == qmi_wds_rat_3gpp_values[i].value)
            return qmi_wds_rat_3gpp_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_RAT_3GPP_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_RAT_3GPP_IS_FLAGS__
/**
 * qmi_wds_rat_3gpp_build_string_from_mask:
 * @mask: bitmask of QmiWdsRat3gpp values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsRat3gpp in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_rat_3gpp_build_string_from_mask (QmiWdsRat3gpp mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_rat_3gpp_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_rat_3gpp_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_rat_3gpp_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_rat_3gpp_values[i].value) {
            guint c;
            gulong number = qmi_wds_rat_3gpp_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_rat_3gpp_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_RAT_3GPP_IS_FLAGS__ */

static const GFlagsValue qmi_wds_so_cdma1x_values[] = {
    { QMI_WDS_SO_CDMA1X_NONE, "QMI_WDS_SO_CDMA1X_NONE", "none" },
    { QMI_WDS_SO_CDMA1X_IS95, "QMI_WDS_SO_CDMA1X_IS95", "is95" },
    { QMI_WDS_SO_CDMA1X_IS2000, "QMI_WDS_SO_CDMA1X_IS2000", "is2000" },
    { QMI_WDS_SO_CDMA1X_IS2000_REL_A, "QMI_WDS_SO_CDMA1X_IS2000_REL_A", "is2000-rel-a" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_so_cdma1x_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("QmiWdsSoCdma1x"),
                                      qmi_wds_so_cdma1x_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_SO_CDMA1X_IS_ENUM__
/**
 * qmi_wds_so_cdma1x_get_string:
 * @val: a QmiWdsSoCdma1x.
 *
 * Gets the nickname string for the #QmiWdsSoCdma1x specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_so_cdma1x_get_string (QmiWdsSoCdma1x val)
{
    guint i;

    for (i = 0; qmi_wds_so_cdma1x_values[i].value_nick; i++) {
        if (val == qmi_wds_so_cdma1x_values[i].value)
            return qmi_wds_so_cdma1x_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_SO_CDMA1X_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_SO_CDMA1X_IS_FLAGS__
/**
 * qmi_wds_so_cdma1x_build_string_from_mask:
 * @mask: bitmask of QmiWdsSoCdma1x values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsSoCdma1x in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_so_cdma1x_build_string_from_mask (QmiWdsSoCdma1x mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_so_cdma1x_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_so_cdma1x_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_so_cdma1x_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_so_cdma1x_values[i].value) {
            guint c;
            gulong number = qmi_wds_so_cdma1x_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_so_cdma1x_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_SO_CDMA1X_IS_FLAGS__ */

static const GFlagsValue qmi_wds_so_evdo_reva_values[] = {
    { QMI_WDS_SO_EVDO_REVA_NONE, "QMI_WDS_SO_EVDO_REVA_NONE", "none" },
    { QMI_WDS_SO_EVDO_REVA_DPA, "QMI_WDS_SO_EVDO_REVA_DPA", "dpa" },
    { QMI_WDS_SO_EVDO_REVA_MFPA, "QMI_WDS_SO_EVDO_REVA_MFPA", "mfpa" },
    { QMI_WDS_SO_EVDO_REVA_EMPA, "QMI_WDS_SO_EVDO_REVA_EMPA", "empa" },
    { QMI_WDS_SO_EVDO_REVA_EMPA_EHRPD, "QMI_WDS_SO_EVDO_REVA_EMPA_EHRPD", "empa-ehrpd" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_so_evdo_reva_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("QmiWdsSoEvdoRevA"),
                                      qmi_wds_so_evdo_reva_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_SO_EVDO_REVA_IS_ENUM__
/**
 * qmi_wds_so_evdo_reva_get_string:
 * @val: a QmiWdsSoEvdoRevA.
 *
 * Gets the nickname string for the #QmiWdsSoEvdoRevA specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_so_evdo_reva_get_string (QmiWdsSoEvdoRevA val)
{
    guint i;

    for (i = 0; qmi_wds_so_evdo_reva_values[i].value_nick; i++) {
        if (val == qmi_wds_so_evdo_reva_values[i].value)
            return qmi_wds_so_evdo_reva_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_SO_EVDO_REVA_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_SO_EVDO_REVA_IS_FLAGS__
/**
 * qmi_wds_so_evdo_reva_build_string_from_mask:
 * @mask: bitmask of QmiWdsSoEvdoRevA values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsSoEvdoRevA in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_so_evdo_reva_build_string_from_mask (QmiWdsSoEvdoRevA mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_so_evdo_reva_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_so_evdo_reva_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_so_evdo_reva_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_so_evdo_reva_values[i].value) {
            guint c;
            gulong number = qmi_wds_so_evdo_reva_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_so_evdo_reva_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_SO_EVDO_REVA_IS_FLAGS__ */

static const GFlagsValue qmi_wds_get_current_settings_requested_settings_values[] = {
    { QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_NONE, "QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_NONE", "none" },
    { QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_PROFILE_ID, "QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_PROFILE_ID", "profile-id" },
    { QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_PROFILE_NAME, "QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_PROFILE_NAME", "profile-name" },
    { QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_PDP_TYPE, "QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_PDP_TYPE", "pdp-type" },
    { QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_APN_NAME, "QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_APN_NAME", "apn-name" },
    { QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_DNS_ADDRESS, "QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_DNS_ADDRESS", "dns-address" },
    { QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_GRANTED_QOS, "QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_GRANTED_QOS", "granted-qos" },
    { QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_USERNAME, "QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_USERNAME", "username" },
    { QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_AUTH_PROTOCOL, "QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_AUTH_PROTOCOL", "auth-protocol" },
    { QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_IP_ADDRESS, "QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_IP_ADDRESS", "ip-address" },
    { QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_GATEWAY_INFO, "QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_GATEWAY_INFO", "gateway-info" },
    { QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_PCSCF_ADDRESS, "QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_PCSCF_ADDRESS", "pcscf-address" },
    { QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_PCSCF_SERVER_ADDRESS_LIST, "QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_PCSCF_SERVER_ADDRESS_LIST", "pcscf-server-address-list" },
    { QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_PCSCF_DOMAIN_NAME_LIST, "QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_PCSCF_DOMAIN_NAME_LIST", "pcscf-domain-name-list" },
    { QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_MTU, "QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_MTU", "mtu" },
    { QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_DOMAIN_NAME_LIST, "QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_DOMAIN_NAME_LIST", "domain-name-list" },
    { QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_IP_FAMILY, "QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_IP_FAMILY", "ip-family" },
    { QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_IMCN_FLAG, "QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_IMCN_FLAG", "imcn-flag" },
    { QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_EXTENDED_TECHNOLOGY, "QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_EXTENDED_TECHNOLOGY", "extended-technology" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_get_current_settings_requested_settings_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("QmiWdsGetCurrentSettingsRequestedSettings"),
                                      qmi_wds_get_current_settings_requested_settings_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_IS_ENUM__
/**
 * qmi_wds_get_current_settings_requested_settings_get_string:
 * @val: a QmiWdsGetCurrentSettingsRequestedSettings.
 *
 * Gets the nickname string for the #QmiWdsGetCurrentSettingsRequestedSettings specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_get_current_settings_requested_settings_get_string (QmiWdsGetCurrentSettingsRequestedSettings val)
{
    guint i;

    for (i = 0; qmi_wds_get_current_settings_requested_settings_values[i].value_nick; i++) {
        if (val == qmi_wds_get_current_settings_requested_settings_values[i].value)
            return qmi_wds_get_current_settings_requested_settings_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_IS_FLAGS__
/**
 * qmi_wds_get_current_settings_requested_settings_build_string_from_mask:
 * @mask: bitmask of QmiWdsGetCurrentSettingsRequestedSettings values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsGetCurrentSettingsRequestedSettings in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_get_current_settings_requested_settings_build_string_from_mask (QmiWdsGetCurrentSettingsRequestedSettings mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_get_current_settings_requested_settings_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_get_current_settings_requested_settings_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_get_current_settings_requested_settings_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_get_current_settings_requested_settings_values[i].value) {
            guint c;
            gulong number = qmi_wds_get_current_settings_requested_settings_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_get_current_settings_requested_settings_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_GET_CURRENT_SETTINGS_REQUESTED_SETTINGS_IS_FLAGS__ */

static const GEnumValue qmi_wds_pdp_type_values[] = {
    { QMI_WDS_PDP_TYPE_IPV4, "QMI_WDS_PDP_TYPE_IPV4", "ipv4" },
    { QMI_WDS_PDP_TYPE_PPP, "QMI_WDS_PDP_TYPE_PPP", "ppp" },
    { QMI_WDS_PDP_TYPE_IPV6, "QMI_WDS_PDP_TYPE_IPV6", "ipv6" },
    { QMI_WDS_PDP_TYPE_IPV4_OR_IPV6, "QMI_WDS_PDP_TYPE_IPV4_OR_IPV6", "ipv4-or-ipv6" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_pdp_type_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWdsPdpType"),
                                      qmi_wds_pdp_type_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_PDP_TYPE_IS_ENUM__
/**
 * qmi_wds_pdp_type_get_string:
 * @val: a QmiWdsPdpType.
 *
 * Gets the nickname string for the #QmiWdsPdpType specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_pdp_type_get_string (QmiWdsPdpType val)
{
    guint i;

    for (i = 0; qmi_wds_pdp_type_values[i].value_nick; i++) {
        if (val == qmi_wds_pdp_type_values[i].value)
            return qmi_wds_pdp_type_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_PDP_TYPE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_PDP_TYPE_IS_FLAGS__
/**
 * qmi_wds_pdp_type_build_string_from_mask:
 * @mask: bitmask of QmiWdsPdpType values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsPdpType in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_pdp_type_build_string_from_mask (QmiWdsPdpType mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_pdp_type_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_pdp_type_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_pdp_type_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_pdp_type_values[i].value) {
            guint c;
            gulong number = qmi_wds_pdp_type_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_pdp_type_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_PDP_TYPE_IS_FLAGS__ */

static const GEnumValue qmi_wds_traffic_class_values[] = {
    { QMI_WDS_TRAFFIC_CLASS_SUBSCRIBED, "QMI_WDS_TRAFFIC_CLASS_SUBSCRIBED", "subscribed" },
    { QMI_WDS_TRAFFIC_CLASS_CONVERSATIONAL, "QMI_WDS_TRAFFIC_CLASS_CONVERSATIONAL", "conversational" },
    { QMI_WDS_TRAFFIC_CLASS_STREAMING, "QMI_WDS_TRAFFIC_CLASS_STREAMING", "streaming" },
    { QMI_WDS_TRAFFIC_CLASS_INTERACTIVE, "QMI_WDS_TRAFFIC_CLASS_INTERACTIVE", "interactive" },
    { QMI_WDS_TRAFFIC_CLASS_BACKGROUND, "QMI_WDS_TRAFFIC_CLASS_BACKGROUND", "background" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_traffic_class_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWdsTrafficClass"),
                                      qmi_wds_traffic_class_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_TRAFFIC_CLASS_IS_ENUM__
/**
 * qmi_wds_traffic_class_get_string:
 * @val: a QmiWdsTrafficClass.
 *
 * Gets the nickname string for the #QmiWdsTrafficClass specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_traffic_class_get_string (QmiWdsTrafficClass val)
{
    guint i;

    for (i = 0; qmi_wds_traffic_class_values[i].value_nick; i++) {
        if (val == qmi_wds_traffic_class_values[i].value)
            return qmi_wds_traffic_class_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_TRAFFIC_CLASS_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_TRAFFIC_CLASS_IS_FLAGS__
/**
 * qmi_wds_traffic_class_build_string_from_mask:
 * @mask: bitmask of QmiWdsTrafficClass values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsTrafficClass in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_traffic_class_build_string_from_mask (QmiWdsTrafficClass mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_traffic_class_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_traffic_class_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_traffic_class_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_traffic_class_values[i].value) {
            guint c;
            gulong number = qmi_wds_traffic_class_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_traffic_class_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_TRAFFIC_CLASS_IS_FLAGS__ */

static const GFlagsValue qmi_wds_authentication_values[] = {
    { QMI_WDS_AUTHENTICATION_NONE, "QMI_WDS_AUTHENTICATION_NONE", "none" },
    { QMI_WDS_AUTHENTICATION_PAP, "QMI_WDS_AUTHENTICATION_PAP", "pap" },
    { QMI_WDS_AUTHENTICATION_CHAP, "QMI_WDS_AUTHENTICATION_CHAP", "chap" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_authentication_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("QmiWdsAuthentication"),
                                      qmi_wds_authentication_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_AUTHENTICATION_IS_ENUM__
/**
 * qmi_wds_authentication_get_string:
 * @val: a QmiWdsAuthentication.
 *
 * Gets the nickname string for the #QmiWdsAuthentication specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_authentication_get_string (QmiWdsAuthentication val)
{
    guint i;

    for (i = 0; qmi_wds_authentication_values[i].value_nick; i++) {
        if (val == qmi_wds_authentication_values[i].value)
            return qmi_wds_authentication_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_AUTHENTICATION_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_AUTHENTICATION_IS_FLAGS__
/**
 * qmi_wds_authentication_build_string_from_mask:
 * @mask: bitmask of QmiWdsAuthentication values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsAuthentication in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_authentication_build_string_from_mask (QmiWdsAuthentication mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_authentication_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_authentication_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_authentication_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_authentication_values[i].value) {
            guint c;
            gulong number = qmi_wds_authentication_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_authentication_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_AUTHENTICATION_IS_FLAGS__ */

static const GEnumValue qmi_wds_profile_type_values[] = {
    { QMI_WDS_PROFILE_TYPE_3GPP, "QMI_WDS_PROFILE_TYPE_3GPP", "3gpp" },
    { QMI_WDS_PROFILE_TYPE_3GPP2, "QMI_WDS_PROFILE_TYPE_3GPP2", "3gpp2" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wds_profile_type_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWdsProfileType"),
                                      qmi_wds_profile_type_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WDS_PROFILE_TYPE_IS_ENUM__
/**
 * qmi_wds_profile_type_get_string:
 * @val: a QmiWdsProfileType.
 *
 * Gets the nickname string for the #QmiWdsProfileType specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wds_profile_type_get_string (QmiWdsProfileType val)
{
    guint i;

    for (i = 0; qmi_wds_profile_type_values[i].value_nick; i++) {
        if (val == qmi_wds_profile_type_values[i].value)
            return qmi_wds_profile_type_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WDS_PROFILE_TYPE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WDS_PROFILE_TYPE_IS_FLAGS__
/**
 * qmi_wds_profile_type_build_string_from_mask:
 * @mask: bitmask of QmiWdsProfileType values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWdsProfileType in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wds_profile_type_build_string_from_mask (QmiWdsProfileType mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wds_profile_type_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wds_profile_type_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wds_profile_type_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wds_profile_type_values[i].value) {
            guint c;
            gulong number = qmi_wds_profile_type_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wds_profile_type_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WDS_PROFILE_TYPE_IS_FLAGS__ */

/* enumerations from "../../libqmi-glib/qmi-enums-dms.h" */
static const GEnumValue qmi_dms_data_service_capability_values[] = {
    { QMI_DMS_DATA_SERVICE_CAPABILITY_NONE, "QMI_DMS_DATA_SERVICE_CAPABILITY_NONE", "none" },
    { QMI_DMS_DATA_SERVICE_CAPABILITY_CS, "QMI_DMS_DATA_SERVICE_CAPABILITY_CS", "cs" },
    { QMI_DMS_DATA_SERVICE_CAPABILITY_PS, "QMI_DMS_DATA_SERVICE_CAPABILITY_PS", "ps" },
    { QMI_DMS_DATA_SERVICE_CAPABILITY_SIMULTANEOUS_CS_PS, "QMI_DMS_DATA_SERVICE_CAPABILITY_SIMULTANEOUS_CS_PS", "simultaneous-cs-ps" },
    { QMI_DMS_DATA_SERVICE_CAPABILITY_NON_SIMULTANEOUS_CS_PS, "QMI_DMS_DATA_SERVICE_CAPABILITY_NON_SIMULTANEOUS_CS_PS", "non-simultaneous-cs-ps" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_dms_data_service_capability_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiDmsDataServiceCapability"),
                                      qmi_dms_data_service_capability_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_DMS_DATA_SERVICE_CAPABILITY_IS_ENUM__
/**
 * qmi_dms_data_service_capability_get_string:
 * @val: a QmiDmsDataServiceCapability.
 *
 * Gets the nickname string for the #QmiDmsDataServiceCapability specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_dms_data_service_capability_get_string (QmiDmsDataServiceCapability val)
{
    guint i;

    for (i = 0; qmi_dms_data_service_capability_values[i].value_nick; i++) {
        if (val == qmi_dms_data_service_capability_values[i].value)
            return qmi_dms_data_service_capability_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_DMS_DATA_SERVICE_CAPABILITY_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_DMS_DATA_SERVICE_CAPABILITY_IS_FLAGS__
/**
 * qmi_dms_data_service_capability_build_string_from_mask:
 * @mask: bitmask of QmiDmsDataServiceCapability values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiDmsDataServiceCapability in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_dms_data_service_capability_build_string_from_mask (QmiDmsDataServiceCapability mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_dms_data_service_capability_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_dms_data_service_capability_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_dms_data_service_capability_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_dms_data_service_capability_values[i].value) {
            guint c;
            gulong number = qmi_dms_data_service_capability_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_dms_data_service_capability_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_DMS_DATA_SERVICE_CAPABILITY_IS_FLAGS__ */

static const GEnumValue qmi_dms_sim_capability_values[] = {
    { QMI_DMS_SIM_CAPABILITY_NOT_SUPPORTED, "QMI_DMS_SIM_CAPABILITY_NOT_SUPPORTED", "not-supported" },
    { QMI_DMS_SIM_CAPABILITY_SUPPORTED, "QMI_DMS_SIM_CAPABILITY_SUPPORTED", "supported" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_dms_sim_capability_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiDmsSimCapability"),
                                      qmi_dms_sim_capability_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_DMS_SIM_CAPABILITY_IS_ENUM__
/**
 * qmi_dms_sim_capability_get_string:
 * @val: a QmiDmsSimCapability.
 *
 * Gets the nickname string for the #QmiDmsSimCapability specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_dms_sim_capability_get_string (QmiDmsSimCapability val)
{
    guint i;

    for (i = 0; qmi_dms_sim_capability_values[i].value_nick; i++) {
        if (val == qmi_dms_sim_capability_values[i].value)
            return qmi_dms_sim_capability_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_DMS_SIM_CAPABILITY_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_DMS_SIM_CAPABILITY_IS_FLAGS__
/**
 * qmi_dms_sim_capability_build_string_from_mask:
 * @mask: bitmask of QmiDmsSimCapability values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiDmsSimCapability in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_dms_sim_capability_build_string_from_mask (QmiDmsSimCapability mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_dms_sim_capability_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_dms_sim_capability_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_dms_sim_capability_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_dms_sim_capability_values[i].value) {
            guint c;
            gulong number = qmi_dms_sim_capability_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_dms_sim_capability_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_DMS_SIM_CAPABILITY_IS_FLAGS__ */

static const GEnumValue qmi_dms_radio_interface_values[] = {
    { QMI_DMS_RADIO_INTERFACE_CDMA20001X, "QMI_DMS_RADIO_INTERFACE_CDMA20001X", "cdma20001x" },
    { QMI_DMS_RADIO_INTERFACE_EVDO, "QMI_DMS_RADIO_INTERFACE_EVDO", "evdo" },
    { QMI_DMS_RADIO_INTERFACE_GSM, "QMI_DMS_RADIO_INTERFACE_GSM", "gsm" },
    { QMI_DMS_RADIO_INTERFACE_UMTS, "QMI_DMS_RADIO_INTERFACE_UMTS", "umts" },
    { QMI_DMS_RADIO_INTERFACE_LTE, "QMI_DMS_RADIO_INTERFACE_LTE", "lte" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_dms_radio_interface_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiDmsRadioInterface"),
                                      qmi_dms_radio_interface_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_DMS_RADIO_INTERFACE_IS_ENUM__
/**
 * qmi_dms_radio_interface_get_string:
 * @val: a QmiDmsRadioInterface.
 *
 * Gets the nickname string for the #QmiDmsRadioInterface specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_dms_radio_interface_get_string (QmiDmsRadioInterface val)
{
    guint i;

    for (i = 0; qmi_dms_radio_interface_values[i].value_nick; i++) {
        if (val == qmi_dms_radio_interface_values[i].value)
            return qmi_dms_radio_interface_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_DMS_RADIO_INTERFACE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_DMS_RADIO_INTERFACE_IS_FLAGS__
/**
 * qmi_dms_radio_interface_build_string_from_mask:
 * @mask: bitmask of QmiDmsRadioInterface values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiDmsRadioInterface in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_dms_radio_interface_build_string_from_mask (QmiDmsRadioInterface mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_dms_radio_interface_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_dms_radio_interface_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_dms_radio_interface_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_dms_radio_interface_values[i].value) {
            guint c;
            gulong number = qmi_dms_radio_interface_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_dms_radio_interface_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_DMS_RADIO_INTERFACE_IS_FLAGS__ */

static const GFlagsValue qmi_dms_power_state_values[] = {
    { QMI_DMS_POWER_STATE_EXTERNAL_SOURCE, "QMI_DMS_POWER_STATE_EXTERNAL_SOURCE", "external-source" },
    { QMI_DMS_POWER_STATE_BATTERY_CONNECTED, "QMI_DMS_POWER_STATE_BATTERY_CONNECTED", "battery-connected" },
    { QMI_DMS_POWER_STATE_BATTERY_CHARGING, "QMI_DMS_POWER_STATE_BATTERY_CHARGING", "battery-charging" },
    { QMI_DMS_POWER_STATE_FAULT, "QMI_DMS_POWER_STATE_FAULT", "fault" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_dms_power_state_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("QmiDmsPowerState"),
                                      qmi_dms_power_state_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_DMS_POWER_STATE_IS_ENUM__
/**
 * qmi_dms_power_state_get_string:
 * @val: a QmiDmsPowerState.
 *
 * Gets the nickname string for the #QmiDmsPowerState specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_dms_power_state_get_string (QmiDmsPowerState val)
{
    guint i;

    for (i = 0; qmi_dms_power_state_values[i].value_nick; i++) {
        if (val == qmi_dms_power_state_values[i].value)
            return qmi_dms_power_state_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_DMS_POWER_STATE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_DMS_POWER_STATE_IS_FLAGS__
/**
 * qmi_dms_power_state_build_string_from_mask:
 * @mask: bitmask of QmiDmsPowerState values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiDmsPowerState in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_dms_power_state_build_string_from_mask (QmiDmsPowerState mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_dms_power_state_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_dms_power_state_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_dms_power_state_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_dms_power_state_values[i].value) {
            guint c;
            gulong number = qmi_dms_power_state_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_dms_power_state_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_DMS_POWER_STATE_IS_FLAGS__ */

static const GEnumValue qmi_dms_uim_pin_id_values[] = {
    { QMI_DMS_UIM_PIN_ID_PIN, "QMI_DMS_UIM_PIN_ID_PIN", "pin" },
    { QMI_DMS_UIM_PIN_ID_PIN2, "QMI_DMS_UIM_PIN_ID_PIN2", "pin2" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_dms_uim_pin_id_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiDmsUimPinId"),
                                      qmi_dms_uim_pin_id_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_DMS_UIM_PIN_ID_IS_ENUM__
/**
 * qmi_dms_uim_pin_id_get_string:
 * @val: a QmiDmsUimPinId.
 *
 * Gets the nickname string for the #QmiDmsUimPinId specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_dms_uim_pin_id_get_string (QmiDmsUimPinId val)
{
    guint i;

    for (i = 0; qmi_dms_uim_pin_id_values[i].value_nick; i++) {
        if (val == qmi_dms_uim_pin_id_values[i].value)
            return qmi_dms_uim_pin_id_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_DMS_UIM_PIN_ID_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_DMS_UIM_PIN_ID_IS_FLAGS__
/**
 * qmi_dms_uim_pin_id_build_string_from_mask:
 * @mask: bitmask of QmiDmsUimPinId values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiDmsUimPinId in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_dms_uim_pin_id_build_string_from_mask (QmiDmsUimPinId mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_dms_uim_pin_id_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_dms_uim_pin_id_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_dms_uim_pin_id_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_dms_uim_pin_id_values[i].value) {
            guint c;
            gulong number = qmi_dms_uim_pin_id_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_dms_uim_pin_id_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_DMS_UIM_PIN_ID_IS_FLAGS__ */

static const GEnumValue qmi_dms_uim_pin_status_values[] = {
    { QMI_DMS_UIM_PIN_STATUS_NOT_INITIALIZED, "QMI_DMS_UIM_PIN_STATUS_NOT_INITIALIZED", "not-initialized" },
    { QMI_DMS_UIM_PIN_STATUS_ENABLED_NOT_VERIFIED, "QMI_DMS_UIM_PIN_STATUS_ENABLED_NOT_VERIFIED", "enabled-not-verified" },
    { QMI_DMS_UIM_PIN_STATUS_ENABLED_VERIFIED, "QMI_DMS_UIM_PIN_STATUS_ENABLED_VERIFIED", "enabled-verified" },
    { QMI_DMS_UIM_PIN_STATUS_DISABLED, "QMI_DMS_UIM_PIN_STATUS_DISABLED", "disabled" },
    { QMI_DMS_UIM_PIN_STATUS_BLOCKED, "QMI_DMS_UIM_PIN_STATUS_BLOCKED", "blocked" },
    { QMI_DMS_UIM_PIN_STATUS_PERMANENTLY_BLOCKED, "QMI_DMS_UIM_PIN_STATUS_PERMANENTLY_BLOCKED", "permanently-blocked" },
    { QMI_DMS_UIM_PIN_STATUS_UNBLOCKED, "QMI_DMS_UIM_PIN_STATUS_UNBLOCKED", "unblocked" },
    { QMI_DMS_UIM_PIN_STATUS_CHANGED, "QMI_DMS_UIM_PIN_STATUS_CHANGED", "changed" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_dms_uim_pin_status_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiDmsUimPinStatus"),
                                      qmi_dms_uim_pin_status_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_DMS_UIM_PIN_STATUS_IS_ENUM__
/**
 * qmi_dms_uim_pin_status_get_string:
 * @val: a QmiDmsUimPinStatus.
 *
 * Gets the nickname string for the #QmiDmsUimPinStatus specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_dms_uim_pin_status_get_string (QmiDmsUimPinStatus val)
{
    guint i;

    for (i = 0; qmi_dms_uim_pin_status_values[i].value_nick; i++) {
        if (val == qmi_dms_uim_pin_status_values[i].value)
            return qmi_dms_uim_pin_status_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_DMS_UIM_PIN_STATUS_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_DMS_UIM_PIN_STATUS_IS_FLAGS__
/**
 * qmi_dms_uim_pin_status_build_string_from_mask:
 * @mask: bitmask of QmiDmsUimPinStatus values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiDmsUimPinStatus in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_dms_uim_pin_status_build_string_from_mask (QmiDmsUimPinStatus mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_dms_uim_pin_status_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_dms_uim_pin_status_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_dms_uim_pin_status_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_dms_uim_pin_status_values[i].value) {
            guint c;
            gulong number = qmi_dms_uim_pin_status_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_dms_uim_pin_status_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_DMS_UIM_PIN_STATUS_IS_FLAGS__ */

static const GEnumValue qmi_dms_operating_mode_values[] = {
    { QMI_DMS_OPERATING_MODE_ONLINE, "QMI_DMS_OPERATING_MODE_ONLINE", "online" },
    { QMI_DMS_OPERATING_MODE_LOW_POWER, "QMI_DMS_OPERATING_MODE_LOW_POWER", "low-power" },
    { QMI_DMS_OPERATING_MODE_FACTORY_TEST, "QMI_DMS_OPERATING_MODE_FACTORY_TEST", "factory-test" },
    { QMI_DMS_OPERATING_MODE_OFFLINE, "QMI_DMS_OPERATING_MODE_OFFLINE", "offline" },
    { QMI_DMS_OPERATING_MODE_RESET, "QMI_DMS_OPERATING_MODE_RESET", "reset" },
    { QMI_DMS_OPERATING_MODE_SHUTTING_DOWN, "QMI_DMS_OPERATING_MODE_SHUTTING_DOWN", "shutting-down" },
    { QMI_DMS_OPERATING_MODE_PERSISTENT_LOW_POWER, "QMI_DMS_OPERATING_MODE_PERSISTENT_LOW_POWER", "persistent-low-power" },
    { QMI_DMS_OPERATING_MODE_MODE_ONLY_LOW_POWER, "QMI_DMS_OPERATING_MODE_MODE_ONLY_LOW_POWER", "mode-only-low-power" },
    { QMI_DMS_OPERATING_MODE_UNKNOWN, "QMI_DMS_OPERATING_MODE_UNKNOWN", "unknown" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_dms_operating_mode_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiDmsOperatingMode"),
                                      qmi_dms_operating_mode_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_DMS_OPERATING_MODE_IS_ENUM__
/**
 * qmi_dms_operating_mode_get_string:
 * @val: a QmiDmsOperatingMode.
 *
 * Gets the nickname string for the #QmiDmsOperatingMode specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_dms_operating_mode_get_string (QmiDmsOperatingMode val)
{
    guint i;

    for (i = 0; qmi_dms_operating_mode_values[i].value_nick; i++) {
        if (val == qmi_dms_operating_mode_values[i].value)
            return qmi_dms_operating_mode_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_DMS_OPERATING_MODE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_DMS_OPERATING_MODE_IS_FLAGS__
/**
 * qmi_dms_operating_mode_build_string_from_mask:
 * @mask: bitmask of QmiDmsOperatingMode values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiDmsOperatingMode in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_dms_operating_mode_build_string_from_mask (QmiDmsOperatingMode mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_dms_operating_mode_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_dms_operating_mode_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_dms_operating_mode_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_dms_operating_mode_values[i].value) {
            guint c;
            gulong number = qmi_dms_operating_mode_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_dms_operating_mode_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_DMS_OPERATING_MODE_IS_FLAGS__ */

static const GFlagsValue qmi_dms_offline_reason_values[] = {
    { QMI_DMS_OFFLINE_REASON_HOST_IMAGE_MISCONFIGURATION, "QMI_DMS_OFFLINE_REASON_HOST_IMAGE_MISCONFIGURATION", "host-image-misconfiguration" },
    { QMI_DMS_OFFLINE_REASON_PRI_IMAGE_MISCONFIGURATION, "QMI_DMS_OFFLINE_REASON_PRI_IMAGE_MISCONFIGURATION", "pri-image-misconfiguration" },
    { QMI_DMS_OFFLINE_REASON_PRI_VERSION_INCOMPATIBLE, "QMI_DMS_OFFLINE_REASON_PRI_VERSION_INCOMPATIBLE", "pri-version-incompatible" },
    { QMI_DMS_OFFLINE_REASON_DEVICE_MEMORY_FULL, "QMI_DMS_OFFLINE_REASON_DEVICE_MEMORY_FULL", "device-memory-full" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_dms_offline_reason_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("QmiDmsOfflineReason"),
                                      qmi_dms_offline_reason_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_DMS_OFFLINE_REASON_IS_ENUM__
/**
 * qmi_dms_offline_reason_get_string:
 * @val: a QmiDmsOfflineReason.
 *
 * Gets the nickname string for the #QmiDmsOfflineReason specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_dms_offline_reason_get_string (QmiDmsOfflineReason val)
{
    guint i;

    for (i = 0; qmi_dms_offline_reason_values[i].value_nick; i++) {
        if (val == qmi_dms_offline_reason_values[i].value)
            return qmi_dms_offline_reason_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_DMS_OFFLINE_REASON_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_DMS_OFFLINE_REASON_IS_FLAGS__
/**
 * qmi_dms_offline_reason_build_string_from_mask:
 * @mask: bitmask of QmiDmsOfflineReason values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiDmsOfflineReason in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_dms_offline_reason_build_string_from_mask (QmiDmsOfflineReason mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_dms_offline_reason_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_dms_offline_reason_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_dms_offline_reason_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_dms_offline_reason_values[i].value) {
            guint c;
            gulong number = qmi_dms_offline_reason_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_dms_offline_reason_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_DMS_OFFLINE_REASON_IS_FLAGS__ */

static const GEnumValue qmi_dms_time_source_values[] = {
    { QMI_DMS_TIME_SOURCE_DEVICE, "QMI_DMS_TIME_SOURCE_DEVICE", "device" },
    { QMI_DMS_TIME_SOURCE_CDMA_NETWORK, "QMI_DMS_TIME_SOURCE_CDMA_NETWORK", "cdma-network" },
    { QMI_DMS_TIME_SOURCE_HDR_NETWORK, "QMI_DMS_TIME_SOURCE_HDR_NETWORK", "hdr-network" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_dms_time_source_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiDmsTimeSource"),
                                      qmi_dms_time_source_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_DMS_TIME_SOURCE_IS_ENUM__
/**
 * qmi_dms_time_source_get_string:
 * @val: a QmiDmsTimeSource.
 *
 * Gets the nickname string for the #QmiDmsTimeSource specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_dms_time_source_get_string (QmiDmsTimeSource val)
{
    guint i;

    for (i = 0; qmi_dms_time_source_values[i].value_nick; i++) {
        if (val == qmi_dms_time_source_values[i].value)
            return qmi_dms_time_source_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_DMS_TIME_SOURCE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_DMS_TIME_SOURCE_IS_FLAGS__
/**
 * qmi_dms_time_source_build_string_from_mask:
 * @mask: bitmask of QmiDmsTimeSource values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiDmsTimeSource in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_dms_time_source_build_string_from_mask (QmiDmsTimeSource mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_dms_time_source_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_dms_time_source_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_dms_time_source_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_dms_time_source_values[i].value) {
            guint c;
            gulong number = qmi_dms_time_source_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_dms_time_source_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_DMS_TIME_SOURCE_IS_FLAGS__ */

static const GEnumValue qmi_dms_activation_state_values[] = {
    { QMI_DMS_ACTIVATION_STATE_NOT_ACTIVATED, "QMI_DMS_ACTIVATION_STATE_NOT_ACTIVATED", "not-activated" },
    { QMI_DMS_ACTIVATION_STATE_ACTIVATED, "QMI_DMS_ACTIVATION_STATE_ACTIVATED", "activated" },
    { QMI_DMS_ACTIVATION_STATE_CONNECTING, "QMI_DMS_ACTIVATION_STATE_CONNECTING", "connecting" },
    { QMI_DMS_ACTIVATION_STATE_CONNECTED, "QMI_DMS_ACTIVATION_STATE_CONNECTED", "connected" },
    { QMI_DMS_ACTIVATION_STATE_OTASP_AUTHENTICATED, "QMI_DMS_ACTIVATION_STATE_OTASP_AUTHENTICATED", "otasp-authenticated" },
    { QMI_DMS_ACTIVATION_STATE_OTASP_NAM, "QMI_DMS_ACTIVATION_STATE_OTASP_NAM", "otasp-nam" },
    { QMI_DMS_ACTIVATION_STATE_OTASP_MDN, "QMI_DMS_ACTIVATION_STATE_OTASP_MDN", "otasp-mdn" },
    { QMI_DMS_ACTIVATION_STATE_OTASP_IMSI, "QMI_DMS_ACTIVATION_STATE_OTASP_IMSI", "otasp-imsi" },
    { QMI_DMS_ACTIVATION_STATE_OTASP_PRL, "QMI_DMS_ACTIVATION_STATE_OTASP_PRL", "otasp-prl" },
    { QMI_DMS_ACTIVATION_STATE_OTASP_SPC, "QMI_DMS_ACTIVATION_STATE_OTASP_SPC", "otasp-spc" },
    { QMI_DMS_ACTIVATION_STATE_OTASP_COMMITED, "QMI_DMS_ACTIVATION_STATE_OTASP_COMMITED", "otasp-commited" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_dms_activation_state_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiDmsActivationState"),
                                      qmi_dms_activation_state_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_DMS_ACTIVATION_STATE_IS_ENUM__
/**
 * qmi_dms_activation_state_get_string:
 * @val: a QmiDmsActivationState.
 *
 * Gets the nickname string for the #QmiDmsActivationState specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_dms_activation_state_get_string (QmiDmsActivationState val)
{
    guint i;

    for (i = 0; qmi_dms_activation_state_values[i].value_nick; i++) {
        if (val == qmi_dms_activation_state_values[i].value)
            return qmi_dms_activation_state_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_DMS_ACTIVATION_STATE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_DMS_ACTIVATION_STATE_IS_FLAGS__
/**
 * qmi_dms_activation_state_build_string_from_mask:
 * @mask: bitmask of QmiDmsActivationState values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiDmsActivationState in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_dms_activation_state_build_string_from_mask (QmiDmsActivationState mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_dms_activation_state_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_dms_activation_state_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_dms_activation_state_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_dms_activation_state_values[i].value) {
            guint c;
            gulong number = qmi_dms_activation_state_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_dms_activation_state_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_DMS_ACTIVATION_STATE_IS_FLAGS__ */

static const GEnumValue qmi_dms_uim_facility_values[] = {
    { QMI_DMS_UIM_FACILITY_PN, "QMI_DMS_UIM_FACILITY_PN", "pn" },
    { QMI_DMS_UIM_FACILITY_PU, "QMI_DMS_UIM_FACILITY_PU", "pu" },
    { QMI_DMS_UIM_FACILITY_PP, "QMI_DMS_UIM_FACILITY_PP", "pp" },
    { QMI_DMS_UIM_FACILITY_PC, "QMI_DMS_UIM_FACILITY_PC", "pc" },
    { QMI_DMS_UIM_FACILITY_PF, "QMI_DMS_UIM_FACILITY_PF", "pf" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_dms_uim_facility_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiDmsUimFacility"),
                                      qmi_dms_uim_facility_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_DMS_UIM_FACILITY_IS_ENUM__
/**
 * qmi_dms_uim_facility_get_string:
 * @val: a QmiDmsUimFacility.
 *
 * Gets the nickname string for the #QmiDmsUimFacility specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_dms_uim_facility_get_string (QmiDmsUimFacility val)
{
    guint i;

    for (i = 0; qmi_dms_uim_facility_values[i].value_nick; i++) {
        if (val == qmi_dms_uim_facility_values[i].value)
            return qmi_dms_uim_facility_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_DMS_UIM_FACILITY_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_DMS_UIM_FACILITY_IS_FLAGS__
/**
 * qmi_dms_uim_facility_build_string_from_mask:
 * @mask: bitmask of QmiDmsUimFacility values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiDmsUimFacility in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_dms_uim_facility_build_string_from_mask (QmiDmsUimFacility mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_dms_uim_facility_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_dms_uim_facility_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_dms_uim_facility_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_dms_uim_facility_values[i].value) {
            guint c;
            gulong number = qmi_dms_uim_facility_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_dms_uim_facility_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_DMS_UIM_FACILITY_IS_FLAGS__ */

static const GEnumValue qmi_dms_uim_facility_state_values[] = {
    { QMI_DMS_UIM_FACILITY_STATE_DEACTIVATED, "QMI_DMS_UIM_FACILITY_STATE_DEACTIVATED", "deactivated" },
    { QMI_DMS_UIM_FACILITY_STATE_ACTIVATED, "QMI_DMS_UIM_FACILITY_STATE_ACTIVATED", "activated" },
    { QMI_DMS_UIM_FACILITY_STATE_BLOCKED, "QMI_DMS_UIM_FACILITY_STATE_BLOCKED", "blocked" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_dms_uim_facility_state_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiDmsUimFacilityState"),
                                      qmi_dms_uim_facility_state_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_DMS_UIM_FACILITY_STATE_IS_ENUM__
/**
 * qmi_dms_uim_facility_state_get_string:
 * @val: a QmiDmsUimFacilityState.
 *
 * Gets the nickname string for the #QmiDmsUimFacilityState specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_dms_uim_facility_state_get_string (QmiDmsUimFacilityState val)
{
    guint i;

    for (i = 0; qmi_dms_uim_facility_state_values[i].value_nick; i++) {
        if (val == qmi_dms_uim_facility_state_values[i].value)
            return qmi_dms_uim_facility_state_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_DMS_UIM_FACILITY_STATE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_DMS_UIM_FACILITY_STATE_IS_FLAGS__
/**
 * qmi_dms_uim_facility_state_build_string_from_mask:
 * @mask: bitmask of QmiDmsUimFacilityState values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiDmsUimFacilityState in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_dms_uim_facility_state_build_string_from_mask (QmiDmsUimFacilityState mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_dms_uim_facility_state_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_dms_uim_facility_state_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_dms_uim_facility_state_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_dms_uim_facility_state_values[i].value) {
            guint c;
            gulong number = qmi_dms_uim_facility_state_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_dms_uim_facility_state_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_DMS_UIM_FACILITY_STATE_IS_FLAGS__ */

static const GEnumValue qmi_dms_uim_state_values[] = {
    { QMI_DMS_UIM_STATE_INITIALIZATION_COMPLETED, "QMI_DMS_UIM_STATE_INITIALIZATION_COMPLETED", "initialization-completed" },
    { QMI_DMS_UIM_STATE_LOCKED_OR_FAILED, "QMI_DMS_UIM_STATE_LOCKED_OR_FAILED", "locked-or-failed" },
    { QMI_DMS_UIM_STATE_NOT_PRESENT, "QMI_DMS_UIM_STATE_NOT_PRESENT", "not-present" },
    { QMI_DMS_UIM_STATE_RESERVED, "QMI_DMS_UIM_STATE_RESERVED", "reserved" },
    { QMI_DMS_UIM_STATE_UNKNOWN, "QMI_DMS_UIM_STATE_UNKNOWN", "unknown" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_dms_uim_state_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiDmsUimState"),
                                      qmi_dms_uim_state_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_DMS_UIM_STATE_IS_ENUM__
/**
 * qmi_dms_uim_state_get_string:
 * @val: a QmiDmsUimState.
 *
 * Gets the nickname string for the #QmiDmsUimState specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_dms_uim_state_get_string (QmiDmsUimState val)
{
    guint i;

    for (i = 0; qmi_dms_uim_state_values[i].value_nick; i++) {
        if (val == qmi_dms_uim_state_values[i].value)
            return qmi_dms_uim_state_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_DMS_UIM_STATE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_DMS_UIM_STATE_IS_FLAGS__
/**
 * qmi_dms_uim_state_build_string_from_mask:
 * @mask: bitmask of QmiDmsUimState values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiDmsUimState in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_dms_uim_state_build_string_from_mask (QmiDmsUimState mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_dms_uim_state_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_dms_uim_state_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_dms_uim_state_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_dms_uim_state_values[i].value) {
            guint c;
            gulong number = qmi_dms_uim_state_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_dms_uim_state_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_DMS_UIM_STATE_IS_FLAGS__ */

static const GEnumValue qmi_dms_time_reference_type_values[] = {
    { QMI_DMS_TIME_REFERENCE_TYPE_USER, "QMI_DMS_TIME_REFERENCE_TYPE_USER", "user" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_dms_time_reference_type_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiDmsTimeReferenceType"),
                                      qmi_dms_time_reference_type_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_DMS_TIME_REFERENCE_TYPE_IS_ENUM__
/**
 * qmi_dms_time_reference_type_get_string:
 * @val: a QmiDmsTimeReferenceType.
 *
 * Gets the nickname string for the #QmiDmsTimeReferenceType specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_dms_time_reference_type_get_string (QmiDmsTimeReferenceType val)
{
    guint i;

    for (i = 0; qmi_dms_time_reference_type_values[i].value_nick; i++) {
        if (val == qmi_dms_time_reference_type_values[i].value)
            return qmi_dms_time_reference_type_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_DMS_TIME_REFERENCE_TYPE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_DMS_TIME_REFERENCE_TYPE_IS_FLAGS__
/**
 * qmi_dms_time_reference_type_build_string_from_mask:
 * @mask: bitmask of QmiDmsTimeReferenceType values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiDmsTimeReferenceType in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_dms_time_reference_type_build_string_from_mask (QmiDmsTimeReferenceType mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_dms_time_reference_type_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_dms_time_reference_type_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_dms_time_reference_type_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_dms_time_reference_type_values[i].value) {
            guint c;
            gulong number = qmi_dms_time_reference_type_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_dms_time_reference_type_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_DMS_TIME_REFERENCE_TYPE_IS_FLAGS__ */

static const GEnumValue qmi_dms_firmware_image_type_values[] = {
    { QMI_DMS_FIRMWARE_IMAGE_TYPE_MODEM, "QMI_DMS_FIRMWARE_IMAGE_TYPE_MODEM", "modem" },
    { QMI_DMS_FIRMWARE_IMAGE_TYPE_PRI, "QMI_DMS_FIRMWARE_IMAGE_TYPE_PRI", "pri" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_dms_firmware_image_type_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiDmsFirmwareImageType"),
                                      qmi_dms_firmware_image_type_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_DMS_FIRMWARE_IMAGE_TYPE_IS_ENUM__
/**
 * qmi_dms_firmware_image_type_get_string:
 * @val: a QmiDmsFirmwareImageType.
 *
 * Gets the nickname string for the #QmiDmsFirmwareImageType specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_dms_firmware_image_type_get_string (QmiDmsFirmwareImageType val)
{
    guint i;

    for (i = 0; qmi_dms_firmware_image_type_values[i].value_nick; i++) {
        if (val == qmi_dms_firmware_image_type_values[i].value)
            return qmi_dms_firmware_image_type_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_DMS_FIRMWARE_IMAGE_TYPE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_DMS_FIRMWARE_IMAGE_TYPE_IS_FLAGS__
/**
 * qmi_dms_firmware_image_type_build_string_from_mask:
 * @mask: bitmask of QmiDmsFirmwareImageType values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiDmsFirmwareImageType in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_dms_firmware_image_type_build_string_from_mask (QmiDmsFirmwareImageType mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_dms_firmware_image_type_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_dms_firmware_image_type_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_dms_firmware_image_type_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_dms_firmware_image_type_values[i].value) {
            guint c;
            gulong number = qmi_dms_firmware_image_type_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_dms_firmware_image_type_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_DMS_FIRMWARE_IMAGE_TYPE_IS_FLAGS__ */

/* enumerations from "../../libqmi-glib/qmi-enums-nas.h" */
static const GEnumValue qmi_nas_radio_interface_values[] = {
    { QMI_NAS_RADIO_INTERFACE_UNKNOWN, "QMI_NAS_RADIO_INTERFACE_UNKNOWN", "unknown" },
    { QMI_NAS_RADIO_INTERFACE_NONE, "QMI_NAS_RADIO_INTERFACE_NONE", "none" },
    { QMI_NAS_RADIO_INTERFACE_CDMA_1X, "QMI_NAS_RADIO_INTERFACE_CDMA_1X", "cdma-1x" },
    { QMI_NAS_RADIO_INTERFACE_CDMA_1XEVDO, "QMI_NAS_RADIO_INTERFACE_CDMA_1XEVDO", "cdma-1xevdo" },
    { QMI_NAS_RADIO_INTERFACE_AMPS, "QMI_NAS_RADIO_INTERFACE_AMPS", "amps" },
    { QMI_NAS_RADIO_INTERFACE_GSM, "QMI_NAS_RADIO_INTERFACE_GSM", "gsm" },
    { QMI_NAS_RADIO_INTERFACE_UMTS, "QMI_NAS_RADIO_INTERFACE_UMTS", "umts" },
    { QMI_NAS_RADIO_INTERFACE_LTE, "QMI_NAS_RADIO_INTERFACE_LTE", "lte" },
    { QMI_NAS_RADIO_INTERFACE_TD_SCDMA, "QMI_NAS_RADIO_INTERFACE_TD_SCDMA", "td-scdma" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_radio_interface_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasRadioInterface"),
                                      qmi_nas_radio_interface_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_RADIO_INTERFACE_IS_ENUM__
/**
 * qmi_nas_radio_interface_get_string:
 * @val: a QmiNasRadioInterface.
 *
 * Gets the nickname string for the #QmiNasRadioInterface specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_radio_interface_get_string (QmiNasRadioInterface val)
{
    guint i;

    for (i = 0; qmi_nas_radio_interface_values[i].value_nick; i++) {
        if (val == qmi_nas_radio_interface_values[i].value)
            return qmi_nas_radio_interface_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_RADIO_INTERFACE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_RADIO_INTERFACE_IS_FLAGS__
/**
 * qmi_nas_radio_interface_build_string_from_mask:
 * @mask: bitmask of QmiNasRadioInterface values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasRadioInterface in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_radio_interface_build_string_from_mask (QmiNasRadioInterface mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_radio_interface_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_radio_interface_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_radio_interface_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_radio_interface_values[i].value) {
            guint c;
            gulong number = qmi_nas_radio_interface_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_radio_interface_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_RADIO_INTERFACE_IS_FLAGS__ */

static const GEnumValue qmi_nas_active_band_values[] = {
    { QMI_NAS_ACTIVE_BAND_BC_0, "QMI_NAS_ACTIVE_BAND_BC_0", "bc-0" },
    { QMI_NAS_ACTIVE_BAND_BC_1, "QMI_NAS_ACTIVE_BAND_BC_1", "bc-1" },
    { QMI_NAS_ACTIVE_BAND_BC_2, "QMI_NAS_ACTIVE_BAND_BC_2", "bc-2" },
    { QMI_NAS_ACTIVE_BAND_BC_3, "QMI_NAS_ACTIVE_BAND_BC_3", "bc-3" },
    { QMI_NAS_ACTIVE_BAND_BC_4, "QMI_NAS_ACTIVE_BAND_BC_4", "bc-4" },
    { QMI_NAS_ACTIVE_BAND_BC_5, "QMI_NAS_ACTIVE_BAND_BC_5", "bc-5" },
    { QMI_NAS_ACTIVE_BAND_BC_6, "QMI_NAS_ACTIVE_BAND_BC_6", "bc-6" },
    { QMI_NAS_ACTIVE_BAND_BC_7, "QMI_NAS_ACTIVE_BAND_BC_7", "bc-7" },
    { QMI_NAS_ACTIVE_BAND_BC_8, "QMI_NAS_ACTIVE_BAND_BC_8", "bc-8" },
    { QMI_NAS_ACTIVE_BAND_BC_9, "QMI_NAS_ACTIVE_BAND_BC_9", "bc-9" },
    { QMI_NAS_ACTIVE_BAND_BC_10, "QMI_NAS_ACTIVE_BAND_BC_10", "bc-10" },
    { QMI_NAS_ACTIVE_BAND_BC_11, "QMI_NAS_ACTIVE_BAND_BC_11", "bc-11" },
    { QMI_NAS_ACTIVE_BAND_BC_12, "QMI_NAS_ACTIVE_BAND_BC_12", "bc-12" },
    { QMI_NAS_ACTIVE_BAND_BC_13, "QMI_NAS_ACTIVE_BAND_BC_13", "bc-13" },
    { QMI_NAS_ACTIVE_BAND_BC_14, "QMI_NAS_ACTIVE_BAND_BC_14", "bc-14" },
    { QMI_NAS_ACTIVE_BAND_BC_15, "QMI_NAS_ACTIVE_BAND_BC_15", "bc-15" },
    { QMI_NAS_ACTIVE_BAND_BC_16, "QMI_NAS_ACTIVE_BAND_BC_16", "bc-16" },
    { QMI_NAS_ACTIVE_BAND_BC_17, "QMI_NAS_ACTIVE_BAND_BC_17", "bc-17" },
    { QMI_NAS_ACTIVE_BAND_BC_18, "QMI_NAS_ACTIVE_BAND_BC_18", "bc-18" },
    { QMI_NAS_ACTIVE_BAND_BC_19, "QMI_NAS_ACTIVE_BAND_BC_19", "bc-19" },
    { QMI_NAS_ACTIVE_BAND_GSM_450, "QMI_NAS_ACTIVE_BAND_GSM_450", "gsm-450" },
    { QMI_NAS_ACTIVE_BAND_GSM_480, "QMI_NAS_ACTIVE_BAND_GSM_480", "gsm-480" },
    { QMI_NAS_ACTIVE_BAND_GSM_750, "QMI_NAS_ACTIVE_BAND_GSM_750", "gsm-750" },
    { QMI_NAS_ACTIVE_BAND_GSM_850, "QMI_NAS_ACTIVE_BAND_GSM_850", "gsm-850" },
    { QMI_NAS_ACTIVE_BAND_GSM_900_EXTENDED, "QMI_NAS_ACTIVE_BAND_GSM_900_EXTENDED", "gsm-900-extended" },
    { QMI_NAS_ACTIVE_BAND_GSM_900_PRIMARY, "QMI_NAS_ACTIVE_BAND_GSM_900_PRIMARY", "gsm-900-primary" },
    { QMI_NAS_ACTIVE_BAND_GSM_900_RAILWAYS, "QMI_NAS_ACTIVE_BAND_GSM_900_RAILWAYS", "gsm-900-railways" },
    { QMI_NAS_ACTIVE_BAND_GSM_DCS_1800, "QMI_NAS_ACTIVE_BAND_GSM_DCS_1800", "gsm-dcs-1800" },
    { QMI_NAS_ACTIVE_BAND_GSM_PCS_1900, "QMI_NAS_ACTIVE_BAND_GSM_PCS_1900", "gsm-pcs-1900" },
    { QMI_NAS_ACTIVE_BAND_WCDMA_2100, "QMI_NAS_ACTIVE_BAND_WCDMA_2100", "wcdma-2100" },
    { QMI_NAS_ACTIVE_BAND_WCDMA_PCS_1900, "QMI_NAS_ACTIVE_BAND_WCDMA_PCS_1900", "wcdma-pcs-1900" },
    { QMI_NAS_ACTIVE_BAND_WCDMA_DCS_1800, "QMI_NAS_ACTIVE_BAND_WCDMA_DCS_1800", "wcdma-dcs-1800" },
    { QMI_NAS_ACTIVE_BAND_WCDMA_1700_US, "QMI_NAS_ACTIVE_BAND_WCDMA_1700_US", "wcdma-1700-us" },
    { QMI_NAS_ACTIVE_BAND_WCDMA_850, "QMI_NAS_ACTIVE_BAND_WCDMA_850", "wcdma-850" },
    { QMI_NAS_ACTIVE_BAND_WCDMA_800, "QMI_NAS_ACTIVE_BAND_WCDMA_800", "wcdma-800" },
    { QMI_NAS_ACTIVE_BAND_WCDMA_2600, "QMI_NAS_ACTIVE_BAND_WCDMA_2600", "wcdma-2600" },
    { QMI_NAS_ACTIVE_BAND_WCDMA_900, "QMI_NAS_ACTIVE_BAND_WCDMA_900", "wcdma-900" },
    { QMI_NAS_ACTIVE_BAND_WCDMA_1700_JAPAN, "QMI_NAS_ACTIVE_BAND_WCDMA_1700_JAPAN", "wcdma-1700-japan" },
    { QMI_NAS_ACTIVE_BAND_WCDMA_1500_JAPAN, "QMI_NAS_ACTIVE_BAND_WCDMA_1500_JAPAN", "wcdma-1500-japan" },
    { QMI_NAS_ACTIVE_BAND_WCDMA_850_JAPAN, "QMI_NAS_ACTIVE_BAND_WCDMA_850_JAPAN", "wcdma-850-japan" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_1, "QMI_NAS_ACTIVE_BAND_EUTRAN_1", "eutran-1" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_2, "QMI_NAS_ACTIVE_BAND_EUTRAN_2", "eutran-2" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_3, "QMI_NAS_ACTIVE_BAND_EUTRAN_3", "eutran-3" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_4, "QMI_NAS_ACTIVE_BAND_EUTRAN_4", "eutran-4" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_5, "QMI_NAS_ACTIVE_BAND_EUTRAN_5", "eutran-5" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_6, "QMI_NAS_ACTIVE_BAND_EUTRAN_6", "eutran-6" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_7, "QMI_NAS_ACTIVE_BAND_EUTRAN_7", "eutran-7" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_8, "QMI_NAS_ACTIVE_BAND_EUTRAN_8", "eutran-8" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_9, "QMI_NAS_ACTIVE_BAND_EUTRAN_9", "eutran-9" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_10, "QMI_NAS_ACTIVE_BAND_EUTRAN_10", "eutran-10" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_11, "QMI_NAS_ACTIVE_BAND_EUTRAN_11", "eutran-11" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_12, "QMI_NAS_ACTIVE_BAND_EUTRAN_12", "eutran-12" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_13, "QMI_NAS_ACTIVE_BAND_EUTRAN_13", "eutran-13" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_14, "QMI_NAS_ACTIVE_BAND_EUTRAN_14", "eutran-14" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_17, "QMI_NAS_ACTIVE_BAND_EUTRAN_17", "eutran-17" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_18, "QMI_NAS_ACTIVE_BAND_EUTRAN_18", "eutran-18" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_19, "QMI_NAS_ACTIVE_BAND_EUTRAN_19", "eutran-19" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_20, "QMI_NAS_ACTIVE_BAND_EUTRAN_20", "eutran-20" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_21, "QMI_NAS_ACTIVE_BAND_EUTRAN_21", "eutran-21" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_24, "QMI_NAS_ACTIVE_BAND_EUTRAN_24", "eutran-24" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_25, "QMI_NAS_ACTIVE_BAND_EUTRAN_25", "eutran-25" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_33, "QMI_NAS_ACTIVE_BAND_EUTRAN_33", "eutran-33" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_34, "QMI_NAS_ACTIVE_BAND_EUTRAN_34", "eutran-34" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_35, "QMI_NAS_ACTIVE_BAND_EUTRAN_35", "eutran-35" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_36, "QMI_NAS_ACTIVE_BAND_EUTRAN_36", "eutran-36" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_37, "QMI_NAS_ACTIVE_BAND_EUTRAN_37", "eutran-37" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_38, "QMI_NAS_ACTIVE_BAND_EUTRAN_38", "eutran-38" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_39, "QMI_NAS_ACTIVE_BAND_EUTRAN_39", "eutran-39" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_40, "QMI_NAS_ACTIVE_BAND_EUTRAN_40", "eutran-40" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_41, "QMI_NAS_ACTIVE_BAND_EUTRAN_41", "eutran-41" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_42, "QMI_NAS_ACTIVE_BAND_EUTRAN_42", "eutran-42" },
    { QMI_NAS_ACTIVE_BAND_EUTRAN_43, "QMI_NAS_ACTIVE_BAND_EUTRAN_43", "eutran-43" },
    { QMI_NAS_ACTIVE_BAND_TDSCDMA_A, "QMI_NAS_ACTIVE_BAND_TDSCDMA_A", "tdscdma-a" },
    { QMI_NAS_ACTIVE_BAND_TDSCDMA_B, "QMI_NAS_ACTIVE_BAND_TDSCDMA_B", "tdscdma-b" },
    { QMI_NAS_ACTIVE_BAND_TDSCDMA_C, "QMI_NAS_ACTIVE_BAND_TDSCDMA_C", "tdscdma-c" },
    { QMI_NAS_ACTIVE_BAND_TDSCDMA_D, "QMI_NAS_ACTIVE_BAND_TDSCDMA_D", "tdscdma-d" },
    { QMI_NAS_ACTIVE_BAND_TDSCDMA_E, "QMI_NAS_ACTIVE_BAND_TDSCDMA_E", "tdscdma-e" },
    { QMI_NAS_ACTIVE_BAND_TDSCDMA_F, "QMI_NAS_ACTIVE_BAND_TDSCDMA_F", "tdscdma-f" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_active_band_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasActiveBand"),
                                      qmi_nas_active_band_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_ACTIVE_BAND_IS_ENUM__
/**
 * qmi_nas_active_band_get_string:
 * @val: a QmiNasActiveBand.
 *
 * Gets the nickname string for the #QmiNasActiveBand specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_active_band_get_string (QmiNasActiveBand val)
{
    guint i;

    for (i = 0; qmi_nas_active_band_values[i].value_nick; i++) {
        if (val == qmi_nas_active_band_values[i].value)
            return qmi_nas_active_band_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_ACTIVE_BAND_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_ACTIVE_BAND_IS_FLAGS__
/**
 * qmi_nas_active_band_build_string_from_mask:
 * @mask: bitmask of QmiNasActiveBand values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasActiveBand in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_active_band_build_string_from_mask (QmiNasActiveBand mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_active_band_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_active_band_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_active_band_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_active_band_values[i].value) {
            guint c;
            gulong number = qmi_nas_active_band_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_active_band_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_ACTIVE_BAND_IS_FLAGS__ */

static const GEnumValue qmi_nas_network_service_domain_values[] = {
    { QMI_NAS_NETWORK_SERVICE_DOMAIN_NONE, "QMI_NAS_NETWORK_SERVICE_DOMAIN_NONE", "none" },
    { QMI_NAS_NETWORK_SERVICE_DOMAIN_CS, "QMI_NAS_NETWORK_SERVICE_DOMAIN_CS", "cs" },
    { QMI_NAS_NETWORK_SERVICE_DOMAIN_PS, "QMI_NAS_NETWORK_SERVICE_DOMAIN_PS", "ps" },
    { QMI_NAS_NETWORK_SERVICE_DOMAIN_CS_PS, "QMI_NAS_NETWORK_SERVICE_DOMAIN_CS_PS", "cs-ps" },
    { QMI_NAS_NETWORK_SERVICE_DOMAIN_UNKNOWN, "QMI_NAS_NETWORK_SERVICE_DOMAIN_UNKNOWN", "unknown" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_network_service_domain_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasNetworkServiceDomain"),
                                      qmi_nas_network_service_domain_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_NETWORK_SERVICE_DOMAIN_IS_ENUM__
/**
 * qmi_nas_network_service_domain_get_string:
 * @val: a QmiNasNetworkServiceDomain.
 *
 * Gets the nickname string for the #QmiNasNetworkServiceDomain specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_network_service_domain_get_string (QmiNasNetworkServiceDomain val)
{
    guint i;

    for (i = 0; qmi_nas_network_service_domain_values[i].value_nick; i++) {
        if (val == qmi_nas_network_service_domain_values[i].value)
            return qmi_nas_network_service_domain_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_NETWORK_SERVICE_DOMAIN_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_NETWORK_SERVICE_DOMAIN_IS_FLAGS__
/**
 * qmi_nas_network_service_domain_build_string_from_mask:
 * @mask: bitmask of QmiNasNetworkServiceDomain values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasNetworkServiceDomain in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_network_service_domain_build_string_from_mask (QmiNasNetworkServiceDomain mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_network_service_domain_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_network_service_domain_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_network_service_domain_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_network_service_domain_values[i].value) {
            guint c;
            gulong number = qmi_nas_network_service_domain_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_network_service_domain_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_NETWORK_SERVICE_DOMAIN_IS_FLAGS__ */

static const GEnumValue qmi_nas_evdo_sinr_level_values[] = {
    { QMI_NAS_EVDO_SINR_LEVEL_0, "QMI_NAS_EVDO_SINR_LEVEL_0", "0" },
    { QMI_NAS_EVDO_SINR_LEVEL_1, "QMI_NAS_EVDO_SINR_LEVEL_1", "1" },
    { QMI_NAS_EVDO_SINR_LEVEL_2, "QMI_NAS_EVDO_SINR_LEVEL_2", "2" },
    { QMI_NAS_EVDO_SINR_LEVEL_3, "QMI_NAS_EVDO_SINR_LEVEL_3", "3" },
    { QMI_NAS_EVDO_SINR_LEVEL_4, "QMI_NAS_EVDO_SINR_LEVEL_4", "4" },
    { QMI_NAS_EVDO_SINR_LEVEL_5, "QMI_NAS_EVDO_SINR_LEVEL_5", "5" },
    { QMI_NAS_EVDO_SINR_LEVEL_6, "QMI_NAS_EVDO_SINR_LEVEL_6", "6" },
    { QMI_NAS_EVDO_SINR_LEVEL_7, "QMI_NAS_EVDO_SINR_LEVEL_7", "7" },
    { QMI_NAS_EVDO_SINR_LEVEL_8, "QMI_NAS_EVDO_SINR_LEVEL_8", "8" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_evdo_sinr_level_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasEvdoSinrLevel"),
                                      qmi_nas_evdo_sinr_level_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_EVDO_SINR_LEVEL_IS_ENUM__
/**
 * qmi_nas_evdo_sinr_level_get_string:
 * @val: a QmiNasEvdoSinrLevel.
 *
 * Gets the nickname string for the #QmiNasEvdoSinrLevel specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_evdo_sinr_level_get_string (QmiNasEvdoSinrLevel val)
{
    guint i;

    for (i = 0; qmi_nas_evdo_sinr_level_values[i].value_nick; i++) {
        if (val == qmi_nas_evdo_sinr_level_values[i].value)
            return qmi_nas_evdo_sinr_level_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_EVDO_SINR_LEVEL_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_EVDO_SINR_LEVEL_IS_FLAGS__
/**
 * qmi_nas_evdo_sinr_level_build_string_from_mask:
 * @mask: bitmask of QmiNasEvdoSinrLevel values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasEvdoSinrLevel in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_evdo_sinr_level_build_string_from_mask (QmiNasEvdoSinrLevel mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_evdo_sinr_level_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_evdo_sinr_level_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_evdo_sinr_level_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_evdo_sinr_level_values[i].value) {
            guint c;
            gulong number = qmi_nas_evdo_sinr_level_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_evdo_sinr_level_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_EVDO_SINR_LEVEL_IS_FLAGS__ */

static const GFlagsValue qmi_nas_signal_strength_request_values[] = {
    { QMI_NAS_SIGNAL_STRENGTH_REQUEST_NONE, "QMI_NAS_SIGNAL_STRENGTH_REQUEST_NONE", "none" },
    { QMI_NAS_SIGNAL_STRENGTH_REQUEST_RSSI, "QMI_NAS_SIGNAL_STRENGTH_REQUEST_RSSI", "rssi" },
    { QMI_NAS_SIGNAL_STRENGTH_REQUEST_ECIO, "QMI_NAS_SIGNAL_STRENGTH_REQUEST_ECIO", "ecio" },
    { QMI_NAS_SIGNAL_STRENGTH_REQUEST_IO, "QMI_NAS_SIGNAL_STRENGTH_REQUEST_IO", "io" },
    { QMI_NAS_SIGNAL_STRENGTH_REQUEST_SINR, "QMI_NAS_SIGNAL_STRENGTH_REQUEST_SINR", "sinr" },
    { QMI_NAS_SIGNAL_STRENGTH_REQUEST_ERROR_RATE, "QMI_NAS_SIGNAL_STRENGTH_REQUEST_ERROR_RATE", "error-rate" },
    { QMI_NAS_SIGNAL_STRENGTH_REQUEST_RSRQ, "QMI_NAS_SIGNAL_STRENGTH_REQUEST_RSRQ", "rsrq" },
    { QMI_NAS_SIGNAL_STRENGTH_REQUEST_LTE_SNR, "QMI_NAS_SIGNAL_STRENGTH_REQUEST_LTE_SNR", "lte-snr" },
    { QMI_NAS_SIGNAL_STRENGTH_REQUEST_LTE_RSRP, "QMI_NAS_SIGNAL_STRENGTH_REQUEST_LTE_RSRP", "lte-rsrp" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_signal_strength_request_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("QmiNasSignalStrengthRequest"),
                                      qmi_nas_signal_strength_request_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_SIGNAL_STRENGTH_REQUEST_IS_ENUM__
/**
 * qmi_nas_signal_strength_request_get_string:
 * @val: a QmiNasSignalStrengthRequest.
 *
 * Gets the nickname string for the #QmiNasSignalStrengthRequest specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_signal_strength_request_get_string (QmiNasSignalStrengthRequest val)
{
    guint i;

    for (i = 0; qmi_nas_signal_strength_request_values[i].value_nick; i++) {
        if (val == qmi_nas_signal_strength_request_values[i].value)
            return qmi_nas_signal_strength_request_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_SIGNAL_STRENGTH_REQUEST_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_SIGNAL_STRENGTH_REQUEST_IS_FLAGS__
/**
 * qmi_nas_signal_strength_request_build_string_from_mask:
 * @mask: bitmask of QmiNasSignalStrengthRequest values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasSignalStrengthRequest in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_signal_strength_request_build_string_from_mask (QmiNasSignalStrengthRequest mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_signal_strength_request_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_signal_strength_request_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_signal_strength_request_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_signal_strength_request_values[i].value) {
            guint c;
            gulong number = qmi_nas_signal_strength_request_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_signal_strength_request_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_SIGNAL_STRENGTH_REQUEST_IS_FLAGS__ */

static const GFlagsValue qmi_nas_network_scan_type_values[] = {
    { QMI_NAS_NETWORK_SCAN_TYPE_GSM, "QMI_NAS_NETWORK_SCAN_TYPE_GSM", "gsm" },
    { QMI_NAS_NETWORK_SCAN_TYPE_UMTS, "QMI_NAS_NETWORK_SCAN_TYPE_UMTS", "umts" },
    { QMI_NAS_NETWORK_SCAN_TYPE_LTE, "QMI_NAS_NETWORK_SCAN_TYPE_LTE", "lte" },
    { QMI_NAS_NETWORK_SCAN_TYPE_TD_SCDMA, "QMI_NAS_NETWORK_SCAN_TYPE_TD_SCDMA", "td-scdma" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_network_scan_type_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("QmiNasNetworkScanType"),
                                      qmi_nas_network_scan_type_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_NETWORK_SCAN_TYPE_IS_ENUM__
/**
 * qmi_nas_network_scan_type_get_string:
 * @val: a QmiNasNetworkScanType.
 *
 * Gets the nickname string for the #QmiNasNetworkScanType specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_network_scan_type_get_string (QmiNasNetworkScanType val)
{
    guint i;

    for (i = 0; qmi_nas_network_scan_type_values[i].value_nick; i++) {
        if (val == qmi_nas_network_scan_type_values[i].value)
            return qmi_nas_network_scan_type_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_NETWORK_SCAN_TYPE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_NETWORK_SCAN_TYPE_IS_FLAGS__
/**
 * qmi_nas_network_scan_type_build_string_from_mask:
 * @mask: bitmask of QmiNasNetworkScanType values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasNetworkScanType in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_network_scan_type_build_string_from_mask (QmiNasNetworkScanType mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_network_scan_type_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_network_scan_type_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_network_scan_type_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_network_scan_type_values[i].value) {
            guint c;
            gulong number = qmi_nas_network_scan_type_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_network_scan_type_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_NETWORK_SCAN_TYPE_IS_FLAGS__ */

static const GFlagsValue qmi_nas_network_status_values[] = {
    { QMI_NAS_NETWORK_STATUS_CURRENT_SERVING, "QMI_NAS_NETWORK_STATUS_CURRENT_SERVING", "current-serving" },
    { QMI_NAS_NETWORK_STATUS_AVAILABLE, "QMI_NAS_NETWORK_STATUS_AVAILABLE", "available" },
    { QMI_NAS_NETWORK_STATUS_HOME, "QMI_NAS_NETWORK_STATUS_HOME", "home" },
    { QMI_NAS_NETWORK_STATUS_ROAMING, "QMI_NAS_NETWORK_STATUS_ROAMING", "roaming" },
    { QMI_NAS_NETWORK_STATUS_FORBIDDEN, "QMI_NAS_NETWORK_STATUS_FORBIDDEN", "forbidden" },
    { QMI_NAS_NETWORK_STATUS_NOT_FORBIDDEN, "QMI_NAS_NETWORK_STATUS_NOT_FORBIDDEN", "not-forbidden" },
    { QMI_NAS_NETWORK_STATUS_PREFERRED, "QMI_NAS_NETWORK_STATUS_PREFERRED", "preferred" },
    { QMI_NAS_NETWORK_STATUS_NOT_PREFERRED, "QMI_NAS_NETWORK_STATUS_NOT_PREFERRED", "not-preferred" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_network_status_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("QmiNasNetworkStatus"),
                                      qmi_nas_network_status_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_NETWORK_STATUS_IS_ENUM__
/**
 * qmi_nas_network_status_get_string:
 * @val: a QmiNasNetworkStatus.
 *
 * Gets the nickname string for the #QmiNasNetworkStatus specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_network_status_get_string (QmiNasNetworkStatus val)
{
    guint i;

    for (i = 0; qmi_nas_network_status_values[i].value_nick; i++) {
        if (val == qmi_nas_network_status_values[i].value)
            return qmi_nas_network_status_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_NETWORK_STATUS_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_NETWORK_STATUS_IS_FLAGS__
/**
 * qmi_nas_network_status_build_string_from_mask:
 * @mask: bitmask of QmiNasNetworkStatus values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasNetworkStatus in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_network_status_build_string_from_mask (QmiNasNetworkStatus mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_network_status_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_network_status_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_network_status_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_network_status_values[i].value) {
            guint c;
            gulong number = qmi_nas_network_status_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_network_status_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_NETWORK_STATUS_IS_FLAGS__ */

static const GEnumValue qmi_nas_network_register_type_values[] = {
    { QMI_NAS_NETWORK_REGISTER_TYPE_AUTOMATIC, "QMI_NAS_NETWORK_REGISTER_TYPE_AUTOMATIC", "automatic" },
    { QMI_NAS_NETWORK_REGISTER_TYPE_MANUAL, "QMI_NAS_NETWORK_REGISTER_TYPE_MANUAL", "manual" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_network_register_type_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasNetworkRegisterType"),
                                      qmi_nas_network_register_type_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_NETWORK_REGISTER_TYPE_IS_ENUM__
/**
 * qmi_nas_network_register_type_get_string:
 * @val: a QmiNasNetworkRegisterType.
 *
 * Gets the nickname string for the #QmiNasNetworkRegisterType specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_network_register_type_get_string (QmiNasNetworkRegisterType val)
{
    guint i;

    for (i = 0; qmi_nas_network_register_type_values[i].value_nick; i++) {
        if (val == qmi_nas_network_register_type_values[i].value)
            return qmi_nas_network_register_type_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_NETWORK_REGISTER_TYPE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_NETWORK_REGISTER_TYPE_IS_FLAGS__
/**
 * qmi_nas_network_register_type_build_string_from_mask:
 * @mask: bitmask of QmiNasNetworkRegisterType values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasNetworkRegisterType in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_network_register_type_build_string_from_mask (QmiNasNetworkRegisterType mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_network_register_type_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_network_register_type_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_network_register_type_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_network_register_type_values[i].value) {
            guint c;
            gulong number = qmi_nas_network_register_type_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_network_register_type_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_NETWORK_REGISTER_TYPE_IS_FLAGS__ */

static const GEnumValue qmi_nas_registration_state_values[] = {
    { QMI_NAS_REGISTRATION_STATE_NOT_REGISTERED, "QMI_NAS_REGISTRATION_STATE_NOT_REGISTERED", "not-registered" },
    { QMI_NAS_REGISTRATION_STATE_REGISTERED, "QMI_NAS_REGISTRATION_STATE_REGISTERED", "registered" },
    { QMI_NAS_REGISTRATION_STATE_NOT_REGISTERED_SEARCHING, "QMI_NAS_REGISTRATION_STATE_NOT_REGISTERED_SEARCHING", "not-registered-searching" },
    { QMI_NAS_REGISTRATION_STATE_REGISTRATION_DENIED, "QMI_NAS_REGISTRATION_STATE_REGISTRATION_DENIED", "registration-denied" },
    { QMI_NAS_REGISTRATION_STATE_UNKNOWN, "QMI_NAS_REGISTRATION_STATE_UNKNOWN", "unknown" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_registration_state_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasRegistrationState"),
                                      qmi_nas_registration_state_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_REGISTRATION_STATE_IS_ENUM__
/**
 * qmi_nas_registration_state_get_string:
 * @val: a QmiNasRegistrationState.
 *
 * Gets the nickname string for the #QmiNasRegistrationState specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_registration_state_get_string (QmiNasRegistrationState val)
{
    guint i;

    for (i = 0; qmi_nas_registration_state_values[i].value_nick; i++) {
        if (val == qmi_nas_registration_state_values[i].value)
            return qmi_nas_registration_state_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_REGISTRATION_STATE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_REGISTRATION_STATE_IS_FLAGS__
/**
 * qmi_nas_registration_state_build_string_from_mask:
 * @mask: bitmask of QmiNasRegistrationState values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasRegistrationState in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_registration_state_build_string_from_mask (QmiNasRegistrationState mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_registration_state_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_registration_state_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_registration_state_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_registration_state_values[i].value) {
            guint c;
            gulong number = qmi_nas_registration_state_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_registration_state_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_REGISTRATION_STATE_IS_FLAGS__ */

static const GEnumValue qmi_nas_attach_state_values[] = {
    { QMI_NAS_ATTACH_STATE_UNKNOWN, "QMI_NAS_ATTACH_STATE_UNKNOWN", "unknown" },
    { QMI_NAS_ATTACH_STATE_ATTACHED, "QMI_NAS_ATTACH_STATE_ATTACHED", "attached" },
    { QMI_NAS_ATTACH_STATE_DETACHED, "QMI_NAS_ATTACH_STATE_DETACHED", "detached" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_attach_state_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasAttachState"),
                                      qmi_nas_attach_state_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_ATTACH_STATE_IS_ENUM__
/**
 * qmi_nas_attach_state_get_string:
 * @val: a QmiNasAttachState.
 *
 * Gets the nickname string for the #QmiNasAttachState specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_attach_state_get_string (QmiNasAttachState val)
{
    guint i;

    for (i = 0; qmi_nas_attach_state_values[i].value_nick; i++) {
        if (val == qmi_nas_attach_state_values[i].value)
            return qmi_nas_attach_state_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_ATTACH_STATE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_ATTACH_STATE_IS_FLAGS__
/**
 * qmi_nas_attach_state_build_string_from_mask:
 * @mask: bitmask of QmiNasAttachState values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasAttachState in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_attach_state_build_string_from_mask (QmiNasAttachState mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_attach_state_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_attach_state_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_attach_state_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_attach_state_values[i].value) {
            guint c;
            gulong number = qmi_nas_attach_state_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_attach_state_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_ATTACH_STATE_IS_FLAGS__ */

static const GEnumValue qmi_nas_network_type_values[] = {
    { QMI_NAS_NETWORK_TYPE_UNKNOWN, "QMI_NAS_NETWORK_TYPE_UNKNOWN", "unknown" },
    { QMI_NAS_NETWORK_TYPE_3GPP2, "QMI_NAS_NETWORK_TYPE_3GPP2", "3gpp2" },
    { QMI_NAS_NETWORK_TYPE_3GPP, "QMI_NAS_NETWORK_TYPE_3GPP", "3gpp" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_network_type_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasNetworkType"),
                                      qmi_nas_network_type_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_NETWORK_TYPE_IS_ENUM__
/**
 * qmi_nas_network_type_get_string:
 * @val: a QmiNasNetworkType.
 *
 * Gets the nickname string for the #QmiNasNetworkType specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_network_type_get_string (QmiNasNetworkType val)
{
    guint i;

    for (i = 0; qmi_nas_network_type_values[i].value_nick; i++) {
        if (val == qmi_nas_network_type_values[i].value)
            return qmi_nas_network_type_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_NETWORK_TYPE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_NETWORK_TYPE_IS_FLAGS__
/**
 * qmi_nas_network_type_build_string_from_mask:
 * @mask: bitmask of QmiNasNetworkType values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasNetworkType in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_network_type_build_string_from_mask (QmiNasNetworkType mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_network_type_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_network_type_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_network_type_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_network_type_values[i].value) {
            guint c;
            gulong number = qmi_nas_network_type_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_network_type_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_NETWORK_TYPE_IS_FLAGS__ */

static const GEnumValue qmi_nas_roaming_indicator_status_values[] = {
    { QMI_NAS_ROAMING_INDICATOR_STATUS_ON, "QMI_NAS_ROAMING_INDICATOR_STATUS_ON", "on" },
    { QMI_NAS_ROAMING_INDICATOR_STATUS_OFF, "QMI_NAS_ROAMING_INDICATOR_STATUS_OFF", "off" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_roaming_indicator_status_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasRoamingIndicatorStatus"),
                                      qmi_nas_roaming_indicator_status_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_ROAMING_INDICATOR_STATUS_IS_ENUM__
/**
 * qmi_nas_roaming_indicator_status_get_string:
 * @val: a QmiNasRoamingIndicatorStatus.
 *
 * Gets the nickname string for the #QmiNasRoamingIndicatorStatus specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_roaming_indicator_status_get_string (QmiNasRoamingIndicatorStatus val)
{
    guint i;

    for (i = 0; qmi_nas_roaming_indicator_status_values[i].value_nick; i++) {
        if (val == qmi_nas_roaming_indicator_status_values[i].value)
            return qmi_nas_roaming_indicator_status_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_ROAMING_INDICATOR_STATUS_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_ROAMING_INDICATOR_STATUS_IS_FLAGS__
/**
 * qmi_nas_roaming_indicator_status_build_string_from_mask:
 * @mask: bitmask of QmiNasRoamingIndicatorStatus values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasRoamingIndicatorStatus in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_roaming_indicator_status_build_string_from_mask (QmiNasRoamingIndicatorStatus mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_roaming_indicator_status_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_roaming_indicator_status_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_roaming_indicator_status_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_roaming_indicator_status_values[i].value) {
            guint c;
            gulong number = qmi_nas_roaming_indicator_status_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_roaming_indicator_status_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_ROAMING_INDICATOR_STATUS_IS_FLAGS__ */

static const GEnumValue qmi_nas_data_capability_values[] = {
    { QMI_NAS_DATA_CAPABILITY_NONE, "QMI_NAS_DATA_CAPABILITY_NONE", "none" },
    { QMI_NAS_DATA_CAPABILITY_GPRS, "QMI_NAS_DATA_CAPABILITY_GPRS", "gprs" },
    { QMI_NAS_DATA_CAPABILITY_EDGE, "QMI_NAS_DATA_CAPABILITY_EDGE", "edge" },
    { QMI_NAS_DATA_CAPABILITY_HSDPA, "QMI_NAS_DATA_CAPABILITY_HSDPA", "hsdpa" },
    { QMI_NAS_DATA_CAPABILITY_HSUPA, "QMI_NAS_DATA_CAPABILITY_HSUPA", "hsupa" },
    { QMI_NAS_DATA_CAPABILITY_WCDMA, "QMI_NAS_DATA_CAPABILITY_WCDMA", "wcdma" },
    { QMI_NAS_DATA_CAPABILITY_CDMA, "QMI_NAS_DATA_CAPABILITY_CDMA", "cdma" },
    { QMI_NAS_DATA_CAPABILITY_EVDO_REV_0, "QMI_NAS_DATA_CAPABILITY_EVDO_REV_0", "evdo-rev-0" },
    { QMI_NAS_DATA_CAPABILITY_EVDO_REV_A, "QMI_NAS_DATA_CAPABILITY_EVDO_REV_A", "evdo-rev-a" },
    { QMI_NAS_DATA_CAPABILITY_GSM, "QMI_NAS_DATA_CAPABILITY_GSM", "gsm" },
    { QMI_NAS_DATA_CAPABILITY_EVDO_REV_B, "QMI_NAS_DATA_CAPABILITY_EVDO_REV_B", "evdo-rev-b" },
    { QMI_NAS_DATA_CAPABILITY_LTE, "QMI_NAS_DATA_CAPABILITY_LTE", "lte" },
    { QMI_NAS_DATA_CAPABILITY_HSDPA_PLUS, "QMI_NAS_DATA_CAPABILITY_HSDPA_PLUS", "hsdpa-plus" },
    { QMI_NAS_DATA_CAPABILITY_DC_HSDPA_PLUS, "QMI_NAS_DATA_CAPABILITY_DC_HSDPA_PLUS", "dc-hsdpa-plus" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_data_capability_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasDataCapability"),
                                      qmi_nas_data_capability_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_DATA_CAPABILITY_IS_ENUM__
/**
 * qmi_nas_data_capability_get_string:
 * @val: a QmiNasDataCapability.
 *
 * Gets the nickname string for the #QmiNasDataCapability specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_data_capability_get_string (QmiNasDataCapability val)
{
    guint i;

    for (i = 0; qmi_nas_data_capability_values[i].value_nick; i++) {
        if (val == qmi_nas_data_capability_values[i].value)
            return qmi_nas_data_capability_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_DATA_CAPABILITY_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_DATA_CAPABILITY_IS_FLAGS__
/**
 * qmi_nas_data_capability_build_string_from_mask:
 * @mask: bitmask of QmiNasDataCapability values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasDataCapability in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_data_capability_build_string_from_mask (QmiNasDataCapability mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_data_capability_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_data_capability_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_data_capability_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_data_capability_values[i].value) {
            guint c;
            gulong number = qmi_nas_data_capability_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_data_capability_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_DATA_CAPABILITY_IS_FLAGS__ */

static const GEnumValue qmi_nas_service_status_values[] = {
    { QMI_NAS_SERVICE_STATUS_NONE, "QMI_NAS_SERVICE_STATUS_NONE", "none" },
    { QMI_NAS_SERVICE_STATUS_LIMITED, "QMI_NAS_SERVICE_STATUS_LIMITED", "limited" },
    { QMI_NAS_SERVICE_STATUS_AVAILABLE, "QMI_NAS_SERVICE_STATUS_AVAILABLE", "available" },
    { QMI_NAS_SERVICE_STATUS_LIMITED_REGIONAL, "QMI_NAS_SERVICE_STATUS_LIMITED_REGIONAL", "limited-regional" },
    { QMI_NAS_SERVICE_STATUS_POWER_SAVE, "QMI_NAS_SERVICE_STATUS_POWER_SAVE", "power-save" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_service_status_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasServiceStatus"),
                                      qmi_nas_service_status_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_SERVICE_STATUS_IS_ENUM__
/**
 * qmi_nas_service_status_get_string:
 * @val: a QmiNasServiceStatus.
 *
 * Gets the nickname string for the #QmiNasServiceStatus specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_service_status_get_string (QmiNasServiceStatus val)
{
    guint i;

    for (i = 0; qmi_nas_service_status_values[i].value_nick; i++) {
        if (val == qmi_nas_service_status_values[i].value)
            return qmi_nas_service_status_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_SERVICE_STATUS_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_SERVICE_STATUS_IS_FLAGS__
/**
 * qmi_nas_service_status_build_string_from_mask:
 * @mask: bitmask of QmiNasServiceStatus values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasServiceStatus in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_service_status_build_string_from_mask (QmiNasServiceStatus mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_service_status_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_service_status_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_service_status_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_service_status_values[i].value) {
            guint c;
            gulong number = qmi_nas_service_status_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_service_status_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_SERVICE_STATUS_IS_FLAGS__ */

static const GEnumValue qmi_nas_hdr_personality_values[] = {
    { QMI_NAS_HDR_PERSONALITY_UNKNOWN, "QMI_NAS_HDR_PERSONALITY_UNKNOWN", "unknown" },
    { QMI_NAS_HDR_PERSONALITY_HRPD, "QMI_NAS_HDR_PERSONALITY_HRPD", "hrpd" },
    { QMI_NAS_HDR_PERSONALITY_EHRPD, "QMI_NAS_HDR_PERSONALITY_EHRPD", "ehrpd" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_hdr_personality_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasHdrPersonality"),
                                      qmi_nas_hdr_personality_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_HDR_PERSONALITY_IS_ENUM__
/**
 * qmi_nas_hdr_personality_get_string:
 * @val: a QmiNasHdrPersonality.
 *
 * Gets the nickname string for the #QmiNasHdrPersonality specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_hdr_personality_get_string (QmiNasHdrPersonality val)
{
    guint i;

    for (i = 0; qmi_nas_hdr_personality_values[i].value_nick; i++) {
        if (val == qmi_nas_hdr_personality_values[i].value)
            return qmi_nas_hdr_personality_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_HDR_PERSONALITY_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_HDR_PERSONALITY_IS_FLAGS__
/**
 * qmi_nas_hdr_personality_build_string_from_mask:
 * @mask: bitmask of QmiNasHdrPersonality values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasHdrPersonality in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_hdr_personality_build_string_from_mask (QmiNasHdrPersonality mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_hdr_personality_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_hdr_personality_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_hdr_personality_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_hdr_personality_values[i].value) {
            guint c;
            gulong number = qmi_nas_hdr_personality_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_hdr_personality_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_HDR_PERSONALITY_IS_FLAGS__ */

static const GEnumValue qmi_nas_call_barring_status_values[] = {
    { QMI_NAS_CALL_BARRING_STATUS_NORMAL_ONLY, "QMI_NAS_CALL_BARRING_STATUS_NORMAL_ONLY", "normal-only" },
    { QMI_NAS_CALL_BARRING_STATUS_EMERGENCY_ONLY, "QMI_NAS_CALL_BARRING_STATUS_EMERGENCY_ONLY", "emergency-only" },
    { QMI_NAS_CALL_BARRING_STATUS_NO_CALLS, "QMI_NAS_CALL_BARRING_STATUS_NO_CALLS", "no-calls" },
    { QMI_NAS_CALL_BARRING_STATUS_ALL_CALLS, "QMI_NAS_CALL_BARRING_STATUS_ALL_CALLS", "all-calls" },
    { QMI_NAS_CALL_BARRING_STATUS_UNKNOWN, "QMI_NAS_CALL_BARRING_STATUS_UNKNOWN", "unknown" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_call_barring_status_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasCallBarringStatus"),
                                      qmi_nas_call_barring_status_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_CALL_BARRING_STATUS_IS_ENUM__
/**
 * qmi_nas_call_barring_status_get_string:
 * @val: a QmiNasCallBarringStatus.
 *
 * Gets the nickname string for the #QmiNasCallBarringStatus specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_call_barring_status_get_string (QmiNasCallBarringStatus val)
{
    guint i;

    for (i = 0; qmi_nas_call_barring_status_values[i].value_nick; i++) {
        if (val == qmi_nas_call_barring_status_values[i].value)
            return qmi_nas_call_barring_status_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_CALL_BARRING_STATUS_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_CALL_BARRING_STATUS_IS_FLAGS__
/**
 * qmi_nas_call_barring_status_build_string_from_mask:
 * @mask: bitmask of QmiNasCallBarringStatus values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasCallBarringStatus in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_call_barring_status_build_string_from_mask (QmiNasCallBarringStatus mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_call_barring_status_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_call_barring_status_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_call_barring_status_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_call_barring_status_values[i].value) {
            guint c;
            gulong number = qmi_nas_call_barring_status_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_call_barring_status_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_CALL_BARRING_STATUS_IS_FLAGS__ */

static const GEnumValue qmi_nas_network_description_display_values[] = {
    { QMI_NAS_NETWORK_DESCRIPTION_DISPLAY_NO, "QMI_NAS_NETWORK_DESCRIPTION_DISPLAY_NO", "no" },
    { QMI_NAS_NETWORK_DESCRIPTION_DISPLAY_YES, "QMI_NAS_NETWORK_DESCRIPTION_DISPLAY_YES", "yes" },
    { QMI_NAS_NETWORK_DESCRIPTION_DISPLAY_UNKNOWN, "QMI_NAS_NETWORK_DESCRIPTION_DISPLAY_UNKNOWN", "unknown" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_network_description_display_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasNetworkDescriptionDisplay"),
                                      qmi_nas_network_description_display_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_NETWORK_DESCRIPTION_DISPLAY_IS_ENUM__
/**
 * qmi_nas_network_description_display_get_string:
 * @val: a QmiNasNetworkDescriptionDisplay.
 *
 * Gets the nickname string for the #QmiNasNetworkDescriptionDisplay specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_network_description_display_get_string (QmiNasNetworkDescriptionDisplay val)
{
    guint i;

    for (i = 0; qmi_nas_network_description_display_values[i].value_nick; i++) {
        if (val == qmi_nas_network_description_display_values[i].value)
            return qmi_nas_network_description_display_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_NETWORK_DESCRIPTION_DISPLAY_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_NETWORK_DESCRIPTION_DISPLAY_IS_FLAGS__
/**
 * qmi_nas_network_description_display_build_string_from_mask:
 * @mask: bitmask of QmiNasNetworkDescriptionDisplay values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasNetworkDescriptionDisplay in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_network_description_display_build_string_from_mask (QmiNasNetworkDescriptionDisplay mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_network_description_display_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_network_description_display_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_network_description_display_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_network_description_display_values[i].value) {
            guint c;
            gulong number = qmi_nas_network_description_display_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_network_description_display_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_NETWORK_DESCRIPTION_DISPLAY_IS_FLAGS__ */

static const GEnumValue qmi_nas_network_description_encoding_values[] = {
    { QMI_NAS_NETWORK_DESCRIPTION_ENCODING_UNSPECIFIED, "QMI_NAS_NETWORK_DESCRIPTION_ENCODING_UNSPECIFIED", "unspecified" },
    { QMI_NAS_NETWORK_DESCRIPTION_ENCODING_ASCII7, "QMI_NAS_NETWORK_DESCRIPTION_ENCODING_ASCII7", "ascii7" },
    { QMI_NAS_NETWORK_DESCRIPTION_ENCODING_UNICODE, "QMI_NAS_NETWORK_DESCRIPTION_ENCODING_UNICODE", "unicode" },
    { QMI_NAS_NETWORK_DESCRIPTION_ENCODING_GSM, "QMI_NAS_NETWORK_DESCRIPTION_ENCODING_GSM", "gsm" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_network_description_encoding_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasNetworkDescriptionEncoding"),
                                      qmi_nas_network_description_encoding_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_NETWORK_DESCRIPTION_ENCODING_IS_ENUM__
/**
 * qmi_nas_network_description_encoding_get_string:
 * @val: a QmiNasNetworkDescriptionEncoding.
 *
 * Gets the nickname string for the #QmiNasNetworkDescriptionEncoding specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_network_description_encoding_get_string (QmiNasNetworkDescriptionEncoding val)
{
    guint i;

    for (i = 0; qmi_nas_network_description_encoding_values[i].value_nick; i++) {
        if (val == qmi_nas_network_description_encoding_values[i].value)
            return qmi_nas_network_description_encoding_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_NETWORK_DESCRIPTION_ENCODING_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_NETWORK_DESCRIPTION_ENCODING_IS_FLAGS__
/**
 * qmi_nas_network_description_encoding_build_string_from_mask:
 * @mask: bitmask of QmiNasNetworkDescriptionEncoding values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasNetworkDescriptionEncoding in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_network_description_encoding_build_string_from_mask (QmiNasNetworkDescriptionEncoding mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_network_description_encoding_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_network_description_encoding_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_network_description_encoding_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_network_description_encoding_values[i].value) {
            guint c;
            gulong number = qmi_nas_network_description_encoding_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_network_description_encoding_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_NETWORK_DESCRIPTION_ENCODING_IS_FLAGS__ */

static const GFlagsValue qmi_nas_radio_technology_preference_values[] = {
    { QMI_NAS_RADIO_TECHNOLOGY_PREFERENCE_AUTO, "QMI_NAS_RADIO_TECHNOLOGY_PREFERENCE_AUTO", "auto" },
    { QMI_NAS_RADIO_TECHNOLOGY_PREFERENCE_3GPP2, "QMI_NAS_RADIO_TECHNOLOGY_PREFERENCE_3GPP2", "3gpp2" },
    { QMI_NAS_RADIO_TECHNOLOGY_PREFERENCE_3GPP, "QMI_NAS_RADIO_TECHNOLOGY_PREFERENCE_3GPP", "3gpp" },
    { QMI_NAS_RADIO_TECHNOLOGY_PREFERENCE_AMPS_OR_GSM, "QMI_NAS_RADIO_TECHNOLOGY_PREFERENCE_AMPS_OR_GSM", "amps-or-gsm" },
    { QMI_NAS_RADIO_TECHNOLOGY_PREFERENCE_CDMA_OR_WCDMA, "QMI_NAS_RADIO_TECHNOLOGY_PREFERENCE_CDMA_OR_WCDMA", "cdma-or-wcdma" },
    { QMI_NAS_RADIO_TECHNOLOGY_PREFERENCE_HDR, "QMI_NAS_RADIO_TECHNOLOGY_PREFERENCE_HDR", "hdr" },
    { QMI_NAS_RADIO_TECHNOLOGY_PREFERENCE_LTE, "QMI_NAS_RADIO_TECHNOLOGY_PREFERENCE_LTE", "lte" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_radio_technology_preference_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("QmiNasRadioTechnologyPreference"),
                                      qmi_nas_radio_technology_preference_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_RADIO_TECHNOLOGY_PREFERENCE_IS_ENUM__
/**
 * qmi_nas_radio_technology_preference_get_string:
 * @val: a QmiNasRadioTechnologyPreference.
 *
 * Gets the nickname string for the #QmiNasRadioTechnologyPreference specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_radio_technology_preference_get_string (QmiNasRadioTechnologyPreference val)
{
    guint i;

    for (i = 0; qmi_nas_radio_technology_preference_values[i].value_nick; i++) {
        if (val == qmi_nas_radio_technology_preference_values[i].value)
            return qmi_nas_radio_technology_preference_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_RADIO_TECHNOLOGY_PREFERENCE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_RADIO_TECHNOLOGY_PREFERENCE_IS_FLAGS__
/**
 * qmi_nas_radio_technology_preference_build_string_from_mask:
 * @mask: bitmask of QmiNasRadioTechnologyPreference values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasRadioTechnologyPreference in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_radio_technology_preference_build_string_from_mask (QmiNasRadioTechnologyPreference mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_radio_technology_preference_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_radio_technology_preference_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_radio_technology_preference_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_radio_technology_preference_values[i].value) {
            guint c;
            gulong number = qmi_nas_radio_technology_preference_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_radio_technology_preference_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_RADIO_TECHNOLOGY_PREFERENCE_IS_FLAGS__ */

static const GEnumValue qmi_nas_preference_duration_values[] = {
    { QMI_NAS_PREFERENCE_DURATION_PERMANENT, "QMI_NAS_PREFERENCE_DURATION_PERMANENT", "permanent" },
    { QMI_NAS_PREFERENCE_DURATION_POWER_CYCLE, "QMI_NAS_PREFERENCE_DURATION_POWER_CYCLE", "power-cycle" },
    { QMI_NAS_PREFERENCE_DURATION_ONE_CALL, "QMI_NAS_PREFERENCE_DURATION_ONE_CALL", "one-call" },
    { QMI_NAS_PREFERENCE_DURATION_ONE_CALL_OR_TIME, "QMI_NAS_PREFERENCE_DURATION_ONE_CALL_OR_TIME", "one-call-or-time" },
    { QMI_NAS_PREFERENCE_DURATION_INTERNAL_ONE_CALL_1, "QMI_NAS_PREFERENCE_DURATION_INTERNAL_ONE_CALL_1", "internal-one-call-1" },
    { QMI_NAS_PREFERENCE_DURATION_INTERNAL_ONE_CALL_2, "QMI_NAS_PREFERENCE_DURATION_INTERNAL_ONE_CALL_2", "internal-one-call-2" },
    { QMI_NAS_PREFERENCE_DURATION_INTERNAL_ONE_CALL_3, "QMI_NAS_PREFERENCE_DURATION_INTERNAL_ONE_CALL_3", "internal-one-call-3" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_preference_duration_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasPreferenceDuration"),
                                      qmi_nas_preference_duration_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_PREFERENCE_DURATION_IS_ENUM__
/**
 * qmi_nas_preference_duration_get_string:
 * @val: a QmiNasPreferenceDuration.
 *
 * Gets the nickname string for the #QmiNasPreferenceDuration specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_preference_duration_get_string (QmiNasPreferenceDuration val)
{
    guint i;

    for (i = 0; qmi_nas_preference_duration_values[i].value_nick; i++) {
        if (val == qmi_nas_preference_duration_values[i].value)
            return qmi_nas_preference_duration_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_PREFERENCE_DURATION_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_PREFERENCE_DURATION_IS_FLAGS__
/**
 * qmi_nas_preference_duration_build_string_from_mask:
 * @mask: bitmask of QmiNasPreferenceDuration values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasPreferenceDuration in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_preference_duration_build_string_from_mask (QmiNasPreferenceDuration mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_preference_duration_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_preference_duration_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_preference_duration_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_preference_duration_values[i].value) {
            guint c;
            gulong number = qmi_nas_preference_duration_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_preference_duration_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_PREFERENCE_DURATION_IS_FLAGS__ */

static const GFlagsValue qmi_nas_rat_mode_preference_values[] = {
    { QMI_NAS_RAT_MODE_PREFERENCE_CDMA_1X, "QMI_NAS_RAT_MODE_PREFERENCE_CDMA_1X", "cdma-1x" },
    { QMI_NAS_RAT_MODE_PREFERENCE_CDMA_1XEVDO, "QMI_NAS_RAT_MODE_PREFERENCE_CDMA_1XEVDO", "cdma-1xevdo" },
    { QMI_NAS_RAT_MODE_PREFERENCE_GSM, "QMI_NAS_RAT_MODE_PREFERENCE_GSM", "gsm" },
    { QMI_NAS_RAT_MODE_PREFERENCE_UMTS, "QMI_NAS_RAT_MODE_PREFERENCE_UMTS", "umts" },
    { QMI_NAS_RAT_MODE_PREFERENCE_LTE, "QMI_NAS_RAT_MODE_PREFERENCE_LTE", "lte" },
    { QMI_NAS_RAT_MODE_PREFERENCE_TD_SCDMA, "QMI_NAS_RAT_MODE_PREFERENCE_TD_SCDMA", "td-scdma" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_rat_mode_preference_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("QmiNasRatModePreference"),
                                      qmi_nas_rat_mode_preference_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_RAT_MODE_PREFERENCE_IS_ENUM__
/**
 * qmi_nas_rat_mode_preference_get_string:
 * @val: a QmiNasRatModePreference.
 *
 * Gets the nickname string for the #QmiNasRatModePreference specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_rat_mode_preference_get_string (QmiNasRatModePreference val)
{
    guint i;

    for (i = 0; qmi_nas_rat_mode_preference_values[i].value_nick; i++) {
        if (val == qmi_nas_rat_mode_preference_values[i].value)
            return qmi_nas_rat_mode_preference_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_RAT_MODE_PREFERENCE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_RAT_MODE_PREFERENCE_IS_FLAGS__
/**
 * qmi_nas_rat_mode_preference_build_string_from_mask:
 * @mask: bitmask of QmiNasRatModePreference values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasRatModePreference in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_rat_mode_preference_build_string_from_mask (QmiNasRatModePreference mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_rat_mode_preference_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_rat_mode_preference_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_rat_mode_preference_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_rat_mode_preference_values[i].value) {
            guint c;
            gulong number = qmi_nas_rat_mode_preference_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_rat_mode_preference_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_RAT_MODE_PREFERENCE_IS_FLAGS__ */

static const GEnumValue qmi_nas_cdma_prl_preference_values[] = {
    { QMI_NAS_CDMA_PRL_PREFERENCE_A_SIDE_ONLY, "QMI_NAS_CDMA_PRL_PREFERENCE_A_SIDE_ONLY", "a-side-only" },
    { QMI_NAS_CDMA_PRL_PREFERENCE_B_SIDE_ONLY, "QMI_NAS_CDMA_PRL_PREFERENCE_B_SIDE_ONLY", "b-side-only" },
    { QMI_NAS_CDMA_PRL_PREFERENCE_ANY, "QMI_NAS_CDMA_PRL_PREFERENCE_ANY", "any" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_cdma_prl_preference_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasCdmaPrlPreference"),
                                      qmi_nas_cdma_prl_preference_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_CDMA_PRL_PREFERENCE_IS_ENUM__
/**
 * qmi_nas_cdma_prl_preference_get_string:
 * @val: a QmiNasCdmaPrlPreference.
 *
 * Gets the nickname string for the #QmiNasCdmaPrlPreference specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_cdma_prl_preference_get_string (QmiNasCdmaPrlPreference val)
{
    guint i;

    for (i = 0; qmi_nas_cdma_prl_preference_values[i].value_nick; i++) {
        if (val == qmi_nas_cdma_prl_preference_values[i].value)
            return qmi_nas_cdma_prl_preference_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_CDMA_PRL_PREFERENCE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_CDMA_PRL_PREFERENCE_IS_FLAGS__
/**
 * qmi_nas_cdma_prl_preference_build_string_from_mask:
 * @mask: bitmask of QmiNasCdmaPrlPreference values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasCdmaPrlPreference in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_cdma_prl_preference_build_string_from_mask (QmiNasCdmaPrlPreference mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_cdma_prl_preference_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_cdma_prl_preference_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_cdma_prl_preference_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_cdma_prl_preference_values[i].value) {
            guint c;
            gulong number = qmi_nas_cdma_prl_preference_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_cdma_prl_preference_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_CDMA_PRL_PREFERENCE_IS_FLAGS__ */

static const GEnumValue qmi_nas_roaming_preference_values[] = {
    { QMI_NAS_ROAMING_PREFERENCE_OFF, "QMI_NAS_ROAMING_PREFERENCE_OFF", "off" },
    { QMI_NAS_ROAMING_PREFERENCE_NOT_OFF, "QMI_NAS_ROAMING_PREFERENCE_NOT_OFF", "not-off" },
    { QMI_NAS_ROAMING_PREFERENCE_NOT_FLASHING, "QMI_NAS_ROAMING_PREFERENCE_NOT_FLASHING", "not-flashing" },
    { QMI_NAS_ROAMING_PREFERENCE_ANY, "QMI_NAS_ROAMING_PREFERENCE_ANY", "any" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_roaming_preference_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasRoamingPreference"),
                                      qmi_nas_roaming_preference_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_ROAMING_PREFERENCE_IS_ENUM__
/**
 * qmi_nas_roaming_preference_get_string:
 * @val: a QmiNasRoamingPreference.
 *
 * Gets the nickname string for the #QmiNasRoamingPreference specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_roaming_preference_get_string (QmiNasRoamingPreference val)
{
    guint i;

    for (i = 0; qmi_nas_roaming_preference_values[i].value_nick; i++) {
        if (val == qmi_nas_roaming_preference_values[i].value)
            return qmi_nas_roaming_preference_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_ROAMING_PREFERENCE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_ROAMING_PREFERENCE_IS_FLAGS__
/**
 * qmi_nas_roaming_preference_build_string_from_mask:
 * @mask: bitmask of QmiNasRoamingPreference values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasRoamingPreference in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_roaming_preference_build_string_from_mask (QmiNasRoamingPreference mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_roaming_preference_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_roaming_preference_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_roaming_preference_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_roaming_preference_values[i].value) {
            guint c;
            gulong number = qmi_nas_roaming_preference_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_roaming_preference_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_ROAMING_PREFERENCE_IS_FLAGS__ */

static const GEnumValue qmi_nas_network_selection_preference_values[] = {
    { QMI_NAS_NETWORK_SELECTION_PREFERENCE_AUTOMATIC, "QMI_NAS_NETWORK_SELECTION_PREFERENCE_AUTOMATIC", "automatic" },
    { QMI_NAS_NETWORK_SELECTION_PREFERENCE_MANUAL, "QMI_NAS_NETWORK_SELECTION_PREFERENCE_MANUAL", "manual" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_network_selection_preference_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasNetworkSelectionPreference"),
                                      qmi_nas_network_selection_preference_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_NETWORK_SELECTION_PREFERENCE_IS_ENUM__
/**
 * qmi_nas_network_selection_preference_get_string:
 * @val: a QmiNasNetworkSelectionPreference.
 *
 * Gets the nickname string for the #QmiNasNetworkSelectionPreference specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_network_selection_preference_get_string (QmiNasNetworkSelectionPreference val)
{
    guint i;

    for (i = 0; qmi_nas_network_selection_preference_values[i].value_nick; i++) {
        if (val == qmi_nas_network_selection_preference_values[i].value)
            return qmi_nas_network_selection_preference_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_NETWORK_SELECTION_PREFERENCE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_NETWORK_SELECTION_PREFERENCE_IS_FLAGS__
/**
 * qmi_nas_network_selection_preference_build_string_from_mask:
 * @mask: bitmask of QmiNasNetworkSelectionPreference values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasNetworkSelectionPreference in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_network_selection_preference_build_string_from_mask (QmiNasNetworkSelectionPreference mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_network_selection_preference_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_network_selection_preference_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_network_selection_preference_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_network_selection_preference_values[i].value) {
            guint c;
            gulong number = qmi_nas_network_selection_preference_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_network_selection_preference_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_NETWORK_SELECTION_PREFERENCE_IS_FLAGS__ */

static const GEnumValue qmi_nas_change_duration_values[] = {
    { QMI_NAS_CHANGE_DURATION_POWER_CYCLE, "QMI_NAS_CHANGE_DURATION_POWER_CYCLE", "power-cycle" },
    { QMI_NAS_CHANGE_DURATION_PERMANENT, "QMI_NAS_CHANGE_DURATION_PERMANENT", "permanent" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_change_duration_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasChangeDuration"),
                                      qmi_nas_change_duration_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_CHANGE_DURATION_IS_ENUM__
/**
 * qmi_nas_change_duration_get_string:
 * @val: a QmiNasChangeDuration.
 *
 * Gets the nickname string for the #QmiNasChangeDuration specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_change_duration_get_string (QmiNasChangeDuration val)
{
    guint i;

    for (i = 0; qmi_nas_change_duration_values[i].value_nick; i++) {
        if (val == qmi_nas_change_duration_values[i].value)
            return qmi_nas_change_duration_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_CHANGE_DURATION_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_CHANGE_DURATION_IS_FLAGS__
/**
 * qmi_nas_change_duration_build_string_from_mask:
 * @mask: bitmask of QmiNasChangeDuration values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasChangeDuration in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_change_duration_build_string_from_mask (QmiNasChangeDuration mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_change_duration_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_change_duration_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_change_duration_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_change_duration_values[i].value) {
            guint c;
            gulong number = qmi_nas_change_duration_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_change_duration_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_CHANGE_DURATION_IS_FLAGS__ */

static const GEnumValue qmi_nas_service_domain_preference_values[] = {
    { QMI_NAS_SERVICE_DOMAIN_PREFERENCE_CS_ONLY, "QMI_NAS_SERVICE_DOMAIN_PREFERENCE_CS_ONLY", "cs-only" },
    { QMI_NAS_SERVICE_DOMAIN_PREFERENCE_PS_ONLY, "QMI_NAS_SERVICE_DOMAIN_PREFERENCE_PS_ONLY", "ps-only" },
    { QMI_NAS_SERVICE_DOMAIN_PREFERENCE_CS_PS, "QMI_NAS_SERVICE_DOMAIN_PREFERENCE_CS_PS", "cs-ps" },
    { QMI_NAS_SERVICE_DOMAIN_PREFERENCE_PS_ATTACH, "QMI_NAS_SERVICE_DOMAIN_PREFERENCE_PS_ATTACH", "ps-attach" },
    { QMI_NAS_SERVICE_DOMAIN_PREFERENCE_PS_DETACH, "QMI_NAS_SERVICE_DOMAIN_PREFERENCE_PS_DETACH", "ps-detach" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_service_domain_preference_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasServiceDomainPreference"),
                                      qmi_nas_service_domain_preference_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_SERVICE_DOMAIN_PREFERENCE_IS_ENUM__
/**
 * qmi_nas_service_domain_preference_get_string:
 * @val: a QmiNasServiceDomainPreference.
 *
 * Gets the nickname string for the #QmiNasServiceDomainPreference specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_service_domain_preference_get_string (QmiNasServiceDomainPreference val)
{
    guint i;

    for (i = 0; qmi_nas_service_domain_preference_values[i].value_nick; i++) {
        if (val == qmi_nas_service_domain_preference_values[i].value)
            return qmi_nas_service_domain_preference_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_SERVICE_DOMAIN_PREFERENCE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_SERVICE_DOMAIN_PREFERENCE_IS_FLAGS__
/**
 * qmi_nas_service_domain_preference_build_string_from_mask:
 * @mask: bitmask of QmiNasServiceDomainPreference values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasServiceDomainPreference in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_service_domain_preference_build_string_from_mask (QmiNasServiceDomainPreference mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_service_domain_preference_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_service_domain_preference_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_service_domain_preference_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_service_domain_preference_values[i].value) {
            guint c;
            gulong number = qmi_nas_service_domain_preference_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_service_domain_preference_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_SERVICE_DOMAIN_PREFERENCE_IS_FLAGS__ */

static const GEnumValue qmi_nas_gsm_wcdma_acquisition_order_preference_values[] = {
    { QMI_NAS_GSM_WCDMA_ACQUISITION_ORDER_PREFERENCE_AUTOMATIC, "QMI_NAS_GSM_WCDMA_ACQUISITION_ORDER_PREFERENCE_AUTOMATIC", "automatic" },
    { QMI_NAS_GSM_WCDMA_ACQUISITION_ORDER_PREFERENCE_GSM, "QMI_NAS_GSM_WCDMA_ACQUISITION_ORDER_PREFERENCE_GSM", "gsm" },
    { QMI_NAS_GSM_WCDMA_ACQUISITION_ORDER_PREFERENCE_WCDMA, "QMI_NAS_GSM_WCDMA_ACQUISITION_ORDER_PREFERENCE_WCDMA", "wcdma" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_gsm_wcdma_acquisition_order_preference_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasGsmWcdmaAcquisitionOrderPreference"),
                                      qmi_nas_gsm_wcdma_acquisition_order_preference_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_GSM_WCDMA_ACQUISITION_ORDER_PREFERENCE_IS_ENUM__
/**
 * qmi_nas_gsm_wcdma_acquisition_order_preference_get_string:
 * @val: a QmiNasGsmWcdmaAcquisitionOrderPreference.
 *
 * Gets the nickname string for the #QmiNasGsmWcdmaAcquisitionOrderPreference specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_gsm_wcdma_acquisition_order_preference_get_string (QmiNasGsmWcdmaAcquisitionOrderPreference val)
{
    guint i;

    for (i = 0; qmi_nas_gsm_wcdma_acquisition_order_preference_values[i].value_nick; i++) {
        if (val == qmi_nas_gsm_wcdma_acquisition_order_preference_values[i].value)
            return qmi_nas_gsm_wcdma_acquisition_order_preference_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_GSM_WCDMA_ACQUISITION_ORDER_PREFERENCE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_GSM_WCDMA_ACQUISITION_ORDER_PREFERENCE_IS_FLAGS__
/**
 * qmi_nas_gsm_wcdma_acquisition_order_preference_build_string_from_mask:
 * @mask: bitmask of QmiNasGsmWcdmaAcquisitionOrderPreference values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasGsmWcdmaAcquisitionOrderPreference in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_gsm_wcdma_acquisition_order_preference_build_string_from_mask (QmiNasGsmWcdmaAcquisitionOrderPreference mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_gsm_wcdma_acquisition_order_preference_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_gsm_wcdma_acquisition_order_preference_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_gsm_wcdma_acquisition_order_preference_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_gsm_wcdma_acquisition_order_preference_values[i].value) {
            guint c;
            gulong number = qmi_nas_gsm_wcdma_acquisition_order_preference_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_gsm_wcdma_acquisition_order_preference_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_GSM_WCDMA_ACQUISITION_ORDER_PREFERENCE_IS_FLAGS__ */

static const GFlagsValue qmi_nas_td_scdma_band_preference_values[] = {
    { QMI_NAS_TD_SCDMA_BAND_PREFERENCE_A, "QMI_NAS_TD_SCDMA_BAND_PREFERENCE_A", "a" },
    { QMI_NAS_TD_SCDMA_BAND_PREFERENCE_B, "QMI_NAS_TD_SCDMA_BAND_PREFERENCE_B", "b" },
    { QMI_NAS_TD_SCDMA_BAND_PREFERENCE_C, "QMI_NAS_TD_SCDMA_BAND_PREFERENCE_C", "c" },
    { QMI_NAS_TD_SCDMA_BAND_PREFERENCE_D, "QMI_NAS_TD_SCDMA_BAND_PREFERENCE_D", "d" },
    { QMI_NAS_TD_SCDMA_BAND_PREFERENCE_E, "QMI_NAS_TD_SCDMA_BAND_PREFERENCE_E", "e" },
    { QMI_NAS_TD_SCDMA_BAND_PREFERENCE_F, "QMI_NAS_TD_SCDMA_BAND_PREFERENCE_F", "f" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_td_scdma_band_preference_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("QmiNasTdScdmaBandPreference"),
                                      qmi_nas_td_scdma_band_preference_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_TD_SCDMA_BAND_PREFERENCE_IS_ENUM__
/**
 * qmi_nas_td_scdma_band_preference_get_string:
 * @val: a QmiNasTdScdmaBandPreference.
 *
 * Gets the nickname string for the #QmiNasTdScdmaBandPreference specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_td_scdma_band_preference_get_string (QmiNasTdScdmaBandPreference val)
{
    guint i;

    for (i = 0; qmi_nas_td_scdma_band_preference_values[i].value_nick; i++) {
        if (val == qmi_nas_td_scdma_band_preference_values[i].value)
            return qmi_nas_td_scdma_band_preference_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_TD_SCDMA_BAND_PREFERENCE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_TD_SCDMA_BAND_PREFERENCE_IS_FLAGS__
/**
 * qmi_nas_td_scdma_band_preference_build_string_from_mask:
 * @mask: bitmask of QmiNasTdScdmaBandPreference values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasTdScdmaBandPreference in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_td_scdma_band_preference_build_string_from_mask (QmiNasTdScdmaBandPreference mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_td_scdma_band_preference_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_td_scdma_band_preference_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_td_scdma_band_preference_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_td_scdma_band_preference_values[i].value) {
            guint c;
            gulong number = qmi_nas_td_scdma_band_preference_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_td_scdma_band_preference_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_TD_SCDMA_BAND_PREFERENCE_IS_FLAGS__ */

static const GEnumValue qmi_nas_roaming_status_values[] = {
    { QMI_NAS_ROAMING_STATUS_OFF, "QMI_NAS_ROAMING_STATUS_OFF", "off" },
    { QMI_NAS_ROAMING_STATUS_ON, "QMI_NAS_ROAMING_STATUS_ON", "on" },
    { QMI_NAS_ROAMING_STATUS_BLINK, "QMI_NAS_ROAMING_STATUS_BLINK", "blink" },
    { QMI_NAS_ROAMING_STATUS_OUT_OF_NEIGHBORHOOD, "QMI_NAS_ROAMING_STATUS_OUT_OF_NEIGHBORHOOD", "out-of-neighborhood" },
    { QMI_NAS_ROAMING_STATUS_OUT_OF_BUILDING, "QMI_NAS_ROAMING_STATUS_OUT_OF_BUILDING", "out-of-building" },
    { QMI_NAS_ROAMING_STATUS_PREFERRED_SYSTEM, "QMI_NAS_ROAMING_STATUS_PREFERRED_SYSTEM", "preferred-system" },
    { QMI_NAS_ROAMING_STATUS_AVAILABLE_SYSTEM, "QMI_NAS_ROAMING_STATUS_AVAILABLE_SYSTEM", "available-system" },
    { QMI_NAS_ROAMING_STATUS_ALLIANCE_PARTNER, "QMI_NAS_ROAMING_STATUS_ALLIANCE_PARTNER", "alliance-partner" },
    { QMI_NAS_ROAMING_STATUS_PREMIUM_PARTNER, "QMI_NAS_ROAMING_STATUS_PREMIUM_PARTNER", "premium-partner" },
    { QMI_NAS_ROAMING_STATUS_FULL_SERVICE, "QMI_NAS_ROAMING_STATUS_FULL_SERVICE", "full-service" },
    { QMI_NAS_ROAMING_STATUS_PARTIAL_SERVICE, "QMI_NAS_ROAMING_STATUS_PARTIAL_SERVICE", "partial-service" },
    { QMI_NAS_ROAMING_STATUS_BANNER_ON, "QMI_NAS_ROAMING_STATUS_BANNER_ON", "banner-on" },
    { QMI_NAS_ROAMING_STATUS_BANNER_OFF, "QMI_NAS_ROAMING_STATUS_BANNER_OFF", "banner-off" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_roaming_status_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasRoamingStatus"),
                                      qmi_nas_roaming_status_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_ROAMING_STATUS_IS_ENUM__
/**
 * qmi_nas_roaming_status_get_string:
 * @val: a QmiNasRoamingStatus.
 *
 * Gets the nickname string for the #QmiNasRoamingStatus specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_roaming_status_get_string (QmiNasRoamingStatus val)
{
    guint i;

    for (i = 0; qmi_nas_roaming_status_values[i].value_nick; i++) {
        if (val == qmi_nas_roaming_status_values[i].value)
            return qmi_nas_roaming_status_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_ROAMING_STATUS_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_ROAMING_STATUS_IS_FLAGS__
/**
 * qmi_nas_roaming_status_build_string_from_mask:
 * @mask: bitmask of QmiNasRoamingStatus values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasRoamingStatus in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_roaming_status_build_string_from_mask (QmiNasRoamingStatus mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_roaming_status_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_roaming_status_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_roaming_status_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_roaming_status_values[i].value) {
            guint c;
            gulong number = qmi_nas_roaming_status_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_roaming_status_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_ROAMING_STATUS_IS_FLAGS__ */

static const GEnumValue qmi_nas_hdr_protocol_revision_values[] = {
    { QMI_NAS_HDR_PROTOCOL_REVISION_NONE, "QMI_NAS_HDR_PROTOCOL_REVISION_NONE", "none" },
    { QMI_NAS_HDR_PROTOCOL_REVISION_REL_0, "QMI_NAS_HDR_PROTOCOL_REVISION_REL_0", "rel-0" },
    { QMI_NAS_HDR_PROTOCOL_REVISION_REL_A, "QMI_NAS_HDR_PROTOCOL_REVISION_REL_A", "rel-a" },
    { QMI_NAS_HDR_PROTOCOL_REVISION_REL_B, "QMI_NAS_HDR_PROTOCOL_REVISION_REL_B", "rel-b" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_hdr_protocol_revision_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasHdrProtocolRevision"),
                                      qmi_nas_hdr_protocol_revision_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_HDR_PROTOCOL_REVISION_IS_ENUM__
/**
 * qmi_nas_hdr_protocol_revision_get_string:
 * @val: a QmiNasHdrProtocolRevision.
 *
 * Gets the nickname string for the #QmiNasHdrProtocolRevision specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_hdr_protocol_revision_get_string (QmiNasHdrProtocolRevision val)
{
    guint i;

    for (i = 0; qmi_nas_hdr_protocol_revision_values[i].value_nick; i++) {
        if (val == qmi_nas_hdr_protocol_revision_values[i].value)
            return qmi_nas_hdr_protocol_revision_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_HDR_PROTOCOL_REVISION_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_HDR_PROTOCOL_REVISION_IS_FLAGS__
/**
 * qmi_nas_hdr_protocol_revision_build_string_from_mask:
 * @mask: bitmask of QmiNasHdrProtocolRevision values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasHdrProtocolRevision in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_hdr_protocol_revision_build_string_from_mask (QmiNasHdrProtocolRevision mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_hdr_protocol_revision_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_hdr_protocol_revision_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_hdr_protocol_revision_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_hdr_protocol_revision_values[i].value) {
            guint c;
            gulong number = qmi_nas_hdr_protocol_revision_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_hdr_protocol_revision_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_HDR_PROTOCOL_REVISION_IS_FLAGS__ */

static const GEnumValue qmi_nas_wcdma_hs_service_values[] = {
    { QMI_NAS_WCDMA_HS_SERVICE_HSDPA_HSUPA_UNSUPPORTED, "QMI_NAS_WCDMA_HS_SERVICE_HSDPA_HSUPA_UNSUPPORTED", "hsdpa-hsupa-unsupported" },
    { QMI_NAS_WCDMA_HS_SERVICE_HSDPA_SUPPORTED, "QMI_NAS_WCDMA_HS_SERVICE_HSDPA_SUPPORTED", "hsdpa-supported" },
    { QMI_NAS_WCDMA_HS_SERVICE_HSUPA_SUPPORTED, "QMI_NAS_WCDMA_HS_SERVICE_HSUPA_SUPPORTED", "hsupa-supported" },
    { QMI_NAS_WCDMA_HS_SERVICE_HSDPA_HSUPA_SUPPORTED, "QMI_NAS_WCDMA_HS_SERVICE_HSDPA_HSUPA_SUPPORTED", "hsdpa-hsupa-supported" },
    { QMI_NAS_WCDMA_HS_SERVICE_HSDPA_PLUS_SUPPORTED, "QMI_NAS_WCDMA_HS_SERVICE_HSDPA_PLUS_SUPPORTED", "hsdpa-plus-supported" },
    { QMI_NAS_WCDMA_HS_SERVICE_HSDPA_PLUS_HSUPA_SUPPORTED, "QMI_NAS_WCDMA_HS_SERVICE_HSDPA_PLUS_HSUPA_SUPPORTED", "hsdpa-plus-hsupa-supported" },
    { QMI_NAS_WCDMA_HS_SERVICE_DC_HSDPA_PLUS_SUPPORTED, "QMI_NAS_WCDMA_HS_SERVICE_DC_HSDPA_PLUS_SUPPORTED", "dc-hsdpa-plus-supported" },
    { QMI_NAS_WCDMA_HS_SERVICE_DC_HSDPA_PLUS_HSUPA_SUPPORTED, "QMI_NAS_WCDMA_HS_SERVICE_DC_HSDPA_PLUS_HSUPA_SUPPORTED", "dc-hsdpa-plus-hsupa-supported" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_wcdma_hs_service_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasWcdmaHsService"),
                                      qmi_nas_wcdma_hs_service_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_WCDMA_HS_SERVICE_IS_ENUM__
/**
 * qmi_nas_wcdma_hs_service_get_string:
 * @val: a QmiNasWcdmaHsService.
 *
 * Gets the nickname string for the #QmiNasWcdmaHsService specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_wcdma_hs_service_get_string (QmiNasWcdmaHsService val)
{
    guint i;

    for (i = 0; qmi_nas_wcdma_hs_service_values[i].value_nick; i++) {
        if (val == qmi_nas_wcdma_hs_service_values[i].value)
            return qmi_nas_wcdma_hs_service_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_WCDMA_HS_SERVICE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_WCDMA_HS_SERVICE_IS_FLAGS__
/**
 * qmi_nas_wcdma_hs_service_build_string_from_mask:
 * @mask: bitmask of QmiNasWcdmaHsService values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasWcdmaHsService in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_wcdma_hs_service_build_string_from_mask (QmiNasWcdmaHsService mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_wcdma_hs_service_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_wcdma_hs_service_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_wcdma_hs_service_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_wcdma_hs_service_values[i].value) {
            guint c;
            gulong number = qmi_nas_wcdma_hs_service_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_wcdma_hs_service_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_WCDMA_HS_SERVICE_IS_FLAGS__ */

static const GEnumValue qmi_nas_cell_broadcast_capability_values[] = {
    { QMI_NAS_CELL_BROADCAST_CAPABILITY_UNKNOWN, "QMI_NAS_CELL_BROADCAST_CAPABILITY_UNKNOWN", "unknown" },
    { QMI_NAS_CELL_BROADCAST_CAPABILITY_OFF, "QMI_NAS_CELL_BROADCAST_CAPABILITY_OFF", "off" },
    { QMI_NAS_CELL_BROADCAST_CAPABILITY_ON, "QMI_NAS_CELL_BROADCAST_CAPABILITY_ON", "on" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_cell_broadcast_capability_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasCellBroadcastCapability"),
                                      qmi_nas_cell_broadcast_capability_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_CELL_BROADCAST_CAPABILITY_IS_ENUM__
/**
 * qmi_nas_cell_broadcast_capability_get_string:
 * @val: a QmiNasCellBroadcastCapability.
 *
 * Gets the nickname string for the #QmiNasCellBroadcastCapability specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_cell_broadcast_capability_get_string (QmiNasCellBroadcastCapability val)
{
    guint i;

    for (i = 0; qmi_nas_cell_broadcast_capability_values[i].value_nick; i++) {
        if (val == qmi_nas_cell_broadcast_capability_values[i].value)
            return qmi_nas_cell_broadcast_capability_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_CELL_BROADCAST_CAPABILITY_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_CELL_BROADCAST_CAPABILITY_IS_FLAGS__
/**
 * qmi_nas_cell_broadcast_capability_build_string_from_mask:
 * @mask: bitmask of QmiNasCellBroadcastCapability values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasCellBroadcastCapability in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_cell_broadcast_capability_build_string_from_mask (QmiNasCellBroadcastCapability mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_cell_broadcast_capability_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_cell_broadcast_capability_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_cell_broadcast_capability_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_cell_broadcast_capability_values[i].value) {
            guint c;
            gulong number = qmi_nas_cell_broadcast_capability_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_cell_broadcast_capability_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_CELL_BROADCAST_CAPABILITY_IS_FLAGS__ */

static const GEnumValue qmi_nas_sim_reject_state_values[] = {
    { QMI_NAS_SIM_REJECT_STATE_SIM_UNAVAILABLE, "QMI_NAS_SIM_REJECT_STATE_SIM_UNAVAILABLE", "unavailable" },
    { QMI_NAS_SIM_REJECT_STATE_SIM_VAILABLE, "QMI_NAS_SIM_REJECT_STATE_SIM_VAILABLE", "vailable" },
    { QMI_NAS_SIM_REJECT_STATE_SIM_CS_INVALID, "QMI_NAS_SIM_REJECT_STATE_SIM_CS_INVALID", "cs-invalid" },
    { QMI_NAS_SIM_REJECT_STATE_SIM_PS_INVALID, "QMI_NAS_SIM_REJECT_STATE_SIM_PS_INVALID", "ps-invalid" },
    { QMI_NAS_SIM_REJECT_STATE_SIM_CS_PS_INVALID, "QMI_NAS_SIM_REJECT_STATE_SIM_CS_PS_INVALID", "cs-ps-invalid" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_sim_reject_state_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasSimRejectState"),
                                      qmi_nas_sim_reject_state_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_SIM_REJECT_STATE_IS_ENUM__
/**
 * qmi_nas_sim_reject_state_get_string:
 * @val: a QmiNasSimRejectState.
 *
 * Gets the nickname string for the #QmiNasSimRejectState specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_sim_reject_state_get_string (QmiNasSimRejectState val)
{
    guint i;

    for (i = 0; qmi_nas_sim_reject_state_values[i].value_nick; i++) {
        if (val == qmi_nas_sim_reject_state_values[i].value)
            return qmi_nas_sim_reject_state_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_SIM_REJECT_STATE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_SIM_REJECT_STATE_IS_FLAGS__
/**
 * qmi_nas_sim_reject_state_build_string_from_mask:
 * @mask: bitmask of QmiNasSimRejectState values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasSimRejectState in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_sim_reject_state_build_string_from_mask (QmiNasSimRejectState mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_sim_reject_state_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_sim_reject_state_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_sim_reject_state_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_sim_reject_state_values[i].value) {
            guint c;
            gulong number = qmi_nas_sim_reject_state_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_sim_reject_state_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_SIM_REJECT_STATE_IS_FLAGS__ */

static const GEnumValue qmi_nas_cdma_pilot_type_values[] = {
    { QMI_NAS_CDMA_PILOT_TYPE_ACTIVE, "QMI_NAS_CDMA_PILOT_TYPE_ACTIVE", "active" },
    { QMI_NAS_CDMA_PILOT_TYPE_NEIGHBOR, "QMI_NAS_CDMA_PILOT_TYPE_NEIGHBOR", "neighbor" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_cdma_pilot_type_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasCdmaPilotType"),
                                      qmi_nas_cdma_pilot_type_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_CDMA_PILOT_TYPE_IS_ENUM__
/**
 * qmi_nas_cdma_pilot_type_get_string:
 * @val: a QmiNasCdmaPilotType.
 *
 * Gets the nickname string for the #QmiNasCdmaPilotType specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_cdma_pilot_type_get_string (QmiNasCdmaPilotType val)
{
    guint i;

    for (i = 0; qmi_nas_cdma_pilot_type_values[i].value_nick; i++) {
        if (val == qmi_nas_cdma_pilot_type_values[i].value)
            return qmi_nas_cdma_pilot_type_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_CDMA_PILOT_TYPE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_CDMA_PILOT_TYPE_IS_FLAGS__
/**
 * qmi_nas_cdma_pilot_type_build_string_from_mask:
 * @mask: bitmask of QmiNasCdmaPilotType values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasCdmaPilotType in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_cdma_pilot_type_build_string_from_mask (QmiNasCdmaPilotType mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_cdma_pilot_type_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_cdma_pilot_type_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_cdma_pilot_type_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_cdma_pilot_type_values[i].value) {
            guint c;
            gulong number = qmi_nas_cdma_pilot_type_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_cdma_pilot_type_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_CDMA_PILOT_TYPE_IS_FLAGS__ */

static const GEnumValue qmi_nas_day_of_week_values[] = {
    { QMI_NAS_DAY_OF_WEEK_MONDAY, "QMI_NAS_DAY_OF_WEEK_MONDAY", "monday" },
    { QMI_NAS_DAY_OF_WEEK_TUESDAY, "QMI_NAS_DAY_OF_WEEK_TUESDAY", "tuesday" },
    { QMI_NAS_DAY_OF_WEEK_WEDNESDAY, "QMI_NAS_DAY_OF_WEEK_WEDNESDAY", "wednesday" },
    { QMI_NAS_DAY_OF_WEEK_THURSDAY, "QMI_NAS_DAY_OF_WEEK_THURSDAY", "thursday" },
    { QMI_NAS_DAY_OF_WEEK_FRIDAY, "QMI_NAS_DAY_OF_WEEK_FRIDAY", "friday" },
    { QMI_NAS_DAY_OF_WEEK_SATURDAY, "QMI_NAS_DAY_OF_WEEK_SATURDAY", "saturday" },
    { QMI_NAS_DAY_OF_WEEK_SUNDAY, "QMI_NAS_DAY_OF_WEEK_SUNDAY", "sunday" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_day_of_week_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasDayOfWeek"),
                                      qmi_nas_day_of_week_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_DAY_OF_WEEK_IS_ENUM__
/**
 * qmi_nas_day_of_week_get_string:
 * @val: a QmiNasDayOfWeek.
 *
 * Gets the nickname string for the #QmiNasDayOfWeek specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_day_of_week_get_string (QmiNasDayOfWeek val)
{
    guint i;

    for (i = 0; qmi_nas_day_of_week_values[i].value_nick; i++) {
        if (val == qmi_nas_day_of_week_values[i].value)
            return qmi_nas_day_of_week_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_DAY_OF_WEEK_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_DAY_OF_WEEK_IS_FLAGS__
/**
 * qmi_nas_day_of_week_build_string_from_mask:
 * @mask: bitmask of QmiNasDayOfWeek values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasDayOfWeek in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_day_of_week_build_string_from_mask (QmiNasDayOfWeek mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_day_of_week_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_day_of_week_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_day_of_week_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_day_of_week_values[i].value) {
            guint c;
            gulong number = qmi_nas_day_of_week_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_day_of_week_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_DAY_OF_WEEK_IS_FLAGS__ */

static const GEnumValue qmi_nas_daylight_savings_adjustment_values[] = {
    { QMI_NAS_DAYLIGHT_SAVINGS_ADJUSTMENT_NONE, "QMI_NAS_DAYLIGHT_SAVINGS_ADJUSTMENT_NONE", "none" },
    { QMI_NAS_DAYLIGHT_SAVINGS_ADJUSTMENT_ONE_HOUR, "QMI_NAS_DAYLIGHT_SAVINGS_ADJUSTMENT_ONE_HOUR", "one-hour" },
    { QMI_NAS_DAYLIGHT_SAVINGS_ADJUSTMENT_TWO_HOURS, "QMI_NAS_DAYLIGHT_SAVINGS_ADJUSTMENT_TWO_HOURS", "two-hours" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_nas_daylight_savings_adjustment_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiNasDaylightSavingsAdjustment"),
                                      qmi_nas_daylight_savings_adjustment_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_NAS_DAYLIGHT_SAVINGS_ADJUSTMENT_IS_ENUM__
/**
 * qmi_nas_daylight_savings_adjustment_get_string:
 * @val: a QmiNasDaylightSavingsAdjustment.
 *
 * Gets the nickname string for the #QmiNasDaylightSavingsAdjustment specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_nas_daylight_savings_adjustment_get_string (QmiNasDaylightSavingsAdjustment val)
{
    guint i;

    for (i = 0; qmi_nas_daylight_savings_adjustment_values[i].value_nick; i++) {
        if (val == qmi_nas_daylight_savings_adjustment_values[i].value)
            return qmi_nas_daylight_savings_adjustment_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_NAS_DAYLIGHT_SAVINGS_ADJUSTMENT_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_NAS_DAYLIGHT_SAVINGS_ADJUSTMENT_IS_FLAGS__
/**
 * qmi_nas_daylight_savings_adjustment_build_string_from_mask:
 * @mask: bitmask of QmiNasDaylightSavingsAdjustment values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasDaylightSavingsAdjustment in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_daylight_savings_adjustment_build_string_from_mask (QmiNasDaylightSavingsAdjustment mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_daylight_savings_adjustment_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_daylight_savings_adjustment_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_daylight_savings_adjustment_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_daylight_savings_adjustment_values[i].value) {
            guint c;
            gulong number = qmi_nas_daylight_savings_adjustment_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_daylight_savings_adjustment_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_NAS_DAYLIGHT_SAVINGS_ADJUSTMENT_IS_FLAGS__ */

/* enumerations from "../../libqmi-glib/qmi-enums-wms.h" */
static const GEnumValue qmi_wms_storage_type_values[] = {
    { QMI_WMS_STORAGE_TYPE_UIM, "QMI_WMS_STORAGE_TYPE_UIM", "uim" },
    { QMI_WMS_STORAGE_TYPE_NV, "QMI_WMS_STORAGE_TYPE_NV", "nv" },
    { QMI_WMS_STORAGE_TYPE_NONE, "QMI_WMS_STORAGE_TYPE_NONE", "none" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wms_storage_type_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWmsStorageType"),
                                      qmi_wms_storage_type_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WMS_STORAGE_TYPE_IS_ENUM__
/**
 * qmi_wms_storage_type_get_string:
 * @val: a QmiWmsStorageType.
 *
 * Gets the nickname string for the #QmiWmsStorageType specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wms_storage_type_get_string (QmiWmsStorageType val)
{
    guint i;

    for (i = 0; qmi_wms_storage_type_values[i].value_nick; i++) {
        if (val == qmi_wms_storage_type_values[i].value)
            return qmi_wms_storage_type_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WMS_STORAGE_TYPE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WMS_STORAGE_TYPE_IS_FLAGS__
/**
 * qmi_wms_storage_type_build_string_from_mask:
 * @mask: bitmask of QmiWmsStorageType values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWmsStorageType in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wms_storage_type_build_string_from_mask (QmiWmsStorageType mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wms_storage_type_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wms_storage_type_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wms_storage_type_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wms_storage_type_values[i].value) {
            guint c;
            gulong number = qmi_wms_storage_type_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wms_storage_type_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WMS_STORAGE_TYPE_IS_FLAGS__ */

static const GEnumValue qmi_wms_ack_indicator_values[] = {
    { QMI_WMS_ACK_INDICATOR_SEND, "QMI_WMS_ACK_INDICATOR_SEND", "send" },
    { QMI_WMS_ACK_INDICATOR_DO_NOT_SEND, "QMI_WMS_ACK_INDICATOR_DO_NOT_SEND", "do-not-send" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wms_ack_indicator_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWmsAckIndicator"),
                                      qmi_wms_ack_indicator_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WMS_ACK_INDICATOR_IS_ENUM__
/**
 * qmi_wms_ack_indicator_get_string:
 * @val: a QmiWmsAckIndicator.
 *
 * Gets the nickname string for the #QmiWmsAckIndicator specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wms_ack_indicator_get_string (QmiWmsAckIndicator val)
{
    guint i;

    for (i = 0; qmi_wms_ack_indicator_values[i].value_nick; i++) {
        if (val == qmi_wms_ack_indicator_values[i].value)
            return qmi_wms_ack_indicator_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WMS_ACK_INDICATOR_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WMS_ACK_INDICATOR_IS_FLAGS__
/**
 * qmi_wms_ack_indicator_build_string_from_mask:
 * @mask: bitmask of QmiWmsAckIndicator values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWmsAckIndicator in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wms_ack_indicator_build_string_from_mask (QmiWmsAckIndicator mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wms_ack_indicator_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wms_ack_indicator_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wms_ack_indicator_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wms_ack_indicator_values[i].value) {
            guint c;
            gulong number = qmi_wms_ack_indicator_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wms_ack_indicator_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WMS_ACK_INDICATOR_IS_FLAGS__ */

static const GEnumValue qmi_wms_message_format_values[] = {
    { QMI_WMS_MESSAGE_FORMAT_CDMA, "QMI_WMS_MESSAGE_FORMAT_CDMA", "cdma" },
    { QMI_WMS_MESSAGE_FORMAT_GSM_WCDMA_POINT_TO_POINT, "QMI_WMS_MESSAGE_FORMAT_GSM_WCDMA_POINT_TO_POINT", "gsm-wcdma-point-to-point" },
    { QMI_WMS_MESSAGE_FORMAT_GSM_WCDMA_BROADCAST, "QMI_WMS_MESSAGE_FORMAT_GSM_WCDMA_BROADCAST", "gsm-wcdma-broadcast" },
    { QMI_WMS_MESSAGE_FORMAT_MWI, "QMI_WMS_MESSAGE_FORMAT_MWI", "mwi" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wms_message_format_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWmsMessageFormat"),
                                      qmi_wms_message_format_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WMS_MESSAGE_FORMAT_IS_ENUM__
/**
 * qmi_wms_message_format_get_string:
 * @val: a QmiWmsMessageFormat.
 *
 * Gets the nickname string for the #QmiWmsMessageFormat specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wms_message_format_get_string (QmiWmsMessageFormat val)
{
    guint i;

    for (i = 0; qmi_wms_message_format_values[i].value_nick; i++) {
        if (val == qmi_wms_message_format_values[i].value)
            return qmi_wms_message_format_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WMS_MESSAGE_FORMAT_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WMS_MESSAGE_FORMAT_IS_FLAGS__
/**
 * qmi_wms_message_format_build_string_from_mask:
 * @mask: bitmask of QmiWmsMessageFormat values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWmsMessageFormat in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wms_message_format_build_string_from_mask (QmiWmsMessageFormat mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wms_message_format_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wms_message_format_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wms_message_format_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wms_message_format_values[i].value) {
            guint c;
            gulong number = qmi_wms_message_format_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wms_message_format_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WMS_MESSAGE_FORMAT_IS_FLAGS__ */

static const GEnumValue qmi_wms_message_mode_values[] = {
    { QMI_WMS_MESSAGE_MODE_CDMA, "QMI_WMS_MESSAGE_MODE_CDMA", "cdma" },
    { QMI_WMS_MESSAGE_MODE_GSM_WCDMA, "QMI_WMS_MESSAGE_MODE_GSM_WCDMA", "gsm-wcdma" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wms_message_mode_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWmsMessageMode"),
                                      qmi_wms_message_mode_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WMS_MESSAGE_MODE_IS_ENUM__
/**
 * qmi_wms_message_mode_get_string:
 * @val: a QmiWmsMessageMode.
 *
 * Gets the nickname string for the #QmiWmsMessageMode specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wms_message_mode_get_string (QmiWmsMessageMode val)
{
    guint i;

    for (i = 0; qmi_wms_message_mode_values[i].value_nick; i++) {
        if (val == qmi_wms_message_mode_values[i].value)
            return qmi_wms_message_mode_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WMS_MESSAGE_MODE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WMS_MESSAGE_MODE_IS_FLAGS__
/**
 * qmi_wms_message_mode_build_string_from_mask:
 * @mask: bitmask of QmiWmsMessageMode values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWmsMessageMode in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wms_message_mode_build_string_from_mask (QmiWmsMessageMode mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wms_message_mode_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wms_message_mode_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wms_message_mode_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wms_message_mode_values[i].value) {
            guint c;
            gulong number = qmi_wms_message_mode_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wms_message_mode_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WMS_MESSAGE_MODE_IS_FLAGS__ */

static const GEnumValue qmi_wms_notification_type_values[] = {
    { QMI_WMS_NOTIFICATION_TYPE_PRIMARY, "QMI_WMS_NOTIFICATION_TYPE_PRIMARY", "primary" },
    { QMI_WMS_NOTIFICATION_TYPE_SECONDARY_GSM, "QMI_WMS_NOTIFICATION_TYPE_SECONDARY_GSM", "secondary-gsm" },
    { QMI_WMS_NOTIFICATION_TYPE_SECONDARY_UMTS, "QMI_WMS_NOTIFICATION_TYPE_SECONDARY_UMTS", "secondary-umts" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wms_notification_type_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWmsNotificationType"),
                                      qmi_wms_notification_type_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WMS_NOTIFICATION_TYPE_IS_ENUM__
/**
 * qmi_wms_notification_type_get_string:
 * @val: a QmiWmsNotificationType.
 *
 * Gets the nickname string for the #QmiWmsNotificationType specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wms_notification_type_get_string (QmiWmsNotificationType val)
{
    guint i;

    for (i = 0; qmi_wms_notification_type_values[i].value_nick; i++) {
        if (val == qmi_wms_notification_type_values[i].value)
            return qmi_wms_notification_type_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WMS_NOTIFICATION_TYPE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WMS_NOTIFICATION_TYPE_IS_FLAGS__
/**
 * qmi_wms_notification_type_build_string_from_mask:
 * @mask: bitmask of QmiWmsNotificationType values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWmsNotificationType in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wms_notification_type_build_string_from_mask (QmiWmsNotificationType mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wms_notification_type_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wms_notification_type_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wms_notification_type_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wms_notification_type_values[i].value) {
            guint c;
            gulong number = qmi_wms_notification_type_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wms_notification_type_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WMS_NOTIFICATION_TYPE_IS_FLAGS__ */

static const GEnumValue qmi_wms_cdma_service_option_values[] = {
    { QMI_WMS_CDMA_SERVICE_OPTION_AUTO, "QMI_WMS_CDMA_SERVICE_OPTION_AUTO", "auto" },
    { QMI_WMS_CDMA_SERVICE_OPTION_6, "QMI_WMS_CDMA_SERVICE_OPTION_6", "6" },
    { QMI_WMS_CDMA_SERVICE_OPTION_14, "QMI_WMS_CDMA_SERVICE_OPTION_14", "14" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wms_cdma_service_option_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWmsCdmaServiceOption"),
                                      qmi_wms_cdma_service_option_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WMS_CDMA_SERVICE_OPTION_IS_ENUM__
/**
 * qmi_wms_cdma_service_option_get_string:
 * @val: a QmiWmsCdmaServiceOption.
 *
 * Gets the nickname string for the #QmiWmsCdmaServiceOption specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wms_cdma_service_option_get_string (QmiWmsCdmaServiceOption val)
{
    guint i;

    for (i = 0; qmi_wms_cdma_service_option_values[i].value_nick; i++) {
        if (val == qmi_wms_cdma_service_option_values[i].value)
            return qmi_wms_cdma_service_option_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WMS_CDMA_SERVICE_OPTION_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WMS_CDMA_SERVICE_OPTION_IS_FLAGS__
/**
 * qmi_wms_cdma_service_option_build_string_from_mask:
 * @mask: bitmask of QmiWmsCdmaServiceOption values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWmsCdmaServiceOption in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wms_cdma_service_option_build_string_from_mask (QmiWmsCdmaServiceOption mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wms_cdma_service_option_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wms_cdma_service_option_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wms_cdma_service_option_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wms_cdma_service_option_values[i].value) {
            guint c;
            gulong number = qmi_wms_cdma_service_option_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wms_cdma_service_option_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WMS_CDMA_SERVICE_OPTION_IS_FLAGS__ */

static const GEnumValue qmi_wms_cdma_cause_code_values[] = {
    { QMI_WDS_CDMA_CAUSE_CODE_NETWORK_ADDRESS_VACANT, "QMI_WDS_CDMA_CAUSE_CODE_NETWORK_ADDRESS_VACANT", "network-address-vacant" },
    { QMI_WDS_CDMA_CAUSE_CODE_NETWORK_ADDRESS_TRANSLATION_FAILURE, "QMI_WDS_CDMA_CAUSE_CODE_NETWORK_ADDRESS_TRANSLATION_FAILURE", "network-address-translation-failure" },
    { QMI_WDS_CDMA_CAUSE_CODE_NETWORK_RESOURCE_SHORTAGE, "QMI_WDS_CDMA_CAUSE_CODE_NETWORK_RESOURCE_SHORTAGE", "network-resource-shortage" },
    { QMI_WDS_CDMA_CAUSE_CODE_NETWORK_FAILURE, "QMI_WDS_CDMA_CAUSE_CODE_NETWORK_FAILURE", "network-failure" },
    { QMI_WDS_CDMA_CAUSE_CODE_NETWORK_INVALID_TELESERVICE_ID, "QMI_WDS_CDMA_CAUSE_CODE_NETWORK_INVALID_TELESERVICE_ID", "network-invalid-teleservice-id" },
    { QMI_WDS_CDMA_CAUSE_CODE_NETWORK_OTHER, "QMI_WDS_CDMA_CAUSE_CODE_NETWORK_OTHER", "network-other" },
    { QMI_WDS_CDMA_CAUSE_CODE_DESTINATION_NO_PAGE_RESPONSE, "QMI_WDS_CDMA_CAUSE_CODE_DESTINATION_NO_PAGE_RESPONSE", "destination-no-page-response" },
    { QMI_WDS_CDMA_CAUSE_CODE_DESTINATION_BUSY, "QMI_WDS_CDMA_CAUSE_CODE_DESTINATION_BUSY", "destination-busy" },
    { QMI_WDS_CDMA_CAUSE_CODE_DESTINATION_NO_ACK, "QMI_WDS_CDMA_CAUSE_CODE_DESTINATION_NO_ACK", "destination-no-ack" },
    { QMI_WDS_CDMA_CAUSE_CODE_DESTINATION_RESOURCE_SHORTAGE, "QMI_WDS_CDMA_CAUSE_CODE_DESTINATION_RESOURCE_SHORTAGE", "destination-resource-shortage" },
    { QMI_WDS_CDMA_CAUSE_CODE_DESTINATION_SMS_DELIVERY_POSTPONED, "QMI_WDS_CDMA_CAUSE_CODE_DESTINATION_SMS_DELIVERY_POSTPONED", "destination-sms-delivery-postponed" },
    { QMI_WDS_CDMA_CAUSE_CODE_DESTINATION_OUT_OF_SERVICE, "QMI_WDS_CDMA_CAUSE_CODE_DESTINATION_OUT_OF_SERVICE", "destination-out-of-service" },
    { QMI_WDS_CDMA_CAUSE_CODE_DESTINATION_NOT_AT_ADDRESS, "QMI_WDS_CDMA_CAUSE_CODE_DESTINATION_NOT_AT_ADDRESS", "destination-not-at-address" },
    { QMI_WDS_CDMA_CAUSE_CODE_DESTINATION_OTHER, "QMI_WDS_CDMA_CAUSE_CODE_DESTINATION_OTHER", "destination-other" },
    { QMI_WDS_CDMA_CAUSE_CODE_RADIO_INTERFACE_RESOURCE_SHORTAGE, "QMI_WDS_CDMA_CAUSE_CODE_RADIO_INTERFACE_RESOURCE_SHORTAGE", "radio-interface-resource-shortage" },
    { QMI_WDS_CDMA_CAUSE_CODE_RADIO_INTERFACE_INCOMPATIBILITY, "QMI_WDS_CDMA_CAUSE_CODE_RADIO_INTERFACE_INCOMPATIBILITY", "radio-interface-incompatibility" },
    { QMI_WDS_CDMA_CAUSE_CODE_RADIO_INTERFACE_OTHER, "QMI_WDS_CDMA_CAUSE_CODE_RADIO_INTERFACE_OTHER", "radio-interface-other" },
    { QMI_WDS_CDMA_CAUSE_CODE_GENERAL_ENCODING, "QMI_WDS_CDMA_CAUSE_CODE_GENERAL_ENCODING", "general-encoding" },
    { QMI_WDS_CDMA_CAUSE_CODE_GENERAL_SMS_ORIGIN_DENIED, "QMI_WDS_CDMA_CAUSE_CODE_GENERAL_SMS_ORIGIN_DENIED", "general-sms-origin-denied" },
    { QMI_WDS_CDMA_CAUSE_CODE_GENERAL_SMS_DESTINATION_DENIED, "QMI_WDS_CDMA_CAUSE_CODE_GENERAL_SMS_DESTINATION_DENIED", "general-sms-destination-denied" },
    { QMI_WDS_CDMA_CAUSE_CODE_GENERAL_SUPPLEMENTARY_SERVICE_NOT_SUPPORTED, "QMI_WDS_CDMA_CAUSE_CODE_GENERAL_SUPPLEMENTARY_SERVICE_NOT_SUPPORTED", "general-supplementary-service-not-supported" },
    { QMI_WDS_CDMA_CAUSE_CODE_GENERAL_SMS_NOT_SUPPORTED, "QMI_WDS_CDMA_CAUSE_CODE_GENERAL_SMS_NOT_SUPPORTED", "general-sms-not-supported" },
    { QMI_WDS_CDMA_CAUSE_CODE_GENERAL_MISSING_EXPECTED_PARAMETER, "QMI_WDS_CDMA_CAUSE_CODE_GENERAL_MISSING_EXPECTED_PARAMETER", "general-missing-expected-parameter" },
    { QMI_WDS_CDMA_CAUSE_CODE_GENERAL_MISSING_MANDATORY_PARAMETER, "QMI_WDS_CDMA_CAUSE_CODE_GENERAL_MISSING_MANDATORY_PARAMETER", "general-missing-mandatory-parameter" },
    { QMI_WDS_CDMA_CAUSE_CODE_GENERAL_UNRECOGNIZED_PARAMETER_VALUE, "QMI_WDS_CDMA_CAUSE_CODE_GENERAL_UNRECOGNIZED_PARAMETER_VALUE", "general-unrecognized-parameter-value" },
    { QMI_WDS_CDMA_CAUSE_CODE_GENERAL_UNEXPECTED_PARAMETER_VALUE, "QMI_WDS_CDMA_CAUSE_CODE_GENERAL_UNEXPECTED_PARAMETER_VALUE", "general-unexpected-parameter-value" },
    { QMI_WDS_CDMA_CAUSE_CODE_GENERAL_USER_DATA_SIZE_ERROR, "QMI_WDS_CDMA_CAUSE_CODE_GENERAL_USER_DATA_SIZE_ERROR", "general-user-data-size-error" },
    { QMI_WDS_CDMA_CAUSE_CODE_GENERAL_OTHER, "QMI_WDS_CDMA_CAUSE_CODE_GENERAL_OTHER", "general-other" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wms_cdma_cause_code_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWmsCdmaCauseCode"),
                                      qmi_wms_cdma_cause_code_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WMS_CDMA_CAUSE_CODE_IS_ENUM__
/**
 * qmi_wms_cdma_cause_code_get_string:
 * @val: a QmiWmsCdmaCauseCode.
 *
 * Gets the nickname string for the #QmiWmsCdmaCauseCode specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wms_cdma_cause_code_get_string (QmiWmsCdmaCauseCode val)
{
    guint i;

    for (i = 0; qmi_wms_cdma_cause_code_values[i].value_nick; i++) {
        if (val == qmi_wms_cdma_cause_code_values[i].value)
            return qmi_wms_cdma_cause_code_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WMS_CDMA_CAUSE_CODE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WMS_CDMA_CAUSE_CODE_IS_FLAGS__
/**
 * qmi_wms_cdma_cause_code_build_string_from_mask:
 * @mask: bitmask of QmiWmsCdmaCauseCode values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWmsCdmaCauseCode in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wms_cdma_cause_code_build_string_from_mask (QmiWmsCdmaCauseCode mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wms_cdma_cause_code_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wms_cdma_cause_code_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wms_cdma_cause_code_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wms_cdma_cause_code_values[i].value) {
            guint c;
            gulong number = qmi_wms_cdma_cause_code_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wms_cdma_cause_code_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WMS_CDMA_CAUSE_CODE_IS_FLAGS__ */

static const GEnumValue qmi_wms_cdma_error_class_values[] = {
    { QMI_WMS_CDMA_ERROR_CLASS_TEMPORARY, "QMI_WMS_CDMA_ERROR_CLASS_TEMPORARY", "temporary" },
    { QMI_WMS_CDMA_ERROR_CLASS_PERMANENT, "QMI_WMS_CDMA_ERROR_CLASS_PERMANENT", "permanent" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wms_cdma_error_class_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWmsCdmaErrorClass"),
                                      qmi_wms_cdma_error_class_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WMS_CDMA_ERROR_CLASS_IS_ENUM__
/**
 * qmi_wms_cdma_error_class_get_string:
 * @val: a QmiWmsCdmaErrorClass.
 *
 * Gets the nickname string for the #QmiWmsCdmaErrorClass specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wms_cdma_error_class_get_string (QmiWmsCdmaErrorClass val)
{
    guint i;

    for (i = 0; qmi_wms_cdma_error_class_values[i].value_nick; i++) {
        if (val == qmi_wms_cdma_error_class_values[i].value)
            return qmi_wms_cdma_error_class_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WMS_CDMA_ERROR_CLASS_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WMS_CDMA_ERROR_CLASS_IS_FLAGS__
/**
 * qmi_wms_cdma_error_class_build_string_from_mask:
 * @mask: bitmask of QmiWmsCdmaErrorClass values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWmsCdmaErrorClass in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wms_cdma_error_class_build_string_from_mask (QmiWmsCdmaErrorClass mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wms_cdma_error_class_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wms_cdma_error_class_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wms_cdma_error_class_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wms_cdma_error_class_values[i].value) {
            guint c;
            gulong number = qmi_wms_cdma_error_class_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wms_cdma_error_class_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WMS_CDMA_ERROR_CLASS_IS_FLAGS__ */

static const GEnumValue qmi_wms_gsm_umts_rp_cause_values[] = {
    { QMI_WMS_GSM_UMTS_RP_CAUSE_UNASSIGNED_NUMBER, "QMI_WMS_GSM_UMTS_RP_CAUSE_UNASSIGNED_NUMBER", "unassigned-number" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_OPERATOR_DETERMINED_BARRING, "QMI_WMS_GSM_UMTS_RP_CAUSE_OPERATOR_DETERMINED_BARRING", "operator-determined-barring" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_CALL_BARRED, "QMI_WMS_GSM_UMTS_RP_CAUSE_CALL_BARRED", "call-barred" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_RESERVED, "QMI_WMS_GSM_UMTS_RP_CAUSE_RESERVED", "reserved" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_SMS_TRANSFER_REJECTED, "QMI_WMS_GSM_UMTS_RP_CAUSE_SMS_TRANSFER_REJECTED", "sms-transfer-rejected" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_MEMORY_CAPACITY_EXCEEDED, "QMI_WMS_GSM_UMTS_RP_CAUSE_MEMORY_CAPACITY_EXCEEDED", "memory-capacity-exceeded" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_DESTINATION_OUT_OF_ORDER, "QMI_WMS_GSM_UMTS_RP_CAUSE_DESTINATION_OUT_OF_ORDER", "destination-out-of-order" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_UNIDENTIFIED_SUBSCRIBER, "QMI_WMS_GSM_UMTS_RP_CAUSE_UNIDENTIFIED_SUBSCRIBER", "unidentified-subscriber" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_FACILITY_REJECTED, "QMI_WMS_GSM_UMTS_RP_CAUSE_FACILITY_REJECTED", "facility-rejected" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_UNKNOWN_SUBSCRIBER, "QMI_WMS_GSM_UMTS_RP_CAUSE_UNKNOWN_SUBSCRIBER", "unknown-subscriber" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_NETWORK_OUF_OF_ORDER, "QMI_WMS_GSM_UMTS_RP_CAUSE_NETWORK_OUF_OF_ORDER", "network-ouf-of-order" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_TEMPORARY_FAILURE, "QMI_WMS_GSM_UMTS_RP_CAUSE_TEMPORARY_FAILURE", "temporary-failure" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_CONGESTION, "QMI_WMS_GSM_UMTS_RP_CAUSE_CONGESTION", "congestion" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_RESOURCES_UNAVAILABLE, "QMI_WMS_GSM_UMTS_RP_CAUSE_RESOURCES_UNAVAILABLE", "resources-unavailable" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_FACILITY_NOT_SUBSCRIBED, "QMI_WMS_GSM_UMTS_RP_CAUSE_FACILITY_NOT_SUBSCRIBED", "facility-not-subscribed" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_FACILITY_NOT_IMPLEMENTED, "QMI_WMS_GSM_UMTS_RP_CAUSE_FACILITY_NOT_IMPLEMENTED", "facility-not-implemented" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_INVALID_SMS_TRANSFER_REFERENCE_VALUE, "QMI_WMS_GSM_UMTS_RP_CAUSE_INVALID_SMS_TRANSFER_REFERENCE_VALUE", "invalid-sms-transfer-reference-value" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_SEMANTICALLY_INCORRECT_MESSAGE, "QMI_WMS_GSM_UMTS_RP_CAUSE_SEMANTICALLY_INCORRECT_MESSAGE", "semantically-incorrect-message" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_INVALID_MANDATORY_INFO, "QMI_WMS_GSM_UMTS_RP_CAUSE_INVALID_MANDATORY_INFO", "invalid-mandatory-info" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_MESSAGE_TYPE_NOT_IMPLEMENTED, "QMI_WMS_GSM_UMTS_RP_CAUSE_MESSAGE_TYPE_NOT_IMPLEMENTED", "message-type-not-implemented" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_MESSAGE_NOT_COMPATIBLE_WITH_SMS, "QMI_WMS_GSM_UMTS_RP_CAUSE_MESSAGE_NOT_COMPATIBLE_WITH_SMS", "message-not-compatible-with-sms" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_INFORMATION_ELEMENT_NOT_IMPLEMENTED, "QMI_WMS_GSM_UMTS_RP_CAUSE_INFORMATION_ELEMENT_NOT_IMPLEMENTED", "information-element-not-implemented" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_PROTOCOL_ERROR, "QMI_WMS_GSM_UMTS_RP_CAUSE_PROTOCOL_ERROR", "protocol-error" },
    { QMI_WMS_GSM_UMTS_RP_CAUSE_INTERWORKING, "QMI_WMS_GSM_UMTS_RP_CAUSE_INTERWORKING", "interworking" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wms_gsm_umts_rp_cause_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWmsGsmUmtsRpCause"),
                                      qmi_wms_gsm_umts_rp_cause_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WMS_GSM_UMTS_RP_CAUSE_IS_ENUM__
/**
 * qmi_wms_gsm_umts_rp_cause_get_string:
 * @val: a QmiWmsGsmUmtsRpCause.
 *
 * Gets the nickname string for the #QmiWmsGsmUmtsRpCause specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wms_gsm_umts_rp_cause_get_string (QmiWmsGsmUmtsRpCause val)
{
    guint i;

    for (i = 0; qmi_wms_gsm_umts_rp_cause_values[i].value_nick; i++) {
        if (val == qmi_wms_gsm_umts_rp_cause_values[i].value)
            return qmi_wms_gsm_umts_rp_cause_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WMS_GSM_UMTS_RP_CAUSE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WMS_GSM_UMTS_RP_CAUSE_IS_FLAGS__
/**
 * qmi_wms_gsm_umts_rp_cause_build_string_from_mask:
 * @mask: bitmask of QmiWmsGsmUmtsRpCause values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWmsGsmUmtsRpCause in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wms_gsm_umts_rp_cause_build_string_from_mask (QmiWmsGsmUmtsRpCause mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wms_gsm_umts_rp_cause_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wms_gsm_umts_rp_cause_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wms_gsm_umts_rp_cause_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wms_gsm_umts_rp_cause_values[i].value) {
            guint c;
            gulong number = qmi_wms_gsm_umts_rp_cause_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wms_gsm_umts_rp_cause_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WMS_GSM_UMTS_RP_CAUSE_IS_FLAGS__ */

static const GEnumValue qmi_wms_gsm_umts_tp_cause_values[] = {
    { QMI_WMS_GSM_UMTS_TP_CAUSE_TELE_INTERWORKING_NOT_SUPPORTED, "QMI_WMS_GSM_UMTS_TP_CAUSE_TELE_INTERWORKING_NOT_SUPPORTED", "tele-interworking-not-supported" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_SHORT_MESSAGE_TYPE_0_NOT_SUPPORTED, "QMI_WMS_GSM_UMTS_TP_CAUSE_SHORT_MESSAGE_TYPE_0_NOT_SUPPORTED", "short-message-type-0-not-supported" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_SHORT_MESSAGE_CANNOT_BE_REPLACED, "QMI_WMS_GSM_UMTS_TP_CAUSE_SHORT_MESSAGE_CANNOT_BE_REPLACED", "short-message-cannot-be-replaced" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_UNSPECIFIED_PID_ERROR, "QMI_WMS_GSM_UMTS_TP_CAUSE_UNSPECIFIED_PID_ERROR", "unspecified-pid-error" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_DCS_NOT_SUPPORTED, "QMI_WMS_GSM_UMTS_TP_CAUSE_DCS_NOT_SUPPORTED", "dcs-not-supported" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_MESSAGE_CLASS_NOT_SUPPORTED, "QMI_WMS_GSM_UMTS_TP_CAUSE_MESSAGE_CLASS_NOT_SUPPORTED", "message-class-not-supported" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_UNSPECIFIED_DCS_ERROR, "QMI_WMS_GSM_UMTS_TP_CAUSE_UNSPECIFIED_DCS_ERROR", "unspecified-dcs-error" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_COMMAND_CANNOT_BE_ACTIONED, "QMI_WMS_GSM_UMTS_TP_CAUSE_COMMAND_CANNOT_BE_ACTIONED", "command-cannot-be-actioned" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_COMMAND_UNSUPPORTED, "QMI_WMS_GSM_UMTS_TP_CAUSE_COMMAND_UNSUPPORTED", "command-unsupported" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_UNSPECIFIED_COMMAND_ERROR, "QMI_WMS_GSM_UMTS_TP_CAUSE_UNSPECIFIED_COMMAND_ERROR", "unspecified-command-error" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_TPDU_NOT_SUPPORTED, "QMI_WMS_GSM_UMTS_TP_CAUSE_TPDU_NOT_SUPPORTED", "tpdu-not-supported" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_SC_BUSY, "QMI_WMS_GSM_UMTS_TP_CAUSE_SC_BUSY", "sc-busy" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_NO_SC_SUBSCRIPTION, "QMI_WMS_GSM_UMTS_TP_CAUSE_NO_SC_SUBSCRIPTION", "no-sc-subscription" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_SC_SYSTEM_FAILURE, "QMI_WMS_GSM_UMTS_TP_CAUSE_SC_SYSTEM_FAILURE", "sc-system-failure" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_INVALID_SME_ADDRESS, "QMI_WMS_GSM_UMTS_TP_CAUSE_INVALID_SME_ADDRESS", "invalid-sme-address" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_DESTINATION_SME_BARRED, "QMI_WMS_GSM_UMTS_TP_CAUSE_DESTINATION_SME_BARRED", "destination-sme-barred" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_SM_REJECTED_OR_DUPLICATE, "QMI_WMS_GSM_UMTS_TP_CAUSE_SM_REJECTED_OR_DUPLICATE", "sm-rejected-or-duplicate" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_VPF_NOT_SUPPORTED, "QMI_WMS_GSM_UMTS_TP_CAUSE_VPF_NOT_SUPPORTED", "vpf-not-supported" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_VP_NOT_SUPPORTED, "QMI_WMS_GSM_UMTS_TP_CAUSE_VP_NOT_SUPPORTED", "vp-not-supported" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_SIM_SMS_STORAGE_FULL, "QMI_WMS_GSM_UMTS_TP_CAUSE_SIM_SMS_STORAGE_FULL", "sim-sms-storage-full" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_NO_SMS_STORAGE_CAPABILITY_IN_SIM, "QMI_WMS_GSM_UMTS_TP_CAUSE_NO_SMS_STORAGE_CAPABILITY_IN_SIM", "no-sms-storage-capability-in-sim" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_MS_ERROR, "QMI_WMS_GSM_UMTS_TP_CAUSE_MS_ERROR", "ms-error" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_MEMORY_CAPACITY_EXCEEDED, "QMI_WMS_GSM_UMTS_TP_CAUSE_MEMORY_CAPACITY_EXCEEDED", "memory-capacity-exceeded" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_SIM_APPLICATION_TOOLKIT_BUSY, "QMI_WMS_GSM_UMTS_TP_CAUSE_SIM_APPLICATION_TOOLKIT_BUSY", "sim-application-toolkit-busy" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_SIM_DATA_DOWNLOAD_ERROR, "QMI_WMS_GSM_UMTS_TP_CAUSE_SIM_DATA_DOWNLOAD_ERROR", "sim-data-download-error" },
    { QMI_WMS_GSM_UMTS_TP_CAUSE_UNSPECIFIED_ERROR, "QMI_WMS_GSM_UMTS_TP_CAUSE_UNSPECIFIED_ERROR", "unspecified-error" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wms_gsm_umts_tp_cause_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWmsGsmUmtsTpCause"),
                                      qmi_wms_gsm_umts_tp_cause_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WMS_GSM_UMTS_TP_CAUSE_IS_ENUM__
/**
 * qmi_wms_gsm_umts_tp_cause_get_string:
 * @val: a QmiWmsGsmUmtsTpCause.
 *
 * Gets the nickname string for the #QmiWmsGsmUmtsTpCause specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wms_gsm_umts_tp_cause_get_string (QmiWmsGsmUmtsTpCause val)
{
    guint i;

    for (i = 0; qmi_wms_gsm_umts_tp_cause_values[i].value_nick; i++) {
        if (val == qmi_wms_gsm_umts_tp_cause_values[i].value)
            return qmi_wms_gsm_umts_tp_cause_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WMS_GSM_UMTS_TP_CAUSE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WMS_GSM_UMTS_TP_CAUSE_IS_FLAGS__
/**
 * qmi_wms_gsm_umts_tp_cause_build_string_from_mask:
 * @mask: bitmask of QmiWmsGsmUmtsTpCause values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWmsGsmUmtsTpCause in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wms_gsm_umts_tp_cause_build_string_from_mask (QmiWmsGsmUmtsTpCause mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wms_gsm_umts_tp_cause_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wms_gsm_umts_tp_cause_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wms_gsm_umts_tp_cause_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wms_gsm_umts_tp_cause_values[i].value) {
            guint c;
            gulong number = qmi_wms_gsm_umts_tp_cause_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wms_gsm_umts_tp_cause_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WMS_GSM_UMTS_TP_CAUSE_IS_FLAGS__ */

static const GEnumValue qmi_wms_message_delivery_failure_type_values[] = {
    { QMI_WMS_MESSAGE_DELIVERY_FAILURE_TYPE_TEMPORARY, "QMI_WMS_MESSAGE_DELIVERY_FAILURE_TYPE_TEMPORARY", "temporary" },
    { QMI_WMS_MESSAGE_DELIVERY_FAILURE_TYPE_PERMANENT, "QMI_WMS_MESSAGE_DELIVERY_FAILURE_TYPE_PERMANENT", "permanent" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wms_message_delivery_failure_type_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWmsMessageDeliveryFailureType"),
                                      qmi_wms_message_delivery_failure_type_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WMS_MESSAGE_DELIVERY_FAILURE_TYPE_IS_ENUM__
/**
 * qmi_wms_message_delivery_failure_type_get_string:
 * @val: a QmiWmsMessageDeliveryFailureType.
 *
 * Gets the nickname string for the #QmiWmsMessageDeliveryFailureType specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wms_message_delivery_failure_type_get_string (QmiWmsMessageDeliveryFailureType val)
{
    guint i;

    for (i = 0; qmi_wms_message_delivery_failure_type_values[i].value_nick; i++) {
        if (val == qmi_wms_message_delivery_failure_type_values[i].value)
            return qmi_wms_message_delivery_failure_type_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WMS_MESSAGE_DELIVERY_FAILURE_TYPE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WMS_MESSAGE_DELIVERY_FAILURE_TYPE_IS_FLAGS__
/**
 * qmi_wms_message_delivery_failure_type_build_string_from_mask:
 * @mask: bitmask of QmiWmsMessageDeliveryFailureType values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWmsMessageDeliveryFailureType in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wms_message_delivery_failure_type_build_string_from_mask (QmiWmsMessageDeliveryFailureType mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wms_message_delivery_failure_type_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wms_message_delivery_failure_type_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wms_message_delivery_failure_type_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wms_message_delivery_failure_type_values[i].value) {
            guint c;
            gulong number = qmi_wms_message_delivery_failure_type_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wms_message_delivery_failure_type_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WMS_MESSAGE_DELIVERY_FAILURE_TYPE_IS_FLAGS__ */

static const GEnumValue qmi_wms_message_tag_type_values[] = {
    { QMI_WMS_MESSAGE_TAG_TYPE_MT_READ, "QMI_WMS_MESSAGE_TAG_TYPE_MT_READ", "mt-read" },
    { QMI_WMS_MESSAGE_TAG_TYPE_MT_NOT_READ, "QMI_WMS_MESSAGE_TAG_TYPE_MT_NOT_READ", "mt-not-read" },
    { QMI_WMS_MESSAGE_TAG_TYPE_MO_SENT, "QMI_WMS_MESSAGE_TAG_TYPE_MO_SENT", "mo-sent" },
    { QMI_WMS_MESSAGE_TAG_TYPE_MO_NOT_SENT, "QMI_WMS_MESSAGE_TAG_TYPE_MO_NOT_SENT", "mo-not-sent" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wms_message_tag_type_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWmsMessageTagType"),
                                      qmi_wms_message_tag_type_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WMS_MESSAGE_TAG_TYPE_IS_ENUM__
/**
 * qmi_wms_message_tag_type_get_string:
 * @val: a QmiWmsMessageTagType.
 *
 * Gets the nickname string for the #QmiWmsMessageTagType specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wms_message_tag_type_get_string (QmiWmsMessageTagType val)
{
    guint i;

    for (i = 0; qmi_wms_message_tag_type_values[i].value_nick; i++) {
        if (val == qmi_wms_message_tag_type_values[i].value)
            return qmi_wms_message_tag_type_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WMS_MESSAGE_TAG_TYPE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WMS_MESSAGE_TAG_TYPE_IS_FLAGS__
/**
 * qmi_wms_message_tag_type_build_string_from_mask:
 * @mask: bitmask of QmiWmsMessageTagType values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWmsMessageTagType in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wms_message_tag_type_build_string_from_mask (QmiWmsMessageTagType mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wms_message_tag_type_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wms_message_tag_type_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wms_message_tag_type_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wms_message_tag_type_values[i].value) {
            guint c;
            gulong number = qmi_wms_message_tag_type_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wms_message_tag_type_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WMS_MESSAGE_TAG_TYPE_IS_FLAGS__ */

static const GEnumValue qmi_wms_message_protocol_values[] = {
    { QMI_WMS_MESSAGE_PROTOCOL_CDMA, "QMI_WMS_MESSAGE_PROTOCOL_CDMA", "cdma" },
    { QMI_WMS_MESSAGE_PROTOCOL_WCDMA, "QMI_WMS_MESSAGE_PROTOCOL_WCDMA", "wcdma" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wms_message_protocol_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWmsMessageProtocol"),
                                      qmi_wms_message_protocol_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WMS_MESSAGE_PROTOCOL_IS_ENUM__
/**
 * qmi_wms_message_protocol_get_string:
 * @val: a QmiWmsMessageProtocol.
 *
 * Gets the nickname string for the #QmiWmsMessageProtocol specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wms_message_protocol_get_string (QmiWmsMessageProtocol val)
{
    guint i;

    for (i = 0; qmi_wms_message_protocol_values[i].value_nick; i++) {
        if (val == qmi_wms_message_protocol_values[i].value)
            return qmi_wms_message_protocol_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WMS_MESSAGE_PROTOCOL_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WMS_MESSAGE_PROTOCOL_IS_FLAGS__
/**
 * qmi_wms_message_protocol_build_string_from_mask:
 * @mask: bitmask of QmiWmsMessageProtocol values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWmsMessageProtocol in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wms_message_protocol_build_string_from_mask (QmiWmsMessageProtocol mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wms_message_protocol_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wms_message_protocol_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wms_message_protocol_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wms_message_protocol_values[i].value) {
            guint c;
            gulong number = qmi_wms_message_protocol_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wms_message_protocol_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WMS_MESSAGE_PROTOCOL_IS_FLAGS__ */

static const GEnumValue qmi_wms_message_type_values[] = {
    { QMI_WMS_MESSAGE_TYPE_POINT_TO_POINT, "QMI_WMS_MESSAGE_TYPE_POINT_TO_POINT", "point" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wms_message_type_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWmsMessageType"),
                                      qmi_wms_message_type_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WMS_MESSAGE_TYPE_IS_ENUM__
/**
 * qmi_wms_message_type_get_string:
 * @val: a QmiWmsMessageType.
 *
 * Gets the nickname string for the #QmiWmsMessageType specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wms_message_type_get_string (QmiWmsMessageType val)
{
    guint i;

    for (i = 0; qmi_wms_message_type_values[i].value_nick; i++) {
        if (val == qmi_wms_message_type_values[i].value)
            return qmi_wms_message_type_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WMS_MESSAGE_TYPE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WMS_MESSAGE_TYPE_IS_FLAGS__
/**
 * qmi_wms_message_type_build_string_from_mask:
 * @mask: bitmask of QmiWmsMessageType values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWmsMessageType in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wms_message_type_build_string_from_mask (QmiWmsMessageType mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wms_message_type_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wms_message_type_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wms_message_type_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wms_message_type_values[i].value) {
            guint c;
            gulong number = qmi_wms_message_type_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wms_message_type_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WMS_MESSAGE_TYPE_IS_FLAGS__ */

static const GEnumValue qmi_wms_message_class_values[] = {
    { QMI_WMS_MESSAGE_CLASS_0, "QMI_WMS_MESSAGE_CLASS_0", "0" },
    { QMI_WMS_MESSAGE_CLASS_1, "QMI_WMS_MESSAGE_CLASS_1", "1" },
    { QMI_WMS_MESSAGE_CLASS_2, "QMI_WMS_MESSAGE_CLASS_2", "2" },
    { QMI_WMS_MESSAGE_CLASS_3, "QMI_WMS_MESSAGE_CLASS_3", "3" },
    { QMI_WMS_MESSAGE_CLASS_NONE, "QMI_WMS_MESSAGE_CLASS_NONE", "none" },
    { QMI_WMS_MESSAGE_CLASS_CDMA, "QMI_WMS_MESSAGE_CLASS_CDMA", "cdma" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wms_message_class_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWmsMessageClass"),
                                      qmi_wms_message_class_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WMS_MESSAGE_CLASS_IS_ENUM__
/**
 * qmi_wms_message_class_get_string:
 * @val: a QmiWmsMessageClass.
 *
 * Gets the nickname string for the #QmiWmsMessageClass specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wms_message_class_get_string (QmiWmsMessageClass val)
{
    guint i;

    for (i = 0; qmi_wms_message_class_values[i].value_nick; i++) {
        if (val == qmi_wms_message_class_values[i].value)
            return qmi_wms_message_class_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WMS_MESSAGE_CLASS_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WMS_MESSAGE_CLASS_IS_FLAGS__
/**
 * qmi_wms_message_class_build_string_from_mask:
 * @mask: bitmask of QmiWmsMessageClass values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWmsMessageClass in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wms_message_class_build_string_from_mask (QmiWmsMessageClass mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wms_message_class_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wms_message_class_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wms_message_class_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wms_message_class_values[i].value) {
            guint c;
            gulong number = qmi_wms_message_class_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wms_message_class_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WMS_MESSAGE_CLASS_IS_FLAGS__ */

static const GEnumValue qmi_wms_receipt_action_values[] = {
    { QMI_WMS_RECEIPT_ACTION_DISCARD, "QMI_WMS_RECEIPT_ACTION_DISCARD", "discard" },
    { QMI_WMS_RECEIPT_ACTION_STORE_AND_NOTIFY, "QMI_WMS_RECEIPT_ACTION_STORE_AND_NOTIFY", "store-and-notify" },
    { QMI_WMS_RECEIPT_ACTION_TRANSFER_ONLY, "QMI_WMS_RECEIPT_ACTION_TRANSFER_ONLY", "transfer-only" },
    { QMI_WMS_RECEIPT_ACTION_TRANSFER_AND_ACK, "QMI_WMS_RECEIPT_ACTION_TRANSFER_AND_ACK", "transfer-and-ack" },
    { QMI_WMS_RECEIPT_ACTION_UNKNOWN, "QMI_WMS_RECEIPT_ACTION_UNKNOWN", "unknown" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wms_receipt_action_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWmsReceiptAction"),
                                      qmi_wms_receipt_action_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WMS_RECEIPT_ACTION_IS_ENUM__
/**
 * qmi_wms_receipt_action_get_string:
 * @val: a QmiWmsReceiptAction.
 *
 * Gets the nickname string for the #QmiWmsReceiptAction specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wms_receipt_action_get_string (QmiWmsReceiptAction val)
{
    guint i;

    for (i = 0; qmi_wms_receipt_action_values[i].value_nick; i++) {
        if (val == qmi_wms_receipt_action_values[i].value)
            return qmi_wms_receipt_action_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WMS_RECEIPT_ACTION_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WMS_RECEIPT_ACTION_IS_FLAGS__
/**
 * qmi_wms_receipt_action_build_string_from_mask:
 * @mask: bitmask of QmiWmsReceiptAction values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWmsReceiptAction in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wms_receipt_action_build_string_from_mask (QmiWmsReceiptAction mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wms_receipt_action_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wms_receipt_action_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wms_receipt_action_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wms_receipt_action_values[i].value) {
            guint c;
            gulong number = qmi_wms_receipt_action_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wms_receipt_action_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WMS_RECEIPT_ACTION_IS_FLAGS__ */

static const GEnumValue qmi_wms_transfer_indication_values[] = {
    { QMI_WMS_TRANSFER_INDICATION_CLIENT, "QMI_WMS_TRANSFER_INDICATION_CLIENT", "client" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_wms_transfer_indication_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiWmsTransferIndication"),
                                      qmi_wms_transfer_indication_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_WMS_TRANSFER_INDICATION_IS_ENUM__
/**
 * qmi_wms_transfer_indication_get_string:
 * @val: a QmiWmsTransferIndication.
 *
 * Gets the nickname string for the #QmiWmsTransferIndication specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_wms_transfer_indication_get_string (QmiWmsTransferIndication val)
{
    guint i;

    for (i = 0; qmi_wms_transfer_indication_values[i].value_nick; i++) {
        if (val == qmi_wms_transfer_indication_values[i].value)
            return qmi_wms_transfer_indication_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_WMS_TRANSFER_INDICATION_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_WMS_TRANSFER_INDICATION_IS_FLAGS__
/**
 * qmi_wms_transfer_indication_build_string_from_mask:
 * @mask: bitmask of QmiWmsTransferIndication values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiWmsTransferIndication in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_wms_transfer_indication_build_string_from_mask (QmiWmsTransferIndication mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_wms_transfer_indication_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_wms_transfer_indication_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_wms_transfer_indication_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_wms_transfer_indication_values[i].value) {
            guint c;
            gulong number = qmi_wms_transfer_indication_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_wms_transfer_indication_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_WMS_TRANSFER_INDICATION_IS_FLAGS__ */

/* enumerations from "../../libqmi-glib/qmi-enums-pds.h" */
static const GEnumValue qmi_pds_operation_mode_values[] = {
    { QMI_PDS_OPERATION_MODE_UNKNOWN, "QMI_PDS_OPERATION_MODE_UNKNOWN", "unknown" },
    { QMI_PDS_OPERATION_MODE_STANDALONE, "QMI_PDS_OPERATION_MODE_STANDALONE", "standalone" },
    { QMI_PDS_OPERATION_MODE_MS_BASED, "QMI_PDS_OPERATION_MODE_MS_BASED", "ms-based" },
    { QMI_PDS_OPERATION_MODE_MS_ASSISTED, "QMI_PDS_OPERATION_MODE_MS_ASSISTED", "ms-assisted" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_pds_operation_mode_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiPdsOperationMode"),
                                      qmi_pds_operation_mode_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_PDS_OPERATION_MODE_IS_ENUM__
/**
 * qmi_pds_operation_mode_get_string:
 * @val: a QmiPdsOperationMode.
 *
 * Gets the nickname string for the #QmiPdsOperationMode specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_pds_operation_mode_get_string (QmiPdsOperationMode val)
{
    guint i;

    for (i = 0; qmi_pds_operation_mode_values[i].value_nick; i++) {
        if (val == qmi_pds_operation_mode_values[i].value)
            return qmi_pds_operation_mode_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_PDS_OPERATION_MODE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_PDS_OPERATION_MODE_IS_FLAGS__
/**
 * qmi_pds_operation_mode_build_string_from_mask:
 * @mask: bitmask of QmiPdsOperationMode values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiPdsOperationMode in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_pds_operation_mode_build_string_from_mask (QmiPdsOperationMode mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_pds_operation_mode_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_pds_operation_mode_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_pds_operation_mode_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_pds_operation_mode_values[i].value) {
            guint c;
            gulong number = qmi_pds_operation_mode_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_pds_operation_mode_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_PDS_OPERATION_MODE_IS_FLAGS__ */

static const GEnumValue qmi_pds_position_session_status_values[] = {
    { QMI_PDS_POSITION_SESSION_STATUS_SUCCESS, "QMI_PDS_POSITION_SESSION_STATUS_SUCCESS", "success" },
    { QMI_PDS_POSITION_SESSION_STATUS_IN_PROGRESS, "QMI_PDS_POSITION_SESSION_STATUS_IN_PROGRESS", "in-progress" },
    { QMI_PDS_POSITION_SESSION_STATUS_GENERAL_FAILURE, "QMI_PDS_POSITION_SESSION_STATUS_GENERAL_FAILURE", "general-failure" },
    { QMI_PDS_POSITION_SESSION_STATUS_TIMEOUT, "QMI_PDS_POSITION_SESSION_STATUS_TIMEOUT", "timeout" },
    { QMI_PDS_POSITION_SESSION_STATUS_USER_ENDED_SESSION, "QMI_PDS_POSITION_SESSION_STATUS_USER_ENDED_SESSION", "user-ended-session" },
    { QMI_PDS_POSITION_SESSION_STATUS_BAD_PARAMETER, "QMI_PDS_POSITION_SESSION_STATUS_BAD_PARAMETER", "bad-parameter" },
    { QMI_PDS_POSITION_SESSION_STATUS_PHONE_OFFLINE, "QMI_PDS_POSITION_SESSION_STATUS_PHONE_OFFLINE", "phone-offline" },
    { QMI_PDS_POSITION_SESSION_STATUS_ENGINE_LOCKED, "QMI_PDS_POSITION_SESSION_STATUS_ENGINE_LOCKED", "engine-locked" },
    { QMI_PDS_POSITION_SESSION_STATUS_E911_SESSION_IN_PROGRESS, "QMI_PDS_POSITION_SESSION_STATUS_E911_SESSION_IN_PROGRESS", "e911-session-in-progress" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_pds_position_session_status_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiPdsPositionSessionStatus"),
                                      qmi_pds_position_session_status_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_PDS_POSITION_SESSION_STATUS_IS_ENUM__
/**
 * qmi_pds_position_session_status_get_string:
 * @val: a QmiPdsPositionSessionStatus.
 *
 * Gets the nickname string for the #QmiPdsPositionSessionStatus specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_pds_position_session_status_get_string (QmiPdsPositionSessionStatus val)
{
    guint i;

    for (i = 0; qmi_pds_position_session_status_values[i].value_nick; i++) {
        if (val == qmi_pds_position_session_status_values[i].value)
            return qmi_pds_position_session_status_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_PDS_POSITION_SESSION_STATUS_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_PDS_POSITION_SESSION_STATUS_IS_FLAGS__
/**
 * qmi_pds_position_session_status_build_string_from_mask:
 * @mask: bitmask of QmiPdsPositionSessionStatus values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiPdsPositionSessionStatus in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_pds_position_session_status_build_string_from_mask (QmiPdsPositionSessionStatus mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_pds_position_session_status_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_pds_position_session_status_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_pds_position_session_status_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_pds_position_session_status_values[i].value) {
            guint c;
            gulong number = qmi_pds_position_session_status_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_pds_position_session_status_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_PDS_POSITION_SESSION_STATUS_IS_FLAGS__ */

static const GFlagsValue qmi_pds_data_valid_values[] = {
    { QMI_PDS_DATA_VALID_TIMESTAMP_CALENDAR, "QMI_PDS_DATA_VALID_TIMESTAMP_CALENDAR", "timestamp-calendar" },
    { QMI_PDS_DATA_VALID_TIMESTAMP_UTC, "QMI_PDS_DATA_VALID_TIMESTAMP_UTC", "timestamp-utc" },
    { QMI_PDS_DATA_VALID_LEAP_SECONDS, "QMI_PDS_DATA_VALID_LEAP_SECONDS", "leap-seconds" },
    { QMI_PDS_DATA_VALID_TIME_UNCERTAINTY, "QMI_PDS_DATA_VALID_TIME_UNCERTAINTY", "time-uncertainty" },
    { QMI_PDS_DATA_VALID_LATITUDE, "QMI_PDS_DATA_VALID_LATITUDE", "latitude" },
    { QMI_PDS_DATA_VALID_LONGITUDE, "QMI_PDS_DATA_VALID_LONGITUDE", "longitude" },
    { QMI_PDS_DATA_VALID_ELLIPSOID_ALTITUDE, "QMI_PDS_DATA_VALID_ELLIPSOID_ALTITUDE", "ellipsoid-altitude" },
    { QMI_PDS_DATA_VALID_MEAN_SEA_LEVEL_ALTITUDE, "QMI_PDS_DATA_VALID_MEAN_SEA_LEVEL_ALTITUDE", "mean-sea-level-altitude" },
    { QMI_PDS_DATA_VALID_HORIZONTAL_SPEED, "QMI_PDS_DATA_VALID_HORIZONTAL_SPEED", "horizontal-speed" },
    { QMI_PDS_DATA_VALID_VERTICAL_SPEED, "QMI_PDS_DATA_VALID_VERTICAL_SPEED", "vertical-speed" },
    { QMI_PDS_DATA_VALID_HEADING, "QMI_PDS_DATA_VALID_HEADING", "heading" },
    { QMI_PDS_DATA_VALID_HORIZONTAL_UNCERTAINTY_CIRCULAR, "QMI_PDS_DATA_VALID_HORIZONTAL_UNCERTAINTY_CIRCULAR", "horizontal-uncertainty-circular" },
    { QMI_PDS_DATA_VALID_HORIZONTAL_UNCERTAINTY_ELLIPSE_SEMI_MAJOR, "QMI_PDS_DATA_VALID_HORIZONTAL_UNCERTAINTY_ELLIPSE_SEMI_MAJOR", "horizontal-uncertainty-ellipse-semi-major" },
    { QMI_PDS_DATA_VALID_HORIZONTAL_UNCERTAINTY_ELLIPSE_SEMI_MINOR, "QMI_PDS_DATA_VALID_HORIZONTAL_UNCERTAINTY_ELLIPSE_SEMI_MINOR", "horizontal-uncertainty-ellipse-semi-minor" },
    { QMI_PDS_DATA_VALID_HORIZONTAL_UNCERTAINTY_ELLIPSE_ORIENT_AZIMUTH, "QMI_PDS_DATA_VALID_HORIZONTAL_UNCERTAINTY_ELLIPSE_ORIENT_AZIMUTH", "horizontal-uncertainty-ellipse-orient-azimuth" },
    { QMI_PDS_DATA_VALID_VERTICAL_UNCERTAINTY, "QMI_PDS_DATA_VALID_VERTICAL_UNCERTAINTY", "vertical-uncertainty" },
    { QMI_PDS_DATA_VALID_HORIZONTAL_VELOCITY_UNCERTAINTY, "QMI_PDS_DATA_VALID_HORIZONTAL_VELOCITY_UNCERTAINTY", "horizontal-velocity-uncertainty" },
    { QMI_PDS_DATA_VALID_VERTICAL_VELOCITY_UNCERTAINTY, "QMI_PDS_DATA_VALID_VERTICAL_VELOCITY_UNCERTAINTY", "vertical-velocity-uncertainty" },
    { QMI_PDS_DATA_VALID_HORIZONTAL_CONFIDENCE, "QMI_PDS_DATA_VALID_HORIZONTAL_CONFIDENCE", "horizontal-confidence" },
    { QMI_PDS_DATA_VALID_POSITION_DOP, "QMI_PDS_DATA_VALID_POSITION_DOP", "position-dop" },
    { QMI_PDS_DATA_VALID_HORIZONTAL_DOP, "QMI_PDS_DATA_VALID_HORIZONTAL_DOP", "horizontal-dop" },
    { QMI_PDS_DATA_VALID_VERTICAL_DOP, "QMI_PDS_DATA_VALID_VERTICAL_DOP", "vertical-dop" },
    { QMI_PDS_DATA_VALID_OPERATING_MODE, "QMI_PDS_DATA_VALID_OPERATING_MODE", "operating-mode" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_pds_data_valid_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("QmiPdsDataValid"),
                                      qmi_pds_data_valid_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_PDS_DATA_VALID_IS_ENUM__
/**
 * qmi_pds_data_valid_get_string:
 * @val: a QmiPdsDataValid.
 *
 * Gets the nickname string for the #QmiPdsDataValid specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_pds_data_valid_get_string (QmiPdsDataValid val)
{
    guint i;

    for (i = 0; qmi_pds_data_valid_values[i].value_nick; i++) {
        if (val == qmi_pds_data_valid_values[i].value)
            return qmi_pds_data_valid_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_PDS_DATA_VALID_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_PDS_DATA_VALID_IS_FLAGS__
/**
 * qmi_pds_data_valid_build_string_from_mask:
 * @mask: bitmask of QmiPdsDataValid values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiPdsDataValid in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_pds_data_valid_build_string_from_mask (QmiPdsDataValid mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_pds_data_valid_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_pds_data_valid_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_pds_data_valid_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_pds_data_valid_values[i].value) {
            guint c;
            gulong number = qmi_pds_data_valid_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_pds_data_valid_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_PDS_DATA_VALID_IS_FLAGS__ */

static const GEnumValue qmi_pds_tracking_session_state_values[] = {
    { QMI_PDS_TRACKING_SESSION_STATE_UNKNOWN, "QMI_PDS_TRACKING_SESSION_STATE_UNKNOWN", "unknown" },
    { QMI_PDS_TRACKING_SESSION_STATE_INACTIVE, "QMI_PDS_TRACKING_SESSION_STATE_INACTIVE", "inactive" },
    { QMI_PDS_TRACKING_SESSION_STATE_ACTIVE, "QMI_PDS_TRACKING_SESSION_STATE_ACTIVE", "active" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_pds_tracking_session_state_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiPdsTrackingSessionState"),
                                      qmi_pds_tracking_session_state_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_PDS_TRACKING_SESSION_STATE_IS_ENUM__
/**
 * qmi_pds_tracking_session_state_get_string:
 * @val: a QmiPdsTrackingSessionState.
 *
 * Gets the nickname string for the #QmiPdsTrackingSessionState specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_pds_tracking_session_state_get_string (QmiPdsTrackingSessionState val)
{
    guint i;

    for (i = 0; qmi_pds_tracking_session_state_values[i].value_nick; i++) {
        if (val == qmi_pds_tracking_session_state_values[i].value)
            return qmi_pds_tracking_session_state_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_PDS_TRACKING_SESSION_STATE_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_PDS_TRACKING_SESSION_STATE_IS_FLAGS__
/**
 * qmi_pds_tracking_session_state_build_string_from_mask:
 * @mask: bitmask of QmiPdsTrackingSessionState values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiPdsTrackingSessionState in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_pds_tracking_session_state_build_string_from_mask (QmiPdsTrackingSessionState mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_pds_tracking_session_state_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_pds_tracking_session_state_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_pds_tracking_session_state_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_pds_tracking_session_state_values[i].value) {
            guint c;
            gulong number = qmi_pds_tracking_session_state_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_pds_tracking_session_state_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_PDS_TRACKING_SESSION_STATE_IS_FLAGS__ */


/* Generated data ends here */

