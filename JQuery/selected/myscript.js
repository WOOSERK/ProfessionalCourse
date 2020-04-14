var menus = [
	['자바', 'C', 'C++'],
	['mariadb', 'mysql', 'oracle'],
	['html', 'css', 'javascript', 'jQuery']
];

$(document).ready(function()
{
	$('#lpart').change(function()
	{
		$('#spart').empty();
		var idx = $(this).find(':selected').index()-1;
			
		$('<option>소분류 선택</option>').appendTo($('#spart'))
		
		for(var i=0; i<menus[idx].length; i++)
		{
			$('<option>' + menus[idx][i] + '</option>').appendTo($('#spart'));
		}

	});
});