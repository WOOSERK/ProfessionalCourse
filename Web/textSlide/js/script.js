function changeNews(interval)
{
	setTimeout(function()
	{
		$('.news>ul>li:first-child').slideUp(500, function()
		{
			$('.news>ul>li:first-child').appendTo($('.news>ul'));
			$('.news>ul>li:last-child').css(
			{
				height : '20px',
				display : 'block',
				visibility : 'visible'
			});
		});
		changeNews(interval);
	}, interval);
}

$(document).ready(function()
{
	changeNews(2000);
});