
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
#include "qmi-enums-private.h"
#include "qmi-message.h"
#include "qmi-client.h"

#ifndef __LIBQMI_GLIB_QMI_CTL__
#define __LIBQMI_GLIB_QMI_CTL__

G_BEGIN_DECLS

#define HAVE_QMI_MESSAGE_CTL_SET_INSTANCE_ID
#define HAVE_QMI_MESSAGE_CTL_GET_VERSION_INFO
#define HAVE_QMI_MESSAGE_CTL_ALLOCATE_CID
#define HAVE_QMI_MESSAGE_CTL_RELEASE_CID
#define HAVE_QMI_MESSAGE_CTL_SET_DATA_FORMAT
#define HAVE_QMI_MESSAGE_CTL_SYNC
#define HAVE_QMI_MESSAGE_CTL_INTERNAL_PROXY_OPEN
#define HAVE_QMI_INDICATION_CTL_SYNC

/*****************************************************************************/
/* INDICATION: Qmi Indication CTL Sync */


/* --- Output -- */

/* Note: no fields in the Output container */

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message CTL Set Instance ID */


/* --- Input -- */

/**
 * QmiMessageCtlSetInstanceIdInput:
 *
 * The #QmiMessageCtlSetInstanceIdInput structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.0
 */
typedef struct _QmiMessageCtlSetInstanceIdInput QmiMessageCtlSetInstanceIdInput;
GType qmi_message_ctl_set_instance_id_input_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_SET_INSTANCE_ID_INPUT (qmi_message_ctl_set_instance_id_input_get_type ())


/**
 * qmi_message_ctl_set_instance_id_input_get_id:
 * @self: a #QmiMessageCtlSetInstanceIdInput.
 * @value_id: (out)(optional): a placeholder for the output #guint8, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'ID' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_set_instance_id_input_get_id (
    QmiMessageCtlSetInstanceIdInput *self,
    guint8 *value_id,
    GError **error);


/**
 * qmi_message_ctl_set_instance_id_input_set_id:
 * @self: a #QmiMessageCtlSetInstanceIdInput.
 * @value_id: a #guint8.
 * @error: Return location for error or %NULL.
 *
 * Set the 'ID' field in the message.
 *
 * Returns: (skip): %TRUE if @value was successfully set, %FALSE otherwise.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_set_instance_id_input_set_id (
    QmiMessageCtlSetInstanceIdInput *self,
    guint8 value_id,
    GError **error);


/**
 * qmi_message_ctl_set_instance_id_input_ref:
 * @self: a #QmiMessageCtlSetInstanceIdInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 *
 * Since: 1.0
 */
QmiMessageCtlSetInstanceIdInput *qmi_message_ctl_set_instance_id_input_ref (QmiMessageCtlSetInstanceIdInput *self);

/**
 * qmi_message_ctl_set_instance_id_input_unref:
 * @self: a #QmiMessageCtlSetInstanceIdInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 *
 * Since: 1.0
 */
void qmi_message_ctl_set_instance_id_input_unref (QmiMessageCtlSetInstanceIdInput *self);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiMessageCtlSetInstanceIdInput, qmi_message_ctl_set_instance_id_input_unref)

/**
 * qmi_message_ctl_set_instance_id_input_new:
 *
 * Allocates a new #QmiMessageCtlSetInstanceIdInput.
 *
 * Returns: the newly created #QmiMessageCtlSetInstanceIdInput. The returned value should be freed with qmi_message_ctl_set_instance_id_input_unref().
 *
 * Since: 1.0
 */
QmiMessageCtlSetInstanceIdInput *qmi_message_ctl_set_instance_id_input_new (void);

/* --- Output -- */

/**
 * QmiMessageCtlSetInstanceIdOutput:
 *
 * The #QmiMessageCtlSetInstanceIdOutput structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.0
 */
typedef struct _QmiMessageCtlSetInstanceIdOutput QmiMessageCtlSetInstanceIdOutput;
GType qmi_message_ctl_set_instance_id_output_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_SET_INSTANCE_ID_OUTPUT (qmi_message_ctl_set_instance_id_output_get_type ())


/**
 * qmi_message_ctl_set_instance_id_output_get_result:
 * @self: a QmiMessageCtlSetInstanceIdOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: (skip): %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_set_instance_id_output_get_result (
    QmiMessageCtlSetInstanceIdOutput *self,
    GError **error);


/**
 * qmi_message_ctl_set_instance_id_output_get_link_id:
 * @self: a #QmiMessageCtlSetInstanceIdOutput.
 * @value_link_id: (out)(optional): a placeholder for the output #guint16, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Link ID' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_set_instance_id_output_get_link_id (
    QmiMessageCtlSetInstanceIdOutput *self,
    guint16 *value_link_id,
    GError **error);


/**
 * qmi_message_ctl_set_instance_id_output_ref:
 * @self: a #QmiMessageCtlSetInstanceIdOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 *
 * Since: 1.0
 */
QmiMessageCtlSetInstanceIdOutput *qmi_message_ctl_set_instance_id_output_ref (QmiMessageCtlSetInstanceIdOutput *self);

/**
 * qmi_message_ctl_set_instance_id_output_unref:
 * @self: a #QmiMessageCtlSetInstanceIdOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 *
 * Since: 1.0
 */
void qmi_message_ctl_set_instance_id_output_unref (QmiMessageCtlSetInstanceIdOutput *self);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiMessageCtlSetInstanceIdOutput, qmi_message_ctl_set_instance_id_output_unref)

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message CTL Get Version Info */


/* --- Input -- */

/* Note: no fields in the Input container */

/* --- Output -- */


/**
 * QmiMessageCtlGetVersionInfoOutputServiceListService:
 * @service: a #QmiService.
 * @major_version: a #guint16.
 * @minor_version: a #guint16.
 *
 * A QmiMessageCtlGetVersionInfoOutputServiceListService struct.
 *
 * Since: 1.0
 */
typedef struct _QmiMessageCtlGetVersionInfoOutputServiceListService {
    QmiService service;
    guint16 major_version;
    guint16 minor_version;
} QmiMessageCtlGetVersionInfoOutputServiceListService;

/**
 * QmiMessageCtlGetVersionInfoOutput:
 *
 * The #QmiMessageCtlGetVersionInfoOutput structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.0
 */
typedef struct _QmiMessageCtlGetVersionInfoOutput QmiMessageCtlGetVersionInfoOutput;
GType qmi_message_ctl_get_version_info_output_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_GET_VERSION_INFO_OUTPUT (qmi_message_ctl_get_version_info_output_get_type ())


/**
 * qmi_message_ctl_get_version_info_output_get_result:
 * @self: a QmiMessageCtlGetVersionInfoOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: (skip): %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_get_version_info_output_get_result (
    QmiMessageCtlGetVersionInfoOutput *self,
    GError **error);


/**
 * qmi_message_ctl_get_version_info_output_get_service_list:
 * @self: a #QmiMessageCtlGetVersionInfoOutput.
 * @value_service_list: (out)(optional)(element-type QmiMessageCtlGetVersionInfoOutputServiceListService)(transfer none): a placeholder for the output #GArray of #QmiMessageCtlGetVersionInfoOutputServiceListService elements, or %NULL if not required. Do not free it, it is owned by @self.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Service list' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_get_version_info_output_get_service_list (
    QmiMessageCtlGetVersionInfoOutput *self,
    GArray **value_service_list,
    GError **error);


/**
 * qmi_message_ctl_get_version_info_output_ref:
 * @self: a #QmiMessageCtlGetVersionInfoOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 *
 * Since: 1.0
 */
QmiMessageCtlGetVersionInfoOutput *qmi_message_ctl_get_version_info_output_ref (QmiMessageCtlGetVersionInfoOutput *self);

/**
 * qmi_message_ctl_get_version_info_output_unref:
 * @self: a #QmiMessageCtlGetVersionInfoOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 *
 * Since: 1.0
 */
void qmi_message_ctl_get_version_info_output_unref (QmiMessageCtlGetVersionInfoOutput *self);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiMessageCtlGetVersionInfoOutput, qmi_message_ctl_get_version_info_output_unref)

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message CTL Allocate CID */


/* --- Input -- */

/**
 * QmiMessageCtlAllocateCidInput:
 *
 * The #QmiMessageCtlAllocateCidInput structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.0
 */
typedef struct _QmiMessageCtlAllocateCidInput QmiMessageCtlAllocateCidInput;
GType qmi_message_ctl_allocate_cid_input_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_ALLOCATE_CID_INPUT (qmi_message_ctl_allocate_cid_input_get_type ())


/**
 * qmi_message_ctl_allocate_cid_input_get_service:
 * @self: a #QmiMessageCtlAllocateCidInput.
 * @value_service: (out)(optional): a placeholder for the output #QmiService, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Service' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_allocate_cid_input_get_service (
    QmiMessageCtlAllocateCidInput *self,
    QmiService *value_service,
    GError **error);


/**
 * qmi_message_ctl_allocate_cid_input_set_service:
 * @self: a #QmiMessageCtlAllocateCidInput.
 * @value_service: a #QmiService.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Service' field in the message.
 *
 * Returns: (skip): %TRUE if @value was successfully set, %FALSE otherwise.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_allocate_cid_input_set_service (
    QmiMessageCtlAllocateCidInput *self,
    QmiService value_service,
    GError **error);


/**
 * qmi_message_ctl_allocate_cid_input_ref:
 * @self: a #QmiMessageCtlAllocateCidInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 *
 * Since: 1.0
 */
QmiMessageCtlAllocateCidInput *qmi_message_ctl_allocate_cid_input_ref (QmiMessageCtlAllocateCidInput *self);

/**
 * qmi_message_ctl_allocate_cid_input_unref:
 * @self: a #QmiMessageCtlAllocateCidInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 *
 * Since: 1.0
 */
void qmi_message_ctl_allocate_cid_input_unref (QmiMessageCtlAllocateCidInput *self);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiMessageCtlAllocateCidInput, qmi_message_ctl_allocate_cid_input_unref)

/**
 * qmi_message_ctl_allocate_cid_input_new:
 *
 * Allocates a new #QmiMessageCtlAllocateCidInput.
 *
 * Returns: the newly created #QmiMessageCtlAllocateCidInput. The returned value should be freed with qmi_message_ctl_allocate_cid_input_unref().
 *
 * Since: 1.0
 */
QmiMessageCtlAllocateCidInput *qmi_message_ctl_allocate_cid_input_new (void);

/* --- Output -- */

/**
 * QmiMessageCtlAllocateCidOutput:
 *
 * The #QmiMessageCtlAllocateCidOutput structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.0
 */
typedef struct _QmiMessageCtlAllocateCidOutput QmiMessageCtlAllocateCidOutput;
GType qmi_message_ctl_allocate_cid_output_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_ALLOCATE_CID_OUTPUT (qmi_message_ctl_allocate_cid_output_get_type ())


/**
 * qmi_message_ctl_allocate_cid_output_get_result:
 * @self: a QmiMessageCtlAllocateCidOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: (skip): %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_allocate_cid_output_get_result (
    QmiMessageCtlAllocateCidOutput *self,
    GError **error);


/**
 * qmi_message_ctl_allocate_cid_output_get_allocation_info:
 * @self: a #QmiMessageCtlAllocateCidOutput.
 * @value_allocation_info_service: (out)(optional): a placeholder for the output #QmiService, or %NULL if not required.
 * @value_allocation_info_cid: (out)(optional): a placeholder for the output #guint8, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Allocation Info' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_allocate_cid_output_get_allocation_info (
    QmiMessageCtlAllocateCidOutput *self,
    QmiService *value_allocation_info_service,
    guint8 *value_allocation_info_cid,
    GError **error);


/**
 * qmi_message_ctl_allocate_cid_output_ref:
 * @self: a #QmiMessageCtlAllocateCidOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 *
 * Since: 1.0
 */
QmiMessageCtlAllocateCidOutput *qmi_message_ctl_allocate_cid_output_ref (QmiMessageCtlAllocateCidOutput *self);

/**
 * qmi_message_ctl_allocate_cid_output_unref:
 * @self: a #QmiMessageCtlAllocateCidOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 *
 * Since: 1.0
 */
void qmi_message_ctl_allocate_cid_output_unref (QmiMessageCtlAllocateCidOutput *self);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiMessageCtlAllocateCidOutput, qmi_message_ctl_allocate_cid_output_unref)

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message CTL Release CID */


/* --- Input -- */

/**
 * QmiMessageCtlReleaseCidInput:
 *
 * The #QmiMessageCtlReleaseCidInput structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.0
 */
typedef struct _QmiMessageCtlReleaseCidInput QmiMessageCtlReleaseCidInput;
GType qmi_message_ctl_release_cid_input_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_RELEASE_CID_INPUT (qmi_message_ctl_release_cid_input_get_type ())


/**
 * qmi_message_ctl_release_cid_input_get_release_info:
 * @self: a #QmiMessageCtlReleaseCidInput.
 * @value_release_info_service: (out)(optional): a placeholder for the output #QmiService, or %NULL if not required.
 * @value_release_info_cid: (out)(optional): a placeholder for the output #guint8, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Release Info' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_release_cid_input_get_release_info (
    QmiMessageCtlReleaseCidInput *self,
    QmiService *value_release_info_service,
    guint8 *value_release_info_cid,
    GError **error);


/**
 * qmi_message_ctl_release_cid_input_set_release_info:
 * @self: a #QmiMessageCtlReleaseCidInput.
 * @value_release_info_service: a #QmiService.
 * @value_release_info_cid: a #guint8.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Release Info' field in the message.
 *
 * Returns: (skip): %TRUE if @value was successfully set, %FALSE otherwise.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_release_cid_input_set_release_info (
    QmiMessageCtlReleaseCidInput *self,
    QmiService value_release_info_service,
    guint8 value_release_info_cid,
    GError **error);


/**
 * qmi_message_ctl_release_cid_input_ref:
 * @self: a #QmiMessageCtlReleaseCidInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 *
 * Since: 1.0
 */
QmiMessageCtlReleaseCidInput *qmi_message_ctl_release_cid_input_ref (QmiMessageCtlReleaseCidInput *self);

/**
 * qmi_message_ctl_release_cid_input_unref:
 * @self: a #QmiMessageCtlReleaseCidInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 *
 * Since: 1.0
 */
void qmi_message_ctl_release_cid_input_unref (QmiMessageCtlReleaseCidInput *self);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiMessageCtlReleaseCidInput, qmi_message_ctl_release_cid_input_unref)

/**
 * qmi_message_ctl_release_cid_input_new:
 *
 * Allocates a new #QmiMessageCtlReleaseCidInput.
 *
 * Returns: the newly created #QmiMessageCtlReleaseCidInput. The returned value should be freed with qmi_message_ctl_release_cid_input_unref().
 *
 * Since: 1.0
 */
QmiMessageCtlReleaseCidInput *qmi_message_ctl_release_cid_input_new (void);

/* --- Output -- */

/**
 * QmiMessageCtlReleaseCidOutput:
 *
 * The #QmiMessageCtlReleaseCidOutput structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.0
 */
typedef struct _QmiMessageCtlReleaseCidOutput QmiMessageCtlReleaseCidOutput;
GType qmi_message_ctl_release_cid_output_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_RELEASE_CID_OUTPUT (qmi_message_ctl_release_cid_output_get_type ())


/**
 * qmi_message_ctl_release_cid_output_get_result:
 * @self: a QmiMessageCtlReleaseCidOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: (skip): %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_release_cid_output_get_result (
    QmiMessageCtlReleaseCidOutput *self,
    GError **error);


/**
 * qmi_message_ctl_release_cid_output_get_release_info:
 * @self: a #QmiMessageCtlReleaseCidOutput.
 * @value_release_info_service: (out)(optional): a placeholder for the output #QmiService, or %NULL if not required.
 * @value_release_info_cid: (out)(optional): a placeholder for the output #guint8, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Release Info' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_release_cid_output_get_release_info (
    QmiMessageCtlReleaseCidOutput *self,
    QmiService *value_release_info_service,
    guint8 *value_release_info_cid,
    GError **error);


/**
 * qmi_message_ctl_release_cid_output_ref:
 * @self: a #QmiMessageCtlReleaseCidOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 *
 * Since: 1.0
 */
QmiMessageCtlReleaseCidOutput *qmi_message_ctl_release_cid_output_ref (QmiMessageCtlReleaseCidOutput *self);

/**
 * qmi_message_ctl_release_cid_output_unref:
 * @self: a #QmiMessageCtlReleaseCidOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 *
 * Since: 1.0
 */
void qmi_message_ctl_release_cid_output_unref (QmiMessageCtlReleaseCidOutput *self);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiMessageCtlReleaseCidOutput, qmi_message_ctl_release_cid_output_unref)

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message CTL Set Data Format */


/* --- Input -- */

/**
 * QmiMessageCtlSetDataFormatInput:
 *
 * The #QmiMessageCtlSetDataFormatInput structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.0
 */
typedef struct _QmiMessageCtlSetDataFormatInput QmiMessageCtlSetDataFormatInput;
GType qmi_message_ctl_set_data_format_input_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_SET_DATA_FORMAT_INPUT (qmi_message_ctl_set_data_format_input_get_type ())


/**
 * qmi_message_ctl_set_data_format_input_get_protocol:
 * @self: a #QmiMessageCtlSetDataFormatInput.
 * @value_protocol: (out)(optional): a placeholder for the output #QmiCtlDataLinkProtocol, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Protocol' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_set_data_format_input_get_protocol (
    QmiMessageCtlSetDataFormatInput *self,
    QmiCtlDataLinkProtocol *value_protocol,
    GError **error);


/**
 * qmi_message_ctl_set_data_format_input_set_protocol:
 * @self: a #QmiMessageCtlSetDataFormatInput.
 * @value_protocol: a #QmiCtlDataLinkProtocol.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Protocol' field in the message.
 *
 * Returns: (skip): %TRUE if @value was successfully set, %FALSE otherwise.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_set_data_format_input_set_protocol (
    QmiMessageCtlSetDataFormatInput *self,
    QmiCtlDataLinkProtocol value_protocol,
    GError **error);


/**
 * qmi_message_ctl_set_data_format_input_get_format:
 * @self: a #QmiMessageCtlSetDataFormatInput.
 * @value_format: (out)(optional): a placeholder for the output #QmiCtlDataFormat, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Format' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_set_data_format_input_get_format (
    QmiMessageCtlSetDataFormatInput *self,
    QmiCtlDataFormat *value_format,
    GError **error);


/**
 * qmi_message_ctl_set_data_format_input_set_format:
 * @self: a #QmiMessageCtlSetDataFormatInput.
 * @value_format: a #QmiCtlDataFormat.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Format' field in the message.
 *
 * Returns: (skip): %TRUE if @value was successfully set, %FALSE otherwise.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_set_data_format_input_set_format (
    QmiMessageCtlSetDataFormatInput *self,
    QmiCtlDataFormat value_format,
    GError **error);


/**
 * qmi_message_ctl_set_data_format_input_ref:
 * @self: a #QmiMessageCtlSetDataFormatInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 *
 * Since: 1.0
 */
QmiMessageCtlSetDataFormatInput *qmi_message_ctl_set_data_format_input_ref (QmiMessageCtlSetDataFormatInput *self);

/**
 * qmi_message_ctl_set_data_format_input_unref:
 * @self: a #QmiMessageCtlSetDataFormatInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 *
 * Since: 1.0
 */
void qmi_message_ctl_set_data_format_input_unref (QmiMessageCtlSetDataFormatInput *self);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiMessageCtlSetDataFormatInput, qmi_message_ctl_set_data_format_input_unref)

/**
 * qmi_message_ctl_set_data_format_input_new:
 *
 * Allocates a new #QmiMessageCtlSetDataFormatInput.
 *
 * Returns: the newly created #QmiMessageCtlSetDataFormatInput. The returned value should be freed with qmi_message_ctl_set_data_format_input_unref().
 *
 * Since: 1.0
 */
QmiMessageCtlSetDataFormatInput *qmi_message_ctl_set_data_format_input_new (void);

/* --- Output -- */

/**
 * QmiMessageCtlSetDataFormatOutput:
 *
 * The #QmiMessageCtlSetDataFormatOutput structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.0
 */
typedef struct _QmiMessageCtlSetDataFormatOutput QmiMessageCtlSetDataFormatOutput;
GType qmi_message_ctl_set_data_format_output_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_SET_DATA_FORMAT_OUTPUT (qmi_message_ctl_set_data_format_output_get_type ())


/**
 * qmi_message_ctl_set_data_format_output_get_result:
 * @self: a QmiMessageCtlSetDataFormatOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: (skip): %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_set_data_format_output_get_result (
    QmiMessageCtlSetDataFormatOutput *self,
    GError **error);


/**
 * qmi_message_ctl_set_data_format_output_get_protocol:
 * @self: a #QmiMessageCtlSetDataFormatOutput.
 * @value_protocol: (out)(optional): a placeholder for the output #QmiCtlDataLinkProtocol, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Protocol' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_set_data_format_output_get_protocol (
    QmiMessageCtlSetDataFormatOutput *self,
    QmiCtlDataLinkProtocol *value_protocol,
    GError **error);


/**
 * qmi_message_ctl_set_data_format_output_ref:
 * @self: a #QmiMessageCtlSetDataFormatOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 *
 * Since: 1.0
 */
QmiMessageCtlSetDataFormatOutput *qmi_message_ctl_set_data_format_output_ref (QmiMessageCtlSetDataFormatOutput *self);

/**
 * qmi_message_ctl_set_data_format_output_unref:
 * @self: a #QmiMessageCtlSetDataFormatOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 *
 * Since: 1.0
 */
void qmi_message_ctl_set_data_format_output_unref (QmiMessageCtlSetDataFormatOutput *self);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiMessageCtlSetDataFormatOutput, qmi_message_ctl_set_data_format_output_unref)

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message CTL Sync */


/* --- Input -- */

/* Note: no fields in the Input container */

/* --- Output -- */

/**
 * QmiMessageCtlSyncOutput:
 *
 * The #QmiMessageCtlSyncOutput structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.0
 */
typedef struct _QmiMessageCtlSyncOutput QmiMessageCtlSyncOutput;
GType qmi_message_ctl_sync_output_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_SYNC_OUTPUT (qmi_message_ctl_sync_output_get_type ())


/**
 * qmi_message_ctl_sync_output_get_result:
 * @self: a QmiMessageCtlSyncOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: (skip): %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 *
 * Since: 1.0
 */
gboolean qmi_message_ctl_sync_output_get_result (
    QmiMessageCtlSyncOutput *self,
    GError **error);


/**
 * qmi_message_ctl_sync_output_ref:
 * @self: a #QmiMessageCtlSyncOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 *
 * Since: 1.0
 */
QmiMessageCtlSyncOutput *qmi_message_ctl_sync_output_ref (QmiMessageCtlSyncOutput *self);

/**
 * qmi_message_ctl_sync_output_unref:
 * @self: a #QmiMessageCtlSyncOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 *
 * Since: 1.0
 */
void qmi_message_ctl_sync_output_unref (QmiMessageCtlSyncOutput *self);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiMessageCtlSyncOutput, qmi_message_ctl_sync_output_unref)

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message CTL Internal Proxy Open */


/* --- Input -- */

/**
 * QmiMessageCtlInternalProxyOpenInput:
 *
 * The #QmiMessageCtlInternalProxyOpenInput structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.8
 */
typedef struct _QmiMessageCtlInternalProxyOpenInput QmiMessageCtlInternalProxyOpenInput;
GType qmi_message_ctl_internal_proxy_open_input_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_INTERNAL_PROXY_OPEN_INPUT (qmi_message_ctl_internal_proxy_open_input_get_type ())


/**
 * qmi_message_ctl_internal_proxy_open_input_get_device_path:
 * @self: a #QmiMessageCtlInternalProxyOpenInput.
 * @value_device_path: (out)(optional)(transfer none): a placeholder for the output constant string, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'Device Path' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.8
 */
gboolean qmi_message_ctl_internal_proxy_open_input_get_device_path (
    QmiMessageCtlInternalProxyOpenInput *self,
    const gchar **value_device_path,
    GError **error);


/**
 * qmi_message_ctl_internal_proxy_open_input_set_device_path:
 * @self: a #QmiMessageCtlInternalProxyOpenInput.
 * @value_device_path: a constant string.
 * @error: Return location for error or %NULL.
 *
 * Set the 'Device Path' field in the message.
 *
 * Returns: (skip): %TRUE if @value was successfully set, %FALSE otherwise.
 *
 * Since: 1.8
 */
gboolean qmi_message_ctl_internal_proxy_open_input_set_device_path (
    QmiMessageCtlInternalProxyOpenInput *self,
    const gchar *value_device_path,
    GError **error);


/**
 * qmi_message_ctl_internal_proxy_open_input_ref:
 * @self: a #QmiMessageCtlInternalProxyOpenInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 *
 * Since: 1.8
 */
QmiMessageCtlInternalProxyOpenInput *qmi_message_ctl_internal_proxy_open_input_ref (QmiMessageCtlInternalProxyOpenInput *self);

/**
 * qmi_message_ctl_internal_proxy_open_input_unref:
 * @self: a #QmiMessageCtlInternalProxyOpenInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 *
 * Since: 1.8
 */
void qmi_message_ctl_internal_proxy_open_input_unref (QmiMessageCtlInternalProxyOpenInput *self);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiMessageCtlInternalProxyOpenInput, qmi_message_ctl_internal_proxy_open_input_unref)

/**
 * qmi_message_ctl_internal_proxy_open_input_new:
 *
 * Allocates a new #QmiMessageCtlInternalProxyOpenInput.
 *
 * Returns: the newly created #QmiMessageCtlInternalProxyOpenInput. The returned value should be freed with qmi_message_ctl_internal_proxy_open_input_unref().
 *
 * Since: 1.8
 */
QmiMessageCtlInternalProxyOpenInput *qmi_message_ctl_internal_proxy_open_input_new (void);

/* --- Output -- */

/**
 * QmiMessageCtlInternalProxyOpenOutput:
 *
 * The #QmiMessageCtlInternalProxyOpenOutput structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.8
 */
typedef struct _QmiMessageCtlInternalProxyOpenOutput QmiMessageCtlInternalProxyOpenOutput;
GType qmi_message_ctl_internal_proxy_open_output_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_CTL_INTERNAL_PROXY_OPEN_OUTPUT (qmi_message_ctl_internal_proxy_open_output_get_type ())


/**
 * qmi_message_ctl_internal_proxy_open_output_get_result:
 * @self: a QmiMessageCtlInternalProxyOpenOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: (skip): %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 *
 * Since: 1.8
 */
gboolean qmi_message_ctl_internal_proxy_open_output_get_result (
    QmiMessageCtlInternalProxyOpenOutput *self,
    GError **error);


/**
 * qmi_message_ctl_internal_proxy_open_output_ref:
 * @self: a #QmiMessageCtlInternalProxyOpenOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 *
 * Since: 1.8
 */
QmiMessageCtlInternalProxyOpenOutput *qmi_message_ctl_internal_proxy_open_output_ref (QmiMessageCtlInternalProxyOpenOutput *self);

/**
 * qmi_message_ctl_internal_proxy_open_output_unref:
 * @self: a #QmiMessageCtlInternalProxyOpenOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 *
 * Since: 1.8
 */
void qmi_message_ctl_internal_proxy_open_output_unref (QmiMessageCtlInternalProxyOpenOutput *self);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiMessageCtlInternalProxyOpenOutput, qmi_message_ctl_internal_proxy_open_output_unref)

/*****************************************************************************/
/* Service-specific utils: CTL */


#if defined (LIBQMI_GLIB_COMPILATION)

G_GNUC_INTERNAL
gchar *__qmi_message_ctl_get_printable (
    QmiMessage *self,
    QmiMessageContext *context,
    const gchar *line_prefix);

#endif


#define HAVE_QMI_SERVICE_CTL

/*****************************************************************************/
/* CLIENT: QMI Client CTL */

#define QMI_TYPE_CLIENT_CTL            (qmi_client_ctl_get_type ())
#define QMI_CLIENT_CTL(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), QMI_TYPE_CLIENT_CTL, QmiClientCtl))
#define QMI_CLIENT_CTL_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  QMI_TYPE_CLIENT_CTL, QmiClientCtlClass))
#define QMI_IS_CLIENT_CTL(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), QMI_TYPE_CLIENT_CTL))
#define QMI_IS_CLIENT_CTL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  QMI_TYPE_CLIENT_CTL))
#define QMI_CLIENT_CTL_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  QMI_TYPE_CLIENT_CTL, QmiClientCtlClass))

typedef struct _QmiClientCtl QmiClientCtl;
typedef struct _QmiClientCtlClass QmiClientCtlClass;

/**
 * QmiClientCtl:
 *
 * The #QmiClientCtl structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.0
 */
struct _QmiClientCtl {
    /*< private >*/
    QmiClient parent;
    gpointer priv_unused;
};

struct _QmiClientCtlClass {
    /*< private >*/
    QmiClientClass parent;
};

GType qmi_client_ctl_get_type (void);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiClientCtl, g_object_unref)


/**
 * qmi_client_ctl_set_instance_id:
 * @self: a #QmiClientCtl.
 * @input: a #QmiMessageCtlSetInstanceIdInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Set Instance ID request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_ctl_set_instance_id_finish() to get the result of the operation.
 *
 * Since: 1.0
 */
void qmi_client_ctl_set_instance_id (
    QmiClientCtl *self,
    QmiMessageCtlSetInstanceIdInput *input,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

/**
 * qmi_client_ctl_set_instance_id_finish:
 * @self: a #QmiClientCtl.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_ctl_set_instance_id().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_ctl_set_instance_id().
 *
 * Returns: a #QmiMessageCtlSetInstanceIdOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_ctl_set_instance_id_output_unref().
 *
 * Since: 1.0
 */
QmiMessageCtlSetInstanceIdOutput *qmi_client_ctl_set_instance_id_finish (
    QmiClientCtl *self,
    GAsyncResult *res,
    GError **error);

/**
 * qmi_client_ctl_get_version_info:
 * @self: a #QmiClientCtl.
 * @unused: %NULL. This message doesn't have any input bundle.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Get Version Info request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_ctl_get_version_info_finish() to get the result of the operation.
 *
 * Since: 1.0
 */
void qmi_client_ctl_get_version_info (
    QmiClientCtl *self,
    gpointer unused,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

/**
 * qmi_client_ctl_get_version_info_finish:
 * @self: a #QmiClientCtl.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_ctl_get_version_info().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_ctl_get_version_info().
 *
 * Returns: a #QmiMessageCtlGetVersionInfoOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_ctl_get_version_info_output_unref().
 *
 * Since: 1.0
 */
QmiMessageCtlGetVersionInfoOutput *qmi_client_ctl_get_version_info_finish (
    QmiClientCtl *self,
    GAsyncResult *res,
    GError **error);

/**
 * qmi_client_ctl_allocate_cid:
 * @self: a #QmiClientCtl.
 * @input: a #QmiMessageCtlAllocateCidInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Allocate CID request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_ctl_allocate_cid_finish() to get the result of the operation.
 *
 * Since: 1.0
 */
void qmi_client_ctl_allocate_cid (
    QmiClientCtl *self,
    QmiMessageCtlAllocateCidInput *input,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

/**
 * qmi_client_ctl_allocate_cid_finish:
 * @self: a #QmiClientCtl.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_ctl_allocate_cid().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_ctl_allocate_cid().
 *
 * Returns: a #QmiMessageCtlAllocateCidOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_ctl_allocate_cid_output_unref().
 *
 * Since: 1.0
 */
QmiMessageCtlAllocateCidOutput *qmi_client_ctl_allocate_cid_finish (
    QmiClientCtl *self,
    GAsyncResult *res,
    GError **error);

/**
 * qmi_client_ctl_release_cid:
 * @self: a #QmiClientCtl.
 * @input: a #QmiMessageCtlReleaseCidInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Release CID request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_ctl_release_cid_finish() to get the result of the operation.
 *
 * Since: 1.0
 */
void qmi_client_ctl_release_cid (
    QmiClientCtl *self,
    QmiMessageCtlReleaseCidInput *input,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

/**
 * qmi_client_ctl_release_cid_finish:
 * @self: a #QmiClientCtl.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_ctl_release_cid().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_ctl_release_cid().
 *
 * Returns: a #QmiMessageCtlReleaseCidOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_ctl_release_cid_output_unref().
 *
 * Since: 1.0
 */
QmiMessageCtlReleaseCidOutput *qmi_client_ctl_release_cid_finish (
    QmiClientCtl *self,
    GAsyncResult *res,
    GError **error);

/**
 * qmi_client_ctl_set_data_format:
 * @self: a #QmiClientCtl.
 * @input: a #QmiMessageCtlSetDataFormatInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Set Data Format request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_ctl_set_data_format_finish() to get the result of the operation.
 *
 * Since: 1.0
 */
void qmi_client_ctl_set_data_format (
    QmiClientCtl *self,
    QmiMessageCtlSetDataFormatInput *input,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

/**
 * qmi_client_ctl_set_data_format_finish:
 * @self: a #QmiClientCtl.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_ctl_set_data_format().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_ctl_set_data_format().
 *
 * Returns: a #QmiMessageCtlSetDataFormatOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_ctl_set_data_format_output_unref().
 *
 * Since: 1.0
 */
QmiMessageCtlSetDataFormatOutput *qmi_client_ctl_set_data_format_finish (
    QmiClientCtl *self,
    GAsyncResult *res,
    GError **error);

/**
 * qmi_client_ctl_sync:
 * @self: a #QmiClientCtl.
 * @unused: %NULL. This message doesn't have any input bundle.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Sync request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_ctl_sync_finish() to get the result of the operation.
 *
 * Since: 1.0
 */
void qmi_client_ctl_sync (
    QmiClientCtl *self,
    gpointer unused,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

/**
 * qmi_client_ctl_sync_finish:
 * @self: a #QmiClientCtl.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_ctl_sync().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_ctl_sync().
 *
 * Returns: a #QmiMessageCtlSyncOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_ctl_sync_output_unref().
 *
 * Since: 1.0
 */
QmiMessageCtlSyncOutput *qmi_client_ctl_sync_finish (
    QmiClientCtl *self,
    GAsyncResult *res,
    GError **error);

/**
 * qmi_client_ctl_internal_proxy_open:
 * @self: a #QmiClientCtl.
 * @input: a #QmiMessageCtlInternalProxyOpenInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Internal Proxy Open request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_ctl_internal_proxy_open_finish() to get the result of the operation.
 *
 * Since: 1.8
 */
void qmi_client_ctl_internal_proxy_open (
    QmiClientCtl *self,
    QmiMessageCtlInternalProxyOpenInput *input,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

/**
 * qmi_client_ctl_internal_proxy_open_finish:
 * @self: a #QmiClientCtl.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_ctl_internal_proxy_open().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_ctl_internal_proxy_open().
 *
 * Returns: a #QmiMessageCtlInternalProxyOpenOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_ctl_internal_proxy_open_output_unref().
 *
 * Since: 1.8
 */
QmiMessageCtlInternalProxyOpenOutput *qmi_client_ctl_internal_proxy_open_finish (
    QmiClientCtl *self,
    GAsyncResult *res,
    GError **error);

G_END_DECLS

#endif /* __LIBQMI_GLIB_QMI_CTL__ */
