jQuery().ready(function(){

jQuery(".zopim").remove();
jQuery('.views-submit-button').remove();
jQuery("input#edit-title").attr("placeholder","Search Products");

jQuery(".btn a").each(function(){ 
	jQuery(this).parent().parent().find(".title").append(jQuery(this))});





// jQuery(document).bind("pagebeforeload pageload pageloadfailed pagebeforechange pagechange pagechangefailed pagebeforeshow pagebeforehide pageshow pagehide pagebeforecreate pagecreate pageinit pageremove updatelayout", function(e) { console.log(e.type);

//       });





// jQuery( ".product" ).live( "pageshow", function(){ 
// 	console.log("The page has been enhanced...");
// // Attach event handlers or run other jQuery code...
// console.log("swipe");
// //      // pure JS
// // var elem = document.getElementById('mySwipe');
// // window.mySwipe = Swipe(elem, {
// //   // startSlide: 4,
// //   // auto: 3000,
// //   // continuous: true,
// //   // disableScroll: true,
// //   // stopPropagation: true,
// //   // callback: function(index, element) {},
// //   // transitionEnd: function(index, element) {}
// // });

// });

jQuery(".list , .type-home").live("pageshow",function(e,data){
	jQuery("input#edit-title").attr("placeholder","Search Products");
	
});

jQuery(" .type-home").live("pageshow",function(e,data){
	jQuery.get("/nselect/count",
		{ name: Math.floor(Math.random()*11) },
		function(dt){ jQuery("span.count.ajax").text(dt); 
	});

});


jQuery( ".ui-page-active.product" ).live( "pageshow", 
	function( e, data ){ 
		// console.log( "pageshow" );
		window.mySwipe = jQuery('.ui-page-active #mySwipe').Swipe().data('Swipe');

});

jQuery( ".ui-page-active.product" ).live( "pageinit", 
	function( e, data ){ 
		// console.log( "page init" );
		window.mySwipe = jQuery('.ui-page-active #mySwipe').Swipe().data('Swipe');
 
});


});


jQuery(document).bind("mobileinit", function() {
    jQuery.extend( jQuery.mobile, {
        ajaxEnabled: false
}); });




