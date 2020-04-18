String.prototype.isEmpty = function()
{
	return (this.trim() == '');
};

$.fn.isEmpty = function()
{
	return ($(this).val().trim() == '');
};

$.refresh = function()
{
	$.ajax(
	{
		url:'/board',
		type:'get',
		success: function(data)
		{
			$('.board').empty();
			
			let category = $('<ul>', {id:'category'});
			category.append($('<li>', {text: '글 번호'}));
			category.append($('<li>', {text: '제목'}));
			category.append($('<li>', {text: '작성자'}));
			category.append($('<li>', {text: '등록일자'}));
			
			$('.board').append(category);
			
			$(data).each(function(index, item)
			{
				let ul = $('<ul>');
				ul.append($('<li>', {text: item.b_Id}));
				ul.append($('<li>', {text: item.b_title}));
				ul.append($('<li>', {text: item.b_writer}));
				ul.append($('<li>', {text: item.b_date.substring(2,10)}));
				category.after(ul);
			});
		}
	});
};

$(document).ready(function()
{
	var socket = io('localhost:8080');
	socket.on('refresh', function(data)
	{
		$.refresh();
	});
	
	$.refresh();
	
	$('#b_write').click(function()
	{
		if($('#b_writer').isEmpty())
		{
			alert('작성자 왜 안 입력해?^^');
			$('#b_writer').val('').focus();
			return;
		}
		
		if($('#b_password').isEmpty())
		{
			alert('비밀번호 왜 안 입력해?^^');
			$('#b_password').val('').focus();
			return;
		}
		
		if($('#b_title').isEmpty())
		{
			alert('제목 안 입력할거야?^^');
			$('#b_title').val('').focus();
			return;
		}		
		
		if($('#b_contents').isEmpty())
		{
			alert('내용 안 입력할거야?^^');
			$('#b_contents').val('').focus();
			return;
		}
		
		$.ajax(
		{
			url: '/board',
			type: 'post',
			data: 
			{
				b_writer: $('#b_writer').val(),
				b_password: $('#b_password').val(),
				b_title: $('#b_title').val(),
				b_contents: $('#b_contents').val()
			},
			success: function(data)
			{
				alert(data.message);
			}
		});
	});
});