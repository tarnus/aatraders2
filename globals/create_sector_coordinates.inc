<?php
if (!function_exists('create_sector_coordinates'))
{
	function create_sector_coordinates()
	{
		global $universe_size, $sector, $index, $collisions, $spiral_galaxy_arms, $angle, $scale;

		//The Spiral Galaxy Code was proviced by "Kelly Shane Harrelson" <shane@mo-ware.com> 
		# need to randomly assign this point to an arm.
		$arm = mt_rand(0,$spiral_galaxy_arms-1);
		$arm_offset = $arm * $angle;

		# generate the logical position on the spiral (0 being closer to the center).
		# the double rand puts more towards the center.
		$u = deg2rad(mt_rand(0, mt_rand(0, 360)));

		# generate the base x,y,z location in cartesian form
		$bx = $u*cos($u+$arm_offset);
		$by = $u*sin($u+$arm_offset);
		$bz = 0.0;

		# generate a max delta from the base x, y, z.
		# this will be larger closer to the center,
		# tapering off the further out you are. 
		# this will create the bulge like effect in 
		# the center.	this is just a rough function
		# and there are probably better ones out there.
		$d = ($u<0.3) ? 1.5 : (log($u,10)*-1.0)+1.0;	# log base 10

		# generate random angles and distance for offsets from base x,y,z
		$dt = deg2rad(mt_rand(0, 360)); # angle theta 0-360
		$dp = deg2rad(mt_rand(0, 360)); # angle phi	0-360
		$dd = $d*mt_rand(1,100)/100;	 # distance	 0-$d

		# based on random angles and distance, generate cartesian offsets for base x,y,z
		$dx = $dd*sin($dt)*cos($dp);
		$dy = $dd*sin($dt)*sin($dp);
		$dz = $dd*cos($dt);

		# we want the arms to flatten out away from center
		$dz *= ($d/1.5);	

		# calcuate final cartesian coordinate 
		$x = $bx + $dx;
		$y = $by + $dy;
		$z = $bz + $dz;

		# now scale them to fit $universe_size
		$x *= $scale;
		$y *= $scale;
		$z *= $scale;

		$sector['x'] = $x;
		$sector['y'] = $y;
		$sector['z'] = $z;
		$sector['spiral_arm'] = $arm;

		// Collision check
		if (isset($index[$sector['x'].','.$sector['y'].','.$sector['z']])) 
		{
			$collisions++;
			create_sector_coordinates();
		} 
		else 
		{
			return true;
		}
	}
}

?>
