<?php
/*
Plugin Name: Qik Live Stream Widget
Plugin URI: http://danperron.com/
Description: Puts your live Qik Stream in a sidebar widget.
Version: 2.0
Author: Dan Perron
Author URI: http://danperron.com
*/

/*  Copyright 2009  Dan Perron  (email : danp3rr0n@gmail.com)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

if(!class_exists("Qik_Stream_Widget"))
{
	class Qik_Stream_Widget
	{
		var $unique_id = "qik_stream_widget";
		var $options = null;
		var $plugin_path;
		
		function Qik_Stream_Widget()
		{
			$this->plugin_path = WP_PLUGIN_URL.'/'.str_replace(basename(__FILE__),"",plugin_basename(__FILE__));
			
			$this->options = get_option("wp_qik_options");
			
			$old_username = get_option("wp_qik_username",false);
			
			if($old_username)
			{
				$this->options['username'] = $old_username;
				delete_option("wp_qik_username");
				delete_option("wp_qik_label");
				delete_option("wp_qik_show_icon");
				$this->save();
			}
			
			if(!isset($this->options['widget_label']))
			{
				$this->options['widget_label'] = "Qik Stream";
			}
			
			if(!isset($this->options['show_icon']))
			{
				$this->options['show_icon'] = true;
			}
			
			if(!isset($this->options['vid_width']))
			{
				$this->options['vid_width'] = 200;
			}
			
			if(!isset($this->options['vid_height']))
			{
				$this->options['vid_height'] = 150;
			}
			
			$this->save();
			
		}
		
		function save()
		{
			update_option('wp_qik_options',$this->options);
		}
		
		function add_qik_wp_options()
		{
			add_options_page('Qik Settings', 'Qik Stream', 10, $this->unique_id, array(&$this,'wp_qik_settings_page'));
		}
		
		function wp_qik_settings_page()
		{
			include("qik_settings.inc");
		}
		
		function add_wp_qik_widget($args)
		{
			extract($args);
			include("qik_widget.inc");
		}
		
	}
}

if(class_exists("Qik_Stream_Widget"))
{
	$qikstreamwidget = new Qik_Stream_Widget;
	add_action('admin_menu', array(&$qikstreamwidget,'add_qik_wp_options'));
	if(isset($qikstreamwidget->options['username']))
	{
		wp_register_sidebar_widget($qikstreamwidget->unique_id, "Qik Stream",array(&$qikstreamwidget,"add_wp_qik_widget"));
	}
}

//add the settings page to the menu

//add_action('admin_menu', 'add_qik_wp_options');
/*

 * function add_qik_wp_options()
 * {
 * 	add_options_page('Qik Settings', 'Qik Stream', 10, QIK_ID, 'wp_qik_settings_page');
 * }

 * function wp_qik_settings_page()
 * {
 * 	include("qik_settings.inc");
 * }



 * if(get_option("wp_qik_username"))
 * {
 * 	//add the widget
 * 	register_sidebar_widget("Qik Stream", "add_wp_qik_widget");
 * }

 * function add_wp_qik_widget()
 * {
 * 	include("qik_widget.inc");
 * }
 */
