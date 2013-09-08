<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
 <head>
  <META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=<?php echo $this->_vars['game_charset']; ?>">
  <link rel="icon" href="favicon.ico"> 
  <link rel="shortcut icon" href="favicon.ico">
  <link rel="stylesheet" href="<?php echo $this->_vars['style_sheet_file']; ?>" type="text/css">


<link rel="stylesheet" type="text/css" href="
<?php extract($this->_vars, EXTR_REFS);  
if(is_file("templates/windowed_menu/player_window_positions/" . $player_id . "_window_positions.css"))
{
	echo "templates/windowed_menu/player_window_positions/" . $player_id . "_window_positions.css";
}
else
{
	echo "templates/windowed_menu/player_window_positions/default_window_positions.css";
}
 ?>
">
<title><?php echo $this->_vars['Title']; ?> - Alien Assault Traders - a  multiplayer turn based strategy online roleplaying space game - MPOG  MPORPG</title> 
<meta name="description" content="Alien Assault Traders allows you to explore, trade, build and dominate in an  science fiction universe.  Form alliance, trade commodites, discover artifacts, fight and defend against invasiomn. Make friends and enemies in this multiplayer on line game adventure."> 
<meta name="keywords" content="AATRADE, Alien Assault Traders Online, cool online game, scifi, explore, discover, dominate, space, spaceship, science fiction, Blacknova, Trade wars, free, browser game, electronics, games, computers, computer games">
 </head>
<?php if ($this->_vars['no_body'] != 1): ?>
<?php if ($this->_vars['currentprogram'] != "main.inc"): ?>
<body marginheight=0 marginwidth=0 topmargin=0 leftmargin=0 background="templates/windowed_menu/images/bgoutspace1.gif" bgcolor="#000000" text="#c0c0c0" link="#52ACEA" vlink="#52ACEA" alink="#52ACEA">
<?php else: ?>
<body marginheight=0 marginwidth=0 topmargin=0 leftmargin=0 bgcolor="#222222" text="#c0c0c0" link="#52ACEA" vlink="#52ACEA" alink="#52ACEA">
<?php endif; ?>
<?php echo $this->_vars['banner_top']; ?>

<?php if ($this->_vars['currentprogram'] != "main.inc"): ?>
<table width="100%" border=0 cellspacing=0 cellpadding=0>
	<tr>		  
	  <td>
<?php endif; ?>
<?php endif; ?>
