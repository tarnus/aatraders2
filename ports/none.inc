<?php
$template_object->assign("error_msg", $l_noport);
$template_object->assign("error_msg2", "");
$template_object->assign("gotomain", $l_global_mmenu);
$template_object->display("master_template/genericdie.tpl");

include ("footer.php");

?>
