$(document).ready(function() 
{
	var socket = null;
	
	socket = io('http://localhost:8080');
	
	$('.images').change(function()
	{
		$('#imageBox').attr('src', $(this).val());
	});
	
	socket.on('addtrue', function(data)
	{
		$('<option>', { value:'images/'+data, text:data}).appendTo($('.images'))
		.attr('selected', 'selected');
		$('#imageBox').attr('src', ('images/' + data));
	});
			
	socket.on('deltrue', function(data)
	{
		var options = $('option').filter(function()
		{
			return ($(this).text() == data);
		});
		
		if($(options).last().next().length == 0)
		{
			$('#imageBox').attr('src', ('images/' + $(options).last().prev().text()));
			$(options).last().remove();
		}
		else
		{
			$('#imageBox').attr('src', ('images/' + $(options).last().next().text()));
			$(options).last().remove();
		}
	});
			
	socket.on('false', function(data)
	{
		alert(data + '는 서버에 존재하지 않는 이미지입니다.');
	});

	$('button').click(function()
	{
		var text = $(this).siblings('input').val().trim();
		
		if(text == '')
		{
			alert("이미지 제목을 입력하세요.");
			return;
		}
		
		if($(this).attr("class") == "add")
		{
			socket.emit("add", text);
		}
		else
		{
			socket.emit("del", text);
		}
	});
});