
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

#include "qmi-pbm.h"
#include "qmi-enum-types.h"
#include "qmi-enum-types-private.h"
#include "qmi-flags64-types.h"
#include "qmi-error-types.h"
#include "qmi-device.h"
#include "qmi-helpers.h"

#define QMI_STATUS_SUCCESS 0x0000
#define QMI_STATUS_FAILURE 0x0001


typedef enum {
    QMI_MESSAGE_PBM_INDICATION_REGISTER = 0x0001,
    QMI_MESSAGE_PBM_GET_CAPABILITIES = 0x0002,
    QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES = 0x0003,
} QmiMessagePbm;


/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message PBM Indication Register */


/* --- Input -- */

struct _QmiMessagePbmIndicationRegisterInput {
    volatile gint ref_count;

    /* Event Registration Mask */
    gboolean arg_event_registration_mask_set;
    guint32 arg_event_registration_mask;
};

#define QMI_MESSAGE_PBM_INDICATION_REGISTER_INPUT_TLV_EVENT_REGISTRATION_MASK 0x01

gboolean
qmi_message_pbm_indication_register_input_get_event_registration_mask (
    QmiMessagePbmIndicationRegisterInput *self,
    QmiPbmEventRegistrationFlag *value_event_registration_mask,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_event_registration_mask_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Event Registration Mask' was not found in the message");
        return FALSE;
    }

    if (value_event_registration_mask)
        *value_event_registration_mask = (QmiPbmEventRegistrationFlag)(self->arg_event_registration_mask);

    return TRUE;
}

gboolean
qmi_message_pbm_indication_register_input_set_event_registration_mask (
    QmiMessagePbmIndicationRegisterInput *self,
    QmiPbmEventRegistrationFlag value_event_registration_mask,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_event_registration_mask = (guint32)(value_event_registration_mask);
    self->arg_event_registration_mask_set = TRUE;

    return TRUE;
}

GType
qmi_message_pbm_indication_register_input_get_type (void)
{
    static gsize g_define_type_id_initialized = 0;

    if (g_once_init_enter (&g_define_type_id_initialized)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessagePbmIndicationRegisterInput"),
                                          (GBoxedCopyFunc) qmi_message_pbm_indication_register_input_ref,
                                          (GBoxedFreeFunc) qmi_message_pbm_indication_register_input_unref);

        g_once_init_leave (&g_define_type_id_initialized, g_define_type_id);
    }

    return g_define_type_id_initialized;
}

QmiMessagePbmIndicationRegisterInput *
qmi_message_pbm_indication_register_input_ref (QmiMessagePbmIndicationRegisterInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

void
qmi_message_pbm_indication_register_input_unref (QmiMessagePbmIndicationRegisterInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessagePbmIndicationRegisterInput, self);
    }
}

QmiMessagePbmIndicationRegisterInput *
qmi_message_pbm_indication_register_input_new (void)
{
    QmiMessagePbmIndicationRegisterInput *self;

    self = g_slice_new0 (QmiMessagePbmIndicationRegisterInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_pbm_indication_register_request_create (
    guint16 transaction_id,
    guint8 cid,
    QmiMessagePbmIndicationRegisterInput *input,
    GError **error)
{
    g_autoptr(QmiMessage) self = NULL;

    self = qmi_message_new (QMI_SERVICE_PBM,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_PBM_INDICATION_REGISTER);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Indication Register' has mandatory TLVs");
        return NULL;
    }

    /* Try to add the 'Event Registration Mask' TLV */
    if (input->arg_event_registration_mask_set) {
        gsize tlv_offset;

        if (!(tlv_offset = qmi_message_tlv_write_init (self, (guint8)QMI_MESSAGE_PBM_INDICATION_REGISTER_INPUT_TLV_EVENT_REGISTRATION_MASK, error))) {
            g_prefix_error (error, "Cannot initialize TLV 'Event Registration Mask': ");
            return NULL;
        }

        {
            guint32 tmp;

            tmp = (guint32) input->arg_event_registration_mask;
            /* Write the guint32 variable to the buffer */
            if (!qmi_message_tlv_write_guint32 (self, QMI_ENDIAN_LITTLE, tmp, error)) {
                g_prefix_error (error, "Cannot write enum in TLV 'Event Registration Mask': ");
                return NULL;
            }
        }

        if (!qmi_message_tlv_write_complete (self, tlv_offset, error)) {
            g_prefix_error (error, "Cannot complete TLV 'Event Registration Mask': ");
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'Event Registration Mask' in message 'Indication Register'");
        return NULL;
    }

    return g_steal_pointer (&self);
}

/* --- Output -- */

typedef struct _QmiMessageResult {
    guint16 error_status;
    guint16 error_code;
} QmiMessageResult;

struct _QmiMessagePbmIndicationRegisterOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Event Registration Mask */
    gboolean arg_event_registration_mask_set;
    guint32 arg_event_registration_mask;
};

#define QMI_MESSAGE_PBM_INDICATION_REGISTER_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_PBM_INDICATION_REGISTER_OUTPUT_TLV_EVENT_REGISTRATION_MASK 0x10

gboolean
qmi_message_pbm_indication_register_output_get_result (
    QmiMessagePbmIndicationRegisterOutput *self,
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
qmi_message_pbm_indication_register_output_get_event_registration_mask (
    QmiMessagePbmIndicationRegisterOutput *self,
    QmiPbmEventRegistrationFlag *value_event_registration_mask,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_event_registration_mask_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Event Registration Mask' was not found in the message");
        return FALSE;
    }

    if (value_event_registration_mask)
        *value_event_registration_mask = (QmiPbmEventRegistrationFlag)(self->arg_event_registration_mask);

    return TRUE;
}

GType
qmi_message_pbm_indication_register_output_get_type (void)
{
    static gsize g_define_type_id_initialized = 0;

    if (g_once_init_enter (&g_define_type_id_initialized)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessagePbmIndicationRegisterOutput"),
                                          (GBoxedCopyFunc) qmi_message_pbm_indication_register_output_ref,
                                          (GBoxedFreeFunc) qmi_message_pbm_indication_register_output_unref);

        g_once_init_leave (&g_define_type_id_initialized, g_define_type_id);
    }

    return g_define_type_id_initialized;
}

QmiMessagePbmIndicationRegisterOutput *
qmi_message_pbm_indication_register_output_ref (QmiMessagePbmIndicationRegisterOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

void
qmi_message_pbm_indication_register_output_unref (QmiMessagePbmIndicationRegisterOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessagePbmIndicationRegisterOutput, self);
    }
}

static gchar *
qmi_message_pbm_indication_register_input_event_registration_mask_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_INDICATION_REGISTER_INPUT_TLV_EVENT_REGISTRATION_MASK, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");

    {
        guint32 tmp;

        if (!qmi_message_tlv_read_guint32 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &tmp, &error))
            goto out;
#if defined  __QMI_PBM_EVENT_REGISTRATION_FLAG_IS_ENUM__
        g_string_append_printf (printable, "%s", qmi_pbm_event_registration_flag_get_string ((QmiPbmEventRegistrationFlag)tmp));
#elif defined  __QMI_PBM_EVENT_REGISTRATION_FLAG_IS_FLAGS__
        {
            g_autofree gchar *flags_str = NULL;

            flags_str = qmi_pbm_event_registration_flag_build_string_from_mask ((QmiPbmEventRegistrationFlag)tmp);
            g_string_append_printf (printable, "%s", flags_str);
        }
#else
# error unexpected public format: QmiPbmEventRegistrationFlag
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

    if ((init_offset = qmi_message_tlv_read_init (self, QMI_MESSAGE_PBM_INDICATION_REGISTER_OUTPUT_TLV_RESULT, NULL, NULL)) == 0)
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

static gchar *
qmi_message_pbm_indication_register_output_event_registration_mask_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_INDICATION_REGISTER_OUTPUT_TLV_EVENT_REGISTRATION_MASK, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");

    {
        guint32 tmp;

        if (!qmi_message_tlv_read_guint32 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &tmp, &error))
            goto out;
#if defined  __QMI_PBM_EVENT_REGISTRATION_FLAG_IS_ENUM__
        g_string_append_printf (printable, "%s", qmi_pbm_event_registration_flag_get_string ((QmiPbmEventRegistrationFlag)tmp));
#elif defined  __QMI_PBM_EVENT_REGISTRATION_FLAG_IS_FLAGS__
        {
            g_autofree gchar *flags_str = NULL;

            flags_str = qmi_pbm_event_registration_flag_build_string_from_mask ((QmiPbmEventRegistrationFlag)tmp);
            g_string_append_printf (printable, "%s", flags_str);
        }
#else
# error unexpected public format: QmiPbmEventRegistrationFlag
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

struct message_indication_register_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_indication_register_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_indication_register_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    g_autofree gchar *translated_value = NULL;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_PBM_INDICATION_REGISTER_INPUT_TLV_EVENT_REGISTRATION_MASK:
            tlv_type_str = "Event Registration Mask";
            translated_value = qmi_message_pbm_indication_register_input_event_registration_mask_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_PBM_INDICATION_REGISTER_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PBM_INDICATION_REGISTER_OUTPUT_TLV_EVENT_REGISTRATION_MASK:
            tlv_type_str = "Event Registration Mask";
            translated_value = qmi_message_pbm_indication_register_output_event_registration_mask_get_printable (
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
message_indication_register_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Indication Register\" (0x0001)\n",
                            line_prefix);

    {
        struct message_indication_register_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_indication_register_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessagePbmIndicationRegisterOutput *
__qmi_message_pbm_indication_register_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessagePbmIndicationRegisterOutput *self;

    g_assert_cmphex (qmi_message_get_message_id (message), ==, QMI_MESSAGE_PBM_INDICATION_REGISTER);

    self = g_slice_new0 (QmiMessagePbmIndicationRegisterOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            gsize offset = 0;
            gsize init_offset;

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_INDICATION_REGISTER_OUTPUT_TLV_RESULT, NULL, error)) == 0) {
                g_prefix_error (error, "Couldn't get the mandatory Result TLV: ");
                qmi_message_pbm_indication_register_output_unref (self);
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
                qmi_message_pbm_indication_register_output_unref (self);
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

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_INDICATION_REGISTER_OUTPUT_TLV_EVENT_REGISTRATION_MASK, NULL, NULL)) == 0) {
                goto qmi_message_pbm_indication_register_output_event_registration_mask_out;
            }
            {
                guint32 tmp;

                if (!qmi_message_tlv_read_guint32 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &tmp, NULL))
                    goto qmi_message_pbm_indication_register_output_event_registration_mask_out;
                self->arg_event_registration_mask = (QmiPbmEventRegistrationFlag)tmp;
            }

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Event Registration Mask' TLV", offset);
            }

            self->arg_event_registration_mask_set = TRUE;

qmi_message_pbm_indication_register_output_event_registration_mask_out:
            ;

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message PBM Get Capabilities */


/* --- Input -- */

struct _QmiMessagePbmGetCapabilitiesInput {
    volatile gint ref_count;

    /* Phonebook Information */
    gboolean arg_phonebook_information_set;
    guint8 arg_phonebook_information_session_type;
    guint16 arg_phonebook_information_phonebook_type;
};

#define QMI_MESSAGE_PBM_GET_CAPABILITIES_INPUT_TLV_PHONEBOOK_INFORMATION 0x01

gboolean
qmi_message_pbm_get_capabilities_input_get_phonebook_information (
    QmiMessagePbmGetCapabilitiesInput *self,
    QmiPbmSessionType *value_phonebook_information_session_type,
    QmiPbmPhonebookType *value_phonebook_information_phonebook_type,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_phonebook_information_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Phonebook Information' was not found in the message");
        return FALSE;
    }

    if (value_phonebook_information_session_type)
        *value_phonebook_information_session_type = (QmiPbmSessionType)(self->arg_phonebook_information_session_type);
    if (value_phonebook_information_phonebook_type)
        *value_phonebook_information_phonebook_type = (QmiPbmPhonebookType)(self->arg_phonebook_information_phonebook_type);

    return TRUE;
}

gboolean
qmi_message_pbm_get_capabilities_input_set_phonebook_information (
    QmiMessagePbmGetCapabilitiesInput *self,
    QmiPbmSessionType value_phonebook_information_session_type,
    QmiPbmPhonebookType value_phonebook_information_phonebook_type,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    self->arg_phonebook_information_session_type = (guint8)(value_phonebook_information_session_type);
    self->arg_phonebook_information_phonebook_type = (guint16)(value_phonebook_information_phonebook_type);
    self->arg_phonebook_information_set = TRUE;

    return TRUE;
}

GType
qmi_message_pbm_get_capabilities_input_get_type (void)
{
    static gsize g_define_type_id_initialized = 0;

    if (g_once_init_enter (&g_define_type_id_initialized)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessagePbmGetCapabilitiesInput"),
                                          (GBoxedCopyFunc) qmi_message_pbm_get_capabilities_input_ref,
                                          (GBoxedFreeFunc) qmi_message_pbm_get_capabilities_input_unref);

        g_once_init_leave (&g_define_type_id_initialized, g_define_type_id);
    }

    return g_define_type_id_initialized;
}

QmiMessagePbmGetCapabilitiesInput *
qmi_message_pbm_get_capabilities_input_ref (QmiMessagePbmGetCapabilitiesInput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

void
qmi_message_pbm_get_capabilities_input_unref (QmiMessagePbmGetCapabilitiesInput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessagePbmGetCapabilitiesInput, self);
    }
}

QmiMessagePbmGetCapabilitiesInput *
qmi_message_pbm_get_capabilities_input_new (void)
{
    QmiMessagePbmGetCapabilitiesInput *self;

    self = g_slice_new0 (QmiMessagePbmGetCapabilitiesInput);
    self->ref_count = 1;
    return self;
}

static QmiMessage *
__qmi_message_pbm_get_capabilities_request_create (
    guint16 transaction_id,
    guint8 cid,
    QmiMessagePbmGetCapabilitiesInput *input,
    GError **error)
{
    g_autoptr(QmiMessage) self = NULL;

    self = qmi_message_new (QMI_SERVICE_PBM,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_PBM_GET_CAPABILITIES);

    /* There is at least one mandatory TLV, don't allow NULL input */
    if (!input) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Message 'Get Capabilities' has mandatory TLVs");
        return NULL;
    }

    /* Try to add the 'Phonebook Information' TLV */
    if (input->arg_phonebook_information_set) {
        gsize tlv_offset;

        if (!(tlv_offset = qmi_message_tlv_write_init (self, (guint8)QMI_MESSAGE_PBM_GET_CAPABILITIES_INPUT_TLV_PHONEBOOK_INFORMATION, error))) {
            g_prefix_error (error, "Cannot initialize TLV 'Phonebook Information': ");
            return NULL;
        }

        {
            guint8 tmp;

            tmp = (guint8) input->arg_phonebook_information_session_type;
            /* Write the guint8 variable to the buffer */
            if (!qmi_message_tlv_write_guint8 (self, tmp, error)) {
                g_prefix_error (error, "Cannot write enum in TLV 'Phonebook Information': ");
                return NULL;
            }
        }
        {
            guint16 tmp;

            tmp = (guint16) input->arg_phonebook_information_phonebook_type;
            /* Write the guint16 variable to the buffer */
            if (!qmi_message_tlv_write_guint16 (self, QMI_ENDIAN_LITTLE, tmp, error)) {
                g_prefix_error (error, "Cannot write enum in TLV 'Phonebook Information': ");
                return NULL;
            }
        }

        if (!qmi_message_tlv_write_complete (self, tlv_offset, error)) {
            g_prefix_error (error, "Cannot complete TLV 'Phonebook Information': ");
            return NULL;
        }
    } else {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_INVALID_ARGS,
                     "Missing mandatory TLV 'Phonebook Information' in message 'Get Capabilities'");
        return NULL;
    }

    return g_steal_pointer (&self);
}

/* --- Output -- */

struct _QmiMessagePbmGetCapabilitiesOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Capability Basic Information */
    gboolean arg_capability_basic_information_set;
    guint8 arg_capability_basic_information_session_type;
    guint16 arg_capability_basic_information_phonebook_type;
    guint16 arg_capability_basic_information_used_records;
    guint16 arg_capability_basic_information_maximum_records;
    guint8 arg_capability_basic_information_maximum_number_length;
    guint8 arg_capability_basic_information_maximum_name_length;

    /* Group Capability */
    gboolean arg_group_capability_set;
    guint8 arg_group_capability_maximum_groups;
    guint8 arg_group_capability_maximum_group_tag_length;

    /* Additional Number Capability */
    gboolean arg_additional_number_capability_set;
    guint8 arg_additional_number_capability_maximum_additional_numbers;
    guint8 arg_additional_number_capability_maximum_additional_number_length;
    guint8 arg_additional_number_capability_maximum_additional_number_tag_length;

    /* Email Capability */
    gboolean arg_email_capability_set;
    guint8 arg_email_capability_maximum_emails;
    guint8 arg_email_capability_maximum_email_address_length;

    /* Second Name Capability */
    gboolean arg_second_name_capability_set;
    guint8 arg_second_name_capability_maximum_second_name_length;

    /* Hidden Records Capability */
    gboolean arg_hidden_records_capability_set;
    guint8 arg_hidden_records_capability_supported;

    /* Grouping Information Alpha String Capability */
    gboolean arg_grouping_information_alpha_string_capability_set;
    guint8 arg_grouping_information_alpha_string_capability_maximum_records;
    guint8 arg_grouping_information_alpha_string_capability_used_records;
    guint8 arg_grouping_information_alpha_string_capability_maximum_string_length;

    /* Additional Number Alpha String Capability */
    gboolean arg_additional_number_alpha_string_capability_set;
    guint8 arg_additional_number_alpha_string_capability_maximum_records;
    guint8 arg_additional_number_alpha_string_capability_used_records;
    guint8 arg_additional_number_alpha_string_capability_maximum_string_length;
};

#define QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_CAPABILITY_BASIC_INFORMATION 0x10
#define QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_GROUP_CAPABILITY 0x11
#define QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_ADDITIONAL_NUMBER_CAPABILITY 0x12
#define QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_EMAIL_CAPABILITY 0x13
#define QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_SECOND_NAME_CAPABILITY 0x14
#define QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_HIDDEN_RECORDS_CAPABILITY 0x15
#define QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_GROUPING_INFORMATION_ALPHA_STRING_CAPABILITY 0x16
#define QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_ADDITIONAL_NUMBER_ALPHA_STRING_CAPABILITY 0x17

gboolean
qmi_message_pbm_get_capabilities_output_get_result (
    QmiMessagePbmGetCapabilitiesOutput *self,
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
qmi_message_pbm_get_capabilities_output_get_capability_basic_information (
    QmiMessagePbmGetCapabilitiesOutput *self,
    QmiPbmSessionType *value_capability_basic_information_session_type,
    QmiPbmPhonebookType *value_capability_basic_information_phonebook_type,
    guint16 *value_capability_basic_information_used_records,
    guint16 *value_capability_basic_information_maximum_records,
    guint8 *value_capability_basic_information_maximum_number_length,
    guint8 *value_capability_basic_information_maximum_name_length,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_capability_basic_information_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Capability Basic Information' was not found in the message");
        return FALSE;
    }

    if (value_capability_basic_information_session_type)
        *value_capability_basic_information_session_type = (QmiPbmSessionType)(self->arg_capability_basic_information_session_type);
    if (value_capability_basic_information_phonebook_type)
        *value_capability_basic_information_phonebook_type = (QmiPbmPhonebookType)(self->arg_capability_basic_information_phonebook_type);
    if (value_capability_basic_information_used_records)
        *value_capability_basic_information_used_records = self->arg_capability_basic_information_used_records;
    if (value_capability_basic_information_maximum_records)
        *value_capability_basic_information_maximum_records = self->arg_capability_basic_information_maximum_records;
    if (value_capability_basic_information_maximum_number_length)
        *value_capability_basic_information_maximum_number_length = self->arg_capability_basic_information_maximum_number_length;
    if (value_capability_basic_information_maximum_name_length)
        *value_capability_basic_information_maximum_name_length = self->arg_capability_basic_information_maximum_name_length;

    return TRUE;
}

gboolean
qmi_message_pbm_get_capabilities_output_get_group_capability (
    QmiMessagePbmGetCapabilitiesOutput *self,
    guint8 *value_group_capability_maximum_groups,
    guint8 *value_group_capability_maximum_group_tag_length,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_group_capability_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Group Capability' was not found in the message");
        return FALSE;
    }

    if (value_group_capability_maximum_groups)
        *value_group_capability_maximum_groups = self->arg_group_capability_maximum_groups;
    if (value_group_capability_maximum_group_tag_length)
        *value_group_capability_maximum_group_tag_length = self->arg_group_capability_maximum_group_tag_length;

    return TRUE;
}

gboolean
qmi_message_pbm_get_capabilities_output_get_additional_number_capability (
    QmiMessagePbmGetCapabilitiesOutput *self,
    guint8 *value_additional_number_capability_maximum_additional_numbers,
    guint8 *value_additional_number_capability_maximum_additional_number_length,
    guint8 *value_additional_number_capability_maximum_additional_number_tag_length,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_additional_number_capability_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Additional Number Capability' was not found in the message");
        return FALSE;
    }

    if (value_additional_number_capability_maximum_additional_numbers)
        *value_additional_number_capability_maximum_additional_numbers = self->arg_additional_number_capability_maximum_additional_numbers;
    if (value_additional_number_capability_maximum_additional_number_length)
        *value_additional_number_capability_maximum_additional_number_length = self->arg_additional_number_capability_maximum_additional_number_length;
    if (value_additional_number_capability_maximum_additional_number_tag_length)
        *value_additional_number_capability_maximum_additional_number_tag_length = self->arg_additional_number_capability_maximum_additional_number_tag_length;

    return TRUE;
}

gboolean
qmi_message_pbm_get_capabilities_output_get_email_capability (
    QmiMessagePbmGetCapabilitiesOutput *self,
    guint8 *value_email_capability_maximum_emails,
    guint8 *value_email_capability_maximum_email_address_length,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_email_capability_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Email Capability' was not found in the message");
        return FALSE;
    }

    if (value_email_capability_maximum_emails)
        *value_email_capability_maximum_emails = self->arg_email_capability_maximum_emails;
    if (value_email_capability_maximum_email_address_length)
        *value_email_capability_maximum_email_address_length = self->arg_email_capability_maximum_email_address_length;

    return TRUE;
}

gboolean
qmi_message_pbm_get_capabilities_output_get_second_name_capability (
    QmiMessagePbmGetCapabilitiesOutput *self,
    guint8 *value_second_name_capability_maximum_second_name_length,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_second_name_capability_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Second Name Capability' was not found in the message");
        return FALSE;
    }

    if (value_second_name_capability_maximum_second_name_length)
        *value_second_name_capability_maximum_second_name_length = self->arg_second_name_capability_maximum_second_name_length;

    return TRUE;
}

gboolean
qmi_message_pbm_get_capabilities_output_get_hidden_records_capability (
    QmiMessagePbmGetCapabilitiesOutput *self,
    gboolean *value_hidden_records_capability_supported,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_hidden_records_capability_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Hidden Records Capability' was not found in the message");
        return FALSE;
    }

    if (value_hidden_records_capability_supported)
        *value_hidden_records_capability_supported = (gboolean)(self->arg_hidden_records_capability_supported);

    return TRUE;
}

gboolean
qmi_message_pbm_get_capabilities_output_get_grouping_information_alpha_string_capability (
    QmiMessagePbmGetCapabilitiesOutput *self,
    guint8 *value_grouping_information_alpha_string_capability_maximum_records,
    guint8 *value_grouping_information_alpha_string_capability_used_records,
    guint8 *value_grouping_information_alpha_string_capability_maximum_string_length,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_grouping_information_alpha_string_capability_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Grouping Information Alpha String Capability' was not found in the message");
        return FALSE;
    }

    if (value_grouping_information_alpha_string_capability_maximum_records)
        *value_grouping_information_alpha_string_capability_maximum_records = self->arg_grouping_information_alpha_string_capability_maximum_records;
    if (value_grouping_information_alpha_string_capability_used_records)
        *value_grouping_information_alpha_string_capability_used_records = self->arg_grouping_information_alpha_string_capability_used_records;
    if (value_grouping_information_alpha_string_capability_maximum_string_length)
        *value_grouping_information_alpha_string_capability_maximum_string_length = self->arg_grouping_information_alpha_string_capability_maximum_string_length;

    return TRUE;
}

gboolean
qmi_message_pbm_get_capabilities_output_get_additional_number_alpha_string_capability (
    QmiMessagePbmGetCapabilitiesOutput *self,
    guint8 *value_additional_number_alpha_string_capability_maximum_records,
    guint8 *value_additional_number_alpha_string_capability_used_records,
    guint8 *value_additional_number_alpha_string_capability_maximum_string_length,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_additional_number_alpha_string_capability_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Additional Number Alpha String Capability' was not found in the message");
        return FALSE;
    }

    if (value_additional_number_alpha_string_capability_maximum_records)
        *value_additional_number_alpha_string_capability_maximum_records = self->arg_additional_number_alpha_string_capability_maximum_records;
    if (value_additional_number_alpha_string_capability_used_records)
        *value_additional_number_alpha_string_capability_used_records = self->arg_additional_number_alpha_string_capability_used_records;
    if (value_additional_number_alpha_string_capability_maximum_string_length)
        *value_additional_number_alpha_string_capability_maximum_string_length = self->arg_additional_number_alpha_string_capability_maximum_string_length;

    return TRUE;
}

GType
qmi_message_pbm_get_capabilities_output_get_type (void)
{
    static gsize g_define_type_id_initialized = 0;

    if (g_once_init_enter (&g_define_type_id_initialized)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessagePbmGetCapabilitiesOutput"),
                                          (GBoxedCopyFunc) qmi_message_pbm_get_capabilities_output_ref,
                                          (GBoxedFreeFunc) qmi_message_pbm_get_capabilities_output_unref);

        g_once_init_leave (&g_define_type_id_initialized, g_define_type_id);
    }

    return g_define_type_id_initialized;
}

QmiMessagePbmGetCapabilitiesOutput *
qmi_message_pbm_get_capabilities_output_ref (QmiMessagePbmGetCapabilitiesOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

void
qmi_message_pbm_get_capabilities_output_unref (QmiMessagePbmGetCapabilitiesOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        g_slice_free (QmiMessagePbmGetCapabilitiesOutput, self);
    }
}

static gchar *
qmi_message_pbm_get_capabilities_input_phonebook_information_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_CAPABILITIES_INPUT_TLV_PHONEBOOK_INFORMATION, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    g_string_append (printable, "[");
    g_string_append (printable, " session_type = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
#if defined  __QMI_PBM_SESSION_TYPE_IS_ENUM__
        g_string_append_printf (printable, "%s", qmi_pbm_session_type_get_string ((QmiPbmSessionType)tmp));
#elif defined  __QMI_PBM_SESSION_TYPE_IS_FLAGS__
        {
            g_autofree gchar *flags_str = NULL;

            flags_str = qmi_pbm_session_type_build_string_from_mask ((QmiPbmSessionType)tmp);
            g_string_append_printf (printable, "%s", flags_str);
        }
#else
# error unexpected public format: QmiPbmSessionType
#endif
    }
    g_string_append (printable, "'");
    g_string_append (printable, " phonebook_type = '");

    {
        guint16 tmp;

        if (!qmi_message_tlv_read_guint16 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &tmp, &error))
            goto out;
#if defined  __QMI_PBM_PHONEBOOK_TYPE_IS_ENUM__
        g_string_append_printf (printable, "%s", qmi_pbm_phonebook_type_get_string ((QmiPbmPhonebookType)tmp));
#elif defined  __QMI_PBM_PHONEBOOK_TYPE_IS_FLAGS__
        {
            g_autofree gchar *flags_str = NULL;

            flags_str = qmi_pbm_phonebook_type_build_string_from_mask ((QmiPbmPhonebookType)tmp);
            g_string_append_printf (printable, "%s", flags_str);
        }
#else
# error unexpected public format: QmiPbmPhonebookType
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

static gchar *
qmi_message_pbm_get_capabilities_output_capability_basic_information_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_CAPABILITY_BASIC_INFORMATION, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    g_string_append (printable, "[");
    g_string_append (printable, " session_type = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
#if defined  __QMI_PBM_SESSION_TYPE_IS_ENUM__
        g_string_append_printf (printable, "%s", qmi_pbm_session_type_get_string ((QmiPbmSessionType)tmp));
#elif defined  __QMI_PBM_SESSION_TYPE_IS_FLAGS__
        {
            g_autofree gchar *flags_str = NULL;

            flags_str = qmi_pbm_session_type_build_string_from_mask ((QmiPbmSessionType)tmp);
            g_string_append_printf (printable, "%s", flags_str);
        }
#else
# error unexpected public format: QmiPbmSessionType
#endif
    }
    g_string_append (printable, "'");
    g_string_append (printable, " phonebook_type = '");

    {
        guint16 tmp;

        if (!qmi_message_tlv_read_guint16 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &tmp, &error))
            goto out;
#if defined  __QMI_PBM_PHONEBOOK_TYPE_IS_ENUM__
        g_string_append_printf (printable, "%s", qmi_pbm_phonebook_type_get_string ((QmiPbmPhonebookType)tmp));
#elif defined  __QMI_PBM_PHONEBOOK_TYPE_IS_FLAGS__
        {
            g_autofree gchar *flags_str = NULL;

            flags_str = qmi_pbm_phonebook_type_build_string_from_mask ((QmiPbmPhonebookType)tmp);
            g_string_append_printf (printable, "%s", flags_str);
        }
#else
# error unexpected public format: QmiPbmPhonebookType
#endif
    }
    g_string_append (printable, "'");
    g_string_append (printable, " used_records = '");

    {
        guint16 tmp;

        if (!qmi_message_tlv_read_guint16 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%" G_GUINT16_FORMAT "", tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " maximum_records = '");

    {
        guint16 tmp;

        if (!qmi_message_tlv_read_guint16 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%" G_GUINT16_FORMAT "", tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " maximum_number_length = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " maximum_name_length = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
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
qmi_message_pbm_get_capabilities_output_group_capability_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_GROUP_CAPABILITY, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    g_string_append (printable, "[");
    g_string_append (printable, " maximum_groups = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " maximum_group_tag_length = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
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
qmi_message_pbm_get_capabilities_output_additional_number_capability_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_ADDITIONAL_NUMBER_CAPABILITY, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    g_string_append (printable, "[");
    g_string_append (printable, " maximum_additional_numbers = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " maximum_additional_number_length = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " maximum_additional_number_tag_length = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
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
qmi_message_pbm_get_capabilities_output_email_capability_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_EMAIL_CAPABILITY, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    g_string_append (printable, "[");
    g_string_append (printable, " maximum_emails = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " maximum_email_address_length = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
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
qmi_message_pbm_get_capabilities_output_second_name_capability_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_SECOND_NAME_CAPABILITY, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    g_string_append (printable, "[");
    g_string_append (printable, " maximum_second_name_length = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
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
qmi_message_pbm_get_capabilities_output_hidden_records_capability_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_HIDDEN_RECORDS_CAPABILITY, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    g_string_append (printable, "[");
    g_string_append (printable, " supported = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%s", tmp ? "yes" : "no");
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
qmi_message_pbm_get_capabilities_output_grouping_information_alpha_string_capability_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_GROUPING_INFORMATION_ALPHA_STRING_CAPABILITY, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    g_string_append (printable, "[");
    g_string_append (printable, " maximum_records = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " used_records = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " maximum_string_length = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
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
qmi_message_pbm_get_capabilities_output_additional_number_alpha_string_capability_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_ADDITIONAL_NUMBER_ALPHA_STRING_CAPABILITY, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    g_string_append (printable, "[");
    g_string_append (printable, " maximum_records = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " used_records = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
    }
    g_string_append (printable, "'");
    g_string_append (printable, " maximum_string_length = '");

    {
        guint8 tmp;

        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
            goto out;
        g_string_append_printf (printable, "%u", (guint)tmp);
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

struct message_get_capabilities_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_get_capabilities_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_get_capabilities_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    g_autofree gchar *translated_value = NULL;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        case QMI_MESSAGE_PBM_GET_CAPABILITIES_INPUT_TLV_PHONEBOOK_INFORMATION:
            tlv_type_str = "Phonebook Information";
            translated_value = qmi_message_pbm_get_capabilities_input_phonebook_information_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_CAPABILITY_BASIC_INFORMATION:
            tlv_type_str = "Capability Basic Information";
            translated_value = qmi_message_pbm_get_capabilities_output_capability_basic_information_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_GROUP_CAPABILITY:
            tlv_type_str = "Group Capability";
            translated_value = qmi_message_pbm_get_capabilities_output_group_capability_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_ADDITIONAL_NUMBER_CAPABILITY:
            tlv_type_str = "Additional Number Capability";
            translated_value = qmi_message_pbm_get_capabilities_output_additional_number_capability_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_EMAIL_CAPABILITY:
            tlv_type_str = "Email Capability";
            translated_value = qmi_message_pbm_get_capabilities_output_email_capability_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_SECOND_NAME_CAPABILITY:
            tlv_type_str = "Second Name Capability";
            translated_value = qmi_message_pbm_get_capabilities_output_second_name_capability_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_HIDDEN_RECORDS_CAPABILITY:
            tlv_type_str = "Hidden Records Capability";
            translated_value = qmi_message_pbm_get_capabilities_output_hidden_records_capability_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_GROUPING_INFORMATION_ALPHA_STRING_CAPABILITY:
            tlv_type_str = "Grouping Information Alpha String Capability";
            translated_value = qmi_message_pbm_get_capabilities_output_grouping_information_alpha_string_capability_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_ADDITIONAL_NUMBER_ALPHA_STRING_CAPABILITY:
            tlv_type_str = "Additional Number Alpha String Capability";
            translated_value = qmi_message_pbm_get_capabilities_output_additional_number_alpha_string_capability_get_printable (
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
message_get_capabilities_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Get Capabilities\" (0x0002)\n",
                            line_prefix);

    {
        struct message_get_capabilities_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_get_capabilities_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessagePbmGetCapabilitiesOutput *
__qmi_message_pbm_get_capabilities_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessagePbmGetCapabilitiesOutput *self;

    g_assert_cmphex (qmi_message_get_message_id (message), ==, QMI_MESSAGE_PBM_GET_CAPABILITIES);

    self = g_slice_new0 (QmiMessagePbmGetCapabilitiesOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            gsize offset = 0;
            gsize init_offset;

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_RESULT, NULL, error)) == 0) {
                g_prefix_error (error, "Couldn't get the mandatory Result TLV: ");
                qmi_message_pbm_get_capabilities_output_unref (self);
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
                qmi_message_pbm_get_capabilities_output_unref (self);
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

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_CAPABILITY_BASIC_INFORMATION, NULL, NULL)) == 0) {
                goto qmi_message_pbm_get_capabilities_output_capability_basic_information_out;
            }
            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, NULL))
                    goto qmi_message_pbm_get_capabilities_output_capability_basic_information_out;
                self->arg_capability_basic_information_session_type = (QmiPbmSessionType)tmp;
            }
            {
                guint16 tmp;

                if (!qmi_message_tlv_read_guint16 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &tmp, NULL))
                    goto qmi_message_pbm_get_capabilities_output_capability_basic_information_out;
                self->arg_capability_basic_information_phonebook_type = (QmiPbmPhonebookType)tmp;
            }
            if (!qmi_message_tlv_read_guint16 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &(self->arg_capability_basic_information_used_records), NULL))
                goto qmi_message_pbm_get_capabilities_output_capability_basic_information_out;
            if (!qmi_message_tlv_read_guint16 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &(self->arg_capability_basic_information_maximum_records), NULL))
                goto qmi_message_pbm_get_capabilities_output_capability_basic_information_out;
            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(self->arg_capability_basic_information_maximum_number_length), NULL))
                goto qmi_message_pbm_get_capabilities_output_capability_basic_information_out;
            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(self->arg_capability_basic_information_maximum_name_length), NULL))
                goto qmi_message_pbm_get_capabilities_output_capability_basic_information_out;

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Capability Basic Information' TLV", offset);
            }

            self->arg_capability_basic_information_set = TRUE;

qmi_message_pbm_get_capabilities_output_capability_basic_information_out:
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

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_GROUP_CAPABILITY, NULL, NULL)) == 0) {
                goto qmi_message_pbm_get_capabilities_output_group_capability_out;
            }
            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(self->arg_group_capability_maximum_groups), NULL))
                goto qmi_message_pbm_get_capabilities_output_group_capability_out;
            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(self->arg_group_capability_maximum_group_tag_length), NULL))
                goto qmi_message_pbm_get_capabilities_output_group_capability_out;

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Group Capability' TLV", offset);
            }

            self->arg_group_capability_set = TRUE;

qmi_message_pbm_get_capabilities_output_group_capability_out:
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

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_ADDITIONAL_NUMBER_CAPABILITY, NULL, NULL)) == 0) {
                goto qmi_message_pbm_get_capabilities_output_additional_number_capability_out;
            }
            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(self->arg_additional_number_capability_maximum_additional_numbers), NULL))
                goto qmi_message_pbm_get_capabilities_output_additional_number_capability_out;
            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(self->arg_additional_number_capability_maximum_additional_number_length), NULL))
                goto qmi_message_pbm_get_capabilities_output_additional_number_capability_out;
            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(self->arg_additional_number_capability_maximum_additional_number_tag_length), NULL))
                goto qmi_message_pbm_get_capabilities_output_additional_number_capability_out;

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Additional Number Capability' TLV", offset);
            }

            self->arg_additional_number_capability_set = TRUE;

qmi_message_pbm_get_capabilities_output_additional_number_capability_out:
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

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_EMAIL_CAPABILITY, NULL, NULL)) == 0) {
                goto qmi_message_pbm_get_capabilities_output_email_capability_out;
            }
            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(self->arg_email_capability_maximum_emails), NULL))
                goto qmi_message_pbm_get_capabilities_output_email_capability_out;
            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(self->arg_email_capability_maximum_email_address_length), NULL))
                goto qmi_message_pbm_get_capabilities_output_email_capability_out;

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Email Capability' TLV", offset);
            }

            self->arg_email_capability_set = TRUE;

qmi_message_pbm_get_capabilities_output_email_capability_out:
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

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_SECOND_NAME_CAPABILITY, NULL, NULL)) == 0) {
                goto qmi_message_pbm_get_capabilities_output_second_name_capability_out;
            }
            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(self->arg_second_name_capability_maximum_second_name_length), NULL))
                goto qmi_message_pbm_get_capabilities_output_second_name_capability_out;

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Second Name Capability' TLV", offset);
            }

            self->arg_second_name_capability_set = TRUE;

qmi_message_pbm_get_capabilities_output_second_name_capability_out:
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

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_HIDDEN_RECORDS_CAPABILITY, NULL, NULL)) == 0) {
                goto qmi_message_pbm_get_capabilities_output_hidden_records_capability_out;
            }
            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, NULL))
                    goto qmi_message_pbm_get_capabilities_output_hidden_records_capability_out;
                self->arg_hidden_records_capability_supported = (gboolean)tmp;
            }

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Hidden Records Capability' TLV", offset);
            }

            self->arg_hidden_records_capability_set = TRUE;

qmi_message_pbm_get_capabilities_output_hidden_records_capability_out:
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

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_GROUPING_INFORMATION_ALPHA_STRING_CAPABILITY, NULL, NULL)) == 0) {
                goto qmi_message_pbm_get_capabilities_output_grouping_information_alpha_string_capability_out;
            }
            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(self->arg_grouping_information_alpha_string_capability_maximum_records), NULL))
                goto qmi_message_pbm_get_capabilities_output_grouping_information_alpha_string_capability_out;
            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(self->arg_grouping_information_alpha_string_capability_used_records), NULL))
                goto qmi_message_pbm_get_capabilities_output_grouping_information_alpha_string_capability_out;
            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(self->arg_grouping_information_alpha_string_capability_maximum_string_length), NULL))
                goto qmi_message_pbm_get_capabilities_output_grouping_information_alpha_string_capability_out;

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Grouping Information Alpha String Capability' TLV", offset);
            }

            self->arg_grouping_information_alpha_string_capability_set = TRUE;

qmi_message_pbm_get_capabilities_output_grouping_information_alpha_string_capability_out:
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

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_CAPABILITIES_OUTPUT_TLV_ADDITIONAL_NUMBER_ALPHA_STRING_CAPABILITY, NULL, NULL)) == 0) {
                goto qmi_message_pbm_get_capabilities_output_additional_number_alpha_string_capability_out;
            }
            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(self->arg_additional_number_alpha_string_capability_maximum_records), NULL))
                goto qmi_message_pbm_get_capabilities_output_additional_number_alpha_string_capability_out;
            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(self->arg_additional_number_alpha_string_capability_used_records), NULL))
                goto qmi_message_pbm_get_capabilities_output_additional_number_alpha_string_capability_out;
            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(self->arg_additional_number_alpha_string_capability_maximum_string_length), NULL))
                goto qmi_message_pbm_get_capabilities_output_additional_number_alpha_string_capability_out;

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Additional Number Alpha String Capability' TLV", offset);
            }

            self->arg_additional_number_alpha_string_capability_set = TRUE;

qmi_message_pbm_get_capabilities_output_additional_number_alpha_string_capability_out:
            ;

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message PBM Get All Capabilities */


/* --- Input -- */

/* Note: no fields in the Input container */

static QmiMessage *
__qmi_message_pbm_get_all_capabilities_request_create (
    guint16 transaction_id,
    guint8 cid,
    gpointer unused,
    GError **error)
{
    g_autoptr(QmiMessage) self = NULL;

    self = qmi_message_new (QMI_SERVICE_PBM,
                            cid,
                            transaction_id,
                            QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES);

    return g_steal_pointer (&self);
}

/* --- Output -- */

static void
capability_basic_information_qmimessagepbmgetallcapabilitiesoutputcapabilitybasicinformationelement_clear (QmiMessagePbmGetAllCapabilitiesOutputCapabilityBasicInformationElement *p)
{
    if ((*p).phonebooks)
        g_array_unref ((*p).phonebooks);
}

struct _QmiMessagePbmGetAllCapabilitiesOutput {
    volatile gint ref_count;

    /* Result */
    gboolean arg_result_set;
    QmiMessageResult arg_result;

    /* Capability Basic Information */
    gboolean arg_capability_basic_information_set;
    GArray *arg_capability_basic_information;

    /* Group Capability */
    gboolean arg_group_capability_set;
    GArray *arg_group_capability;

    /* Additional Number Capability */
    gboolean arg_additional_number_capability_set;
    GArray *arg_additional_number_capability;

    /* Email Capability */
    gboolean arg_email_capability_set;
    GArray *arg_email_capability;

    /* Second Name Capability */
    gboolean arg_second_name_capability_set;
    GArray *arg_second_name_capability;

    /* Hidden Records Capability */
    gboolean arg_hidden_records_capability_set;
    GArray *arg_hidden_records_capability;

    /* Grouping Information Alpha String Capability */
    gboolean arg_grouping_information_alpha_string_capability_set;
    GArray *arg_grouping_information_alpha_string_capability;

    /* Additional Number Alpha String Capability */
    gboolean arg_additional_number_alpha_string_capability_set;
    GArray *arg_additional_number_alpha_string_capability;
};

#define QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_RESULT 0x02
#define QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_CAPABILITY_BASIC_INFORMATION 0x10
#define QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_GROUP_CAPABILITY 0x11
#define QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_ADDITIONAL_NUMBER_CAPABILITY 0x12
#define QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_EMAIL_CAPABILITY 0x13
#define QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_SECOND_NAME_CAPABILITY 0x14
#define QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_HIDDEN_RECORDS_CAPABILITY 0x15
#define QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_GROUPING_INFORMATION_ALPHA_STRING_CAPABILITY 0x16
#define QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_ADDITIONAL_NUMBER_ALPHA_STRING_CAPABILITY 0x17

gboolean
qmi_message_pbm_get_all_capabilities_output_get_result (
    QmiMessagePbmGetAllCapabilitiesOutput *self,
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
qmi_message_pbm_get_all_capabilities_output_get_capability_basic_information (
    QmiMessagePbmGetAllCapabilitiesOutput *self,
    GArray **value_capability_basic_information,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_capability_basic_information_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Capability Basic Information' was not found in the message");
        return FALSE;
    }

    if (value_capability_basic_information)
        *value_capability_basic_information = self->arg_capability_basic_information;

    return TRUE;
}

gboolean
qmi_message_pbm_get_all_capabilities_output_get_group_capability (
    QmiMessagePbmGetAllCapabilitiesOutput *self,
    GArray **value_group_capability,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_group_capability_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Group Capability' was not found in the message");
        return FALSE;
    }

    if (value_group_capability)
        *value_group_capability = self->arg_group_capability;

    return TRUE;
}

gboolean
qmi_message_pbm_get_all_capabilities_output_get_additional_number_capability (
    QmiMessagePbmGetAllCapabilitiesOutput *self,
    GArray **value_additional_number_capability,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_additional_number_capability_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Additional Number Capability' was not found in the message");
        return FALSE;
    }

    if (value_additional_number_capability)
        *value_additional_number_capability = self->arg_additional_number_capability;

    return TRUE;
}

gboolean
qmi_message_pbm_get_all_capabilities_output_get_email_capability (
    QmiMessagePbmGetAllCapabilitiesOutput *self,
    GArray **value_email_capability,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_email_capability_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Email Capability' was not found in the message");
        return FALSE;
    }

    if (value_email_capability)
        *value_email_capability = self->arg_email_capability;

    return TRUE;
}

gboolean
qmi_message_pbm_get_all_capabilities_output_get_second_name_capability (
    QmiMessagePbmGetAllCapabilitiesOutput *self,
    GArray **value_second_name_capability,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_second_name_capability_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Second Name Capability' was not found in the message");
        return FALSE;
    }

    if (value_second_name_capability)
        *value_second_name_capability = self->arg_second_name_capability;

    return TRUE;
}

gboolean
qmi_message_pbm_get_all_capabilities_output_get_hidden_records_capability (
    QmiMessagePbmGetAllCapabilitiesOutput *self,
    GArray **value_hidden_records_capability,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_hidden_records_capability_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Hidden Records Capability' was not found in the message");
        return FALSE;
    }

    if (value_hidden_records_capability)
        *value_hidden_records_capability = self->arg_hidden_records_capability;

    return TRUE;
}

gboolean
qmi_message_pbm_get_all_capabilities_output_get_grouping_information_alpha_string_capability (
    QmiMessagePbmGetAllCapabilitiesOutput *self,
    GArray **value_grouping_information_alpha_string_capability,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_grouping_information_alpha_string_capability_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Grouping Information Alpha String Capability' was not found in the message");
        return FALSE;
    }

    if (value_grouping_information_alpha_string_capability)
        *value_grouping_information_alpha_string_capability = self->arg_grouping_information_alpha_string_capability;

    return TRUE;
}

gboolean
qmi_message_pbm_get_all_capabilities_output_get_additional_number_alpha_string_capability (
    QmiMessagePbmGetAllCapabilitiesOutput *self,
    GArray **value_additional_number_alpha_string_capability,
    GError **error)
{
    g_return_val_if_fail (self != NULL, FALSE);

    if (!self->arg_additional_number_alpha_string_capability_set) {
        g_set_error (error,
                     QMI_CORE_ERROR,
                     QMI_CORE_ERROR_TLV_NOT_FOUND,
                     "Field 'Additional Number Alpha String Capability' was not found in the message");
        return FALSE;
    }

    if (value_additional_number_alpha_string_capability)
        *value_additional_number_alpha_string_capability = self->arg_additional_number_alpha_string_capability;

    return TRUE;
}

GType
qmi_message_pbm_get_all_capabilities_output_get_type (void)
{
    static gsize g_define_type_id_initialized = 0;

    if (g_once_init_enter (&g_define_type_id_initialized)) {
        GType g_define_type_id =
            g_boxed_type_register_static (g_intern_static_string ("QmiMessagePbmGetAllCapabilitiesOutput"),
                                          (GBoxedCopyFunc) qmi_message_pbm_get_all_capabilities_output_ref,
                                          (GBoxedFreeFunc) qmi_message_pbm_get_all_capabilities_output_unref);

        g_once_init_leave (&g_define_type_id_initialized, g_define_type_id);
    }

    return g_define_type_id_initialized;
}

QmiMessagePbmGetAllCapabilitiesOutput *
qmi_message_pbm_get_all_capabilities_output_ref (QmiMessagePbmGetAllCapabilitiesOutput *self)
{
    g_return_val_if_fail (self != NULL, NULL);

    g_atomic_int_inc (&self->ref_count);
    return self;
}

void
qmi_message_pbm_get_all_capabilities_output_unref (QmiMessagePbmGetAllCapabilitiesOutput *self)
{
    g_return_if_fail (self != NULL);

    if (g_atomic_int_dec_and_test (&self->ref_count)) {
        if (self->arg_capability_basic_information)
            g_array_unref (self->arg_capability_basic_information);
        if (self->arg_group_capability)
            g_array_unref (self->arg_group_capability);
        if (self->arg_additional_number_capability)
            g_array_unref (self->arg_additional_number_capability);
        if (self->arg_email_capability)
            g_array_unref (self->arg_email_capability);
        if (self->arg_second_name_capability)
            g_array_unref (self->arg_second_name_capability);
        if (self->arg_hidden_records_capability)
            g_array_unref (self->arg_hidden_records_capability);
        if (self->arg_grouping_information_alpha_string_capability)
            g_array_unref (self->arg_grouping_information_alpha_string_capability);
        if (self->arg_additional_number_alpha_string_capability)
            g_array_unref (self->arg_additional_number_alpha_string_capability);
        g_slice_free (QmiMessagePbmGetAllCapabilitiesOutput, self);
    }
}

static gchar *
qmi_message_pbm_get_all_capabilities_output_capability_basic_information_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_CAPABILITY_BASIC_INFORMATION, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    {
        guint capability_basic_information_i;
        guint8 capability_basic_information_n_items;

        /* Read number of items in the array */
        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(capability_basic_information_n_items), &error))
            goto out;

        g_string_append (printable, "{");

        for (capability_basic_information_i = 0; capability_basic_information_i < capability_basic_information_n_items; capability_basic_information_i++) {
            g_string_append_printf (printable, " [%u] = '", capability_basic_information_i);
            g_string_append (printable, "[");
            g_string_append (printable, " session_type = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
#if defined  __QMI_PBM_SESSION_TYPE_IS_ENUM__
                g_string_append_printf (printable, "%s", qmi_pbm_session_type_get_string ((QmiPbmSessionType)tmp));
#elif defined  __QMI_PBM_SESSION_TYPE_IS_FLAGS__
                {
                    g_autofree gchar *flags_str = NULL;

                    flags_str = qmi_pbm_session_type_build_string_from_mask ((QmiPbmSessionType)tmp);
                    g_string_append_printf (printable, "%s", flags_str);
                }
#else
# error unexpected public format: QmiPbmSessionType
#endif
            }
            g_string_append (printable, "'");
            g_string_append (printable, " phonebooks = '");
            {
                guint phonebooks_i;
                guint8 phonebooks_n_items;

                /* Read number of items in the array */
                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(phonebooks_n_items), &error))
                    goto out;

                g_string_append (printable, "{");

                for (phonebooks_i = 0; phonebooks_i < phonebooks_n_items; phonebooks_i++) {
                    g_string_append_printf (printable, " [%u] = '", phonebooks_i);
                    g_string_append (printable, "[");
                    g_string_append (printable, " phonebook_type = '");

                    {
                        guint16 tmp;

                        if (!qmi_message_tlv_read_guint16 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &tmp, &error))
                            goto out;
#if defined  __QMI_PBM_PHONEBOOK_TYPE_IS_ENUM__
                        g_string_append_printf (printable, "%s", qmi_pbm_phonebook_type_get_string ((QmiPbmPhonebookType)tmp));
#elif defined  __QMI_PBM_PHONEBOOK_TYPE_IS_FLAGS__
                        {
                            g_autofree gchar *flags_str = NULL;

                            flags_str = qmi_pbm_phonebook_type_build_string_from_mask ((QmiPbmPhonebookType)tmp);
                            g_string_append_printf (printable, "%s", flags_str);
                        }
#else
# error unexpected public format: QmiPbmPhonebookType
#endif
                    }
                    g_string_append (printable, "'");
                    g_string_append (printable, " used_records = '");

                    {
                        guint16 tmp;

                        if (!qmi_message_tlv_read_guint16 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &tmp, &error))
                            goto out;
                        g_string_append_printf (printable, "%" G_GUINT16_FORMAT "", tmp);
                    }
                    g_string_append (printable, "'");
                    g_string_append (printable, " maximum_records = '");

                    {
                        guint16 tmp;

                        if (!qmi_message_tlv_read_guint16 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &tmp, &error))
                            goto out;
                        g_string_append_printf (printable, "%" G_GUINT16_FORMAT "", tmp);
                    }
                    g_string_append (printable, "'");
                    g_string_append (printable, " maximum_number_length = '");

                    {
                        guint8 tmp;

                        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                            goto out;
                        g_string_append_printf (printable, "%u", (guint)tmp);
                    }
                    g_string_append (printable, "'");
                    g_string_append (printable, " maximum_name_length = '");

                    {
                        guint8 tmp;

                        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                            goto out;
                        g_string_append_printf (printable, "%u", (guint)tmp);
                    }
                    g_string_append (printable, "'");
                    g_string_append (printable, " ]");
                    g_string_append (printable, " '");
                }

                g_string_append (printable, "}");
            }            g_string_append (printable, "'");
            g_string_append (printable, " ]");
            g_string_append (printable, " '");
        }

        g_string_append (printable, "}");
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
qmi_message_pbm_get_all_capabilities_output_group_capability_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_GROUP_CAPABILITY, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    {
        guint group_capability_i;
        guint8 group_capability_n_items;

        /* Read number of items in the array */
        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(group_capability_n_items), &error))
            goto out;

        g_string_append (printable, "{");

        for (group_capability_i = 0; group_capability_i < group_capability_n_items; group_capability_i++) {
            g_string_append_printf (printable, " [%u] = '", group_capability_i);
            g_string_append (printable, "[");
            g_string_append (printable, " session_type = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
#if defined  __QMI_PBM_SESSION_TYPE_IS_ENUM__
                g_string_append_printf (printable, "%s", qmi_pbm_session_type_get_string ((QmiPbmSessionType)tmp));
#elif defined  __QMI_PBM_SESSION_TYPE_IS_FLAGS__
                {
                    g_autofree gchar *flags_str = NULL;

                    flags_str = qmi_pbm_session_type_build_string_from_mask ((QmiPbmSessionType)tmp);
                    g_string_append_printf (printable, "%s", flags_str);
                }
#else
# error unexpected public format: QmiPbmSessionType
#endif
            }
            g_string_append (printable, "'");
            g_string_append (printable, " maximum_groups = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
                g_string_append_printf (printable, "%u", (guint)tmp);
            }
            g_string_append (printable, "'");
            g_string_append (printable, " maximum_group_tag_length = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
                g_string_append_printf (printable, "%u", (guint)tmp);
            }
            g_string_append (printable, "'");
            g_string_append (printable, " ]");
            g_string_append (printable, " '");
        }

        g_string_append (printable, "}");
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
qmi_message_pbm_get_all_capabilities_output_additional_number_capability_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_ADDITIONAL_NUMBER_CAPABILITY, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    {
        guint additional_number_capability_i;
        guint8 additional_number_capability_n_items;

        /* Read number of items in the array */
        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(additional_number_capability_n_items), &error))
            goto out;

        g_string_append (printable, "{");

        for (additional_number_capability_i = 0; additional_number_capability_i < additional_number_capability_n_items; additional_number_capability_i++) {
            g_string_append_printf (printable, " [%u] = '", additional_number_capability_i);
            g_string_append (printable, "[");
            g_string_append (printable, " session_type = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
#if defined  __QMI_PBM_SESSION_TYPE_IS_ENUM__
                g_string_append_printf (printable, "%s", qmi_pbm_session_type_get_string ((QmiPbmSessionType)tmp));
#elif defined  __QMI_PBM_SESSION_TYPE_IS_FLAGS__
                {
                    g_autofree gchar *flags_str = NULL;

                    flags_str = qmi_pbm_session_type_build_string_from_mask ((QmiPbmSessionType)tmp);
                    g_string_append_printf (printable, "%s", flags_str);
                }
#else
# error unexpected public format: QmiPbmSessionType
#endif
            }
            g_string_append (printable, "'");
            g_string_append (printable, " maximum_additional_numbers = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
                g_string_append_printf (printable, "%u", (guint)tmp);
            }
            g_string_append (printable, "'");
            g_string_append (printable, " maximum_additional_number_length = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
                g_string_append_printf (printable, "%u", (guint)tmp);
            }
            g_string_append (printable, "'");
            g_string_append (printable, " maximum_additional_number_tag_length = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
                g_string_append_printf (printable, "%u", (guint)tmp);
            }
            g_string_append (printable, "'");
            g_string_append (printable, " ]");
            g_string_append (printable, " '");
        }

        g_string_append (printable, "}");
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
qmi_message_pbm_get_all_capabilities_output_email_capability_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_EMAIL_CAPABILITY, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    {
        guint email_capability_i;
        guint8 email_capability_n_items;

        /* Read number of items in the array */
        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(email_capability_n_items), &error))
            goto out;

        g_string_append (printable, "{");

        for (email_capability_i = 0; email_capability_i < email_capability_n_items; email_capability_i++) {
            g_string_append_printf (printable, " [%u] = '", email_capability_i);
            g_string_append (printable, "[");
            g_string_append (printable, " session_type = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
#if defined  __QMI_PBM_SESSION_TYPE_IS_ENUM__
                g_string_append_printf (printable, "%s", qmi_pbm_session_type_get_string ((QmiPbmSessionType)tmp));
#elif defined  __QMI_PBM_SESSION_TYPE_IS_FLAGS__
                {
                    g_autofree gchar *flags_str = NULL;

                    flags_str = qmi_pbm_session_type_build_string_from_mask ((QmiPbmSessionType)tmp);
                    g_string_append_printf (printable, "%s", flags_str);
                }
#else
# error unexpected public format: QmiPbmSessionType
#endif
            }
            g_string_append (printable, "'");
            g_string_append (printable, " maximum_emails = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
                g_string_append_printf (printable, "%u", (guint)tmp);
            }
            g_string_append (printable, "'");
            g_string_append (printable, " maximum_email_address_length = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
                g_string_append_printf (printable, "%u", (guint)tmp);
            }
            g_string_append (printable, "'");
            g_string_append (printable, " ]");
            g_string_append (printable, " '");
        }

        g_string_append (printable, "}");
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
qmi_message_pbm_get_all_capabilities_output_second_name_capability_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_SECOND_NAME_CAPABILITY, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    {
        guint second_name_capability_i;
        guint8 second_name_capability_n_items;

        /* Read number of items in the array */
        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(second_name_capability_n_items), &error))
            goto out;

        g_string_append (printable, "{");

        for (second_name_capability_i = 0; second_name_capability_i < second_name_capability_n_items; second_name_capability_i++) {
            g_string_append_printf (printable, " [%u] = '", second_name_capability_i);
            g_string_append (printable, "[");
            g_string_append (printable, " session_type = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
#if defined  __QMI_PBM_SESSION_TYPE_IS_ENUM__
                g_string_append_printf (printable, "%s", qmi_pbm_session_type_get_string ((QmiPbmSessionType)tmp));
#elif defined  __QMI_PBM_SESSION_TYPE_IS_FLAGS__
                {
                    g_autofree gchar *flags_str = NULL;

                    flags_str = qmi_pbm_session_type_build_string_from_mask ((QmiPbmSessionType)tmp);
                    g_string_append_printf (printable, "%s", flags_str);
                }
#else
# error unexpected public format: QmiPbmSessionType
#endif
            }
            g_string_append (printable, "'");
            g_string_append (printable, " maximum_second_name_length = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
                g_string_append_printf (printable, "%u", (guint)tmp);
            }
            g_string_append (printable, "'");
            g_string_append (printable, " ]");
            g_string_append (printable, " '");
        }

        g_string_append (printable, "}");
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
qmi_message_pbm_get_all_capabilities_output_hidden_records_capability_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_HIDDEN_RECORDS_CAPABILITY, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    {
        guint hidden_records_capability_i;
        guint8 hidden_records_capability_n_items;

        /* Read number of items in the array */
        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(hidden_records_capability_n_items), &error))
            goto out;

        g_string_append (printable, "{");

        for (hidden_records_capability_i = 0; hidden_records_capability_i < hidden_records_capability_n_items; hidden_records_capability_i++) {
            g_string_append_printf (printable, " [%u] = '", hidden_records_capability_i);
            g_string_append (printable, "[");
            g_string_append (printable, " session_type = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
#if defined  __QMI_PBM_SESSION_TYPE_IS_ENUM__
                g_string_append_printf (printable, "%s", qmi_pbm_session_type_get_string ((QmiPbmSessionType)tmp));
#elif defined  __QMI_PBM_SESSION_TYPE_IS_FLAGS__
                {
                    g_autofree gchar *flags_str = NULL;

                    flags_str = qmi_pbm_session_type_build_string_from_mask ((QmiPbmSessionType)tmp);
                    g_string_append_printf (printable, "%s", flags_str);
                }
#else
# error unexpected public format: QmiPbmSessionType
#endif
            }
            g_string_append (printable, "'");
            g_string_append (printable, " supported = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
                g_string_append_printf (printable, "%s", tmp ? "yes" : "no");
            }
            g_string_append (printable, "'");
            g_string_append (printable, " ]");
            g_string_append (printable, " '");
        }

        g_string_append (printable, "}");
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
qmi_message_pbm_get_all_capabilities_output_grouping_information_alpha_string_capability_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_GROUPING_INFORMATION_ALPHA_STRING_CAPABILITY, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    {
        guint grouping_information_alpha_string_capability_i;
        guint8 grouping_information_alpha_string_capability_n_items;

        /* Read number of items in the array */
        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(grouping_information_alpha_string_capability_n_items), &error))
            goto out;

        g_string_append (printable, "{");

        for (grouping_information_alpha_string_capability_i = 0; grouping_information_alpha_string_capability_i < grouping_information_alpha_string_capability_n_items; grouping_information_alpha_string_capability_i++) {
            g_string_append_printf (printable, " [%u] = '", grouping_information_alpha_string_capability_i);
            g_string_append (printable, "[");
            g_string_append (printable, " session_type = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
#if defined  __QMI_PBM_SESSION_TYPE_IS_ENUM__
                g_string_append_printf (printable, "%s", qmi_pbm_session_type_get_string ((QmiPbmSessionType)tmp));
#elif defined  __QMI_PBM_SESSION_TYPE_IS_FLAGS__
                {
                    g_autofree gchar *flags_str = NULL;

                    flags_str = qmi_pbm_session_type_build_string_from_mask ((QmiPbmSessionType)tmp);
                    g_string_append_printf (printable, "%s", flags_str);
                }
#else
# error unexpected public format: QmiPbmSessionType
#endif
            }
            g_string_append (printable, "'");
            g_string_append (printable, " maximum_records = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
                g_string_append_printf (printable, "%u", (guint)tmp);
            }
            g_string_append (printable, "'");
            g_string_append (printable, " used_records = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
                g_string_append_printf (printable, "%u", (guint)tmp);
            }
            g_string_append (printable, "'");
            g_string_append (printable, " maximum_string_length = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
                g_string_append_printf (printable, "%u", (guint)tmp);
            }
            g_string_append (printable, "'");
            g_string_append (printable, " ]");
            g_string_append (printable, " '");
        }

        g_string_append (printable, "}");
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
qmi_message_pbm_get_all_capabilities_output_additional_number_alpha_string_capability_get_printable (
    QmiMessage *message,
    const gchar *line_prefix)
{
    gsize offset = 0;
    gsize init_offset;
    GString *printable;
    GError *error = NULL;

    if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_ADDITIONAL_NUMBER_ALPHA_STRING_CAPABILITY, NULL, NULL)) == 0)
        return NULL;

    printable = g_string_new ("");
    {
        guint additional_number_alpha_string_capability_i;
        guint8 additional_number_alpha_string_capability_n_items;

        /* Read number of items in the array */
        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(additional_number_alpha_string_capability_n_items), &error))
            goto out;

        g_string_append (printable, "{");

        for (additional_number_alpha_string_capability_i = 0; additional_number_alpha_string_capability_i < additional_number_alpha_string_capability_n_items; additional_number_alpha_string_capability_i++) {
            g_string_append_printf (printable, " [%u] = '", additional_number_alpha_string_capability_i);
            g_string_append (printable, "[");
            g_string_append (printable, " session_type = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
#if defined  __QMI_PBM_SESSION_TYPE_IS_ENUM__
                g_string_append_printf (printable, "%s", qmi_pbm_session_type_get_string ((QmiPbmSessionType)tmp));
#elif defined  __QMI_PBM_SESSION_TYPE_IS_FLAGS__
                {
                    g_autofree gchar *flags_str = NULL;

                    flags_str = qmi_pbm_session_type_build_string_from_mask ((QmiPbmSessionType)tmp);
                    g_string_append_printf (printable, "%s", flags_str);
                }
#else
# error unexpected public format: QmiPbmSessionType
#endif
            }
            g_string_append (printable, "'");
            g_string_append (printable, " maximum_records = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
                g_string_append_printf (printable, "%u", (guint)tmp);
            }
            g_string_append (printable, "'");
            g_string_append (printable, " used_records = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
                g_string_append_printf (printable, "%u", (guint)tmp);
            }
            g_string_append (printable, "'");
            g_string_append (printable, " maximum_string_length = '");

            {
                guint8 tmp;

                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, &error))
                    goto out;
                g_string_append_printf (printable, "%u", (guint)tmp);
            }
            g_string_append (printable, "'");
            g_string_append (printable, " ]");
            g_string_append (printable, " '");
        }

        g_string_append (printable, "}");
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

struct message_get_all_capabilities_context {
    QmiMessage *self;
    const gchar *line_prefix;
    GString *printable;
};

static void
message_get_all_capabilities_get_tlv_printable (
    guint8 type,
    const guint8 *value,
    gsize length,
    struct message_get_all_capabilities_context *ctx)
{
    const gchar *tlv_type_str = NULL;
    g_autofree gchar *translated_value = NULL;

    if (!qmi_message_is_response (ctx->self)) {
        switch (type) {
        default:
            break;
        }
    } else {
        switch (type) {
        case QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_RESULT:
            tlv_type_str = "Result";
            translated_value = qmi_message_result_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_CAPABILITY_BASIC_INFORMATION:
            tlv_type_str = "Capability Basic Information";
            translated_value = qmi_message_pbm_get_all_capabilities_output_capability_basic_information_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_GROUP_CAPABILITY:
            tlv_type_str = "Group Capability";
            translated_value = qmi_message_pbm_get_all_capabilities_output_group_capability_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_ADDITIONAL_NUMBER_CAPABILITY:
            tlv_type_str = "Additional Number Capability";
            translated_value = qmi_message_pbm_get_all_capabilities_output_additional_number_capability_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_EMAIL_CAPABILITY:
            tlv_type_str = "Email Capability";
            translated_value = qmi_message_pbm_get_all_capabilities_output_email_capability_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_SECOND_NAME_CAPABILITY:
            tlv_type_str = "Second Name Capability";
            translated_value = qmi_message_pbm_get_all_capabilities_output_second_name_capability_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_HIDDEN_RECORDS_CAPABILITY:
            tlv_type_str = "Hidden Records Capability";
            translated_value = qmi_message_pbm_get_all_capabilities_output_hidden_records_capability_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_GROUPING_INFORMATION_ALPHA_STRING_CAPABILITY:
            tlv_type_str = "Grouping Information Alpha String Capability";
            translated_value = qmi_message_pbm_get_all_capabilities_output_grouping_information_alpha_string_capability_get_printable (
                                   ctx->self,
                                   ctx->line_prefix);
            break;
        case QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_ADDITIONAL_NUMBER_ALPHA_STRING_CAPABILITY:
            tlv_type_str = "Additional Number Alpha String Capability";
            translated_value = qmi_message_pbm_get_all_capabilities_output_additional_number_alpha_string_capability_get_printable (
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
message_get_all_capabilities_get_printable (
    QmiMessage *self,
    const gchar *line_prefix)
{
    GString *printable;

    printable = g_string_new ("");
    g_string_append_printf (printable,
                            "%s  message     = \"Get All Capabilities\" (0x0003)\n",
                            line_prefix);

    {
        struct message_get_all_capabilities_context ctx;
        ctx.self = self;
        ctx.line_prefix = line_prefix;
        ctx.printable = printable;
        qmi_message_foreach_raw_tlv (self,
                                     (QmiMessageForeachRawTlvFn)message_get_all_capabilities_get_tlv_printable,
                                     &ctx);
    }

    return g_string_free (printable, FALSE);
}

static QmiMessagePbmGetAllCapabilitiesOutput *
__qmi_message_pbm_get_all_capabilities_response_parse (
    QmiMessage *message,
    GError **error)
{
    QmiMessagePbmGetAllCapabilitiesOutput *self;

    g_assert_cmphex (qmi_message_get_message_id (message), ==, QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES);

    self = g_slice_new0 (QmiMessagePbmGetAllCapabilitiesOutput);
    self->ref_count = 1;

    do {
        /* No Prerequisites for field */

        {
            gsize offset = 0;
            gsize init_offset;

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_RESULT, NULL, error)) == 0) {
                g_prefix_error (error, "Couldn't get the mandatory Result TLV: ");
                qmi_message_pbm_get_all_capabilities_output_unref (self);
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
                qmi_message_pbm_get_all_capabilities_output_unref (self);
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

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_CAPABILITY_BASIC_INFORMATION, NULL, NULL)) == 0) {
                goto qmi_message_pbm_get_all_capabilities_output_capability_basic_information_out;
            }
            {
                guint capability_basic_information_i;
                guint8 capability_basic_information_n_items;

                /* Read number of items in the array */
                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(capability_basic_information_n_items), NULL))
                    goto qmi_message_pbm_get_all_capabilities_output_capability_basic_information_out;

                self->arg_capability_basic_information = g_array_sized_new (
                    FALSE,
                    FALSE,
                    sizeof (QmiMessagePbmGetAllCapabilitiesOutputCapabilityBasicInformationElement),
                    (guint)capability_basic_information_n_items);

                g_array_set_clear_func (self->arg_capability_basic_information,
                                        (GDestroyNotify)capability_basic_information_qmimessagepbmgetallcapabilitiesoutputcapabilitybasicinformationelement_clear);

                for (capability_basic_information_i = 0; capability_basic_information_i < capability_basic_information_n_items; capability_basic_information_i++) {
                    QmiMessagePbmGetAllCapabilitiesOutputCapabilityBasicInformationElement capability_basic_information_aux;

                    {
                        guint8 tmp;

                        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, NULL))
                            goto qmi_message_pbm_get_all_capabilities_output_capability_basic_information_out;
                        capability_basic_information_aux.session_type = (QmiPbmSessionType)tmp;
                    }
                    {
                        guint phonebooks_i;
                        guint8 phonebooks_n_items;

                        /* Read number of items in the array */
                        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(phonebooks_n_items), NULL))
                            goto qmi_message_pbm_get_all_capabilities_output_capability_basic_information_out;

                        capability_basic_information_aux.phonebooks = g_array_sized_new (
                            FALSE,
                            FALSE,
                            sizeof (QmiMessagePbmGetAllCapabilitiesOutputCapabilityBasicInformationElementPhonebooksElement),
                            (guint)phonebooks_n_items);

                        for (phonebooks_i = 0; phonebooks_i < phonebooks_n_items; phonebooks_i++) {
                            QmiMessagePbmGetAllCapabilitiesOutputCapabilityBasicInformationElementPhonebooksElement phonebooks_aux;

                            {
                                guint16 tmp;

                                if (!qmi_message_tlv_read_guint16 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &tmp, NULL))
                                    goto qmi_message_pbm_get_all_capabilities_output_capability_basic_information_out;
                                phonebooks_aux.phonebook_type = (QmiPbmPhonebookType)tmp;
                            }
                            if (!qmi_message_tlv_read_guint16 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &(phonebooks_aux.used_records), NULL))
                                goto qmi_message_pbm_get_all_capabilities_output_capability_basic_information_out;
                            if (!qmi_message_tlv_read_guint16 (message, init_offset, &offset, QMI_ENDIAN_LITTLE, &(phonebooks_aux.maximum_records), NULL))
                                goto qmi_message_pbm_get_all_capabilities_output_capability_basic_information_out;
                            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(phonebooks_aux.maximum_number_length), NULL))
                                goto qmi_message_pbm_get_all_capabilities_output_capability_basic_information_out;
                            if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(phonebooks_aux.maximum_name_length), NULL))
                                goto qmi_message_pbm_get_all_capabilities_output_capability_basic_information_out;
                            g_array_insert_val (capability_basic_information_aux.phonebooks, phonebooks_i, phonebooks_aux);
                        }
                    }
                    g_array_insert_val (self->arg_capability_basic_information, capability_basic_information_i, capability_basic_information_aux);
                }
            }

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Capability Basic Information' TLV", offset);
            }

            self->arg_capability_basic_information_set = TRUE;

qmi_message_pbm_get_all_capabilities_output_capability_basic_information_out:
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

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_GROUP_CAPABILITY, NULL, NULL)) == 0) {
                goto qmi_message_pbm_get_all_capabilities_output_group_capability_out;
            }
            {
                guint group_capability_i;
                guint8 group_capability_n_items;

                /* Read number of items in the array */
                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(group_capability_n_items), NULL))
                    goto qmi_message_pbm_get_all_capabilities_output_group_capability_out;

                self->arg_group_capability = g_array_sized_new (
                    FALSE,
                    FALSE,
                    sizeof (QmiMessagePbmGetAllCapabilitiesOutputGroupCapabilityElement),
                    (guint)group_capability_n_items);

                for (group_capability_i = 0; group_capability_i < group_capability_n_items; group_capability_i++) {
                    QmiMessagePbmGetAllCapabilitiesOutputGroupCapabilityElement group_capability_aux;

                    {
                        guint8 tmp;

                        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, NULL))
                            goto qmi_message_pbm_get_all_capabilities_output_group_capability_out;
                        group_capability_aux.session_type = (QmiPbmSessionType)tmp;
                    }
                    if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(group_capability_aux.maximum_groups), NULL))
                        goto qmi_message_pbm_get_all_capabilities_output_group_capability_out;
                    if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(group_capability_aux.maximum_group_tag_length), NULL))
                        goto qmi_message_pbm_get_all_capabilities_output_group_capability_out;
                    g_array_insert_val (self->arg_group_capability, group_capability_i, group_capability_aux);
                }
            }

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Group Capability' TLV", offset);
            }

            self->arg_group_capability_set = TRUE;

qmi_message_pbm_get_all_capabilities_output_group_capability_out:
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

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_ADDITIONAL_NUMBER_CAPABILITY, NULL, NULL)) == 0) {
                goto qmi_message_pbm_get_all_capabilities_output_additional_number_capability_out;
            }
            {
                guint additional_number_capability_i;
                guint8 additional_number_capability_n_items;

                /* Read number of items in the array */
                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(additional_number_capability_n_items), NULL))
                    goto qmi_message_pbm_get_all_capabilities_output_additional_number_capability_out;

                self->arg_additional_number_capability = g_array_sized_new (
                    FALSE,
                    FALSE,
                    sizeof (QmiMessagePbmGetAllCapabilitiesOutputAdditionalNumberCapabilityElement),
                    (guint)additional_number_capability_n_items);

                for (additional_number_capability_i = 0; additional_number_capability_i < additional_number_capability_n_items; additional_number_capability_i++) {
                    QmiMessagePbmGetAllCapabilitiesOutputAdditionalNumberCapabilityElement additional_number_capability_aux;

                    {
                        guint8 tmp;

                        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, NULL))
                            goto qmi_message_pbm_get_all_capabilities_output_additional_number_capability_out;
                        additional_number_capability_aux.session_type = (QmiPbmSessionType)tmp;
                    }
                    if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(additional_number_capability_aux.maximum_additional_numbers), NULL))
                        goto qmi_message_pbm_get_all_capabilities_output_additional_number_capability_out;
                    if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(additional_number_capability_aux.maximum_additional_number_length), NULL))
                        goto qmi_message_pbm_get_all_capabilities_output_additional_number_capability_out;
                    if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(additional_number_capability_aux.maximum_additional_number_tag_length), NULL))
                        goto qmi_message_pbm_get_all_capabilities_output_additional_number_capability_out;
                    g_array_insert_val (self->arg_additional_number_capability, additional_number_capability_i, additional_number_capability_aux);
                }
            }

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Additional Number Capability' TLV", offset);
            }

            self->arg_additional_number_capability_set = TRUE;

qmi_message_pbm_get_all_capabilities_output_additional_number_capability_out:
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

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_EMAIL_CAPABILITY, NULL, NULL)) == 0) {
                goto qmi_message_pbm_get_all_capabilities_output_email_capability_out;
            }
            {
                guint email_capability_i;
                guint8 email_capability_n_items;

                /* Read number of items in the array */
                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(email_capability_n_items), NULL))
                    goto qmi_message_pbm_get_all_capabilities_output_email_capability_out;

                self->arg_email_capability = g_array_sized_new (
                    FALSE,
                    FALSE,
                    sizeof (QmiMessagePbmGetAllCapabilitiesOutputEmailCapabilityElement),
                    (guint)email_capability_n_items);

                for (email_capability_i = 0; email_capability_i < email_capability_n_items; email_capability_i++) {
                    QmiMessagePbmGetAllCapabilitiesOutputEmailCapabilityElement email_capability_aux;

                    {
                        guint8 tmp;

                        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, NULL))
                            goto qmi_message_pbm_get_all_capabilities_output_email_capability_out;
                        email_capability_aux.session_type = (QmiPbmSessionType)tmp;
                    }
                    if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(email_capability_aux.maximum_emails), NULL))
                        goto qmi_message_pbm_get_all_capabilities_output_email_capability_out;
                    if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(email_capability_aux.maximum_email_address_length), NULL))
                        goto qmi_message_pbm_get_all_capabilities_output_email_capability_out;
                    g_array_insert_val (self->arg_email_capability, email_capability_i, email_capability_aux);
                }
            }

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Email Capability' TLV", offset);
            }

            self->arg_email_capability_set = TRUE;

qmi_message_pbm_get_all_capabilities_output_email_capability_out:
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

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_SECOND_NAME_CAPABILITY, NULL, NULL)) == 0) {
                goto qmi_message_pbm_get_all_capabilities_output_second_name_capability_out;
            }
            {
                guint second_name_capability_i;
                guint8 second_name_capability_n_items;

                /* Read number of items in the array */
                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(second_name_capability_n_items), NULL))
                    goto qmi_message_pbm_get_all_capabilities_output_second_name_capability_out;

                self->arg_second_name_capability = g_array_sized_new (
                    FALSE,
                    FALSE,
                    sizeof (QmiMessagePbmGetAllCapabilitiesOutputSecondNameCapabilityElement),
                    (guint)second_name_capability_n_items);

                for (second_name_capability_i = 0; second_name_capability_i < second_name_capability_n_items; second_name_capability_i++) {
                    QmiMessagePbmGetAllCapabilitiesOutputSecondNameCapabilityElement second_name_capability_aux;

                    {
                        guint8 tmp;

                        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, NULL))
                            goto qmi_message_pbm_get_all_capabilities_output_second_name_capability_out;
                        second_name_capability_aux.session_type = (QmiPbmSessionType)tmp;
                    }
                    if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(second_name_capability_aux.maximum_second_name_length), NULL))
                        goto qmi_message_pbm_get_all_capabilities_output_second_name_capability_out;
                    g_array_insert_val (self->arg_second_name_capability, second_name_capability_i, second_name_capability_aux);
                }
            }

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Second Name Capability' TLV", offset);
            }

            self->arg_second_name_capability_set = TRUE;

qmi_message_pbm_get_all_capabilities_output_second_name_capability_out:
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

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_HIDDEN_RECORDS_CAPABILITY, NULL, NULL)) == 0) {
                goto qmi_message_pbm_get_all_capabilities_output_hidden_records_capability_out;
            }
            {
                guint hidden_records_capability_i;
                guint8 hidden_records_capability_n_items;

                /* Read number of items in the array */
                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(hidden_records_capability_n_items), NULL))
                    goto qmi_message_pbm_get_all_capabilities_output_hidden_records_capability_out;

                self->arg_hidden_records_capability = g_array_sized_new (
                    FALSE,
                    FALSE,
                    sizeof (QmiMessagePbmGetAllCapabilitiesOutputHiddenRecordsCapabilityElement),
                    (guint)hidden_records_capability_n_items);

                for (hidden_records_capability_i = 0; hidden_records_capability_i < hidden_records_capability_n_items; hidden_records_capability_i++) {
                    QmiMessagePbmGetAllCapabilitiesOutputHiddenRecordsCapabilityElement hidden_records_capability_aux;

                    {
                        guint8 tmp;

                        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, NULL))
                            goto qmi_message_pbm_get_all_capabilities_output_hidden_records_capability_out;
                        hidden_records_capability_aux.session_type = (QmiPbmSessionType)tmp;
                    }
                    {
                        guint8 tmp;

                        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, NULL))
                            goto qmi_message_pbm_get_all_capabilities_output_hidden_records_capability_out;
                        hidden_records_capability_aux.supported = (gboolean)tmp;
                    }
                    g_array_insert_val (self->arg_hidden_records_capability, hidden_records_capability_i, hidden_records_capability_aux);
                }
            }

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Hidden Records Capability' TLV", offset);
            }

            self->arg_hidden_records_capability_set = TRUE;

qmi_message_pbm_get_all_capabilities_output_hidden_records_capability_out:
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

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_GROUPING_INFORMATION_ALPHA_STRING_CAPABILITY, NULL, NULL)) == 0) {
                goto qmi_message_pbm_get_all_capabilities_output_grouping_information_alpha_string_capability_out;
            }
            {
                guint grouping_information_alpha_string_capability_i;
                guint8 grouping_information_alpha_string_capability_n_items;

                /* Read number of items in the array */
                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(grouping_information_alpha_string_capability_n_items), NULL))
                    goto qmi_message_pbm_get_all_capabilities_output_grouping_information_alpha_string_capability_out;

                self->arg_grouping_information_alpha_string_capability = g_array_sized_new (
                    FALSE,
                    FALSE,
                    sizeof (QmiMessagePbmGetAllCapabilitiesOutputGroupingInformationAlphaStringCapabilityElement),
                    (guint)grouping_information_alpha_string_capability_n_items);

                for (grouping_information_alpha_string_capability_i = 0; grouping_information_alpha_string_capability_i < grouping_information_alpha_string_capability_n_items; grouping_information_alpha_string_capability_i++) {
                    QmiMessagePbmGetAllCapabilitiesOutputGroupingInformationAlphaStringCapabilityElement grouping_information_alpha_string_capability_aux;

                    {
                        guint8 tmp;

                        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, NULL))
                            goto qmi_message_pbm_get_all_capabilities_output_grouping_information_alpha_string_capability_out;
                        grouping_information_alpha_string_capability_aux.session_type = (QmiPbmSessionType)tmp;
                    }
                    if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(grouping_information_alpha_string_capability_aux.maximum_records), NULL))
                        goto qmi_message_pbm_get_all_capabilities_output_grouping_information_alpha_string_capability_out;
                    if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(grouping_information_alpha_string_capability_aux.used_records), NULL))
                        goto qmi_message_pbm_get_all_capabilities_output_grouping_information_alpha_string_capability_out;
                    if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(grouping_information_alpha_string_capability_aux.maximum_string_length), NULL))
                        goto qmi_message_pbm_get_all_capabilities_output_grouping_information_alpha_string_capability_out;
                    g_array_insert_val (self->arg_grouping_information_alpha_string_capability, grouping_information_alpha_string_capability_i, grouping_information_alpha_string_capability_aux);
                }
            }

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Grouping Information Alpha String Capability' TLV", offset);
            }

            self->arg_grouping_information_alpha_string_capability_set = TRUE;

qmi_message_pbm_get_all_capabilities_output_grouping_information_alpha_string_capability_out:
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

            if ((init_offset = qmi_message_tlv_read_init (message, QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES_OUTPUT_TLV_ADDITIONAL_NUMBER_ALPHA_STRING_CAPABILITY, NULL, NULL)) == 0) {
                goto qmi_message_pbm_get_all_capabilities_output_additional_number_alpha_string_capability_out;
            }
            {
                guint additional_number_alpha_string_capability_i;
                guint8 additional_number_alpha_string_capability_n_items;

                /* Read number of items in the array */
                if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(additional_number_alpha_string_capability_n_items), NULL))
                    goto qmi_message_pbm_get_all_capabilities_output_additional_number_alpha_string_capability_out;

                self->arg_additional_number_alpha_string_capability = g_array_sized_new (
                    FALSE,
                    FALSE,
                    sizeof (QmiMessagePbmGetAllCapabilitiesOutputAdditionalNumberAlphaStringCapabilityElement),
                    (guint)additional_number_alpha_string_capability_n_items);

                for (additional_number_alpha_string_capability_i = 0; additional_number_alpha_string_capability_i < additional_number_alpha_string_capability_n_items; additional_number_alpha_string_capability_i++) {
                    QmiMessagePbmGetAllCapabilitiesOutputAdditionalNumberAlphaStringCapabilityElement additional_number_alpha_string_capability_aux;

                    {
                        guint8 tmp;

                        if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &tmp, NULL))
                            goto qmi_message_pbm_get_all_capabilities_output_additional_number_alpha_string_capability_out;
                        additional_number_alpha_string_capability_aux.session_type = (QmiPbmSessionType)tmp;
                    }
                    if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(additional_number_alpha_string_capability_aux.maximum_records), NULL))
                        goto qmi_message_pbm_get_all_capabilities_output_additional_number_alpha_string_capability_out;
                    if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(additional_number_alpha_string_capability_aux.used_records), NULL))
                        goto qmi_message_pbm_get_all_capabilities_output_additional_number_alpha_string_capability_out;
                    if (!qmi_message_tlv_read_guint8 (message, init_offset, &offset, &(additional_number_alpha_string_capability_aux.maximum_string_length), NULL))
                        goto qmi_message_pbm_get_all_capabilities_output_additional_number_alpha_string_capability_out;
                    g_array_insert_val (self->arg_additional_number_alpha_string_capability, additional_number_alpha_string_capability_i, additional_number_alpha_string_capability_aux);
                }
            }

            /* The remaining size of the buffer needs to be 0 if we successfully read the TLV */
            if ((offset = qmi_message_tlv_read_remaining_size (message, init_offset, offset)) > 0) {
                g_warning ("Left '%" G_GSIZE_FORMAT "' bytes unread when getting the 'Additional Number Alpha String Capability' TLV", offset);
            }

            self->arg_additional_number_alpha_string_capability_set = TRUE;

qmi_message_pbm_get_all_capabilities_output_additional_number_alpha_string_capability_out:
            ;

        }
    } while (0);

    return self;
}

/*****************************************************************************/
/* Service-specific utils: PBM */


gchar *
__qmi_message_pbm_get_printable (
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
            case QMI_MESSAGE_PBM_INDICATION_REGISTER:
                return message_indication_register_get_printable (self, line_prefix);
            case QMI_MESSAGE_PBM_GET_CAPABILITIES:
                return message_get_capabilities_get_printable (self, line_prefix);
            case QMI_MESSAGE_PBM_GET_ALL_CAPABILITIES:
                return message_get_all_capabilities_get_printable (self, line_prefix);
             default:
                 return NULL;
            }
        } else {
            return NULL;
        }
    }
}

/*****************************************************************************/
/* CLIENT: QMI Client PBM */


/**
 * SECTION: qmi-client-pbm
 * @title: QmiClientPbm
 * @short_description: #QmiClient for the PBM service.
 *
 * #QmiClient which handles operations in the PBM service.
 */

G_DEFINE_TYPE (QmiClientPbm, qmi_client_pbm, QMI_TYPE_CLIENT)

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
qmi_client_pbm_init (QmiClientPbm *self)
{
}

static void
qmi_client_pbm_class_init (QmiClientPbmClass *klass)
{
    QmiClientClass *client_class = QMI_CLIENT_CLASS (klass);

    client_class->process_indication = process_indication;
}


QmiMessagePbmIndicationRegisterOutput *
qmi_client_pbm_indication_register_finish (
    QmiClientPbm *self,
    GAsyncResult *res,
    GError **error)
{
   return g_task_propagate_pointer (G_TASK (res), error);
}

static void
indication_register_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GTask *task)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessagePbmIndicationRegisterOutput *output;

    reply = qmi_device_command_full_finish (device, res, &error);
    if (!reply) {
        g_task_return_error (task, error);
        g_object_unref (task);
        return;
    }

    /* Parse reply */
    output = __qmi_message_pbm_indication_register_response_parse (reply, &error);
    if (!output)
        g_task_return_error (task, error);
    else
        g_task_return_pointer (task,
                               output,
                               (GDestroyNotify)qmi_message_pbm_indication_register_output_unref);
    g_object_unref (task);
    qmi_message_unref (reply);
}

void
qmi_client_pbm_indication_register (
    QmiClientPbm *self,
    QmiMessagePbmIndicationRegisterInput *input,
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

    request = __qmi_message_pbm_indication_register_request_create (
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
                             (GAsyncReadyCallback)indication_register_ready,
                             task);
}


QmiMessagePbmGetCapabilitiesOutput *
qmi_client_pbm_get_capabilities_finish (
    QmiClientPbm *self,
    GAsyncResult *res,
    GError **error)
{
   return g_task_propagate_pointer (G_TASK (res), error);
}

static void
get_capabilities_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GTask *task)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessagePbmGetCapabilitiesOutput *output;

    reply = qmi_device_command_full_finish (device, res, &error);
    if (!reply) {
        g_task_return_error (task, error);
        g_object_unref (task);
        return;
    }

    /* Parse reply */
    output = __qmi_message_pbm_get_capabilities_response_parse (reply, &error);
    if (!output)
        g_task_return_error (task, error);
    else
        g_task_return_pointer (task,
                               output,
                               (GDestroyNotify)qmi_message_pbm_get_capabilities_output_unref);
    g_object_unref (task);
    qmi_message_unref (reply);
}

void
qmi_client_pbm_get_capabilities (
    QmiClientPbm *self,
    QmiMessagePbmGetCapabilitiesInput *input,
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

    request = __qmi_message_pbm_get_capabilities_request_create (
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
                             (GAsyncReadyCallback)get_capabilities_ready,
                             task);
}


QmiMessagePbmGetAllCapabilitiesOutput *
qmi_client_pbm_get_all_capabilities_finish (
    QmiClientPbm *self,
    GAsyncResult *res,
    GError **error)
{
   return g_task_propagate_pointer (G_TASK (res), error);
}

static void
get_all_capabilities_ready (
    QmiDevice *device,
    GAsyncResult *res,
    GTask *task)
{
    GError *error = NULL;
    QmiMessage *reply;
    QmiMessagePbmGetAllCapabilitiesOutput *output;

    reply = qmi_device_command_full_finish (device, res, &error);
    if (!reply) {
        g_task_return_error (task, error);
        g_object_unref (task);
        return;
    }

    /* Parse reply */
    output = __qmi_message_pbm_get_all_capabilities_response_parse (reply, &error);
    if (!output)
        g_task_return_error (task, error);
    else
        g_task_return_pointer (task,
                               output,
                               (GDestroyNotify)qmi_message_pbm_get_all_capabilities_output_unref);
    g_object_unref (task);
    qmi_message_unref (reply);
}

void
qmi_client_pbm_get_all_capabilities (
    QmiClientPbm *self,
    gpointer unused,
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

    request = __qmi_message_pbm_get_all_capabilities_request_create (
                  transaction_id,
                  qmi_client_get_cid (QMI_CLIENT (self)),
                  NULL,
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
                             (GAsyncReadyCallback)get_all_capabilities_ready,
                             task);
}

