$.getConfirm = function(msg, callbackYes, callbackNo)
{
	var confirm = $('<div/>', { class: 'confirm' });
	confirm.append($('<ul/>'));
	confirm.find('ul').append($('<li/>', { id: 'message', text: msg }));
	confirm.find('ul').append($('<li/>', { id: 'action' }));
	confirm.find('#action').append($('<button/>', { id: 'yes', text: '예' }));
	confirm.find('#action').append($('<button/>', { id: 'no', text: '아니오' }));
	confirm.find('button').click(function()
	{
		if($(this).attr('id') == 'yes')
		{
			callbackYes && callbackYes();
		}
		else
		{
			callbackNo && callbackNo();
		}
		$(this).closest('.confirm').remove();
	});
	confirm.appendTo($('body'));
};

$.fn.check = function()
{
	return ($(this).val().trim() != '');
};

$.fn.equals = function(obj)
{
	return ($(this).val() == obj.val());
};

$(document).ready(function()
{
	$('button').click(function()
	{
		if (!$('#id').check())
		{
			alert('아이디를 입력해주세요.');
			$('#id').focus();
			return;
		}

		if (!$('#password').check())
		{
			alert('비밀번호를 입력해주세요.');
			$('#password').focus();
			return;
		}

		if (!$('#password').equals($('#password2')))
		{
			alert('비밀번호와 비밀번호 확인이 일치하지 않습니다.');
			$('#password2').focus();
			return;
		}

		if (!$('#nick').check())
		{
			alert('별명을 입력해주세요.');
			$('#nick').focus();
			return;
		}

		$.getConfirm('데이터를 전송하시겠습니까?', function()
		{
			alert('폼 데이터를 전송합니다.');
		}, function()
		{
			alert('폼 데이터 전송을 취소합니다.');
		});
	});
});