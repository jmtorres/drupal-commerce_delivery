<?php

/**
 * @file
 * Delivery entity controller
 */

class CommerceDeliveryEntityController extends EntityAPIController {

  /**
   * Create a default delivery.
   *
   * @param $type
   *   The machine-readable type of the line item.
   * @param $order_id
   *   The ID of the order the line item belongs to (if available).
   *
   * @return
   *   A line item object with all default fields initialized.
   */
  public function create(array $values = array()) {
    $values += array(
      'delivery_id' => '',
      'order_id' => 0,
      'status' => 0,
      'created' => '',
      'changed' => '',
    );

    return parent::create($values);
  }

  public function save($delivery) {
    // Set the timestamp fields.
    if (empty($delivery->delivery_id)) {
      $delivery->created = REQUEST_TIME;
    }
    $delivery->changed = REQUEST_TIME;

    return parent::save($delivery);
  }
}
