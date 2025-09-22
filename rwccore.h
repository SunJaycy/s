












































template <typename MATRIX4X3TYPE, typename VECTOR3TYPE, class MemoryDumpPolicy>
class AABBoxTemplate
{
public:
    typedef MATRIX4X3TYPE Matrix4x3Type;
    typedef VECTOR3TYPE Vector3Type;
    typedef typename VECTOR3TYPE::FloatType FloatType;
    typedef typename VECTOR3TYPE::FastFloatType FastFloatType;
    Vector3Type m_min;
    Vector3Type m_max;

    static rw::core::arena::SizeAndAlignment *
    Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset)
    {
        return MemoryDumpPolicy::Unfix(ptr, offset);
    }
    static void
    Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator)
    {
        MemoryDumpPolicy::Refix(ptr, offset, iterator);
    }
    static RwBool
    Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator)
    {
        return MemoryDumpPolicy::Fixup(ptr, iterator);
    }
    static void
    RegisterArenaReadCallbacks(void)
    {
        MemoryDumpPolicy::RegisterArenaReadCallbacks();
    }
    static void
    RegisterArenaWriteCallbacks(void)
    {
        MemoryDumpPolicy::RegisterArenaWriteCallbacks();
    }

    AABBoxTemplate() {}
    AABBoxTemplate(const Vector3Type &min_,
                   const Vector3Type &max_)
    {
        ;
        m_min = min_;
        m_max = max_;
        return;
    }
    AABBoxTemplate(FloatType minx, FloatType miny, FloatType minz,
                   FloatType maxx, FloatType maxy, FloatType maxz)
        : m_min(Vector3Type(minx, miny, minz)),
          m_max(Vector3Type(maxx, maxy, maxz)) {}
    void
    Set(const Vector3Type &min,
        const Vector3Type &max)
    {
        ;
        m_min = min;
        m_max = max;
        return;
    }
    RwBool
    IsValid() const
    {
        ;
        RwBool result =
                (static_cast<float>(m_min.X()) <= static_cast<float>(m_max.X()))
            && (static_cast<float>(m_min.Y()) <= static_cast<float>(m_max.Y()))
            && (static_cast<float>(m_min.Z()) <= static_cast<float>(m_max.Z()));
        return result;
    }
    const Vector3Type &
    Min() const
    {
        ;
        return m_min;
    }
    const Vector3Type &
    Max() const
    {
        ;
        return m_max;
    }
    AABBoxTemplate
    Scale(FloatType scale) const
    {
        ;
        ;
        FastFloatType scalefactor((scale - static_cast<FloatType>(1.0)) * static_cast<FloatType>(0.5));
        Vector3Type offset = (m_max - m_min) * scalefactor;
        AABBoxTemplate sclBox(m_min - offset, m_max + offset);
        return sclBox;
    }
    RwBool
    Overlaps(const AABBoxTemplate &bb2) const
    {
        ;
        ;
        RwBool result =
                (static_cast<float>(bb2.m_max.X()) >= static_cast<float>(m_min.X()))
            && (static_cast<float>(bb2.m_min.X()) <= static_cast<float>(m_max.X()))
            && (static_cast<float>(bb2.m_max.Y()) >= static_cast<float>(m_min.Y()))
            && (static_cast<float>(bb2.m_min.Y()) <= static_cast<float>(m_max.Y()))
            && (static_cast<float>(bb2.m_max.Z()) >= static_cast<float>(m_min.Z()))
            && (static_cast<float>(bb2.m_min.Z()) <= static_cast<float>(m_max.Z()));
        return result;
    }
    float32_t
    Distance(const AABBoxTemplate &other) const
    {
        ;
        ;
        Vector3Type temp = rw::math::Max(m_min - other.m_max, other.m_min - m_max);
        return rw::math::Max((float32_t)(temp.X()), (float32_t)(temp.Y()), (float32_t)(temp.Z()));
    }
    RwBool
    Contains(const AABBoxTemplate &bb2) const
    {
        ;
        ;
        RwBool result =
                (static_cast<float>(bb2.m_max.X()) <= static_cast<float>(m_max.X()))
            && (static_cast<float>(bb2.m_min.X()) >= static_cast<float>(m_min.X()))
            && (static_cast<float>(bb2.m_max.Y()) <= static_cast<float>(m_max.Y()))
            && (static_cast<float>(bb2.m_min.Y()) >= static_cast<float>(m_min.Y()))
            && (static_cast<float>(bb2.m_max.Z()) <= static_cast<float>(m_max.Z()))
            && (static_cast<float>(bb2.m_min.Z()) >= static_cast<float>(m_min.Z()));
        return result;
    }
    AABBoxTemplate
    Transform(const Matrix4x3Type *mtx) const
    {
        ;
        ;
        if (!mtx)
        {
            return *this;
        }
        Vector3Type center = (m_max + m_min) * FastFloatType(0.5f);
        center = TransformPoint(center, *mtx);
        Vector3Type diag = (m_max - m_min) * FastFloatType(0.5f);
        diag = Abs(mtx->XAxis()) * (diag.X())
             + Abs(mtx->YAxis()) * (diag.Y())
             + Abs(mtx->ZAxis()) * (diag.Z());
        AABBoxTemplate result(center - diag, center + diag);
        return result;
    }
};
template <class AABBoxType>
AABBoxType
Union(const AABBoxType &bb1, const AABBoxType &bb2)
{
    ;
    AABBoxType bb;
    bb.m_min = Min(bb1.m_min, bb2.m_min);
    bb.m_max = Max(bb1.m_max, bb2.m_max);
    return bb;
}
namespace rw
{
namespace collision
{

struct AABBoxUMemoryDumpPolicyInterface {};
typedef AABBoxTemplate<rw::math::fpu::Matrix44AffineU_32,
                       rw::math::fpu::Vector3U_32,
                       AABBoxUMemoryDumpPolicyInterface> AABBoxU;
struct AABBoxMemoryDumpPolicy
{
    static rw::core::arena::SizeAndAlignment *
    Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset);
    static void
    Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator);
    static RwBool
    Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator);
    static void
    RegisterArenaReadCallbacks(void);
    static void
    RegisterArenaWriteCallbacks(void);
};



typedef AABBoxTemplate<rw::math::Matrix44Affine,
                       rw::math::Vector3,
                       AABBoxMemoryDumpPolicy> AABBox;
}
}
template <>
inline RwBool
AABBoxTemplate<rw::math::Matrix44Affine, rw::math::Vector3, rw::collision::AABBoxMemoryDumpPolicy>::Overlaps(const AABBoxTemplate &bb2) const
{
    ;

    __attribute__((altivec(vector__))) unsigned int zero = static_cast<__attribute__((altivec(vector__))) unsigned int>(vec_splat_s32(0));
    __attribute__((altivec(vector__))) unsigned int cmpgt1 = static_cast<__attribute__((altivec(vector__))) unsigned int>(vec_cmpgt(m_min.GetVector(), bb2.m_max.GetVector()));
    __attribute__((altivec(vector__))) unsigned int cmpgt2 = static_cast<__attribute__((altivec(vector__))) unsigned int>(vec_cmpgt(bb2.m_min.GetVector(), m_max.GetVector()));
    __attribute__((altivec(vector__))) unsigned int both = vec_or(cmpgt1, cmpgt2);
    __attribute__((altivec(vector__))) unsigned int chop = vec_sld(zero, both, 12);
    return vec_all_eq(zero, chop);













}
template <>
inline RwBool
AABBoxTemplate<rw::math::Matrix44Affine, rw::math::Vector3, rw::collision::AABBoxMemoryDumpPolicy>::Contains(const AABBoxTemplate &bb2) const
{
    ;

    __attribute__((altivec(vector__))) unsigned int zero = static_cast<__attribute__((altivec(vector__))) unsigned int>(vec_splat_s32(0));
    __attribute__((altivec(vector__))) unsigned int cmpgt1 = static_cast<__attribute__((altivec(vector__))) unsigned int>(vec_cmpgt(bb2.m_max.GetVector(), m_max.GetVector()));
    __attribute__((altivec(vector__))) unsigned int cmpgt2 = static_cast<__attribute__((altivec(vector__))) unsigned int>(vec_cmpgt(m_min.GetVector(), bb2.m_min.GetVector()));
    __attribute__((altivec(vector__))) unsigned int both = vec_or(cmpgt1, cmpgt2);
    __attribute__((altivec(vector__))) unsigned int chop = vec_sld(zero, both, 12);
    return vec_all_eq(zero, chop);













}









namespace rw
{
namespace collision
{

class AALineClipper
{
public:
    rw::math::Vector3 m_origin;
    rw::math::Vector3 m_delta;
    rw::math::Vector3 m_recip;
    rw::math::Vector3 m_padding;
    void
    Init(rw::math::Vector3::InParam start,
         rw::math::Vector3::InParam end,
         rw::math::Vector3::InParam padding,
         const AABBox &bbox)
    {
        ;
        rw::math::Vector3 extentTol, hdelta, absHDelta, signHDelta, extentTolPad, offset;
        extentTol = Max(Abs(bbox.m_min), Abs(bbox.m_max));
        extentTol = Max(extentTol, Abs(start));
        extentTol *= rw::math::VecFloat(1e-6f);
        hdelta = (end - start) * rw::math::VecFloat(0.5f);
        absHDelta = Abs(hdelta);
        signHDelta.Set(rw::math::fpu::SgnNonZero((float32_t)hdelta.X()), rw::math::fpu::SgnNonZero((float32_t)hdelta.Y()), rw::math::fpu::SgnNonZero((float32_t)hdelta.Z()));
        extentTolPad = Max(absHDelta, extentTol) - absHDelta;
        offset = Mult(signHDelta, extentTolPad);
        m_origin = start - offset;
        m_delta = end + offset - m_origin;
  ;
  ;
  ;
        m_recip = rw::math::_asmReciprocal(m_delta.GetVector());
        m_padding = padding + extentTolPad;
        return;
    }
    AALineClipper(rw::math::Vector3::InParam start,
                  rw::math::Vector3::InParam end,
                  rw::math::Vector3::InParam padding,
                  const AABBox &bbox)
    {
        ;
        math::Vector3 epsPadding = math::Max(math::Abs(start), math::Abs(end)) * math::VecFloat(1e-6f);
        Init(start, end, padding + epsPadding, bbox);
        return;
    }
    AALineClipper(rw::math::Vector3::InParam start,
                  rw::math::Vector3::InParam end,
                  const AABBox &bbox)
    {
        ;
        math::Vector3 epsPadding = math::Max(math::Abs(start), math::Abs(end)) * math::VecFloat(1e-6f);
        Init(start, end, epsPadding, bbox);
        return;
    }
    RwBool
    ClipToAABBox(float32_t &pa,
                 float32_t &pb,
                 const AABBox &bbox)
    {
        ;
        rw::math::Vector3 vpmin = Mult(m_recip, (bbox.m_min - m_padding - m_origin));
        rw::math::Vector3 vpmax = Mult(m_recip, (bbox.m_max + m_padding - m_origin));
        rw::math::Vector3 vp0 = Min(vpmin, vpmax);
        rw::math::Vector3 vp1 = Max(vpmin, vpmax);
        pa = rw::math::Max(pa, rw::math::Max((float32_t)vp0.X(), (float32_t)vp0.Y(), (float32_t)vp0.Z()));
        pb = rw::math::Min(pb, rw::math::Min((float32_t)vp1.X(), (float32_t)vp1.Y(), (float32_t)vp1.Z()));
        return pa < pb;
    }
};
}
}










namespace rw
{
namespace collision
{





class KDTree
{
private:
    KDTree();
public:
    struct NodeRef
    {
        uint32_t m_content;
        uint32_t m_index;
    };
    struct BranchNode
    {
        uint32_t m_parent;
        uint32_t m_axis;
        NodeRef m_childRefs[2];
        float32_t m_extents[2];
    };
    BranchNode* m_branchNodes;
    uint32_t m_numBranchNodes;
    uint32_t m_numEntries;
    AABBox m_bbox;
    static rw::ResourceDescriptor
    GetResourceDescriptor(uint32_t numBranchNodes,
                          uint32_t ,
                          const rw::collision::AABBox &)
    {
        ;
        uint32_t size = (((sizeof(KDTree)) + ((16) - 1)) & ~((16) - 1)) + numBranchNodes * sizeof(BranchNode);
        return rw::ResourceDescriptor(size, 16);
    }
    static KDTree *
    Initialize(const rw::Resource& resource,
               uint32_t numBranchNodes,
               uint32_t numEntries,
               const rw::collision::AABBox &bbox)
    {
        ;
        ;
        KDTree *kdtree = static_cast<KDTree *>(resource.GetMemoryResource());
        kdtree->m_numBranchNodes = numBranchNodes;
        kdtree->m_numEntries = numEntries;
        kdtree->m_bbox = bbox;
        if (numBranchNodes > 0)
        {
            kdtree->m_branchNodes = (BranchNode *)((void *)(((rw::HostPtr)(kdtree + 1) + ((rw::HostPtr)(16) - 1)) & ~((rw::HostPtr)(16) - 1)));
        }
        else
        {
            kdtree->m_branchNodes = static_cast<BranchNode *>(0);
        }
        return kdtree;
    }
    void
    Release()
    {
        ;
        return;
    }
    RwBool
    IsValid() const;
    static rw::core::arena::SizeAndAlignment *
    Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset);
    static void
    Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator);
    static RwBool
    Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator);
    uint32_t
    GetNumBranchNodes() const
    {
        ;
        return m_numBranchNodes;
    }
    uint32_t
    GetNumEntries() const
    {
        ;
        return m_numEntries;
    }
 const rw::collision::AABBox &
    GetBBox() const
    {
        ;
        return m_bbox;
    }
    class LineQuery
    {
    public:
        struct StackElement
        {
            NodeRef m_nodeRef;
            float32_t m_pa;
            float32_t m_pb;
        };
        const KDTree *m_kdtree;
        AALineClipper m_lineClipper;
        StackElement m_stack[32];
        uint32_t m_top;
        uint32_t m_leafCount;
        uint32_t m_nextEntry;
        LineQuery(const KDTree *kdtree,
                  rw::math::Vector3::InParam start,
                  rw::math::Vector3::InParam end,
                  const float32_t fatness = 0.0f)
        : m_kdtree(kdtree),
            m_lineClipper(start, end, rw::math::Vector3(fatness, fatness, fatness), kdtree->m_bbox),
            m_leafCount(0),
            m_nextEntry(0)
        {
            ;
            m_stack[0].m_pa = 0.0f;
            m_stack[0].m_pb = 1.0f;
            if (!m_lineClipper.ClipToAABBox(m_stack[0].m_pa, m_stack[0].m_pb, m_kdtree->m_bbox))
            {
                m_top = 0;
            }
            else if (kdtree->m_numBranchNodes > 0)
            {
                m_stack[0].m_nodeRef.m_content = 0xffffffff;
                m_stack[0].m_nodeRef.m_index = 0;
                m_top = 1;
            }
            else
            {
                m_leafCount = kdtree->m_numEntries;
                m_nextEntry = 0;
                m_top = 0;
            }
            return;
        }
        void
        ProcessBranchNode()
        {
            ;
            StackElement cur = m_stack[--m_top];
            ;
            BranchNode &node = m_kdtree->m_branchNodes[cur.m_nodeRef.m_index];
            float32_t p[2];
            float32_t origin = m_lineClipper.m_origin.GetComponent(node.m_axis);
            float32_t pad = m_lineClipper.m_padding.GetComponent(node.m_axis);
            float32_t recip = m_lineClipper.m_recip.GetComponent(node.m_axis);
            p[0] = (node.m_extents[0] + pad - origin) * recip;
            p[1] = (node.m_extents[1] - pad - origin) * recip;
            uint32_t farBranch = (recip > 0);
            if (cur.m_pb > p[farBranch])
            {
                m_stack[m_top].m_nodeRef = node.m_childRefs[farBranch];
                m_stack[m_top].m_pa = rw::math::Max(cur.m_pa, p[farBranch]);
                m_stack[m_top].m_pb = cur.m_pb;
                m_top++;
            }
            uint32_t nearBranch = !farBranch;
            if (cur.m_pa < p[nearBranch])
            {
                m_stack[m_top].m_nodeRef = node.m_childRefs[nearBranch];
                m_stack[m_top].m_pa = cur.m_pa;
                m_stack[m_top].m_pb = rw::math::Min(cur.m_pb, p[nearBranch]);
                m_top++;
            }
            return;
        }
        RwBool
        GetNext(uint32_t &entry)
        {
            ;
            while (m_leafCount == 0)
            {
                for ( ;; )
                {
                    if (m_top == 0)
                    {
                        return (0);
                    }
                    if (m_stack[m_top-1].m_nodeRef.m_content != 0xffffffff)
                    {
                        break;
                    }
                    ProcessBranchNode();
                }
                m_top--;
                m_leafCount = m_stack[m_top].m_nodeRef.m_content;
                m_nextEntry = m_stack[m_top].m_nodeRef.m_index;
            }
            entry = m_nextEntry++;
            m_leafCount--;
            return (1);
        }
        RwBool
        GetNext(uint32_t &entry, uint32_t &count)
        {
            ;
            if (!GetNext(entry))
            {
                return (0);
            }
            count = m_leafCount + 1;
            m_leafCount = 0;
            return (1);
        }
        void
        ClipEnd(float32_t endVal)
        {
            ;
            uint32_t i, iKeep;
            for (i=0, iKeep=0; i < m_top; i++)
            {
                if (m_stack[i].m_pa <= endVal)
                {
                    m_stack[iKeep] = m_stack[i];
                    m_stack[iKeep].m_pb = rw::math::Min(m_stack[iKeep].m_pb, endVal);
                    iKeep++;
                }
            }
            m_top = iKeep;
            return;
        }
    };
    class BBoxQuery
    {
    public:
        const KDTree *m_kdtree;
        AABBox m_bbox;
        uint32_t m_stack[32];
        uint32_t m_top;
        uint32_t m_resultCount;
        uint32_t m_nextEntry;
        BBoxQuery(const KDTree *kdtree,
                  const AABBox &bbox)
        : m_kdtree(kdtree),
            m_bbox(bbox),
            m_resultCount(0),
            m_nextEntry(0)
        {
            ;
            if (kdtree->m_numBranchNodes > 0)
            {
                m_stack[0] = 0;
                m_top = 1;
            }
            else
            {
                m_resultCount = kdtree->m_numEntries;
                m_nextEntry = 0;
                m_top = 0;
            }
            return;
        }
        void
        ProcessBranchNode()
        {
            ;
            ;
            BranchNode &node = m_kdtree->m_branchNodes[m_stack[--m_top]];
            m_resultCount = 0;
            if (static_cast<float>(m_bbox.m_max.GetComponent(node.m_axis)) >= node.m_extents[1])
            {
                if (0xffffffff == node.m_childRefs[1].m_content)
                {
                    ;
                    m_stack[m_top++] = node.m_childRefs[1].m_index;
                }
                else
                {
                    m_resultCount += node.m_childRefs[1].m_content;
                    m_nextEntry = node.m_childRefs[1].m_index;
                }
            }
            if (static_cast<float>(m_bbox.m_min.GetComponent(node.m_axis)) <= node.m_extents[0])
            {
                if (0xffffffff == node.m_childRefs[0].m_content)
                {
                    ;
                    m_stack[m_top++] = node.m_childRefs[0].m_index;
                }
                else
                {
                    m_resultCount += node.m_childRefs[0].m_content;
                    m_nextEntry = node.m_childRefs[0].m_index;
                }
            }
            return;
        }
        RwBool
        GetNext(uint32_t &entry)
        {
            ;
            while (m_resultCount == 0)
            {
                if (m_top == 0)
                {
                    return (0);
                }
                ProcessBranchNode();
            }
            entry = m_nextEntry++;
            m_resultCount--;
            return (1);
        }
        RwBool
        GetNext(uint32_t &entry, uint32_t &count)
        {
            ;
            if (!GetNext(entry))
            {
                return (0);
            }
            count = m_resultCount + 1;
            m_resultCount = 0;
            return (1);
        }
    };




    template<typename NODEDATA>
    class Traversal
    {
    public:
        class StackValue
        {
        public:
            KDTree::NodeRef m_nodeRef;
            NODEDATA m_data;
        };
        const KDTree *m_kdtree;
        StackValue m_stack[32];
        uint32_t m_top;
        KDTree::NodeRef m_cur;
        Traversal(const KDTree *tree, const NODEDATA &data)
            : m_kdtree(tree), m_top(0)
        {
            ;
            Reset(data);
            return;
        }
        void
        Reset(const NODEDATA &data)
        {
            ;
            m_stack[0].m_nodeRef.m_content =
                (m_kdtree->m_numBranchNodes > 0) ? 0xffffffff : m_kdtree->m_numEntries;
            m_stack[0].m_nodeRef.m_index = 0;
            m_stack[0].m_data = data;
            m_top = 1;
            m_cur.m_content = 0;
            m_cur.m_index = 0xffffffff;
            return;
        }
        RwBool
        PopNode(NODEDATA &data)
        {
            ;
            if (m_top > 0)
            {
                data = m_stack[--m_top].m_data;
                m_cur = m_stack[m_top].m_nodeRef;
                return (1);
            }
            return (0);
        }
        void
        PushChildNode(uint32_t idx, const NODEDATA &data)
        {
            ;
            m_stack[m_top].m_nodeRef = m_kdtree->m_branchNodes[GetBranchIndex()].m_childRefs[idx];
            m_stack[m_top++].m_data = data;
            return;
        }
        RwBool
        CurrentNodeIsBranch() const
        {
            ;
            ;

            return m_cur.m_content == 0xffffffff;
        }
        uint32_t
        GetBranchIndex() const
        {
            ;
            ;
            return m_cur.m_index;
        }
        void
        GetLeafNodeEntries(uint32_t &first, uint32_t &count) const
        {
            ;
            ;
            first = m_cur.m_index;
            count = m_cur.m_content;
            return;
        }
    };
};



}
}










namespace rw
{
namespace collision
{
class Aggregate;

enum ObjectType
{
    RWCOBJECTTYPE_NA = ((((rwCOMPONENTID_COLLISION) & 0xff) << 16) | ((0x00) & 0xff)),
    RWCOBJECTTYPE_VOLUME = ((((rwCOMPONENTID_COLLISION) & 0xff) << 16) | ((0x01) & 0xff)),
    RWCOBJECTTYPE_SIMPLEMAPPEDARRAY = ((((rwCOMPONENTID_COLLISION) & 0xff) << 16) | ((0x02) & 0xff)),
    RWCOBJECTTYPE_TRIANGLEKDTREEPROCEDURAL = ((((rwCOMPONENTID_COLLISION) & 0xff) << 16) | ((0x03) & 0xff)),
    RWCOBJECTTYPE_KDTREEMAPPEDARRAY = ((((rwCOMPONENTID_COLLISION) & 0xff) << 16) | ((0x04) & 0xff)),
    RWCOBJECTTYPE_BBOX = ((((rwCOMPONENTID_COLLISION) & 0xff) << 16) | ((0x05) & 0xff)),
    RWCOBJECTTYPE_CLUSTEREDMESH = ((((rwCOMPONENTID_COLLISION) & 0xff) << 16) | ((0x06) & 0xff)),
    RWCOBJECTTYPE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
typedef enum ObjectType ObjectType;

struct SphereSpecificData
{
    void *nothing;
};
struct CapsuleSpecificData
{
    float32_t hh;
};
struct TriangleSpecificData
{
    float32_t edgeCos0;
    float32_t edgeCos1;
    float32_t edgeCos2;
};
struct BoxSpecificData
{
    float32_t hx;
    float32_t hy;
    float32_t hz;
};
struct CylinderSpecificData
{
    float32_t hh;
    float32_t innerRadius;
};
struct AggregateSpecificData
{
    Aggregate *agg;
};
}
}









namespace rw
{
namespace collision
{

    const rw::math::VecFloat VEC_EPSILON(rw::math::EPSILON);
typedef class Volume Volume;
class VolumeLineQuery;
class VolumeBBoxQuery;
struct FeatureEdge
{
    rw::math::Vector3 base, dir, pn;
    rw::math::VecFloat length;
    inline FeatureEdge()
    {
    }
    inline FeatureEdge( const rw::math::Vector3 &p1,
                        const rw::math::Vector3 &p2 )
    {
        ;
        base = p1;
        rw::math::Vector3 delta = p2 - p1;
        rw::math::vpu::VecFloat lengthSq = MagnitudeSquared(delta);
        rw::math::vpu::MaskScalar nonZero = rw::math::vpu::CompGreaterThan(lengthSq, VEC_EPSILON);
        length = rw::math::vpu::Select(nonZero, rw::math::vpu::SqrtFast(lengthSq), rw::math::vpu::GetVecFloat_Zero());
        dir = rw::math::vpu::Select(nonZero, delta * rw::math::vpu::ReciprocalFast(length), rw::math::vpu::GetVector3_Zero());
        return;
    }
    FeatureEdge( const rw::math::Vector3 & newbase, const rw::math::Vector3 & newdir,
        const rw::math::VecFloat & newlength )
    {
        base = newbase;
        dir = newdir;
        length = newlength;
    }
    FeatureEdge( const rw::math::Vector3 & newbase, const rw::math::Vector3 & newdir,
                 const rw::math::Vector3 & newpn, const rw::math::VecFloat & newlength )
    {
        base = newbase;
        dir = newdir;
        pn = newpn;
        length = newlength;
    }
    inline void
    build_plane( const rw::math::Vector3 &extrusion_dir )
    {
        pn = rw::math::Cross( dir, extrusion_dir );
        rw::math::vpu::VecFloat lengthSq = MagnitudeSquared(pn);
        pn *= rw::math::vpu::Select(rw::math::vpu::CompGreaterThan(lengthSq, VEC_EPSILON), InvSqrtFast(lengthSq),rw::math::vpu::GetVecFloat_Zero());
    }
    rw::math::Vector3 endpoint() const
    {
        return base + dir * length;
    }
    rw::math::Vector3 midpoint() const
    {
        return base + (dir * length * rw::math::vpu::GetVecFloat_Half());
    }
uint32_t
    constrain_point( rw::math::Vector3 &pt ) const
    {
        ;
        rw::math::vpu::VecFloat pt_t = rw::math::Dot( pt - base, dir );
        if (pt_t < 0.0f)
        {
            pt = base;
            return 1;
        }
        if (pt_t > length)
        {
            pt = endpoint();
            return 3;
        }
        pt = base + dir * rw::math::vpu::VecFloat(pt_t);
        return 2;
    }
};
struct Feature
{
    enum
    {
        MAXEDGECOUNT = 8
    };
    uint32_t region;
    FeatureEdge edges[MAXEDGECOUNT];
    rw::math::Vector3 ownNormal;
    rw::math::Vector3 pt;
    int32_t numedges;
    rw::math::Vector3 Center()
    {
        ;
        if ( numedges == 0 )
        {
            return pt;
        }
        rw::math::Vector3 c(0,0,0);
        for ( int32_t i = 0; i < numedges; i++ )
        {
            c += edges[i].base + edges[i].endpoint();
        }
        return c / rw::math::VecFloat( numedges * 2.0f );
    }
    int32_t MappedType()
    {
        ;
        return numedges > 1 ? 3 : (numedges & 1);
    }
    void BuildEdgePlanes( RwBool ccw, const rw::math::Vector3 &extrusion_dir )
    {
        ;
        if ( ccw )
        {
            for ( int32_t i = 0; i < numedges; i++ )
            {
                edges[i].build_plane( extrusion_dir );
            }
        }
        else
        {
            for ( int32_t i = 0; i < numedges; i++ )
            {
                edges[i].build_plane( -extrusion_dir );
            }
        }
        return;
    }
    void BuildEdgePlanes( const rw::math::Vector3 &extrusion_dir )
    {
        ;
        for ( int32_t i = 0; i < numedges; i++ )
        {
            edges[i].build_plane( extrusion_dir );
        }
        return;
    }
};
struct Interval
{
    rw::math::VecFloat min, max;
    Interval()
    {
    }
    Interval( const rw::math::vpu::VecFloat & a, const rw::math::vpu::VecFloat & b )
    {
        ;
        min = rw::math::vpu::Select(rw::math::vpu::CompLessThan(a, b), a, b);
        max = rw::math::vpu::Select(rw::math::vpu::CompLessThan(a, b), b, a);
        return;
    }
} __attribute__ ((__aligned__ (16)));








struct GPInstance
{
    enum VolumeType
    {
        UNUSED = 0,
        SPHERE,
        CAPSULE,
        TRIANGLE,
        BOX,
        CYLINDER,
        NUMINTERNALTYPES,
        FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };
    enum VolumeFlag
    {
        FLAG_TRIANGLEONESIDED = 0x0010,
        FLAG_TRIANGLEEDGE0CONVEX = 0x0020,
        FLAG_TRIANGLEEDGE1CONVEX = 0x0040,
        FLAG_TRIANGLEEDGE2CONVEX = 0x0080,
        FLAG_TRIANGLEUSEEDGECOS = 0x0100,
        FLAG_TRIANGLEVERT0DISABLE = 0x0200,
        FLAG_TRIANGLEVERT1DISABLE = 0x0400,
        FLAG_TRIANGLEVERT2DISABLE = 0x0800,
        FLAG_TRIANGLEDEFAULT = FLAG_TRIANGLEUSEEDGECOS + FLAG_TRIANGLEEDGE0CONVEX
                                                            + FLAG_TRIANGLEEDGE1CONVEX
                                                            + FLAG_TRIANGLEEDGE2CONVEX,
        FLAG_TRIANGLEOLDMASK = FLAG_TRIANGLEONESIDED + FLAG_TRIANGLEEDGE0CONVEX
                                                            + FLAG_TRIANGLEEDGE1CONVEX
                                                            + FLAG_TRIANGLEEDGE2CONVEX,
        FLAG_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };
    typedef void (GPInstance::*GetMaximumFeatureFn)( RwBool ccw, rw::math::Vector3::InParam dir, Feature &feature ) const;
    typedef void (GPInstance::*GetIntervalFn) ( rw::math::Vector3::InParam dir, Interval &interval ) const;
    typedef void (GPInstance::*GetIntervalsFn) ( const rw::math::Vector3 *dirs, uint32_t numDirs, Interval *intervals ) const;
    typedef void (GPInstance::*GetBBoxFn) ( AABBox &bbox ) const;
    struct VolumeMethods
    {
        GetMaximumFeatureFn mGetMaximumFeature;
        GetIntervalFn mGetInterval;
        GetIntervalsFn mGetIntervals;
        GetBBoxFn mGetBBox;
    };
    static VolumeMethods sVolumeMethods[GPInstance::NUMINTERNALTYPES];
    struct ContactPoints
    {
        struct PointPair
        {
            rw::math::Vector3 p1;
            rw::math::Vector3 p2;
        };
        uint32_t volumeTag1;
        uint32_t volumeTag2;
        uint32_t userTag1;
        uint32_t userTag2;
        uint32_t numPoints;
        rw::math::Vector3 normal;
        PointPair pointPairs[8];
    };





















    rw::math::Vector3 mPos;
    rw::math::Vector3 mFaceNormals[3];
    rw::math::Vector3 mEdgeDirections[3];
    rw::math::Vector3 mDimensions;
    float32_t mFatness;
    uint32_t mVolumeTag;
    uint32_t mUserTag;
    uint8_t mNumFaceNormals;
    uint8_t mNumEdgeDirections;
    VolumeType mVolumeType;
    uint32_t mFlags;
    float32_t mEdgeData[3];







    inline __attribute__ ((always_inline)) VolumeMethods *GetVolumeMethods(GPInstance::VolumeType volumeType);









    inline __attribute__ ((always_inline)) GPInstance::VolumeType Type() const { return mVolumeType; };
    inline __attribute__ ((always_inline)) uint32_t Flags() const { return mFlags; };
    inline __attribute__ ((always_inline)) rw::math::Vector3 Pos() const { return mPos; };
    inline __attribute__ ((always_inline)) rw::math::Vector3 FaceNormal(uint32_t index) const { return mFaceNormals[index]; };
    inline __attribute__ ((always_inline)) rw::math::Vector3 EdgeDirection(uint32_t index) const { return mEdgeDirections[index]; };
    inline __attribute__ ((always_inline)) const float32_t &Fatness() const { return mFatness; };
    inline __attribute__ ((always_inline)) rw::math::VecFloat FatnessVec() const { return rw::math::VecFloat(mFatness); };

    inline __attribute__ ((always_inline)) void GetMaximumFeature(RwBool ccw, rw::math::Vector3::InParam dir, Feature &feature) const;
    inline __attribute__ ((always_inline)) void GetInterval (rw::math::Vector3::InParam dir, Interval &interval) const;
    inline __attribute__ ((always_inline)) void GetIntervals (const rw::math::Vector3 *dirs, uint32_t numDirs, Interval *intervals) const;
    inline __attribute__ ((always_inline)) void GetBBox (AABBox &bbox) const;
protected:







    inline __attribute__ ((always_inline)) void SetPos(rw::math::Vector3::InParam pos) { mPos = pos; };
    inline __attribute__ ((always_inline)) void SetFaceNormal(uint32_t index, rw::math::Vector3::InParam normal) { mFaceNormals[index] = normal; };
    inline __attribute__ ((always_inline)) void SetEdgeDirection(uint32_t index, rw::math::Vector3::InParam edgeDirection) { mEdgeDirections[index] = edgeDirection; };
    inline __attribute__ ((always_inline)) void SetEdgeData(uint32_t index, float32_t data) { mEdgeData[index] = data; };
    inline __attribute__ ((always_inline)) const float32_t &EdgeData(uint32_t index) const { return mEdgeData[index]; };

};
inline __attribute__ ((always_inline)) GPInstance::VolumeMethods *
GPInstance::GetVolumeMethods(rw::collision::GPInstance::VolumeType volumeType)
{
    ;
    return &sVolumeMethods[volumeType];
}
inline __attribute__ ((always_inline)) void
GPInstance::GetMaximumFeature(RwBool ccw, rw::math::Vector3::InParam dir, Feature &feature) const
{
    ;
    ;
    (this->*(sVolumeMethods[Type()].mGetMaximumFeature))(ccw, dir, feature);
}
inline __attribute__ ((always_inline)) void
GPInstance::GetInterval(rw::math::Vector3::InParam dir, Interval &interval) const
{
    ;
    ;
    (this->*(sVolumeMethods[Type()].mGetInterval))(dir, interval);
}
inline __attribute__ ((always_inline)) void
GPInstance::GetIntervals(const rw::math::Vector3 *dirs, uint32_t numDirs, Interval *intervals) const
{
    ;
    ;
    (this->*(sVolumeMethods[Type()].mGetIntervals))(dirs, numDirs, intervals);
}
inline __attribute__ ((always_inline)) void
GPInstance::GetBBox(AABBox &bbox) const
{
    ;
    ;
    (this->*(sVolumeMethods[Type()].mGetBBox))(bbox);
}
uint32_t ComputeContactPoints(const GPInstance &gp1, const GPInstance &gp2, const float32_t &padding, GPInstance::ContactPoints &result);
uint32_t ComputeContactPoints(const GPInstance &gp, const GPInstance *gps, uint32_t count, const float32_t &padding, GPInstance::ContactPoints *results, uint32_t &numIntersections);
struct GPSphere: public GPInstance
{
public:
    inline __attribute__ ((always_inline)) void Initialize(rw::math::Vector3::InParam center, const float32_t &radius, uint32_t volumeFlags, uint32_t volumeTag, uint32_t userTag);
    inline __attribute__ ((always_inline)) rw::math::Vector3 Center() const { return Pos(); };
    inline __attribute__ ((always_inline)) const float32_t &Radius() const { return mFatness; };
    void GetBBox( AABBox &bbox ) const;
    void GetMaximumFeature(RwBool ccw, rw::math::Vector3::InParam dir, Feature &feature) const;
    void GetInterval(rw::math::Vector3::InParam dir, Interval &interval) const;
    void GetIntervals(const rw::math::Vector3 *dirs, uint32_t numDirs, Interval *intervals) const;
};
struct GPCapsule : public GPInstance
{
public:
    inline __attribute__ ((always_inline)) void Initialize(rw::math::Vector3::InParam center, const float32_t &radius, rw::math::Vector3::InParam axis, const float32_t &halfHeight, uint32_t volumeFlags, uint32_t volumeTag, uint32_t userTag);
    inline __attribute__ ((always_inline)) rw::math::Vector3 Center() const { return Pos(); };
    inline __attribute__ ((always_inline)) const float32_t &Radius() const { return mFatness; };
    inline __attribute__ ((always_inline)) rw::math::VecFloat RadiusVec() const { return rw::math::VecFloat(mFatness); };
    inline __attribute__ ((always_inline)) rw::math::Vector3 Axis() const { return EdgeDirection(0); };
    inline __attribute__ ((always_inline)) rw::math::VecFloat HalfHeight() const { return mDimensions.GetX(); };
    void GetBBox( AABBox &bbox ) const;
    void GetMaximumFeature(RwBool ccw, rw::math::Vector3::InParam dir, Feature &feature) const;
    void GetInterval(rw::math::Vector3::InParam dir, Interval &interval) const;
    void GetIntervals(const rw::math::Vector3 *dirs, uint32_t numDirs, Interval *intervals) const;
};
struct GPBox : public GPInstance
{
public:
    inline __attribute__ ((always_inline)) void Initialize(rw::math::Vector3::InParam center, rw::math::Vector3::InParam faceNormal0, rw::math::Vector3::InParam faceNormal1, rw::math::Vector3::InParam faceNormal2,
        rw::math::Vector3::InParam dimensions, const float32_t &fatness, uint32_t volumeFlags, uint32_t volumeTag, uint32_t userTag);
    inline __attribute__ ((always_inline)) rw::math::Vector3 Center() const { return Pos(); };
    inline __attribute__ ((always_inline)) rw::math::VecFloat HalfSize(uint32_t index) const { return mDimensions.GetComponent(index); };
    inline __attribute__ ((always_inline)) rw::math::Vector3 HalfSizeDimensionsVec() const { return mDimensions; };
    void GetBBox( AABBox &bbox ) const;
    void GetMaximumFeature(RwBool ccw, rw::math::Vector3::InParam dir, Feature &feature) const;
    void GetInterval(rw::math::Vector3::InParam dir, Interval &interval) const;
    void GetIntervals(const rw::math::Vector3 *dirs, uint32_t numDirs, Interval *intervals) const;
private:
    inline __attribute__ ((always_inline)) void SetDimensions(rw::math::Vector3::InParam dimensions) { mDimensions = dimensions; };
};
struct GPTriangle : public GPInstance
{
public:
    inline __attribute__ ((always_inline)) void GPTriangle::Initialize(rw::math::Vector3::InParam p1, rw::math::Vector3::InParam p2, rw::math::Vector3::InParam p3, const float32_t &fatness, uint32_t volumeFlags, rw::math::Vector3::InParam edgeCosines, uint32_t volumeTag, uint32_t userTag);
    inline __attribute__ ((always_inline)) void GPTriangle::Initialize(rw::math::Vector3::InParam p1, rw::math::Vector3::InParam p2, rw::math::Vector3::InParam p3, const float32_t &fatness, uint32_t volumeFlags, rw::math::Vector3::InParam edgeCosines, uint32_t volumeTag, uint32_t userTag, rw::math::Vector3::InParam normal);
    inline __attribute__ ((always_inline)) void GPTriangle::Initialize(rw::math::Vector3::InParam p1, rw::math::Vector3::InParam p2, rw::math::Vector3::InParam p3, const float32_t &fatness, uint32_t volumeFlags, float32_t edgeCosine0, float32_t edgeCosine1, float32_t edgeCosine2, uint32_t volumeTag, uint32_t userTag, rw::math::Vector3::InParam normal);
    inline __attribute__ ((always_inline)) rw::math::Vector3 Normal() const { return FaceNormal(0); };
    inline __attribute__ ((always_inline)) rw::math::Vector3 Vertex0() const { return Pos(); };
    inline __attribute__ ((always_inline)) rw::math::Vector3 Vertex1() const { return FaceNormal(1); };
    inline __attribute__ ((always_inline)) rw::math::Vector3 Vertex2() const { return FaceNormal(2); };
    inline __attribute__ ((always_inline)) rw::math::VecFloat EdgeLength(uint32_t index) const { return mDimensions.GetComponent(index); };
    inline __attribute__ ((always_inline)) void GetEdgeLengths(rw::math::VecFloat &edgeLength0, rw::math::VecFloat &edgeLength1, rw::math::VecFloat &edgeLength2) const
    {
        edgeLength0 = mDimensions.GetX();
        edgeLength1 = mDimensions.GetY();
        edgeLength2 = mDimensions.GetZ();
    };
    inline __attribute__ ((always_inline)) rw::math::Vector3 EdgeCosines() const { return rw::math::Vector3(EdgeData(0), EdgeData(1), EdgeData(2)); };
    void GetBBox( AABBox &bbox ) const;
    void GetMaximumFeature(RwBool ccw, rw::math::Vector3::InParam dir, Feature &feature) const;
    void GetInterval(rw::math::Vector3::InParam dir, Interval &interval) const;
    void GetIntervals(const rw::math::Vector3 *dirs, uint32_t numDirs, Interval *intervals) const;
private:
    inline __attribute__ ((always_inline)) void SetEdgeCosines(rw::math::Vector3::InParam edgeCosines) { SetEdgeData(0, edgeCosines.GetX());
                                                                                            SetEdgeData(1, edgeCosines.GetY());
                                                                                            SetEdgeData(2, edgeCosines.GetZ()); };
    inline __attribute__ ((always_inline)) void SetEdgeCosines(float32_t edgeCosine0, float32_t edgeCosine1, float32_t edgeCosine2)
                                                                                          { SetEdgeData(0, edgeCosine0);
                                                                                            SetEdgeData(1, edgeCosine1);
                                                                                            SetEdgeData(2, edgeCosine2); };
};
struct GPCylinder : public GPInstance
{
public:
    inline __attribute__ ((always_inline)) void Initialize(rw::math::Vector3::InParam center, const float32_t &radius, rw::math::Vector3::InParam axis, const float32_t &halfHeight, const float32_t &fatness,
         uint32_t volumeFlags, uint32_t volumeTag, uint32_t userTag, rw::math::Vector3::InParam faceNormal0, rw::math::Vector3::InParam faceNormal1 );
    inline __attribute__ ((always_inline)) rw::math::Vector3 Center() const { return Pos(); };
    inline __attribute__ ((always_inline)) rw::math::VecFloat Radius() const { return mDimensions.GetY(); };
    inline __attribute__ ((always_inline)) rw::math::Vector3 Axis() const { return EdgeDirection(0); };
    inline __attribute__ ((always_inline)) rw::math::VecFloat HalfHeight() const { return mDimensions.GetX(); };
    void GetBBox( AABBox &bbox ) const;
    void GetMaximumFeature(RwBool ccw, rw::math::Vector3::InParam dir, Feature &feature) const;
    void GetInterval(rw::math::Vector3::InParam dir, Interval &interval) const;
    void GetIntervals(const rw::math::Vector3 *dirs, uint32_t numDirs, Interval *intervals) const;
};
inline __attribute__ ((always_inline)) void
GPSphere::Initialize( rw::math::Vector3::InParam center, const float32_t &radius, uint32_t volumeFlags, uint32_t volumeTag, uint32_t userTag )
{
    ;
    mVolumeType = GPInstance::SPHERE;
    mNumFaceNormals = 0;
    mNumEdgeDirections = 0;
    mVolumeTag = volumeTag;
    mUserTag = userTag;
    SetPos(center);
    mFatness = radius;
    mFlags = volumeFlags;



    return;
}
inline __attribute__ ((always_inline)) void
GPCapsule::Initialize( rw::math::Vector3::InParam center, const float32_t &radius, rw::math::Vector3::InParam axis, const float32_t &halfHeight, uint32_t volumeFlags, uint32_t volumeTag, uint32_t userTag )
{
    ;
    mVolumeType = GPInstance::CAPSULE;
    mNumFaceNormals = 0;
    mNumEdgeDirections = 1;
    mVolumeTag = volumeTag;
    mUserTag = userTag;
    SetPos(center);
    mFatness = radius;
    SetEdgeDirection(0, axis);
    mDimensions.SetX(halfHeight);
    mFlags = volumeFlags;



    return;
}
inline __attribute__ ((always_inline)) void
GPBox::Initialize( rw::math::Vector3::InParam center, rw::math::Vector3::InParam faceNormal0, rw::math::Vector3::InParam faceNormal1, rw::math::Vector3::InParam faceNormal2,
                   rw::math::Vector3::InParam dimensions, const float32_t &fatness, uint32_t volumeFlags, uint32_t volumeTag, uint32_t userTag )
{
    ;
    GPInstance::VolumeType type = GPInstance::BOX;
    mVolumeType = type;
    mNumFaceNormals = 3;
    mNumEdgeDirections = 3;
    mVolumeTag = volumeTag;
    mUserTag = userTag;
    SetPos(center);
    SetFaceNormal (0, faceNormal0);
    SetEdgeDirection(0, faceNormal0);
    SetFaceNormal (1, faceNormal1);
    SetEdgeDirection(1, faceNormal1);
    SetFaceNormal (2, faceNormal2);
    SetEdgeDirection(2, faceNormal2);
    SetDimensions(dimensions);
    mFatness = fatness;
    mFlags = volumeFlags;



    return;
}
inline __attribute__ ((always_inline)) void
GPTriangle::Initialize( rw::math::Vector3::InParam p1, rw::math::Vector3::InParam p2, rw::math::Vector3::InParam p3, const float32_t &fatness, uint32_t volumeFlags, rw::math::Vector3::InParam edgeCosines, uint32_t volumeTag, uint32_t userTag )
{
    ;
    rw::math::Vector3 normal = rw::math::Cross(p2 - p1, p3 - p2);
    rw::math::Normalize(normal, normal);
    Initialize(p1, p2, p3, fatness, volumeFlags, edgeCosines, volumeTag, userTag, normal);
    return;
}
inline __attribute__ ((always_inline)) void
GPTriangle::Initialize( rw::math::Vector3::InParam p1, rw::math::Vector3::InParam p2, rw::math::Vector3::InParam p3, const float32_t &fatness, uint32_t volumeFlags, rw::math::Vector3::InParam edgeCosines, uint32_t volumeTag, uint32_t userTag, rw::math::Vector3::InParam normal )
{
    ;
    Initialize(p1, p2, p3, fatness, volumeFlags, edgeCosines.GetX(), edgeCosines.GetY(), edgeCosines.GetZ(), volumeTag, userTag, normal);
    return;
}
inline __attribute__ ((always_inline)) rw::math::Vector3
NormalizeReturnMagnitude3Fast(rw::math::Vector3 & v1, rw::math::Vector3 & v2, rw::math::Vector3 & v3)
{
    rw::math::VecFloat magSquared1 = MagnitudeSquared(v1);
    rw::math::VecFloat magSquared2 = MagnitudeSquared(v2);
    rw::math::VecFloat magSquared3 = MagnitudeSquared(v3);
    rw::math::Vector3 magnitudesInv(InvSqrtFast(magSquared1), InvSqrtFast(magSquared2), InvSqrtFast(magSquared3));
    v1 *= magnitudesInv.GetX();
    v2 *= magnitudesInv.GetY();
    v3 *= magnitudesInv.GetZ();
    return rw::math::Vector3(rw::math::GetVecFloat_One() / magnitudesInv.GetX(),
                             rw::math::GetVecFloat_One() / magnitudesInv.GetY(),
                             rw::math::GetVecFloat_One() / magnitudesInv.GetZ());
}
inline __attribute__ ((always_inline)) void
GPTriangle::Initialize( rw::math::Vector3::InParam p1, rw::math::Vector3::InParam p2, rw::math::Vector3::InParam p3, const float32_t &fatness, uint32_t volumeFlags,
                       float32_t edgeCosine0, float32_t edgeCosine1, float32_t edgeCosine2, uint32_t volumeTag, uint32_t userTag, rw::math::Vector3::InParam normal )
{
    ;
    GPInstance::VolumeType type = GPInstance::TRIANGLE;
    mVolumeType = type;
    mNumFaceNormals = 1;
    mNumEdgeDirections = 3;
    mVolumeTag = volumeTag;
    mUserTag = userTag;
    SetPos (p1);
    SetFaceNormal(1, p2);
    SetFaceNormal(2, p3);
    mFatness = fatness;
    SetFaceNormal(0, normal);
    SetEdgeCosines(edgeCosine0, edgeCosine1, edgeCosine2);
    mFlags = volumeFlags;
    rw::math::Vector3 edgeDirection0 = p3 - p1;
    rw::math::Vector3 edgeDirection1 = p2 - p3;
    rw::math::Vector3 edgeDirection2 = p1 - p2;
    mDimensions = NormalizeReturnMagnitude3Fast(edgeDirection0, edgeDirection1, edgeDirection2);
    SetEdgeDirection(0, edgeDirection0);
    SetEdgeDirection(1, edgeDirection1);
    SetEdgeDirection(2, edgeDirection2);



    return;
}
inline __attribute__ ((always_inline)) void
GPCylinder::Initialize( rw::math::Vector3::InParam center, const float32_t &radius, rw::math::Vector3::InParam axis, const float32_t &halfHeight,
                       const float32_t &fatness, uint32_t volumeFlags, uint32_t volumeTag, uint32_t userTag, rw::math::Vector3::InParam faceNormal0, rw::math::Vector3::InParam faceNormal1 )
{
    ;
    mVolumeType = GPInstance::CYLINDER;
    mNumFaceNormals = 1;
    mNumEdgeDirections = 1;
    mVolumeTag = volumeTag;
    mUserTag = userTag;
    SetPos(center);
    SetEdgeDirection(0, axis);
    SetFaceNormal (0, axis);
    SetFaceNormal (1, faceNormal0);
    SetFaceNormal (2, faceNormal1);
    mDimensions.SetX(halfHeight);
    mDimensions.SetY(radius);
    mFatness = fatness;
    mFlags = volumeFlags;



    return;
}
struct VolRef
{
    const Volume *volume;
    rw::math::Matrix44Affine *tm;
    rw::math::Matrix44Affine tmContents;
    AABBox bBox;
    uint32_t tag;
    uint8_t numTagBits;
};
struct VolRefPair
{
    rw::collision::VolRef *vRef1;
    rw::collision::VolRef *vRef2;
};
struct VolRef1xN
{
    rw::collision::VolRef *vRef1;
    uint32_t vRefsNCount;
    RwBool volumesSwapped;
    rw::collision::VolRef *vRefsN[1];
};



const float32_t krGPFeatureSimplificationThreshold = 0.05f;
const float32_t krGPMinimumAllowedClippingAngle = 0.001f;
struct VolumeLineSegIntersectResult
{
    const Volume *v;
    rw::math::Vector3 position;
    rw::math::Vector3 normal;
    rw::math::Vector3 volParam;
    float32_t lineParam;
    VolRef vRef;
};
struct Fraction
{
    float32_t num;
    float32_t den;
};
inline RwBool
FracLT(const Fraction &f1, const Fraction &f2)
{
    ;
    ;
    return f1.num * f2.den < f2.num * f1.den;
}
enum VolumeType
{
    VOLUMETYPENULL = GPInstance::UNUSED,
    VOLUMETYPESPHERE = GPInstance::SPHERE,
    VOLUMETYPECAPSULE = GPInstance::CAPSULE,
    VOLUMETYPETRIANGLE = GPInstance::TRIANGLE,
    VOLUMETYPEBOX = GPInstance::BOX,
    VOLUMETYPECYLINDER = GPInstance::CYLINDER,
    VOLUMETYPEAGGREGATE,
    VOLUMETYPENUMINTERNALTYPES,
    VOLUMETYPEFORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
enum VolumeFlag
{
    VOLUMEFLAG_ISENABLED = 0x0001,
    VOLUMEFLAG_TRIANGLENORMALISDIRTY = 0x0002,
    VOLUMEFLAG_TRIANGLEONESIDED = GPInstance::FLAG_TRIANGLEONESIDED,
    VOLUMEFLAG_TRIANGLEEDGE0CONVEX = GPInstance::FLAG_TRIANGLEEDGE0CONVEX,
    VOLUMEFLAG_TRIANGLEEDGE1CONVEX = GPInstance::FLAG_TRIANGLEEDGE1CONVEX,
    VOLUMEFLAG_TRIANGLEEDGE2CONVEX = GPInstance::FLAG_TRIANGLEEDGE2CONVEX,
    VOLUMEFLAG_TRIANGLEUSEEDGECOS = GPInstance::FLAG_TRIANGLEUSEEDGECOS,
    VOLUMEFLAG_TRIANGLEVERT0DISABLE = GPInstance::FLAG_TRIANGLEVERT0DISABLE,
    VOLUMEFLAG_TRIANGLEVERT1DISABLE = GPInstance::FLAG_TRIANGLEVERT1DISABLE,
    VOLUMEFLAG_TRIANGLEVERT2DISABLE = GPInstance::FLAG_TRIANGLEVERT2DISABLE,
    VOLUMEFLAG_TRIANGLEDEFAULT = VOLUMEFLAG_ISENABLED + GPInstance::FLAG_TRIANGLEDEFAULT,
    VOLUMEFLAG_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
class Volume
{
public:
    typedef RwBool (Volume::*GetBBoxFn)(const rw::math::Matrix44Affine *tm,
                                             RwBool tight, AABBox &bBox) const;
    typedef rw::math::Vector3 (Volume::*GetBBoxDiagFn)() const;
    typedef RwBool (Volume::*GetIntervalFn)(const rw::math::Vector3 & dir,
                                                 Interval &interval) const;
    typedef RwBool (Volume::*GetMaximumFeatureFn)(RwBool ccw,
                                                       const rw::math::Vector3 & dir,
                                                       Feature &feature) const;
    typedef RwBool (Volume::*CreateGPInstanceFn)(GPInstance &instance,
                                                      const rw::math::Matrix44Affine *tm) const;
    typedef RwBool (Volume::*LineSegIntersectFn)(const rw::math::Vector3 & pt1,
                                                      const rw::math::Vector3 & pt2,
                                                      const rw::math::Matrix44Affine *tm,
                                                      VolumeLineSegIntersectResult &result,
                                                      const float32_t fatness) const;
    typedef void (Volume::*ReleaseFn)();
    Volume()
    {
    }
protected:
    Volume(rw::collision::VolumeType type)
    {
        ;
        ;
        vTable = Volume::vTableArray[type];
        radius = 0.0f;
        groupID = 0;
        surfaceID = 0;
        m_flags = VOLUMEFLAG_ISENABLED;
        transform = rw::math::GetMatrix44Affine_Identity();
        return;
    }
public:
    void Release()
    {
        (this->*(vTable->release))();
    }
    rw::collision::VolumeType
    GetType() const;
    const RwChar *
    GetTypeName();
    const float32_t &
    GetRadius() const;
    void
    SetRadius(float32_t rad);
    uint32_t
    GetGroup() const;
    void
    SetGroup(uint32_t group);
    uint32_t
    GetSurface() const;
    void
    SetSurface(uint32_t surface);
    RwBool
    IsEnabled() const;
    void
    SetEnabled(RwBool whetherEnabled);
    uint32_t
    GetFlags() const;
    void
    SetFlags(uint32_t newflags);
    const rw::math::Matrix44Affine *
    GetRelativeTransform() const;
    rw::math::Matrix44Affine *
    GetRelativeTransform();
    RwBool
    GetBBox(const rw::math::Matrix44Affine *tm,
        RwBool tight, AABBox &bBox) const;
    rw::math::Vector3
        GetBBoxDiag() const;
    RwBool
    CreateGPInstance(GPInstance &instance, const rw::math::Matrix44Affine *tm) const;
    RwBool
    LineSegIntersect(const rw::math::Vector3 & pt1,
                    const rw::math::Vector3 & pt2,
                    const rw::math::Matrix44Affine *tm,
                    VolumeLineSegIntersectResult &result,
                    const float32_t fatness = 0.0f) const;

    static rw::core::arena::SizeAndAlignment *
    Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset);
    static void
    Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *);
    static RwBool
    Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator);
    static void
    RegisterArenaReadCallbacks(void);
    static void
    RegisterArenaWriteCallbacks(void);

    static RwBool
    InitializeVTable(void);
    static RwBool
    ReleaseVTable(void);
    struct VTable
    {
        rw::collision::VolumeType typeID;
        GetBBoxFn getBBox;
        GetBBoxDiagFn getBBoxDiag;
        GetIntervalFn getInterval;
        GetMaximumFeatureFn getMaximumFeature;
        CreateGPInstanceFn createGPInstance;
        LineSegIntersectFn lineSegIntersect;
        ReleaseFn release;
        const RwChar *name;
        uint32_t flags;
    };
    static VTable *vTableArray[rw::collision::VOLUMETYPENUMINTERNALTYPES];
protected:
    mutable rw::math::Matrix44Affine transform;
    struct VTable* vTable;
    union
    {
        AggregateSpecificData aggregateData;
        SphereSpecificData sphereData;
        CapsuleSpecificData capsuleData;
        TriangleSpecificData triangleData;
        BoxSpecificData boxData;
        CylinderSpecificData cylinderData;
        rw::TargetPtr sizeOfTargetPointer[2];
    };
    float32_t radius;
    uint32_t groupID;
    uint32_t surfaceID;
    uint32_t m_flags;
};
inline rw::collision::VolumeType
Volume::GetType() const
{
    ;
    return vTable->typeID;
}
inline const RwChar *
Volume::GetTypeName()
{
    ;
    return vTable->name;
}
inline const float32_t &
Volume::GetRadius() const
{
    ;
    return radius;
}
inline void
Volume::SetRadius(float32_t rad)
{
    ;
    ;
    radius = rad;
    return;
}
inline uint32_t
Volume::GetGroup() const
{
    ;
    return groupID;
}
inline void
Volume::SetGroup(uint32_t group)
{
    ;
    groupID = group;
    return;
}
inline uint32_t
Volume::GetSurface() const
{
    ;
    return surfaceID;
}
inline void
Volume::SetSurface(uint32_t surface)
{
    ;
    surfaceID = surface;
    return;
}
inline RwBool
Volume::IsEnabled() const
{
    ;
    return (m_flags & VOLUMEFLAG_ISENABLED) != 0;
}
inline void
Volume::SetEnabled(RwBool whetherEnabled)
{
    ;
    if ( whetherEnabled )
    {
        m_flags |= VOLUMEFLAG_ISENABLED;
    }
    else
    {
        m_flags &= ~VOLUMEFLAG_ISENABLED;
    }
    return;
}
inline uint32_t
Volume::GetFlags() const
{
    ;
    return m_flags;
}
inline void
Volume::SetFlags(uint32_t newflags)
{
    ;
    m_flags = newflags;
    return;
}
inline const rw::math::Matrix44Affine *
Volume::GetRelativeTransform() const
{
    ;
    return &transform;
}
inline rw::math::Matrix44Affine *
Volume::GetRelativeTransform()
{
    ;
    return &transform;
}
inline RwBool
Volume::GetBBox(const rw::math::Matrix44Affine *tm,
        RwBool tight, AABBox &bBox) const
{
    return (this->*(vTable->getBBox))(tm, tight, bBox);
}
inline __attribute__ ((always_inline)) rw::math::Vector3
Volume::GetBBoxDiag() const
{
    return (this->*(vTable->getBBoxDiag))();
}
inline RwBool
Volume::CreateGPInstance(GPInstance &instance, const rw::math::Matrix44Affine *tm) const
{
    return (this->*(vTable->createGPInstance))(instance, tm);
}
inline RwBool
Volume::LineSegIntersect(const rw::math::Vector3 & pt1,
                    const rw::math::Vector3 & pt2,
                    const rw::math::Matrix44Affine *tm,
                    VolumeLineSegIntersectResult &result,
                    const float32_t fatness) const
{
    ;
    ;
    if (!this->IsEnabled())
    {
        return (0);
    }
    return (this->*(vTable->lineSegIntersect))(pt1, pt2, tm, result, fatness);
}
}
}









namespace rw
{
namespace collision
{
class Plane;
class Plane
{
public:
    Plane() {};
    Plane(rw::math::Vector3::InParam normal, float32_t distance) : m_data(normal.X(), normal.Y(), normal.Z(), distance) {};
    rw::math::Vector3 GetNormal() { return m_data.GetVector3(); }
    float32_t GetDistance() { return m_data.UserData(); }
    void SetDistance(float32_t distance) { m_data.UserData()= distance; }
    void SetNormal(rw::math::Vector3::InParam normal) { m_data.SetVector3(normal); }
    void Transform(const rw::math::Matrix44Affine &transform);
    inline RwBool PointTest (rw::math::Vector3::InParam center);
    inline RwBool SphereTest(rw::math::Vector3::InParam center, float32_t radius);
private:
    rw::math::Vector3Plus m_data;
};
inline RwBool
Plane::PointTest(rw::math::Vector3::InParam center)
{
    ;
    float32_t distance = Dot(GetNormal(), center);
    return GetDistance() < distance;
}
inline RwBool
Plane::SphereTest(rw::math::Vector3::InParam center, float32_t radius)
{
    ;
    float32_t distance = Dot(GetNormal(), center);
    return GetDistance() < distance + radius;
}
}
}






namespace rw
{
namespace collision
{
struct rwc_FeatureIntersectionPrism
{
    rw::math::Vector3 m_ptsOn1[2 * Feature::MAXEDGECOUNT];
    rw::math::Vector3 m_ptsOn2[2 * Feature::MAXEDGECOUNT];
    rw::math::Vector3 normal;
    int32_t m_numpts;
    RwBool normalOverride;
};
RwBool
FindPointPointPrism( rwc_FeatureIntersectionPrism &res, rw::math::Vector3 *ptsOn1, rw::math::Vector3 *ptsOn2,
                     Feature &pf1, Feature &pf2, const rw::math::Vector3 & );
RwBool
FindEdgePointPrism( rwc_FeatureIntersectionPrism &res, rw::math::Vector3 *ptsOn1, rw::math::Vector3 *ptsOn2,
                    Feature &ef, Feature &pf, const rw::math::Vector3 & );
RwBool
FindEdgeEdgePrism( rwc_FeatureIntersectionPrism &res, rw::math::Vector3 *ptsOn1, rw::math::Vector3 *ptsOn2,
                   Feature &ef1, Feature &ef2, const rw::math::Vector3 &sepDir );
RwBool
FindFacePointPrism( rwc_FeatureIntersectionPrism &res, rw::math::Vector3 *ptsOnF, rw::math::Vector3 *ptsOnP,
                    Feature &ff, Feature &pf, const rw::math::Vector3 &sepDir );
RwBool
FindFaceEdgePrism( rwc_FeatureIntersectionPrism &res, rw::math::Vector3 *ptsOnF, rw::math::Vector3 *ptsOnE,
                   Feature &ff, Feature &ef, const rw::math::Vector3 &sepDir );
RwBool
FindFaceFacePrism( rwc_FeatureIntersectionPrism &res, rw::math::Vector3 *ptsOn1, rw::math::Vector3 *ptsOn2,
                   Feature &ff1, Feature &ff2, const rw::math::Vector3 &sepDir );
RwBool
FindFaceFacePrism4x3( rwc_FeatureIntersectionPrism &res, rw::math::Vector3 *ptsOn1, rw::math::Vector3 *ptsOn2,
                      Feature &ff1, Feature &ff2, const rw::math::Vector3 &sepDir );
RwBool
FindFaceFacePrism4x4( rwc_FeatureIntersectionPrism &res, rw::math::Vector3 *ptsOn1, rw::math::Vector3 *ptsOn2,
                      Feature &ff1, Feature &ff2, const rw::math:: Vector3 &sepDir );
RwBool
FindFeatureIntersectionPrism( rwc_FeatureIntersectionPrism &res,
                              Feature &f1, Feature &f2, const rw::math::Vector3 & sepDir );
}
}






namespace rw
{
namespace collision
{










class Octree
{
public:
    struct Entry
    {
        uint16_t m_group;
        uint16_t m_next;
        uint16_t m_node;
        uint8_t m_child;
        uint8_t m_corner;
        void Init(uint32_t node, uint32_t child, RwBool inCorner)
        {
            ;
            m_group = 0;
            m_next = 0xffff;
            m_node = uint16_t(node);
            m_child = uint8_t(child);
            m_corner = uint8_t(inCorner);
            return;
        }
        void GetNode(uint32_t &node, uint32_t &child) const
        {
            ;
            node = m_node;
            child = m_child;
            return;
        }
        RwBool CornerFlag() const
        {
            ;
            return m_corner;
        }
        void SetNext(const uint32_t next)
        {
            ;
            m_next = uint16_t(next);
            return;
        }
        uint32_t Next() const
        {
            ;
            return m_next;
        }
        void SetGroup(const uint32_t group)
        {
            ;
            m_group = uint16_t(group);
            return;
        }
        uint32_t Group() const
        {
            ;
            return m_group;
        }
    };
    struct Node
    {
        uint16_t m_parent;
        uint16_t m_childOfParent;
        uint16_t m_stuckEntries;
        uint16_t m_childTypes;
        uint16_t m_childRefs[8];
        uint8_t m_pushCounts[8];
        void InitFree(uint32_t next)
        {
            ;
            m_parent = uint16_t(next);
            return;
        }
        uint32_t NextFree() const
        {
            ;
            return m_parent;
        }
        void InitLeaf(uint32_t child)
        {
            m_childRefs[child] = 0xffff;
            m_pushCounts[child] = 0;
            m_childTypes |= (1<<child);
        }
        void Init(uint32_t parent, uint32_t childOfParent)
        {
            m_parent = uint16_t(parent);
            m_childOfParent = uint8_t(childOfParent);
            m_stuckEntries = 0xffff;
            m_childTypes = 0;
            for (uint32_t i=0; i<8; i++)
            {
                InitLeaf(i);
            }
        }
        uint32_t Parent() const
        {
            ;
            return m_parent;
        }
        uint32_t ChildOfParent() const
        {
            ;
            return m_childOfParent;
        }
        void SetStuckEntries(uint32_t firstEntry)
        {
            ;
            m_stuckEntries = uint16_t(firstEntry);
            return;
        }
        uint32_t StuckEntries() const
        {
            ;
            return m_stuckEntries;
        }
        void SetLeafEntries(uint32_t child, uint32_t entry)
        {
            ;
            m_childRefs[child] = uint16_t(entry);
            return;
        }
        uint32_t LeafEntries(uint32_t child) const
        {
            ;
            return m_childRefs[child];
        }
        uint32_t PushCount(uint32_t child) const
        {
            ;
            return m_pushCounts[child];
        }
        void IncPushCount(uint32_t child)
        {
            ;
            if (m_pushCounts[child] < 255)
            {
                m_pushCounts[child]++;
            }
            return;
        }
        void DecPushCount(uint32_t child, Octree *tree)
        {
            ;
            if (m_pushCounts[child] != 255)
            {
                m_pushCounts[child]--;
                return;
            }
            uint32_t count = 0;
            uint32_t i = m_childRefs[child];
            while (i != 0xffff && count < 255)
            {
                if (tree->m_entries[i].CornerFlag())
                {
                    count++;
                }
                i = tree->m_entries[i].Next();
            }
            m_pushCounts[child] = uint8_t(count);
            return;
        }
        void SetChildNode(uint32_t child, uint32_t node)
        {
            ;
            m_childRefs[child] = uint16_t(node);
            m_childTypes &= ~(1<<child);
            return;
        }
        uint32_t ChildNode(uint32_t child) const
        {
            ;
            return m_childRefs[child];
        }
        RwBool ChildIsLeaf(uint32_t child) const
        {
            ;
            return (m_childTypes >> child) & 1;
        }
    } __attribute__ ((__aligned__ (32)));
    AABBox m_extent;
    uint32_t m_maxEntries;
    uint32_t m_maxNodes;
    uint32_t m_nodeFreeList;
    Node *m_nodes;
    Entry *m_entries;
    AABBox *m_bboxes;
private:
    void
    SplitLeaf(uint32_t iParent,
              uint32_t iChildOfParent,
              const AABBox &nodeBBox);
    void
    AddEntryToLeaf(uint32_t iEntry, uint32_t iNode, uint32_t iChild, RwBool inCorner)
    {
        ;
        Octree::Node *node = &m_nodes[iNode];
        Octree::Entry *entry = &m_entries[iEntry];
        entry->Init(iNode, iChild, inCorner);
        entry->SetNext(node->LeafEntries(iChild));
        node->SetLeafEntries(iChild, iEntry);
        if (inCorner)
        {
            node->IncPushCount(iChild);
        }
        return;
    }
    void
    AddEntryToNode(uint32_t iEntry, uint32_t iNode)
    {
        ;
        Octree::Node *node = &m_nodes[iNode];
        Octree::Entry *entry = &m_entries[iEntry];
        entry->Init(iNode, 0xff, (0));
        entry->SetNext(node->StuckEntries());
        node->SetStuckEntries(iEntry);
        return;
    }
    Octree(uint32_t maxObjs, const AABBox &extent);
public:
    static rw::ResourceDescriptor
    GetResourceDescriptor(uint32_t maxObjs, const AABBox &extent);
    static Octree*
    Initialize(const rw::Resource& resource, uint32_t maxObjs, const AABBox &extent);
    void
    Release();
    void
    Insert(uint32_t index, const AABBox &bbox);
    void
    Update(uint32_t index, const AABBox &bbox)
    {
        ;
        Remove(index);
        Insert(index, bbox);
        return;
    }
    void
    Remove(uint32_t index);
    const AABBox *
    GetEntryBBox(uint32_t index) const
    {
        ;
        return &m_bboxes[index];
    }
    class LineQuery
    {
    public:
        struct StackElement
        {
            AABBox m_bb;
            float32_t m_p[2];
            uint16_t m_node;
        };
    private:
        struct Result
        {
            float32_t m_p[2];
            uint16_t m_node;
        };
        const Octree *m_octree;
        AALineClipper m_clipper;
        rw::math::Vector3 m_recipPad;
        uint32_t m_swap;
        StackElement m_stack[(1+7*30)];
        uint32_t m_top;
        Result m_results[9];
        int32_t m_curResult;
        uint32_t m_nextEntry;
        void
        ProcessNode();
    public:
        LineQuery(const Octree *octree,
                  rw::math::Vector3::InParam start,
                  rw::math::Vector3::InParam end,
                  const float32_t fatness = 0.0f);
        RwBool
        GetNextInIntersectedNodes(uint32_t &entry)
        {
            ;
            entry = m_nextEntry;
            if (entry == 0xffff)
            {
                m_curResult--;
                while (m_curResult < 0)
                {
                    if (m_top == 0)
                    {
                        return (0);
                    }
                    else
                    {
                        ProcessNode();
                    }
                }
                entry = m_results[m_curResult].m_node;
            }
            m_nextEntry = m_octree->m_entries[entry].Next();
            return (1);
        }
        RwBool
        GetNext(uint32_t &entry)
        {
            ;
            while (GetNextInIntersectedNodes(entry))
            {
                float32_t pa = m_results[m_curResult].m_p[0];
                float32_t pb = m_results[m_curResult].m_p[1];
                if (m_clipper.ClipToAABBox(pa, pb, m_octree->m_bboxes[entry]))
                {
                    return (1);
                }
            }
            return (0);
        }
        void
        ClipEnd(float32_t endVal)
        {
            ;
            uint32_t i, count;
            count = m_curResult + 1;
            m_curResult = -1;
            for (i=0; i < count; i++)
            {
                if (m_results[i].m_p[0] <= endVal)
                {
                    m_curResult++;
                    m_results[m_curResult] = m_results[i];
                    m_results[m_curResult].m_p[1] = rw::math::Min(m_results[m_curResult].m_p[1], endVal);
                }
            }
            count = m_top;
            m_top = 0;
            for (i=0; i < count; i++)
            {
                if (m_stack[i].m_p[0] <= endVal)
                {
                    m_stack[m_top] = m_stack[i];
                    m_stack[m_top].m_p[1] = rw::math::Min(m_stack[m_top].m_p[1], endVal);
                    m_top++;
                }
            }
            return;
        }
    };
    class BBoxQuery
    {
    public:
        struct StackElement
        {
            AABBox m_bb;
            uint16_t m_node;
        };
    private:
        const Octree *m_octree;
        AABBox m_bbox;
        StackElement m_stack[(1+7*30)];
        uint32_t m_top;
        uint16_t m_results[9];
        int32_t m_curResult;
        uint32_t m_nextEntry;
        void
        ProcessNode();
    public:
        BBoxQuery(const Octree *octree,
                  const AABBox &bbox);
        RwBool
        GetNextInIntersectedNodes(uint32_t &entry)
        {
            ;
            entry = m_nextEntry;
            if (entry == 0xffff)
            {
                m_curResult--;
                while (m_curResult < 0)
                {
                    if (m_top == 0)
                    {
                        return (0);
                    }
                    else
                    {
                        ProcessNode();
                    }
                }
                entry = m_results[m_curResult];
            }
            m_nextEntry = m_octree->m_entries[entry].Next();
            return (1);
        }
        RwBool
        GetNext(uint32_t &entry)
        {
            ;
            while (GetNextInIntersectedNodes(entry))
            {
                if (m_bbox.Overlaps(m_octree->m_bboxes[entry]))
                {
                    return (1);
                }
            }
            return (0);
        }
    };
};
}
}






namespace rw
{
namespace collision
{
class Frustum;
class Frustum
{
public:
    Frustum() {};
    enum PlaneIndex
    {
        PLANE_NA,
        PLANE_FRONT = 0,
        PLANE_BACK,
        PLANE_LEFT,
        PLANE_RIGHT,
        PLANE_TOP,
        PLANE_BOTTOM,
        PLANE_MAX,
        PLANE_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
    };
    void SetPlane(uint32_t index, const Plane &plane) { m_planes[index] = plane; }
    const Plane &GetPlane(uint32_t index) const { return m_planes[index]; }
    Plane GetPlane(uint32_t index) { return m_planes[index]; }
    void TransformPlanes(const rw::math::Matrix44Affine &transform);
    RwBool IsSphereInFrustum(const rw::math::Vector3 &center, float32_t radius);
    RwBool Frustum::IsBoxInFrustum(const rw::math::Vector3 corners[8]);
private:
    Plane m_planes[6];
};
}
}






namespace rw
{
namespace collision
{
class Aggregate;
class Aggregate
{
public:
    const AABBox &
    GetBBox() const
    {
        ;
        return m_AABB;
    }
    uint32_t
    GetVolumeCount() const
    {
        return m_numVolumes;
    }
    uint32_t
    GetChildTagFromTag(uint32_t tag)
    {
        ;
        return (tag >> m_numTagBits);
    }
    uint32_t
    GetChildIndexFromTag(uint32_t tag)
    {
        ;
        ;
        return ((~(0xffffffff << m_numTagBits)) & tag)-1;
    }
    rw::collision::ObjectType
    GetType()
    {
        return (m_vTable->m_type);
    }
    rw::ResourceDescriptor
    GetResourceDescriptor()
    {
        return rw::ResourceDescriptor((this->*(m_vTable->m_GetSize))(), m_vTable->m_alignment);
    }
    RwBool
    IsProcedural()
    {
        return (m_vTable->m_isProcedural);
    }
    void
    Update()
    {
        (this->*(m_vTable->m_Update))();
    }
    RwBool
    LineIntersectionQuery(VolumeLineQuery *lineQuery,
                         const rw::math::Matrix44Affine *tm)
    {
        return (this->*(m_vTable->m_LineIntersectionQuery))(lineQuery, tm);
    }
    RwBool
    BBoxOverlapQuery(VolumeBBoxQuery *bboxQuery,
                    const rw::math::Matrix44Affine *tm)
    {
        return (this->*(m_vTable->m_BBoxOverlapQuery))(bboxQuery, tm);
    }
    typedef uint32_t (Aggregate::*GetSizeFn)(void);
    typedef uint32_t (Aggregate::*GetAlignmentFn)(void);
    typedef RwBool (Aggregate::*IsProceduralFn)(void);
    typedef void (Aggregate::*UpdateFn)(void);
    typedef uint32_t (Aggregate::*LineIntersectionQueryFn)(VolumeLineQuery *lineQuery,
                                                           const rw::math::Matrix44Affine *tm );
    typedef uint32_t (Aggregate::*BBoxOverlapQueryFn)(VolumeBBoxQuery *bboxQuery,
                                                       const rw::math::Matrix44Affine *tm );
    struct VTable
    {
        rw::collision::ObjectType m_type;
        GetSizeFn m_GetSize;
        uint32_t m_alignment;
        RwBool m_isProcedural;
        UpdateFn m_Update;
        LineIntersectionQueryFn m_LineIntersectionQuery;
        BBoxOverlapQueryFn m_BBoxOverlapQuery;
    };
    Aggregate(uint32_t numVolumes, VTable *vTable)
    : m_vTable(vTable),
      m_numTagBits(0),
      m_numVolumes(numVolumes)
    {
        uint32_t nv = numVolumes+1;
        while(nv)
        {
            nv>>=1;
            m_numTagBits++;
        }
    }
protected:
    static rw::core::arena::SizeAndAlignment *
    Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset);
    static void
    Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator);
    static RwBool
    Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator);
    AABBox m_AABB;
    VTable* m_vTable;
    uint32_t m_numTagBits;
    uint32_t m_numVolumes;

    uint32_t pad;

};
}
}






namespace rw
{
namespace collision
{
class SphereVolume;
extern Volume::VTable globalSphereVTable;
class SphereVolume : public Volume
{
protected:
    SphereVolume(float32_t rad)
    : Volume(rw::collision::VOLUMETYPESPHERE)
    {
        radius = rad;
    }
public:
    static rw::ResourceDescriptor
    GetResourceDescriptor(float32_t = 0)
    {
        ;
        return rw::ResourceDescriptor(sizeof(Volume), (16));
    }
    static SphereVolume *
    Initialize(const rw::Resource& resource, float32_t r);
    RwBool
    GetBBox(const rw::math::Matrix44Affine *tm, RwBool tight, AABBox &bBox) const;
    rw::math::Vector3
        GetBBoxDiag() const;
    RwBool
    CreateGPInstance(GPInstance &instance, const rw::math::Matrix44Affine *tm) const;
    RwBool
    GetInterval(const rw::math::Vector3 & dir, Interval &interval) const;
    RwBool
    GetMaximumFeature(RwBool ccw, const rw::math::Vector3 & dir, Feature &feature) const;
    RwBool
    LineSegIntersect(const rw::math::Vector3 & pt1,
                     const rw::math::Vector3 & pt2,
                     const rw::math::Matrix44Affine *tm,
                     VolumeLineSegIntersectResult &result,
                     const float32_t fatness=0.0f) const;
    void Release() {}
private:
};
int32_t
rwcSphereLineSegIntersect(Fraction *dist,
                          const rw::math::Vector3 & orig,
                          const rw::math::Vector3 & seg,
                          const rw::math::Vector3 & center,
                          const float32_t radius);
}
}






namespace rw
{
namespace collision
{
class CapsuleVolume;
extern Volume::VTable globalCapsuleVTable;
class CapsuleVolume : public Volume
{
protected:
    CapsuleVolume()
    : Volume(rw::collision::VOLUMETYPECAPSULE)
    {
        radius = 0;
        capsuleData.hh = 0;
    }
    CapsuleVolume(float32_t r, float32_t hh)
    : Volume(rw::collision::VOLUMETYPECAPSULE)
    {
        radius = r;
        capsuleData.hh = hh;
    }
public:
    static rw::ResourceDescriptor
    GetResourceDescriptor(float32_t = 0, float32_t = 0)
    {
        ;
        return rw::ResourceDescriptor(sizeof(Volume), (16));
    }
    static CapsuleVolume *
    Initialize(const rw::Resource& resource, float32_t r, float32_t hh);
    const float32_t &
    GetHalfHeight() const
    {
        return capsuleData.hh;
    }
    void
    SetHalfHeight(const float32_t halfHeight)
    {
        capsuleData.hh = halfHeight;
    }
    RwBool
    GetBBox(const rw::math::Matrix44Affine *tm, RwBool tight, AABBox &bBox) const;
    rw::math::Vector3
        GetBBoxDiag() const;
    RwBool
    CreateGPInstance(GPInstance &instance, const rw::math::Matrix44Affine *tm) const;
    RwBool
    GetInterval(const rw::math::Vector3 & dir, Interval &interval) const;
    RwBool
    GetMaximumFeature(RwBool ccw, const rw::math::Vector3 & dir, Feature &feature) const;
    RwBool
    LineSegIntersect(const rw::math::Vector3 & pt1,
                     const rw::math::Vector3 & pt2,
                     const rw::math::Matrix44Affine *tm,
                     VolumeLineSegIntersectResult &result,
                     const float32_t fatness = 0.0f) const;
    void Release() {}
private:
};
int32_t
rwcCylinderLineSegIntersect(Fraction * dist,
                            rw::math::Vector3::InParam orig,
                            rw::math::Vector3::InParam seg,
                            rw::math::Vector3::InParam center,
                            rw::math::Vector3::InParam axis,
                            float32_t axisLengthSq,
                            float32_t radius,
                            RwBool invert,
                            RwBool ignoreInside);
}
}






namespace rw
{
namespace collision
{
typedef class VolumeLineQuery VolumeLineQuery;
class VolumeLineQuery
{
public:
    typedef enum {
        ALLLINEINTERSECTIONS,
        ANYLINEINTERSECTION,
        NEARESTLINEINTERSECTION
    } QueryResultsSet;
    VolumeLineQuery(uint32_t stackMax,
                    uint32_t primsBufferSize,
                    uint32_t resBufferSize);
    RwBool
    AddPrimitiveRef(const Volume *vol,
                    const rw::math::Matrix44Affine *tm,
                    const uint32_t tag,
                    const uint8_t numTagBits)
    {
        ;
        ;
        if (m_primNext >= m_primBufferSize)
        {
            return (0);
        }
        m_primVRefBuffer[m_primNext].volume = vol;
        if ( tm )
        {
            m_primVRefBuffer[m_primNext].tmContents = *tm;
            m_primVRefBuffer[m_primNext].tm = &m_primVRefBuffer[m_primNext].tmContents;
        }
        else
        {
            m_primVRefBuffer[m_primNext].tm = 0;
        }
        m_primVRefBuffer[m_primNext].tag = tag;
        m_primVRefBuffer[m_primNext].numTagBits = numTagBits;
        m_primNext++;
        return (1);
    }
    RwBool
    AddVolumeRef(const Volume *vol,
                 const rw::math::Matrix44Affine *tm,
                 const uint32_t tag,
                 const uint8_t numTagBits)
    {
        ;
        if (vol->GetType() != rw::collision::VOLUMETYPEAGGREGATE)
        {
            return AddPrimitiveRef(vol, tm, tag, numTagBits);
        }
        if (m_stackNext >= m_stackMax)
        {
            ;
            return (0);
        }
        m_stackVRefBuffer[m_stackNext].volume = vol;
        if ( tm )
        {
            m_stackVRefBuffer[m_stackNext].tmContents = *tm;
            m_stackVRefBuffer[m_stackNext].tm = &m_stackVRefBuffer[m_stackNext].tmContents;
        }
        else
        {
            m_stackVRefBuffer[m_stackNext].tm = 0;
        }
        m_stackVRefBuffer[m_stackNext].tag = tag;
        m_stackVRefBuffer[m_stackNext].numTagBits = numTagBits;
        m_stackNext++;
        return (1);
    }
protected:
    uint32_t
    GetIntersections();
public:
    uint32_t
    GetAllIntersections();
    VolumeLineSegIntersectResult *
    GetAnyIntersection();
    VolumeLineSegIntersectResult *
    GetNearestIntersection();
    VolumeLineSegIntersectResult *
    GetIntersectionResultsBuffer() const
    {
        ;
        return m_resBuffer;
    }
    static rw::ResourceDescriptor
    GetResourceDescriptor(uint32_t stackMax,
                          uint32_t resBufferSize);
    static VolumeLineQuery *
    Initialize(const rw::Resource& resource,
               uint32_t stackMax,
               uint32_t resBufferSize);
    static VolumeLineQuery *
    Initialize(void *mem,
                uint32_t stackMax,
                uint32_t resBufferSize);
    static void
    Release(VolumeLineQuery *)
    {
        ;
        return;
    };
    void
    InitQuery(const rw::collision::Volume **inputVols,
              const rw::math::Matrix44Affine **inputMats,
              const uint32_t numInputs,
              const rw::math::Vector3 &pt1,
              const rw::math::Vector3 &pt2,
              const float32_t fatness =0.0)
    {
        ;
        m_inputVols = inputVols;
        m_inputMats = inputMats;
        m_numInputs = numInputs;
        m_currInput = 0;
        m_stackNext = 0;
        m_primNext = 0;
        m_currVRef.volume = 0;
        m_aggIndex = 0;
        m_curSpatialMapQuery = 0;
        m_resCount = 0;
        m_instVolCount = 0;
        m_pt1 = pt1;
        m_pt2 = pt2;
        m_endClipVal = 1.0f;
        m_fatness = fatness;
        m_resultsSet = ALLLINEINTERSECTIONS;
        m_resMax = m_resBufferSize;
        m_tag = 0;
        m_numTagBits = 0;
        return;
    }
    RwBool
    Finished()
    {
        ;
        if(m_currInput == m_numInputs &&
           m_currVRef.volume == 0 &&
           m_stackNext == 0 &&
           m_primNext == 0)
        {
            return (1);
        }
        else
        {
            return (0);
        }
    }
    const rw::collision::Volume **m_inputVols;
    const rw::math::Matrix44Affine **m_inputMats;
    uint32_t m_numInputs;
    uint32_t m_currInput;
    VolumeLineSegIntersectResult *m_resBuffer;
    uint32_t m_resCount;
    uint32_t m_resMax;
    uint32_t m_resBufferSize;
    rw::math::Vector3 m_pt1;
    rw::math::Vector3 m_pt2;
    float32_t m_fatness;
    VolRef *m_stackVRefBuffer;
    VolRef m_currVRef;
    uint32_t m_stackNext;
    uint32_t m_stackMax;
    VolRef *m_primVRefBuffer;
    uint32_t m_primNext;
    uint32_t m_primBufferSize;
    Volume *m_instVolPool;
    uint32_t m_instVolCount;
    uint32_t m_instVolMax;
    uint32_t m_aggIndex;
    void* m_spatialMapQueryMem;
    void* m_curSpatialMapQuery;
    float32_t m_endClipVal;
    QueryResultsSet m_resultsSet;
    uint32_t m_tag;
    uint8_t m_numTagBits;
};
}
}






namespace rw
{
namespace collision
{
class MappedArray;
class MappedArray : public Aggregate
{
public:
    Volume *
    GetVolume(uint16_t index) const
    {
        ;
        return m_volumes + index;
    }
    Volume *
    GetVolumeArray()
    {
        return m_volumes;
    }
    MappedArray(uint32_t numVolumes, VTable *vTable)
    : Aggregate(numVolumes, vTable)
    {
    }
    static rw::core::arena::SizeAndAlignment *
    Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset);
    static void
    Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator);
    static RwBool
    Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator);
protected:
    Volume* m_volumes;
};
}
}






namespace rw
{
namespace collision
{
typedef class VolumeBBoxQuery VolumeBBoxQuery;
class VolumeBBoxQuery
{
public:
    VolumeBBoxQuery(uint32_t stackMax,
                    uint32_t instVolBufferSize,
                    uint32_t primsBufferSize);
    RwBool
    AddPrimitiveRef(const Volume *vol,
                    const rw::math::Matrix44Affine *tm,
                    const AABBox &bb,
                    const uint32_t tag,
                    const uint8_t numTagBits)
    {
        ;
        ;
        if (m_primNext >= m_primBufferSize)
        {
            return (0);
        }
        m_primVRefBuffer[m_primNext].volume = vol;
        if ( tm )
        {
            m_primVRefBuffer[m_primNext].tmContents = *tm;
            m_primVRefBuffer[m_primNext].tm = &m_primVRefBuffer[m_primNext].tmContents;
        }
        else
        {
            m_primVRefBuffer[m_primNext].tm = 0;
        }
        m_primVRefBuffer[m_primNext].bBox = bb;
        m_primVRefBuffer[m_primNext].tag = tag;
        m_primVRefBuffer[m_primNext].numTagBits = numTagBits;
        m_primNext++;
        return (1);
    }
    RwBool
    AddVolumeRef(const Volume *vol,
                 const rw::math::Matrix44Affine *tm,
                 const AABBox &bb,
                 const uint32_t tag,
                 const uint8_t numTagBits)
    {
        ;
        if (vol->GetType() != rw::collision::VOLUMETYPEAGGREGATE)
        {
            return AddPrimitiveRef(vol, tm, bb, tag, numTagBits);
        }
        if (m_stackNext >= m_stackMax)
        {
            return (0);
        }
        m_stackVRefBuffer[m_stackNext].volume = vol;
        if ( tm )
        {
            m_stackVRefBuffer[m_stackNext].tmContents = *tm;
            m_stackVRefBuffer[m_stackNext].tm = &m_stackVRefBuffer[m_stackNext].tmContents;
        }
        else
        {
            m_stackVRefBuffer[m_stackNext].tm = 0;
        }
        m_stackVRefBuffer[m_stackNext].bBox = bb;
        m_stackVRefBuffer[m_stackNext].tag = tag;
        m_stackVRefBuffer[m_stackNext].numTagBits = numTagBits;
        m_stackNext++;
        return (1);
    }
    uint32_t
    GetOverlaps();
    VolRef *
    GetOverlapResultsBuffer() const
    {
        ;
        return m_primVRefBuffer;
    }
    uint32_t
    GetOverlapResultsBufferCount() const
    {
        ;
        return m_instVolCount;
    }
 static rw::ResourceDescriptor
    GetResourceDescriptor(uint32_t stackMax,
                          uint32_t resBufferSize);
    static VolumeBBoxQuery *
    Initialize(const rw::Resource& resource,
               uint32_t stackMax,
               uint32_t resBufferSize);
    static void
    Release(VolumeBBoxQuery *)
    {
        ;
        return;
    };
    void
    InitQuery(const rw::collision::Volume **inputVols,
              const rw::math::Matrix44Affine **inputMats,
              const uint32_t numInputs,
              const AABBox &aabb)
    {
        ;
        m_inputVols = inputVols;
        m_inputMats = inputMats;
        m_numInputs = numInputs;
        m_currInput = 0;
        m_stackNext = 0;
        m_primNext = 0;
        m_currVRef.volume = 0;
        m_aggIndex = 0;
        m_curSpatialMapQuery = 0;
        m_instVolCount = 0;
        m_aabb = aabb;
        m_tag = 0;
        m_numTagBits = 0;
        return;
    }
    RwBool
    Finished()
    {
        ;
        if(m_currInput == m_numInputs &&
           m_currVRef.volume == 0 &&
           m_stackNext == 0)
        {
            return (1);
        }
        else
        {
            return (0);
        }
    }
    const rw::collision::Volume **m_inputVols;
    const rw::math::Matrix44Affine **m_inputMats;
    uint32_t m_numInputs;
    uint32_t m_currInput;
    AABBox m_aabb;
    VolRef *m_stackVRefBuffer;
    VolRef m_currVRef;
    uint32_t m_stackNext;
    uint32_t m_stackMax;
    VolRef *m_primVRefBuffer;
    uint32_t m_primNext;
    uint32_t m_primBufferSize;
    Volume *m_instVolPool;
    uint32_t m_instVolCount;
    uint32_t m_instVolMax;
    uint32_t m_aggIndex;
    void* m_spatialMapQueryMem;
    void* m_curSpatialMapQuery;
    uint32_t m_tag;
    uint8_t m_numTagBits;
};
}
}






namespace rw
{
namespace collision
{
struct PrimitivePairIntersectResult;

void
FixupSepDirMethods();
struct PrimitivePairIntersectResult
{
    enum
    {
        MAXPOINTCOUNT = 2 * Feature::MAXEDGECOUNT
    };
    const Volume *v1;
    uint32_t tag1;
    const Volume *v2;
    uint32_t tag2;
    int32_t vNindex;
    Feature f1;
    Feature f2;
    rw::math::Vector3 sepDir;
    float32_t sepDist;
    rw::math::Vector3 normal;
    rw::math::Vector3 pointOn1;
    rw::math::Vector3 pointOn2;
    float32_t distance;
    rw::math::Vector3 pointsOn1[MAXPOINTCOUNT];
    rw::math::Vector3 pointsOn2[MAXPOINTCOUNT];
    float32_t distances[MAXPOINTCOUNT];
    uint32_t numPoints;
    inline PrimitivePairIntersectResult()
    {
    }
};
int32_t
GPInstanceBatchIntersect1xN( PrimitivePairIntersectResult *res,
                             int32_t resBufMaxSize,
                             const GPInstance &inst1, const GPInstance *inst2, int32_t num,
                             float32_t padding = 0.0f );
int32_t
GPInstanceBatchIntersectNx1( PrimitivePairIntersectResult *resBuf,
                            int32_t resBufMaxSize,
                            const GPInstance *insts1, int32_t num, const GPInstance &inst2,
                            float32_t padding = 0.0f );

void
PrimitiveBatchInstance( GPInstance *resBuf,
                        const Volume *vN, const rw::math::Matrix44Affine *tmN, int32_t num );
void
PrimitiveBatchInstance( GPInstance *resBuf,
                        const Volume *vN, const rw::math::Matrix44Affine **tmN, int32_t num );
RwBool PrimitivePairIntersect( PrimitivePairIntersectResult &res,
                               const Volume *v1, const rw::math::Matrix44Affine *tm1,
                               const Volume *v2, const rw::math::Matrix44Affine *tm2,
                               float32_t padding = 0.0f, const rw::math::Vector4 *sepDir = 0 );
int32_t
PrimitiveBatchIntersect1xN( PrimitivePairIntersectResult *res,
                            GPInstance *instancingSPR,
                            const Volume *v1, const rw::math::Matrix44Affine *tm1,
                            const Volume *vN, const rw::math::Matrix44Affine *tmN, int32_t num );
int32_t
PrimitiveBatchIntersect1xN( PrimitivePairIntersectResult *res,
                            GPInstance *instancingSPR,
                            const Volume *v1, const rw::math::Matrix44Affine *tm1,
                            const Volume **vN, const rw::math::Matrix44Affine **tmN, int32_t num );
int32_t
PrimitiveBatchIntersectNxM( PrimitivePairIntersectResult *res,
                            GPInstance *instancingSPR,
                            const Volume **vN, const rw::math::Matrix44Affine **tmN, int32_t numN,
                            const Volume **vM, const rw::math::Matrix44Affine **tmM, int32_t numM );
int32_t
PrimitiveBatchIntersect( PrimitivePairIntersectResult *resBuf,
                         int32_t resBufMaxSize,
                         GPInstance *instancingSPR,
                         VolRefPair *pairs,
                         int32_t numPairs,
                         float32_t padding = 0.0f );

float32_t
SetTriangleEdgeCullingTolerance(float32_t newTolerance);
float32_t
SetTriangleFaceNormalTolerance(float32_t newTolerance);
}
}






namespace rw
{
namespace collision
{
class KDTreeMappedArray;
class KDTreeMappedArray : public MappedArray
{
protected:
    KDTreeMappedArray::KDTreeMappedArray(uint32_t numVols,
                                     VTable *vTable,
                                     uint32_t classSize);
public:
    KDTree *
    GetKDTreeMap()
    {
        ;
        return m_map;
    }
    static rw::ResourceDescriptor
    GetResourceDescriptor(uint32_t numVols, uint32_t numNodes, const rw::collision::AABBox &bbox,
                          const VTable *vTable = &sm_vTable,
                          uint32_t classSize = sizeof(KDTreeMappedArray));
    static KDTreeMappedArray *
    Initialize(const rw::Resource& resource,
               uint32_t numVols,
               uint32_t numNodes,
               rw::collision::AABBox &bbox,
               VTable *vTable = &sm_vTable,
               uint32_t classSize = sizeof(KDTreeMappedArray));
    static KDTreeMappedArray *
    Initialize(void *ptr,
               uint32_t numVols,
               uint32_t numNodes,
               rw::collision::AABBox &bbox,
               VTable *vTable = &sm_vTable,
               uint32_t classSize = sizeof(KDTreeMappedArray));
    void
    Release();
    RwBool
    IsValid();
    uint32_t
    GetSizeThis() const;
    void
    UpdateThis(void);
    RwBool
    LineIntersectionQueryThis(VolumeLineQuery *lineQuery,
                             const rw::math::Matrix44Affine *tm);
    RwBool
    BBoxOverlapQueryThis(VolumeBBoxQuery *bboxQuery,
                         const rw::math::Matrix44Affine *tm);
    static rw::core::arena::SizeAndAlignment *
    Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset);
    static void
    Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator);
    static RwBool
    Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator);
    static void
    RegisterArenaReadCallbacks(void)
    {
        rw::core::arena::ArenaTypeReg *typeReg =
            rw::core::arena::ArenaTypeRegGetType(RWCOBJECTTYPE_KDTREEMAPPEDARRAY);
        ;
        typeReg->fixupCB = Fixup;
        return;
    }
    static void
    RegisterArenaWriteCallbacks(void)
    {
        rw::core::arena::ArenaTypeReg *typeReg =
            rw::core::arena::ArenaTypeRegGetType(RWCOBJECTTYPE_KDTREEMAPPEDARRAY);
        ;
        typeReg->unfixCB = Unfix;
        typeReg->refixCB = Refix;
        return;
    }
private:
    static VTable sm_vTable;
    KDTree *m_map;
};
}
}






namespace rw
{
namespace collision
{
inline __attribute__ ((always_inline)) rw::math::MaskScalar
ComputeSeparation(const rw::math::Vector3 &dir, const GPInstance &gp1, const GPInstance &gp2, rw::math::VecFloat &result)
{
    ;
    Interval interval1, interval2;
    gp1.GetInterval( dir, interval1 );
    gp2.GetInterval( dir, interval2 );
    rw::math::VecFloat sepa = interval1.min - interval2.max;
    rw::math::VecFloat sepb = interval2.min - interval1.max;
    rw::math::MaskScalar useSepA = CompGreaterThan(sepa, sepb);
    result = Select(useSepA, sepa, sepb);
    return useSepA;
}
rw::math::VecFloat
FindBestSeparatingDirection( rw::math::Vector3 &bestSepDir, const GPInstance &gp1, const GPInstance &gp2 );
rw::math::VecFloat
FindBestSeparatingDirectionBoxBox( rw::math::Vector3 &bestSepDir, const GPInstance &gp1, const GPInstance &gp2 );
rw::math::VecFloat
FindBestSeparatingDirectionTriBox( rw::math::Vector3 &bestSepDir, const GPInstance &gp1, const GPInstance &gp2 );
inline rw::math::VecFloat
FindBestSeparatingDirectionBoxTri( rw::math::Vector3 &bestSepDir, const GPInstance &gp1, const GPInstance &gp2 )
{
    rw::math::VecFloat ret = FindBestSeparatingDirectionTriBox(bestSepDir, gp2, gp1);
    bestSepDir = -bestSepDir;
    return ret;
}
inline __attribute__ ((always_inline)) rw::math::VecFloat
FindBestSeparatingDirectionSphSph( rw::math::Vector3 &bestSepDir, const GPInstance &gp1, const GPInstance &gp2 )
{
    rw::math::Vector3 res = gp2.Pos() - gp1.Pos();
    return NormalizeReturnMagnitude(res, bestSepDir);
}
}
}






namespace rw
{
namespace collision
{




























































}
}






namespace rw
{
namespace collision
{
class SimpleMappedArray;
class SimpleMappedArray : public MappedArray
{
protected:
    SimpleMappedArray(uint32_t numVols,
                    VTable *vTable,
                    uint32_t classSize);
public:
    uint32_t
    GetSizeThis() const;
    static rw::ResourceDescriptor
    GetResourceDescriptor(uint32_t numVols,
                          const VTable *vTable = &sm_vTable,
                          uint32_t classSize = sizeof(SimpleMappedArray));
    static SimpleMappedArray *
    Initialize(const rw::Resource& resource,
               uint32_t numVols,
               VTable *vTable = &sm_vTable,
               uint32_t classSize = sizeof(SimpleMappedArray));
    void
    Release();
    void
    UpdateThis(void);
    RwBool
    LineIntersectionQueryThis(VolumeLineQuery *lineQuery,
                             const rw::math::Matrix44Affine *tm);
    RwBool
    BBoxOverlapQueryThis(VolumeBBoxQuery *bboxQuery,
                         const rw::math::Matrix44Affine *tm);
    static rw::core::arena::SizeAndAlignment *
    Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset);
    static void
    Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator);
    static RwBool
    Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator);
    static void
    RegisterArenaReadCallbacks(void)
    {
        rw::core::arena::ArenaTypeReg *typeReg =
            rw::core::arena::ArenaTypeRegGetType(RWCOBJECTTYPE_SIMPLEMAPPEDARRAY);
        ;
        typeReg->fixupCB = Fixup;
        return;
    }
 static void
    RegisterArenaWriteCallbacks(void)
    {
        rw::core::arena::ArenaTypeReg *typeReg =
            rw::core::arena::ArenaTypeRegGetType(RWCOBJECTTYPE_SIMPLEMAPPEDARRAY);
        ;
        typeReg->unfixCB = Unfix;
        typeReg->refixCB = Refix;
        return;
    }
private:
    static VTable sm_vTable;
};
}
}






namespace rw
{
namespace collision
{
typedef class VolumeVolumeQuery VolumeVolumeQuery;
class VolumeVolumeQuery
{
public:
    VolumeVolumeQuery(uint32_t stackSize,
                      uint32_t resBufferSize);
    uint32_t
    GetPrimitiveBBoxOverlaps();
    uint32_t
    GetPrimitiveIntersections();
    static rw::ResourceDescriptor
    GetResourceDescriptor(uint32_t stackSize, uint32_t resBufferSize);
    static VolumeVolumeQuery *
    Initialize(const rw::Resource& resource, uint32_t stackSize, uint32_t resBufferSize);
    static void
    Release(VolumeVolumeQuery *)
    {
        ;
        return;
    };
    VolRefPair *
    GetOverlapResultsBuffer() const
    {
        ;
        return m_volRefPairBuffer;
    }
    uint32_t
    GetNumOverlaps() const
    {
        ;
        return m_volRef1xNCount;
    }
    PrimitivePairIntersectResult*
    GetIntersectionResultsBuffer() const
    {
        ;
        return m_intersectionBuffer;
    }
    void
    InitQuery(const rw::collision::Volume **inputVols,
              const rw::math::Matrix44Affine **inputMats,
              const uint32_t numInputs,
              const rw::collision::Volume *queryVol,
              const rw::math::Matrix44Affine *queryMtx,
              const rw::BitTable *cullTable = 0,
              float32_t padding = 0.0f)
    {
        ;
        m_inputVols = inputVols;
        m_inputMats = inputMats;
        m_numInputs = numInputs;
        m_currInput = 0;
        m_volRefPairCount = 0;
        m_queryVol = queryVol;
        m_queryMtx = queryMtx;
        m_padding = padding;
        m_cullTable = cullTable;
        return;
    }
    const rw::collision::Volume **m_inputVols;
    const rw::math::Matrix44Affine **m_inputMats;
    uint32_t m_numInputs;
    uint32_t m_currInput;
    const rw::BitTable *m_cullTable;
    float32_t m_padding;
    VolRefPair *m_volRefPairBuffer;
    uint32_t m_volRefPairCount;
    uint32_t m_volRefPairBufferSize;
    VolRef1xN *m_volRef1xNBuffer;
    uint32_t m_volRef1xNCount;
    GPInstance *m_instancingSPR;
    PrimitivePairIntersectResult *m_intersectionBuffer;
    int32_t m_intersectionBufferMaxSize;
    const rw::collision::Volume *m_queryVol;
    const rw::math::Matrix44Affine *m_queryMtx;
    VolumeBBoxQuery *m_bBoxQueryAtoB;
    VolumeBBoxQuery *m_bBoxQueryBtoA;
















};
}
}







namespace rw
{
namespace collision
{
class TriangleVolume;
extern Volume::VTable globalTriangleVTable;
class TriangleVolume : public Volume
{
protected:
    TriangleVolume(rw::math::Vector3::InParam p1,
                   rw::math::Vector3::InParam p2,
                   rw::math::Vector3::InParam p3);
public:
    static rw::ResourceDescriptor
    GetResourceDescriptor()
    {
        ;
        return rw::ResourceDescriptor(sizeof(Volume), (16));
    }
    static rw::ResourceDescriptor
    GetResourceDescriptor(rw::math::Vector3::InParam ,
                          rw::math::Vector3::InParam ,
                          rw::math::Vector3::InParam )
    {
        ;
        return GetResourceDescriptor();
    }
    static TriangleVolume *
    Initialize(const rw::Resource& resource, rw::math::Vector3::InParam p1,
               rw::math::Vector3::InParam p2, rw::math::Vector3::InParam p3);
    void
    GetNormal(rw::math::Vector3 &normal, const rw::math::Matrix44Affine *tm = 0) const;
    void
    GetPoints(rw::math::Vector3 &p1,
              rw::math::Vector3 &p2,
              rw::math::Vector3 &p3,
              const rw::math::Matrix44Affine *tm = 0) const;
    void
    SetPoints(rw::math::Vector3::InParam p1,
              rw::math::Vector3::InParam p2,
              rw::math::Vector3::InParam p3);
    float32_t GetEdgeCos(uint32_t i) const;
    math::Vector3 GetEdgeCosVector() const;
    void SetEdgeCos(float32_t ec0, float32_t ec1, float32_t ec2);
    RwBool
    GetBBox(const rw::math::Matrix44Affine *tm, RwBool tight, AABBox &bBox) const;
    rw::math::Vector3
        GetBBoxDiag() const;
    RwBool
    CreateGPInstance(GPInstance &instance, const rw::math::Matrix44Affine *tm) const;
    RwBool
    GetInterval(rw::math::Vector3::InParam dir, Interval &interval) const;
    RwBool
    GetMaximumFeature(RwBool ccw, rw::math::Vector3::InParam dir, Feature &feature) const;
    RwBool
    LineSegIntersect(rw::math::Vector3::InParam pt1,
                     rw::math::Vector3::InParam pt2,
                     const rw::math::Matrix44Affine *tm,
                     VolumeLineSegIntersectResult &result,
                     const float32_t fatness = 0.0f) const;
    void Release() {}
private:
};
RwBool
TriangleLineSegIntersect(VolumeLineSegIntersectResult &result,
                         rw::math::Vector3::InParam lineStart,
                         rw::math::Vector3::InParam lineDelta,
                         rw::math::Vector3::InParam v0,
                         rw::math::Vector3::InParam v1,
                         rw::math::Vector3::InParam v2,
                         const float32_t fatness = 0.0f);
inline void
TriangleVolume::GetNormal(rw::math::Vector3 &normal, const rw::math::Matrix44Affine *tm) const
{
    rw::math::Vector3 tmpNormal = transform.GetW();
    if (m_flags & VOLUMEFLAG_TRIANGLENORMALISDIRTY)
    {
        rw::math::Vector3 n = rw::math::Cross(transform.YAxis() - transform.XAxis(),
                                              transform.ZAxis() - transform.XAxis());
        rw::math::VecFloat len2 = rw::math::MagnitudeSquared(n);
        n = Select(CompGreaterThan(len2, VEC_EPSILON), n * rw::math::InvSqrtFast(len2), n);
        const_cast<TriangleVolume*>(this)->m_flags &= ~VOLUMEFLAG_TRIANGLENORMALISDIRTY;
        transform.SetW(n);
        tmpNormal=n;
    }
    if (tm)
    {
        tmpNormal = TransformVector(tmpNormal, *tm);
    }
    normal = tmpNormal;
}
inline void
TriangleVolume::GetPoints(rw::math::Vector3 &p1,
            rw::math::Vector3 &p2,
            rw::math::Vector3 &p3,
            const rw::math::Matrix44Affine *tm) const
{
    if (tm)
    {
        p1 = TransformPoint(transform.XAxis(), *tm);
        p2 = TransformPoint(transform.YAxis(), *tm);
        p3 = TransformPoint(transform.ZAxis(), *tm);
    }
    else
    {
        p1 = transform.XAxis();
        p2 = transform.YAxis();
        p3 = transform.ZAxis();
    }
}
inline TriangleVolume *
TriangleVolume::Initialize(const Resource& resource,
                           rw::math::Vector3::InParam p1, rw::math::Vector3::InParam p2, rw::math::Vector3::InParam p3)
{
    ;
    ;
    return new (resource.GetMemoryResource()) TriangleVolume(p1, p2, p3);
}
inline void
TriangleVolume::SetPoints(rw::math::Vector3::InParam p1,
            rw::math::Vector3::InParam p2,
            rw::math::Vector3::InParam p3)
{
    transform.XAxis() = p1;
    transform.YAxis() = p2;
    transform.ZAxis() = p3;
    m_flags |= VOLUMEFLAG_TRIANGLENORMALISDIRTY;
}
inline float32_t
TriangleVolume::GetEdgeCos(uint32_t i) const
{
    ;
    ;
    return i==0 ? triangleData.edgeCos0 : i==1 ? triangleData.edgeCos1 : triangleData.edgeCos2;
}
inline math::Vector3
TriangleVolume::GetEdgeCosVector() const
{
    ;
    return math::Vector3(triangleData.edgeCos0, triangleData.edgeCos1, triangleData.edgeCos2);
}
inline void
TriangleVolume::SetEdgeCos(float32_t ec0, float32_t ec1, float32_t ec2)
{
    ;
    triangleData.edgeCos0 = ec0;
    triangleData.edgeCos1 = ec1;
    triangleData.edgeCos2 = ec2;
    return;
}
inline
TriangleVolume::TriangleVolume(rw::math::Vector3::InParam p1,
               rw::math::Vector3::InParam p2,
               rw::math::Vector3::InParam p3)
               : Volume(rw::collision::VOLUMETYPETRIANGLE)
{
    m_flags = VOLUMEFLAG_TRIANGLEDEFAULT;
    SetPoints(p1, p2, p3);
    SetEdgeCos(-1.0f,-1.0f,-1.0f);
}


inline
RwBool
ThinTriangleLineSegIntersect(VolumeLineSegIntersectResult &result,
                             rw::math::Vector3::InParam lineStart,
                             rw::math::Vector3::InParam lineDelta,
                             rw::math::Vector3::InParam v0,
                             rw::math::Vector3::InParam v1,
                             rw::math::Vector3::InParam v2 )
{
    ;
    rw::math::Vector3 edge1, edge2, tVec, pVec, qVec;
    float32_t det;
    float32_t lo, hi, u, t;
    u = t = 0.0f;
    edge1 = v1 - v0;
    edge2 = v2 - v0;
    pVec = rw::math::Cross( lineDelta, edge2 );
    det = rw::math::Dot( edge1, pVec );
    if (det > (float32_t)(1e-8))
    {
        lo = - det*(float32_t)(1e-5);
        hi = det - lo;
        tVec = lineStart - v0;
        u = rw::math::Dot( tVec, pVec );
        if (u >= lo && u <= hi)
        {
            qVec = rw::math::Cross( tVec, edge1 );
            t = rw::math::Dot( lineDelta, qVec );
            if (t >= lo && (u + t) <= hi)
            {
                result.lineParam = rw::math::Dot(edge2, qVec);
                if (result.lineParam >= lo && result.lineParam <= hi)
                {
                    hi = rw::math::Reciprocal(det);
                    result.lineParam *= hi;
                    result.position = lineStart + lineDelta * rw::math::VecFloat(result.lineParam);
                    result.volParam.Set(u*hi, t*hi, 0.0f);
                    return (1);
                }
            }
        }
    }
    return (0);
}
}
}






namespace rw
{
namespace collision
{
class BoxVolume;
extern Volume::VTable globalBoxVTable;
class BoxVolume : public Volume
{
protected:
    BoxVolume(rw::math::Vector3::InParam dimensions)
    : Volume(rw::collision::VOLUMETYPEBOX)
    {
        ;
        ;
        ;
        ;
        boxData.hx = dimensions.X();
        boxData.hy = dimensions.Y();
        boxData.hz = dimensions.Z();
        return;
    }
    rw::math::Vector3
    GetDimensions() const
    {
        ;
        rw::math::Vector3 dimensions(rw::math::VecFloat(boxData.hx), rw::math::VecFloat(boxData.hy), rw::math::VecFloat(boxData.hz));
        return dimensions;
    }
public:
    static rw::ResourceDescriptor
    GetResourceDescriptor(rw::math::Vector3::InParam )
    {
        ;
        return rw::ResourceDescriptor(sizeof(Volume), (16));
    }
    static rw::ResourceDescriptor
    GetResourceDescriptor(float32_t = 0,float32_t = 0,
                          float32_t = 0)
    {
        ;
        return rw::ResourceDescriptor(sizeof(Volume), (16));
    }
    static BoxVolume *
    Initialize(const rw::Resource& resource, rw::math::Vector3::InParam dimensions);
    static BoxVolume *
    Initialize(const rw::Resource& resource, float32_t halfX,float32_t halfY,float32_t halfZ);
    void
    GetDimensions(rw::math::Vector3 &dimensions) const
    {
        dimensions.Set(boxData.hx,boxData.hy,boxData.hz);
    }
    void
    SetDimensions(rw::math::Vector3::InParam dimensions)
    {
        ;
        ;
        ;
        ;
        boxData.hx = dimensions.X();
        boxData.hy = dimensions.Y();
        boxData.hz = dimensions.Z();
        return;
    }
    RwBool
    GetBBox(const rw::math::Matrix44Affine *tm, RwBool tight, AABBox &bBox) const;
    rw::math::Vector3
        GetBBoxDiag() const;
    RwBool
    CreateGPInstance(GPInstance &instance, const rw::math::Matrix44Affine *tm) const;
    RwBool
    GetInterval(rw::math::Vector3::InParam dir, Interval &interval) const;
    RwBool
    GetMaximumFeature(RwBool ccw, rw::math::Vector3::InParam dir, Feature &feature) const;
    RwBool
    LineSegIntersect(const rw::math::Vector3 & pt1,
                     const rw::math::Vector3 & pt2,
                     const rw::math::Matrix44Affine *tm,
                     VolumeLineSegIntersectResult &result,
                     const float32_t = 0.0f) const;
    void Release() {}
private:
};
int32_t
rwcPlaneLineSegIntersect(Fraction *dist, float32_t orig_i, float32_t seg_i, float32_t sign, float32_t disp);
}
}






namespace rw
{
namespace collision
{
class CylinderVolume;
enum CylinderBoxSizeIndex
{
    HALFHEIGHT_INDEX = 0,
    RADIUS_INDEX = 1,
    CYLINDERBOXSIZEINDEX_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
extern Volume::VTable globalCylinderVTable;
class CylinderVolume : public Volume
{
protected:
    CylinderVolume()
    : Volume(rw::collision::VOLUMETYPECYLINDER)
    {
        cylinderData.innerRadius = 0.0f;
        cylinderData.hh = 0.0f;
    }
    CylinderVolume(float32_t innerRadius, float32_t hh)
    : Volume(rw::collision::VOLUMETYPECYLINDER)
    {
        cylinderData.innerRadius = innerRadius;
        cylinderData.hh = hh;
    }
public:
    static rw::ResourceDescriptor
    GetResourceDescriptor(float32_t = 0, float32_t = 0)
    {
        ;
        return rw::ResourceDescriptor(sizeof(Volume), (16));
    }
    static CylinderVolume *
    Initialize(const rw::Resource& resource, float32_t innerRadius, float32_t hh);
    float32_t
    GetHalfHeight() const
    {
        return cylinderData.hh;
    }
    void
    SetHalfHeight(const float32_t halfHeight)
    {
        cylinderData.hh = halfHeight;
    }
    float32_t
    GetInnerRadius() const
    {
        return cylinderData.innerRadius;
    }
    void
    SetInnerRadius(const float32_t innerRadius)
    {
        cylinderData.innerRadius = innerRadius;
    }
    RwBool
    GetBBox(const rw::math::Matrix44Affine *tm, RwBool tight, AABBox &bBox) const;
    rw::math::Vector3
        GetBBoxDiag() const;
    RwBool
    CreateGPInstance(GPInstance &instance, const rw::math::Matrix44Affine *tm) const;
    RwBool
    GetInterval(const rw::math::Vector3 & dir, Interval &interval) const;
    RwBool
    GetMaximumFeature(RwBool ccw, const rw::math::Vector3 & dir, Feature &feature) const;
    RwBool
    LineSegIntersect(const rw::math::Vector3 & pt1,
                     const rw::math::Vector3 & pt2,
                     const rw::math::Matrix44Affine *tm,
                     VolumeLineSegIntersectResult &result,
                     float32_t fatness = 0.0f) const;
    RwBool
    ThinLineSegIntersect(const rw::math::Vector3 & pt1,
                         const rw::math::Vector3 & pt2,
                         const rw::math::Matrix44Affine *tm,
                         VolumeLineSegIntersectResult &result) const;
    RwBool
    FatLineSegIntersect(const rw::math::Vector3 & pt1,
                     const rw::math::Vector3 & pt2,
                     const rw::math::Matrix44Affine *tm,
                     VolumeLineSegIntersectResult &result,
                     float32_t fatness = 0.0f) const;
    void Release() {}
private:
};
RwBool
SolveQuarticRoots(float32_t coefficients[5], float32_t & root);
int32_t
rwcTorusLineSegIntersect(float32_t & dist,
                         rw::math::Vector3::InParam orig,
                         rw::math::Vector3::InParam dir,
                         float32_t majorRadius,
                         float32_t minorRadius);
}
}






namespace rw
{
namespace collision
{
rw::math::VecFloat
FindBestSepDirWithCylinder( rw::math::Vector3 &bestSepDir, const GPCylinder &gp1, const GPInstance &gp2 );
inline rw::math::VecFloat
FindBestSeparatingDirCylVol( rw::math::Vector3 &bestSepDir, const GPInstance &gpCylinder, const GPInstance &gpOther )
{
    return FindBestSepDirWithCylinder(bestSepDir, static_cast<const GPCylinder&> (gpCylinder), gpOther);
}
inline rw::math::VecFloat
FindBestSeparatingDirVolCyl( rw::math::Vector3 &bestSepDir, const GPInstance &gpOther, const GPInstance &gpCylinder )
{
    rw::math::VecFloat ret = FindBestSepDirWithCylinder(bestSepDir, static_cast<const GPCylinder&> (gpCylinder), gpOther);
    bestSepDir = -bestSepDir;
    return ret;
}
}
}






namespace rw
{
namespace collision
{
class AggregateVolume;
extern Volume::VTable globalAggregateVolumeVTable;
class AggregateVolume : public Volume
{
protected:
 AggregateVolume(Aggregate *agg)
    : Volume(rw::collision::VOLUMETYPEAGGREGATE)
    {
        SetAggregate(agg);
    }
public:
    static rw::ResourceDescriptor
    GetResourceDescriptor(Aggregate * = 0)
    {
        ;
        return rw::ResourceDescriptor(sizeof(Volume), (16));
    }
    static AggregateVolume *
    Initialize(const rw::Resource& resource, Aggregate *agg);
    void
    SetAggregate(Aggregate *agg)
    {
        ;
        ;
        *reinterpret_cast<Aggregate* *>(&aggregateData.agg) = agg;
        return;
    }
    Aggregate *
    GetAggregate() const
    {
        ;
        return (Aggregate *)rw::RwPtrToHostPtr(*reinterpret_cast<Aggregate* const *>(&aggregateData.agg));
    }
    RwBool
    GetBBox(const rw::math::Matrix44Affine *tm, RwBool tight, AABBox &bBox) const;
    rw::math::Vector3
        GetBBoxDiag() const;
    RwBool
    CreateGPInstance(GPInstance &instance, const rw::math::Matrix44Affine *tm) const;
    RwBool
    GetMaximumFeature(RwBool ccw, const rw::math::Vector3 & dir, Feature &feature) const;
    void Release() {}
private:
};
}
}






namespace rw
{
namespace collision
{
class Procedural;
class Procedural : public Aggregate
{
protected:
    Procedural(uint32_t numVolumes, VTable *vTable)
    : Aggregate(numVolumes, vTable)
    {
    }
    static rw::core::arena::SizeAndAlignment *
    Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset)
    {
        ;
        return Aggregate::Unfix(ptr, offset);
    }
    static void
    Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator)
    {
        ;
        Aggregate::Refix(ptr, offset, iterator);
        return;
    }
    static RwBool
    Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator)
    {
        ;
        return Aggregate::Fixup(ptr, iterator);
    }
};
}
}






namespace rw
{
namespace collision
{




class TriangleKDTreeProcedural : public Procedural
{
protected:
    TriangleKDTreeProcedural(uint32_t numVerts,
                             uint32_t numTris,
                             VTable *vTable,
                             uint32_t classSize);
public:
    struct Triangle
    {
        uint32_t indices[3];
        uint32_t id;
    };
    uint32_t
    GetSizeThis() const;
    static rw::ResourceDescriptor
    GetResourceDescriptor(uint32_t numVerts,
                          uint32_t numTris,
                          uint32_t numNodes,
                          const rw::collision::AABBox &bbox,
                          const VTable *vTable = &sm_vTable,
                          uint32_t classSize = sizeof(TriangleKDTreeProcedural));
    static TriangleKDTreeProcedural *
    Initialize(const rw::Resource& resource,
               uint32_t numVerts,
               uint32_t numTris,
               uint32_t numNodes,
               rw::collision::AABBox &bbox,
               VTable *vTable = &sm_vTable,
               uint32_t classSize = sizeof(TriangleKDTreeProcedural));
    static void
    Release(TriangleKDTreeProcedural *triKDTree);
    rw::math::Vector3 *
    GetVertices()
    {
        ;
        return m_verts;
    }
    const rw::math::Vector3 *
    GetVertices() const
    {
        ;
        return m_verts;
    }
    Triangle *
    GetTriangles()
    {
        ;
        return m_tris;
    }
    const Triangle *
    GetTriangles() const
    {
        ;
        return m_tris;
    }
    inline uint32_t
    GetTriangleFlags(uint32_t index) const
    {
        ;
        ;
        return (((m_flags[index >> 3] >> (4 * (index & 7))) & 15) * VOLUMEFLAG_TRIANGLEONESIDED) | VOLUMEFLAG_ISENABLED | VOLUMEFLAG_TRIANGLENORMALISDIRTY;

    }
    inline void
    SetTriangleFlags(uint32_t index, uint32_t set1, uint32_t set0 = 15)
    {
        ;
        ;
        ;
        ;
        uint32_t i,j;
        i = index >> 3;
        j = 4 * (index & 7);
        m_flags[i] = (m_flags[i] & ~(set0 << j)) | (set1 << j);
        return;
    }
    const rw::collision::KDTree *
    GetKDTree() const
    {
        ;
        return m_map;
    }
    rw::collision::KDTree *
    GetKDTree()
    {
        ;
        return m_map;
    }
    RwBool
    IsValid();
    void
    UpdateThis(void);
    RwBool
    LineIntersectionQueryThis(VolumeLineQuery *lineQuery,
                              const rw::math::Matrix44Affine *tm);
    RwBool
    BBoxOverlapQueryThis(VolumeBBoxQuery *bboxQuery,
                         const rw::math::Matrix44Affine *tm);
    static rw::core::arena::SizeAndAlignment *
    Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset);
    static void
    Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator);
    static RwBool
    Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator);
    static void
    RegisterArenaReadCallbacks(void)
    {
        rw::core::arena::ArenaTypeReg *typeReg =
            rw::core::arena::ArenaTypeRegGetType(RWCOBJECTTYPE_TRIANGLEKDTREEPROCEDURAL);
        ;
        typeReg->fixupCB = Fixup;
        return;
    }
    static void
    RegisterArenaWriteCallbacks(void)
    {
        rw::core::arena::ArenaTypeReg *typeReg =
            rw::core::arena::ArenaTypeRegGetType(RWCOBJECTTYPE_TRIANGLEKDTREEPROCEDURAL);
        ;
        typeReg->unfixCB = Unfix;
        typeReg->refixCB = Refix;
        return;
    }
    float32_t
    GetTriangleNormal(uint32_t i, rw::math::Vector3 &result) const;
    void
    AutoSetFlags(float32_t tolerance = 0.1f);
private:
    RwBool
    TriangleIsOutside(uint32_t i, uint32_t j, const rw::math::Vector3 &inorm) const;
    void
    MateTriangles(uint32_t i, uint32_t j, float32_t eps, float32_t inradius, const rw::math::Vector3 &inorm);
private:
    static VTable sm_vTable;
    uint32_t m_numVerts;
    Triangle* m_tris;
    rw::math::Vector3* m_verts;
    KDTree* m_map;
    uint32_t* m_flags;
};



}
}






namespace rw
{
namespace collision
{
enum CMFlags
{
    CMFLAG_INT16VERTEX = 1,
    CMFLAG_INT16NORMAL = 2,
    CMFLAG_20BITCLUSTERINDEX = 4,
    CMFLAG_ONESIDED = 16,
    CMFLAG_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
enum UnitTypeAndFlags
{
    UNITTYPE_OLDTRIANGLE = 0,
    UNITTYPE_TRIANGLE = 1,
    UNITTYPE_QUAD = 2,
    UNITTYPE_TRILIST = 3,
    UNITTYPE_MASK = 15,
    UNITFLAG_NORMAL = 16,
    UNITFLAG_EDGEANGLE = 32,
    UNITFLAG_GROUPID = 64,
    UNITFLAG_SURFACEID = 128,
    UNITFLAG_USEOLDTRI = 255,
    UNITFLAG_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
enum UnitEdgeFlags
{
    EDGEFLAG_ANGLEZERO = 26,
    EDGEFLAG_ANGLEMASK = 0x1F,
    EDGEFLAG_EDGECONVEX = 0x20,
    EDGEFLAG_VERTEXDISABLE = 0x40,
    EDGEFLAG_EDGEUNMATCHED = 0x80
};
enum SpecialNormalTags
{
    NORMAL_NA = -1,
    NORMAL_POSX = 250,
    NORMAL_NEGX = 251,
    NORMAL_POSY = 252,
    NORMAL_NEGY = 253,
    NORMAL_POSZ = 254,
    NORMAL_NEGZ = 255,
    NORMAL_INVALID = 999,
    NORMAL_FORCEENUMSIZEINT = ((int32_t)((~((uint32_t)0))>>1))
};
class ClusteredMeshCluster
{
    ClusteredMeshCluster();
public:
 enum
 {
  VERTICES_UNCOMPRESSED = 0,
  VERTICES_16BIT_COMPRESSED = 1,
  VERTICES_32BIT_COMPRESSED = 2
 };
    struct Vertex16
    {
        uint16_t x;
        uint16_t y;
        uint16_t z;
    };
    struct Vertex32
    {
        int32_t x;
        int32_t y;
        int32_t z;
    };
    rw::math::Vector3 GetVertex(uint8_t vertid, const float32_t &vertexGranularity);
    void Get3Vertices(rw::math::Vector3 *out, uint8_t v0, uint8_t v1, uint8_t v2, const float32_t &vertexGranularity);
    void Get4Vertices(rw::math::Vector3 *out, uint8_t v0, uint8_t v1, uint8_t v2, uint8_t v3, const float32_t &vertexGranularity);
    uint8_t *UnitData();
    rw::math::Vector3 *NormalArray();
public:
    uint16_t unitCount;
    uint16_t unitDataSize;
    uint16_t unitDataStart;
    uint16_t normalStart;
    uint8_t vertexCount;
    uint8_t normalCount;
    uint8_t compressionMode;
    uint8_t padding[5];
    rw::math::Vector3 vertexArray[1];
};
inline rw::math::Vector3
ClusteredMeshCluster::GetVertex(uint8_t vertid, const float32_t &vertexGranularity )
{
    ;
    if ( compressionMode == VERTICES_16BIT_COMPRESSED )
    {
        int32_t *vertexOffsetData = reinterpret_cast<int32_t*>(vertexArray);
        Vertex16 *vertData = reinterpret_cast<Vertex16*>(vertexArray);
        vertData += 2;

        ;
        __attribute__((altivec(vector__))) float zero = (__attribute__((altivec(vector__))) float)vec_splat_s32(0);
        __attribute__((altivec(vector__))) int vert_offset = vec_ld(0, vertexOffsetData);
        __attribute__((altivec(vector__))) int vert_l = (__attribute__((altivec(vector__))) int)vec_lvlx(0, &vertData[vertid].x);
        __attribute__((altivec(vector__))) int vert_r = (__attribute__((altivec(vector__))) int)vec_lvrx(16, &vertData[vertid].x);
        __attribute__((altivec(vector__))) int vert_i = vec_or(vert_l, vert_r);
                     vert_i = (__attribute__((altivec(vector__))) int)vec_mergeh((__attribute__((altivec(vector__))) short)zero, (__attribute__((altivec(vector__))) short)vert_i);
                     vert_i = vec_add(vert_i, vert_offset);
        __attribute__((altivec(vector__))) float floatvert = vec_ctf(vert_i, 0);
        __attribute__((altivec(vector__))) float vertGran = (__attribute__((altivec(vector__))) float)vec_lvlx(0, &vertexGranularity);
                     vertGran = vec_splat(vertGran, 0);
        return rw::math::Vector3(vec_madd(floatvert, vertGran, zero));



















    }
    else
    {
        if ( compressionMode == VERTICES_32BIT_COMPRESSED )
        {
            Vertex32 *vertData = reinterpret_cast<Vertex32*>(vertexArray);

            __attribute__((altivec(vector__))) float zero = (__attribute__((altivec(vector__))) float)vec_splat_s32(0);
            __attribute__((altivec(vector__))) int vert_l = (__attribute__((altivec(vector__))) int)vec_lvlx(0, &vertData[vertid].x);
            __attribute__((altivec(vector__))) int vert_r = (__attribute__((altivec(vector__))) int)vec_lvrx(16, &vertData[vertid].x);
            __attribute__((altivec(vector__))) int vert_i = vec_or(vert_l, vert_r);
            __attribute__((altivec(vector__))) float floatvert = vec_ctf(vert_i, 0);
            __attribute__((altivec(vector__))) float vertGran = (__attribute__((altivec(vector__))) float)vec_lvlx(0, &vertexGranularity);
                         vertGran = vec_splat(vertGran, 0);
            return rw::math::Vector3(vec_madd(floatvert, vertGran, zero));













        }
        else
        {
            return vertexArray[vertid];
        }
    }
}
inline void
ClusteredMeshCluster::Get3Vertices(rw::math::Vector3 *out, uint8_t v0, uint8_t v1, uint8_t v2, const float32_t &g)
{
    ;
    if (compressionMode == VERTICES_16BIT_COMPRESSED)
    {
        int32_t *offset = reinterpret_cast<int32_t*>(vertexArray);
        Vertex16 *vert = reinterpret_cast<Vertex16*>(vertexArray) + 2;

        ;
        __attribute__((altivec(vector__))) float zero = (__attribute__((altivec(vector__))) float)vec_splat_s32(0);
        __attribute__((altivec(vector__))) int vert_offset = vec_ld(0, offset);
        __attribute__((altivec(vector__))) float vertGran = (__attribute__((altivec(vector__))) float)vec_lvlx(0, &g);
        vertGran = vec_splat(vertGran, 0);
        __attribute__((altivec(vector__))) int vert_0_l = (__attribute__((altivec(vector__))) int)vec_lvlx(0, &vert[v0].x);
        __attribute__((altivec(vector__))) int vert_1_l = (__attribute__((altivec(vector__))) int)vec_lvlx(0, &vert[v1].x);
        __attribute__((altivec(vector__))) int vert_2_l = (__attribute__((altivec(vector__))) int)vec_lvlx(0, &vert[v2].x);
        __attribute__((altivec(vector__))) int vert_0_r = (__attribute__((altivec(vector__))) int)vec_lvrx(16, &vert[v0].x);
        __attribute__((altivec(vector__))) int vert_1_r = (__attribute__((altivec(vector__))) int)vec_lvrx(16, &vert[v1].x);
        __attribute__((altivec(vector__))) int vert_2_r = (__attribute__((altivec(vector__))) int)vec_lvrx(16, &vert[v2].x);
        __attribute__((altivec(vector__))) int vert_0_i = vec_or(vert_0_l, vert_0_r);
        __attribute__((altivec(vector__))) int vert_1_i = vec_or(vert_1_l, vert_1_r);
        __attribute__((altivec(vector__))) int vert_2_i = vec_or(vert_2_l, vert_2_r);
        vert_0_i = (__attribute__((altivec(vector__))) int)vec_mergeh((__attribute__((altivec(vector__))) short)zero, (__attribute__((altivec(vector__))) short)vert_0_i);
        vert_1_i = (__attribute__((altivec(vector__))) int)vec_mergeh((__attribute__((altivec(vector__))) short)zero, (__attribute__((altivec(vector__))) short)vert_1_i);
        vert_2_i = (__attribute__((altivec(vector__))) int)vec_mergeh((__attribute__((altivec(vector__))) short)zero, (__attribute__((altivec(vector__))) short)vert_2_i);
        vert_0_i = vec_add(vert_0_i, vert_offset);
        vert_1_i = vec_add(vert_1_i, vert_offset);
        vert_2_i = vec_add(vert_2_i, vert_offset);
        __attribute__((altivec(vector__))) float floatvert_0 = vec_ctf(vert_0_i, 0);
        __attribute__((altivec(vector__))) float floatvert_1 = vec_ctf(vert_1_i, 0);
        __attribute__((altivec(vector__))) float floatvert_2 = vec_ctf(vert_2_i, 0);
        out[0] = rw::math::Vector3(vec_madd(floatvert_0, vertGran, zero));
        out[1] = rw::math::Vector3(vec_madd(floatvert_1, vertGran, zero));
        out[2] = rw::math::Vector3(vec_madd(floatvert_2, vertGran, zero));



































    }
    else if (compressionMode == VERTICES_32BIT_COMPRESSED)
    {
        Vertex32 *vert = reinterpret_cast<Vertex32*>(vertexArray);

        __attribute__((altivec(vector__))) float zero = (__attribute__((altivec(vector__))) float)vec_splat_s32(0);
        __attribute__((altivec(vector__))) float vertGran = (__attribute__((altivec(vector__))) float)vec_lvlx(0, &g);
                     vertGran = vec_splat(vertGran, 0);
        __attribute__((altivec(vector__))) int vert_0_l = (__attribute__((altivec(vector__))) int)vec_lvlx(0, &vert[v0].x);
        __attribute__((altivec(vector__))) int vert_1_l = (__attribute__((altivec(vector__))) int)vec_lvlx(0, &vert[v1].x);
        __attribute__((altivec(vector__))) int vert_2_l = (__attribute__((altivec(vector__))) int)vec_lvlx(0, &vert[v2].x);
        __attribute__((altivec(vector__))) int vert_0_r = (__attribute__((altivec(vector__))) int)vec_lvrx(16, &vert[v0].x);
        __attribute__((altivec(vector__))) int vert_1_r = (__attribute__((altivec(vector__))) int)vec_lvrx(16, &vert[v1].x);
        __attribute__((altivec(vector__))) int vert_2_r = (__attribute__((altivec(vector__))) int)vec_lvrx(16, &vert[v2].x);
        __attribute__((altivec(vector__))) int vert_0_i = vec_or(vert_0_l, vert_0_r);
        __attribute__((altivec(vector__))) int vert_1_i = vec_or(vert_1_l, vert_1_r);
        __attribute__((altivec(vector__))) int vert_2_i = vec_or(vert_2_l, vert_2_r);
        __attribute__((altivec(vector__))) float floatvert_0 = vec_ctf(vert_0_i, 0);
        __attribute__((altivec(vector__))) float floatvert_1 = vec_ctf(vert_1_i, 0);
        __attribute__((altivec(vector__))) float floatvert_2 = vec_ctf(vert_2_i, 0);
        out[0] = rw::math::Vector3(vec_madd(floatvert_0, vertGran, zero));
        out[1] = rw::math::Vector3(vec_madd(floatvert_1, vertGran, zero));
        out[2] = rw::math::Vector3(vec_madd(floatvert_2, vertGran, zero));























    }
    else
    {
        out[0] = vertexArray[v0];
        out[1] = vertexArray[v1];
        out[2] = vertexArray[v2];
    }
    return;
}
inline void
ClusteredMeshCluster::Get4Vertices(rw::math::Vector3 *out, uint8_t v0, uint8_t v1, uint8_t v2, uint8_t v3, const float32_t &g)
{
    ;
    if (compressionMode == VERTICES_16BIT_COMPRESSED)
    {
        int32_t *offset = reinterpret_cast<int32_t*>(vertexArray);
        Vertex16 *vert = reinterpret_cast<Vertex16*>(vertexArray) + 2;

        ;
        __attribute__((altivec(vector__))) float zero = (__attribute__((altivec(vector__))) float)vec_splat_s32(0);
        __attribute__((altivec(vector__))) int vert_offset = vec_ld(0, offset);
        __attribute__((altivec(vector__))) float vertGran = (__attribute__((altivec(vector__))) float)vec_lvlx(0, &g);
                     vertGran = vec_splat(vertGran, 0);
        __attribute__((altivec(vector__))) int vert_0_l = (__attribute__((altivec(vector__))) int)vec_lvlx(0, &vert[v0].x);
        __attribute__((altivec(vector__))) int vert_1_l = (__attribute__((altivec(vector__))) int)vec_lvlx(0, &vert[v1].x);
        __attribute__((altivec(vector__))) int vert_2_l = (__attribute__((altivec(vector__))) int)vec_lvlx(0, &vert[v2].x);
        __attribute__((altivec(vector__))) int vert_3_l = (__attribute__((altivec(vector__))) int)vec_lvlx(0, &vert[v3].x);
        __attribute__((altivec(vector__))) int vert_0_r = (__attribute__((altivec(vector__))) int)vec_lvrx(16, &vert[v0].x);
        __attribute__((altivec(vector__))) int vert_1_r = (__attribute__((altivec(vector__))) int)vec_lvrx(16, &vert[v1].x);
        __attribute__((altivec(vector__))) int vert_2_r = (__attribute__((altivec(vector__))) int)vec_lvrx(16, &vert[v2].x);
        __attribute__((altivec(vector__))) int vert_3_r = (__attribute__((altivec(vector__))) int)vec_lvrx(16, &vert[v3].x);
        __attribute__((altivec(vector__))) int vert_0_i = vec_or(vert_0_l, vert_0_r);
        __attribute__((altivec(vector__))) int vert_1_i = vec_or(vert_1_l, vert_1_r);
        __attribute__((altivec(vector__))) int vert_2_i = vec_or(vert_2_l, vert_2_r);
        __attribute__((altivec(vector__))) int vert_3_i = vec_or(vert_3_l, vert_3_r);
                     vert_0_i = (__attribute__((altivec(vector__))) int)vec_mergeh((__attribute__((altivec(vector__))) short)zero, (__attribute__((altivec(vector__))) short)vert_0_i);
                     vert_1_i = (__attribute__((altivec(vector__))) int)vec_mergeh((__attribute__((altivec(vector__))) short)zero, (__attribute__((altivec(vector__))) short)vert_1_i);
                     vert_2_i = (__attribute__((altivec(vector__))) int)vec_mergeh((__attribute__((altivec(vector__))) short)zero, (__attribute__((altivec(vector__))) short)vert_2_i);
                     vert_3_i = (__attribute__((altivec(vector__))) int)vec_mergeh((__attribute__((altivec(vector__))) short)zero, (__attribute__((altivec(vector__))) short)vert_3_i);
                     vert_0_i = vec_add(vert_0_i, vert_offset);
                     vert_1_i = vec_add(vert_1_i, vert_offset);
                     vert_2_i = vec_add(vert_2_i, vert_offset);
                     vert_3_i = vec_add(vert_3_i, vert_offset);
        __attribute__((altivec(vector__))) float floatvert_0 = vec_ctf(vert_0_i, 0);
        __attribute__((altivec(vector__))) float floatvert_1 = vec_ctf(vert_1_i, 0);
        __attribute__((altivec(vector__))) float floatvert_2 = vec_ctf(vert_2_i, 0);
        __attribute__((altivec(vector__))) float floatvert_3 = vec_ctf(vert_3_i, 0);
        out[0] = rw::math::Vector3(vec_madd(floatvert_0, vertGran, zero));
        out[1] = rw::math::Vector3(vec_madd(floatvert_1, vertGran, zero));
        out[2] = rw::math::Vector3(vec_madd(floatvert_2, vertGran, zero));
        out[3] = rw::math::Vector3(vec_madd(floatvert_3, vertGran, zero));











































    }
    else if (compressionMode == VERTICES_32BIT_COMPRESSED)
    {
        Vertex32 *vert = reinterpret_cast<Vertex32*>(vertexArray);

        __attribute__((altivec(vector__))) float zero = (__attribute__((altivec(vector__))) float)vec_splat_s32(0);
        __attribute__((altivec(vector__))) float vertGran = (__attribute__((altivec(vector__))) float)vec_lvlx(0, &g);
                     vertGran = vec_splat(vertGran, 0);
        __attribute__((altivec(vector__))) int vert_0_l = (__attribute__((altivec(vector__))) int)vec_lvlx(0, &vert[v0].x);
        __attribute__((altivec(vector__))) int vert_1_l = (__attribute__((altivec(vector__))) int)vec_lvlx(0, &vert[v1].x);
        __attribute__((altivec(vector__))) int vert_2_l = (__attribute__((altivec(vector__))) int)vec_lvlx(0, &vert[v2].x);
        __attribute__((altivec(vector__))) int vert_3_l = (__attribute__((altivec(vector__))) int)vec_lvlx(0, &vert[v3].x);
        __attribute__((altivec(vector__))) int vert_0_r = (__attribute__((altivec(vector__))) int)vec_lvrx(16, &vert[v0].x);
        __attribute__((altivec(vector__))) int vert_1_r = (__attribute__((altivec(vector__))) int)vec_lvrx(16, &vert[v1].x);
        __attribute__((altivec(vector__))) int vert_2_r = (__attribute__((altivec(vector__))) int)vec_lvrx(16, &vert[v2].x);
        __attribute__((altivec(vector__))) int vert_3_r = (__attribute__((altivec(vector__))) int)vec_lvrx(16, &vert[v3].x);
        __attribute__((altivec(vector__))) int vert_0_i = vec_or(vert_0_l, vert_0_r);
        __attribute__((altivec(vector__))) int vert_1_i = vec_or(vert_1_l, vert_1_r);
        __attribute__((altivec(vector__))) int vert_2_i = vec_or(vert_2_l, vert_2_r);
        __attribute__((altivec(vector__))) int vert_3_i = vec_or(vert_3_l, vert_3_r);
        __attribute__((altivec(vector__))) float floatvert_0 = vec_ctf(vert_0_i, 0);
        __attribute__((altivec(vector__))) float floatvert_1 = vec_ctf(vert_1_i, 0);
        __attribute__((altivec(vector__))) float floatvert_2 = vec_ctf(vert_2_i, 0);
        __attribute__((altivec(vector__))) float floatvert_3 = vec_ctf(vert_3_i, 0);
        out[0] = rw::math::Vector3(vec_madd(floatvert_0, vertGran, zero));
        out[1] = rw::math::Vector3(vec_madd(floatvert_1, vertGran, zero));
        out[2] = rw::math::Vector3(vec_madd(floatvert_2, vertGran, zero));
        out[3] = rw::math::Vector3(vec_madd(floatvert_3, vertGran, zero));





























    }
    else
    {
        out[0] = vertexArray[v0];
        out[1] = vertexArray[v1];
        out[2] = vertexArray[v2];
        out[3] = vertexArray[v3];
    }
    return;
}
inline uint8_t *
ClusteredMeshCluster::UnitData()
{
    ;
    return reinterpret_cast<uint8_t*>(&vertexArray[unitDataStart]);
}
inline rw::math::Vector3 *
ClusteredMeshCluster::NormalArray()
{
    ;
    return vertexArray + normalStart;
}
class ClusteredMesh : public Procedural
{
private:
    ClusteredMesh();
public:
    static rw::ResourceDescriptor
    GetResourceDescriptor(uint32_t maxClusters,
                          uint32_t clusterDataSize,
                          uint32_t numBranchNodes,
                          uint32_t maxUnits,
                          const rw::collision::AABBox &bbox,
                          float32_t vertexCompressionGranularity = 0.01f,
                          uint32_t classSize = sizeof(ClusteredMesh));
    static ClusteredMesh *
    Initialize(const rw::Resource& resource,
               uint32_t maxClusters,
               uint32_t clusterDataSize,
               uint32_t numBranchNodes,
               uint32_t maxUnits,
               const rw::collision::AABBox &bbox,
               float32_t vertexCompressionGranularity = 0.01f,
               uint32_t classSize = sizeof(ClusteredMesh));
    void
    Release();
    ClusteredMeshCluster *
    AllocateNextCluster(uint32_t sizeInBytes, uint32_t numUnits);
    KDTree *
    GetKDTree() const;
    uint32_t
    GetNumCluster() const;
    uint32_t
    GetMaxCluster() const;
    ClusteredMeshCluster &
    GetCluster(uint32_t index) const;
    uint32_t
    GetNumUnits() const;
    uint32_t
    GetNumUnitInCluster(uint32_t clusterId) const;
    uint32_t
    GetMaxUnits() const;
    uint32_t
    GetUnitVolumes(uint32_t index, uint32_t offset, Volume *triList, uint32_t &triCount) const;
    uint32_t
    UnitGetOverlappingGPInstances(uint32_t index, uint32_t offset, const AABBox &bbox, const rw::math::Matrix44Affine *transform,
                                    GPTriangle *instances, uint32_t &numPrimitivesInUnit) const;
    uint16_t
    GetDefaultGroupId() const;
    void
    SetDefaultGroupId(uint16_t defaultGroupId);
    uint16_t
    GetDefaultSurfaceId() const;
    void
    SetDefaultSurfaceId(uint16_t defaultSurfaceId);
    uint8_t
    GetDefaultEdgeAngle() const;
    void
    SetDefaultEdgeAngle(uint8_t defaultEdgeAngle);
    uint8_t
    GetGroupIdSize() const;
    void
    SetGroupIdSize(uint8_t GroupId);
    uint8_t
    GetSurfaceIdSize() const;
    void
    SetSurfaceIdSize(uint8_t SurfaceId);
    RwBool
    IsOneSided() const;
    void
    SetOneSided(RwBool onesided);
    const float32_t &
    GetVertexCompressionGranularity() const;
    RwBool
    IsValid();
    uint32_t
    GetSizeThis();
    void
    UpdateThis();
    RwBool
    LineIntersectionQueryThis(VolumeLineQuery *lineQuery,
                              const rw::math::Matrix44Affine *tm);
    RwBool
    BBoxOverlapQueryThis(VolumeBBoxQuery *bboxQuery,
                         const rw::math::Matrix44Affine *tm);
    static rw::core::arena::SizeAndAlignment *
    Unfix(void *ptr, rw::core::arena::SizeAndAlignment *offset);
    static void
    Refix(void *ptr, void *offset, rw::core::arena::ArenaIterator *iterator);
    static RwBool
    Fixup(void *ptr, rw::core::arena::ArenaIterator *iterator);
    static void
    RegisterArenaReadCallbacks();
    static void
    RegisterArenaWriteCallbacks();
private:
    void
    CommonFixupCode(void *base);
    rw::math::Vector3
    GetVertex(uint32_t index, uint8_t vertid) const;
    uint32_t
    GetUnitType(uint32_t index, uint32_t offset) const;
    AABBox
    GetUnitBBox(uint32_t index, uint32_t offset) const;
    uint32_t
    GetUnitSize(uint32_t index, uint32_t offset) const;
    uint32_t
    NumVolumesInUnit(uint32_t index, uint32_t offset) const;
    uint32_t
    GetUnitVolume(uint32_t index, uint32_t offset, uint32_t subindex, Volume *vol) const;
protected:
    KDTree* mKDTree;
    uint32_t* mCluster;
    uint32_t mNumClusters;
    uint32_t mMaxClusters;
    uint32_t mNumUnits;
    uint32_t mMaxUnits;
    float32_t mVertexCompressionGranularity;
    uint32_t mSizeOfThis;
    uint16_t mFlags;
    uint16_t mDefaultGroupId;
    uint16_t mDefaultSurfaceId;
    uint8_t mDefaultEdgeAngle;
    uint8_t mGroupIdSize;
    uint8_t mSurfaceIdSize;
};
inline KDTree *
ClusteredMesh::GetKDTree() const
{
    ;
    return mKDTree;
}
inline uint32_t
ClusteredMesh::GetNumCluster() const
{
    ;
    return mNumClusters;
}
inline uint32_t
ClusteredMesh::GetMaxCluster() const
{
    ;
    return mMaxClusters;
}
inline ClusteredMeshCluster &
ClusteredMesh::GetCluster(uint32_t index) const
{
    ;
    ;
    return *reinterpret_cast<ClusteredMeshCluster *>( reinterpret_cast<rw::HostPtr>(this) + mCluster[index]);

}
inline uint32_t
ClusteredMesh::GetNumUnits() const
{
    ;
    return mNumUnits;
}
inline uint32_t
ClusteredMesh::GetMaxUnits() const
{
    ;
    return mMaxUnits;
}
inline uint16_t
ClusteredMesh::GetDefaultGroupId() const
{
    ;
    return mDefaultGroupId;
}
inline void
ClusteredMesh::SetDefaultGroupId(uint16_t defaultGroupId)
{
    ;
    mDefaultGroupId = defaultGroupId;
    return;
}
inline uint16_t
ClusteredMesh::GetDefaultSurfaceId() const
{
    ;
    return mDefaultSurfaceId;
}
inline void
ClusteredMesh::SetDefaultSurfaceId(uint16_t defaultSurfaceId)
{
    ;
    mDefaultSurfaceId = defaultSurfaceId;
    return;
}
inline uint8_t
ClusteredMesh::GetDefaultEdgeAngle() const
{
    ;
    return mDefaultEdgeAngle;
}
inline void
ClusteredMesh::SetDefaultEdgeAngle(uint8_t defaultEdgeAngle)
{
    ;
    mDefaultEdgeAngle = defaultEdgeAngle;
    return;
}
inline uint8_t
ClusteredMesh::GetGroupIdSize() const
{
    ;
    return mGroupIdSize;
}
inline void
ClusteredMesh::SetGroupIdSize(uint8_t groupIdSize)
{
    ;
    mGroupIdSize = groupIdSize;
    return;
}
inline uint8_t
ClusteredMesh::GetSurfaceIdSize() const
{
    ;
    return mSurfaceIdSize;
}
inline void
ClusteredMesh::SetSurfaceIdSize(uint8_t surfaceIdSize)
{
    ;
    mSurfaceIdSize = surfaceIdSize;
    return;
}
inline RwBool
ClusteredMesh::IsOneSided() const
{
    ;
    return (mFlags & CMFLAG_ONESIDED)!=0;
}
inline const float32_t &
ClusteredMesh::GetVertexCompressionGranularity() const
{
    ;
    return mVertexCompressionGranularity;
}
inline void
ClusteredMesh::SetOneSided(RwBool onesided)
{
    ;
    if (onesided)
    {
        mFlags |= CMFLAG_ONESIDED;
    }
    else
    {
        mFlags &= ~CMFLAG_ONESIDED;
    }
    return;
}
inline void
ClusteredMesh::RegisterArenaReadCallbacks()
{
    ;
    rw::core::arena::ArenaTypeReg *typeReg =
        rw::core::arena::ArenaTypeRegGetType(RWCOBJECTTYPE_CLUSTEREDMESH);
    typeReg->fixupCB = Fixup;
    return;
}
inline void
ClusteredMesh::RegisterArenaWriteCallbacks()
{
    ;
    rw::core::arena::ArenaTypeReg *typeReg =
        rw::core::arena::ArenaTypeRegGetType(RWCOBJECTTYPE_CLUSTEREDMESH);
    typeReg->unfixCB = Unfix;
    typeReg->refixCB = Refix;
    return;
}
inline void
ClusteredMesh::Release()
{
    ;
    mNumClusters = 0;
    return;
}
class ClusteredMeshUnit
{
public:
    ClusteredMeshUnit(ClusteredMesh *cm, uint32_t clusterId);
    bool AtEnd() const;
    void Next();
    bool IsValid() const;
    uint32_t GetType() const;
    uint8_t GetTypeAndFlags() const;
    uint32_t GetTriangleCount() const;
    uint32_t GetSize() const;
    uint32_t GetSurfaceId() const;
    void SetSurfaceId(uint32_t id) const;
    uint32_t GetGroupId() const;
    void SetGroupId(uint32_t id) const;
    uint32_t GetVertexCount() const;
    uint8_t GetVertexId(uint32_t i) const;
    void SetVertexId(uint32_t i, uint8_t newId) const;
    rw::math::Vector3 GetVertex(uint32_t i) const;
    uint32_t GetEdgeCount() const;
    uint8_t GetEdgeData(uint32_t i) const;
    void SetEdgeData(uint32_t i, uint8_t newec) const;
protected:
    uint32_t GetMemberOffset(uint32_t flag) const;
    ClusteredMesh *mClusteredMesh;
    ClusteredMeshCluster *mCluster;
    uint8_t *mUnitData;
};
inline
ClusteredMeshUnit::ClusteredMeshUnit(ClusteredMesh *cm, uint32_t clusterId)
{
    ;
    mClusteredMesh = cm;
    mCluster = &cm->GetCluster(clusterId);
    mUnitData = mCluster->UnitData();
    return;
}
inline bool
ClusteredMeshUnit::AtEnd() const
{
    ;
    return mUnitData >= mCluster->UnitData() + mCluster->unitDataSize;
}
inline void
ClusteredMeshUnit::Next()
{
    ;
    mUnitData += GetMemberOffset(0);
    return;
}















inline uint32_t
ClusteredMeshUnit::GetMemberOffset(uint32_t flag) const
{
    ;
    uint32_t i = 1;
    uint32_t triangleCount = 1;
    if (GetType() == UNITTYPE_QUAD)
    {
        triangleCount = 2;
    }
    else if (GetType() == UNITTYPE_TRILIST)
    {
        triangleCount = mUnitData[i++];
    }
    if (flag == 1)
    {
        return i;
    }
    i += triangleCount + 2;
    if (flag == UNITFLAG_NORMAL)
    {
        return i;
    }
    if (mUnitData[0] & UNITFLAG_NORMAL)
    {
        ++i;
    }
    if (flag == UNITFLAG_EDGEANGLE)
    {
        return i;
    }
    if (mUnitData[0] & UNITFLAG_EDGEANGLE)
    {
        i += triangleCount + 2;
    }
    if (flag == UNITFLAG_GROUPID)
    {
        return i;
    }
    if (mUnitData[0] & UNITFLAG_GROUPID)
    {
        i += mClusteredMesh->GetGroupIdSize();
    }
    if (flag == UNITFLAG_SURFACEID)
    {
        return i;
    }
    if (mUnitData[0] & UNITFLAG_SURFACEID)
    {
        i += mClusteredMesh->GetSurfaceIdSize();
    }
    return i;
}
inline uint32_t
ClusteredMeshUnit::GetType() const
{
    ;
    return GetTypeAndFlags() & UNITTYPE_MASK;
}
inline uint8_t
ClusteredMeshUnit::GetTypeAndFlags() const
{
    ;
    ;
    return mUnitData[0];
}
inline uint32_t
ClusteredMeshUnit::GetTriangleCount() const
{
    ;
    ;
    switch (GetType())
    {
    case UNITTYPE_QUAD: return 2;
    case UNITTYPE_TRILIST: return mUnitData[1];
    }
    return 1;
}
inline uint32_t
ClusteredMeshUnit::GetVertexCount() const
{
    ;
    return GetTriangleCount() + 2;
}
inline uint32_t
ClusteredMeshUnit::GetEdgeCount() const
{
    ;
    return GetTriangleCount() + 2;
}
inline uint32_t
ClusteredMeshUnit::GetSurfaceId() const
{
    ;
    ;
    uint32_t i = GetMemberOffset(UNITFLAG_SURFACEID);
    uint32_t id = mUnitData[i];
    if (mClusteredMesh->GetSurfaceIdSize() == 2)
    {
        id += 256 * mUnitData[i + 1];
    }
    return id;
}
inline void
ClusteredMeshUnit::SetSurfaceId(uint32_t id) const
{
    ;
    ;
    uint32_t i = GetMemberOffset(UNITFLAG_SURFACEID);
    mUnitData[i] = static_cast<uint8_t>(id & 255);
    if (mClusteredMesh->GetSurfaceIdSize() == 2)
    {
        mUnitData[i + 1] = static_cast<uint8_t>((id >> 8) & 255);
    }
    return;
}
inline uint32_t
ClusteredMeshUnit::GetGroupId() const
{
    ;
    ;
    uint32_t i = GetMemberOffset(UNITFLAG_GROUPID);
    uint32_t id = mUnitData[i];
    if (mClusteredMesh->GetGroupIdSize() == 2)
    {
        id += 256 * mUnitData[i + 1];
    }
    return id;
}
inline void
ClusteredMeshUnit::SetGroupId(uint32_t id) const
{
    ;
    ;
    uint32_t i = GetMemberOffset(UNITFLAG_GROUPID);
    mUnitData[i] = static_cast<uint8_t>(id & 255);
    if (mClusteredMesh->GetGroupIdSize() == 2)
    {
        mUnitData[i + 1] = static_cast<uint8_t>((id >> 8) & 255);
    }
    return;
}
inline uint8_t
ClusteredMeshUnit::GetVertexId(uint32_t i) const
{
    ;
    ;
    i += GetMemberOffset(1);
    return mUnitData[i];
}
inline rw::math::Vector3
ClusteredMeshUnit::GetVertex(uint32_t i) const
{
    ;
    ;
    i += GetMemberOffset(1);
    return mCluster->GetVertex(mUnitData[i], mClusteredMesh->GetVertexCompressionGranularity());
}
inline void
ClusteredMeshUnit::SetVertexId(uint32_t i, uint8_t newId) const
{
    ;
    ;
    i += GetMemberOffset(1);
    mUnitData[i] = newId;
    return;
}
inline uint8_t
ClusteredMeshUnit::GetEdgeData(uint32_t i) const
{
    ;
    ;
    ;
    i += GetMemberOffset(UNITFLAG_EDGEANGLE);
    return mUnitData[i];
}
inline void
ClusteredMeshUnit::SetEdgeData(uint32_t i, uint8_t newval) const
{
    ;
    ;
    ;
    i += GetMemberOffset(UNITFLAG_EDGEANGLE);
    mUnitData[i] = newval;
    return;
}
}
}






namespace rw
{
namespace collision
{
    bool InitializeArenaReadCallbacks();
    bool InitializeArenaWriteCallbacks();
    bool InitializeVTables();
}
}
