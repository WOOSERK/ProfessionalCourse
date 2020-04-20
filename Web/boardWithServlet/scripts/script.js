$.refresh = function()
{
	$.ajax(
	{
		url: '/Boards/boards',
		type: 'post',
		success: function(data)
		{
			console.log(data);
			eval("d = [" + data + "]");
			
			$(d).each(function(index, item)
			{
				let ul = $('<ul>');
				
				ul.append($('<li>', {text: item.id}));
				ul.append($('<li>', {text: item.regdate.substring(0,10)}));
				ul.append($('<li>', {text: item.writer}));
				ul.append($('<li>', {text: item.title}));
				ul.append($('<li>', {text: item.good}));
				ul.append($('<li>', {text: item.bad}));
				ul.append($('<div>', {text: item.content, class: 'content'}).hide());
				
				$('.category').after(ul);
			});
		}
	});
};

$(document).ready(function()
{
	$.refresh();
	
	$('[name=write]').click(function()
	{
		location.href="/Boards/write.html";
	});
	
	$('[name=confirm]').click(function()
	{
		if($('[name=writer]').val().trim() == '')
		{
			alert('작성자를 입력하라.');
			$('[name=writer]').val('').focus();
			return;
		}
		
		if($('[name=pass]').val().trim() == '')
		{
			alert('비밀번호를 입력하라.');
			$('[name=pass]').val('').focus();
			return;
		}
		
		if($('[name=title]').val().trim() == '')
		{
			alert('제목을 입력하라.');
			$('[name=title]').val('').focus();
			return;
		}
		
		if($('[name=content]').val().trim() == '')
		{
			alert('내용을 입력하라.');
			$('[name=content]').val('').focus();
			return;
		}
		
		$.ajax(
		{
			url: '/Boards/write',
			type: 'post',
			data: { writer: $('[name=writer]').val(),
					pass: $('[name=pass]').val(),
					title: $('[name=title]').val(),
					content: $('[name=content]').val()},
			success: function()
			{
				history.back();
			}
		});
	});
	
	$('[name=cancle]').click(function()
	{
		history.back();
	});
});


$(document).on('click', 'ul:not(:first-child) > li', function(e)
{
	$('ul').css('height', '21px');
	$('.content').hide();
	$(e.target).parent().css('height', '78px');
	$(e.target).siblings().show();
});