$.fn.changeImage = function(items)
{
	this.click(function()
	{
		let idx = $('.preview>img').data('index');
		if($(this).text() == '이전')
		{
			--idx;
			if(idx < 0)
			{
				idx = items.length - 1;
			}
		}
		else
		{
			++idx;
			if(idx >= items.length)
			{
				idx = 0;
			}	
		}
		
		$('.preview>img').attr('src', items[idx].file);
		$('.preview>img').data('index', idx);
	});
}

$(document).ready(function()
{
	$.ajax({
		url: 'http://localhost:8080/Ajax2/data.txt',
		success: function(data)
		{
			let items = eval('(' + data + ')');
			$('.preview>img').attr('src', items[0].file);
			$('.preview>img').data('index', 0);
			$('button').changeImage(items);
		}
	})
});