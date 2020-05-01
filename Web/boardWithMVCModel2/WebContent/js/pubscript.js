String.prototype.equals = function(_string) {
	return (this == _string);
}

String.prototype.isEmpty = function() {
	return (this.trim() == '');
}

String.prototype.replaceAll = function(_findValue, _replaceValue){
	return this.replace(new RegExp(_findValue,'g'), _replaceValue);
}

String.prototype.isMail = function(){
	return new RegExp('^[a-z][a-z0-9_.]{1,20}@[a-z0-9_]{3,20}\.((com|net|gov)|((co|pe|ne|go|ac)\.(kr|en|cn|jp)))$', 'ig').test(this);
}

String.prototype.isID = function(){
	return new RegExp('^[a-z][a-z0-9]{5,11}$', 'ig').test(this);
}

String.prototype.formatCurrency = function(){
	str = '';
	for (i=this.length-1 ; i>=0 ; i--){				
		str = this.substring(i, i+1) + str; 
		if ( ((this.length - i) % 3 == 0)  &&  (i > 0) ){
			str = ',' + str;
		}
	}
	return str;
}

String.prototype.isPassword = function(){
	return new RegExp('.{6,12}$', 'ig').test(this);
}

String.prototype.isTel = function(){
	return new RegExp('^0[0-9]{1,2}-[0-9]{3,4}-[0-9]{4}$', 'ig').test(this);
}

String.prototype.isInteger = function(){
	return new RegExp('^[0-9]*$', 'ig').test(this);			
}

String.prototype.isYear = function(){
	return new RegExp('^[0-9]{4}$', 'ig').test(this);
}

String.prototype.isMonth = function(){	
	if (parseInt(this) < 1){
		return false;
	}
	if (parseInt(this) > 12){
		return false;
	}
	return new RegExp('^[0-9]{1,2}$', 'ig').test(this);
}

String.prototype.isDay = function(){		
	if (parseInt(this) < 1){
		return false;
	}
	if (parseInt(this) > 31){
		return false;
	}
	return new RegExp('^[0-9]{1,2}$', 'ig').test(this);	
}

String.prototype.isHour = function(){	
	if (parseInt(this) < 0){
		return false;
	}
	if (parseInt(this) > 23){
		return false;	
	}
	return new RegExp('^[0-9]{1,2}$', 'ig').test(this);
}

String.prototype.isMinute = function(){
	if (parseInt(this) < 0){
		return false;
	}
	if (parseInt(this) > 60){
		return false;
	}
	return new RegExp('^[0-9]{1,2}$', 'ig').test(this);
}

String.prototype.isImageFile = function(){
	return new RegExp('(jpg|png|gif)$', 'ig').test(this);
}

String.prototype.go = function(){
	location.href = this;	
}
