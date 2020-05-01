$.fn.btnWriteClick = function()
{
	this.one('click', function()
	{
		$.ajax(
		{
			url: '../BoardInsert.do',
			type: 'post',
			data:
			{
				writer: $('.inputArea #writer').val(),
				password: $('.inputArea #password').val(),
				password2: $('.inputArea #password2').val(),
				title: $('.inputArea #title').val(),
				content: $('.inputArea #content').val()
			},
			success: function(data)
			{
				alert(data.message);
				// 성공하였다면
				if(data.result)
				{
					$('.inputArea #btnCancel').trigger('click');
				}
				// 실패하였다면
				else
				{
					$('.inputArea #btnWrite').btnWriteClick();
				}
			}
		});
	});
};

$.fn.bindCheckCancel = function()
{
	this.one('click', function()
	{
		$(this).closest('.checkForm').hide(0, function()
		{
			//$(this).off(); // #btnCancel
			//$(this).siblings('#btnOk').off();
			// 아래로 바꿔야 정상 작동
			$('.checkForm #btnCancel').off();
			$('.checkForm #btnOk').off();
			$('.viewArea #btnDelete').bindDelete();
		});
	});
};

$.fn.bindCheckOk = function()
{
	this.one('click', function()
	{
		$.ajax(
		{
			url: '../BoardDelete.do',
			type: 'post',
			data:
			{
				id: $('.viewBox').data('board').id,
				password: $('.checkForm #password').val()
			},
			success: function(data)
			{
				alert(data.message);
				if(data.result)
				{
					$('.checkForm #btnOk').off();
					$('.checkForm #btnCancel').off();
					$('.checkForm').hide(0, function()
					{
						$('.viewArea #btnUpdate').off();
						$('.viewArea #btnDelete').off();
						$('.viewArea #btnClose').off();
						$('.viewArea').hide(0, function()
						{
							$('.main').setContent();
						});
					});
				}
				else
				{
					$(this).bindCheckOk();
				}
			}
		});
	});
};

$.fn.bindDelete = function()
{
	this.one('click', function()
	{
		let board = $(this).closest('.viewBox').data('board');
		if(board)
		{
			$('.checkForm').show(0, function()
			{
				$('.checkForm #btnCancel').bindCheckCancel();
				$('.checkForm #btnOk').bindCheckOk();
			});
		}
	});
}

$.fn.bindClose = function()
{
	this.one('click', function()
	{
		$('.viewArea').hide(0, function()
		{
			$('.viewArea #btnClose').off();
			$('.viewArea #btnDelete').off();
			$('.viewArea #btnUpdate').off();
		});
	});
};

$.fn.bindLink = function()
{
	this.click(function()
	{
		let board = $(this).data('board');
		
		$.ajax(
		{
			url: '../BoardView.do',
			type: 'post',
			data: board,
			success: function(data)
			{
				console.log(data);
				if(data.result == true)
				{
					$('.viewBox #writer').text(data.board.writer);
					$('.viewBox #regdate').text(data.board.regdate);
					$('.viewBox #title').text(data.board.title);
					$('.viewBox #content').text(data.board.content);
					$('.viewBox').data('board', data.board);
					$('.viewArea').show(0, function()
					{
						$('.viewBox #btnClose').bindClose();
						$('.viewBox #btnDelete').bindDelete();
					});
				}
			}
		});
	});
};

var gPage = 1;

$.fn.setContent = function()
{
	$(this).find('ul').not('#head,#action,#search').remove();
	
	$.ajax(
	{
		url: '../BoardList.do',
		type: 'get',
		data:
		{
			page: gPage,
			condition: $('#cond').val(),
			word: $('#word').val()
		},
		success: function(data)
		{
			for(let i=0; i<data.boards.length; i++)
			{
				let board = data.boards[i];
				let obj = $('<ul>' + 
						'<li>' + board.id + '</li>' +
						'<li>' + board.writer + '</li>' +
						'<li>' + board.regdate + '</li>' +
						'<li>' + board.title + '</li>' +
						'<li>' + board.cnt + '</li>' +
						'</ul>');
				obj.data('board', board);
				obj.bindLink();
				$('#action').before(obj);
			}
		}
	});
};

$(document).ready(function() 
{
	$('.main').setContent();
	
	$('#btnNew').click(function() 
	{
		$('.inputArea').show(0, function() 
		{	
			$('.inputArea #btnWrite').btnWriteClick();
			
			$('.inputArea #btnCancel').one('click', function()
			{
				$('.inputArea').hide(0, function() // off가 먼저인지 이벤트 부여가 먼저인지
				{
					$('.inputArea #btnWrite').off();
					$('.inputArea #btnCancel').off();
				});
			});
		});
	});
});