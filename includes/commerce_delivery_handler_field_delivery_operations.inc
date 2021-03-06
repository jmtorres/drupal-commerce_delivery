<?php

/**
 * Field handler to present a delivery's operations links.
 */
class commerce_delivery_handler_field_delivery_operations extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['delivery_id'] = 'delivery_id';
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['add_destination'] = TRUE;

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['add_destination'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add a destination parameter to edit and delete operation links so users return to this View on form submission.'),
      '#default_value' => $this->options['add_destination'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $delivery_id = $this->get_value($values, 'delivery_id');

    // Get the operations links.
    $links = menu_contextual_links('commerce-delivery', 'admin/commerce/deliveries', array($delivery_id));

    if (!empty($links)) {
      // Add the destination to the links if specified.
      if ($this->options['add_destination']) {
        foreach ($links as $id => &$link) {
          $link['query'] = drupal_get_destination();
        }
      }

      return theme('links__ctools_dropbutton', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
