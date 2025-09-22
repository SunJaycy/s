








#include <rw/core/importnamespaces.h>
#include <rw/core/base/ostypes.h>






#include <rw/core/debug/debug.h>
#include <rw/core/debug/exception.h>




#include <rw/core/debug/manager.h>
#include <rw/core/debug/asserthandler.h>
#include <rw/core/debug/channel.h>
#include <rw/core/debug/device.h>
#include <rw/core/debug/consoledevice.h>
#include <rw/core/debug/filedevice.h>
#include <rw/core/debug/formatter.h>
#include <rw/core/debug/host.h>

#include <rw/core/docmessage/docmessage.h>
#include <rw/core/docmessage/hostdocmsg.h>
#include <rw/core/docmessage/docexception.h>

#include <rw/core/linearalloc.h>
#include <rw/core/guid.h>
#include <rw/core/string.h>
#include <rw/core/threadsafecoreguard.h>

#include <rw/core/timer/timer.h>
#include <rw/core/timer/stopwatch.h>

#include <rw/core/memory/memoryfunctions.h>
#include <rw/core/memory/memoryalignedfunctions.h>
#include <rw/core/memory/linkedlist.h>
#include <rw/core/memory/freelist.h>
#include <rw/core/memory/memoryprofilefunctions.h>
#include <rw/core/memory/memoryinitializers.h>

#include <rw/core/resource/baseresource.h>
#include <rw/core/resource/resource.h>
#include <rw/core/resource/targetresource.h>

#include <rw/core/resource/resourceallocator.h>
#include <rw/core/resource/linearresourceallocator.h>
#include <rw/core/resource/resourceallocatortarget.h>
#include <rw/core/resource/resourceallocatorregistry.h>
#include <rw/core/resource/creator.h>
#include <rw/core/resource/sharedresource.h>








#include <rw/core/spu.h>
#include <rw/core/sputhread.h>


#include <rw/core/cachemanager/cachemanager.h>

#include <rw/core/hash/hash.h>
#include <rw/core/hash/hashcontainer.h>

#include <rw/core/arena/simplevector.h>
#include <rw/core/atom/atomsettings.h>
#include <rw/core/atom/staticatomtable.h>
#include <rw/core/atom/dynamicatomtable.h>
#include <rw/core/atom/globalatomtable.h>
#include <rw/core/atom/unfixrefixatoms.h>

#include <rw/core/arena/arena.h>
#include <rw/core/componentids.h>
#include <rw/core/objecttypes.h>
#include <rw/core/targarena.h>
#include <rw/core/arena/typereg.h>
#include <rw/core/arena/arenabaseresources.h>
#include <rw/core/arena/arenasections.h>


#include <rw/core/bittable/bitarray.h>
#include <rw/core/bittable/bittable.h>

#include <rw/core/coreinitialize.h>



#include <rw/core/staticcontainers.h>

#include <rw/core/endian/endian.h>

#include <rw/core/stdc/memory.h>
#include <rw/core/stdc/util.h>
#include <rw/core/stdc/string.h>
#include <rw/core/stdc/wstring.h>

#include <rw/core/thread/base.h>
#include <rw/core/thread/atomic.h>
#include <rw/core/thread/atomicptr.h>
#include <rw/core/thread/sync.h>
#include <rw/core/thread/thread.h>
#include <rw/core/thread/mutex.h>
#include <rw/core/thread/semaphore.h>
#include <rw/core/thread/condition.h>
#include <rw/core/thread/barrier.h>
#include <rw/core/thread/list.h>
#include <rw/core/thread/pool.h>
#include <rw/core/thread/readwritemutex.h>
#include <rw/core/thread/spinlock.h>
#include <rw/core/thread/readwritespinlock.h>
#include <rw/core/thread/storage.h>

#include <rw/core/codec/icodec.h>
#include <rw/core/codec/refpack.h>

#include <rw/core/filesys/manager.h>
#include <rw/core/filesys/async.h>
#include <rw/core/filesys/device.h>
#include <rw/core/filesys/directory.h>
#include <rw/core/filesys/loadsave.h>
#include <rw/core/filesys/scatterload.h>
#include <rw/core/filesys/stream.h>
#include <rw/core/filesys/ifilestream.h>

#include <rw/core/controller/manager.h>
#include <rw/core/controller/deviceinfo.h>
#include <rw/core/controller/devicestate.h>
#include <rw/core/controller/ideviceeffect.h>

#include <rw/core/xml/xml.h>
#include <rw/core/xml/parser.h>
#include <rw/core/xml/writer.h>
