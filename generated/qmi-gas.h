
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


#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>

#include "qmi-enums.h"
#include "qmi-enums-gas.h"
#include "qmi-message.h"
#include "qmi-client.h"

#ifndef __LIBQMI_GLIB_QMI_GAS__
#define __LIBQMI_GLIB_QMI_GAS__

G_BEGIN_DECLS

#define HAVE_QMI_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE
#define HAVE_QMI_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message GAS DMS Set Active Firmware */


/* --- Input -- */

/**
 * QmiMessageGasDmsSetActiveFirmwareInput:
 *
 * The #QmiMessageGasDmsSetActiveFirmwareInput structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.24
 */
typedef struct _QmiMessageGasDmsSetActiveFirmwareInput QmiMessageGasDmsSetActiveFirmwareInput;
GType qmi_message_gas_dms_set_active_firmware_input_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE_INPUT (qmi_message_gas_dms_set_active_firmware_input_get_type ())


/**
 * qmi_message_gas_dms_set_active_firmware_input_get_version:
 * @self: a #QmiMessageGasDmsSetActiveFirmwareInput.
 * @value_version: (out)(optional)(transfer none): a placeholder for the output constant string, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Version' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_set_active_firmware_input_get_version (
    QmiMessageGasDmsSetActiveFirmwareInput *self,
    const gchar **value_version,
    GError **error);


/**
 * qmi_message_gas_dms_set_active_firmware_input_set_version:
 * @self: a #QmiMessageGasDmsSetActiveFirmwareInput.
 * @value_version: a constant string.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Version' field in the message.
 *
 * Returns: (skip): %TRUE if @value was successfully set, %FALSE otherwise.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_set_active_firmware_input_set_version (
    QmiMessageGasDmsSetActiveFirmwareInput *self,
    const gchar *value_version,
    GError **error);


/**
 * qmi_message_gas_dms_set_active_firmware_input_get_slot_index:
 * @self: a #QmiMessageGasDmsSetActiveFirmwareInput.
 * @value_slot_index: (out)(optional): a placeholder for the output #guint8, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Slot Index' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_set_active_firmware_input_get_slot_index (
    QmiMessageGasDmsSetActiveFirmwareInput *self,
    guint8 *value_slot_index,
    GError **error);


/**
 * qmi_message_gas_dms_set_active_firmware_input_set_slot_index:
 * @self: a #QmiMessageGasDmsSetActiveFirmwareInput.
 * @value_slot_index: a #guint8.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Slot Index' field in the message.
 *
 * Returns: (skip): %TRUE if @value was successfully set, %FALSE otherwise.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_set_active_firmware_input_set_slot_index (
    QmiMessageGasDmsSetActiveFirmwareInput *self,
    guint8 value_slot_index,
    GError **error);


/**
 * qmi_message_gas_dms_set_active_firmware_input_get_carrier_name:
 * @self: a #QmiMessageGasDmsSetActiveFirmwareInput.
 * @value_carrier_name: (out)(optional)(transfer none): a placeholder for the output constant string, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Carrier Name' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_set_active_firmware_input_get_carrier_name (
    QmiMessageGasDmsSetActiveFirmwareInput *self,
    const gchar **value_carrier_name,
    GError **error);


/**
 * qmi_message_gas_dms_set_active_firmware_input_set_carrier_name:
 * @self: a #QmiMessageGasDmsSetActiveFirmwareInput.
 * @value_carrier_name: a constant string.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Carrier Name' field in the message.
 *
 * Returns: (skip): %TRUE if @value was successfully set, %FALSE otherwise.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_set_active_firmware_input_set_carrier_name (
    QmiMessageGasDmsSetActiveFirmwareInput *self,
    const gchar *value_carrier_name,
    GError **error);


/**
 * qmi_message_gas_dms_set_active_firmware_input_ref:
 * @self: a #QmiMessageGasDmsSetActiveFirmwareInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 *
 * Since: 1.24
 */
QmiMessageGasDmsSetActiveFirmwareInput *qmi_message_gas_dms_set_active_firmware_input_ref (QmiMessageGasDmsSetActiveFirmwareInput *self);

/**
 * qmi_message_gas_dms_set_active_firmware_input_unref:
 * @self: a #QmiMessageGasDmsSetActiveFirmwareInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 *
 * Since: 1.24
 */
void qmi_message_gas_dms_set_active_firmware_input_unref (QmiMessageGasDmsSetActiveFirmwareInput *self);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiMessageGasDmsSetActiveFirmwareInput, qmi_message_gas_dms_set_active_firmware_input_unref)

/**
 * qmi_message_gas_dms_set_active_firmware_input_new:
 *
 * Allocates a new #QmiMessageGasDmsSetActiveFirmwareInput.
 *
 * Returns: the newly created #QmiMessageGasDmsSetActiveFirmwareInput. The returned value should be freed with qmi_message_gas_dms_set_active_firmware_input_unref().
 *
 * Since: 1.24
 */
QmiMessageGasDmsSetActiveFirmwareInput *qmi_message_gas_dms_set_active_firmware_input_new (void);

/* --- Output -- */

/**
 * QmiMessageGasDmsSetActiveFirmwareOutput:
 *
 * The #QmiMessageGasDmsSetActiveFirmwareOutput structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.24
 */
typedef struct _QmiMessageGasDmsSetActiveFirmwareOutput QmiMessageGasDmsSetActiveFirmwareOutput;
GType qmi_message_gas_dms_set_active_firmware_output_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_GAS_DMS_SET_ACTIVE_FIRMWARE_OUTPUT (qmi_message_gas_dms_set_active_firmware_output_get_type ())


/**
 * qmi_message_gas_dms_set_active_firmware_output_get_result:
 * @self: a QmiMessageGasDmsSetActiveFirmwareOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: (skip): %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_set_active_firmware_output_get_result (
    QmiMessageGasDmsSetActiveFirmwareOutput *self,
    GError **error);


/**
 * qmi_message_gas_dms_set_active_firmware_output_ref:
 * @self: a #QmiMessageGasDmsSetActiveFirmwareOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 *
 * Since: 1.24
 */
QmiMessageGasDmsSetActiveFirmwareOutput *qmi_message_gas_dms_set_active_firmware_output_ref (QmiMessageGasDmsSetActiveFirmwareOutput *self);

/**
 * qmi_message_gas_dms_set_active_firmware_output_unref:
 * @self: a #QmiMessageGasDmsSetActiveFirmwareOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 *
 * Since: 1.24
 */
void qmi_message_gas_dms_set_active_firmware_output_unref (QmiMessageGasDmsSetActiveFirmwareOutput *self);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiMessageGasDmsSetActiveFirmwareOutput, qmi_message_gas_dms_set_active_firmware_output_unref)

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message GAS DMS Get Firmware List */


/* --- Input -- */

/**
 * QmiMessageGasDmsGetFirmwareListInput:
 *
 * The #QmiMessageGasDmsGetFirmwareListInput structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.24
 */
typedef struct _QmiMessageGasDmsGetFirmwareListInput QmiMessageGasDmsGetFirmwareListInput;
GType qmi_message_gas_dms_get_firmware_list_input_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_INPUT (qmi_message_gas_dms_get_firmware_list_input_get_type ())


/**
 * qmi_message_gas_dms_get_firmware_list_input_get_version:
 * @self: a #QmiMessageGasDmsGetFirmwareListInput.
 * @value_version: (out)(optional)(transfer none): a placeholder for the output constant string, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Version' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_get_firmware_list_input_get_version (
    QmiMessageGasDmsGetFirmwareListInput *self,
    const gchar **value_version,
    GError **error);


/**
 * qmi_message_gas_dms_get_firmware_list_input_set_version:
 * @self: a #QmiMessageGasDmsGetFirmwareListInput.
 * @value_version: a constant string.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Version' field in the message.
 *
 * Returns: (skip): %TRUE if @value was successfully set, %FALSE otherwise.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_get_firmware_list_input_set_version (
    QmiMessageGasDmsGetFirmwareListInput *self,
    const gchar *value_version,
    GError **error);


/**
 * qmi_message_gas_dms_get_firmware_list_input_get_name:
 * @self: a #QmiMessageGasDmsGetFirmwareListInput.
 * @value_name: (out)(optional)(transfer none): a placeholder for the output constant string, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Name' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_get_firmware_list_input_get_name (
    QmiMessageGasDmsGetFirmwareListInput *self,
    const gchar **value_name,
    GError **error);


/**
 * qmi_message_gas_dms_get_firmware_list_input_set_name:
 * @self: a #QmiMessageGasDmsGetFirmwareListInput.
 * @value_name: a constant string.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Name' field in the message.
 *
 * Returns: (skip): %TRUE if @value was successfully set, %FALSE otherwise.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_get_firmware_list_input_set_name (
    QmiMessageGasDmsGetFirmwareListInput *self,
    const gchar *value_name,
    GError **error);


/**
 * qmi_message_gas_dms_get_firmware_list_input_get_slot_index:
 * @self: a #QmiMessageGasDmsGetFirmwareListInput.
 * @value_slot_index: (out)(optional): a placeholder for the output #guint8, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Slot Index' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_get_firmware_list_input_get_slot_index (
    QmiMessageGasDmsGetFirmwareListInput *self,
    guint8 *value_slot_index,
    GError **error);


/**
 * qmi_message_gas_dms_get_firmware_list_input_set_slot_index:
 * @self: a #QmiMessageGasDmsGetFirmwareListInput.
 * @value_slot_index: a #guint8.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Slot Index' field in the message.
 *
 * Returns: (skip): %TRUE if @value was successfully set, %FALSE otherwise.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_get_firmware_list_input_set_slot_index (
    QmiMessageGasDmsGetFirmwareListInput *self,
    guint8 value_slot_index,
    GError **error);


/**
 * qmi_message_gas_dms_get_firmware_list_input_get_mode:
 * @self: a #QmiMessageGasDmsGetFirmwareListInput.
 * @value_mode: (out)(optional): a placeholder for the output #QmiGasFirmwareListingMode, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Mode' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_get_firmware_list_input_get_mode (
    QmiMessageGasDmsGetFirmwareListInput *self,
    QmiGasFirmwareListingMode *value_mode,
    GError **error);


/**
 * qmi_message_gas_dms_get_firmware_list_input_set_mode:
 * @self: a #QmiMessageGasDmsGetFirmwareListInput.
 * @value_mode: a #QmiGasFirmwareListingMode.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Mode' field in the message.
 *
 * Returns: (skip): %TRUE if @value was successfully set, %FALSE otherwise.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_get_firmware_list_input_set_mode (
    QmiMessageGasDmsGetFirmwareListInput *self,
    QmiGasFirmwareListingMode value_mode,
    GError **error);


/**
 * qmi_message_gas_dms_get_firmware_list_input_ref:
 * @self: a #QmiMessageGasDmsGetFirmwareListInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 *
 * Since: 1.24
 */
QmiMessageGasDmsGetFirmwareListInput *qmi_message_gas_dms_get_firmware_list_input_ref (QmiMessageGasDmsGetFirmwareListInput *self);

/**
 * qmi_message_gas_dms_get_firmware_list_input_unref:
 * @self: a #QmiMessageGasDmsGetFirmwareListInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 *
 * Since: 1.24
 */
void qmi_message_gas_dms_get_firmware_list_input_unref (QmiMessageGasDmsGetFirmwareListInput *self);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiMessageGasDmsGetFirmwareListInput, qmi_message_gas_dms_get_firmware_list_input_unref)

/**
 * qmi_message_gas_dms_get_firmware_list_input_new:
 *
 * Allocates a new #QmiMessageGasDmsGetFirmwareListInput.
 *
 * Returns: the newly created #QmiMessageGasDmsGetFirmwareListInput. The returned value should be freed with qmi_message_gas_dms_get_firmware_list_input_unref().
 *
 * Since: 1.24
 */
QmiMessageGasDmsGetFirmwareListInput *qmi_message_gas_dms_get_firmware_list_input_new (void);

/* --- Output -- */

/**
 * QmiMessageGasDmsGetFirmwareListOutput:
 *
 * The #QmiMessageGasDmsGetFirmwareListOutput structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.24
 */
typedef struct _QmiMessageGasDmsGetFirmwareListOutput QmiMessageGasDmsGetFirmwareListOutput;
GType qmi_message_gas_dms_get_firmware_list_output_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_GAS_DMS_GET_FIRMWARE_LIST_OUTPUT (qmi_message_gas_dms_get_firmware_list_output_get_type ())


/**
 * qmi_message_gas_dms_get_firmware_list_output_get_result:
 * @self: a QmiMessageGasDmsGetFirmwareListOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: (skip): %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_get_firmware_list_output_get_result (
    QmiMessageGasDmsGetFirmwareListOutput *self,
    GError **error);


/**
 * qmi_message_gas_dms_get_firmware_list_output_get_mode:
 * @self: a #QmiMessageGasDmsGetFirmwareListOutput.
 * @value_mode: (out)(optional): a placeholder for the output #QmiGasFirmwareListingMode, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Mode' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_get_firmware_list_output_get_mode (
    QmiMessageGasDmsGetFirmwareListOutput *self,
    QmiGasFirmwareListingMode *value_mode,
    GError **error);


/**
 * qmi_message_gas_dms_get_firmware_list_output_get_stored_firmware_1:
 * @self: a #QmiMessageGasDmsGetFirmwareListOutput.
 * @value_stored_firmware_1_index: (out)(optional): a placeholder for the output #guint8, or %NULL if not required.
 * @value_stored_firmware_1_name: (out)(optional)(transfer none): a placeholder for the output constant string, or %NULL if not required.
 * @value_stored_firmware_1_version: (out)(optional)(transfer none): a placeholder for the output constant string, or %NULL if not required.
 * @value_stored_firmware_1_pri_revision: (out)(optional)(transfer none): a placeholder for the output constant string, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Stored Firmware 1' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_get_firmware_list_output_get_stored_firmware_1 (
    QmiMessageGasDmsGetFirmwareListOutput *self,
    guint8 *value_stored_firmware_1_index,
    const gchar **value_stored_firmware_1_name,
    const gchar **value_stored_firmware_1_version,
    const gchar **value_stored_firmware_1_pri_revision,
    GError **error);


/**
 * qmi_message_gas_dms_get_firmware_list_output_get_stored_firmware_2:
 * @self: a #QmiMessageGasDmsGetFirmwareListOutput.
 * @value_stored_firmware_2_index: (out)(optional): a placeholder for the output #guint8, or %NULL if not required.
 * @value_stored_firmware_2_name: (out)(optional)(transfer none): a placeholder for the output constant string, or %NULL if not required.
 * @value_stored_firmware_2_version: (out)(optional)(transfer none): a placeholder for the output constant string, or %NULL if not required.
 * @value_stored_firmware_2_pri_revision: (out)(optional)(transfer none): a placeholder for the output constant string, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Stored Firmware 2' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_get_firmware_list_output_get_stored_firmware_2 (
    QmiMessageGasDmsGetFirmwareListOutput *self,
    guint8 *value_stored_firmware_2_index,
    const gchar **value_stored_firmware_2_name,
    const gchar **value_stored_firmware_2_version,
    const gchar **value_stored_firmware_2_pri_revision,
    GError **error);


/**
 * qmi_message_gas_dms_get_firmware_list_output_get_stored_firmware_3:
 * @self: a #QmiMessageGasDmsGetFirmwareListOutput.
 * @value_stored_firmware_3_index: (out)(optional): a placeholder for the output #guint8, or %NULL if not required.
 * @value_stored_firmware_3_name: (out)(optional)(transfer none): a placeholder for the output constant string, or %NULL if not required.
 * @value_stored_firmware_3_version: (out)(optional)(transfer none): a placeholder for the output constant string, or %NULL if not required.
 * @value_stored_firmware_3_pri_revision: (out)(optional)(transfer none): a placeholder for the output constant string, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Stored Firmware 3' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_get_firmware_list_output_get_stored_firmware_3 (
    QmiMessageGasDmsGetFirmwareListOutput *self,
    guint8 *value_stored_firmware_3_index,
    const gchar **value_stored_firmware_3_name,
    const gchar **value_stored_firmware_3_version,
    const gchar **value_stored_firmware_3_pri_revision,
    GError **error);


/**
 * qmi_message_gas_dms_get_firmware_list_output_get_stored_firmware_4:
 * @self: a #QmiMessageGasDmsGetFirmwareListOutput.
 * @value_stored_firmware_4_index: (out)(optional): a placeholder for the output #guint8, or %NULL if not required.
 * @value_stored_firmware_4_name: (out)(optional)(transfer none): a placeholder for the output constant string, or %NULL if not required.
 * @value_stored_firmware_4_version: (out)(optional)(transfer none): a placeholder for the output constant string, or %NULL if not required.
 * @value_stored_firmware_4_pri_revision: (out)(optional)(transfer none): a placeholder for the output constant string, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Stored Firmware 4' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.24
 */
gboolean qmi_message_gas_dms_get_firmware_list_output_get_stored_firmware_4 (
    QmiMessageGasDmsGetFirmwareListOutput *self,
    guint8 *value_stored_firmware_4_index,
    const gchar **value_stored_firmware_4_name,
    const gchar **value_stored_firmware_4_version,
    const gchar **value_stored_firmware_4_pri_revision,
    GError **error);


/**
 * qmi_message_gas_dms_get_firmware_list_output_ref:
 * @self: a #QmiMessageGasDmsGetFirmwareListOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 *
 * Since: 1.24
 */
QmiMessageGasDmsGetFirmwareListOutput *qmi_message_gas_dms_get_firmware_list_output_ref (QmiMessageGasDmsGetFirmwareListOutput *self);

/**
 * qmi_message_gas_dms_get_firmware_list_output_unref:
 * @self: a #QmiMessageGasDmsGetFirmwareListOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 *
 * Since: 1.24
 */
void qmi_message_gas_dms_get_firmware_list_output_unref (QmiMessageGasDmsGetFirmwareListOutput *self);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiMessageGasDmsGetFirmwareListOutput, qmi_message_gas_dms_get_firmware_list_output_unref)

/*****************************************************************************/
/* Service-specific utils: GAS */


#if defined (LIBQMI_GLIB_COMPILATION)

G_GNUC_INTERNAL
gchar *__qmi_message_gas_get_printable (
    QmiMessage *self,
    QmiMessageContext *context,
    const gchar *line_prefix);

#endif


#define HAVE_QMI_SERVICE_GAS

/*****************************************************************************/
/* CLIENT: QMI Client GAS */

#define QMI_TYPE_CLIENT_GAS            (qmi_client_gas_get_type ())
#define QMI_CLIENT_GAS(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), QMI_TYPE_CLIENT_GAS, QmiClientGas))
#define QMI_CLIENT_GAS_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  QMI_TYPE_CLIENT_GAS, QmiClientGasClass))
#define QMI_IS_CLIENT_GAS(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), QMI_TYPE_CLIENT_GAS))
#define QMI_IS_CLIENT_GAS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  QMI_TYPE_CLIENT_GAS))
#define QMI_CLIENT_GAS_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  QMI_TYPE_CLIENT_GAS, QmiClientGasClass))

typedef struct _QmiClientGas QmiClientGas;
typedef struct _QmiClientGasClass QmiClientGasClass;

/**
 * QmiClientGas:
 *
 * The #QmiClientGas structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.24
 */
struct _QmiClientGas {
    /*< private >*/
    QmiClient parent;
    gpointer priv_unused;
};

struct _QmiClientGasClass {
    /*< private >*/
    QmiClientClass parent;
};

GType qmi_client_gas_get_type (void);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiClientGas, g_object_unref)


/**
 * qmi_client_gas_dms_set_active_firmware:
 * @self: a #QmiClientGas.
 * @input: a #QmiMessageGasDmsSetActiveFirmwareInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a DMS Set Active Firmware request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_gas_dms_set_active_firmware_finish() to get the result of the operation.
 *
 * Since: 1.24
 */
void qmi_client_gas_dms_set_active_firmware (
    QmiClientGas *self,
    QmiMessageGasDmsSetActiveFirmwareInput *input,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

/**
 * qmi_client_gas_dms_set_active_firmware_finish:
 * @self: a #QmiClientGas.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_gas_dms_set_active_firmware().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_gas_dms_set_active_firmware().
 *
 * Returns: a #QmiMessageGasDmsSetActiveFirmwareOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_gas_dms_set_active_firmware_output_unref().
 *
 * Since: 1.24
 */
QmiMessageGasDmsSetActiveFirmwareOutput *qmi_client_gas_dms_set_active_firmware_finish (
    QmiClientGas *self,
    GAsyncResult *res,
    GError **error);

/**
 * qmi_client_gas_dms_get_firmware_list:
 * @self: a #QmiClientGas.
 * @input: a #QmiMessageGasDmsGetFirmwareListInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a DMS Get Firmware List request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_gas_dms_get_firmware_list_finish() to get the result of the operation.
 *
 * Since: 1.24
 */
void qmi_client_gas_dms_get_firmware_list (
    QmiClientGas *self,
    QmiMessageGasDmsGetFirmwareListInput *input,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

/**
 * qmi_client_gas_dms_get_firmware_list_finish:
 * @self: a #QmiClientGas.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_gas_dms_get_firmware_list().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_gas_dms_get_firmware_list().
 *
 * Returns: a #QmiMessageGasDmsGetFirmwareListOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_gas_dms_get_firmware_list_output_unref().
 *
 * Since: 1.24
 */
QmiMessageGasDmsGetFirmwareListOutput *qmi_client_gas_dms_get_firmware_list_finish (
    QmiClientGas *self,
    GAsyncResult *res,
    GError **error);

G_END_DECLS

#endif /* __LIBQMI_GLIB_QMI_GAS__ */
