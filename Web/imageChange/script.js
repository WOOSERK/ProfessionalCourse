var images = [ './images/a.jpg', './images/b.jpg', './images/c.jpg',
		'./images/d.jpg', './images/e.jpg' ];

$.fn.bindClick = function(image)
{
	this.click(function()
	{
		$('img').attr('src', image);
	});
};

$(document).ready(function()
{
	$(images).each(function(index, item)
	{
		var btn = $('<button>', {text: item});
		btn.bindClick(item);
		btn.appendTo($('.action'));
	});
	
	// 클래스가 action인 div영역에 버튼을 추가
	// 버튼을 클릭하면 이미지를 변경한다.
	
	/*$('<button>', {text:'이미지 1'}).appendTo('div.action');
	$('<button>', {text:'이미지 2'}).appendTo('div.action');
	$('<button>', {text:'이미지 3'}).appendTo('div.action');
	$('<button>', {text:'이미지 4'}).appendTo('div.action');
	$('<button>', {text:'이미지 5'}).appendTo('div.action');
	
	$(images).each(function(index, item)
	{
		$('button').eq(index).data('src', item);
	});
	
	$('button').click(function()
	{
		$('img').attr('src', $(this).data('src'));
	});*/
});

/*
 * $(document).ready(function() { $('button').eq(0).data('student',
 * students[0]); $('button').eq(1).data('student', students[1]);
 * 
 * $('button').click(function() { if(jQuery.hasData(this)) { console.log('저장된
 * 데이터가 있습니다.'); } console.log($(this).data('student')); }); });
 */

/*
 * $.fn.bindClick = function(_id) { var id = _id; this.click(function() {
 * this.id = _id; // DOM 엘레먼트 }); };
 * 
 * $(document).ready(function() { $('button:first-child').bindClick('1번');
 * $('button:last-child').bindClick('2번');
 * 
 * $('button').click(function(e) { console.log(e); });
 * 
 * var e = $.Event('click'); $('button').trigger(e);
 * 
 * var k = $.Event('keydown'); k.keyCode = 65; $('#data').trigger(k);
 * 
 * });
 */