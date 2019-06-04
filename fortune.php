<?php
/*
 * display a fortunes from fortunes database
 */
function fortune($database)
{
	$ret = "";
	$db = new PDO("sqlite:" . $database);
	if ( $db ) {
		$res = $db->query("SELECT COUNT(*) FROM FORTUNES");
		foreach ( $res as $row )
			$cnt = $row[0];
		$id = rand(1, $cnt);
	    $res = $db->query("SELECT * FROM FORTUNES WHERE ID='" . $id . "'");
		foreach ( $res as $row )
			$ret = $row['CTEXT'];
		}
	else
		$ret = "fortune: db-open failed";
	return $ret;
}

// echo fortune("diogenis.db");
?>
