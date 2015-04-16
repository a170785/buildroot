
/* Generated data (by glib-mkenums) */

#include "qmi-flags64-types.h"

typedef struct {
  guint64 value;
  const gchar *value_name;
  const gchar *value_nick;
} GFlags64Value;

/* enumerations from "../../libqmi-glib/qmi-flags64-dms.h" */
static const GFlags64Value qmi_dms_band_capability_values[] = {
    { QMI_DMS_BAND_CAPABILITY_BC_0_A_SYSTEM, "QMI_DMS_BAND_CAPABILITY_BC_0_A_SYSTEM", "bc-0-a-system" },
    { QMI_DMS_BAND_CAPABILITY_BC_0_B_SYSTEM, "QMI_DMS_BAND_CAPABILITY_BC_0_B_SYSTEM", "bc-0-b-system" },
    { QMI_DMS_BAND_CAPABILITY_BC_1_ALL_BLOCKS, "QMI_DMS_BAND_CAPABILITY_BC_1_ALL_BLOCKS", "bc-1-all-blocks" },
    { QMI_DMS_BAND_CAPABILITY_BC_2, "QMI_DMS_BAND_CAPABILITY_BC_2", "bc-2" },
    { QMI_DMS_BAND_CAPABILITY_BC_3_A_SYSTEM, "QMI_DMS_BAND_CAPABILITY_BC_3_A_SYSTEM", "bc-3-a-system" },
    { QMI_DMS_BAND_CAPABILITY_BC_4_ALL_BLOCKS, "QMI_DMS_BAND_CAPABILITY_BC_4_ALL_BLOCKS", "bc-4-all-blocks" },
    { QMI_DMS_BAND_CAPABILITY_BC_5_ALL_BLOCKS, "QMI_DMS_BAND_CAPABILITY_BC_5_ALL_BLOCKS", "bc-5-all-blocks" },
    { QMI_DMS_BAND_CAPABILITY_GSM_DCS_1800, "QMI_DMS_BAND_CAPABILITY_GSM_DCS_1800", "gsm-dcs-1800" },
    { QMI_DMS_BAND_CAPABILITY_GSM_900_EXTENDED, "QMI_DMS_BAND_CAPABILITY_GSM_900_EXTENDED", "gsm-900-extended" },
    { QMI_DMS_BAND_CAPABILITY_GSM_900_PRIMARY, "QMI_DMS_BAND_CAPABILITY_GSM_900_PRIMARY", "gsm-900-primary" },
    { QMI_DMS_BAND_CAPABILITY_BC_6, "QMI_DMS_BAND_CAPABILITY_BC_6", "bc-6" },
    { QMI_DMS_BAND_CAPABILITY_BC_7, "QMI_DMS_BAND_CAPABILITY_BC_7", "bc-7" },
    { QMI_DMS_BAND_CAPABILITY_BC_8, "QMI_DMS_BAND_CAPABILITY_BC_8", "bc-8" },
    { QMI_DMS_BAND_CAPABILITY_BC_9, "QMI_DMS_BAND_CAPABILITY_BC_9", "bc-9" },
    { QMI_DMS_BAND_CAPABILITY_BC_10, "QMI_DMS_BAND_CAPABILITY_BC_10", "bc-10" },
    { QMI_DMS_BAND_CAPABILITY_BC_11, "QMI_DMS_BAND_CAPABILITY_BC_11", "bc-11" },
    { QMI_DMS_BAND_CAPABILITY_GSM_450, "QMI_DMS_BAND_CAPABILITY_GSM_450", "gsm-450" },
    { QMI_DMS_BAND_CAPABILITY_GSM_480, "QMI_DMS_BAND_CAPABILITY_GSM_480", "gsm-480" },
    { QMI_DMS_BAND_CAPABILITY_GSM_750, "QMI_DMS_BAND_CAPABILITY_GSM_750", "gsm-750" },
    { QMI_DMS_BAND_CAPABILITY_GSM_850, "QMI_DMS_BAND_CAPABILITY_GSM_850", "gsm-850" },
    { QMI_DMS_BAND_CAPABILITY_GSM_900_RAILWAYS, "QMI_DMS_BAND_CAPABILITY_GSM_900_RAILWAYS", "gsm-900-railways" },
    { QMI_DMS_BAND_CAPABILITY_GSM_PCS_1900, "QMI_DMS_BAND_CAPABILITY_GSM_PCS_1900", "gsm-pcs-1900" },
    { QMI_DMS_BAND_CAPABILITY_WCDMA_2100, "QMI_DMS_BAND_CAPABILITY_WCDMA_2100", "wcdma-2100" },
    { QMI_DMS_BAND_CAPABILITY_WCDMA_PCS_1900, "QMI_DMS_BAND_CAPABILITY_WCDMA_PCS_1900", "wcdma-pcs-1900" },
    { QMI_DMS_BAND_CAPABILITY_WCDMA_DCS_1800, "QMI_DMS_BAND_CAPABILITY_WCDMA_DCS_1800", "wcdma-dcs-1800" },
    { QMI_DMS_BAND_CAPABILITY_WCDMA_1700_US, "QMI_DMS_BAND_CAPABILITY_WCDMA_1700_US", "wcdma-1700-us" },
    { QMI_DMS_BAND_CAPABILITY_WCDMA_850_US, "QMI_DMS_BAND_CAPABILITY_WCDMA_850_US", "wcdma-850-us" },
    { QMI_DMS_BAND_CAPABILITY_WCDMA_800, "QMI_DMS_BAND_CAPABILITY_WCDMA_800", "wcdma-800" },
    { QMI_DMS_BAND_CAPABILITY_BC_12, "QMI_DMS_BAND_CAPABILITY_BC_12", "bc-12" },
    { QMI_DMS_BAND_CAPABILITY_BC_14, "QMI_DMS_BAND_CAPABILITY_BC_14", "bc-14" },
    { QMI_DMS_BAND_CAPABILITY_BC_15, "QMI_DMS_BAND_CAPABILITY_BC_15", "bc-15" },
    { QMI_DMS_BAND_CAPABILITY_WCDMA_2600, "QMI_DMS_BAND_CAPABILITY_WCDMA_2600", "wcdma-2600" },
    { QMI_DMS_BAND_CAPABILITY_WCDMA_900, "QMI_DMS_BAND_CAPABILITY_WCDMA_900", "wcdma-900" },
    { QMI_DMS_BAND_CAPABILITY_WCDMA_1700_JAPAN, "QMI_DMS_BAND_CAPABILITY_WCDMA_1700_JAPAN", "wcdma-1700-japan" },
    { QMI_DMS_BAND_CAPABILITY_BC_16, "QMI_DMS_BAND_CAPABILITY_BC_16", "bc-16" },
    { QMI_DMS_BAND_CAPABILITY_BC_17, "QMI_DMS_BAND_CAPABILITY_BC_17", "bc-17" },
    { QMI_DMS_BAND_CAPABILITY_BC_18, "QMI_DMS_BAND_CAPABILITY_BC_18", "bc-18" },
    { QMI_DMS_BAND_CAPABILITY_BC_19, "QMI_DMS_BAND_CAPABILITY_BC_19", "bc-19" },
    { QMI_DMS_BAND_CAPABILITY_WCDMA_850_JAPAN, "QMI_DMS_BAND_CAPABILITY_WCDMA_850_JAPAN", "wcdma-850-japan" },
    { QMI_DMS_BAND_CAPABILITY_WCDMA_1500, "QMI_DMS_BAND_CAPABILITY_WCDMA_1500", "wcdma-1500" },
    { 0, NULL, NULL }
};

/**
 * qmi_dms_band_capability_build_string_from_mask:
 * @mask: bitmask of QmiDmsBandCapability values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiDmsBandCapability in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_dms_band_capability_build_string_from_mask (QmiDmsBandCapability mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_dms_band_capability_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_dms_band_capability_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_dms_band_capability_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_dms_band_capability_values[i].value) {
            guint c;
            gulong number = qmi_dms_band_capability_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_dms_band_capability_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}

static const GFlags64Value qmi_dms_lte_band_capability_values[] = {
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_1, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_1", "1" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_2, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_2", "2" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_3, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_3", "3" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_4, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_4", "4" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_5, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_5", "5" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_6, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_6", "6" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_7, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_7", "7" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_8, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_8", "8" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_9, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_9", "9" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_10, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_10", "10" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_11, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_11", "11" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_12, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_12", "12" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_13, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_13", "13" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_14, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_14", "14" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_17, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_17", "17" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_18, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_18", "18" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_19, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_19", "19" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_20, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_20", "20" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_21, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_21", "21" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_24, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_24", "24" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_25, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_25", "25" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_33, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_33", "33" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_34, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_34", "34" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_35, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_35", "35" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_36, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_36", "36" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_37, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_37", "37" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_38, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_38", "38" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_39, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_39", "39" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_40, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_40", "40" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_41, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_41", "41" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_42, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_42", "42" },
    { QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_43, "QMI_DMS_LTE_BAND_CAPABILITY_EUTRAN_43", "43" },
    { 0, NULL, NULL }
};

/**
 * qmi_dms_lte_band_capability_build_string_from_mask:
 * @mask: bitmask of QmiDmsLteBandCapability values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiDmsLteBandCapability in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_dms_lte_band_capability_build_string_from_mask (QmiDmsLteBandCapability mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_dms_lte_band_capability_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_dms_lte_band_capability_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_dms_lte_band_capability_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_dms_lte_band_capability_values[i].value) {
            guint c;
            gulong number = qmi_dms_lte_band_capability_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_dms_lte_band_capability_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}

/* enumerations from "../../libqmi-glib/qmi-flags64-nas.h" */
static const GFlags64Value qmi_nas_band_preference_values[] = {
    { QMI_NAS_BAND_PREFERENCE_BC_0_A_SYSTEM, "QMI_NAS_BAND_PREFERENCE_BC_0_A_SYSTEM", "bc-0-a-system" },
    { QMI_NAS_BAND_PREFERENCE_BC_0_B_SYSTEM, "QMI_NAS_BAND_PREFERENCE_BC_0_B_SYSTEM", "bc-0-b-system" },
    { QMI_NAS_BAND_PREFERENCE_BC_1_ALL_BLOCKS, "QMI_NAS_BAND_PREFERENCE_BC_1_ALL_BLOCKS", "bc-1-all-blocks" },
    { QMI_NAS_BAND_PREFERENCE_BC_2, "QMI_NAS_BAND_PREFERENCE_BC_2", "bc-2" },
    { QMI_NAS_BAND_PREFERENCE_BC_3_A_SYSTEM, "QMI_NAS_BAND_PREFERENCE_BC_3_A_SYSTEM", "bc-3-a-system" },
    { QMI_NAS_BAND_PREFERENCE_BC_4_ALL_BLOCKS, "QMI_NAS_BAND_PREFERENCE_BC_4_ALL_BLOCKS", "bc-4-all-blocks" },
    { QMI_NAS_BAND_PREFERENCE_BC_5_ALL_BLOCKS, "QMI_NAS_BAND_PREFERENCE_BC_5_ALL_BLOCKS", "bc-5-all-blocks" },
    { QMI_NAS_BAND_PREFERENCE_GSM_DCS_1800, "QMI_NAS_BAND_PREFERENCE_GSM_DCS_1800", "gsm-dcs-1800" },
    { QMI_NAS_BAND_PREFERENCE_GSM_900_EXTENDED, "QMI_NAS_BAND_PREFERENCE_GSM_900_EXTENDED", "gsm-900-extended" },
    { QMI_NAS_BAND_PREFERENCE_GSM_900_PRIMARY, "QMI_NAS_BAND_PREFERENCE_GSM_900_PRIMARY", "gsm-900-primary" },
    { QMI_NAS_BAND_PREFERENCE_BC_6, "QMI_NAS_BAND_PREFERENCE_BC_6", "bc-6" },
    { QMI_NAS_BAND_PREFERENCE_BC_7, "QMI_NAS_BAND_PREFERENCE_BC_7", "bc-7" },
    { QMI_NAS_BAND_PREFERENCE_BC_8, "QMI_NAS_BAND_PREFERENCE_BC_8", "bc-8" },
    { QMI_NAS_BAND_PREFERENCE_BC_9, "QMI_NAS_BAND_PREFERENCE_BC_9", "bc-9" },
    { QMI_NAS_BAND_PREFERENCE_BC_10, "QMI_NAS_BAND_PREFERENCE_BC_10", "bc-10" },
    { QMI_NAS_BAND_PREFERENCE_BC_11, "QMI_NAS_BAND_PREFERENCE_BC_11", "bc-11" },
    { QMI_NAS_BAND_PREFERENCE_GSM_450, "QMI_NAS_BAND_PREFERENCE_GSM_450", "gsm-450" },
    { QMI_NAS_BAND_PREFERENCE_GSM_480, "QMI_NAS_BAND_PREFERENCE_GSM_480", "gsm-480" },
    { QMI_NAS_BAND_PREFERENCE_GSM_750, "QMI_NAS_BAND_PREFERENCE_GSM_750", "gsm-750" },
    { QMI_NAS_BAND_PREFERENCE_GSM_850, "QMI_NAS_BAND_PREFERENCE_GSM_850", "gsm-850" },
    { QMI_NAS_BAND_PREFERENCE_GSM_900_RAILWAYS, "QMI_NAS_BAND_PREFERENCE_GSM_900_RAILWAYS", "gsm-900-railways" },
    { QMI_NAS_BAND_PREFERENCE_GSM_PCS_1900, "QMI_NAS_BAND_PREFERENCE_GSM_PCS_1900", "gsm-pcs-1900" },
    { QMI_NAS_BAND_PREFERENCE_WCDMA_2100, "QMI_NAS_BAND_PREFERENCE_WCDMA_2100", "wcdma-2100" },
    { QMI_NAS_BAND_PREFERENCE_WCDMA_PCS_1900, "QMI_NAS_BAND_PREFERENCE_WCDMA_PCS_1900", "wcdma-pcs-1900" },
    { QMI_NAS_BAND_PREFERENCE_WCDMA_DCS_1800, "QMI_NAS_BAND_PREFERENCE_WCDMA_DCS_1800", "wcdma-dcs-1800" },
    { QMI_NAS_BAND_PREFERENCE_WCDMA_1700_US, "QMI_NAS_BAND_PREFERENCE_WCDMA_1700_US", "wcdma-1700-us" },
    { QMI_NAS_BAND_PREFERENCE_WCDMA_850_US, "QMI_NAS_BAND_PREFERENCE_WCDMA_850_US", "wcdma-850-us" },
    { QMI_NAS_BAND_PREFERENCE_WCDMA_800, "QMI_NAS_BAND_PREFERENCE_WCDMA_800", "wcdma-800" },
    { QMI_NAS_BAND_PREFERENCE_BC_12, "QMI_NAS_BAND_PREFERENCE_BC_12", "bc-12" },
    { QMI_NAS_BAND_PREFERENCE_BC_14, "QMI_NAS_BAND_PREFERENCE_BC_14", "bc-14" },
    { QMI_NAS_BAND_PREFERENCE_BC_15, "QMI_NAS_BAND_PREFERENCE_BC_15", "bc-15" },
    { QMI_NAS_BAND_PREFERENCE_WCDMA_2600, "QMI_NAS_BAND_PREFERENCE_WCDMA_2600", "wcdma-2600" },
    { QMI_NAS_BAND_PREFERENCE_WCDMA_900, "QMI_NAS_BAND_PREFERENCE_WCDMA_900", "wcdma-900" },
    { QMI_NAS_BAND_PREFERENCE_WCDMA_1700_JAPAN, "QMI_NAS_BAND_PREFERENCE_WCDMA_1700_JAPAN", "wcdma-1700-japan" },
    { QMI_NAS_BAND_PREFERENCE_BC_16, "QMI_NAS_BAND_PREFERENCE_BC_16", "bc-16" },
    { QMI_NAS_BAND_PREFERENCE_BC_17, "QMI_NAS_BAND_PREFERENCE_BC_17", "bc-17" },
    { QMI_NAS_BAND_PREFERENCE_BC_18, "QMI_NAS_BAND_PREFERENCE_BC_18", "bc-18" },
    { QMI_NAS_BAND_PREFERENCE_BC_19, "QMI_NAS_BAND_PREFERENCE_BC_19", "bc-19" },
    { 0, NULL, NULL }
};

/**
 * qmi_nas_band_preference_build_string_from_mask:
 * @mask: bitmask of QmiNasBandPreference values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasBandPreference in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_band_preference_build_string_from_mask (QmiNasBandPreference mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_band_preference_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_band_preference_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_band_preference_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_band_preference_values[i].value) {
            guint c;
            gulong number = qmi_nas_band_preference_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_band_preference_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}

static const GFlags64Value qmi_nas_lte_band_preference_values[] = {
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_1, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_1", "1" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_2, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_2", "2" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_3, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_3", "3" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_4, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_4", "4" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_5, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_5", "5" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_6, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_6", "6" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_7, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_7", "7" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_8, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_8", "8" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_9, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_9", "9" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_10, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_10", "10" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_11, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_11", "11" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_12, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_12", "12" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_13, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_13", "13" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_14, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_14", "14" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_17, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_17", "17" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_18, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_18", "18" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_19, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_19", "19" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_20, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_20", "20" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_21, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_21", "21" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_24, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_24", "24" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_25, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_25", "25" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_33, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_33", "33" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_34, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_34", "34" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_35, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_35", "35" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_36, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_36", "36" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_37, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_37", "37" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_38, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_38", "38" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_39, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_39", "39" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_40, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_40", "40" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_41, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_41", "41" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_42, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_42", "42" },
    { QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_43, "QMI_NAS_LTE_BAND_PREFERENCE_EUTRAN_43", "43" },
    { 0, NULL, NULL }
};

/**
 * qmi_nas_lte_band_preference_build_string_from_mask:
 * @mask: bitmask of QmiNasLteBandPreference values.
 *
 * Builds a string containing a comma-separated list of nicknames for
 * each #QmiNasLteBandPreference in @mask.
 *
 * Returns: (transfer full): a string with the list of nicknames, or %NULL if none given. The returned value should be freed with g_free().
 */
gchar *
qmi_nas_lte_band_preference_build_string_from_mask (QmiNasLteBandPreference mask)
{
    guint i;
    gboolean first = TRUE;
    GString *str = NULL;

    for (i = 0; qmi_nas_lte_band_preference_values[i].value_nick; i++) {
        /* We also look for exact matches */
        if (mask == qmi_nas_lte_band_preference_values[i].value) {
            if (str)
                g_string_free (str, TRUE);
            return g_strdup (qmi_nas_lte_band_preference_values[i].value_nick);
        }

        /* Build list with single-bit masks */
        if (mask & qmi_nas_lte_band_preference_values[i].value) {
            guint c;
            gulong number = qmi_nas_lte_band_preference_values[i].value;

            for (c = 0; number; c++)
                number &= number - 1;

            if (c == 1) {
                if (!str)
                    str = g_string_new ("");
                g_string_append_printf (str, "%s%s",
                                        first ? "" : ", ",
                                        qmi_nas_lte_band_preference_values[i].value_nick);
                if (first)
                    first = FALSE;
            }
        }
    }

    return (str ? g_string_free (str, FALSE) : NULL);
}


/* Generated data ends here */

