
/* Generated data (by glib-mkenums) */

#include "qmi-enum-types-private.h"

/* enumerations from "../../libqmi-glib/qmi-enums-private.h" */
static const GEnumValue qmi_ctl_data_format_values[] = {
    { QMI_CTL_DATA_FORMAT_QOS_FLOW_HEADER_ABSENT, "QMI_CTL_DATA_FORMAT_QOS_FLOW_HEADER_ABSENT", "absent" },
    { QMI_CTL_DATA_FORMAT_QOS_FLOW_HEADER_PRESENT, "QMI_CTL_DATA_FORMAT_QOS_FLOW_HEADER_PRESENT", "present" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_ctl_data_format_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiCtlDataFormat"),
                                      qmi_ctl_data_format_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_CTL_DATA_FORMAT_IS_ENUM__
/**
 * qmi_ctl_data_format_get_string:
 * @val: a QmiCtlDataFormat.
 *
 * Gets the nickname string for the #QmiCtlDataFormat specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_ctl_data_format_get_string (QmiCtlDataFormat val)
{
    guint i;

    for (i = 0; qmi_ctl_data_format_values[i].value_nick; i++) {
        if (val == qmi_ctl_data_format_values[i].value)
            return qmi_ctl_data_format_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_CTL_DATA_FORMAT_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_CTL_DATA_FORMAT_IS_FLAGS__
/**
 * qmi_ctl_data_format_build_string_from_mask:
 * @mask: bitmask of QmiCtlDataFormat values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiCtlDataFormat in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_ctl_data_format_build_string_from_mask (QmiCtlDataFormat mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_ctl_data_format_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_ctl_data_format_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_ctl_data_format_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_ctl_data_format_values[i].value) {
            guint c;
            gulong number = qmi_ctl_data_format_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_ctl_data_format_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_CTL_DATA_FORMAT_IS_FLAGS__ */

static const GEnumValue qmi_ctl_data_link_protocol_values[] = {
    { QMI_CTL_DATA_LINK_PROTOCOL_UNKNOWN, "QMI_CTL_DATA_LINK_PROTOCOL_UNKNOWN", "unknown" },
    { QMI_CTL_DATA_LINK_PROTOCOL_802_3, "QMI_CTL_DATA_LINK_PROTOCOL_802_3", "802-3" },
    { QMI_CTL_DATA_LINK_PROTOCOL_RAW_IP, "QMI_CTL_DATA_LINK_PROTOCOL_RAW_IP", "raw-ip" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_ctl_data_link_protocol_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_enum_register_static (g_intern_static_string ("QmiCtlDataLinkProtocol"),
                                      qmi_ctl_data_link_protocol_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_CTL_DATA_LINK_PROTOCOL_IS_ENUM__
/**
 * qmi_ctl_data_link_protocol_get_string:
 * @val: a QmiCtlDataLinkProtocol.
 *
 * Gets the nickname string for the #QmiCtlDataLinkProtocol specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_ctl_data_link_protocol_get_string (QmiCtlDataLinkProtocol val)
{
    guint i;

    for (i = 0; qmi_ctl_data_link_protocol_values[i].value_nick; i++) {
        if (val == qmi_ctl_data_link_protocol_values[i].value)
            return qmi_ctl_data_link_protocol_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_CTL_DATA_LINK_PROTOCOL_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_CTL_DATA_LINK_PROTOCOL_IS_FLAGS__
/**
 * qmi_ctl_data_link_protocol_build_string_from_mask:
 * @mask: bitmask of QmiCtlDataLinkProtocol values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiCtlDataLinkProtocol in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_ctl_data_link_protocol_build_string_from_mask (QmiCtlDataLinkProtocol mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_ctl_data_link_protocol_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_ctl_data_link_protocol_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_ctl_data_link_protocol_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_ctl_data_link_protocol_values[i].value) {
            guint c;
            gulong number = qmi_ctl_data_link_protocol_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_ctl_data_link_protocol_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_CTL_DATA_LINK_PROTOCOL_IS_FLAGS__ */

static const GFlagsValue qmi_ctl_flag_values[] = {
    { QMI_CTL_FLAG_NONE, "QMI_CTL_FLAG_NONE", "none" },
    { QMI_CTL_FLAG_RESPONSE, "QMI_CTL_FLAG_RESPONSE", "response" },
    { QMI_CTL_FLAG_INDICATION, "QMI_CTL_FLAG_INDICATION", "indication" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_ctl_flag_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("QmiCtlFlag"),
                                      qmi_ctl_flag_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_CTL_FLAG_IS_ENUM__
/**
 * qmi_ctl_flag_get_string:
 * @val: a QmiCtlFlag.
 *
 * Gets the nickname string for the #QmiCtlFlag specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_ctl_flag_get_string (QmiCtlFlag val)
{
    guint i;

    for (i = 0; qmi_ctl_flag_values[i].value_nick; i++) {
        if (val == qmi_ctl_flag_values[i].value)
            return qmi_ctl_flag_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_CTL_FLAG_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_CTL_FLAG_IS_FLAGS__
/**
 * qmi_ctl_flag_build_string_from_mask:
 * @mask: bitmask of QmiCtlFlag values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiCtlFlag in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_ctl_flag_build_string_from_mask (QmiCtlFlag mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_ctl_flag_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_ctl_flag_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_ctl_flag_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_ctl_flag_values[i].value) {
            guint c;
            gulong number = qmi_ctl_flag_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_ctl_flag_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_CTL_FLAG_IS_FLAGS__ */

static const GFlagsValue qmi_service_flag_values[] = {
    { QMI_SERVICE_FLAG_NONE, "QMI_SERVICE_FLAG_NONE", "none" },
    { QMI_SERVICE_FLAG_COMPOUND, "QMI_SERVICE_FLAG_COMPOUND", "compound" },
    { QMI_SERVICE_FLAG_RESPONSE, "QMI_SERVICE_FLAG_RESPONSE", "response" },
    { QMI_SERVICE_FLAG_INDICATION, "QMI_SERVICE_FLAG_INDICATION", "indication" },
    { 0, NULL, NULL }
};

/* Define type-specific symbols */

GType
qmi_service_flag_get_type (void)
{
    static volatile gsize g_define_type_id__volatile = 0;

    if (g_once_init_enter (&g_define_type_id__volatile)) {
        GType g_define_type_id =
            g_flags_register_static (g_intern_static_string ("QmiServiceFlag"),
                                      qmi_service_flag_values);
        g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
    }

    return g_define_type_id__volatile;
}

/* Enum-specific method to get the value as a string.
 * We get the nick of the GEnumValue. Note that this will be
 * valid even if the GEnumClass is not referenced anywhere. */
#if defined __QMI_SERVICE_FLAG_IS_ENUM__
/**
 * qmi_service_flag_get_string:
 * @val: a QmiServiceFlag.
 *
 * Gets the nickname string for the #QmiServiceFlag specified at @val.
 *
 * Returns: (transfer none): a string with the nickname, or %NULL if not found. Do not free the returned value.
 */
const gchar *
qmi_service_flag_get_string (QmiServiceFlag val)
{
    guint i;

    for (i = 0; qmi_service_flag_values[i].value_nick; i++) {
        if (val == qmi_service_flag_values[i].value)
            return qmi_service_flag_values[i].value_nick;
    }

    return NULL;
}
#endif /* __QMI_SERVICE_FLAG_IS_ENUM__ */

/* Flags-specific method to build a string with the given mask.
 * We get a comma separated list of the nicks of the GFlagsValues.
 * Note that this will be valid even if the GFlagsClass is not referenced
 * anywhere. */
#if defined __QMI_SERVICE_FLAG_IS_FLAGS__
/**
 * qmi_service_flag_build_string_from_mask:
 * @mask: bitmask of QmiServiceFlag values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiServiceFlag in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_service_flag_build_string_from_mask (QmiServiceFlag mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_service_flag_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_service_flag_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_service_flag_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_service_flag_values[i].value) {
            guint c;
            gulong number = qmi_service_flag_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_service_flag_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}
#endif /* __QMI_SERVICE_FLAG_IS_FLAGS__ */


/* Generated data ends here */

