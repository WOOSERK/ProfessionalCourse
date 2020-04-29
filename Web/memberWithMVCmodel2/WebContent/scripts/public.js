String.prototype.isEmpty = function()
{
	return (this.trim() == '');
}

String.prototype.equals = function(str)
{
	return (this == str);
}

$.fn.clearAndFocus = function(message)
{
	alert(message);
	$(this).val('').focus();
};