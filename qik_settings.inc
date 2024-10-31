<?php

if (isset($_POST['wp_qik_username'])) {
    // update_option("wp_qik_username",trim($_POST['wp_qik_username']));
    //update_option("wp_qik_label",trim($_POST['wp_qik_label']));

    $this->options['username'] = trim($_POST['wp_qik_username']);
    $this->options['widget_label'] = trim($_POST['wp_qik_label']);
    $this->options['vid_width'] = trim($_POST['wp_qik_width']);
	$this->options['vid_height'] = trim($_POST['wp_qik_height']);
	
    if (isset($_POST['show_icon']) && $_POST['show_icon'] == "true") {
        $this->options['show_icon'] = true;
    } else {
        $this->options['show_icon'] = false;
    }
    $this->save();

}

//$widget_label = get_option("wp_qik_label", "Qik Stream");
//$qik_username = get_option("wp_qik_username");
//$show_icon = get_option("wp_qik_show_icon", true);

$widget_label = $this->options['widget_label'];
$qik_username = $this->options['username'];
$show_icon = $this->options['show_icon'];
$vid_width = $this->options['vid_width'];
$vid_height = $this->options['vid_height'];

?>


<div class="wrap">

<div id="icon-options-general" class="icon32"></div>

<h2>Qik Stream Settings</h2>


<?php
if (isset($_POST['wp_qik_username'])) {
    echo "<div>Settings updated!</div>";
}
?>


<form method="post">
<input type="hidden" name="formsent" value="true" />
<table class="form-table">

<tr>
	<th>Qik Username:</th>
	<td><input name="wp_qik_username" type="text" value="<?php echo $qik_username; ?>"/></td>
</tr>

<tr>
	<th>Widget Label:</th>
	<td><input name="wp_qik_label" type="text" value="<?php echo $widget_label; ?>" /></td>
</tr>

<tr>
	<th>Video Width:</th>
	<td><input name="wp_qik_width" type="text" value="<?php echo $vid_width;?>" /></td>
</tr>

<tr>
	<th>Video Height:</th>
	<td><input name="wp_qik_height" type="text" value="<?php echo $vid_height;?>" /></td>
</tr>

<tr>
	<th>Show Icon:</th>
	<td><input name="show_icon" type="checkbox" value="true" <?php if ($show_icon){echo " checked ";} ?> /></td>
</tr>



</table>

<input class="button-primary" type="submit" value="Update Settings" />

</form>

</div>