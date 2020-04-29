$(document).ready(function()
{
	$('#btnRegister').click(function()
	{
		if($('#email').val().isEmpty())
		{
			$('#email').clearAndFocus("메일주소...");
			return;
		}
				
		if($('#password').val().isEmpty())
		{
			$('#password').clearAndFocus("비밀번호...");
			return;
		}
				
		if(!$('#password').val().equals($('#password2').val()))
		{
			$('#password2').clearAndFocus("비밀번호 확인...");
			return;
		}
				
		if($('#nick').val().isEmpty())
		{
			$('#nick').clearAndFocus("별명...");
			return;
		}

		//let form = document.getElementById('regForm');
		//let form = document.forms[0];
		let form = $('#updateForm')[0];
		let formData = new FormData(form);
		$.ajax(
		{
			url: $('#updateForm').attr('action'),
			type: $('#updateForm').attr('method'),
			processData: false, // 별도의 폼 데이터 처리 하지 않도록 정보를 전달
			contentType: false, // 컨텐트 타입도 지정하지 않도록
			enctype: 'multipart/form-data',
			data: formData,
			success: function(data)
			{
				switch(data.errno)
				{
				case 1:
					$('#email').val('').focus();
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				}
			}
		});
	});
	
	$('input[name=change]').click(function()
	{
		let value = $(this).val();
		if(value == 'true')
		{
			$('#pictureField').css('display', 'block');
		}
		else
		{
			$('#pictureField').css('display', 'none');
		}
	});
			
			
});