var gPage = 1;
var gFlag = true;

$.fn.bindClick = function()
{
	this.click(function()
	{
		$('.main > img').attr('src', $(this).attr('src'));	
	});
};

$.getList = function(page)
{
	if(!gFlag)
	{
		console.log("현재 처리중인 작업이 있습니다.");
		return;
	}
	
	gFlag = false;
	
	$.ajax(
	{
		url: 'getList2',
		type: 'get',
		data: { page: page },
		success: function(data)
		{
			if(data.list.length != 0)
			{				
				for(var i=0; i<data.list.length; i++)
				{
					let li = $('<li>');
					let img = $('<img>', { src: "images/" + data.list[i]} );
					img.appendTo(li);
					li.appendTo($('.side > ul'));
					img.bindClick();
				}
				
				if(gPage == 1)
				{
					let mainImg = $('<img>', { src: "images/" + data.list[0] }).appendTo($('.main'));					
				}
				
				gPage++;
			}
			gFlag = true;
		}
	});
};

$(document).ready(function()
{
	$('.side').scroll(function()
	{
		console.log(this.scrollHeight + " : " + this.scrollTop);
		if(this.scrollHeight - this.scrollTop < 500)
		{
			//alert(gPage + "페이지를 요청합니다.");
			$.getList(gPage);
		}
	});
	$('.side > ul').empty();
	$('.main').empty();
	
	$.getList(gPage);
});