jQuery(function () {
  jQuery('option[value="All"]').text('All Categories');
  jQuery('.catalog-sidebar h2').html('<i class="fa fa-list"></i> Categories');
  jQuery('.node-selection-link.delete').click(function () {  jQuery(this).parent().parent().parent().parent().parent().remove() });

  if (jQuery('.breadcrumb li').last().text() == '') {
    jQuery('.breadcrumb li').last().remove();
  }

  jQuery('.block-wrapper li.active-trail a').prepend('<i class="fa fa-arrow-circle-o-left" aria-hidden="true"></i>');

  jQuery('#block-views-exp-search-page input.form-text').attr('placeholder', 'Search here ...');

  //jQuery('.search-box #edit-taxonomy-catalog-tid-wrapper select').attr('size', '11');

  jQuery('.page-nselect-form .rp-cantidad-input').keyup(function () {
    var node = jQuery(this).attr("nid");
    var quantity = jQuery(this).val();
    var path = '/nselect/updatequatity/' + node + '/' + quantity;
    if (quantity) {
      jQuery.get(path,{ name: Math.floor(Math.random()*11) },function(data){
        console.log('done:' +path);
      });
    }
  });

  // Home testimonial, redirect any click
  jQuery('.block-testimonials .jcarousel-container-horizontal .jcarousel-clip-horizontal .jcarousel-item').click(function () {
    window.location = '/testimonial'
  });

  // Add prefix to price product
  var selector = '.not-front.node-type-productv2 .field-name-field-prod-price .field-label';
  jQuery(selector).text(jQuery(selector).text() + ' $');

  // related products block , re size if it doesn' have 4 elements
  jQuery('.jq-related-products .jcarousel-item').css('width', '197px');


  // Resize or another width page
  var currentWidth = jQuery( window ).width();

  function valideElementsWithWidth() {
    if (currentWidth < 1200) {
      jQuery('#block-views-central-block-block .views-row-5').hide()
    } else {
      jQuery('#block-views-central-block-block .views-row-5').show()
    }
    //console.log(currentWidth);
  }

  // on resize
  jQuery( window ).resize(function() {
    currentWidth = jQuery( window ).width();
    valideElementsWithWidth();
  });

  valideElementsWithWidth();


});