function changeNews(interval)
{
	$('.news>ul>li').not(':first-child').fadeOut();
	(function(interval)
	{
		let func = arguments.callee;
		setTimeout(function()
		{
			$('.news>ul>li:first-child').fadeOut(500, function()
			{
				$('.news>ul>li:first-child').appendTo($('.news>ul'));
				$('.news>ul>li:first-child').fadeIn(500);
			});
			func(interval);
		}, interval);
	})(interval);
}

$(document).ready(function()
{
	changeNews(2000);
});
