var movies =
[
	{ title: '누구를 위하여 종은 울리나', stime: '11:30', etime: '13:30', price: '12000'},
	{ title: '아이언맨', stime: '10:20', etime: '11:20', price: '15000'},
	{ title: '트루먼 쇼', stime: '13:30', etime: '15:40', price: '13000'},
	{ title: '어벤져스', stime: '11:30', etime: '13:30', price: '18000'},
	{ title: '컨저링', stime: '10:20', etime: '11:20', price: '15000'},
	{ title: '겨울왕국2', stime: '15:30', etime: '18:30', price: '12000'},
	{ title: '기생충', stime: '18:20', etime: '21:20', price: '15000'},
	{ title: '알라딘', stime: '08:30', etime: '05:30', price: '12000'},
	{ title: '언어의 정원', stime: '15:20', etime: '17:20', price: '15000'},
	{ title: '암수살인', stime: '11:30', etime: '13:30', price: '12000'},
	{ title: '클릭', stime: '22:20', etime: '24:40', price: '15000'},
	{ title: '분노의 질주', stime: '08:30', etime: '11:30', price: '12000'},
	{ title: '데드풀', stime: '15:20', etime: '17:20', price: '15000'},
];

$(document).ready(function()
{
	var div = $('<div>', { class : 'content' }).appendTo($('body'));
	$('<div>', { class : 'left' }).appendTo(div);
	$('<div>', { class : 'right' }).appendTo(div);
	
	movies.forEach(function(item)
	{
		var ul = $('<ul>', { class: 'menuBox'}).appendTo($('.left'));
		$('<li>', { id: 'title', text: item['title'] }).appendTo(ul);
		$('<li>', { id: 'time', text: item['stime'] + ' - ' + item['etime'] }).appendTo(ul);
		$('<li>', { id: 'price', text: item['price'] }).appendTo(ul);
	});
			
	$('.menuBox').click(function(e)
	{
		$('.menuBox').css('height', '28px');
		$(this).css('height', '78px');
	});
});