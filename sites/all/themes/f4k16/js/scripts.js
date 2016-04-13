jQuery(function () {
  jQuery('option[value="All"]').text('All Categories');
  jQuery('.catalog-sidebar h2').html('<i class="fa fa-list"></i> Categories');
  jQuery('.node-selection-link.delete').click(function () {  jQuery(this).parent().parent().parent().parent().parent().remove() });

  if (jQuery('.breadcrumb li').last().text() == '') {
    jQuery('.breadcrumb li').last().remove();
  }

  jQuery('.block-wrapper li.active-trail a').prepend('<i class="fa fa-arrow-circle-o-left" aria-hidden="true"></i>');


});