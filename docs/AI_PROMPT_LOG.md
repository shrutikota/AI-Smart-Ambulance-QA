# AI Prompt Log

## Project

Smart Ambulance Traffic Clearance System

## Purpose

AI was used as an analytical assistant during the Quality Assurance activity. The AI suggestions were reviewed before being used in the project documentation.

---

## Prompt 1 – Timing Analysis

**Prompt:**

Review the following Arduino code for a Smart Ambulance Traffic Clearance System. Identify any timing or responsiveness problems and explain the root cause in simple technical language.

**AI-assisted finding:**

The use of delay(5000) blocks program execution for five seconds. A non-blocking timing method such as millis() can improve responsiveness.

**Action taken:**

The finding was documented as GitHub Issue #1. The suggested solution will be reviewed and tested before implementation.

---

## Prompt 2 – Input Analysis

**Prompt:**

Review the ambulance distance handling in this Arduino code. Identify limitations caused by the way ambulanceDistance is assigned and explain how it could affect a real-time system.

**AI-assisted finding:**

The current code uses fixed test values of 600 m, 300 m and 100 m. This is suitable for simulation testing, but a real implementation should receive dynamic distance information.

**Action taken:**

The finding was documented as GitHub Issue #2.

---

## Prompt 3 – Code Quality Analysis

**Prompt:**

Review the following distance-based traffic decision logic for code duplication and maintainability problems. Suggest a suitable refactoring approach.

**AI-assisted finding:**

The same if-else decision logic is repeated for each test distance. A reusable function can reduce duplication and make future threshold changes easier.

**Action taken:**

The finding was documented as GitHub Issue #3.

---

## Prompt 4 – System Integration Analysis

**Prompt:**

Review this Smart Ambulance traffic control simulation and identify missing integration required for real-time operation with GPS or communication input.

**AI-assisted finding:**

The current Stage 2 code demonstrates the traffic-state logic using predefined distances but does not yet integrate live distance information from the GPS or communication subsystem.

**Action taken:**

The finding was documented as GitHub Issue #4.

---

## AI Validation

The AI output was treated as a suggestion rather than a final decision. The identified issues were compared with the actual project code and system architecture before being documented in GitHub.

## Conclusion

AI helped identify timing, input-handling, code-duplication and system-integration improvement areas. The final QA decisions were reviewed based on the actual project requirements.
