<?php

/**
 * @file
 * Delivery entity controller
 */

class CommerceDeliveryEntityController extends DrupalCommerceEntityController {

  /**
   * Create a default delivery.
   *
   * @inheritdoc
   *
   * @param array $values
   *
   * @return object
   */
  public function create(array $values = array()) {
    $values += array(
      'type' => 'commerce_delivery',
      'delivery_id' => '',
      'order_id' => 0,
      'status' => 0,
      'created' => '',
      'changed' => '',
    );

    return parent::create($values);
  }

  public function save($delivery, DatabaseTransaction $transaction = NULL) {
    // Set the timestamp fields.
    if (empty($delivery->delivery_id)) {
      $delivery->created = REQUEST_TIME;
    }
    $delivery->changed = REQUEST_TIME;

    return parent::save($delivery, $transaction);
  }
}
