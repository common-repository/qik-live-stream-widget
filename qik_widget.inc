<?php
//the widget code
$show_icon = (bool)$this->options['show_icon'];
$username = $this->options['username'];
$label = $this->options['widget_label'];

$vid_width = $this->options['vid_width'];
$vid_height = $this->options['vid_height'];

$qik_icon = WP_PLUGIN_URL.'/'.str_replace(basename(__FILE__),"",plugin_basename(__FILE__))."img/qik_icon.png";


echo $before_widget;
echo $before_title;

if ($show_icon)
{
	echo "<img src=\"$qik_icon\" /> ";
}

echo $label;
echo $after_title;
?>

<object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000" codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=9,0,115,0" width="<?php echo $vid_width;?>" height="<?php echo $vid_height;?>" id="qikPlayer" align="middle"><param name="allowScriptAccess" value="sameDomain" /><param name="allowFullScreen" value="true" /><param name="movie" value="http://assets1.qik.com/swfs/qikPlayer5.swf?1279883548" /><param name="quality" value="high" /><param name="bgcolor" value="#000000" /><param name="FlashVars" value="username=<? echo $username; ?>" /><embed src="http://assets1.qik.com/swfs/qikPlayer5.swf?1279883548" quality="high" bgcolor="#000000" width="<?php echo $vid_width;?>" height="<?php echo $vid_height;?>" name="qikPlayer" align="middle" allowScriptAccess="sameDomain" allowFullScreen="true" type="application/x-shockwave-flash" pluginspage="http://www.macromedia.com/go/getflashplayer" FlashVars="username=<? echo $username; ?>"></embed></object>

<?php echo $after_widget; ?>

<!-- Qik Live Stream widget by Dan Perron -->