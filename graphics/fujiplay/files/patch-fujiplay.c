--- fujiplay.c.orig	Thu Oct 23 17:04:58 2003
+++ fujiplay.c	Thu Oct 23 17:09:08 2003
@@ -759,40 +759,38 @@
 	return 1;
 }
 
-const char *Usage = "\
-Usage: fujiplay [OPTIONS] PICTURES...          (download)
-                          charge NUMBER        (recharge the flash)
-                          shoot                (take picture)
-                          preview              (preview to standard output)
-                          upload FILES...
-                          delete FILES...
-                          setid STRING         (set camera ID)
-                          setflash MODE        (0=Off, 1=On, 2=Strobe, 3=Auto)
-                          setdate gmt|local|YYYYMMDDHHMMSS
-Options:
-  -B NUMBER	Set baudrate (115200, 57600, 38400, 19200, 9600 or 0)
-  -D DEVICE	Select another device file (default is /dev/fujifilm)
-  -L		List command set
-  -7		DS-7 compatibility mode (experimental)
-  -d		Delete pictures after successful download
-  -f		Force (overwrite existing files)
-  -p		Assume picture numbers instead of frame numbers
-  -h		Display this help message
-  -v		Version information
-Pictures:
-  all		All pictures
-  last		Last picture
-  4		Only picture 4
-  2-10		Pictures between 2 and 10
-Files:
-  DSCxxxxx.JPG	Files to delete or to upload into the camera
-";
+const char *Usage =
+"Usage: fujiplay [OPTIONS] PICTURES...          (download)\n"\
+"                          charge NUMBER        (recharge the flash)\n"\
+"                          shoot                (take picture)\n"\
+"                          preview              (preview to standard output)\n"\
+"                          upload FILES...\n"\
+"                          delete FILES...\n"\
+"                          setid STRING         (set camera ID)\n"\
+"                          setflash MODE        (0=Off, 1=On, 2=Strobe, 3=Auto)\n"\
+"                          setdate gmt|local|YYYYMMDDHHMMSS\n"\
+"Options:\n"\
+"  -B NUMBER	Set baudrate (115200, 57600, 38400, 19200, 9600 or 0)\n"\
+"  -D DEVICE	Select another device file (default is /dev/fujifilm)\n"\
+"  -L		List command set\n"\
+"  -7		DS-7 compatibility mode (experimental)\n"\
+"  -d		Delete pictures after successful download\n"\
+"  -f		Force (overwrite existing files)\n"\
+"  -p		Assume picture numbers instead of frame numbers\n"\
+"  -h		Display this help message\n"\
+"  -v		Version information\n"\
+"Pictures:\n"\
+"  all		All pictures\n"\
+"  last		Last picture\n"\
+"  4		Only picture 4\n"\
+"  2-10		Pictures between 2 and 10\n"\
+"Files:\n"\
+"  DSCxxxxx.JPG	Files to delete or to upload into the camera\n";
 
-const char *Copyright = "\
-Fujiplay, $Id: fujiplay.c,v 1.33 1999/02/22 14:13:01 bousch Exp $
-Written by Thierry Bousch <bousch@topo.math.u-psud.fr>
-Public domain. Absolutely no warranty.
-";
+const char *Copyright =
+"Fujiplay, $Id: fujiplay.c,v 1.33 1999/02/22 14:13:01 bousch Exp $\n"\
+"Written by Thierry Bousch <bousch@topo.math.u-psud.fr>\n"\
+"Public domain. Absolutely no warranty.\n";
 
 static void sigint_handler (int sig)
 {
