
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
 * Copyright (C) 2012-2017 Aleksander Morgado <aleksander@aleksander.es>
 */


#include <string.h>

#include "qmi-gas.h"
#include "qmi-enum-types.h"
#include "qmi-enum-types-private.h"
#include "qmi-flags64-types.h"
#include "qmi-error-types.h"
#include "qmi-device.h"
#include "qmi-helpers.h"

#define QMI_STATUS_SUCCESS 0x0000
#define QMI_STATUS_FAILURE 0x0001


typedef enum {
    QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE = 0x0206,
    QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST = 0x0208,
} QmiMessageGas;


/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message GAS DMS Set Active Firmware */


/* --- Input -- */

struct _QmiMessageGasDmsSetActiveFirmwareInput {
    volatile gint ref_count;

    /* Version */
    gboolean arg_version_set;
    gchar *arg_version;

    /* Slot Index */
    gboolean arg_slot_index_set;
    guint8 arg_slot_index;

    /* Carrier Name */
    gboolean arg_carrier_name_set;
    gchar *arg_carrier_name;
};

#define QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE_INPUT_TLV_VERSION 0x12
#define QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE_INPUT_TLV_SLOT_INDEX 0x11
#define QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE_INPUT_TLV_CARRIER_NAME 0x10

gboolean
qmi_message_gas_dms_set_active_firmware_input_get_version (
    QmiMessageGasDmsSetActiveFirmwareInput *self,
    const gchar **value_version,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_version_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Version' was not found in the message");
        return FALSE;
    }

    if (value_version)
        *value_version = self->arg_version;

    return TRUE;
}

gboolean
qmi_message_gas_dms_set_active_firmware_input_set_version (
    QmiMessageGasDmsSetActiveFirmwareInput *self,
    const gchar *value_version,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    g_free (self->arg_version);
    self->arg_version = g_strdup (value_version ? value_version : "");
    self->arg_version_set = TRUE;

    return TRUE;
}

gboolean
qmi_message_gas_dms_set_active_firmware_input_get_slot_index (
    QmiMessageGasDmsSetActiveFirmwareInput *self,
    guint8 *value_slot_index,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_slot_index_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Slot Index' was not found in the message");
        return FALSE;
    }

    if (value_slot_index)
        *value_slot_index = self->arg_slot_index;

    return TRUE;
}

gboolean
qmi_message_gas_dms_set_active_firmware_input_set_slot_index (
    QmiMessageGasDmsSetActiveFirmwareInput *self,
    guint8 value_slot_index,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_slot_index = value_slot_index;
    self->arg_slot_index_set = TRUE;

    return TRUE;
}

gboolean
qmi_message_gas_dms_set_active_firmware_input_get_carrier_name (
    QmiMessageGasDmsSetActiveFirmwareInput *self,
    const gchar **value_carrier_name,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_carrier_name_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Carrier Name' was not found in the message");
        return FALSE;
    }

    if (value_carrier_name)
        *value_carrier_name = self->arg_carrier_name;

    return TRUE;
}

gboolean
qmi_message_gas_dms_set_active_firmware_input_set_carrier_name (
    QmiMessageGasDmsSetActiveFirmwareInput *self,
    const gchar *value_carrier_name,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    g_free (self->arg_carrier_name);
    self->arg_carrier_name = g_strdup (value_carrier_name ? value_carrier_name : "");
    self->arg_carrier_name_set = TRUE;

    return TRUE;
}

GType
qmi_message_gas_dms_set_active_firmware_input_get_type (void)
{
    static gsize g_define_type_id_initialized = 0;

    if (g_once_init_enter (&g_define_type_id_initialized)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageGasDmsSetActiveFirmwareInput"),
                                          (GBoxedCopyFunc) qmi_message_gas_dms_set_active_firmware_input_ref,
                                          (GBoxedFreeFunc) qmi_message_gas_dms_set_active_firmware_input_unref);

        g_once_init_leave (&g_define_type_id_initialized, g_define_type_id);
    }

    return g_define_type_id_initialized;
}

QmiMessageGasDmsSetActiveFirmwareInput *
qmi_message_gas_dms_set_active_firmware_input_ref (QmiMessageGasDmsSetActiveFirmwareInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

void
qmi_message_gas_dms_set_active_firmware_input_unref (QmiMessageGasDmsSetActiveFirmwareInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_free (self->arg_version);
        g_free (self->arg_carrier_name);
        g_slice_free (QmiMessageGasDmsSetActiveFirmwareInput, self);
    }
}

QmiMessageGasDmsSetActiveFirmwareInput *
qmi_message_gas_dms_set_active_firmware_input_new (void)
{
    QmiMessageGasDmsSetActiveFirmwareInput *self;

    self = g_slice_new0 (QmiMessageGasDmsSetActiveFirmwareInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_gas_dms_set_active_firmware_request_create (
    guint16 transaction_id,
    guint8 cid,
    QmiMessageGasDmsSetActiveFirmwareInput *input,
    GError **error)
{
    g_autoptr(QmiMessage) self = NULL;

    self = qmi_message_new (QMI_SERVICE_GAS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE);

    /* All TLVs are optional, we allow NULL input */
    if (!input)
        return g_steal_pointer (&self);

    /* Try to add the 'Version' TLV */
    if (input->arg_version_set) {
        gsize tlv_offset;

        if (!(tlv_offset = qmi_message_tlv_write_init (self, (guint8)QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE_INPUT_TLV_VERSION, error))) {
            g_prefix_error (error, "Cannot initialize TLV 'Version': ");
            return NULL;
        }

        if (!qmi_message_tlv_write_string (self, 0, input->arg_version, -1, error)) {
            g_prefix_error (error, "Cannot write string in TLV 'Version': ");
            return NULL;
        }

        if (!qmi_message_tlv_write_complete (self, tlv_offset, error)) {
            g_prefix_error (error, "Cannot complete TLV 'Version': ");
            return NULL;
        }
    }

    /* Try to add the 'Slot Index' TLV */
    if (input->arg_slot_index_set) {
        gsize tlv_offset;

        if (!(tlv_offset = qmi_message_tlv_write_init (self, (guint8)QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE_INPUT_TLV_SLOT_INDEX, error))) {
            g_prefix_error (error, "Cannot initialize TLV 'Slot Index': ");
            return NULL;
        }

        /* Write the guint8 variable to the buffer */
        if (!qmi_message_tlv_write_guint8 (self, input->arg_slot_index, error)) {
            g_prefix_error (error, "Cannot write integer in TLV 'Slot Index': ");
            return NULL;
        }

        if (!qmi_message_tlv_write_complete (self, tlv_offset, error)) {
            g_prefix_error (error, "Cannot complete TLV 'Slot Index': ");
            return NULL;
        }
    }

    /* Try to add the 'Carrier Name' TLV */
    if (input->arg_carrier_name_set) {
        gsize tlv_offset;

        if (!(tlv_offset = qmi_message_tlv_write_init (self, (guint8)QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE_INPUT_TLV_CARRIER_NAME, error))) {
            g_prefix_error (error, "Cannot initialize TLV 'Carrier Name': ");
            return NULL;
        }

        if (!qmi_message_tlv_write_string (self, 0, input->arg_carrier_name, -1, error)) {
            g_prefix_error (error, "Cannot write string in TLV 'Carrier Name': ");
            return NULL;
        }

        if (!qmi_message_tlv_write_complete (self, tlv_offset, error)) {
            g_prefix_error (error, "Cannot complete TLV 'Carrier Name': ");
            return NULL;
        }
    }

    return g_steal_pointer (&self);
}

/* --- Output -- */

typedef struct _QmiMessageResult {
    guint16 error_status;
    guint16 error_code;
} QmiMessageResult;

struct _QmiMessageGasDmsSetActiveFirmwareOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;
};

#define QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE_OUTPUT_TLV_RESULT 0x02

gboolean
qmi_message_gas_dms_set_active_firmware_output_get_result (
    QmiMessageGasDmsSetActiveFirmwareOutput *self,
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
qmi_message_gas_dms_set_active_firmware_output_get_type (void)
{
    static gsize g_define_type_id_initialized = 0;

    if (g_once_init_enter (&g_define_type_id_initialized)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageGasDmsSetActiveFirmwareOutput"),
                                          (GBoxedCopyFunc) qmi_message_gas_dms_set_active_firmware_output_ref,
                                          (GBoxedFreeFunc) qmi_message_gas_dms_set_active_firmware_output_unref);

        g_once_init_leave (&g_define_type_id_initialized, g_define_type_id);
    }

    return g_define_type_id_initialized;
}

QmiMessageGasDmsSetActiveFirmwareOutput *
qmi_message_gas_dms_set_active_firmware_output_ref (QmiMessageGasDmsSetActiveFirmwareOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

void
qmi_message_gas_dms_set_active_firmware_output_unref (QmiMessageGasDmsSetActiveFirmwareOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageGasDmsSetActiveFirmwareOutput, self);
    }
}

static gchar *
qmi_message_gas_dms_set_active_firmware_input_version_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE_INPUT_TLV_VERSION, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");

    {
        g_autofree gchar *tmp = NULL;

        if (!qmi_message_tlv_read_string (message, init_offset, &offset, 0, 0, &tmp, &error))
            goto out;
        g_string_append (printable, tmp);
    }

    if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0)
        g_string_append_printf (printable, "Additional unexpected '%" G_GSIZE_FORMAT "' bytes", offset);

out:
    if (error) {
        g_string_append_printf (printable, " ERROR: %s", error->message);
        g_error_free (error);
    }
    return g_string_free (printable, FALSE);
}

static gchar *
qmi_message_gas_dms_set_active_firmware_input_slot_index_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE_INPUT_TLV_SLOT_INDEX, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
    }

    if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0)
        g_string_append_printf (printable, "Additional unexpected '%" G_GSIZE_FORMAT "' bytes", offset);

out:
    if (error) {
        g_string_append_printf (printable, " ERROR: %s", error->message);
        g_error_free (error);
    }
    return g_string_free (printable, FALSE);
}

static gchar *
qmi_message_gas_dms_set_active_firmware_input_carrier_name_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE_INPUT_TLV_CARRIER_NAME, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");

    {
        g_autofree gchar *tmp = NULL;

        if (!qmi_message_tlv_read_string (message, init_offset, &offset, 0, 0, &tmp, &error))
            goto out;
        g_string_append (printable, tmp);
    }

    if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0)
        g_string_append_printf (printable, "Additional unexpected '%" G_GSIZE_FORMAT "' bytes", offset);

out:
    if (error) {
        g_string_append_printf (printable, " ERROR: %s", error->message);
        g_error_free (error);
    }
    return g_string_free (printable, FALSE);
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
    gsize offset = 0;
    gsize init_offset;
    guint16 error_status;
    guint16 error_code;

    if ((init_offset = qmi_message_tlv_read_init (self, QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE_OUTPUT_TLV_RESULT, NULL, NULL)) == 0)
        return NULL;
    if (!qmi_message_tlv_read_guint16 (self, init_offset, &offset, QMI_ENDIAN_LITTLE, &error_status, NULL))
        return NULL;
    if (!qmi_message_tlv_read_guint16 (self, init_offset, &offset, QMI_ENDIAN_LITTLE, &error_code, NULL))
        return NULL;
    g_warn_if_fail (qmi_message_tlv_read_remaining_size (self, init_offset, offset) == 0);

    if (error_status == QMI_STATUS_SUCCESS)
        return g_strdup ("SUCCESS");

    return g_strdup_printf ("FAILURE: %s", qmi_protocol_error_get_string ((QmiProtocolError) error_code));
}

struct message_dms_set_active_firmware_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_dms_set_active_firmware_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_dms_set_active_firmware_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    g_autofree gchar *translated_value = NULL;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE_INPUT_TLV_VERSION:
            tlv_type_str = "Version";
            translated_value = qmi_message_gas_dms_set_active_firmware_input_version_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE_INPUT_TLV_SLOT_INDEX:
            tlv_type_str = "Slot Index";
            translated_value = qmi_message_gas_dms_set_active_firmware_input_slot_index_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE_INPUT_TLV_CARRIER_NAME:
            tlv_type_str = "Carrier Name";
            translated_value = qmi_message_gas_dms_set_active_firmware_input_carrier_name_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE_OUTPUT_TLV_RESULT:
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
        g_autofree gchar *value_str = NULL;

        value_str = qmi_message_get_tlv_printable (ctx->self,
                                                   ctx->line_prefix,
                                                   type,
                                                   value,
                                                   length);
        g_string_append (ctx->printable, value_str);
    } else {
        g_autofree gchar *value_hex = NULL;

        value_hex = qmi_helpers_str_hex (value, length, ':');
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
    }
}

static gchar *
message_dms_set_active_firmware_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"DMS Set Active Firmware\" (0x0206)\n",
                            line_prefix);

    {
        struct message_dms_set_active_firmware_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_dms_set_active_firmware_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageGasDmsSetActiveFirmwareOutput *
__qmi_message_gas_dms_set_active_firmware_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageGasDmsSetActiveFirmwareOutput *self;

    g_assert_cmphex (qmi_message_get_message_id (message), ==, QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE);

    self = g_slice_new0 (QmiMessageGasDmsSetActiveFirmwareOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            gsize offset = 0;
            gsize init_offset;

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE_OUTPUT_TLV_RESULT, NULL, error)) == 0) {
                g_prefix_error (error, "Couldn't get the mandatory Result TLV: ");
                qmi_message_gas_dms_set_active_firmware_output_unref (self);
                return NULL;
            }
            if (!qmi_message_tlv_read_guint16 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &(self->arg_result.error_status), error))
                goto qmi_message_result_out;
            if (!qmi_message_tlv_read_guint16 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &(self->arg_result.error_code), error))
                goto qmi_message_result_out;

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Result' TLV", offset);
            }

            self->arg_result_set = TRUE;

qmi_message_result_out:
            if (!self->arg_result_set) {
                qmi_message_gas_dms_set_active_firmware_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message GAS DMS Get Firmware List */


/* --- Input -- */

struct _QmiMessageGasDmsGetFirmwareListInput {
    volatile gint ref_count;

    /* Version */
    gboolean arg_version_set;
    gchar *arg_version;

    /* Name */
    gboolean arg_name_set;
    gchar *arg_name;

    /* Slot Index */
    gboolean arg_slot_index_set;
    guint8 arg_slot_index;

    /* Mode */
    gboolean arg_mode_set;
    guint8 arg_mode;
};

#define QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_INPUT_TLV_VERSION 0x12
#define QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_INPUT_TLV_NAME 0x11
#define QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_INPUT_TLV_SLOT_INDEX 0x10
#define QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_INPUT_TLV_MODE 0x01

gboolean
qmi_message_gas_dms_get_firmware_list_input_get_version (
    QmiMessageGasDmsGetFirmwareListInput *self,
    const gchar **value_version,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_version_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Version' was not found in the message");
        return FALSE;
    }

    if (value_version)
        *value_version = self->arg_version;

    return TRUE;
}

gboolean
qmi_message_gas_dms_get_firmware_list_input_set_version (
    QmiMessageGasDmsGetFirmwareListInput *self,
    const gchar *value_version,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    g_free (self->arg_version);
    self->arg_version = g_strdup (value_version ? value_version : "");
    self->arg_version_set = TRUE;

    return TRUE;
}

gboolean
qmi_message_gas_dms_get_firmware_list_input_get_name (
    QmiMessageGasDmsGetFirmwareListInput *self,
    const gchar **value_name,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_name_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Name' was not found in the message");
        return FALSE;
    }

    if (value_name)
        *value_name = self->arg_name;

    return TRUE;
}

gboolean
qmi_message_gas_dms_get_firmware_list_input_set_name (
    QmiMessageGasDmsGetFirmwareListInput *self,
    const gchar *value_name,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    g_free (self->arg_name);
    self->arg_name = g_strdup (value_name ? value_name : "");
    self->arg_name_set = TRUE;

    return TRUE;
}

gboolean
qmi_message_gas_dms_get_firmware_list_input_get_slot_index (
    QmiMessageGasDmsGetFirmwareListInput *self,
    guint8 *value_slot_index,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_slot_index_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Slot Index' was not found in the message");
        return FALSE;
    }

    if (value_slot_index)
        *value_slot_index = self->arg_slot_index;

    return TRUE;
}

gboolean
qmi_message_gas_dms_get_firmware_list_input_set_slot_index (
    QmiMessageGasDmsGetFirmwareListInput *self,
    guint8 value_slot_index,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_slot_index = value_slot_index;
    self->arg_slot_index_set = TRUE;

    return TRUE;
}

gboolean
qmi_message_gas_dms_get_firmware_list_input_get_mode (
    QmiMessageGasDmsGetFirmwareListInput *self,
    QmiGasFirmwareListingMode *value_mode,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_mode_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Mode' was not found in the message");
        return FALSE;
    }

    if (value_mode)
        *value_mode = (QmiGasFirmwareListingMode)(self->arg_mode);

    return TRUE;
}

gboolean
qmi_message_gas_dms_get_firmware_list_input_set_mode (
    QmiMessageGasDmsGetFirmwareListInput *self,
    QmiGasFirmwareListingMode value_mode,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_mode = (guint8)(value_mode);
    self->arg_mode_set = TRUE;

    return TRUE;
}

GType
qmi_message_gas_dms_get_firmware_list_input_get_type (void)
{
    static gsize g_define_type_id_initialized = 0;

    if (g_once_init_enter (&g_define_type_id_initialized)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageGasDmsGetFirmwareListInput"),
                                          (GBoxedCopyFunc) qmi_message_gas_dms_get_firmware_list_input_ref,
                                          (GBoxedFreeFunc) qmi_message_gas_dms_get_firmware_list_input_unref);

        g_once_init_leave (&g_define_type_id_initialized, g_define_type_id);
    }

    return g_define_type_id_initialized;
}

QmiMessageGasDmsGetFirmwareListInput *
qmi_message_gas_dms_get_firmware_list_input_ref (QmiMessageGasDmsGetFirmwareListInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

void
qmi_message_gas_dms_get_firmware_list_input_unref (QmiMessageGasDmsGetFirmwareListInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_free (self->arg_version);
        g_free (self->arg_name);
        g_slice_free (QmiMessageGasDmsGetFirmwareListInput, self);
    }
}

QmiMessageGasDmsGetFirmwareListInput *
qmi_message_gas_dms_get_firmware_list_input_new (void)
{
    QmiMessageGasDmsGetFirmwareListInput *self;

    self = g_slice_new0 (QmiMessageGasDmsGetFirmwareListInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_gas_dms_get_firmware_list_request_create (
    guint16 transaction_id,
    guint8 cid,
    QmiMessageGasDmsGetFirmwareListInput *input,
    GError **error)
{
    g_autoptr(QmiMessage) self = NULL;

    self = qmi_message_new (QMI_SERVICE_GAS,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'DMS Get Firmware List' has mandatory TLVs");
        return NULL;
    }

    /* Try to add the 'Version' TLV */
    if (input->arg_version_set) {
        gsize tlv_offset;

        if (!(tlv_offset = qmi_message_tlv_write_init (self, (guint8)QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_INPUT_TLV_VERSION, error))) {
            g_prefix_error (error, "Cannot initialize TLV 'Version': ");
            return NULL;
        }

        if (!qmi_message_tlv_write_string (self, 0, input->arg_version, -1, error)) {
            g_prefix_error (error, "Cannot write string in TLV 'Version': ");
            return NULL;
        }

        if (!qmi_message_tlv_write_complete (self, tlv_offset, error)) {
            g_prefix_error (error, "Cannot complete TLV 'Version': ");
            return NULL;
        }
    }

    /* Try to add the 'Name' TLV */
    if (input->arg_name_set) {
        gsize tlv_offset;

        if (!(tlv_offset = qmi_message_tlv_write_init (self, (guint8)QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_INPUT_TLV_NAME, error))) {
            g_prefix_error (error, "Cannot initialize TLV 'Name': ");
            return NULL;
        }

        if (!qmi_message_tlv_write_string (self, 0, input->arg_name, -1, error)) {
            g_prefix_error (error, "Cannot write string in TLV 'Name': ");
            return NULL;
        }

        if (!qmi_message_tlv_write_complete (self, tlv_offset, error)) {
            g_prefix_error (error, "Cannot complete TLV 'Name': ");
            return NULL;
        }
    }

    /* Try to add the 'Slot Index' TLV */
    if (input->arg_slot_index_set) {
        gsize tlv_offset;

        if (!(tlv_offset = qmi_message_tlv_write_init (self, (guint8)QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_INPUT_TLV_SLOT_INDEX, error))) {
            g_prefix_error (error, "Cannot initialize TLV 'Slot Index': ");
            return NULL;
        }

        /* Write the guint8 variable to the buffer */
        if (!qmi_message_tlv_write_guint8 (self, input->arg_slot_index, error)) {
            g_prefix_error (error, "Cannot write integer in TLV 'Slot Index': ");
            return NULL;
        }

        if (!qmi_message_tlv_write_complete (self, tlv_offset, error)) {
            g_prefix_error (error, "Cannot complete TLV 'Slot Index': ");
            return NULL;
        }
    }

    /* Try to add the 'Mode' TLV */
    if (input->arg_mode_set) {
        gsize tlv_offset;

        if (!(tlv_offset = qmi_message_tlv_write_init (self, (guint8)QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_INPUT_TLV_MODE, error))) {
            g_prefix_error (error, "Cannot initialize TLV 'Mode': ");
            return NULL;
        }

        {
            guint8 tmp;

            tmp = (guint8) input->arg_mode;
            /* Write the guint8 variable to the buffer */
            if (!qmi_message_tlv_write_guint8 (self, tmp, error)) {
                g_prefix_error (error, "Cannot write enum in TLV 'Mode': ");
                return NULL;
            }
        }

        if (!qmi_message_tlv_write_complete (self, tlv_offset, error)) {
            g_prefix_error (error, "Cannot complete TLV 'Mode': ");
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'Mode' in message 'DMS Get Firmware List'");
        return NULL;
    }

    return g_steal_pointer (&self);
}

/* --- Output -- */

struct _QmiMessageGasDmsGetFirmwareListOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Mode */
    gboolean arg_mode_set;
    guint8 arg_mode;

    /* Stored Firmware 1 */
    gboolean arg_stored_firmware_1_set;
    guint8 arg_stored_firmware_1_index;
    gchar *arg_stored_firmware_1_name;
    gchar *arg_stored_firmware_1_version;
    gchar *arg_stored_firmware_1_pri_revision;

    /* Stored Firmware 2 */
    gboolean arg_stored_firmware_2_set;
    guint8 arg_stored_firmware_2_index;
    gchar *arg_stored_firmware_2_name;
    gchar *arg_stored_firmware_2_version;
    gchar *arg_stored_firmware_2_pri_revision;

    /* Stored Firmware 3 */
    gboolean arg_stored_firmware_3_set;
    guint8 arg_stored_firmware_3_index;
    gchar *arg_stored_firmware_3_name;
    gchar *arg_stored_firmware_3_version;
    gchar *arg_stored_firmware_3_pri_revision;

    /* Stored Firmware 4 */
    gboolean arg_stored_firmware_4_set;
    guint8 arg_stored_firmware_4_index;
    gchar *arg_stored_firmware_4_name;
    gchar *arg_stored_firmware_4_version;
    gchar *arg_stored_firmware_4_pri_revision;
};

#define QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_MODE 0x01
#define QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_STORED_FIRMWARE_1 0x10
#define QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_STORED_FIRMWARE_2 0x11
#define QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_STORED_FIRMWARE_3 0x12
#define QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_STORED_FIRMWARE_4 0x13

gboolean
qmi_message_gas_dms_get_firmware_list_output_get_result (
    QmiMessageGasDmsGetFirmwareListOutput *self,
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

gboolean
qmi_message_gas_dms_get_firmware_list_output_get_mode (
    QmiMessageGasDmsGetFirmwareListOutput *self,
    QmiGasFirmwareListingMode *value_mode,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_mode_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Mode' was not found in the message");
        return FALSE;
    }

    if (value_mode)
        *value_mode = (QmiGasFirmwareListingMode)(self->arg_mode);

    return TRUE;
}

gboolean
qmi_message_gas_dms_get_firmware_list_output_get_stored_firmware_1 (
    QmiMessageGasDmsGetFirmwareListOutput *self,
    guint8 *value_stored_firmware_1_index,
    const gchar **value_stored_firmware_1_name,
    const gchar **value_stored_firmware_1_version,
    const gchar **value_stored_firmware_1_pri_revision,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_stored_firmware_1_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Stored Firmware 1' was not found in the message");
        return FALSE;
    }

    if (value_stored_firmware_1_index)
        *value_stored_firmware_1_index = self->arg_stored_firmware_1_index;
    if (value_stored_firmware_1_name)
        *value_stored_firmware_1_name = self->arg_stored_firmware_1_name;
    if (value_stored_firmware_1_version)
        *value_stored_firmware_1_version = self->arg_stored_firmware_1_version;
    if (value_stored_firmware_1_pri_revision)
        *value_stored_firmware_1_pri_revision = self->arg_stored_firmware_1_pri_revision;

    return TRUE;
}

gboolean
qmi_message_gas_dms_get_firmware_list_output_get_stored_firmware_2 (
    QmiMessageGasDmsGetFirmwareListOutput *self,
    guint8 *value_stored_firmware_2_index,
    const gchar **value_stored_firmware_2_name,
    const gchar **value_stored_firmware_2_version,
    const gchar **value_stored_firmware_2_pri_revision,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_stored_firmware_2_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Stored Firmware 2' was not found in the message");
        return FALSE;
    }

    if (value_stored_firmware_2_index)
        *value_stored_firmware_2_index = self->arg_stored_firmware_2_index;
    if (value_stored_firmware_2_name)
        *value_stored_firmware_2_name = self->arg_stored_firmware_2_name;
    if (value_stored_firmware_2_version)
        *value_stored_firmware_2_version = self->arg_stored_firmware_2_version;
    if (value_stored_firmware_2_pri_revision)
        *value_stored_firmware_2_pri_revision = self->arg_stored_firmware_2_pri_revision;

    return TRUE;
}

gboolean
qmi_message_gas_dms_get_firmware_list_output_get_stored_firmware_3 (
    QmiMessageGasDmsGetFirmwareListOutput *self,
    guint8 *value_stored_firmware_3_index,
    const gchar **value_stored_firmware_3_name,
    const gchar **value_stored_firmware_3_version,
    const gchar **value_stored_firmware_3_pri_revision,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_stored_firmware_3_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Stored Firmware 3' was not found in the message");
        return FALSE;
    }

    if (value_stored_firmware_3_index)
        *value_stored_firmware_3_index = self->arg_stored_firmware_3_index;
    if (value_stored_firmware_3_name)
        *value_stored_firmware_3_name = self->arg_stored_firmware_3_name;
    if (value_stored_firmware_3_version)
        *value_stored_firmware_3_version = self->arg_stored_firmware_3_version;
    if (value_stored_firmware_3_pri_revision)
        *value_stored_firmware_3_pri_revision = self->arg_stored_firmware_3_pri_revision;

    return TRUE;
}

gboolean
qmi_message_gas_dms_get_firmware_list_output_get_stored_firmware_4 (
    QmiMessageGasDmsGetFirmwareListOutput *self,
    guint8 *value_stored_firmware_4_index,
    const gchar **value_stored_firmware_4_name,
    const gchar **value_stored_firmware_4_version,
    const gchar **value_stored_firmware_4_pri_revision,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_stored_firmware_4_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Stored Firmware 4' was not found in the message");
        return FALSE;
    }

    if (value_stored_firmware_4_index)
        *value_stored_firmware_4_index = self->arg_stored_firmware_4_index;
    if (value_stored_firmware_4_name)
        *value_stored_firmware_4_name = self->arg_stored_firmware_4_name;
    if (value_stored_firmware_4_version)
        *value_stored_firmware_4_version = self->arg_stored_firmware_4_version;
    if (value_stored_firmware_4_pri_revision)
        *value_stored_firmware_4_pri_revision = self->arg_stored_firmware_4_pri_revision;

    return TRUE;
}

GType
qmi_message_gas_dms_get_firmware_list_output_get_type (void)
{
    static gsize g_define_type_id_initialized = 0;

    if (g_once_init_enter (&g_define_type_id_initialized)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageGasDmsGetFirmwareListOutput"),
                                          (GBoxedCopyFunc) qmi_message_gas_dms_get_firmware_list_output_ref,
                                          (GBoxedFreeFunc) qmi_message_gas_dms_get_firmware_list_output_unref);

        g_once_init_leave (&g_define_type_id_initialized, g_define_type_id);
    }

    return g_define_type_id_initialized;
}

QmiMessageGasDmsGetFirmwareListOutput *
qmi_message_gas_dms_get_firmware_list_output_ref (QmiMessageGasDmsGetFirmwareListOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

void
qmi_message_gas_dms_get_firmware_list_output_unref (QmiMessageGasDmsGetFirmwareListOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_free (self->arg_stored_firmware_1_name);
        g_free (self->arg_stored_firmware_1_version);
        g_free (self->arg_stored_firmware_1_pri_revision);
        g_free (self->arg_stored_firmware_2_name);
        g_free (self->arg_stored_firmware_2_version);
        g_free (self->arg_stored_firmware_2_pri_revision);
        g_free (self->arg_stored_firmware_3_name);
        g_free (self->arg_stored_firmware_3_version);
        g_free (self->arg_stored_firmware_3_pri_revision);
        g_free (self->arg_stored_firmware_4_name);
        g_free (self->arg_stored_firmware_4_version);
        g_free (self->arg_stored_firmware_4_pri_revision);
        g_slice_free (QmiMessageGasDmsGetFirmwareListOutput, self);
    }
}

static gchar *
qmi_message_gas_dms_get_firmware_list_input_version_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_INPUT_TLV_VERSION, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");

    {
        g_autofree gchar *tmp = NULL;

        if (!qmi_message_tlv_read_string (message, init_offset, &offset, 0, 0, &tmp, &error))
            goto out;
        g_string_append (printable, tmp);
    }

    if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0)
        g_string_append_printf (printable, "Additional unexpected '%" G_GSIZE_FORMAT "' bytes", offset);

out:
    if (error) {
        g_string_append_printf (printable, " ERROR: %s", error->message);
        g_error_free (error);
    }
    return g_string_free (printable, FALSE);
}

static gchar *
qmi_message_gas_dms_get_firmware_list_input_name_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_INPUT_TLV_NAME, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");

    {
        g_autofree gchar *tmp = NULL;

        if (!qmi_message_tlv_read_string (message, init_offset, &offset, 0, 0, &tmp, &error))
            goto out;
        g_string_append (printable, tmp);
    }

    if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0)
        g_string_append_printf (printable, "Additional unexpected '%" G_GSIZE_FORMAT "' bytes", offset);

out:
    if (error) {
        g_string_append_printf (printable, " ERROR: %s", error->message);
        g_error_free (error);
    }
    return g_string_free (printable, FALSE);
}

static gchar *
qmi_message_gas_dms_get_firmware_list_input_slot_index_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_INPUT_TLV_SLOT_INDEX, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
    }

    if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0)
        g_string_append_printf (printable, "Additional unexpected '%" G_GSIZE_FORMAT "' bytes", offset);

out:
    if (error) {
        g_string_append_printf (printable, " ERROR: %s", error->message);
        g_error_free (error);
    }
    return g_string_free (printable, FALSE);
}

static gchar *
qmi_message_gas_dms_get_firmware_list_input_mode_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_INPUT_TLV_MODE, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
#if defined  __QMI_GAS_FIRMWARE_LISTING_MODE_IS_ENUM__
        g_string_append_printf (printable, "%s", qmi_gas_firmware_listing_mode_get_string ((QmiGasFirmwareListingMode)tmp));
#elif defined  __QMI_GAS_FIRMWARE_LISTING_MODE_IS_FLAGS__
        {
            g_autofree gchar *flags_str = NULL;

            flags_str = qmi_gas_firmware_listing_mode_build_string_from_mask ((QmiGasFirmwareListingMode)tmp);
            g_string_append_printf (printable, "%s", flags_str);
        }
#else
# error unexpected public format: QmiGasFirmwareListingMode
#endif
    }

    if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0)
        g_string_append_printf (printable, "Additional unexpected '%" G_GSIZE_FORMAT "' bytes", offset);

out:
    if (error) {
        g_string_append_printf (printable, " ERROR: %s", error->message);
        g_error_free (error);
    }
    return g_string_free (printable, FALSE);
}

static gchar *
qmi_message_gas_dms_get_firmware_list_output_mode_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_MODE, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
#if defined  __QMI_GAS_FIRMWARE_LISTING_MODE_IS_ENUM__
        g_string_append_printf (printable, "%s", qmi_gas_firmware_listing_mode_get_string ((QmiGasFirmwareListingMode)tmp));
#elif defined  __QMI_GAS_FIRMWARE_LISTING_MODE_IS_FLAGS__
        {
            g_autofree gchar *flags_str = NULL;

            flags_str = qmi_gas_firmware_listing_mode_build_string_from_mask ((QmiGasFirmwareListingMode)tmp);
            g_string_append_printf (printable, "%s", flags_str);
        }
#else
# error unexpected public format: QmiGasFirmwareListingMode
#endif
    }

    if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0)
        g_string_append_printf (printable, "Additional unexpected '%" G_GSIZE_FORMAT "' bytes", offset);

out:
    if (error) {
        g_string_append_printf (printable, " ERROR: %s", error->message);
        g_error_free (error);
    }
    return g_string_free (printable, FALSE);
}

static gchar *
qmi_message_gas_dms_get_firmware_list_output_stored_firmware_1_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_STORED_FIRMWARE_1, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    g_string_append (printable, "[");
    g_string_append (printable, " index = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " name = '");

    {
        g_autofree gchar *tmp = NULL;

        if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &tmp, &error))
            goto out;
        g_string_append (printable, tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " version = '");

    {
        g_autofree gchar *tmp = NULL;

        if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &tmp, &error))
            goto out;
        g_string_append (printable, tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " pri_revision = '");

    {
        g_autofree gchar *tmp = NULL;

        if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &tmp, &error))
            goto out;
        g_string_append (printable, tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " ]");

    if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0)
        g_string_append_printf (printable, "Additional unexpected '%" G_GSIZE_FORMAT "' bytes", offset);

out:
    if (error) {
        g_string_append_printf (printable, " ERROR: %s", error->message);
        g_error_free (error);
    }
    return g_string_free (printable, FALSE);
}

static gchar *
qmi_message_gas_dms_get_firmware_list_output_stored_firmware_2_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_STORED_FIRMWARE_2, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    g_string_append (printable, "[");
    g_string_append (printable, " index = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " name = '");

    {
        g_autofree gchar *tmp = NULL;

        if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &tmp, &error))
            goto out;
        g_string_append (printable, tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " version = '");

    {
        g_autofree gchar *tmp = NULL;

        if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &tmp, &error))
            goto out;
        g_string_append (printable, tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " pri_revision = '");

    {
        g_autofree gchar *tmp = NULL;

        if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &tmp, &error))
            goto out;
        g_string_append (printable, tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " ]");

    if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0)
        g_string_append_printf (printable, "Additional unexpected '%" G_GSIZE_FORMAT "' bytes", offset);

out:
    if (error) {
        g_string_append_printf (printable, " ERROR: %s", error->message);
        g_error_free (error);
    }
    return g_string_free (printable, FALSE);
}

static gchar *
qmi_message_gas_dms_get_firmware_list_output_stored_firmware_3_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_STORED_FIRMWARE_3, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    g_string_append (printable, "[");
    g_string_append (printable, " index = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " name = '");

    {
        g_autofree gchar *tmp = NULL;

        if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &tmp, &error))
            goto out;
        g_string_append (printable, tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " version = '");

    {
        g_autofree gchar *tmp = NULL;

        if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &tmp, &error))
            goto out;
        g_string_append (printable, tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " pri_revision = '");

    {
        g_autofree gchar *tmp = NULL;

        if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &tmp, &error))
            goto out;
        g_string_append (printable, tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " ]");

    if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0)
        g_string_append_printf (printable, "Additional unexpected '%" G_GSIZE_FORMAT "' bytes", offset);

out:
    if (error) {
        g_string_append_printf (printable, " ERROR: %s", error->message);
        g_error_free (error);
    }
    return g_string_free (printable, FALSE);
}

static gchar *
qmi_message_gas_dms_get_firmware_list_output_stored_firmware_4_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_STORED_FIRMWARE_4, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    g_string_append (printable, "[");
    g_string_append (printable, " index = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " name = '");

    {
        g_autofree gchar *tmp = NULL;

        if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &tmp, &error))
            goto out;
        g_string_append (printable, tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " version = '");

    {
        g_autofree gchar *tmp = NULL;

        if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &tmp, &error))
            goto out;
        g_string_append (printable, tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " pri_revision = '");

    {
        g_autofree gchar *tmp = NULL;

        if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &tmp, &error))
            goto out;
        g_string_append (printable, tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " ]");

    if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0)
        g_string_append_printf (printable, "Additional unexpected '%" G_GSIZE_FORMAT "' bytes", offset);

out:
    if (error) {
        g_string_append_printf (printable, " ERROR: %s", error->message);
        g_error_free (error);
    }
    return g_string_free (printable, FALSE);
}

struct message_dms_get_firmware_list_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_dms_get_firmware_list_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_dms_get_firmware_list_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    g_autofree gchar *translated_value = NULL;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_INPUT_TLV_VERSION:
            tlv_type_str = "Version";
            translated_value = qmi_message_gas_dms_get_firmware_list_input_version_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_INPUT_TLV_NAME:
            tlv_type_str = "Name";
            translated_value = qmi_message_gas_dms_get_firmware_list_input_name_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_INPUT_TLV_SLOT_INDEX:
            tlv_type_str = "Slot Index";
            translated_value = qmi_message_gas_dms_get_firmware_list_input_slot_index_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_INPUT_TLV_MODE:
            tlv_type_str = "Mode";
            translated_value = qmi_message_gas_dms_get_firmware_list_input_mode_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_MODE:
            tlv_type_str = "Mode";
            translated_value = qmi_message_gas_dms_get_firmware_list_output_mode_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_STORED_FIRMWARE_1:
            tlv_type_str = "Stored Firmware 1";
            translated_value = qmi_message_gas_dms_get_firmware_list_output_stored_firmware_1_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_STORED_FIRMWARE_2:
            tlv_type_str = "Stored Firmware 2";
            translated_value = qmi_message_gas_dms_get_firmware_list_output_stored_firmware_2_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_STORED_FIRMWARE_3:
            tlv_type_str = "Stored Firmware 3";
            translated_value = qmi_message_gas_dms_get_firmware_list_output_stored_firmware_3_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_STORED_FIRMWARE_4:
            tlv_type_str = "Stored Firmware 4";
            translated_value = qmi_message_gas_dms_get_firmware_list_output_stored_firmware_4_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    }

    if (!tlv_type_str) {
        g_autofree gchar *value_str = NULL;

        value_str = qmi_message_get_tlv_printable (ctx->self,
                                                   ctx->line_prefix,
                                                   type,
                                                   value,
                                                   length);
        g_string_append (ctx->printable, value_str);
    } else {
        g_autofree gchar *value_hex = NULL;

        value_hex = qmi_helpers_str_hex (value, length, ':');
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
    }
}

static gchar *
message_dms_get_firmware_list_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"DMS Get Firmware List\" (0x0208)\n",
                            line_prefix);

    {
        struct message_dms_get_firmware_list_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_dms_get_firmware_list_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageGasDmsGetFirmwareListOutput *
__qmi_message_gas_dms_get_firmware_list_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageGasDmsGetFirmwareListOutput *self;

    g_assert_cmphex (qmi_message_get_message_id (message), ==, QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST);

    self = g_slice_new0 (QmiMessageGasDmsGetFirmwareListOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            gsize offset = 0;
            gsize init_offset;

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_RESULT, NULL, error)) == 0) {
                g_prefix_error (error, "Couldn't get the mandatory Result TLV: ");
                qmi_message_gas_dms_get_firmware_list_output_unref (self);
                return NULL;
            }
            if (!qmi_message_tlv_read_guint16 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &(self->arg_result.error_status), error))
                goto qmi_message_result_out;
            if (!qmi_message_tlv_read_guint16 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &(self->arg_result.error_code), error))
                goto qmi_message_result_out;

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Result' TLV", offset);
            }

            self->arg_result_set = TRUE;

qmi_message_result_out:
            if (!self->arg_result_set) {
                qmi_message_gas_dms_get_firmware_list_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    do {
        /* Prerequisite.... */
        if (!(self->arg_result.error_status == QMI_STATUS_SUCCESS))
            break;

        {
            gsize offset = 0;
            gsize init_offset;

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_MODE, NULL, error)) == 0) {
                g_prefix_error (error, "Couldn't get the mandatory Mode TLV: ");
                qmi_message_gas_dms_get_firmware_list_output_unref (self);
                return NULL;
            }
            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, error))
                    goto qmi_message_gas_dms_get_firmware_list_output_mode_out;
                self->arg_mode = (QmiGasFirmwareListingMode)tmp;
            }

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Mode' TLV", offset);
            }

            self->arg_mode_set = TRUE;

qmi_message_gas_dms_get_firmware_list_output_mode_out:
            if (!self->arg_mode_set) {
                qmi_message_gas_dms_get_firmware_list_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    do {
        /* Prerequisite.... */
        if (!(self->arg_result.error_status == QMI_STATUS_SUCCESS))
            break;

        {
            gsize offset = 0;
            gsize init_offset;

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_STORED_FIRMWARE_1, NULL, NULL)) == 0) {
                goto qmi_message_gas_dms_get_firmware_list_output_stored_firmware_1_out;
            }
            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(self->arg_stored_firmware_1_index), NULL))
                goto qmi_message_gas_dms_get_firmware_list_output_stored_firmware_1_out;
            if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &(self->arg_stored_firmware_1_name), NULL))
                goto qmi_message_gas_dms_get_firmware_list_output_stored_firmware_1_out;
            if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &(self->arg_stored_firmware_1_version), NULL))
                goto qmi_message_gas_dms_get_firmware_list_output_stored_firmware_1_out;
            if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &(self->arg_stored_firmware_1_pri_revision), NULL))
                goto qmi_message_gas_dms_get_firmware_list_output_stored_firmware_1_out;

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Stored Firmware 1' TLV", offset);
            }

            self->arg_stored_firmware_1_set = TRUE;

qmi_message_gas_dms_get_firmware_list_output_stored_firmware_1_out:
            ;

        }
    } while (0);

    do {
        /* Prerequisite.... */
        if (!(self->arg_result.error_status == QMI_STATUS_SUCCESS))
            break;

        {
            gsize offset = 0;
            gsize init_offset;

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_STORED_FIRMWARE_2, NULL, NULL)) == 0) {
                goto qmi_message_gas_dms_get_firmware_list_output_stored_firmware_2_out;
            }
            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(self->arg_stored_firmware_2_index), NULL))
                goto qmi_message_gas_dms_get_firmware_list_output_stored_firmware_2_out;
            if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &(self->arg_stored_firmware_2_name), NULL))
                goto qmi_message_gas_dms_get_firmware_list_output_stored_firmware_2_out;
            if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &(self->arg_stored_firmware_2_version), NULL))
                goto qmi_message_gas_dms_get_firmware_list_output_stored_firmware_2_out;
            if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &(self->arg_stored_firmware_2_pri_revision), NULL))
                goto qmi_message_gas_dms_get_firmware_list_output_stored_firmware_2_out;

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Stored Firmware 2' TLV", offset);
            }

            self->arg_stored_firmware_2_set = TRUE;

qmi_message_gas_dms_get_firmware_list_output_stored_firmware_2_out:
            ;

        }
    } while (0);

    do {
        /* Prerequisite.... */
        if (!(self->arg_result.error_status == QMI_STATUS_SUCCESS))
            break;

        {
            gsize offset = 0;
            gsize init_offset;

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_STORED_FIRMWARE_3, NULL, NULL)) == 0) {
                goto qmi_message_gas_dms_get_firmware_list_output_stored_firmware_3_out;
            }
            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(self->arg_stored_firmware_3_index), NULL))
                goto qmi_message_gas_dms_get_firmware_list_output_stored_firmware_3_out;
            if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &(self->arg_stored_firmware_3_name), NULL))
                goto qmi_message_gas_dms_get_firmware_list_output_stored_firmware_3_out;
            if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &(self->arg_stored_firmware_3_version), NULL))
                goto qmi_message_gas_dms_get_firmware_list_output_stored_firmware_3_out;
            if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &(self->arg_stored_firmware_3_pri_revision), NULL))
                goto qmi_message_gas_dms_get_firmware_list_output_stored_firmware_3_out;

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Stored Firmware 3' TLV", offset);
            }

            self->arg_stored_firmware_3_set = TRUE;

qmi_message_gas_dms_get_firmware_list_output_stored_firmware_3_out:
            ;

        }
    } while (0);

    do {
        /* Prerequisite.... */
        if (!(self->arg_result.error_status == QMI_STATUS_SUCCESS))
            break;

        {
            gsize offset = 0;
            gsize init_offset;

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT_TLV_STORED_FIRMWARE_4, NULL, NULL)) == 0) {
                goto qmi_message_gas_dms_get_firmware_list_output_stored_firmware_4_out;
            }
            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(self->arg_stored_firmware_4_index), NULL))
                goto qmi_message_gas_dms_get_firmware_list_output_stored_firmware_4_out;
            if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &(self->arg_stored_firmware_4_name), NULL))
                goto qmi_message_gas_dms_get_firmware_list_output_stored_firmware_4_out;
            if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &(self->arg_stored_firmware_4_version), NULL))
                goto qmi_message_gas_dms_get_firmware_list_output_stored_firmware_4_out;
            if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &(self->arg_stored_firmware_4_pri_revision), NULL))
                goto qmi_message_gas_dms_get_firmware_list_output_stored_firmware_4_out;

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Stored Firmware 4' TLV", offset);
            }

            self->arg_stored_firmware_4_set = TRUE;

qmi_message_gas_dms_get_firmware_list_output_stored_firmware_4_out:
            ;

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* Service-specific utils: GAS */


gchar *
__qmi_message_gas_get_printable (
    QmiMessage *self,
    QmiMessageContext *context,
    const gchar *line_prefix)
{
    if (qmi_message_is_indication (self)) {
        switch (qmi_message_get_message_id (self)) {
        default:
             return NULL;
        }
    } else {
        guint16 vendor_id;

        vendor_id = (context ? qmi_message_context_get_vendor_id (context) : QMI_MESSAGE_VENDOR_GENERIC);
        if (vendor_id == QMI_MESSAGE_VENDOR_GENERIC) {
            switch (qmi_message_get_message_id (self)) {
            case QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE:
                return message_dms_set_active_firmware_get_printable (self, line_prefix);
            case QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST:
                return message_dms_get_firmware_list_get_printable (self, line_prefix);
             default:
                 return NULL;
            }
        } else {
            return NULL;
        }
    }
}

/*****************************************************************************/
/* CLIENT: QMI Client GAS */


/**
 * SECTION: qmi-client-gas
 * @title: QmiClientGas
 * @short_description: #QmiClient for the GAS service.
 *
 * #QmiClient which handles operations in the GAS service.
 */

G_DEFINE_TYPE (QmiClientGas, qmi_client_gas, QMI_TYPE_CLIENT)

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
qmi_client_gas_init (QmiClientGas *self)
{
}

static void
qmi_client_gas_class_init (QmiClientGasClass *klass)
{
    QmiClientClass *client_class = QMI_CLIENT_CLASS (klass);

    client_class->process_indication = process_indication;
}


QmiMessageGasDmsSetActiveFirmwareOutput *
qmi_client_gas_dms_set_active_firmware_finish (
    QmiClientGas *self,
    GAsyncResult *res,
    GError **error)
{
   return g_task_propagate_pointer (G_TASK (res), error);
}

static void
dms_set_active_firmware_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GTask *task)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageGasDmsSetActiveFirmwareOutput *output;

    reply = qmi_device_command_full_finish (device, res, &error);
    if (!reply) {
        g_task_return_error (task, error);
        g_object_unref (task);
        return;
    }

    /* Parse reply */
    output = __qmi_message_gas_dms_set_active_firmware_response_parse (reply, &error);
    if (!output)
        g_task_return_error (task, error);
    else
        g_task_return_pointer (task,
                               output,
                               (GDestroyNotify)qmi_message_gas_dms_set_active_firmware_output_unref);
    g_object_unref (task);
    qmi_message_unref (reply);
}

void
qmi_client_gas_dms_set_active_firmware (
    QmiClientGas *self,
    QmiMessageGasDmsSetActiveFirmwareInput *input,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data)
{
    GTask *task;
    GError *error = NULL;
    guint16 transaction_id;
    g_autoptr(QmiMessage) request = NULL;

    task = g_task_new (self, cancellable, callback, user_data);
    if (!qmi_client_is_valid (QMI_CLIENT (self))) {
        g_task_return_new_error (task, QMI_CORE_ERROR, QMI_CORE_ERROR_WRONG_STATE, "client invalid");
        g_object_unref (task);
        return;
    }

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_gas_dms_set_active_firmware_request_create (
                  transaction_id,
                  qmi_client_get_cid (QMI_CLIENT (self)),
                  input,
                  &error);
    if (!request) {
        g_prefix_error (&error, "Couldn't create request message: ");
        g_task_return_error (task, error);
        g_object_unref (task);
        return;
    }

    qmi_device_command_full (QMI_DEVICE (qmi_client_peek_device (QMI_CLIENT (self))),
                             request,
                             NULL,
                             timeout,
                             cancellable,
                             (GAsyncReadyCallback)dms_set_active_firmware_ready,
                             task);
}


QmiMessageGasDmsGetFirmwareListOutput *
qmi_client_gas_dms_get_firmware_list_finish (
    QmiClientGas *self,
    GAsyncResult *res,
    GError **error)
{
   return g_task_propagate_pointer (G_TASK (res), error);
}

static void
dms_get_firmware_list_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GTask *task)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageGasDmsGetFirmwareListOutput *output;

    reply = qmi_device_command_full_finish (device, res, &error);
    if (!reply) {
        g_task_return_error (task, error);
        g_object_unref (task);
        return;
    }

    /* Parse reply */
    output = __qmi_message_gas_dms_get_firmware_list_response_parse (reply, &error);
    if (!output)
        g_task_return_error (task, error);
    else
        g_task_return_pointer (task,
                               output,
                               (GDestroyNotify)qmi_message_gas_dms_get_firmware_list_output_unref);
    g_object_unref (task);
    qmi_message_unref (reply);
}

void
qmi_client_gas_dms_get_firmware_list (
    QmiClientGas *self,
    QmiMessageGasDmsGetFirmwareListInput *input,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data)
{
    GTask *task;
    GError *error = NULL;
    guint16 transaction_id;
    g_autoptr(QmiMessage) request = NULL;

    task = g_task_new (self, cancellable, callback, user_data);
    if (!qmi_client_is_valid (QMI_CLIENT (self))) {
        g_task_return_new_error (task, QMI_CORE_ERROR, QMI_CORE_ERROR_WRONG_STATE, "client invalid");
        g_object_unref (task);
        return;
    }

    transaction_id = qmi_client_get_next_transaction_id (QMI_CLIENT (self));

    request = __qmi_message_gas_dms_get_firmware_list_request_create (
                  transaction_id,
                  qmi_client_get_cid (QMI_CLIENT (self)),
                  input,
                  &error);
    if (!request) {
        g_prefix_error (&error, "Couldn't create request message: ");
        g_task_return_error (task, error);
        g_object_unref (task);
        return;
    }

    qmi_device_command_full (QMI_DEVICE (qmi_client_peek_device (QMI_CLIENT (self))),
                             request,
                             NULL,
                             timeout,
                             cancellable,
                             (GAsyncReadyCallback)dms_get_firmware_list_ready,
                             task);
}

