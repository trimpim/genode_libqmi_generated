
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
#include "qmi-enums-dsd.h"
#include "qmi-flags64-dsd.h"
#include "qmi-message.h"
#include "qmi-client.h"

#ifndef __LIBQMI_GLIB_QMI_DSD__
#define __LIBQMI_GLIB_QMI_DSD__

G_BEGIN_DECLS

#define HAVE_QMI_MESSAGE_DSD_GET_APN_INFO
#define HAVE_QMI_MESSAGE_DSD_SET_APN_TYPE

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message DSD Get APN Info */


/* --- Input -- */

/**
 * QmiMessageDsdGetApnInfoInput:
 *
 * The #QmiMessageDsdGetApnInfoInput structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.26
 */
typedef struct _QmiMessageDsdGetApnInfoInput QmiMessageDsdGetApnInfoInput;
GType qmi_message_dsd_get_apn_info_input_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_DSD_GET_APN_INFO_INPUT (qmi_message_dsd_get_apn_info_input_get_type ())


/**
 * qmi_message_dsd_get_apn_info_input_get_apn_type:
 * @self: a #QmiMessageDsdGetApnInfoInput.
 * @value_apn_type: (out)(optional): a placeholder for the output #QmiDsdApnType, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'APN Type' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.26
 */
gboolean qmi_message_dsd_get_apn_info_input_get_apn_type (
    QmiMessageDsdGetApnInfoInput *self,
    QmiDsdApnType *value_apn_type,
    GError **error);


/**
 * qmi_message_dsd_get_apn_info_input_set_apn_type:
 * @self: a #QmiMessageDsdGetApnInfoInput.
 * @value_apn_type: a #QmiDsdApnType.
 * @error: Return location for error or %NULL.
 *
 * Set the 'APN Type' field in the message.
 *
 * Returns: (skip): %TRUE if @value was successfully set, %FALSE otherwise.
 *
 * Since: 1.26
 */
gboolean qmi_message_dsd_get_apn_info_input_set_apn_type (
    QmiMessageDsdGetApnInfoInput *self,
    QmiDsdApnType value_apn_type,
    GError **error);


/**
 * qmi_message_dsd_get_apn_info_input_ref:
 * @self: a #QmiMessageDsdGetApnInfoInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 *
 * Since: 1.26
 */
QmiMessageDsdGetApnInfoInput *qmi_message_dsd_get_apn_info_input_ref (QmiMessageDsdGetApnInfoInput *self);

/**
 * qmi_message_dsd_get_apn_info_input_unref:
 * @self: a #QmiMessageDsdGetApnInfoInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 *
 * Since: 1.26
 */
void qmi_message_dsd_get_apn_info_input_unref (QmiMessageDsdGetApnInfoInput *self);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiMessageDsdGetApnInfoInput, qmi_message_dsd_get_apn_info_input_unref)

/**
 * qmi_message_dsd_get_apn_info_input_new:
 *
 * Allocates a new #QmiMessageDsdGetApnInfoInput.
 *
 * Returns: the newly created #QmiMessageDsdGetApnInfoInput. The returned value should be freed with qmi_message_dsd_get_apn_info_input_unref().
 *
 * Since: 1.26
 */
QmiMessageDsdGetApnInfoInput *qmi_message_dsd_get_apn_info_input_new (void);

/* --- Output -- */

/**
 * QmiMessageDsdGetApnInfoOutput:
 *
 * The #QmiMessageDsdGetApnInfoOutput structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.26
 */
typedef struct _QmiMessageDsdGetApnInfoOutput QmiMessageDsdGetApnInfoOutput;
GType qmi_message_dsd_get_apn_info_output_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_DSD_GET_APN_INFO_OUTPUT (qmi_message_dsd_get_apn_info_output_get_type ())


/**
 * qmi_message_dsd_get_apn_info_output_get_apn_name:
 * @self: a #QmiMessageDsdGetApnInfoOutput.
 * @value_apn_name: (out)(optional)(transfer none): a placeholder for the output constant string, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'APN Name' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.26
 */
gboolean qmi_message_dsd_get_apn_info_output_get_apn_name (
    QmiMessageDsdGetApnInfoOutput *self,
    const gchar **value_apn_name,
    GError **error);


/**
 * qmi_message_dsd_get_apn_info_output_get_result:
 * @self: a QmiMessageDsdGetApnInfoOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: (skip): %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 *
 * Since: 1.26
 */
gboolean qmi_message_dsd_get_apn_info_output_get_result (
    QmiMessageDsdGetApnInfoOutput *self,
    GError **error);


/**
 * qmi_message_dsd_get_apn_info_output_ref:
 * @self: a #QmiMessageDsdGetApnInfoOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 *
 * Since: 1.26
 */
QmiMessageDsdGetApnInfoOutput *qmi_message_dsd_get_apn_info_output_ref (QmiMessageDsdGetApnInfoOutput *self);

/**
 * qmi_message_dsd_get_apn_info_output_unref:
 * @self: a #QmiMessageDsdGetApnInfoOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 *
 * Since: 1.26
 */
void qmi_message_dsd_get_apn_info_output_unref (QmiMessageDsdGetApnInfoOutput *self);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiMessageDsdGetApnInfoOutput, qmi_message_dsd_get_apn_info_output_unref)

/*****************************************************************************/
/* REQUEST/RESPONSE: Qmi Message DSD Set APN Type */


/* --- Input -- */

/**
 * QmiMessageDsdSetApnTypeInput:
 *
 * The #QmiMessageDsdSetApnTypeInput structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.26
 */
typedef struct _QmiMessageDsdSetApnTypeInput QmiMessageDsdSetApnTypeInput;
GType qmi_message_dsd_set_apn_type_input_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_DSD_SET_APN_TYPE_INPUT (qmi_message_dsd_set_apn_type_input_get_type ())


/**
 * qmi_message_dsd_set_apn_type_input_get_apn_type_preference_mask:
 * @self: a #QmiMessageDsdSetApnTypeInput.
 * @value_apn_type_preference_mask: (out)(optional): a placeholder for the output #QmiDsdApnTypePreference, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'APN Type Preference Mask' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.26
 */
gboolean qmi_message_dsd_set_apn_type_input_get_apn_type_preference_mask (
    QmiMessageDsdSetApnTypeInput *self,
    QmiDsdApnTypePreference *value_apn_type_preference_mask,
    GError **error);


/**
 * qmi_message_dsd_set_apn_type_input_set_apn_type_preference_mask:
 * @self: a #QmiMessageDsdSetApnTypeInput.
 * @value_apn_type_preference_mask: a #QmiDsdApnTypePreference.
 * @error: Return location for error or %NULL.
 *
 * Set the 'APN Type Preference Mask' field in the message.
 *
 * Returns: (skip): %TRUE if @value was successfully set, %FALSE otherwise.
 *
 * Since: 1.26
 */
gboolean qmi_message_dsd_set_apn_type_input_set_apn_type_preference_mask (
    QmiMessageDsdSetApnTypeInput *self,
    QmiDsdApnTypePreference value_apn_type_preference_mask,
    GError **error);


/**
 * qmi_message_dsd_set_apn_type_input_get_apn_type:
 * @self: a #QmiMessageDsdSetApnTypeInput.
 * @value_apn_type_name: (out)(optional)(transfer none): a placeholder for the output constant string, or %NULL if not required.
 * @value_apn_type_type: (out)(optional): a placeholder for the output #QmiDsdApnTypePreference, or %NULL if not required.
 * @error: Return location for error or %NULL.
 *
 * Get the 'APN Type' field from @self.
 *
 * Returns: (skip): %TRUE if the field is found, %FALSE otherwise.
 *
 * Since: 1.26
 */
gboolean qmi_message_dsd_set_apn_type_input_get_apn_type (
    QmiMessageDsdSetApnTypeInput *self,
    const gchar **value_apn_type_name,
    QmiDsdApnTypePreference *value_apn_type_type,
    GError **error);


/**
 * qmi_message_dsd_set_apn_type_input_set_apn_type:
 * @self: a #QmiMessageDsdSetApnTypeInput.
 * @value_apn_type_name: a constant string.
 * @value_apn_type_type: a #QmiDsdApnTypePreference.
 * @error: Return location for error or %NULL.
 *
 * Set the 'APN Type' field in the message.
 *
 * Returns: (skip): %TRUE if @value was successfully set, %FALSE otherwise.
 *
 * Since: 1.26
 */
gboolean qmi_message_dsd_set_apn_type_input_set_apn_type (
    QmiMessageDsdSetApnTypeInput *self,
    const gchar *value_apn_type_name,
    QmiDsdApnTypePreference value_apn_type_type,
    GError **error);


/**
 * qmi_message_dsd_set_apn_type_input_ref:
 * @self: a #QmiMessageDsdSetApnTypeInput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 *
 * Since: 1.26
 */
QmiMessageDsdSetApnTypeInput *qmi_message_dsd_set_apn_type_input_ref (QmiMessageDsdSetApnTypeInput *self);

/**
 * qmi_message_dsd_set_apn_type_input_unref:
 * @self: a #QmiMessageDsdSetApnTypeInput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 *
 * Since: 1.26
 */
void qmi_message_dsd_set_apn_type_input_unref (QmiMessageDsdSetApnTypeInput *self);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiMessageDsdSetApnTypeInput, qmi_message_dsd_set_apn_type_input_unref)

/**
 * qmi_message_dsd_set_apn_type_input_new:
 *
 * Allocates a new #QmiMessageDsdSetApnTypeInput.
 *
 * Returns: the newly created #QmiMessageDsdSetApnTypeInput. The returned value should be freed with qmi_message_dsd_set_apn_type_input_unref().
 *
 * Since: 1.26
 */
QmiMessageDsdSetApnTypeInput *qmi_message_dsd_set_apn_type_input_new (void);

/* --- Output -- */

/**
 * QmiMessageDsdSetApnTypeOutput:
 *
 * The #QmiMessageDsdSetApnTypeOutput structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.26
 */
typedef struct _QmiMessageDsdSetApnTypeOutput QmiMessageDsdSetApnTypeOutput;
GType qmi_message_dsd_set_apn_type_output_get_type (void) G_GNUC_CONST;
#define QMI_TYPE_MESSAGE_DSD_SET_APN_TYPE_OUTPUT (qmi_message_dsd_set_apn_type_output_get_type ())


/**
 * qmi_message_dsd_set_apn_type_output_get_result:
 * @self: a QmiMessageDsdSetApnTypeOutput.
 * @error: Return location for error or %NULL.
 *
 * Get the result of the QMI operation.
 *
 * Returns: (skip): %TRUE if the QMI operation succeeded, %FALSE if @error is set.
 *
 * Since: 1.26
 */
gboolean qmi_message_dsd_set_apn_type_output_get_result (
    QmiMessageDsdSetApnTypeOutput *self,
    GError **error);


/**
 * qmi_message_dsd_set_apn_type_output_ref:
 * @self: a #QmiMessageDsdSetApnTypeOutput.
 *
 * Atomically increments the reference count of @self by one.
 *
 * Returns: the new reference to @self.
 *
 * Since: 1.26
 */
QmiMessageDsdSetApnTypeOutput *qmi_message_dsd_set_apn_type_output_ref (QmiMessageDsdSetApnTypeOutput *self);

/**
 * qmi_message_dsd_set_apn_type_output_unref:
 * @self: a #QmiMessageDsdSetApnTypeOutput.
 *
 * Atomically decrements the reference count of @self by one.
 * If the reference count drops to 0, @self is completely disposed.
 *
 * Since: 1.26
 */
void qmi_message_dsd_set_apn_type_output_unref (QmiMessageDsdSetApnTypeOutput *self);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiMessageDsdSetApnTypeOutput, qmi_message_dsd_set_apn_type_output_unref)

/*****************************************************************************/
/* Service-specific utils: DSD */


#if defined (LIBQMI_GLIB_COMPILATION)

G_GNUC_INTERNAL
gchar *__qmi_message_dsd_get_printable (
    QmiMessage *self,
    QmiMessageContext *context,
    const gchar *line_prefix);

#endif


#define HAVE_QMI_SERVICE_DSD

/*****************************************************************************/
/* CLIENT: QMI Client DSD */

#define QMI_TYPE_CLIENT_DSD            (qmi_client_dsd_get_type ())
#define QMI_CLIENT_DSD(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), QMI_TYPE_CLIENT_DSD, QmiClientDsd))
#define QMI_CLIENT_DSD_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  QMI_TYPE_CLIENT_DSD, QmiClientDsdClass))
#define QMI_IS_CLIENT_DSD(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), QMI_TYPE_CLIENT_DSD))
#define QMI_IS_CLIENT_DSD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  QMI_TYPE_CLIENT_DSD))
#define QMI_CLIENT_DSD_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  QMI_TYPE_CLIENT_DSD, QmiClientDsdClass))

typedef struct _QmiClientDsd QmiClientDsd;
typedef struct _QmiClientDsdClass QmiClientDsdClass;

/**
 * QmiClientDsd:
 *
 * The #QmiClientDsd structure contains private data and should only be accessed
 * using the provided API.
 *
 * Since: 1.26
 */
struct _QmiClientDsd {
    /*< private >*/
    QmiClient parent;
    gpointer priv_unused;
};

struct _QmiClientDsdClass {
    /*< private >*/
    QmiClientClass parent;
};

GType qmi_client_dsd_get_type (void);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (QmiClientDsd, g_object_unref)


/**
 * qmi_client_dsd_get_apn_info:
 * @self: a #QmiClientDsd.
 * @input: a #QmiMessageDsdGetApnInfoInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Get APN Info request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_dsd_get_apn_info_finish() to get the result of the operation.
 *
 * Since: 1.26
 */
void qmi_client_dsd_get_apn_info (
    QmiClientDsd *self,
    QmiMessageDsdGetApnInfoInput *input,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

/**
 * qmi_client_dsd_get_apn_info_finish:
 * @self: a #QmiClientDsd.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_dsd_get_apn_info().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_dsd_get_apn_info().
 *
 * Returns: a #QmiMessageDsdGetApnInfoOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_dsd_get_apn_info_output_unref().
 *
 * Since: 1.26
 */
QmiMessageDsdGetApnInfoOutput *qmi_client_dsd_get_apn_info_finish (
    QmiClientDsd *self,
    GAsyncResult *res,
    GError **error);

/**
 * qmi_client_dsd_set_apn_type:
 * @self: a #QmiClientDsd.
 * @input: a #QmiMessageDsdSetApnTypeInput.
 * @timeout: maximum time to wait for the method to complete, in seconds.
 * @cancellable: a #GCancellable or %NULL.
 * @callback: a #GAsyncReadyCallback to call when the request is satisfied.
 * @user_data: user data to pass to @callback.
 *
 * Asynchronously sends a Set APN Type request to the device.
 *
 * When the operation is finished, @callback will be invoked in the thread-default main loop of the thread you are calling this method from.
 *
 * You can then call qmi_client_dsd_set_apn_type_finish() to get the result of the operation.
 *
 * Since: 1.26
 */
void qmi_client_dsd_set_apn_type (
    QmiClientDsd *self,
    QmiMessageDsdSetApnTypeInput *input,
    guint timeout,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

/**
 * qmi_client_dsd_set_apn_type_finish:
 * @self: a #QmiClientDsd.
 * @res: the #GAsyncResult obtained from the #GAsyncReadyCallback passed to qmi_client_dsd_set_apn_type().
 * @error: Return location for error or %NULL.
 *
 * Finishes an async operation started with qmi_client_dsd_set_apn_type().
 *
 * Returns: a #QmiMessageDsdSetApnTypeOutput, or %NULL if @error is set. The returned value should be freed with qmi_message_dsd_set_apn_type_output_unref().
 *
 * Since: 1.26
 */
QmiMessageDsdSetApnTypeOutput *qmi_client_dsd_set_apn_type_finish (
    QmiClientDsd *self,
    GAsyncResult *res,
    GError **error);

G_END_DECLS

#endif /* __LIBQMI_GLIB_QMI_DSD__ */
