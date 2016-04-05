// JavaScript Document

jQuery().ready(function(){
						

function hide_label_idioma(){
	
	jQuery("label:contains('Language')").parent().hide();
	
	}

function ocultar_title_front(){
	jQuery(".front .field-name-title").hide();
	}


// ejecutar al cargar la pagina

hide_label_idioma();
ocultar_title_front();

jQuery(".form-item-taxonomy-catalog-und select option")
.not(":contains('-')").css("font-weight","bold");
						
						
	
jQuery("a.active").parent("li").addClass("active");						
						
						}); // fin de jquery