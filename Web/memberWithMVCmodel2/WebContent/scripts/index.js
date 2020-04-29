$(document).ready(function()
{
	$('#btnRegister').click(function()
	{
		location.href = 'member/register.jsp';
	});
	
	$('#btnLogin').click(function()
	{
		$.ajax(
		{
			url: 'Login.do',
			type: 'post',
			data:
			{
				email: $('input[name=email]').val(),
				password: $('input[name=password]').val()
			},
			success: function(data)
			{
				let obj = JSON.parse(data);
				if(obj.errno == 0)
				{
					location.reload();
				}
			}
		});
	});
	
	$('#btnLogout').click(function()
	{
		$.ajax(
		{
			url: 'Logout.do',
			type: 'post',
			success: function(data)
			{
				if(data.errno == 0)
				{
					location.href = "index.jsp";
				}
			}
		});
	});
	
	$('#btnChangeInfo').click(function()
	{
		location.href="member/update.jsp";
	});
});