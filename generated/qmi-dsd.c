
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

#include "qmi-dsd.h"
#include "qmi-enum-types.h"
#include "qmi-enum-types-private.h"
#include "qmi-flags64-types.h"
#include "qmi-error-types.h"
#include "qmi-device.h"
#include "qmi-helpers.h"

#define QMI_STATUS_SUCCESS 0x0000
#define QMI_STATUS_FAILURE 0x0001


typedef enum {
    QMI_MESSAGE_DSD_GET_APN_INFO = 0x0033,
    QMI_MESSAGE_DSD_SET_APN_TYPE = 0x0051,
} QmiMessageDsd;


/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message DSD Get APN Info */


/* --- Input -- */

struct _QmiMessageDsdGetApnInfoInput {
    volatile gint ref_count;

    /* APN Type */
    gboolean arg_apn_type_set;
    guint32 arg_apn_type;
};

#define QMI_MESSAGE_DSD_GET_APN_INFO_INPUT_TLV_APN_TYPE 0x01

gboolean
qmi_message_dsd_get_apn_info_input_get_apn_type (
    QmiMessageDsdGetApnInfoInput *self,
    QmiDsdApnType *value_apn_type,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_apn_type_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'APN Type' was not found in the message");
        return FALSE;
    }

    if (value_apn_type)
        *value_apn_type = (QmiDsdApnType)(self->arg_apn_type);

    return TRUE;
}

gboolean
qmi_message_dsd_get_apn_info_input_set_apn_type (
    QmiMessageDsdGetApnInfoInput *self,
    QmiDsdApnType value_apn_type,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_apn_type = (guint32)(value_apn_type);
    self->arg_apn_type_set = TRUE;

    return TRUE;
}

GType
qmi_message_dsd_get_apn_info_input_get_type (void)
{
    static gsize g_define_type_id_initialized = 0;

    if (g_once_init_enter (&g_define_type_id_initialized)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageDsdGetApnInfoInput"),
                                          (GBoxedCopyFunc) qmi_message_dsd_get_apn_info_input_ref,
                                          (GBoxedFreeFunc) qmi_message_dsd_get_apn_info_input_unref);

        g_once_init_leave (&g_define_type_id_initialized, g_define_type_id);
    }

    return g_define_type_id_initialized;
}

QmiMessageDsdGetApnInfoInput *
qmi_message_dsd_get_apn_info_input_ref (QmiMessageDsdGetApnInfoInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

void
qmi_message_dsd_get_apn_info_input_unref (QmiMessageDsdGetApnInfoInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageDsdGetApnInfoInput, self);
    }
}

QmiMessageDsdGetApnInfoInput *
qmi_message_dsd_get_apn_info_input_new (void)
{
    QmiMessageDsdGetApnInfoInput *self;

    self = g_slice_new0 (QmiMessageDsdGetApnInfoInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_dsd_get_apn_info_request_create (
    guint16 transaction_id,
    guint8 cid,
    QmiMessageDsdGetApnInfoInput *input,
    GError **error)
{
    g_autoptr(QmiMessage) self = NULL;

    self = qmi_message_new (QMI_SERVICE_DSD,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_DSD_GET_APN_INFO);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Get APN Info' has mandatory TLVs");
        return NULL;
    }

    /* Try to add the 'APN Type' TLV */
    if (input->arg_apn_type_set) {
        gsize tlv_offset;

        if (!(tlv_offset = qmi_message_tlv_write_init (self, (guint8)QMI_MESSAGE_DSD_GET_APN_INFO_INPUT_TLV_APN_TYPE, error))) {
            g_prefix_error (error, "Cannot initialize TLV 'APN Type': ");
            return NULL;
        }

        {
            guint32 tmp;

            tmp = (guint32) input->arg_apn_type;
            /* Write the guint32 variable to the buffer */
            if (!qmi_message_tlv_write_guint32 (self, QMI_ENDIAN_LITTLE, tmp, error)) {
                g_prefix_error (error, "Cannot write enum in TLV 'APN Type': ");
                return NULL;
            }
        }

        if (!qmi_message_tlv_write_complete (self, tlv_offset, error)) {
            g_prefix_error (error, "Cannot complete TLV 'APN Type': ");
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'APN Type' in message 'Get APN Info'");
        return NULL;
    }

    return g_steal_pointer (&self);
}

/* --- Output -- */

typedef struct _QmiMessageResult {
    guint16 error_status;
    guint16 error_code;
} QmiMessageResult;

struct _QmiMessageDsdGetApnInfoOutput {
    volatile gint ref_count;

    /* APN Name */
    gboolean arg_apn_name_set;
    gchar *arg_apn_name;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;
};

#define QMI_MESSAGE_DSD_GET_APN_INFO_OUTPUT_TLV_APN_NAME 0x10
#define QMI_MESSAGE_DSD_GET_APN_INFO_OUTPUT_TLV_RESULT 0x02

gboolean
qmi_message_dsd_get_apn_info_output_get_apn_name (
    QmiMessageDsdGetApnInfoOutput *self,
    const gchar **value_apn_name,
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

    if (value_apn_name)
        *value_apn_name = self->arg_apn_name;

    return TRUE;
}

gboolean
qmi_message_dsd_get_apn_info_output_get_result (
    QmiMessageDsdGetApnInfoOutput *self,
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
qmi_message_dsd_get_apn_info_output_get_type (void)
{
    static gsize g_define_type_id_initialized = 0;

    if (g_once_init_enter (&g_define_type_id_initialized)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageDsdGetApnInfoOutput"),
                                          (GBoxedCopyFunc) qmi_message_dsd_get_apn_info_output_ref,
                                          (GBoxedFreeFunc) qmi_message_dsd_get_apn_info_output_unref);

        g_once_init_leave (&g_define_type_id_initialized, g_define_type_id);
    }

    return g_define_type_id_initialized;
}

QmiMessageDsdGetApnInfoOutput *
qmi_message_dsd_get_apn_info_output_ref (QmiMessageDsdGetApnInfoOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

void
qmi_message_dsd_get_apn_info_output_unref (QmiMessageDsdGetApnInfoOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_free (self->arg_apn_name);
        g_slice_free (QmiMessageDsdGetApnInfoOutput, self);
    }
}

static gchar *
qmi_message_dsd_get_apn_info_input_apn_type_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_DSD_GET_APN_INFO_INPUT_TLV_APN_TYPE, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");

    {
        guint32 tmp;

        if (!qmi_message_tlv_read_guint32 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &tmp, &error))
            goto out;
#if defined  __QMI_DSD_APN_TYPE_IS_ENUM__
        g_string_append_printf (printable, "%s", qmi_dsd_apn_type_get_string ((QmiDsdApnType)tmp));
#elif defined  __QMI_DSD_APN_TYPE_IS_FLAGS__
        {
            g_autofree gchar *flags_str = NULL;

            flags_str = qmi_dsd_apn_type_build_string_from_mask ((QmiDsdApnType)tmp);
            g_string_append_printf (printable, "%s", flags_str);
        }
#else
# error unexpected public format: QmiDsdApnType
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
qmi_message_dsd_get_apn_info_output_apn_name_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_DSD_GET_APN_INFO_OUTPUT_TLV_APN_NAME, NULL, NULL)) == 0)
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

    if ((init_offset = qmi_message_tlv_read_init (self, QMI_MESSAGE_DSD_GET_APN_INFO_OUTPUT_TLV_RESULT, NULL, NULL)) == 0)
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

struct message_get_apn_info_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_get_apn_info_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_get_apn_info_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    g_autofree gchar *translated_value = NULL;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_DSD_GET_APN_INFO_INPUT_TLV_APN_TYPE:
            tlv_type_str = "APN Type";
            translated_value = qmi_message_dsd_get_apn_info_input_apn_type_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_DSD_GET_APN_INFO_OUTPUT_TLV_APN_NAME:
            tlv_type_str = "APN Name";
            translated_value = qmi_message_dsd_get_apn_info_output_apn_name_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_DSD_GET_APN_INFO_OUTPUT_TLV_RESULT:
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
message_get_apn_info_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Get APN Info\" (0x0033)\n",
                            line_prefix);

    {
        struct message_get_apn_info_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_get_apn_info_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageDsdGetApnInfoOutput *
__qmi_message_dsd_get_apn_info_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageDsdGetApnInfoOutput *self;

    g_assert_cmphex (qmi_message_get_message_id (message), ==, QMI_MESSAGE_DSD_GET_APN_INFO);

    self = g_slice_new0 (QmiMessageDsdGetApnInfoOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            gsize offset = 0;
            gsize init_offset;

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_DSD_GET_APN_INFO_OUTPUT_TLV_APN_NAME, NULL, NULL)) == 0) {
                goto qmi_message_dsd_get_apn_info_output_apn_name_out;
            }
            if (!qmi_message_tlv_read_string (message, init_offset, &offset, 0, 0, &(self->arg_apn_name), NULL))
                goto qmi_message_dsd_get_apn_info_output_apn_name_out;

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'APN Name' TLV", offset);
            }

            self->arg_apn_name_set = TRUE;

qmi_message_dsd_get_apn_info_output_apn_name_out:
            ;

        }
    } while (0);

    do {
        /* No Prerequisites for field */

        {
            gsize offset = 0;
            gsize init_offset;

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_DSD_GET_APN_INFO_OUTPUT_TLV_RESULT, NULL, error)) == 0) {
                g_prefix_error (error, "Couldn't get the mandatory Result TLV: ");
                qmi_message_dsd_get_apn_info_output_unref (self);
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
                qmi_message_dsd_get_apn_info_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message DSD Set APN Type */


/* --- Input -- */

struct _QmiMessageDsdSetApnTypeInput {
    volatile gint ref_count;

    /* APN Type Preference Mask */
    gboolean arg_apn_type_preference_mask_set;
    guint64 arg_apn_type_preference_mask;

    /* APN Type */
    gboolean arg_apn_type_set;
    gchar *arg_apn_type_name;
    guint64 arg_apn_type_type;
};

#define QMI_MESSAGE_DSD_SET_APN_TYPE_INPUT_TLV_APN_TYPE_PREFERENCE_MASK 0x10
#define QMI_MESSAGE_DSD_SET_APN_TYPE_INPUT_TLV_APN_TYPE 0x01

gboolean
qmi_message_dsd_set_apn_type_input_get_apn_type_preference_mask (
    QmiMessageDsdSetApnTypeInput *self,
    QmiDsdApnTypePreference *value_apn_type_preference_mask,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_apn_type_preference_mask_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'APN Type Preference Mask' was not found in the message");
        return FALSE;
    }

    if (value_apn_type_preference_mask)
        *value_apn_type_preference_mask = (QmiDsdApnTypePreference)(self->arg_apn_type_preference_mask);

    return TRUE;
}

gboolean
qmi_message_dsd_set_apn_type_input_set_apn_type_preference_mask (
    QmiMessageDsdSetApnTypeInput *self,
    QmiDsdApnTypePreference value_apn_type_preference_mask,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_apn_type_preference_mask = (guint64)(value_apn_type_preference_mask);
    self->arg_apn_type_preference_mask_set = TRUE;

    return TRUE;
}

gboolean
qmi_message_dsd_set_apn_type_input_get_apn_type (
    QmiMessageDsdSetApnTypeInput *self,
    const gchar **value_apn_type_name,
    QmiDsdApnTypePreference *value_apn_type_type,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_apn_type_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'APN Type' was not found in the message");
        return FALSE;
    }

    if (value_apn_type_name)
        *value_apn_type_name = self->arg_apn_type_name;
    if (value_apn_type_type)
        *value_apn_type_type = (QmiDsdApnTypePreference)(self->arg_apn_type_type);

    return TRUE;
}

gboolean
qmi_message_dsd_set_apn_type_input_set_apn_type (
    QmiMessageDsdSetApnTypeInput *self,
    const gchar *value_apn_type_name,
    QmiDsdApnTypePreference value_apn_type_type,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    g_free (self->arg_apn_type_name);
    self->arg_apn_type_name = g_strdup (value_apn_type_name ? value_apn_type_name : "");
    self->arg_apn_type_type = (guint64)(value_apn_type_type);
    self->arg_apn_type_set = TRUE;

    return TRUE;
}

GType
qmi_message_dsd_set_apn_type_input_get_type (void)
{
    static gsize g_define_type_id_initialized = 0;

    if (g_once_init_enter (&g_define_type_id_initialized)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageDsdSetApnTypeInput"),
                                          (GBoxedCopyFunc) qmi_message_dsd_set_apn_type_input_ref,
                                          (GBoxedFreeFunc) qmi_message_dsd_set_apn_type_input_unref);

        g_once_init_leave (&g_define_type_id_initialized, g_define_type_id);
    }

    return g_define_type_id_initialized;
}

QmiMessageDsdSetApnTypeInput *
qmi_message_dsd_set_apn_type_input_ref (QmiMessageDsdSetApnTypeInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

void
qmi_message_dsd_set_apn_type_input_unref (QmiMessageDsdSetApnTypeInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_free (self->arg_apn_type_name);
        g_slice_free (QmiMessageDsdSetApnTypeInput, self);
    }
}

QmiMessageDsdSetApnTypeInput *
qmi_message_dsd_set_apn_type_input_new (void)
{
    QmiMessageDsdSetApnTypeInput *self;

    self = g_slice_new0 (QmiMessageDsdSetApnTypeInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_dsd_set_apn_type_request_create (
    guint16 transaction_id,
    guint8 cid,
    QmiMessageDsdSetApnTypeInput *input,
    GError **error)
{
    g_autoptr(QmiMessage) self = NULL;

    self = qmi_message_new (QMI_SERVICE_DSD,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_DSD_SET_APN_TYPE);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Set APN Type' has mandatory TLVs");
        return NULL;
    }

    /* Try to add the 'APN Type Preference Mask' TLV */
    if (input->arg_apn_type_preference_mask_set) {
        gsize tlv_offset;

        if (!(tlv_offset = qmi_message_tlv_write_init (self, (guint8)QMI_MESSAGE_DSD_SET_APN_TYPE_INPUT_TLV_APN_TYPE_PREFERENCE_MASK, error))) {
            g_prefix_error (error, "Cannot initialize TLV 'APN Type Preference Mask': ");
            return NULL;
        }

        {
            guint64 tmp;

            tmp = (guint64) input->arg_apn_type_preference_mask;
            /* Write the guint64 variable to the buffer */
            if (!qmi_message_tlv_write_guint64 (self, QMI_ENDIAN_LITTLE, tmp, error)) {
                g_prefix_error (error, "Cannot write enum in TLV 'APN Type Preference Mask': ");
                return NULL;
            }
        }

        if (!qmi_message_tlv_write_complete (self, tlv_offset, error)) {
            g_prefix_error (error, "Cannot complete TLV 'APN Type Preference Mask': ");
            return NULL;
        }
    }

    /* Try to add the 'APN Type' TLV */
    if (input->arg_apn_type_set) {
        gsize tlv_offset;

        if (!(tlv_offset = qmi_message_tlv_write_init (self, (guint8)QMI_MESSAGE_DSD_SET_APN_TYPE_INPUT_TLV_APN_TYPE, error))) {
            g_prefix_error (error, "Cannot initialize TLV 'APN Type': ");
            return NULL;
        }

        if (!qmi_message_tlv_write_string (self, 1, input->arg_apn_type_name, -1, error)) {
            g_prefix_error (error, "Cannot write string in TLV 'APN Type': ");
            return NULL;
        }
        {
            guint64 tmp;

            tmp = (guint64) input->arg_apn_type_type;
            /* Write the guint64 variable to the buffer */
            if (!qmi_message_tlv_write_guint64 (self, QMI_ENDIAN_LITTLE, tmp, error)) {
                g_prefix_error (error, "Cannot write enum in TLV 'APN Type': ");
                return NULL;
            }
        }

        if (!qmi_message_tlv_write_complete (self, tlv_offset, error)) {
            g_prefix_error (error, "Cannot complete TLV 'APN Type': ");
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'APN Type' in message 'Set APN Type'");
        return NULL;
    }

    return g_steal_pointer (&self);
}

/* --- Output -- */

struct _QmiMessageDsdSetApnTypeOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;
};

#define QMI_MESSAGE_DSD_SET_APN_TYPE_OUTPUT_TLV_RESULT 0x02

gboolean
qmi_message_dsd_set_apn_type_output_get_result (
    QmiMessageDsdSetApnTypeOutput *self,
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
qmi_message_dsd_set_apn_type_output_get_type (void)
{
    static gsize g_define_type_id_initialized = 0;

    if (g_once_init_enter (&g_define_type_id_initialized)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessageDsdSetApnTypeOutput"),
                                          (GBoxedCopyFunc) qmi_message_dsd_set_apn_type_output_ref,
                                          (GBoxedFreeFunc) qmi_message_dsd_set_apn_type_output_unref);

        g_once_init_leave (&g_define_type_id_initialized, g_define_type_id);
    }

    return g_define_type_id_initialized;
}

QmiMessageDsdSetApnTypeOutput *
qmi_message_dsd_set_apn_type_output_ref (QmiMessageDsdSetApnTypeOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

void
qmi_message_dsd_set_apn_type_output_unref (QmiMessageDsdSetApnTypeOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessageDsdSetApnTypeOutput, self);
    }
}

static gchar *
qmi_message_dsd_set_apn_type_input_apn_type_preference_mask_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_DSD_SET_APN_TYPE_INPUT_TLV_APN_TYPE_PREFERENCE_MASK, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");

    {
        guint64 tmp;

        if (!qmi_message_tlv_read_guint64 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &tmp, &error))
            goto out;
#if defined  __QMI_DSD_APN_TYPE_PREFERENCE_IS_ENUM__
        g_string_append_printf (printable, "%s", qmi_dsd_apn_type_preference_get_string ((QmiDsdApnTypePreference)tmp));
#elif defined  __QMI_DSD_APN_TYPE_PREFERENCE_IS_FLAGS__
        {
            g_autofree gchar *flags_str = NULL;

            flags_str = qmi_dsd_apn_type_preference_build_string_from_mask ((QmiDsdApnTypePreference)tmp);
            g_string_append_printf (printable, "%s", flags_str);
        }
#else
# error unexpected public format: QmiDsdApnTypePreference
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
qmi_message_dsd_set_apn_type_input_apn_type_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_DSD_SET_APN_TYPE_INPUT_TLV_APN_TYPE, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    g_string_append (printable, "[");
    g_string_append (printable, " name = '");

    {
        g_autofree gchar *tmp = NULL;

        if (!qmi_message_tlv_read_string (message, init_offset, &offset, 1, 0, &tmp, &error))
            goto out;
        g_string_append (printable, tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " type = '");

    {
        guint64 tmp;

        if (!qmi_message_tlv_read_guint64 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &tmp, &error))
            goto out;
#if defined  __QMI_DSD_APN_TYPE_PREFERENCE_IS_ENUM__
        g_string_append_printf (printable, "%s", qmi_dsd_apn_type_preference_get_string ((QmiDsdApnTypePreference)tmp));
#elif defined  __QMI_DSD_APN_TYPE_PREFERENCE_IS_FLAGS__
        {
            g_autofree gchar *flags_str = NULL;

            flags_str = qmi_dsd_apn_type_preference_build_string_from_mask ((QmiDsdApnTypePreference)tmp);
            g_string_append_printf (printable, "%s", flags_str);
        }
#else
# error unexpected public format: QmiDsdApnTypePreference
#endif
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

struct message_set_apn_type_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_set_apn_type_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_set_apn_type_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    g_autofree gchar *translated_value = NULL;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_DSD_SET_APN_TYPE_INPUT_TLV_APN_TYPE_PREFERENCE_MASK:
            tlv_type_str = "APN Type Preference Mask";
            translated_value = qmi_message_dsd_set_apn_type_input_apn_type_preference_mask_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_DSD_SET_APN_TYPE_INPUT_TLV_APN_TYPE:
            tlv_type_str = "APN Type";
            translated_value = qmi_message_dsd_set_apn_type_input_apn_type_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_DSD_SET_APN_TYPE_OUTPUT_TLV_RESULT:
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
message_set_apn_type_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Set APN Type\" (0x0051)\n",
                            line_prefix);

    {
        struct message_set_apn_type_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_set_apn_type_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessageDsdSetApnTypeOutput *
__qmi_message_dsd_set_apn_type_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessageDsdSetApnTypeOutput *self;

    g_assert_cmphex (qmi_message_get_message_id (message), ==, QMI_MESSAGE_DSD_SET_APN_TYPE);

    self = g_slice_new0 (QmiMessageDsdSetApnTypeOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            gsize offset = 0;
            gsize init_offset;

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_DSD_SET_APN_TYPE_OUTPUT_TLV_RESULT, NULL, error)) == 0) {
                g_prefix_error (error, "Couldn't get the mandatory Result TLV: ");
                qmi_message_dsd_set_apn_type_output_unref (self);
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
                qmi_message_dsd_set_apn_type_output_unref (self);
                return NULL;
            }

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* Service-specific utils: DSD */


gchar *
__qmi_message_dsd_get_printable (
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
            case QMI_MESSAGE_DSD_GET_APN_INFO:
                return message_get_apn_info_get_printable (self, line_prefix);
            case QMI_MESSAGE_DSD_SET_APN_TYPE:
                return message_set_apn_type_get_printable (self, line_prefix);
             default:
                 return NULL;
            }
        } else {
            return NULL;
        }
    }
}

/*****************************************************************************/
/* CLIENT: QMI Client DSD */


/**
 * SECTION: qmi-client-dsd
 * @title: QmiClientDsd
 * @short_description: #QmiClient for the DSD service.
 *
 * #QmiClient which handles operations in the DSD service.
 */

G_DEFINE_TYPE (QmiClientDsd, qmi_client_dsd, QMI_TYPE_CLIENT)

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
qmi_client_dsd_init (QmiClientDsd *self)
{
}

static void
qmi_client_dsd_class_init (QmiClientDsdClass *klass)
{
    QmiClientClass *client_class = QMI_CLIENT_CLASS (klass);

    client_class->process_indication = process_indication;
}


QmiMessageDsdGetApnInfoOutput *
qmi_client_dsd_get_apn_info_finish (
    QmiClientDsd *self,
    GAsyncResult *res,
    GError **error)
{
   return g_task_propagate_pointer (G_TASK (res), error);
}

static void
get_apn_info_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GTask *task)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageDsdGetApnInfoOutput *output;

    reply = qmi_device_command_full_finish (device, res, &error);
    if (!reply) {
        g_task_return_error (task, error);
        g_object_unref (task);
        return;
    }

    /* Parse reply */
    output = __qmi_message_dsd_get_apn_info_response_parse (reply, &error);
    if (!output)
        g_task_return_error (task, error);
    else
        g_task_return_pointer (task,
                               output,
                               (GDestroyNotify)qmi_message_dsd_get_apn_info_output_unref);
    g_object_unref (task);
    qmi_message_unref (reply);
}

void
qmi_client_dsd_get_apn_info (
    QmiClientDsd *self,
    QmiMessageDsdGetApnInfoInput *input,
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

    request = __qmi_message_dsd_get_apn_info_request_create (
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
                             (GAsyncReadyCallback)get_apn_info_ready,
                             task);
}


QmiMessageDsdSetApnTypeOutput *
qmi_client_dsd_set_apn_type_finish (
    QmiClientDsd *self,
    GAsyncResult *res,
    GError **error)
{
   return g_task_propagate_pointer (G_TASK (res), error);
}

static void
set_apn_type_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GTask *task)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessageDsdSetApnTypeOutput *output;

    reply = qmi_device_command_full_finish (device, res, &error);
    if (!reply) {
        g_task_return_error (task, error);
        g_object_unref (task);
        return;
    }

    /* Parse reply */
    output = __qmi_message_dsd_set_apn_type_response_parse (reply, &error);
    if (!output)
        g_task_return_error (task, error);
    else
        g_task_return_pointer (task,
                               output,
                               (GDestroyNotify)qmi_message_dsd_set_apn_type_output_unref);
    g_object_unref (task);
    qmi_message_unref (reply);
}

void
qmi_client_dsd_set_apn_type (
    QmiClientDsd *self,
    QmiMessageDsdSetApnTypeInput *input,
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

    request = __qmi_message_dsd_set_apn_type_request_create (
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
                             (GAsyncReadyCallback)set_apn_type_ready,
                             task);
}

