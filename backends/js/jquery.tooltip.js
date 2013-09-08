/*
 Tooltip script
 powered by jQuery (http://www.jquery.com)

 written by Alen Grakalic (http://cssglobe.com)
 for more info visit http://cssglobe.com/post/1695/easiest-tooltip-and-image-preview-using-jquery

 ddrivetip conversion & tooltip modification by Rob G, aka Mottie (http://wowmotty.blogspot.com/)
 @updated (8/29/2009): Added Websnapr.com site screenshot option
*/

 // 'tooltipObjFlag' can be defined outside the script. It makes the script load tooltip content
 // from object id contained in the title, e.g. title='###test1'... will load content from #test1
 if (typeof(tooltipObjFlag)=='undefined') { var tooltipObjFlag = '###' }

 // 'tooltipSpeed' sets the display speed of the tooltip
 if (typeof(tooltipSpeed)=='undefined') { var tooltipSpeed = 300 }
 
 // 'tooltipLocal' is a flag that tells the script to attach the tooltip locally if set to true. If
 // false the tooltip is added to the body
 if (typeof(tooltipLocal)=='undefined') { var tooltipLocal = false }

 var xOffset = 20; // Don't use negative values here
 var yOffset = 20;

 var tooltipCSS = 'position:absolute;z-index:1000;';

this.tooltip = function(){
// Tooltips
 $('.tooltip').live('mouseover',function(e) {
  this.t = (this.title == '') ? this.t : this.title;
  var ttt = this.t;
  this.title = '';
  // Load tooltip content from an object
  var rx = new RegExp('^' + tooltipObjFlag);
  if (rx.test(ttt)) {
   tte = ttt.replace(rx,'#').split(' ')[0];
   // ignore the tooltipObjFlag if too short or too long (20 characters seemed reasonable)
   if (tte.length < 1 || tte.length > 20) {
    ttt = this.t;
   } else {
    ttt = $(tte).html();
   }
  }
  // replace new line with <br> (thanks Zbigniew!), or you can just use <br> in the title ;)
  ttt = ttt.replace(/\\n/g,'<br>');

  // retrieves width and color information from the rel attribute
  // rel='250,#000000;color:#ffffff;' => tooltip width = 250, background color = #000000, text = #ffffff
  var tmp = (typeof($(this).attr('rel'))=='undefined') ? '' : $(this).attr('rel').split(',');
  this.w = (tmp[0] == '') ? $('#tooltip').width() : tmp[0];
  this.c = (typeof(tmp[1])=='undefined') ? '' : 'background-color:' + tmp[1];
  var tmp = "<div id='tooltip' style='" + tooltipCSS + "width:" + this.w + "px;" + this.c + "'>" + ttt + "</div>";
  if (tooltipLocal){
   $(this).before(tmp);
  } else {
   $('body').append(tmp);
  }
  ttrelocate(e,'#tooltip');
  $('#tooltip').fadeIn(tooltipSpeed);
 })
 $('.tooltip').live('mouseout',function(e) {
  this.title = this.t;
  $('#tooltip').remove();
 });
 $('.tooltip').live('mousemove',function(e) {
  ttrelocate(e,'#tooltip');
 });
// Image & URL screenshot preview
 $('a.preview,a.screenshot').live('mouseover',function(e){
  this.t = this.title;
  this.title = '';
  var tmp = "<div id='preview' style='" + tooltipCSS + "'><img src='";
  var c = (this.t != '') ? '<br/>' + this.t : '';
  /* use websnapr.com to get website thumbnail preview if rel="#" */
  var ss = ($(this).hasClass('screenshot') && this.rel=="#") ? 'http://images.websnapr.com/?url=' + this.href : this.rel;
  tmp += ($(this).hasClass('preview')) ? this.href + "' alt='Image preview' />" : ss + "' alt='URL preview' />";
  tmp += c +"</div>";
  if (tooltipLocal){
   $(this).before(tmp);
  } else {
   $('body').append(tmp);
  }
  ttrelocate(e,'#preview');
  $('#preview').fadeIn(tooltipSpeed);
 })
 $('a.preview,a.screenshot').live('mouseout',function(e){
  this.title = this.t;
  $('#preview').remove();
 }); 
 $('a.preview,a.screenshot').live('mousemove',function(e){
  ttrelocate(e,'#preview');
 });
}
function ttrelocate(e,ttid){
 var ttw = $(ttid).width();
 var tth = $(ttid).height();
 var wscrY = $(window).scrollTop();
 var wscrX = $(window).scrollLeft();
 var curX = (document.all) ? event.clientX + wscrX : e.pageX;
 var curY = (document.all) ? event.clientY + wscrY : e.pageY;
 var ttleft = ((curX - wscrX + xOffset*2 + ttw) > $(window).width()) ? curX - ttw - xOffset : curX + xOffset;
 if (ttleft < wscrX + xOffset) ttleft = wscrX + xOffset;
 var tttop = ((curY - wscrY + yOffset*2 + tth) > $(window).height()) ? curY - tth - yOffset : curY + yOffset;
 if (tttop < wscrY + yOffset) tttop = curY + yOffset;
 $(ttid).css('top', tttop + 'px').css('left', ttleft + 'px');
}

// Convert ddrivetip functions (http://www.dynamicdrive.com/dynamicindex5/dhtmltooltip.htm)
// to work with this tooltip
function ddrivetip(tit,ttt,ttc,ttw){
 var ttc = (ttc == '') ? '' : 'background-color:' + ttc;
 var topColor ="#7D92A9";
 var subColor = "#A5B4C4";
 var  ContentInfo = '<table border="0" width="150" cellspacing="0" cellpadding="0">'+
    '<tr><td width="100%" bgcolor="#000000">'+

    '<table border="0" width="100%" cellspacing="1" cellpadding="0">'+
    '<tr><td width="100%" bgcolor='+topColor+'>'+

    '<table border="0" width="90%" cellspacing="0" cellpadding="0" align="center">'+
    '<tr><td width="100%" align="center">'+

    '<font class="tooltiptitle">'+tit+'</font>'+

    '</td></tr>'+
    '</table>'+

    '</td></tr>'+

    '<tr><td width="100%" bgcolor='+subColor+'>'+

    '<table border="0" width="90%" cellpadding="0" cellspacing="1" align="center">'+

    '<tr><td width="100%">'+

    '<font class="tooltipcontent">'+ttt+'</font>'+

    '</td></tr>'+
    '</table>'+

    '</td></tr>'+
    '</table>'+

    '</td></tr>'+
    '</table>';
 $('body').append("<div id='tooltip2' style='" + tooltipCSS + "width:" + ttw + "px;" + ttc + "'> " + ContentInfo + "</div>");
 $('#tooltip2').fadeIn(tooltipSpeed);
}
function hideddrivetip(){
 $('#tooltip2').remove();
}
function positiontip(evt){
 if ($('#tooltip2').length) ttrelocate(evt,'#tooltip2');
}
document.onmousemove = positiontip;

$(document).ready(function(){
 tooltip();
});