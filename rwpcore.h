








       




















































namespace rw
{
namespace physics
{



template <typename PhysicsObject>
union AddrPtrUnion
{
    GlobalAddress addr;
    PhysicsObject *ptr;
    PhysicsObject* operator =(PhysicsObject*_ptr) { ptr = _ptr; return ptr; };
    bool operator ==(const AddrPtrUnion &apu){ return apu.ptr == ptr; };
    PhysicsObject* operator ->() const { return ptr; };
                   operator PhysicsObject*() const { return ptr; };
                   operator intptr_t() const { return (intptr_t)ptr; };
    PhysicsObject* operator ++() { return ++ptr; };
    PhysicsObject* operator ++(int ) { return ptr++; };
};
class ContactJacobian;
class ContactSpy;
class JointJacobian;
class JointSpy;
class DriveJacobian;
class DriveSpy;
union AddrVoidPtrUnion
{
    GlobalAddress addr;
    void *ptr;
    void* operator =(void*_ptr) { ptr = _ptr; return ptr; };
    bool operator ==(const AddrVoidPtrUnion &apu){ return apu.ptr == ptr; };
    void* operator ->() const { return ptr; };
          operator void*() const { return (void*)ptr; };
          operator __attribute__((altivec(vector__))) float*() const { return (__attribute__((altivec(vector__))) float*)ptr; };
          operator ContactJacobian*() const { return (ContactJacobian*)ptr; };
          operator ContactSpy*() const { return (ContactSpy*)ptr; };
          operator JointJacobian*() const { return (JointJacobian*)ptr; };
          operator JointSpy*() const { return (JointSpy*)ptr; };
          operator DriveJacobian*() const { return (DriveJacobian*)ptr; };
          operator DriveSpy*() const { return (DriveSpy*)ptr; };
          operator rw::HostPtr() const { return (rw::HostPtr)ptr; };
};
union vector_union
{
    uint32_t u[4];
    int32_t i[4];
    float32_t f[4];
    __attribute__((altivec(vector__))) unsigned int vecu;
    __attribute__((altivec(vector__))) float vecf;
};
static const __attribute__((altivec(vector__))) unsigned int Select_1000 = {0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000};
static const __attribute__((altivec(vector__))) unsigned int Select_1110 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000};
static const __attribute__((altivec(vector__))) unsigned int Swizzle_YZXW = {0x04050607, 0x08090A0B, 0x00010203, 0x0C0D0E0F};
static const __attribute__((altivec(vector__))) unsigned int Swizzle_ZXYW = {0x08090A0B, 0x00010203, 0x04050607, 0x0C0D0E0F};
static const __attribute__((altivec(vector__))) unsigned int Swizzle_XYZX = {0x00010203, 0x04050607, 0x08090A0B, 0x00010203};
static const __attribute__((altivec(vector__))) unsigned int Swizzle_Z0Z1X1W0 = {0x08090A0B, 0x18191A1B, 0x10111213, 0x0C0D0E0F};
static const __attribute__((altivec(vector__))) unsigned int Swizzle_Y0Y1Z1W0 = {0x04050607, 0x14151617, 0x18191A1B, 0x0C0D0E0F};
static const __attribute__((altivec(vector__))) unsigned int Swizzle_Z0W0Y1X1 = {0x08090A0B, 0x0C0D0E0F, 0x14151617, 0x10111213};
static const __attribute__((altivec(vector__))) unsigned int Swizzle_X0Y0Z1X1 = {0x00010203, 0x04050607, 0x18191A1B, 0x10111213};
static const __attribute__((altivec(vector__))) unsigned int Permute_0X0Y1X1Y = {0x00010203, 0x04050607, 0x10111213, 0x14151617};
static const __attribute__((altivec(vector__))) unsigned int Combine_X0X0X0X1 = {0x00010203, 0x00010203, 0x00010203, 0x10111213};
static const __attribute__((altivec(vector__))) unsigned int Combine_Y0Y0Y0Y1 = {0x04050607, 0x04050607, 0x04050607, 0x14151617};
static const __attribute__((altivec(vector__))) unsigned int Combine_Z0Z0Z0Z1 = {0x08090A0B, 0x08090A0B, 0x08090A0B, 0x18191A1B};
static const __attribute__((altivec(vector__))) unsigned int Combine_X1X0X0X1 = {0x10111213, 0x00010203, 0x00010203, 0x10111213};
static const __attribute__((altivec(vector__))) unsigned int Combine_X0Y0Z0X1 = {0x00010203, 0x04050607, 0x08090A0B, 0x10111213};
static const __attribute__((altivec(vector__))) unsigned int Combine_X0Y0Z0Y1 = {0x00010203, 0x04050607, 0x08090A0B, 0x14151617};
static const __attribute__((altivec(vector__))) unsigned int Combine_X0Y0Z0Z1 = {0x00010203, 0x04050607, 0x08090A0B, 0x18191A1B};
static const __attribute__((altivec(vector__))) unsigned int Transpo_Z0W0W1W1 = {0x08090A0B, 0x0C0D0E0F, 0x1C1D1E1F, 0x1C1D1E1F};
static const __attribute__((altivec(vector__))) float Identity_R0 = { 1.0f, 0.0f, 0.0f, 0.0f};
static const __attribute__((altivec(vector__))) float Identity_R1 = { 0.0f, 1.0f, 0.0f, 0.0f};
static const __attribute__((altivec(vector__))) float Identity_R2 = { 0.0f, 0.0f, 1.0f, 0.0f};
static const __attribute__((altivec(vector__))) float Identity_R3 = { 0.0f, 0.0f, 0.0f, 1.0f};
static const __attribute__((altivec(vector__))) unsigned int NegativeZero = { 0x80000000, 0x80000000, 0x80000000, 0x80000000};
static const __attribute__((altivec(vector__))) unsigned int Friction_Filters = { 0x7F7FFFFF, 0x00000000, 0x00000000, 0x7F7FFFFF};
static const __attribute__((altivec(vector__))) float Tolerance_Normal = { 1e-4f, 1e-4f, 1e-4f, 1e-4f};
static const __attribute__((altivec(vector__))) float OneHalf = { 0.5f, 0.5f, 0.5f, 0.5f};
}
}










namespace rw
{
namespace physics
{
class Inertia
{
public:
    Inertia()
        : m_invt(1.0f, 1.0f, 1.0f), m_invm(1.0f),
            m_spherical(1.0f),
            m_dsp_max(rw::math::MAX_FLOAT),
            m_omg_max(1.0f),
            m_lin_drag(0.0f),
            m_ang_drag(0.0f) {};
    ~Inertia() {};
    inline static rw::ResourceDescriptor GetResourceDescriptor();
    inline void EndianSwap();
    inline rw::math::Vector3 GetInverseInertia(void) const;
    inline const float32_t &GetSphericalInertia(void) const;
    inline const float32_t &GetInverseMass(void) const;
    inline const float32_t &GetMaxLinearDisplacement(void) const;
    inline const float32_t &GetMaxAngularDisplacement(void) const;
    inline const float32_t &GetLinearDrag(void) const;
    inline const float32_t &GetAngularDrag(void) const;
    inline void SetInverseInertia(const rw::math::Vector3 &it);
    inline void SetInverseMass(const float32_t invm);
    inline void SetMaxLinearDisplacement(const float32_t ldsp);
    inline void SetMaxAngularDisplacement(const float32_t adsp);
    inline void SetLinearDrag(const float32_t ld);
    inline void SetAngularDrag(const float32_t ad);
private:
    rw::math::Vector3 m_invt;
    float32_t m_invm;
    float32_t m_spherical;
    float32_t m_dsp_max;
    float32_t m_omg_max;
    float32_t m_lin_drag;
    float32_t m_ang_drag;
} __attribute__ ((__aligned__ (16)));



typedef Inertia* InertiaPtr;

inline rw::ResourceDescriptor
Inertia::GetResourceDescriptor()
{
    ;
    uint32_t size = (((sizeof(Inertia)) + ((16) - 1)) & ~((16) - 1));
    return rw::ResourceDescriptor(size, 16);
}
inline void
Inertia::EndianSwap()
{
    ;
    rw::EndianSwapArray(reinterpret_cast<float32_t *>(&m_invt), sizeof(m_invt) / sizeof(float32_t));
    rw::EndianSwap(m_spherical);
    rw::EndianSwap(m_invm);
    rw::EndianSwap(m_dsp_max);
    rw::EndianSwap(m_omg_max);
    rw::EndianSwap(m_lin_drag);
    rw::EndianSwap(m_ang_drag);
    return;
}
inline rw::math::Vector3
Inertia::GetInverseInertia(void) const
{
    ;
    return m_invt;
}
inline const float32_t &
Inertia::GetSphericalInertia(void) const
{
    ;
    return m_spherical;
}
inline const float32_t &
Inertia::GetInverseMass(void) const
{
    ;
    return m_invm;
}
inline const float32_t &
Inertia::GetMaxLinearDisplacement(void) const
{
    ;
    return m_dsp_max;
}
inline const float32_t &
Inertia::GetMaxAngularDisplacement(void) const
{
    ;
    return m_omg_max;
}
inline const float32_t &
Inertia::GetLinearDrag(void) const
{
    ;
    return m_lin_drag;
}
inline const float32_t &
Inertia::GetAngularDrag(void) const
{
    ;
    return m_ang_drag;
}
inline void
Inertia::SetInverseInertia(const rw::math::Vector3 &it)
{
    ;
    ;

    m_invt = it;
    m_spherical = static_cast<float>(it.X()) < static_cast<float>(it.Y()) ? static_cast<float>(it.X()) : static_cast<float>(it.Y());
    m_spherical = m_spherical < static_cast<float>(it.Z()) ? m_spherical : (float32_t)it.Z();
    m_spherical = 1.0f / m_spherical;
    return;
}
inline void
Inertia::SetInverseMass(const float32_t invm)
{
    ;
    ;
    m_invm = invm;
    return;
}
inline void
Inertia::SetMaxLinearDisplacement(const float32_t ldsp)
{
    ;
    ;
    m_dsp_max = ldsp;
    return;
}
inline void
Inertia::SetMaxAngularDisplacement(const float32_t adsp)
{
    ;
    ;
    m_omg_max = adsp;
    return;
}
inline void
Inertia::SetLinearDrag(const float32_t ld)
{
    ;
    ;
    ;
    m_lin_drag = ld;
    return;
}
inline void
Inertia::SetAngularDrag(const float32_t ad)
{
    ;
    ;
    ;
    m_ang_drag = ad;
    return;
}
}
}







namespace rw
{
namespace physics
{
class Simulation;



typedef Simulation* SimulationPtr;

enum BodyState
{
    FREE_BODY = 0x0,
    STATIC_BODY = 0x1,
    FROZEN_BODY = 0x2,
    ACTIVE_BODY = 0x4,
    STATE_FILTER = 0x7,
    SPY_BODY = 0x8,
    BS_FORCE_ENUM_SIZE = ((int32_t)((~((uint32_t)0))>>1))
};
enum InputSpace
{
    WORLD_SPACE = 0x0,
    BODY_SPACE = 0x1,
    IS_FORCE_ENUM_SIZE = ((int32_t)((~((uint32_t)0))>>1))
};
class RigidBody
{
friend class Simulation;
friend class SimulationProxy;
public:
    RigidBody() {};
    ~RigidBody() {};
    inline static rw::ResourceDescriptor GetResourceDescriptor();
    inline static RigidBody *AddressFromOffset(Simulation *stasis, const int32_t off);
    inline int32_t OffsetFromAddress(void) const;
    inline void InertiaUpdate(void);
    inline float32_t GetInverseMass(void) const;
    inline rw::math::Matrix33 GetWorldSpaceInverseInertia(void) const;
    inline rw::math::Vector3 GetPosition(void) const;
    inline rw::math::Vector3 GetDisplacement(void) const;
    inline rw::math::Vector3 GetVelocity(void) const;
    inline rw::math::Vector3 GetAngularDisplacement(void) const;
    inline rw::math::Vector3 GetAngularVelocity(void) const;
    inline rw::math::Quaternion GetQuaternion(void) const;
    inline rw::math::Matrix33 GetOrientation(void) const;
    inline rw::math::QuatPos GetQuatPos(void) const;
    inline rw::math::Matrix44Affine GetTransform(void) const;
    inline rw::math::Vector3 GetLocalDisplacement(const rw::math::Vector3 &p) const;
    inline rw::math::Vector3 GetLocalVelocity(const rw::math::Vector3 &p) const;
    inline rw::math::Vector3 GetForceDisplacement(void) const;
    inline rw::math::Vector3 GetTorqueDisplacement(void) const;
    inline rw::math::Vector3 GetLocalForceDisplacement(const rw::math::Vector3 &p) const;
    inline Inertia *GetInertia(void) const;
    inline float32_t GetKineticEnergy(void) const;
    inline uint32_t GetCoolDown(void) const;
    inline uint32_t GetTag(void) const;
    inline BodyState GetState(void) const;
    inline void SetPosition(const rw::math::Vector3 &p);
    inline void SetDisplacement(const rw::math::Vector3 &d);
    inline void SetVelocity(const rw::math::Vector3 &v);
    inline void SetAngularDisplacement(const rw::math::Vector3 &v);
    inline void SetAngularVelocity(const rw::math::Vector3 &v);
    inline void SetTransform(const rw::math::Matrix44Affine &m);
    inline void SetTransform(const rw::math::QuatPos &q);
    inline void SetInertia(Inertia *ine);
    inline void SetCoolDown(const uint32_t cd);
    inline void SetTag(const uint32_t tag);
    inline void SetSpy(const RwBool on_off);
    inline void ResetForces(void);
    inline void AddDisplacement(const rw::math::Vector3 &ld, const InputSpace spc);
    inline void AddImpulse(const rw::math::Vector3 &li, const InputSpace spc);
    inline void AddForce(const rw::math::Vector3 &lf, const InputSpace spc);
    inline void AddAngularDisplacement(const rw::math::Vector3 &ad, const InputSpace spc);
    inline void AddAngularImpulse(const rw::math::Vector3 &ai, const InputSpace spc);
    inline void AddTorque(const rw::math::Vector3 &af, const InputSpace spc);
    inline void AddLocalDisplacement(const rw::math::Vector3 &ld, const InputSpace dspc,
                                     const rw::math::Vector3 &pos, const InputSpace pspc);
    inline void AddLocalImpulse(const rw::math::Vector3 &li, const InputSpace dspc,
                                const rw::math::Vector3 &pos, const InputSpace pspc);
    inline void AddLocalForce(const rw::math::Vector3 &lf, const InputSpace dspc,
                              const rw::math::Vector3 &pos, const InputSpace pspc);
    inline Simulation *GetSimulation(void) const;
    inline RigidBody *GetRight(void) const;
    inline RigidBody *GetLeft(void) const;
    inline uint32_t GetReactionForcesId(void) const;
 inline void SetRight(RigidBody *ri);
 inline void SetLeft(RigidBody *le);
private:
    inline void SetSimulation(Simulation *stasis);
    inline void Move(RigidBody *src);
    inline void SetStatic(const rw::math::Matrix44Affine &m);
    inline void SetDynamic(const rw::math::Matrix44Affine &m, Inertia *ine);
    inline void SetState(const BodyState state);
    inline void SetReactionForcesId(const uint32_t id);
    void DynamicUpdate(void);

    inline void InertiaUpdate(Inertia *inertia);
    inline void ResetForces(rw::math::Vector3 &dsp_grav);
    void DynamicUpdate(Inertia *inertia, void *reactionForces, float32_t FreezingEnergy, uint32_t coolDown, rw::math::Vector3 &dsp_grav);
    inline void InertiaDynamicUpdate(Inertia *inertia);



private:

    rw::math::Quaternion m_qt;
    rw::math::fpu::Vector3U_32 m_com;
    uint32_t m_Id;
    rw::math::fpu::Vector3U_32 m_dsp;
    int32_t m_right;
    rw::math::fpu::Vector3U_32 m_omega;
    int32_t m_left;
    rw::math::fpu::Vector3U_32 m_ri;
    uint32_t m_pad0;
    rw::math::fpu::Vector3U_32 m_up;
    uint32_t m_pad1;
    rw::math::fpu::Vector3U_32 m_at;
    uint32_t m_tag;
    rw::math::fpu::Vector3U_32 m_Ifull;
    float32_t m_invm;
    rw::math::fpu::Vector3U_32 m_Isplt;
    BodyState m_state;
    rw::math::fpu::Vector3U_32 m_force;
    float32_t m_kine;
    rw::math::fpu::Vector3U_32 m_torque;
    uint32_t m_cool;
    SimulationPtr m_stasis;
    InertiaPtr m_inertia;























} __attribute__ ((__aligned__ (16)));



typedef RigidBody* RigidBodyPtr;

}
}







namespace rw
{
namespace physics
{
class JointFrames
{
public:
    JointFrames() {};
    ~JointFrames() {};
    inline static rw::ResourceDescriptor GetResourceDescriptor();
    inline void EndianSwap(void);
    inline rw::math::Vector3 GetChildPosition(void) const;
    inline rw::math::Vector3 GetParentPosition(void) const;
    inline rw::math::Quaternion GetChildAngularFrame(void) const;
    inline rw::math::Quaternion GetParentAngularFrame(void) const;
    inline rw::math::Quaternion GetParentLinearFrame(void) const;
    inline void SetChildPosition(const rw::math::Vector3 &p);
    inline void SetParentPosition(const rw::math::Vector3 &p);
    inline void SetChildAngularFrame(const rw::math::Matrix33 &m);
    inline void SetChildAngularFrame(const rw::math::Quaternion &q);
    inline void SetParentAngularFrame(const rw::math::Matrix33 &m);
    inline void SetParentAngularFrame(const rw::math::Quaternion &q);
    inline void SetParentLinearFrame(const rw::math::Matrix33 &m);
    inline void SetParentLinearFrame(const rw::math::Quaternion &q);
private:
    rw::math::Quaternion m_qA;
    rw::math::Vector3 m_posA;
    rw::math::Quaternion m_qB;
    rw::math::Vector3 m_posB;
    rw::math::Quaternion m_qL;
} __attribute__ ((__aligned__ (16)));



typedef JointFrames* JointFramesPtr;

inline rw::ResourceDescriptor
JointFrames::GetResourceDescriptor()
{
    ;
    uint32_t size = (((sizeof(JointFrames)) + ((16) - 1)) & ~((16) - 1));
    return rw::ResourceDescriptor(size, 16);
}
inline void
JointFrames::EndianSwap(void)
{
    ;
    ;
    return;
}
inline rw::math::Vector3
JointFrames::GetChildPosition(void) const
{
    ;
    return m_posA;
}
inline rw::math::Vector3
JointFrames::GetParentPosition(void) const
{
    ;
    return m_posB;
}
inline rw::math::Quaternion
JointFrames::GetChildAngularFrame(void) const
{
    ;
    return m_qA;
}
inline rw::math::Quaternion
JointFrames::GetParentAngularFrame(void) const
{
    ;
    return m_qB;
}
inline rw::math::Quaternion
JointFrames::GetParentLinearFrame(void) const
{
    ;
    return m_qL;
}
inline void
JointFrames::SetChildPosition(const rw::math::Vector3 &p)
{
    ;
    m_posA = p;
    return;
}
inline void
JointFrames::SetParentPosition(const rw::math::Vector3 &p)
{
    ;
    m_posB = p;
    return;
}
inline void
JointFrames::SetChildAngularFrame(const rw::math::Matrix33 &m)
{
    ;
    m_qA = QuaternionFromMatrix44Affine(rw::math::Matrix44Affine(m.Right(), m.Up(), m.At(), rw::math::GetVector3_Zero()));
    return;
}
inline void
JointFrames::SetChildAngularFrame(const rw::math::Quaternion &q)
{
    ;
    m_qA = q;
    return;
}
inline void
JointFrames::SetParentAngularFrame(const rw::math::Matrix33 &m)
{
    ;
    m_qB = QuaternionFromMatrix44Affine(rw::math::Matrix44Affine(m.Right(), m.Up(), m.At(), rw::math::GetVector3_Zero()));
    return;
}
inline void
JointFrames::SetParentAngularFrame(const rw::math::Quaternion &q)
{
    ;
    m_qB = q;
    return;
}
inline void
JointFrames::SetParentLinearFrame(const rw::math::Matrix33 &m)
{
    ;
    m_qL = QuaternionFromMatrix44Affine(rw::math::Matrix44Affine(m.Right(), m.Up(), m.At(), rw::math::GetVector3_Zero()));
    return;
}
inline void
JointFrames::SetParentLinearFrame(const rw::math::Quaternion &q)
{
    ;
    m_qL = q;
    return;
}
}
}








namespace rw
{
namespace physics
{
enum SwingType
{
    SWING_LOCKED = 0,
    SWING_CONE = 1,
    SWING_HINGE = 2,
    SWING_AXLE = 3,
    SWING_FREE = 4,
    SWING_FORCE_ENUM_SIZE = ((int32_t)((~((uint32_t)0))>>1))
};
enum TwistType
{
    TWIST_LOCKED = 0,
    TWIST_ARC = 1,
    TWIST_FREE = 2,
    TWIST_FORCE_ENUM_SIZE = ((int32_t)((~((uint32_t)0))>>1))
};
class JointLimits
{
public:
    inline JointLimits();
    ~JointLimits() {};
    inline static rw::ResourceDescriptor GetResourceDescriptor();
    inline void EndianSwap(void);
    inline rw::math::Vector3 GetPositionLimit(void) const;
    inline rw::math::Vector3 GetDisplacementLimit(void) const;
    inline SwingType GetSwingType(void) const;
    inline TwistType GetTwistType(void) const;
    inline float32_t GetSwingAngle(void) const;
    inline float32_t GetTwistAngle(void) const;
    inline float32_t GetSwingLimit(void) const;
    inline float32_t GetTwistLimit(void) const;
    inline rw::math::Vector3 GetAngularDisplacementLimit(void) const;
    inline void SetSwingType(const SwingType s);
    inline void SetTwistType(const TwistType t);
    inline void SetSwingAngle(const float32_t sa);
    inline void SetTwistAngle(const float32_t ta);
    inline void SetPositionLimit(const rw::math::Vector3 &p);
    inline void SetDisplacementLimit(const rw::math::Vector3 &d);
    inline void SetTwistDisplacementLimit(const float32_t tl);
    inline void SetSwingDisplacementLimit(const float32_t sl);
private:
    rw::math::Vector3 m_pprism;
    rw::math::Vector3 m_vprism;
    float32_t m_vtwist;
    float32_t m_vswing;
    float32_t m_swinga;
    float32_t m_twista;
    float32_t m_swingc;
    float32_t m_twistc;
    SwingType m_swingf;
    TwistType m_twistf;
} __attribute__ ((__aligned__ (16)));



typedef JointLimits* JointLimitsPtr;

inline
JointLimits::JointLimits()
: m_pprism(0.0f, 0.0f, 0.0f),
    m_vprism(0.0f, 0.0f, 0.0f),
    m_vtwist(0.0f),
    m_vswing(0.0f),
    m_swinga(0.0f),
    m_twista(0.0f),
    m_swingc(1.0f),
    m_twistc(1.0f),
    m_swingf(SWING_LOCKED),
    m_twistf(TWIST_LOCKED)
{
    ;
    return;
}
inline rw::ResourceDescriptor
JointLimits::GetResourceDescriptor()
{
    ;
    uint32_t size = (((sizeof(JointLimits)) + ((16) - 1)) & ~((16) - 1));
    return rw::ResourceDescriptor(size, 16);
}
inline void
JointLimits::EndianSwap(void)
{
    ;
    rw::EndianSwapArray(reinterpret_cast<float32_t *>(&m_pprism), sizeof(m_pprism) / sizeof(float32_t));
    rw::EndianSwapArray(reinterpret_cast<float32_t *>(&m_vprism), sizeof(m_pprism) / sizeof(float32_t));
    rw::EndianSwap(m_vtwist);
    rw::EndianSwap(m_vswing);
    rw::EndianSwap(m_swinga);
    rw::EndianSwap(m_twista);
    rw::EndianSwap(m_swingc);
    rw::EndianSwap(m_twistc);
    rw::EndianSwap(*reinterpret_cast<uint32_t *>(&m_swingf));
    rw::EndianSwap(*reinterpret_cast<uint32_t *>(&m_twistf));
    return;
}
inline rw::math::Vector3
JointLimits::GetPositionLimit(void) const
{
    ;
    return m_pprism;
}
inline rw::math::Vector3
JointLimits::GetDisplacementLimit(void) const
{
    ;
    return m_vprism;
}
inline SwingType
JointLimits::GetSwingType(void) const
{
    ;
    return m_swingf;
}
inline TwistType
JointLimits::GetTwistType(void) const
{
    ;
    return m_twistf;
}
inline float32_t
JointLimits::GetSwingAngle(void) const
{
    ;
    return m_swinga;
}
inline float32_t
JointLimits::GetTwistAngle(void) const
{
    ;
    return m_twista;
}
inline float32_t
JointLimits::GetSwingLimit(void) const
{
    ;
    return m_swingc;
}
inline float32_t
JointLimits::GetTwistLimit(void) const
{
    ;
    return m_twistc;
}
inline rw::math::Vector3
JointLimits::GetAngularDisplacementLimit(void) const
{
    ;
    return rw::math::Vector3(m_vtwist, m_vswing, m_vswing);
}
inline void
JointLimits::SetSwingType(const SwingType s)
{
    ;
    m_swingf = s;
    return;
}
inline void
JointLimits::SetTwistType(const TwistType t)
{
    ;
    m_twistf = t;
    return;
}
inline void
JointLimits::SetSwingAngle(const float32_t sa)
{
    ;
    ;
    m_swinga = sa;
    m_swingc = rw::math::Cos(sa);
    return;
}
inline void
JointLimits::SetTwistAngle(const float32_t ta)
{
    ;
    m_twista = ta;
    m_twistc = rw::math::Cos(ta);
    return;
}
inline void
JointLimits::SetPositionLimit(const rw::math::Vector3 &p)
{
    ;
    m_pprism = p;
    return;
}
inline void
JointLimits::SetDisplacementLimit(const rw::math::Vector3 &d)
{
    ;
    m_vprism = d;
    return;
}
inline void
JointLimits::SetTwistDisplacementLimit(const float32_t tl)
{
    ;
    ;
    m_vtwist = tl;
    return;
}
inline void
JointLimits::SetSwingDisplacementLimit(const float32_t sl)
{
    ;
    ;
    m_vswing = sl;
    return;
}
}
}







namespace rw
{
namespace physics
{
class DriveFrames
{
public:
    DriveFrames() {};
    ~DriveFrames() {};
    inline static rw::ResourceDescriptor GetResourceDescriptor();
    inline void EndianSwap(void);
    inline rw::math::Vector3 GetChildPosition(void) const;
    inline rw::math::Vector3 GetParentPosition(void) const;
    inline rw::math::Quaternion GetChildOrientation(void) const;
    inline rw::math::Quaternion GetParentOrientation(void) const;
    inline void SetChildPosition(const rw::math::Vector3 &p);
    inline void SetParentPosition(const rw::math::Vector3 &p);
    inline void SetChildOrientation(const rw::math::Matrix33 &m);
    inline void SetChildOrientation(const rw::math::Quaternion &q);
    inline void SetParentOrientation(const rw::math::Matrix33 &m);
    inline void SetParentOrientation(const rw::math::Quaternion &q);
    inline void SetChildFrame(const rw::math::Matrix44Affine &m);
    inline void SetChildFrame(const rw::math::QuatPos &q);
    inline void SetParentFrame(const rw::math::Matrix44Affine &m);
    inline void SetParentFrame(const rw::math::QuatPos &q);
private:
    rw::math::Quaternion m_qA;
    rw::math::Vector3 m_posA;
    rw::math::Quaternion m_qB;
    rw::math::Vector3 m_posB;
} __attribute__ ((__aligned__ (16)));



typedef DriveFrames* DriveFramesPtr;

inline rw::ResourceDescriptor
DriveFrames::GetResourceDescriptor()
{
    ;
    RwUInt32 size = (((sizeof(DriveFrames)) + ((16) - 1)) & ~((16) - 1));
    return rw::ResourceDescriptor(size, 16);
}
inline void
DriveFrames::EndianSwap(void)
{
    ;
    ;
    return;
}
inline rw::math::Vector3
DriveFrames::GetChildPosition(void) const
{
    ;
    return m_posA;
}
inline rw::math::Vector3
DriveFrames::GetParentPosition(void) const
{
    ;
    return m_posB;
}
inline rw::math::Quaternion
DriveFrames::GetChildOrientation(void) const
{
    ;
    return m_qA;
}
inline rw::math::Quaternion
DriveFrames::GetParentOrientation(void) const
{
    ;
    return m_qB;
}
inline void
DriveFrames::SetChildPosition(const rw::math::Vector3 &p)
{
    ;
    m_posA = p;
    return;
}
inline void
DriveFrames::SetParentPosition(const rw::math::Vector3 &p)
{
    ;
    m_posB = p;
    return;
}
inline void
DriveFrames::SetChildOrientation(const rw::math::Matrix33 &m)
{
    ;
    m_qA = QuaternionFromMatrix44Affine(rw::math::Matrix44Affine(m.Right(), m.Up(), m.At(), rw::math::GetVector3_Zero()));
    return;
}
inline void
DriveFrames::SetChildOrientation(const rw::math::Quaternion &q)
{
    ;
    m_qA = q;
    return;
}
inline void
DriveFrames::SetParentOrientation(const rw::math::Matrix33 &m)
{
    ;
    m_qB = QuaternionFromMatrix44Affine(rw::math::Matrix44Affine(m.Right(), m.Up(), m.At(), rw::math::GetVector3_Zero()));
    return;
}
inline void
DriveFrames::SetParentOrientation(const rw::math::Quaternion &q)
{
    ;
    m_qB = q;
    return;
}
inline void
DriveFrames::SetChildFrame(const rw::math::Matrix44Affine &m)
{
    ;
    m_qA = QuaternionFromMatrix44Affine(m);
    m_posA = m.Pos();
    return;
}
inline void
DriveFrames::SetChildFrame(const rw::math::QuatPos &q)
{
    ;
    m_qA = q.GetQuaternion();
    m_posA = q.GetPos();
    return;
}
inline void
DriveFrames::SetParentFrame(const rw::math::Matrix44Affine &m)
{
    ;
    m_qB = QuaternionFromMatrix44Affine(m);
    m_posB = m.Pos();
    return;
}
inline void
DriveFrames::SetParentFrame(const rw::math::QuatPos &q)
{
    ;
    m_qB = q.GetQuaternion();
    m_posB = q.GetPos();
    return;
}
}
}







namespace rw
{
namespace physics
{
enum DriveType
{
    NO_DRIVE = 0,
    SOFT_DRIVE = 1,
    HARD_DRIVE = 2,
    DRIVE_FORCE_ENUM_SIZE = ((int32_t)((~((uint32_t)0))>>1))
};
class DriveDynamics
{
public:
    class Params
    {
    public:
        inline Params();
        ~Params() {};
        inline void EndianSwap(void);
        inline float32_t GetSpring(void) const;
        inline float32_t GetMaxDisplacement(void) const;
        inline float32_t GetDamping(void) const;
        inline float32_t GetMaxStrength(void) const;
        inline DriveType GetDriveType(void) const;
        inline void SetInactive(void);
        inline void SetHard(const float32_t dsp, const float32_t dmp, const float32_t str);
        inline void SetSoft(const float32_t spr, const float32_t dmp, const float32_t str);
        inline void SetSpring(const float32_t spr);
        inline void SetMaxDisplacement(const float32_t dsp);
        inline void SetDamping(const float32_t dmp);
        inline void SetMaxStrength(const float32_t str);
    private:
        float32_t m_spring;
        float32_t m_damping;
        float32_t m_strength;
        DriveType m_type;
    } __attribute__ ((__aligned__ (16)));
    DriveDynamics() {};
    ~DriveDynamics() {};
    inline static rw::ResourceDescriptor GetResourceDescriptor();
    inline void EndianSwap(void);
    inline Params &LinearParams(void);
    inline Params &AngularParams(void);
private:
    Params m_linear;
    Params m_angular;
} __attribute__ ((__aligned__ (16)));



typedef DriveDynamics* DriveDynamicsPtr;

inline
DriveDynamics::Params::Params()
: m_spring(0.0f),
    m_damping(0.0f),
    m_strength(0.0f),
    m_type(NO_DRIVE)
{
    ;
    return;
}
inline rw::ResourceDescriptor
DriveDynamics::GetResourceDescriptor()
{
    ;
    RwUInt32 size = (((sizeof(DriveDynamics)) + ((16) - 1)) & ~((16) - 1));
    return rw::ResourceDescriptor(size, 16);
}
inline void
DriveDynamics::Params::EndianSwap(void)
{
    ;
    rw::EndianSwap(m_spring);
    rw::EndianSwap(m_damping);
    rw::EndianSwap(m_strength);
    rw::EndianSwap(*reinterpret_cast<uint32_t *>(&m_type));
    return;
}
inline void
DriveDynamics::EndianSwap(void)
{
    ;
    m_linear.EndianSwap();
    m_angular.EndianSwap();
    return;
}
inline DriveDynamics::Params &
DriveDynamics::LinearParams(void)
{
    ;
    return m_linear;
}
inline DriveDynamics::Params &
DriveDynamics::AngularParams(void)
{
    ;
    return m_angular;
}
inline float32_t
DriveDynamics::Params::GetSpring(void) const
{
    ;
    ;
    return m_spring;
}
inline float32_t
DriveDynamics::Params::GetMaxDisplacement(void) const
{
    ;
    ;
    return m_spring;
}
inline float32_t
DriveDynamics::Params::GetDamping(void) const
{
    ;
    return m_damping;
}
inline float32_t
DriveDynamics::Params::GetMaxStrength(void) const
{
    ;
    return m_strength;
}
inline DriveType
DriveDynamics::Params::GetDriveType(void) const
{
    ;
    return m_type;
}
inline void
DriveDynamics::Params::SetInactive(void)
{
    ;
    m_spring = 0.0f;
    m_damping = 0.0f;
    m_strength = 0.0f;
    m_type = NO_DRIVE;
    return;
}
inline void
DriveDynamics::Params::SetHard(const float32_t dsp, const float32_t dmp, const float32_t str)
{
    ;
    m_spring = dsp;
    m_damping = dmp;
    m_strength = str;
    m_type = HARD_DRIVE;
    return;
}
inline void
DriveDynamics::Params::SetSoft(const float32_t spr, const float32_t dmp, const float32_t str)
{
    ;
    m_spring = spr;
    m_damping = dmp;
    m_strength = str;
    m_type = SOFT_DRIVE;
    return;
}
inline void
DriveDynamics::Params::SetSpring(const float32_t spr)
{
    ;
    ;
    m_spring = spr;
    return;
}
inline void
DriveDynamics::Params::SetMaxDisplacement(const float32_t dsp)
{
    ;
    ;
    m_spring = dsp;
    return;
}
inline void
DriveDynamics::Params::SetDamping(const float32_t dmp)
{
    ;
    m_damping = dmp;
    return;
}
inline void
DriveDynamics::Params::SetMaxStrength(const float32_t str)
{
    ;
    m_strength = str;
    return;
}
}
}
















namespace rw
{
namespace physics
{
class Joint
{
friend class Simulation;
friend class SimulationProxy;
public:
    Joint() {};
    ~Joint() {};
    inline static rw::ResourceDescriptor GetResourceDescriptor();
    inline static Joint *AddressFromOffset(Simulation *stasis, const int32_t off);
    inline int32_t OffsetFromAddress(void) const;
    inline RigidBody *GetParent(void) const;
    inline RigidBody *GetChild(void) const;
    inline JointFrames *GetFrames(void) const;
    inline JointLimits *GetLimits(void) const;
    inline uint32_t GetTag(void) const;
    inline RwBool GetSpy(void) const;
    inline void SetParent(RigidBody *b);
    inline void SetChild(RigidBody *b);
    inline void SetFrames(JointFrames *js);
    inline void SetLimits(JointLimits *jl);
    inline void SetTag(const uint32_t tag);
    inline void SetSpy(const RwBool on_off);
private:
    inline Joint *GetRight(void) const;
    inline Joint *GetLeft(void) const;
    inline void SetRight(Joint *ri);
    inline void SetLeft(Joint *le);
    inline void Move(Joint *src);



    inline void Initialize(RigidBody *pa, RigidBody *ch, JointFrames *sk, JointLimits *jl);
private:



    JointFramesPtr m_skel;
    JointLimitsPtr m_limit;
    int32_t m_right;
    int32_t m_left;
    int32_t m_bodyA;
    int32_t m_bodyB;
    uint32_t m_tag;
    RwBool m_spy;

    int32_t m_offset;
    uint32_t m_pad[8];

} __attribute__ ((__aligned__ (16)));



typedef Joint* JointPtr;

}
}
















namespace rw
{
namespace physics
{
class Drive
{
friend class Simulation;
friend class SimulationProxy;
public:
    Drive() {};
    ~Drive() {};
    inline static rw::ResourceDescriptor GetResourceDescriptor();
    inline static Drive *AddressFromOffset(Simulation *stasis, const RwInt32 off);
    inline int32_t OffsetFromAddress(void) const;
    inline RigidBody *GetParent(void) const;
    inline RigidBody *GetChild(void) const;
    inline DriveFrames *GetFrames(void) const;
    inline DriveDynamics *GetDynamics(void) const;
    inline uint32_t GetTag(void) const;
    inline RwBool GetSpy(void) const;
    inline void SetParent(RigidBody *b);
    inline void SetChild(RigidBody *b);
    inline void SetFrames(DriveFrames *ds);
    inline void SetDynamics(DriveDynamics *dd);
    inline void SetTag(const uint32_t tag);
    inline void SetSpy(const RwBool on_off);
private:
    inline Drive *GetRight(void) const;
    inline Drive *GetLeft(void) const;
    inline void SetRight(Drive *ri);
    inline void SetLeft(Drive *le);
    inline void Move(Drive *src);



    inline void Initialize(RigidBody *pa, RigidBody *ch, DriveFrames *sk, DriveDynamics *dd);
private:



    DriveFramesPtr m_skel;
    DriveDynamicsPtr m_crtl;
    int32_t m_right;
    int32_t m_left;
    int32_t m_bodyA;
    int32_t m_bodyB;
    uint32_t m_tag;
    RwBool m_spy;

    int32_t m_offset;
    uint32_t m_pad[8];

} __attribute__ ((__aligned__ (16)));



typedef Drive* DrivePtr;

}
}











namespace rw
{
namespace physics
{
class Contact
{
friend class SimulationProxy;
public:
    Contact() {};
    ~Contact() {};
    inline static rw::ResourceDescriptor GetResourceDescriptor();
    inline RigidBody *GetBodyA(Simulation *stasis) const;
    inline RigidBody *GetBodyB(Simulation *stasis) const;
    inline uint32_t GetTag(void) const;
    inline rw::math::Vector3 GetPositionOnA(void) const;
    inline rw::math::Vector3 GetPositionOnB(void) const;
    inline rw::math::Vector3 GetDisplacement(void) const;
    inline rw::math::Matrix33 GetFrame(void) const;
    inline float32_t GetStaticFriction(void) const;
    inline float32_t GetDynamicFriction(void) const;
    inline float32_t GetRestitution(void) const;
    inline void SetBodyA(RigidBody *ba);
    inline void SetBodyB(RigidBody *bb);
    inline void SetTag(const uint32_t tag);
    inline void SetPositionOnA(const rw::math::Vector3 &p);
    inline void SetPositionOnB(const rw::math::Vector3 &p);
    inline void SetFrame(const rw::math::Matrix33 &m);
    inline void GenerateFrame(const rw::math::Vector3 &normal);
    inline void SetFriction(const float32_t s, const float32_t d);
    inline void SetRestitution(const float32_t r);
    inline void SetDisplacement(const rw::math::Vector3 &d);
    inline void GenerateFromCollision(RigidBody *ba, RigidBody *bb,
                                      const rw::math::Vector3 &posa,
                                      const rw::math::Vector3 &posb,
                                      const rw::math::Vector3 &normal);
    inline void GenerateFromCollision(RigidBody *ba, RigidBody *bb,
                                      const rw::math::Vector3 &posa,
                                      const rw::math::Vector3 &posb,
                                      const rw::math::Vector3 &normal,
                                      const float32_t staticFriction,
                                      const float32_t dynamicFriction,
                                      const float32_t restitution,
                                      const uint32_t tag);
private:
    rw::math::fpu::Vector3U_32 m_posA;
    int32_t m_bodyA;
    rw::math::fpu::Vector3U_32 m_posB;
    int32_t m_bodyB;
    rw::math::fpu::Vector3U_32 m_ri;
    float32_t m_res;
    rw::math::fpu::Vector3U_32 m_up;
    float32_t m_mus;
    rw::math::fpu::Vector3U_32 m_at;
    float32_t m_mud;
    rw::math::fpu::Vector3U_32 m_dsp;
    uint32_t m_tag;
    rw::math::fpu::Vector4U_32 m_pad[10];
} __attribute__ ((__aligned__ (128)));
}
}







namespace rw
{
namespace physics
{
class JointSpy
{
friend class Simulation;
friend class SimulationProxy;
public:
    JointSpy() {};
    ~JointSpy() {};
    inline static rw::ResourceDescriptor GetResourceDescriptor();
    inline static uint32_t GetSize();
    inline static uint32_t GetAlignment();
    inline Joint *GetJoint(Simulation *stasis) const;
    inline uint32_t GetTag(void) const;
    inline rw::math::Vector3 GetLinearStress(void) const;
    inline rw::math::Vector3 GetAngularStress(void) const;
private:
    inline void SetJoint(int32_t jt);
    inline void SetTag(const uint32_t tag);
    inline void SetLinearStress(const rw::math::Vector3 &lmag);
    inline void SetAngularStress(const rw::math::Vector3 &amag);



private:
    rw::math::Vector3 m_lstress;
    rw::math::Vector3 m_astress;
    int32_t m_joint;
    uint32_t m_tag;
} __attribute__ ((__aligned__ (16)));
}
}







namespace rw
{
namespace physics
{
class DriveSpy
{
friend class Simulation;
friend class SimulationProxy;
public:
    DriveSpy() {};
    ~DriveSpy() {};
    inline static rw::ResourceDescriptor GetResourceDescriptor();
    inline static uint32_t GetSize();
    inline static uint32_t GetAlignment();
    inline Drive *GetDrive(Simulation *stasis) const;
    inline uint32_t GetTag(void) const;
    inline float32_t GetLinearDistanceToKey(void) const;
    inline float32_t GetAngularDistanceToKey(void) const;
    inline rw::math::Vector3 GetLinearStress(void) const;
    inline rw::math::Vector3 GetAngularStress(void) const;
private:
    inline void SetDrive(int32_t jt);
    inline void SetTag(const uint32_t tag);
    inline void SetLinearDistanceToKey(const float32_t ldst);
    inline void SetAngularDistanceToKey(const float32_t adst);
    inline void SetLinearStress(const rw::math::Vector3 &lmag);
    inline void SetAngularStress(const rw::math::Vector3 &amag);



private:
    rw::math::Vector3 m_lstress;
    rw::math::Vector3 m_astress;
    float32_t m_lindst;
    float32_t m_angdst;
    int32_t m_drive;
    uint32_t m_tag;
} __attribute__ ((__aligned__ (16)));
}
}







namespace rw
{
namespace physics
{
class ContactSpy
{
friend class Simulation;
friend class SimulationProxy;
public:
    ContactSpy() {};
    ~ContactSpy() {};
    inline static rw::ResourceDescriptor GetResourceDescriptor();
    inline RigidBody *GetBodyA(Simulation *stasis) const;
    inline RigidBody *GetBodyB(Simulation *stasis) const;
    inline uint32_t GetTag(void) const;
    inline rw::math::Vector3 GetNormalStress(void) const;
    inline rw::math::Vector3 GetFrictionStress(void) const;
    inline rw::math::Matrix44Affine GetFrame(void) const;
private:
    inline void SetBodyA(int32_t ba);
    inline void SetBodyB(int32_t bb);
    inline void SetTag(const uint32_t tag);
    inline void SetNormalStress(const rw::math::Vector3 &csd);
    inline void SetFrictionStress(const rw::math::Vector3 &fsd);
    inline void SetFrame(const rw::math::Matrix44Affine &m);



private:
    rw::math::Matrix44Affine m_frame;
    rw::math::Vector3 m_nimp;
    rw::math::Vector3 m_fric;
    int32_t m_bodyA;
    int32_t m_bodyB;
    uint32_t m_tag;
} __attribute__ ((__aligned__ (16)));
}
}






namespace rw
{
namespace physics
{
class SimulationWorkspace
{
public:
    SimulationWorkspace() {};
    ~SimulationWorkspace() {};
    static rw::ResourceDescriptor GetResourceDescriptor(const uint32_t max_joints,
                                                        const uint32_t max_drives,
                                                        const uint32_t max_contacts);
    static SimulationWorkspace *Initialize(const rw::Resource &resource, const uint32_t max_joints,
                                                                         const uint32_t max_drives,
                                                                         const uint32_t max_contacts);
    inline RwBool Release(void);
};
inline RwBool
SimulationWorkspace::Release(void)
{
    ;
    return (1);
}
}
}
























namespace rw
{
namespace datacontainer
{
    class Container;
}
}
namespace rw
{
namespace physics
{






typedef void* voidPtr;

    typedef rw::datacontainer::Container* DataContainerPtr;


enum SpyingFlag
{
    SPY_NOTHING = 0x0,
    SPY_JOINTS = 0x1,
    SPY_DRIVES = 0x2,
    SPY_CONTACTS = 0x4,
    SPY_FORCE_ENUM_SIZE = ((int32_t)((~((uint32_t)0))>>1))
};




class Simulation
{

friend class RigidBody;
friend class Joint;
friend class Drive;
friend class ContactJacobian;
friend class SimulationProxy;

public:
    Simulation() {};
    ~Simulation() {};
    static rw::ResourceDescriptor GetResourceDescriptor(const uint32_t max_bodies,
                                                        const uint32_t max_joints,
                                                        const uint32_t max_drives);
    static Simulation *Initialize(const rw::Resource &resource, const uint32_t max_bodies,
                                  const uint32_t max_joints, const uint32_t max_drives);
    RwBool SetWorkspace(const SimulationWorkspace *data, const uint32_t max_joints,
                        const uint32_t max_drives, const uint32_t max_contacts);
    inline void ResetContactStack(void);
    inline void ResetParameters(void);
    inline RwBool Release(void);
    RwBool SimulationUpdate(void);

    enum ProcessingStageFlags
    {
        COMPILE_CONTACTS = 0x01,
        COMPILE_JOINTS = 0x02,
        COMPILE_DRIVES = 0x04,
        SOLVE = 0x08,
        UPDATE_RIGID_BODIES = 0x10,
        GENERATE_CONTACT_SPIES = 0x20,
        GENERATE_JOINT_SPIES = 0x40,
        GENERATE_DRIVE_SPIES = 0x80,
        COMPILE = COMPILE_CONTACTS|COMPILE_JOINTS|COMPILE_DRIVES,
        GENERATE_SPIES = GENERATE_CONTACT_SPIES|GENERATE_JOINT_SPIES|GENERATE_DRIVE_SPIES,
        ALL_STAGES = COMPILE|SOLVE|UPDATE_RIGID_BODIES|GENERATE_SPIES,
        NO_STAGES = 0x00,
        STAGES_FORCE_ENUM_SIZE = ((int32_t)((~((uint32_t)0))>>1))
    };
    GlobalAddress SimulationUpdateSPUProlog(uint32_t selectedStages = ALL_STAGES);
    void SimulationUpdateSPUEpilog(GlobalAddress SPUToken);

    inline rw::math::Vector3 GetGravity(void) const;
    inline rw::math::Vector3 GetDisplacementThroughGravity(void) const;
    inline float32_t GetTimeStep(void) const;
    inline float32_t GetFrequency(void) const;
    inline float32_t GetPadding(void) const;
    inline uint32_t GetCoolDown(void) const;
    inline float32_t GetFreezingEnergy(void) const;
    inline uint32_t GetMaxIteration(void) const;
    inline SpyingFlag GetSpyingMode(void) const;
    inline void SetGravity(const rw::math::Vector3 &grav);
    inline void SetTimeStep(const float32_t t);
    inline void SetPadding(const float32_t pad);
    inline void SetCoolDown(const uint32_t frz);
    inline void SetFreezingEnergy(const float32_t eng);
    inline void SetMaxIteration(const uint32_t iter);
    inline void SetSpyingMode(const SpyingFlag flag);
    inline uint32_t GetMaxRigidBody(void) const;
    inline uint32_t GetMaxJoint(void) const;
    inline uint32_t GetMaxDrive(void) const;
    inline uint32_t GetMaxContact(void) const;
    inline uint32_t GetFreeBodyCount(void) const;
    inline uint32_t GetActiveBodyCount(void) const;
    inline uint32_t GetFrozenBodyCount(void) const;
    inline uint32_t GetStaticBodyCount(void) const;
    inline uint32_t GetFreeJointCount(void) const;
    inline uint32_t GetActiveJointCount(void) const;
    inline RwUInt32 GetFreeDriveCount(void) const;
    inline RwUInt32 GetActiveDriveCount(void) const;
    inline uint32_t GetContactCount(void) const;
    inline uint32_t GetContactSpyCount(void) const;
    inline uint32_t GetJointSpyCount(void) const;
    inline RwUInt32 GetDriveSpyCount(void) const;
    inline Contact *GetFreeContact(void);
    inline Contact *GetFreeContactBatch(const uint32_t numContacts);
    inline Contact *GetContact(const uint32_t id) const;
    inline ContactSpy *GetContactSpy(const uint32_t id) const;
    inline JointSpy *GetJointSpy(const uint32_t id) const;
    inline DriveSpy *GetDriveSpy(const RwUInt32 id) const;
    inline const RigidBody *GetBodyArray(void) const;
    inline const RigidBody *GetActiveBodyAnchor(void) const;
    RigidBody *AddRigidBody(const rw::math::Matrix44Affine &m, Inertia *ine,
                            const BodyState state);
    void RemoveRigidBody(RigidBody *body);
    void FreezeRigidBody(RigidBody *body);
    void ActivateRigidBody(RigidBody *body);
    Joint *AddJoint(RigidBody *pa, RigidBody *ch, JointFrames *sk, JointLimits *jl);
    void RemoveJoint(Joint *joint);
    Drive *AddDrive(RigidBody *pa, RigidBody *ch, DriveFrames *sk, DriveDynamics *dd);
    void RemoveDrive(Drive *drive);
    inline void *GetReactionForces(void) const;
private:
    void BatchIntegrator(void);
    void SpyContactJacobians(void);
    void SpyJointJacobians(void);
    void SpyDriveJacobians(void);
    void ContactBatchBuild(void);
    void JointBatchBuild(void);
    void DriveBatchBuild(void);
    void Anubis_Pipeline(void);
    void Osiris_Pipeline(void);
    void Isis_Pipeline(void);
    void Horus_Pipeline(void);
private:

    DataContainerPtr m_CJ_DataContainer;

    RigidBodyPtr m_RB_Stack;
    JointPtr m_JT_Stack;
    DrivePtr m_DR_Stack;
    voidPtr m_RF_Stack;
    voidPtr m_CJ_Stack;
    voidPtr m_JJ_Stack;
    voidPtr m_DJ_Stack;
    RigidBodyPtr m_FreeRB_Anchor;
    RigidBodyPtr m_StaticRB_Anchor;
    RigidBodyPtr m_FrozenRB_Anchor;
    RigidBodyPtr m_ActiveRB_Anchor;
    JointPtr m_FreeJT_Anchor;
    JointPtr m_ActiveJT_Anchor;
    DrivePtr m_FreeDR_Anchor;
    DrivePtr m_ActiveDR_Anchor;
    uint32_t m_FreeRB_Count;
    uint32_t m_StaticRB_Count;
    uint32_t m_FrozenRB_Count;
    uint32_t m_ActiveRB_Count;
    uint32_t m_FreeJT_Count;
    uint32_t m_ActiveJT_Count;
    uint32_t m_FreeDR_Count;
    uint32_t m_ActiveDR_Count;
    uint32_t m_JT_Stride;
    uint32_t m_DR_Stride;
    uint32_t m_CT_Count;
    uint32_t m_CS_Count;
    uint32_t m_JT_Count;
    uint32_t m_JS_Count;
    uint32_t m_DR_Count;
    uint32_t m_DS_Count;
    uint32_t m_CT_Max;
    uint32_t m_JT_Max;
    uint32_t m_DR_Max;
    uint32_t m_RF_Max;
    rw::math::Vector3 m_Gravity;
    rw::math::Vector3 m_Gdsp;
    float32_t m_TimeStep;
    float32_t m_Frequency;
    float32_t m_Padding;
    uint32_t m_CoolDown;
    float32_t m_MinEnergy;
    float32_t m_Precision;
    uint32_t m_MaxIteration;
    SpyingFlag m_SpyFlag;

    uint32_t m_selectedStages;
    char m_DMApad[16] __attribute__ ((__aligned__ (16)));

} __attribute__ ((__aligned__ (128)));



inline void
Simulation::ResetContactStack(void)
{
    ;
    m_CT_Count = 0;
    m_CS_Count = 0;
    return;
}
inline void
Simulation::ResetParameters(void)
{
    ;
    m_Gravity = (rw::math::Vector3(0.0f, -600.0f, 0.0f));
    m_Frequency = (60.0f);
    m_CoolDown = (30);
    m_MinEnergy = (2.5e-2f);
    m_MaxIteration = (50);
    m_TimeStep = 1.0f / m_Frequency;
    m_Gdsp = m_Gravity * rw::math::VecFloat(m_TimeStep * m_TimeStep);
    m_SpyFlag = SPY_NOTHING;
    return;
}
inline RwBool
Simulation::Release(void)
{
    ;
    return (1);
}
inline rw::math::Vector3
Simulation::GetGravity(void) const
{
    ;
    return m_Gravity;
}
inline rw::math::Vector3
Simulation::GetDisplacementThroughGravity(void) const
{
    ;
    return m_Gdsp;
}
inline float32_t
Simulation::GetTimeStep(void) const
{
    ;
    return m_TimeStep;
}
inline float32_t
Simulation::GetFrequency(void) const
{
    ;
    return m_Frequency;
}
inline float32_t
Simulation::GetPadding(void) const
{
    ;
    ;
    return 0.0f;
}
inline uint32_t
Simulation::GetCoolDown(void) const
{
    ;
    return m_CoolDown;
}
inline float32_t
Simulation::GetFreezingEnergy(void) const
{
    ;
    return m_MinEnergy;
}
inline uint32_t
Simulation::GetMaxIteration(void) const
{
    ;
    return m_MaxIteration;
}
inline SpyingFlag
Simulation::GetSpyingMode(void) const
{
    ;
    return m_SpyFlag;
}
inline void
Simulation::SetGravity(const rw::math::Vector3 &grav)
{
    ;
    m_Gravity = grav;
    m_Gdsp = m_Gravity * rw::math::VecFloat(m_TimeStep * m_TimeStep);
    return;
}
inline void
Simulation::SetTimeStep(const float32_t t)
{
    ;
    ;
    m_TimeStep = t;
    m_Frequency = 1.0f / t;
    m_Gdsp = m_Gravity * rw::math::VecFloat(t * t);
    return;
}
inline void
Simulation::SetPadding(const float32_t )
{
    ;
    ;
    return;
}
inline void
Simulation::SetCoolDown(const uint32_t frz)
{
    ;
    ;
    m_CoolDown = frz;
    return;
}
inline void
Simulation::SetFreezingEnergy(const float32_t eng)
{
    ;
    ;
    m_MinEnergy = eng;
    return;
}
inline void
Simulation::SetMaxIteration(const uint32_t iter)
{
    ;
    ;
    m_MaxIteration = iter;
    return;
}
inline void
Simulation::SetSpyingMode(const SpyingFlag flag)
{
    ;
    m_SpyFlag = flag;
    return;
}
inline uint32_t
Simulation::GetMaxRigidBody(void) const
{
    ;
    return m_RF_Max;
}
inline uint32_t
Simulation::GetMaxJoint(void) const
{
    ;
    return m_JT_Max;
}
inline uint32_t
Simulation::GetMaxDrive(void) const
{
    ;
    return m_DR_Max;
}
inline uint32_t
Simulation::GetMaxContact(void) const
{
    ;
    return m_CT_Max;
}
inline uint32_t
Simulation::GetFreeBodyCount(void) const
{
    ;
    return m_FreeRB_Count;
}
inline uint32_t
Simulation::GetActiveBodyCount(void) const
{
    ;
    return m_ActiveRB_Count;
}
inline uint32_t
Simulation::GetFrozenBodyCount(void) const
{
    ;
    return m_FrozenRB_Count;
}
inline uint32_t
Simulation::GetStaticBodyCount(void) const
{
    ;
    return m_StaticRB_Count;
}
inline uint32_t
Simulation::GetFreeJointCount(void) const
{
    ;
    return m_FreeJT_Count;
}
inline uint32_t
Simulation::GetActiveJointCount(void) const
{
    ;
    return m_ActiveJT_Count;
}
inline uint32_t
Simulation::GetFreeDriveCount(void) const
{
    ;
    return m_FreeDR_Count;
}
inline uint32_t
Simulation::GetActiveDriveCount(void) const
{
    ;
    return m_ActiveDR_Count;
}
inline uint32_t
Simulation::GetContactCount(void) const
{
    ;
    return m_CT_Count;
}
inline uint32_t
Simulation::GetContactSpyCount(void) const
{
    ;
    return m_CS_Count;
}
inline uint32_t
Simulation::GetJointSpyCount(void) const
{
    ;
    return m_JS_Count;
}
inline RwUInt32
Simulation::GetDriveSpyCount(void) const
{
    ;
    return m_DS_Count;
}
inline Contact *
Simulation::GetFreeContact(void)
{
    ;
    if(m_CT_Count == m_CT_Max) return 0;
    Contact * contactStack = reinterpret_cast<Contact*>((rw::HostPtr)(m_CJ_Stack));
    return &contactStack[m_CT_Count++];
}
inline Contact *
Simulation::GetFreeContactBatch(const uint32_t numContacts)
{
    ;
    if(m_CT_Count + numContacts > m_CT_Max) return 0;
    Contact * contactStack = reinterpret_cast<Contact*>((rw::HostPtr)(m_CJ_Stack));
    Contact * contact = &contactStack[m_CT_Count];
    m_CT_Count += numContacts;
    return contact;
}
inline Contact *
Simulation::GetContact(const uint32_t id) const
{
    ;
    ;
    Contact * contactStack = reinterpret_cast<Contact*>((rw::HostPtr)(m_CJ_Stack));
    return &contactStack[id];
}
inline ContactSpy *
Simulation::GetContactSpy(const uint32_t id) const
{
    ;
    if(m_CS_Count) return &((ContactSpy*)m_CJ_Stack)[id];
    return 0;
}
inline JointSpy *
Simulation::GetJointSpy(const uint32_t id) const
{
    ;
    if(m_JS_Count) return &((JointSpy*)m_JJ_Stack)[id];
    return 0;
}
inline DriveSpy *
Simulation::GetDriveSpy(const uint32_t id) const
{
    ;
    if(m_DR_Count) return &((DriveSpy*)m_DJ_Stack)[id];
    return 0;
}
inline const RigidBody *
Simulation::GetBodyArray(void) const
{
    ;
    return m_RB_Stack;
}
inline const RigidBody *
Simulation::GetActiveBodyAnchor(void) const
{
    ;
    return m_ActiveRB_Anchor;
}
inline void *
Simulation::GetReactionForces(void) const
{
    ;
    return m_RF_Stack;
}
}
}






namespace rw
{
namespace physics
{
inline rw::ResourceDescriptor
RigidBody::GetResourceDescriptor()
{
    ;
    uint32_t size = (((sizeof(RigidBody)) + ((16) - 1)) & ~((16) - 1));
    return rw::ResourceDescriptor(size, 16);
}

inline RigidBody *
RigidBody::AddressFromOffset(Simulation *, const int32_t off)
{
    ;
    return (RigidBody*)off;
}









inline int32_t
RigidBody::OffsetFromAddress(void) const
{
    ;
    return (int32_t)this;
}










inline void
RigidBody::InertiaDynamicUpdate(Inertia *inertia)
{
    ;
    math::Vector3 ivt = inertia->GetInverseInertia();
    math::Vector3 ri = (math::Vector3 &)m_ri;
    math::Vector3 up = (math::Vector3 &)m_up;
    math::Vector3 at = (math::Vector3 &)m_at;
    math::Vector3 sri = ri * ivt.X();
    math::Vector3 sup = up * ivt.Y();
    math::Vector3 sat = at * ivt.Z();
    math::Vector3 Ifull(sri * ri.X() + sup * up.X() + sat * at.X());








    math::Vector3 ri_ZYY(ri.Z(), ri.Y(), ri.Y());
    math::Vector3 up_ZYY(up.Z(), up.Y(), up.Y());
    math::Vector3 at_ZYY(at.Z(), at.Y(), at.Y());
    math::Vector3 sri_ZYZ(sri.Z(), sri.Y(), sri.Z());
    math::Vector3 sup_ZYZ(sup.Z(), sup.Y(), sup.Z());
    math::Vector3 sat_ZYZ(sat.Z(), sat.Y(), sat.Z());

    ((math::Vector3Plus &)m_Ifull).SetVector3(Ifull);
    math::Vector3 Isplt(Mult(ri_ZYY, sri_ZYZ) + Mult(up_ZYY, sup_ZYZ) + Mult(at_ZYY, sat_ZYZ));
    ((math::Vector3Plus &)m_Isplt).SetVector3(Isplt);
    return;
}
inline void
RigidBody::InertiaUpdate(void)
{
    ;
    InertiaDynamicUpdate(m_inertia);
    math::VecFloat invm(m_inertia->GetInverseMass());
    ((math::Vector3Plus &)m_Ifull).SetPlus(invm);
    return;
}
inline float32_t
RigidBody::GetInverseMass(void) const
{
    ;
    return m_invm;
}
inline rw::math::Matrix33
RigidBody::GetWorldSpaceInverseInertia(void) const
{
    ;
    rw::math::Matrix33 out;
    out.XAxis().SetVector((__attribute__((altivec(vector__))) float&)m_Ifull);
    out.YAxis().SetVector(vec_perm((__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float&)m_Ifull, (__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float&)m_Isplt, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_Y0Y1Z1W0));
    out.ZAxis().SetVector(vec_perm((__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float&)m_Ifull, (__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float&)m_Isplt, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_Z0Z1X1W0));
    return out;
}
inline rw::math::Vector3
RigidBody::GetPosition(void) const
{
    ;
    return (rw::math::Vector3&)m_com;
}
inline rw::math::Vector3
RigidBody::GetDisplacement(void) const
{
    ;
    return (rw::math::Vector3&)m_dsp;
}
inline rw::math::Vector3
RigidBody::GetVelocity(void) const
{
    ;
    return GetDisplacement() * m_stasis->GetFrequency();
}
inline rw::math::Vector3
RigidBody::GetAngularDisplacement(void) const
{
    ;
    return (rw::math::Vector3&)m_omega;
}
inline rw::math::Vector3
RigidBody::GetAngularVelocity(void) const
{
    ;
    return GetAngularDisplacement() * m_stasis->GetFrequency();
}
inline rw::math::Quaternion
RigidBody::GetQuaternion(void) const
{
    ;
    return m_qt;
}
inline rw::math::Matrix33
RigidBody::GetOrientation(void) const
{
    ;
    return (rw::math::Matrix33&)m_ri;
}
inline rw::math::QuatPos
RigidBody::GetQuatPos(void) const
{
    ;
    return rw::math::QuatPos(m_qt, GetPosition());
}
inline rw::math::Matrix44Affine
RigidBody::GetTransform(void) const
{
    ;
    return rw::math::Matrix44Affine((rw::math::Vector3&)m_ri, (rw::math::Vector3&)m_up, (rw::math::Vector3&)m_at, GetPosition());



}
inline rw::math::Vector3
RigidBody::GetLocalDisplacement(const rw::math::Vector3 &p) const
{
    ;
    __attribute__((altivec(vector__))) float cross_a1 = vec_perm((__attribute__((altivec(vector__))) float)p.GetVector(), (__attribute__((altivec(vector__))) float)p.GetVector(), (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_YZXW);
    __attribute__((altivec(vector__))) float cross_b2 = vec_perm((__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float&)m_omega, (__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float&)m_omega, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_ZXYW);
    __attribute__((altivec(vector__))) float cross_a2 = vec_perm((__attribute__((altivec(vector__))) float)p.GetVector(), (__attribute__((altivec(vector__))) float)p.GetVector(), (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_ZXYW);
    __attribute__((altivec(vector__))) float cross_b1 = vec_perm((__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float&)m_omega, (__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float&)m_omega, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_YZXW);
    __attribute__((altivec(vector__))) float displmnt = vec_madd((__attribute__((altivec(vector__))) float)cross_a2, (__attribute__((altivec(vector__))) float)cross_b1, (__attribute__((altivec(vector__))) float)vec_nmsub((__attribute__((altivec(vector__))) float)cross_a1, (__attribute__((altivec(vector__))) float)cross_b2, (__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float&)m_dsp));
    return *(rw::math::Vector3*)&displmnt;
}
inline rw::math::Vector3
RigidBody::GetLocalVelocity(const rw::math::Vector3 &p) const
{
    ;
    return GetLocalDisplacement(p) * m_stasis->GetFrequency();
}
inline rw::math::Vector3
RigidBody::GetForceDisplacement(void) const
{
    ;
    return (rw::math::Vector3&)m_force;
}
inline rw::math::Vector3
RigidBody::GetTorqueDisplacement(void) const
{
    ;
    return (rw::math::Vector3&)m_torque;
}
inline rw::math::Vector3
RigidBody::GetLocalForceDisplacement(const rw::math::Vector3 &p) const
{
    ;
    __attribute__((altivec(vector__))) float cross_a1 = vec_perm((__attribute__((altivec(vector__))) float)p.GetVector(), (__attribute__((altivec(vector__))) float)p.GetVector(), (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_YZXW);
    __attribute__((altivec(vector__))) float cross_b2 = vec_perm((__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float&)m_torque, (__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float&)m_torque, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_ZXYW);
    __attribute__((altivec(vector__))) float cross_a2 = vec_perm((__attribute__((altivec(vector__))) float)p.GetVector(), (__attribute__((altivec(vector__))) float)p.GetVector(), (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_ZXYW);
    __attribute__((altivec(vector__))) float cross_b1 = vec_perm((__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float&)m_torque, (__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float&)m_torque, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_YZXW);
    __attribute__((altivec(vector__))) float displmnt = vec_madd((__attribute__((altivec(vector__))) float)cross_a2, (__attribute__((altivec(vector__))) float)cross_b1, (__attribute__((altivec(vector__))) float)vec_nmsub((__attribute__((altivec(vector__))) float)cross_a1, (__attribute__((altivec(vector__))) float)cross_b2, (__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float&)m_force));
    return *(rw::math::Vector3*)&displmnt;
}
inline Inertia *
RigidBody::GetInertia(void) const
{
    ;
    return m_inertia;
}
inline float32_t
RigidBody::GetKineticEnergy(void) const
{
    ;
    return m_kine;
}
inline uint32_t
RigidBody::GetCoolDown(void) const
{
    ;
    return m_cool;
}
inline uint32_t
RigidBody::GetTag(void) const
{
    ;
    return m_tag;
}
inline BodyState
RigidBody::GetState(void) const
{
    ;
    return m_state;
}
inline void
RigidBody::SetPosition(const rw::math::Vector3 &p)
{
    ;
    ((rw::math::Vector3Plus &)m_com).SetVector3(p);
    return;
}
inline void
RigidBody::SetDisplacement(const rw::math::Vector3 &d)
{
    ;
    ((rw::math::Vector3Plus &)m_dsp).SetVector3(d);
return;
}
inline void
RigidBody::SetVelocity(const rw::math::Vector3 &v)
{
    ;
    SetDisplacement(v * m_stasis->GetTimeStep());
    return;
}
inline void
RigidBody::SetAngularDisplacement(const rw::math::Vector3 &v)
{
    ;
    ((rw::math::Vector3Plus &)m_omega).SetVector3(v);
    return;
}
inline void
RigidBody::SetAngularVelocity(const rw::math::Vector3 &v)
{
    ;
    SetAngularDisplacement(v * m_stasis->GetTimeStep());
    return;
}
inline void
RigidBody::SetTransform(const rw::math::Matrix44Affine &m)
{
    ;
    ((rw::math::Vector3Plus &)m_ri).SetVector3(m.Right());
    ((rw::math::Vector3Plus &)m_up).SetVector3(m.Up());
    ((rw::math::Vector3Plus &)m_at).SetVector3(m.At());
    SetPosition(m.Pos());
    m_qt= QuaternionFromMatrix44Affine(m);
    if(m_inertia) InertiaUpdate();
    return;
}
inline void
RigidBody::SetTransform(const rw::math::QuatPos &q)
{
    ;
    m_qt = q.GetQuaternion();
    rw::math::Matrix44Affine m = Matrix44AffineFromQuatPos(q);
    ((rw::math::Vector3Plus &)m_ri).SetVector3(m.Right());
    ((rw::math::Vector3Plus &)m_up).SetVector3(m.Up());
    ((rw::math::Vector3Plus &)m_at).SetVector3(m.At());
    SetPosition(m.Pos());
    if(m_inertia) InertiaUpdate();
    return;
}
inline void
RigidBody::SetInertia(Inertia *ine)
{
    ;
    m_inertia = ine;
    if(m_inertia) InertiaUpdate();
    return;
}
inline void
RigidBody::SetCoolDown(const uint32_t cd)
{
    ;
    m_cool = cd;
    return;
}
inline void
RigidBody::SetTag(const uint32_t tag)
{
    ;
    m_tag = tag;
    return;
}
inline void
RigidBody::SetSpy(const RwBool on_off)
{
    ;
    if(on_off) m_state = (BodyState)(m_state | SPY_BODY);
    else m_state = (BodyState)(m_state & STATE_FILTER);
    return;
}
inline void
RigidBody::ResetForces(rw::math::Vector3 &dspGrav)
{
    ;
    ((rw::math::Vector3Plus &)m_force ).SetVector3(dspGrav);
    ((rw::math::Vector3Plus &)m_torque).SetVector3(rw::math::Vector3(rw::math::GetVecFloat_Zero().GetVector()));
    return;
}
inline void
RigidBody::ResetForces(void)
{
    ;
    rw::math::Vector3 dsp_grav = m_stasis->GetDisplacementThroughGravity();
    ResetForces(dsp_grav);
    return;
}
inline void
RigidBody::AddDisplacement(const rw::math::Vector3 &ld, const InputSpace spc)
{
    ;
    ;
    if(spc == WORLD_SPACE)
    {
        m_force += rw::math::fpu::Vector3U_32(ld);
    }
    else
    {
        m_force += m_ri * (float32_t)static_cast<float>(ld.X()) + m_up * (float32_t)static_cast<float>(ld.Y()) + m_at * (float32_t)ld.Z();
    }
    SetCoolDown(0);
    return;
}
inline void
RigidBody::AddImpulse(const rw::math::Vector3 &li, const InputSpace spc)
{
    ;
    ;
    float32_t scale = m_stasis->GetTimeStep();
    if(spc == WORLD_SPACE)
    {
        m_force += rw::math::fpu::Vector3U_32(li * scale);
    }
    else
    {
        m_force += (m_ri * (float32_t)static_cast<float>(li.X()) + m_up * (float32_t)static_cast<float>(li.Y()) + m_at * (float32_t)li.Z()) * scale;
    }
    SetCoolDown(0);
    return;
}
inline void
RigidBody::AddForce(const rw::math::Vector3 &lf, const InputSpace spc)
{
    ;
    ;
    AddImpulse(lf * GetInverseMass() * m_stasis->GetTimeStep(), spc);
    return;
}
inline void
RigidBody::AddAngularDisplacement(const rw::math::Vector3 &ad, const InputSpace spc)
{
    ;
    ;
    if(spc == WORLD_SPACE)
    {
        m_torque += rw::math::fpu::Vector3U_32(ad);
    }
    else
    {
        m_torque += m_ri * static_cast<float32_t>(ad.X()) + m_up * static_cast<float32_t>(ad.Y()) + m_at * static_cast<float32_t>(ad.Z());
    }
    SetCoolDown(0);
    return;
}
inline void
RigidBody::AddAngularImpulse(const rw::math::Vector3 &ai, const InputSpace spc)
{
    ;
    ;
    if(spc == WORLD_SPACE)
    {
        float32_t scale = m_stasis->GetTimeStep();
        m_torque.X() =static_cast<float>(m_torque.X()) + (static_cast<float>(m_Ifull.X()) * static_cast<float>(ai.X()) + static_cast<float>(m_Ifull.Y()) * static_cast<float>(ai.Y()) + static_cast<float>(m_Ifull.Z()) * static_cast<float>(ai.Z())) * scale;
        m_torque.Y() =static_cast<float>(m_torque.Y()) + (static_cast<float>(m_Ifull.Y()) * static_cast<float>(ai.X()) + static_cast<float>(m_Isplt.Y()) * static_cast<float>(ai.Y()) + static_cast<float>(m_Isplt.Z()) * static_cast<float>(ai.Z())) * scale;
        m_torque.Z() =static_cast<float>(m_torque.Z()) + (static_cast<float>(m_Ifull.Z()) * static_cast<float>(ai.X()) + static_cast<float>(m_Isplt.Z()) * static_cast<float>(ai.Y()) + static_cast<float>(m_Isplt.X()) * static_cast<float>(ai.Z())) * scale;
    }
    else
    {
        rw::math::Vector3 ad = rw::math::Mult(ai, m_inertia->GetInverseInertia()) * m_stasis->GetTimeStep();
        m_torque += m_ri * static_cast<float32_t>(ad.X()) + m_up * static_cast<float32_t>(ad.Y()) + m_at * static_cast<float32_t>(ad.Z());
    }
    SetCoolDown(0);
    return;
}
inline void
RigidBody::AddTorque(const rw::math::Vector3 &af, const InputSpace spc)
{
    ;
    ;
    AddAngularImpulse(af * m_stasis->GetTimeStep(), spc);
    return;
}
inline void
RigidBody::AddLocalDisplacement(const rw::math::Vector3 &ld, const InputSpace dspc,
                                const rw::math::Vector3 &pos, const InputSpace pspc)
{
    ;
    ;
    rw::math::Vector3 fwrd;
    if(dspc == WORLD_SPACE)
    {
        fwrd = ld;
    }
    else
    {
        fwrd = rw::math::Vector3(m_ri * (float32_t)static_cast<float>(ld.X()) + m_up * (float32_t)static_cast<float>(ld.Y()) + m_at * (float32_t)ld.Z());
    }
    rw::math::Vector3 fpos;
    if(pspc == WORLD_SPACE)
    {
        fpos = pos;
    }
    else
    {
        fpos = rw::math::Vector3(m_ri * (float32_t)static_cast<float>(pos.X()) + m_up * (float32_t)static_cast<float>(pos.Y()) + m_at * (float32_t)pos.Z());
    }
    m_force += rw::math::fpu::Vector3U_32(fwrd);
    rw::math::Vector3 adsp = rw::math::Cross(fpos, fwrd) / GetInverseMass();
    m_torque.X() =static_cast<float>(m_torque.X()) + static_cast<float>(m_Ifull.X()) * static_cast<float>(adsp.X()) + static_cast<float>(m_Ifull.Y()) * static_cast<float>(adsp.Y()) + static_cast<float>(m_Ifull.Z()) * static_cast<float>(adsp.Z());
    m_torque.Y() =static_cast<float>(m_torque.Y()) + static_cast<float>(m_Ifull.Y()) * static_cast<float>(adsp.X()) + static_cast<float>(m_Isplt.Y()) * static_cast<float>(adsp.Y()) + static_cast<float>(m_Isplt.Z()) * static_cast<float>(adsp.Z());
    m_torque.Z() =static_cast<float>(m_torque.Z()) + static_cast<float>(m_Ifull.Z()) * static_cast<float>(adsp.X()) + static_cast<float>(m_Isplt.Z()) * static_cast<float>(adsp.Y()) + static_cast<float>(m_Isplt.X()) * static_cast<float>(adsp.Z());
    SetCoolDown(0);
    return;
}
inline void
RigidBody::AddLocalImpulse(const rw::math::Vector3 &li, const InputSpace dspc,
                           const rw::math::Vector3 &pos, const InputSpace pspc)
{
    ;
    ;
    rw::math::Vector3 fwrd;
    if(dspc == WORLD_SPACE)
    {
        fwrd = li;
    }
    else
    {
        fwrd = rw::math::Vector3(m_ri * (float32_t)static_cast<float>(li.X()) + m_up * (float32_t)static_cast<float>(li.Y()) + m_at * (float32_t)li.Z());
    }
    rw::math::Vector3 fpos;
    if(pspc == WORLD_SPACE)
    {
        fpos = pos;
    }
    else
    {
        fpos = rw::math::Vector3(m_ri * (float32_t)static_cast<float>(pos.X()) + m_up * (float32_t)static_cast<float>(pos.Y()) + m_at * (float32_t)pos.Z());
    }
    float32_t scale = m_stasis->GetTimeStep();
    m_force += rw::math::fpu::Vector3U_32(fwrd * scale);
    rw::math::Vector3 adsp = rw::math::Cross(fpos, fwrd) * scale;
    m_torque.X() =static_cast<float>(m_torque.X()) + static_cast<float>(m_Ifull.X()) * static_cast<float>(adsp.X()) + static_cast<float>(m_Ifull.Y()) * static_cast<float>(adsp.Y()) + static_cast<float>(m_Ifull.Z()) * static_cast<float>(adsp.Z());
    m_torque.Y() =static_cast<float>(m_torque.Y()) + static_cast<float>(m_Ifull.Y()) * static_cast<float>(adsp.X()) + static_cast<float>(m_Isplt.Y()) * static_cast<float>(adsp.Y()) + static_cast<float>(m_Isplt.Z()) * static_cast<float>(adsp.Z());
    m_torque.Z() =static_cast<float>(m_torque.Z()) + static_cast<float>(m_Ifull.Z()) * static_cast<float>(adsp.X()) + static_cast<float>(m_Isplt.Z()) * static_cast<float>(adsp.Y()) + static_cast<float>(m_Isplt.X()) * static_cast<float>(adsp.Z());
    SetCoolDown(0);
    return;
}
inline void
RigidBody::AddLocalForce(const rw::math::Vector3 &lf, const InputSpace dspc,
                         const rw::math::Vector3 &pos, const InputSpace pspc)
{
    ;
    ;
    AddLocalImpulse(lf * GetInverseMass() * m_stasis->GetTimeStep(), dspc, pos, pspc);
    return;
}
inline Simulation *
RigidBody::GetSimulation(void) const
{
    ;
    return m_stasis;
}
inline RigidBody *
RigidBody::GetRight(void) const
{
    ;
    return RigidBody::AddressFromOffset(m_stasis, m_right);
}
inline RigidBody *
RigidBody::GetLeft(void) const
{
    ;
    return RigidBody::AddressFromOffset(m_stasis, m_left);
}
inline uint32_t
RigidBody::GetReactionForcesId(void) const
{
    ;
    return m_Id;
}
inline void
RigidBody::SetSimulation(Simulation *stasis)
{
    ;
    ;
    m_stasis = stasis;
    return;
}
inline void
RigidBody::SetRight(RigidBody *ri)
{
    ;
    ;
    m_right = ri->OffsetFromAddress();
    return;
}
inline void
RigidBody::SetLeft(RigidBody *le)
{
    ;
    ;
    m_left = le->OffsetFromAddress();
    return;
}
inline void
RigidBody::Move(RigidBody *src)
{
    ;
    ;
    RigidBody::AddressFromOffset(m_stasis, m_right)->m_left = m_left;
    RigidBody::AddressFromOffset(m_stasis, m_left)->m_right = m_right;
    m_right = src->OffsetFromAddress();
    m_left = src->GetLeft()->OffsetFromAddress();
    src->m_left = src->GetLeft()->m_right = OffsetFromAddress();
    return;
}
inline void
RigidBody::SetStatic(const rw::math::Matrix44Affine &m)
{
    ;
    m_inertia = 0;
    SetState(STATIC_BODY);
    SetTransform(m);
    rw::math::VecFloat zero(rw::math::GetVecFloat_Zero());
    ((rw::math::Vector3Plus &)m_dsp ).SetVector3(zero.GetVector());
    ((rw::math::Vector3Plus &)m_omega ).SetVector3(zero.GetVector());
    ((rw::math::Vector3Plus &)m_torque).SetVector3(zero.GetVector());
    rw::math::Vector3Plus &force_kine((rw::math::Vector3Plus &)m_force);
    force_kine.SetVector3(zero.GetVector());
    force_kine.SetPlus(zero);
    return;
}
inline void
RigidBody::SetDynamic(const rw::math::Matrix44Affine &m, Inertia *ine)
{
    ;
    ;
    m_inertia = ine;
    SetTransform(m);
    rw::math::VecFloat zero(rw::math::GetVecFloat_Zero());
    ((rw::math::Vector3Plus &)m_dsp ).SetVector3(zero.GetVector());
    ((rw::math::Vector3Plus &)m_omega ).SetVector3(zero.GetVector());
    m_kine = rw::math::MAX_FLOAT;
    ResetForces();
    return;
}
inline void
RigidBody::SetState(const BodyState state)
{
    ;
    m_state = state;
    return;
}
inline void
RigidBody::SetReactionForcesId(const uint32_t id)
{
    ;
    m_Id = id;
    return;
}
inline void
RigidBody::DynamicUpdate(void)
{
    ;
    rw::math::Vector3 dsp_grav = m_stasis->GetDisplacementThroughGravity();
    DynamicUpdate(m_inertia,
                  m_stasis->GetReactionForces(),
                  m_stasis->GetFreezingEnergy(),
                  m_stasis->GetCoolDown(),
                  dsp_grav);
    return;
}
}
}






namespace rw
{
namespace physics
{
inline rw::ResourceDescriptor
Joint::GetResourceDescriptor()
{
    ;
    uint32_t size = (((sizeof(Joint)) + ((16) - 1)) & ~((16) - 1));
    return rw::ResourceDescriptor(size, 16);
}

inline Joint *
Joint::AddressFromOffset(Simulation *, const int32_t off)
{
    ;
    return (Joint*)off;
}









inline int32_t
Joint::OffsetFromAddress(void) const
{
    ;
    return (int32_t)this;
}










inline RigidBody *
Joint::GetParent(void) const
{
    ;

    return RigidBody::AddressFromOffset(0, m_bodyB);



}
inline RigidBody *
Joint::GetChild(void) const
{
    ;

    return RigidBody::AddressFromOffset(0, m_bodyA);



}
inline JointFrames *
Joint::GetFrames(void) const
{
    ;
    return m_skel;
}
inline JointLimits *
Joint::GetLimits(void) const
{
    ;
    return m_limit;
}
inline uint32_t
Joint::GetTag(void) const
{
    ;
    return m_tag;
}
inline RwBool
Joint::GetSpy(void) const
{
    ;
    return m_spy;
}
inline void
Joint::SetParent(RigidBody *b)
{
    ;
    ;
    m_bodyB = b->OffsetFromAddress();
    return;
}
inline void
Joint::SetChild(RigidBody *b)
{
    ;
    ;
    m_bodyA = b->OffsetFromAddress();
    return;
}
inline void
Joint::SetFrames(JointFrames *js)
{
    ;
    ;
    m_skel = js;
    return;
}
inline void
Joint::SetLimits(JointLimits *jl)
{
    ;
    ;
    m_limit = jl;
    return;
}
inline void
Joint::SetTag(const uint32_t tag)
{
    ;
    m_tag = tag;
    return;
}
inline void
Joint::SetSpy(const RwBool on_off)
{
    ;
    m_spy = on_off;
    return;
}
inline Joint *
Joint::GetRight(void) const
{
    ;

    return Joint::AddressFromOffset(0, m_right);



}
inline Joint *
Joint::GetLeft(void) const
{
    ;

    return Joint::AddressFromOffset(0, m_left);



}
inline void
Joint::SetRight(Joint *ri)
{
    ;
    ;
    m_right = ri->OffsetFromAddress();
    return;
}
inline void
Joint::SetLeft(Joint *le)
{
    ;
    ;
    m_left = le->OffsetFromAddress();
    return;
}
inline void
Joint::Move(Joint *src)
{
    ;
    ;

    Joint::AddressFromOffset(0, m_right)->m_left = m_left;
    Joint::AddressFromOffset(0, m_left)->m_right = m_right;




    m_right = src->OffsetFromAddress();
    m_left = src->GetLeft()->OffsetFromAddress();
    src->m_left = src->GetLeft()->m_right = OffsetFromAddress();
    return;
}










inline void
Joint::Initialize(RigidBody *pa, RigidBody *ch, JointFrames *sk, JointLimits *jl)
{
    ;
    ;
    ;
    ;
    ;
    m_skel = sk;
    m_limit = jl;
    m_bodyB = pa->OffsetFromAddress();
    m_bodyA = ch->OffsetFromAddress();
    m_spy = (0);
    return;
}
}
}






namespace rw
{
namespace physics
{
inline rw::ResourceDescriptor
Drive::GetResourceDescriptor()
{
    ;
    uint32_t size = (((sizeof(Drive)) + ((16) - 1)) & ~((16) - 1));
    return rw::ResourceDescriptor(size, 16);
}

inline Drive *
Drive::AddressFromOffset(Simulation *, const int32_t off)
{
    ;
    return (Drive*)off;
}









inline int32_t
Drive::OffsetFromAddress(void) const
{
    ;
    return (int32_t)this;
}










inline RigidBody *
Drive::GetParent(void) const
{
    ;

    return RigidBody::AddressFromOffset(0, m_bodyB);



}
inline RigidBody *
Drive::GetChild(void) const
{
    ;

    return RigidBody::AddressFromOffset(0, m_bodyA);



}
inline DriveFrames *
Drive::GetFrames(void) const
{
    ;
    return m_skel;
}
inline DriveDynamics *
Drive::GetDynamics(void) const
{
    ;
    return m_crtl;
}
inline uint32_t
Drive::GetTag(void) const
{
    ;
    return m_tag;
}
inline RwBool
Drive::GetSpy(void) const
{
    ;
    return m_spy;
}
inline void
Drive::SetParent(RigidBody *b)
{
    ;
    ;
    m_bodyB = b->OffsetFromAddress();
    return;
}
inline void
Drive::SetChild(RigidBody *b)
{
    ;
    ;
    m_bodyA = b->OffsetFromAddress();
    return;
}
inline void
Drive::SetFrames(DriveFrames *ds)
{
    ;
    ;
    m_skel = ds;
    return;
}
inline void
Drive::SetDynamics(DriveDynamics *dd)
{
    ;
    ;
    m_crtl = dd;
    return;
}
inline void
Drive::SetTag(const uint32_t tag)
{
    ;
    m_tag = tag;
    return;
}
inline void
Drive::SetSpy(const RwBool on_off)
{
    ;
    m_spy = on_off;
    return;
}
inline Drive *
Drive::GetRight(void) const
{
    ;

    return Drive::AddressFromOffset(0, m_right);



}
inline Drive *
Drive::GetLeft(void) const
{
    ;

    return Drive::AddressFromOffset(0, m_left);



}
inline void
Drive::SetRight(Drive *ri)
{
    ;
    ;
    m_right = ri->OffsetFromAddress();
    return;
}
inline void
Drive::SetLeft(Drive *le)
{
    ;
    ;
    m_left = le->OffsetFromAddress();
    return;
}
inline void
Drive::Move(Drive *src)
{
    ;
    ;

    Drive::AddressFromOffset(0, m_right)->m_left = m_left;
    Drive::AddressFromOffset(0, m_left)->m_right = m_right;




    m_right = src->OffsetFromAddress();
    m_left = src->GetLeft()->OffsetFromAddress();
    src->m_left = src->GetLeft()->m_right = OffsetFromAddress();
    return;
}










inline void
Drive::Initialize(RigidBody *pa, RigidBody *ch, DriveFrames *sk, DriveDynamics *dd)
{
    ;
    ;
    ;
    ;
    ;
    m_skel = sk;
    m_crtl = dd;
    m_bodyB = pa->OffsetFromAddress();
    m_bodyA = ch->OffsetFromAddress();
    m_spy = (0);
    return;
}
}
}






namespace rw
{
namespace physics
{
inline rw::ResourceDescriptor
Contact::GetResourceDescriptor()
{
    ;
    uint32_t size = (((sizeof(Contact)) + ((128) - 1)) & ~((128) - 1));
    return rw::ResourceDescriptor(size, 128);
}
inline RigidBody *
Contact::GetBodyA(Simulation *stasis) const
{
    ;
    return RigidBody::AddressFromOffset(stasis, m_bodyA);
}
inline RigidBody *
Contact::GetBodyB(Simulation *stasis) const
{
    ;
    return RigidBody::AddressFromOffset(stasis, m_bodyB);
}
inline uint32_t
Contact::GetTag(void) const
{
    ;
    return m_tag;
}
inline rw::math::Vector3
Contact::GetPositionOnA(void) const
{
    ;
    return (rw::math::Vector3&)m_posA;
}
inline rw::math::Vector3
Contact::GetPositionOnB(void) const
{
    ;
    return (rw::math::Vector3&)m_posB;
}
inline rw::math::Vector3
Contact::GetDisplacement(void) const
{
    ;
    return (rw::math::Vector3&)m_dsp;
}
inline rw::math::Matrix33
Contact::GetFrame(void) const
{
    ;
    return (rw::math::Matrix33&)m_ri;
}
inline float32_t
Contact::GetStaticFriction(void) const
{
    ;
    return m_mus;
}
inline float32_t
Contact::GetDynamicFriction(void) const
{
    ;
    return m_mud;
}
inline float32_t
Contact::GetRestitution(void) const
{
    ;
    return m_res;
}
inline void
Contact::SetBodyA(RigidBody *ba)
{
    ;
    ;
    m_bodyA = ba->OffsetFromAddress();
    return;
}
inline void
Contact::SetBodyB(RigidBody *bb)
{
    ;
    ;
    m_bodyB = bb->OffsetFromAddress();
    return;
}
inline void
Contact::SetTag(const uint32_t tag)
{
    ;
    m_tag = tag;
    return;
}
inline void
Contact::SetPositionOnA(const rw::math::Vector3 &p)
{
    ;
    (__attribute__((altivec(vector__))) float&)m_posA = vec_sel((__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float&)m_posA, (__attribute__((altivec(vector__))) float)p.GetVector(), (__attribute__((altivec(vector__))) unsigned int)(__attribute__((altivec(vector__))) unsigned int)Select_1110);
    return;
}
inline void
Contact::SetPositionOnB(const rw::math::Vector3 &p)
{
    ;
    (__attribute__((altivec(vector__))) float&)m_posB = vec_sel((__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float&)m_posB, (__attribute__((altivec(vector__))) float)p.GetVector(), (__attribute__((altivec(vector__))) unsigned int)(__attribute__((altivec(vector__))) unsigned int)Select_1110);
    return;
}
inline void
Contact::SetFrame(const rw::math::Matrix33 &m)
{
    ;
    (__attribute__((altivec(vector__))) float&)m_ri = vec_sel((__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float&)m_ri, (__attribute__((altivec(vector__))) float)m.XAxis().GetVector(), (__attribute__((altivec(vector__))) unsigned int)(__attribute__((altivec(vector__))) unsigned int)Select_1110);
    (__attribute__((altivec(vector__))) float&)m_up = vec_sel((__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float&)m_up, (__attribute__((altivec(vector__))) float)m.YAxis().GetVector(), (__attribute__((altivec(vector__))) unsigned int)(__attribute__((altivec(vector__))) unsigned int)Select_1110);
    (__attribute__((altivec(vector__))) float&)m_at = vec_sel((__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float&)m_at, (__attribute__((altivec(vector__))) float)m.ZAxis().GetVector(), (__attribute__((altivec(vector__))) unsigned int)(__attribute__((altivec(vector__))) unsigned int)Select_1110);
    return;
}
inline void
Contact::GenerateFrame(const rw::math::Vector3 &normal)
{
    ;
    __attribute__((altivec(vector__))) float * __restrict__ contact = (__attribute__((altivec(vector__))) float * __restrict__)this;
    __attribute__((altivec(vector__))) float dst_c_ri = normal.GetVector();
    __attribute__((altivec(vector__))) float dst_ri_z = vec_splat((__attribute__((altivec(vector__))) float)dst_c_ri, (char)2);
    __attribute__((altivec(vector__))) float dst_ri_x = vec_splat((__attribute__((altivec(vector__))) float)dst_c_ri, (char)0);
    __attribute__((altivec(vector__))) float dot_c_ri = vec_nmsub((__attribute__((altivec(vector__))) float)dst_ri_x, (__attribute__((altivec(vector__))) float)dst_ri_x, (__attribute__((altivec(vector__))) float)OneHalf);
    __attribute__((altivec(vector__))) float tmp_at_1 = vec_nmsub((__attribute__((altivec(vector__))) float)dst_c_ri, (__attribute__((altivec(vector__))) float)dst_ri_z, (__attribute__((altivec(vector__))) float)Identity_R2);
    __attribute__((altivec(vector__))) float dst_at_2 = vec_nmsub((__attribute__((altivec(vector__))) float)dst_c_ri, (__attribute__((altivec(vector__))) float)dst_ri_x, (__attribute__((altivec(vector__))) float)Identity_R0);
    __attribute__((altivec(vector__))) float flag_nrm = (__attribute__((altivec(vector__))) float)vec_cmpge((__attribute__((altivec(vector__))) float)dot_c_ri, (__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float)NegativeZero);
    __attribute__((altivec(vector__))) float nrm_at_1 = vec_splat((__attribute__((altivec(vector__))) float)tmp_at_1, (char)2);
    __attribute__((altivec(vector__))) float nrm_at_2 = vec_splat((__attribute__((altivec(vector__))) float)dst_at_2, (char)0);
    __attribute__((altivec(vector__))) float dst_at_1 = vec_xor(tmp_at_1, (__attribute__((altivec(vector__))) float)NegativeZero);
    __attribute__((altivec(vector__))) float nrm_c_at = vec_sel((__attribute__((altivec(vector__))) float)nrm_at_1, (__attribute__((altivec(vector__))) float)nrm_at_2, (__attribute__((altivec(vector__))) unsigned int)(__attribute__((altivec(vector__))) unsigned int)flag_nrm);
    __attribute__((altivec(vector__))) float dst_c_at = vec_sel((__attribute__((altivec(vector__))) float)dst_at_1, (__attribute__((altivec(vector__))) float)dst_at_2, (__attribute__((altivec(vector__))) unsigned int)(__attribute__((altivec(vector__))) unsigned int)flag_nrm);
    __attribute__((altivec(vector__))) float estimate = vec_rsqrte((__attribute__((altivec(vector__))) float)nrm_c_at);
    __attribute__((altivec(vector__))) float cross_a1 = vec_perm((__attribute__((altivec(vector__))) float)dst_c_at, (__attribute__((altivec(vector__))) float)dst_c_at, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_YZXW);
    __attribute__((altivec(vector__))) float cross_b2 = vec_perm((__attribute__((altivec(vector__))) float)dst_c_ri, (__attribute__((altivec(vector__))) float)dst_c_ri, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_ZXYW);
    __attribute__((altivec(vector__))) float cross_a2 = vec_perm((__attribute__((altivec(vector__))) float)dst_c_at, (__attribute__((altivec(vector__))) float)dst_c_at, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_ZXYW);
    __attribute__((altivec(vector__))) float cross_b1 = vec_perm((__attribute__((altivec(vector__))) float)dst_c_ri, (__attribute__((altivec(vector__))) float)dst_c_ri, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_YZXW);
    __attribute__((altivec(vector__))) float dst_c_up = vec_madd((__attribute__((altivec(vector__))) float)cross_a1, (__attribute__((altivec(vector__))) float)cross_b2, (__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float)NegativeZero);
    dst_c_up = vec_nmsub((__attribute__((altivec(vector__))) float)cross_a2, (__attribute__((altivec(vector__))) float)cross_b1, (__attribute__((altivec(vector__))) float)dst_c_up);
    dst_c_at = vec_madd((__attribute__((altivec(vector__))) float)dst_c_at, (__attribute__((altivec(vector__))) float)estimate, (__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float)NegativeZero);
    dst_c_up = vec_madd((__attribute__((altivec(vector__))) float)dst_c_up, (__attribute__((altivec(vector__))) float)estimate, (__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float)NegativeZero);
    contact[0x2] = vec_sel((__attribute__((altivec(vector__))) float)contact[0x2], (__attribute__((altivec(vector__))) float)dst_c_ri, (__attribute__((altivec(vector__))) unsigned int)(__attribute__((altivec(vector__))) unsigned int)Select_1110);
    contact[0x3] = vec_sel((__attribute__((altivec(vector__))) float)contact[0x3], (__attribute__((altivec(vector__))) float)dst_c_up, (__attribute__((altivec(vector__))) unsigned int)(__attribute__((altivec(vector__))) unsigned int)Select_1110);
    contact[0x4] = vec_sel((__attribute__((altivec(vector__))) float)contact[0x4], (__attribute__((altivec(vector__))) float)dst_c_at, (__attribute__((altivec(vector__))) unsigned int)(__attribute__((altivec(vector__))) unsigned int)Select_1110);
    return;
}
inline void
Contact::SetFriction(const float32_t s, const float32_t d)
{
    ;
    ;
    ;
    ;
    m_mus = s;
    m_mud = d;
    return;
}
inline void
Contact::SetRestitution(const float32_t r)
{
    ;
    ;
    ;
    m_res = r;
    return;
}
inline void
Contact::SetDisplacement(const rw::math::Vector3 &d)
{
    ;
    (__attribute__((altivec(vector__))) float&)m_dsp = vec_sel((__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float&)m_dsp, (__attribute__((altivec(vector__))) float)d.GetVector(), (__attribute__((altivec(vector__))) unsigned int)(__attribute__((altivec(vector__))) unsigned int)Select_1110);
    return;
}
inline void
Contact::GenerateFromCollision(RigidBody * ba, RigidBody * bb,
                               const rw::math::Vector3 &posa,
                               const rw::math::Vector3 &posb,
                               const rw::math::Vector3 &normal)
{
    ;
    Contact::GenerateFromCollision(ba, bb, posa, posb, normal,
        GetStaticFriction(),
        GetDynamicFriction(),
        GetRestitution(),
        GetTag());
    return;
}
inline void
Contact::GenerateFromCollision(RigidBody *ba, RigidBody *bb,
                               const rw::math::Vector3 &posa,
                               const rw::math::Vector3 &posb,
                               const rw::math::Vector3 &normal,
                               const float32_t staticFriction,
                               const float32_t dynamicFriction,
                               const float32_t restitution,
                               const uint32_t tag)
{
    ;
    ;
    ;


    vector_union * __restrict__ contact = (vector_union * __restrict__)this;

    do { uint64_t __dcbz128_offset = 0x000; const void* __dcbz128_ptr = contact; __asm__ volatile ( "dcbz %0, %1" : : [__dcbz128_offset] "r" (__dcbz128_offset), [__dcbz128_ptr] "r" (__dcbz128_ptr) ); } while((0));
    do { uint64_t __dcbz128_offset = 0x080; const void* __dcbz128_ptr = contact; __asm__ volatile ( "dcbz %0, %1" : : [__dcbz128_offset] "r" (__dcbz128_offset), [__dcbz128_ptr] "r" (__dcbz128_ptr) ); } while((0));

    __attribute__((altivec(vector__))) float * __restrict__ rbody_a = (__attribute__((altivec(vector__))) float * __restrict__)ba;
    __attribute__((altivec(vector__))) float * __restrict__ rbody_b = (__attribute__((altivec(vector__))) float * __restrict__)bb;
    __attribute__((altivec(vector__))) float dst_posa = posa.GetVector();
    __attribute__((altivec(vector__))) float dst_posb = posb.GetVector();
    __attribute__((altivec(vector__))) float dst_c_ri = normal.GetVector();
    __attribute__((altivec(vector__))) float rba_cpos = vec_sub((__attribute__((altivec(vector__))) float)dst_posa, (__attribute__((altivec(vector__))) float)rbody_a[0x1]);
    __attribute__((altivec(vector__))) float rbb_cpos = vec_sub((__attribute__((altivec(vector__))) float)dst_posb, (__attribute__((altivec(vector__))) float)rbody_b[0x1]);
    __attribute__((altivec(vector__))) float src_omga = rbody_a[0x3];
    __attribute__((altivec(vector__))) float src_omgb = rbody_b[0x3];
    __attribute__((altivec(vector__))) float vec_zero = (__attribute__((altivec(vector__))) float)vec_splat_s8(0);
    __attribute__((altivec(vector__))) float bd_filtr = (__attribute__((altivec(vector__))) float)vec_splat_s32(ACTIVE_BODY);
    __attribute__((altivec(vector__))) float flag_rba = vec_splat((__attribute__((altivec(vector__))) float)rbody_a[0x8], (char)3);
    contact[0x0].vecf = dst_posa;
    contact[0x1].vecf = dst_posb;
    contact[0x0].i[3] = (int32_t)ba->OffsetFromAddress();
    contact[0x1].i[3] = (int32_t)bb->OffsetFromAddress();
    flag_rba = vec_and(flag_rba, bd_filtr);
    __attribute__((altivec(vector__))) float cposa_c1 = vec_perm((__attribute__((altivec(vector__))) float)rba_cpos, (__attribute__((altivec(vector__))) float)rba_cpos, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_YZXW);
    __attribute__((altivec(vector__))) float cposb_c1 = vec_perm((__attribute__((altivec(vector__))) float)rbb_cpos, (__attribute__((altivec(vector__))) float)rbb_cpos, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_YZXW);
    __attribute__((altivec(vector__))) float cnorm_c2 = vec_perm((__attribute__((altivec(vector__))) float)dst_c_ri, (__attribute__((altivec(vector__))) float)dst_c_ri, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_ZXYW);
    __attribute__((altivec(vector__))) float comga_c2 = vec_perm((__attribute__((altivec(vector__))) float)src_omga, (__attribute__((altivec(vector__))) float)src_omga, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_ZXYW);
    __attribute__((altivec(vector__))) float comgb_c2 = vec_perm((__attribute__((altivec(vector__))) float)src_omgb, (__attribute__((altivec(vector__))) float)src_omgb, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_ZXYW);
    __attribute__((altivec(vector__))) float dst_at_a = vec_nmsub((__attribute__((altivec(vector__))) float)cposa_c1, (__attribute__((altivec(vector__))) float)cnorm_c2, (__attribute__((altivec(vector__))) float)vec_zero);
    __attribute__((altivec(vector__))) float dst_at_b = vec_nmsub((__attribute__((altivec(vector__))) float)cposb_c1, (__attribute__((altivec(vector__))) float)cnorm_c2, (__attribute__((altivec(vector__))) float)vec_zero);
    __attribute__((altivec(vector__))) float ct_dsp_a = vec_nmsub((__attribute__((altivec(vector__))) float)cposa_c1, (__attribute__((altivec(vector__))) float)comga_c2, (__attribute__((altivec(vector__))) float)rbody_a[0x2]);
    __attribute__((altivec(vector__))) float ct_dsp_b = vec_nmsub((__attribute__((altivec(vector__))) float)cposb_c1, (__attribute__((altivec(vector__))) float)comgb_c2, (__attribute__((altivec(vector__))) float)rbody_b[0x2]);
    flag_rba = (__attribute__((altivec(vector__))) float)vec_cmpeq((__attribute__((altivec(vector__))) unsigned int)flag_rba, (__attribute__((altivec(vector__))) unsigned int)bd_filtr);
    __attribute__((altivec(vector__))) float cposa_c2 = vec_perm((__attribute__((altivec(vector__))) float)rba_cpos, (__attribute__((altivec(vector__))) float)rba_cpos, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_ZXYW);
    __attribute__((altivec(vector__))) float cposb_c2 = vec_perm((__attribute__((altivec(vector__))) float)rbb_cpos, (__attribute__((altivec(vector__))) float)rbb_cpos, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_ZXYW);
    __attribute__((altivec(vector__))) float cnorm_c1 = vec_perm((__attribute__((altivec(vector__))) float)dst_c_ri, (__attribute__((altivec(vector__))) float)dst_c_ri, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_YZXW);
    __attribute__((altivec(vector__))) float comga_c1 = vec_perm((__attribute__((altivec(vector__))) float)src_omga, (__attribute__((altivec(vector__))) float)src_omga, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_YZXW);
    __attribute__((altivec(vector__))) float comgb_c1 = vec_perm((__attribute__((altivec(vector__))) float)src_omgb, (__attribute__((altivec(vector__))) float)src_omgb, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_YZXW);
    dst_at_a = vec_madd((__attribute__((altivec(vector__))) float)cposa_c2, (__attribute__((altivec(vector__))) float)cnorm_c1, (__attribute__((altivec(vector__))) float)dst_at_a);
    dst_at_b = vec_madd((__attribute__((altivec(vector__))) float)cposb_c2, (__attribute__((altivec(vector__))) float)cnorm_c1, (__attribute__((altivec(vector__))) float)dst_at_b);
    ct_dsp_a = vec_madd((__attribute__((altivec(vector__))) float)cposa_c2, (__attribute__((altivec(vector__))) float)comga_c1, (__attribute__((altivec(vector__))) float)ct_dsp_a);
    ct_dsp_b = vec_madd((__attribute__((altivec(vector__))) float)cposb_c2, (__attribute__((altivec(vector__))) float)comgb_c1, (__attribute__((altivec(vector__))) float)ct_dsp_b);
    __attribute__((altivec(vector__))) float dst_at_3 = vec_sel((__attribute__((altivec(vector__))) float)dst_at_b, (__attribute__((altivec(vector__))) float)dst_at_a, (__attribute__((altivec(vector__))) unsigned int)(__attribute__((altivec(vector__))) unsigned int)flag_rba);
    __attribute__((altivec(vector__))) float ctx_dspl = vec_sub((__attribute__((altivec(vector__))) float)ct_dsp_b, (__attribute__((altivec(vector__))) float)ct_dsp_a);
    __attribute__((altivec(vector__))) float splat_nx = vec_splat((__attribute__((altivec(vector__))) float)dst_at_3, (char)0);
    __attribute__((altivec(vector__))) float dst_ri_x = vec_splat((__attribute__((altivec(vector__))) float)dst_c_ri, (char)0);
    __attribute__((altivec(vector__))) float dst_ri_z = vec_splat((__attribute__((altivec(vector__))) float)dst_c_ri, (char)2);
    __attribute__((altivec(vector__))) float nrm_at_3 = vec_madd((__attribute__((altivec(vector__))) float)splat_nx, (__attribute__((altivec(vector__))) float)splat_nx, (__attribute__((altivec(vector__))) float)vec_zero);
    __attribute__((altivec(vector__))) float splat_ny = vec_splat((__attribute__((altivec(vector__))) float)dst_at_3, (char)1);
    __attribute__((altivec(vector__))) float splat_nz = vec_splat((__attribute__((altivec(vector__))) float)dst_at_3, (char)2);
    __attribute__((altivec(vector__))) float dot_c_ri = vec_nmsub((__attribute__((altivec(vector__))) float)dst_ri_x, (__attribute__((altivec(vector__))) float)dst_ri_x, (__attribute__((altivec(vector__))) float)OneHalf);
    nrm_at_3 = vec_madd((__attribute__((altivec(vector__))) float)splat_ny, (__attribute__((altivec(vector__))) float)splat_ny, (__attribute__((altivec(vector__))) float)nrm_at_3);
    __attribute__((altivec(vector__))) float tmp_at_1 = vec_nmsub((__attribute__((altivec(vector__))) float)dst_c_ri, (__attribute__((altivec(vector__))) float)dst_ri_z, (__attribute__((altivec(vector__))) float)Identity_R2);
    __attribute__((altivec(vector__))) float dst_at_2 = vec_nmsub((__attribute__((altivec(vector__))) float)dst_c_ri, (__attribute__((altivec(vector__))) float)dst_ri_x, (__attribute__((altivec(vector__))) float)Identity_R0);
    __attribute__((altivec(vector__))) float dst_at_1 = vec_xor(tmp_at_1, (__attribute__((altivec(vector__))) float)NegativeZero);
    nrm_at_3 = vec_madd((__attribute__((altivec(vector__))) float)splat_nz, (__attribute__((altivec(vector__))) float)splat_nz, (__attribute__((altivec(vector__))) float)nrm_at_3);
    __attribute__((altivec(vector__))) float nrm_at_1 = vec_splat((__attribute__((altivec(vector__))) float)tmp_at_1, (char)2);
    __attribute__((altivec(vector__))) float nrm_at_2 = vec_splat((__attribute__((altivec(vector__))) float)dst_at_2, (char)0);
    __attribute__((altivec(vector__))) float flag_nrm = (__attribute__((altivec(vector__))) float)vec_cmpge((__attribute__((altivec(vector__))) float)dot_c_ri, (__attribute__((altivec(vector__))) float)(__attribute__((altivec(vector__))) float)NegativeZero);
    __attribute__((altivec(vector__))) float test_nrm = (__attribute__((altivec(vector__))) float)vec_cmpge((__attribute__((altivec(vector__))) float)nrm_at_3, (__attribute__((altivec(vector__))) float)Tolerance_Normal);
    __attribute__((altivec(vector__))) float dst_c_at = vec_sel((__attribute__((altivec(vector__))) float)dst_at_1, (__attribute__((altivec(vector__))) float)dst_at_2, (__attribute__((altivec(vector__))) unsigned int)(__attribute__((altivec(vector__))) unsigned int)flag_nrm);
    __attribute__((altivec(vector__))) float nrm_c_at = vec_sel((__attribute__((altivec(vector__))) float)nrm_at_1, (__attribute__((altivec(vector__))) float)nrm_at_2, (__attribute__((altivec(vector__))) unsigned int)(__attribute__((altivec(vector__))) unsigned int)flag_nrm);
    dst_c_at = vec_sel((__attribute__((altivec(vector__))) float)dst_c_at, (__attribute__((altivec(vector__))) float)dst_at_3, (__attribute__((altivec(vector__))) unsigned int)(__attribute__((altivec(vector__))) unsigned int)test_nrm);
    nrm_c_at = vec_sel((__attribute__((altivec(vector__))) float)nrm_c_at, (__attribute__((altivec(vector__))) float)nrm_at_3, (__attribute__((altivec(vector__))) unsigned int)(__attribute__((altivec(vector__))) unsigned int)test_nrm);
    __attribute__((altivec(vector__))) float estimate = vec_rsqrte((__attribute__((altivec(vector__))) float)nrm_c_at);
    __attribute__((altivec(vector__))) float cross_a1 = vec_perm((__attribute__((altivec(vector__))) float)dst_c_at, (__attribute__((altivec(vector__))) float)dst_c_at, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_YZXW);
    __attribute__((altivec(vector__))) float cross_a2 = vec_perm((__attribute__((altivec(vector__))) float)dst_c_at, (__attribute__((altivec(vector__))) float)dst_c_at, (__attribute__((altivec(vector__))) unsigned char)(__attribute__((altivec(vector__))) unsigned char)Swizzle_ZXYW);
    __attribute__((altivec(vector__))) float dst_c_up = vec_madd((__attribute__((altivec(vector__))) float)cross_a1, (__attribute__((altivec(vector__))) float)cnorm_c2, (__attribute__((altivec(vector__))) float)vec_zero);
    dst_c_up = vec_nmsub((__attribute__((altivec(vector__))) float)cross_a2, (__attribute__((altivec(vector__))) float)cnorm_c1, (__attribute__((altivec(vector__))) float)dst_c_up);
    dst_c_up = vec_madd((__attribute__((altivec(vector__))) float)dst_c_up, (__attribute__((altivec(vector__))) float)estimate, (__attribute__((altivec(vector__))) float)vec_zero);
    dst_c_at = vec_madd((__attribute__((altivec(vector__))) float)dst_c_at, (__attribute__((altivec(vector__))) float)estimate, (__attribute__((altivec(vector__))) float)vec_zero);
    contact[0x2].vecf = dst_c_ri;
    contact[0x3].vecf = dst_c_up;
    contact[0x4].vecf = dst_c_at;
    contact[0x5].vecf = ctx_dspl;
    contact[0x2].f[3] = restitution;
    contact[0x3].f[3] = staticFriction;
    contact[0x4].f[3] = dynamicFriction;
    contact[0x5].u[3] = tag;
    contact[0x6].vecf = rbody_a[0x1];
    contact[0x7].vecf = rbody_b[0x1];
    contact[0x8].vecf = rbody_a[0x7];
    contact[0x9].vecf = rbody_b[0x7];
    contact[0xA].vecf = rbody_a[0x8];
    contact[0xB].vecf = rbody_b[0x8];
    contact[0xC].vecf = rbody_a[0x9];
    contact[0xD].vecf = rbody_b[0x9];
    contact[0xE].vecf = rbody_a[0xA];
    contact[0xF].vecf = rbody_b[0xA];






































































































    return;
}
}
}






namespace rw
{
namespace physics
{
inline rw::ResourceDescriptor
JointSpy::GetResourceDescriptor()
{
    ;
    uint32_t size = (((sizeof(JointSpy)) + ((16) - 1)) & ~((16) - 1));
    return rw::ResourceDescriptor(size, 16);
}
inline Joint *
JointSpy::GetJoint(Simulation *stasis) const
{
    ;
    return Joint::AddressFromOffset(stasis, m_joint);
}
inline uint32_t
JointSpy::GetTag(void) const
{
    ;
    return m_tag;
}
inline rw::math::Vector3
JointSpy::GetLinearStress(void) const
{
    ;
    return m_lstress;
}
inline rw::math::Vector3
JointSpy::GetAngularStress(void) const
{
    ;
    return m_astress;
}
inline void
JointSpy::SetJoint(int32_t jt)
{
    ;
    m_joint = jt;
    return;
}
inline void
JointSpy::SetTag(const uint32_t tag)
{
    ;
    m_tag = tag;
    return;
}
inline void
JointSpy::SetLinearStress(const rw::math::Vector3 &lmag)
{
    ;
    m_lstress = lmag;
    return;
}
inline void
JointSpy::SetAngularStress(const rw::math::Vector3 &amag)
{
    ;
    m_astress = amag;
    return;
}
}
}






namespace rw
{
namespace physics
{
inline rw::ResourceDescriptor
DriveSpy::GetResourceDescriptor()
{
    ;
    uint32_t size = (((sizeof(DriveSpy)) + ((16) - 1)) & ~((16) - 1));
    return rw::ResourceDescriptor(size, 16);
}
inline Drive *
DriveSpy::GetDrive(Simulation *stasis) const
{
    ;
    return Drive::AddressFromOffset(stasis, m_drive);
}
inline uint32_t
DriveSpy::GetTag(void) const
{
    ;
    return m_tag;
}
inline float32_t
DriveSpy::GetLinearDistanceToKey(void) const
{
    ;
    return m_lindst;
}
inline float32_t
DriveSpy::GetAngularDistanceToKey(void) const
{
    ;
    return m_angdst;
}
inline rw::math::Vector3
DriveSpy::GetLinearStress(void) const
{
    ;
    return m_lstress;
}
inline rw::math::Vector3
DriveSpy::GetAngularStress(void) const
{
    ;
    return m_astress;
}
inline void
DriveSpy::SetDrive(int32_t jt)
{
    ;
    m_drive = jt;
    return;
}
inline void
DriveSpy::SetTag(const uint32_t tag)
{
    ;
    m_tag = tag;
    return;
}
inline void
DriveSpy::SetLinearDistanceToKey(const float32_t ldst)
{
    ;
    m_lindst = ldst;
    return;
}
inline void
DriveSpy::SetAngularDistanceToKey(const float32_t adst)
{
    ;
    m_angdst = adst;
    return;
}
inline void
DriveSpy::SetLinearStress(const rw::math::Vector3 &lmag)
{
    ;
    m_lstress = lmag;
    return;
}
inline void
DriveSpy::SetAngularStress(const rw::math::Vector3 &amag)
{
    ;
    m_astress = amag;
    return;
}
}
}






namespace rw
{
namespace physics
{
inline rw::ResourceDescriptor
ContactSpy::GetResourceDescriptor()
{
    ;
    uint32_t size = (((sizeof(ContactSpy)) + ((16) - 1)) & ~((16) - 1));
    return rw::ResourceDescriptor(size, 16);
}
inline RigidBody *
ContactSpy::GetBodyA(Simulation *stasis) const
{
    ;
    return RigidBody::AddressFromOffset(stasis, m_bodyA);
}
inline RigidBody *
ContactSpy::GetBodyB(Simulation *stasis) const
{
    ;
    return RigidBody::AddressFromOffset(stasis, m_bodyB);
}
inline uint32_t
ContactSpy::GetTag(void) const
{
    ;
    return m_tag;
}
inline rw::math::Vector3
ContactSpy::GetNormalStress(void) const
{
    ;
    return m_nimp;
}
inline rw::math::Vector3
ContactSpy::GetFrictionStress(void) const
{
    ;
    return m_fric;
}
inline rw::math::Matrix44Affine
ContactSpy::GetFrame(void) const
{
    ;
    return m_frame;
}
inline void
ContactSpy::SetBodyA(int32_t ba)
{
    ;
    m_bodyA = ba;
    return;
}
inline void
ContactSpy::SetBodyB(int32_t bb)
{
    ;
    m_bodyB = bb;
    return;
}
inline void
ContactSpy::SetTag(const uint32_t tag)
{
    ;
    m_tag = tag;
    return;
}
inline void
ContactSpy::SetNormalStress(const rw::math::Vector3 &csd)
{
    ;
    m_nimp = csd;
    return;
}
inline void
ContactSpy::SetFrictionStress(const rw::math::Vector3 &fsd)
{
    ;
    m_fric = fsd;
    return;
}
inline void
ContactSpy::SetFrame(const rw::math::Matrix44Affine &m)
{
    ;
    m_frame = m;
    return;
}
}
}
