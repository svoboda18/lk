#!usr/bin/perl
# Copyright Statement:
#
# This software/firmware and related documentation ("MediaTek Software") are
# protected under relevant copyright laws. The information contained herein
# is confidential and proprietary to MediaTek Inc. and/or its licensors.
# Without the prior written permission of MediaTek inc. and/or its licensors,
# any reproduction, modification, use or disclosure of MediaTek Software,
# and information contained herein, in whole or in part, shall be strictly prohibited.
#
# MediaTek Inc. (C) 2010. All rights reserved.
#
# BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
# THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
# RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
# AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
# NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
# SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
# SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
# THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
# THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
# CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
# SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
# STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
# CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
# AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
# OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
# MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
# The following software/firmware and/or related documentation ("MediaTek Software")
# have been modified by MediaTek Inc. All revisions are subject to any receiver's
# applicable license agreements with MediaTek Inc.


my $base_prj = $ARGV[0];
my $prj = $ARGV[1];
my $custom_dir = $ARGV[2];
my $secro_ac = $ARGV[3];
my $nand_page_size = $ARGV[4];
my $board_avb_enable = $ARGV[5];
my $dir = $ARGV[6];
my $tgt = $ARGV[7];
my $sdl_only = $ARGV[8];
my $cfg_dir = "$custom_dir";
my $cfg_def = "IMG_AUTH_CFG.ini";
my $cfg = "$cfg_dir/$cfg_def";
my $key = "$cfg_dir/IMG_AUTH_KEY.ini";
my $oemkey = "$cfg_dir/VERIFIED_BOOT_IMG_AUTH_KEY.ini";
$ENV{PROJECT}=$prj;
my $secro_type = "GMP";

##########################################################
# Dump Parameter
##########################################################
print "\n\n";
print "********************************************\n";
print " Dump Paramter \n";
print "********************************************\n";
print " Base Project     : $base_prj\n";
print " Project          : $prj\n";
print " Custom Directory : $custom_dir\n";
print " SECRO AC         : $secro_ac\n";
print " NAND Page Size   : $nand_page_size\n";
print " BOARD_AVB_ENABLE : $board_avb_enable\n";
print " PRODUCT_OUT      : $dir\n";
print " SDL_ONLY         : $sdl_only\n";
print " TGT              : $tgt\n";

##########################################################
# Create Folder
##########################################################
print "\n\n";
print "********************************************\n";
print " Create Folder \n";
print "********************************************\n";
`mkdir $dir/sig` if ( ! -d "$dir/sig" );
print "Image Dir '$dir'\n";
my $command = "scripts/sign/SignTool.sh";
#tool for signing image with SHA256 + RSA2048 for verified boot
my $command_2048 = "scripts/sign/SignTool_2048";

##########################################################
# File Check
##########################################################
my @imgs_need_sign_raw = ("lk.img", "logo.bin", "secro.img", "odmdtbo.img", "dtbo.img");
my @imgs_need_sign = ("system.img", "system_other.img", "userdata.img", "efuse.img", "vendor.img", "odm.img", "vbmeta.img", "vbmeta_system.img", "vbmeta_vendor.img", "super.img");

if ($board_avb_enable ne "true") {
	push (@imgs_need_sign_raw, "boot.img");
	push (@imgs_need_sign_raw, "recovery.img");
} else {
	push (@imgs_need_sign, "boot.img");
	push (@imgs_need_sign, "recovery.img");
}

# ProjectConfig.mk settings is not imported here, and try all the possible names
push (@imgs_need_sign, "trustzone.bin");
push (@imgs_need_sign, "mobicore.bin");
push (@imgs_need_sign, "tz.img");
push (@imgs_need_sign, "tee.img");

# Does not check whether all images in the list exist. Sign all the images which can be found.


##########################################################
# Process Common Files
##########################################################
print "\n\n";
print "********************************************\n";
print " Sign Common Images \n";
print "********************************************\n";

# for these images, two layers of signature is applied, one for verified boot, one for secure download.
foreach my $img (@imgs_need_sign_raw) {
	if ("$tgt" ne "all") {
		if ("$tgt" ne $img) {
			warn "$img not selected target($tgt), bypass\n";
			next;
		}
	}

	if ( ! -e "$dir/$img") {
		warn "the $img does NOT exist, please check\n";
		next;
	}

	my $signed_verified_img = $img;
	$signed_verified_img =~ s/\./-verified\./;
	if ($sdl_only eq "yes") {
		print "secure boot signature generation bypassed for '$dir/$img'"
	} else {
		my $sig_img = $img;
		$sig_img =~ s/\.bin/\.sig/;
		$sig_img =~ s/\.img/\.sig/;
		print "Sign Image '$dir/$img' with key '$oemkey'... output = '$dir/$signed_verified_img'\n";
		system("$command_2048 $oemkey $dir/$img $dir/$signed_verified_img $dir/sig/$sig_img") == 0 or die "sign image(verified boot) fail";
	}

	my $signed_img = $img;
	$signed_img =~ s/\./-sign\./;

	my $signed_cfg = "$cfg_dir/$img.ini";
	if ( ! -e "$signed_cfg" ) {
		$signed_cfg = $cfg;
	}
	print "Sign Image '$dir/$img' with cfg '$signed_cfg'...\n";

	system("$command $key $signed_cfg $dir/$signed_verified_img $dir/$signed_img $nand_page_size") == 0 or die "sign image fail";
}

# these images are signed for secure download only and not covered by verified boot.
foreach my $img (@imgs_need_sign) {
	if ("$tgt" ne "all") {
		if ("$tgt" ne $img) {
			warn "$img not selected target($tgt), bypass\n";
			next;
		}
	}

	if ( ! -e "$dir/$img") {
		warn "the $img does NOT exist, please check\n";
		next;
	}

	my $signed_img = $img;
	$signed_img =~ s/\./-sign\./;
	my $signed_cfg = "$cfg_dir/$img.ini";
	if ( ! -e "$signed_cfg" ) {
		$signed_cfg = $cfg;
	}
	print "Sign Image '$dir/$img' with cfg '$signed_cfg'...\n";

	system("$command $key $signed_cfg $dir/$img $dir/$signed_img $nand_page_size") == 0 or die "sign image fail";
}

sub print_system {
	my $command = $_[0];
	my $rslt = system($command);
	print "$command: $rslt\n";
	die "Failed to execute $command" if ($rslt != 0);
}

##########################################################
# Process EMMC Files
##########################################################
print "\n\n";
print "********************************************\n";
print " Sign EMMC Images \n";
print "********************************************\n";

my @imgs_need_sign = ("MBR", "EBR1", "EBR2");

foreach my $img (@imgs_need_sign) {
	if ("$tgt" ne "all") {
		if ("$tgt" ne $img) {
			warn "$img not selected target($tgt), bypass\n";
			next;
		}
	}

	if (-e "$dir/$img") {
		my $signed_cfg = "$cfg_dir/$img.ini";
		if ( ! -e "$signed_cfg" ) {
			$signed_cfg = $cfg;
		}
		print "Sign Image '$dir/$img' with cfg '$signed_cfg'...\n";
		system("$command $key $signed_cfg $dir/$img $dir/${img}-sign $nand_page_size") == 0 or die "sign EMMC image fail";
	}
}

my @imgs_need_sign = ("cache.img", "custom.img");

foreach my $img (@imgs_need_sign) {
	if ("$tgt" ne "all") {
		if ("$tgt" ne $img) {
			warn "$img not selected target($tgt), bypass\n";
			next;
		}
	}

	if (-e "$dir/$img") {
		my $signed_img = $img;
		$signed_img =~ s/\./-sign\./;
		my $signed_cfg = "$cfg_dir/$img.ini";
		if ( ! -e "$signed_cfg" ) {
			$signed_cfg = $cfg;
		}
		print "Sign Image '$dir/$img' with cfg '$signed_cfg'...\n";
		system("$command $key $signed_cfg $dir/$img $dir/$signed_img $nand_page_size") == 0 or die "sign EMMC image fail";
	}
}


print "remove unused *sig files \n";
system("rm -f $dir/*.sig ");
